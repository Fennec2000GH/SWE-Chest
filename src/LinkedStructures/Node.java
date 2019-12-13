package LinkedStructures;

/** Java Bean class for each element in a linked list
 * @param <T> Data type used for <code>data</code>
 */
public class Node<T> {
    //MEMBER VARIABLES
    /** Key held by this particular <code>Node</code>
     */
    private T data;

    /** Next <code>Node</code> in linked list
     */
    private Node<T> next;

    /** Boolean marker for multiple purposes
     */
    private boolean marker;

    //MEMBER FUNCTIONS
    //CONSTRUCTORS
    /** Default constructor
     */
    public Node(){ this.marker = false; }

    /** Constructor initializes <code>data</code>
     * @param newData Data value
     */
    public Node(T newData){ this(); this.data = newData; }

    /** Constructor initializes both <code>data</code> and <code>marker</code>
     * @param newData Data value
     * @param newMarker Marker value
     */
    public Node(T newData, boolean newMarker){ this(newData); this.marker = newMarker; }

    /** Copy constructor copies all member variables except for <code>next</code>
     * @param otherNode <code>Node</code> to be deep cloned
     */
    public Node(Node<T> otherNode){
        this.data = otherNode.getData();
        this.marker = otherNode.getMarker();
    }

    //ACCESSORS

    /** Tests for equality in content
     * @param otherNode <code>Node</code> to compare <code>this</code> to
     * @return Whether <code>this</code> and <code>otherNode</code> are equal in content
     */
    @Override
    public boolean equals(Object otherNode){
        if(otherNode.getClass() != Node.class)
            return false;
        Node<T> temp = (Node<T>)otherNode;
        if(this.getData().equals(temp.getData()) && this.getMarker() == temp.getMarker())
            return true;
        return false;
    }

    /** Gets the value stored in <code>data</code>
     * @return <code>data</code> of this <code>Node</code>
     */
    public T getData() { return data; }

    /** Gets the next <code>Node</code> sequentially in linked list
     * @return Next <code>Node</code>
     */
    public Node<T> getNext(){ return this.next; }

    /** Gets the current set <code>marker</code>
     * @return <code>marker</code> of this <code>QuadNode</code>
     */
    public boolean getMarker(){ return this.marker; }

    //MUTATORS
    /** Sets new value for <code>data</code>
     * @param newData Value for <code>data</code>
     * @return Whether provided <code>newData</code> is different that current <code>data</code> and thus a successful replacement
     */
    public void setData(T newData){ this.data = newData; }

    /** Sets new <code>Node</code> to sequentially come after <code>this</code>
     * @param node <code>Node</code> to be <code>next</code>
     */
    public void setNext(Node<T> node){
        this.next = node;
        if(this.next.getClass() == DoublyLinkedNode.class)
            ((DoublyLinkedNode<T>)this.next).setPrev(this);
    }

    /** Sets new value for <code>marker</code>
     * @param newMarker Value for <code>marker</code>, either <code>true</code> or <code>false</code>
     */
    public void setMarker(boolean newMarker){ this.marker = newMarker; }

}