package LinkedStructures;
import java.util.Arrays;
import java.util.Objects;
import java.util.stream.Collectors;
import java.util.List;

public class QuadNode<T> {
    //MEMBER VARIABLES
    /** Key held by this particular <code>QuadNode</code>
     */
    private T data;

    /** Boolean marker for multiple purposes
     */
    private boolean marker;

    /** Array of neighboring <code>QuadNode</code>
     */
    private QuadNode<T>[] neighbors = new QuadNode[4];

    //MEMBER FUNCTIONS
    //CONSTRUCTORS
    /** Constructor initializes <code>code</code>
     * @param newData Data value
     */
    public QuadNode(T newData){  this.data = newData; }

    /** Constructor initializes <code>marker</code>
     * @param newMarker Marker value
     */
    public QuadNode(boolean newMarker){ this.marker = newMarker; }

    /** Constructor initializes both <code>data</code> and <code>marker</code>
     * @param newData Data value
     * @param newMarker Marker value
     */
    public QuadNode(T newData, boolean newMarker){ this.data = newData; this.marker = newMarker; }

    //ACCESSORS
    /** Gets the value stored in <code>data</code>
     * @return <code>data</code> of this <code>QuadNode</code>
     */
    public T getData() { return data; }

    /** Gets the current set <code>marker</code>
     * @return <code>marker</code> of this <code>QuadNode</code>
     */
    public boolean getMarker(){ return this.marker; }

    /** Gets left neighboring <code>QuadNode</code>
     * @return Left neighbor
     */
    public QuadNode<T> getLeft(){ return this.neighbors[0]; }

    /** Gets right neighboring <code>QuadNode</code>
     * @return Right neighbor
     */
    public QuadNode<T> getRight(){ return this.neighbors[1]; }

    /** Gets upper neighboring <code>QuadNode</code>
     * @return Upper neighbor
     */
    public QuadNode<T> getUp() { return this.neighbors[2]; }

    /** Gets lower neighboring <code>QuadNode</code>
     * @return Lower neighbor
     */
    public QuadNode<T> getDown(){ return this.neighbors[3]; }

    /** Gets number of non-null neighboring <code>QuadNede</code>
     * @return Number of neighbors
     */
    public int getDegree(){
        int degree = 0;
        for(QuadNode<T> q : this.neighbors)
            if(q != null)
                ++degree;
        return degree;
    }

    /** Gets the first neighboring <code>QuadNode</code> that contains <code>target</code> as <code>data</code>, where
     * priority is left, right, up, and down.
     * @param target Value for <code>data</code> to search for among neighbors
     * @return First occurrence in the neighboring <code>QuadNode</code> to have <code>target</code>, otherwise returns
     * <code>null</code> if none match
     */
    public QuadNode<T> getNeignbor(T target){
        for(QuadNode<T> q : this.neighbors)
            if(q != null && q.getData().equals(target))
                return q;
        return null;
    }

    /** Get unmodifiable list view of all neigboring <code>QuadNode</code>
     * @param target Value for <code>data</code> to search for among neighbors
     * @return Unomodifiable list containing valid <code>QuadNode</code>
     */
    public List<QuadNode<T>> getAllNeighbors(T target){
        List<QuadNode<T>> quadnodeList = Arrays
                .stream(this.neighbors)
                .parallel()
                .filter(q -> q.getData().equals(target))
                .collect(Collectors.toUnmodifiableList());
        return quadnodeList;
    }

    /** Gets a full unmodifiable list view of all neighboring <code>QuadNode</code>
     * @return Unmoifiable list view of all non-null neighbors
     */
    public List<QuadNode<T>> getAllNeighbors(){ return Arrays
            .stream(this.neighbors)
            .parallel().filter(Objects::nonNull)
            .collect(Collectors.toUnmodifiableList());
    }

    //MUTATORS
    /** Sets new value for <code>data</code>
     * @param newData Value for <code>data</code>
     * @return Whether provided <code>newData</code> is different that current <code>data</code> and thus a successful replacement
     */
    public boolean setData(T newData){
        if(this.getData().equals(newData))
            return false;
        this.data = newData;
        return true;
    }

    /** Sets new value for <code>marker</code>
     * @param newMarker Value for <code>marker</code>, either <code>true</code> or <code>false</code>
     */
    public void setMarker(boolean newMarker){ this.marker = newMarker; }

    /** Sets new <code>QuadNode</code> as left neighbor
     * @param leftNode New <code>QuadNode</code>
     */
    public void setLeft(QuadNode<T> leftNode){ this.neighbors[0] = leftNode; }

    /** Sets new <code>QuadNode</code> as right neighbor
     * @param rightNode New <code>QuadNode</code>
     */
    public void setRight(QuadNode<T> rightNode){ this.neighbors[1] = rightNode; }

    /** Sets new <code>QuadNode</code> as upper neighbor
     * @param upNode New <code>QuadNode</code>
     */
    public void setUp(QuadNode<T> upNode){ this.neighbors[2] = upNode; }

    /** Sets new <code>QuadNode</code> as lower neighbor
     * @param downNode New <code>QuadNode</code>
     */
    public void setDown(QuadNode<T> downNode){ this.neighbors[3] = downNode; }
}
