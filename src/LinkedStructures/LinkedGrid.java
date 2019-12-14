package LinkedStructures;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;
import java.util.function.Function;

public class LinkedGrid<T> {
    //MEMBER VARIABLES
    /** 2D array to ensure fixed-size rectangular <code>LinkedGrid</code>
     */
    private QuadNode<T>[][] matrix;

    //MEMBER FUNCTIONS
    //CONSTRUCTORS
    /** Default constructor
     */
    public LinkedGrid(){ this.matrix = null; }

    /** Constructor sets empty and null <code>matrix</code> with given dimensions, which both must be positive.
     * @param rowSize Number of rows
     * @param colSize Number of columns
     */
    public LinkedGrid(int rowSize, int colSize){
        if(rowSize >= 1 && colSize >= 1)
            this.matrix = new QuadNode[rowSize][colSize];
    }

    /** Copy constructor replacing <code>matrix</code> with <code>otherMatrix</code>
     * @param otherMatrix Another 2D array of <code>QuadNode</code>
     */
    public LinkedGrid(QuadNode<T>[][] otherMatrix){
        Function<QuadNode<T>[][], Boolean> isJagged = m -> Arrays
                .stream(m)
                .parallel()
                .allMatch(n -> n.length == m[0].length);
        Function<QuadNode<T>[][], Boolean> isNull = m -> Arrays
                .stream(m)
                .flatMap(Arrays::stream)
                .parallel()
                .allMatch(Objects::isNull);
        Function<QuadNode<T>[][], QuadNode<T>> getFirstNonNull = m -> Arrays
                .stream(otherMatrix)
                .flatMap(Arrays::stream)
                .filter(Objects::nonNull)
                .findFirst()
                .orElse(null);
        try {
            if (otherMatrix == null)
                this.matrix = null;
            else if(otherMatrix.length == 0 || otherMatrix[0].length == 0)
                throw new IllegalArgumentException("Number of rows and number of columns must be positive!");
            else if (!isJagged.apply(otherMatrix))
                throw new IllegalArgumentException("Cannot accept jagged grid!");
            else if(isNull.apply(otherMatrix))
                this.matrix = new QuadNode[otherMatrix.length][otherMatrix[0].length];
            else if(getFirstNonNull.apply(otherMatrix).getData().getClass() != this.getFirstNonNullElement().getData().getClass())
                throw new IllegalArgumentException("Data types do not match!");
            else {
                this.matrix = new QuadNode[otherMatrix.length][otherMatrix[0].length];
                for (int rowIndex = 0; rowIndex < otherMatrix.length; rowIndex++)
                    for (int columnIndex = 0; columnIndex < otherMatrix[0].length; columnIndex++)
                        this.set(rowIndex, columnIndex, new QuadNode(otherMatrix[rowIndex][columnIndex]));
            }
        } catch (IllegalArgumentException e) {
            e.getStackTrace();
        }
    }

    /** Copy constructor replacing current <code>matrix</code> with copy of <code>matrix</code> in another <code>LinkedGrid</code>
     * @param otherLinkedGrid <code>LinkedGrid</code> to copy new <code>matrix</code> from
     */
    public LinkedGrid(LinkedGrid<T> otherLinkedGrid){ this(otherLinkedGrid.matrix); }

    //ACCESSORS
    /** Finds the element located at specified indices in <code>matrix</code>
     * @param rowIndex 0-based index for row
     * @param columnIndex 0-based index for column
     * @return Element with indices <code>rowIndex</code> and <code>columnIndex</code>, or returns <code>null</code> if
     * indices are invalid by being negative or beyond the dimensions of <code>matrix</code>
     */
    public QuadNode<T> get(int rowIndex, int columnIndex){
        try {
            if (rowIndex <= -1 || columnIndex <= -1 || rowIndex >= this.getRowLength() || columnIndex >= this.getColumnLength())
                throw new IllegalArgumentException("Indices out of bounds!");
        } catch (IllegalArgumentException e){
            e.printStackTrace();
        }
        return this.matrix[rowIndex][columnIndex];
    }

    /** Gets number of rows
     * @return Row dimension
     */
    public int getRowLength(){ return this.matrix.length; }

    /** Gets number of columns
     * @return Column dimension
     */
    public int getColumnLength(){ return this.matrix[0].length; }

    /** Gets entire row of elements at given row index
     * @param rowIndex 0-based index for row
     * @return Row of <code>matrix</code>, or null if index is out of bounds
     */
    public QuadNode<T>[] getRow(int rowIndex){
        if(rowIndex <= -1 || rowIndex > this.getRowLength())
            return null;
        return this.matrix[rowIndex];
    }

    /** Gets entire column of elements at given column index
     * @param columnIndex 0-based index for column
     * @return Column of <code>matrix</code>, or null if index is out of bounds
     */
    public QuadNode<T>[] getColumn(int columnIndex){
        if(columnIndex <= -1 || columnIndex > this.getColumnLength())
            return null;
        ArrayList<QuadNode<T>> outputList = new ArrayList<>(this.getRowLength());
        for(QuadNode<T>[] row : this.matrix)
            outputList.add(row[columnIndex]);
        QuadNode<T>[] output = new QuadNode[this.getRowLength()];
        outputList.toArray(output);
        return output;
    }

    /** Finds if every single element in <code>matrix</code> is <code>null</code>
     * @return Whether <code>matrix</code> is a <code>grid</code>
     */
    public boolean isNull(){
        for(int i = 0; i < this.getRowLength(); i++)
            for(int j = 0; j < this.getColumnLength(); j++)
                if(this.get(i, j) != null)
                    return false;
        return true;
    }

    /** Finds row and column indices of first occurrence of <code>null</code> element
     * @return Ordered pair of indices as 2 element array
     */
    public int[] getFirstNullIndex(){
        for(int i = 0; i < this.getRowLength(); i++)
            for(int j = 0; j < this.getColumnLength(); j++)
                if(this.get(i, j) == null)
                    return new int[]{i, j};
        return new int[]{-1, -1};
    }

    /** Finds row and column indices of first occurrence of non-null element
     * @return Ordered pair of indices as 2 element array
     */
    public int[] getFirstNonNullIndex(){
        for(int i = 0; i < this.getRowLength(); i++)
            for(int j = 0; j < this.getColumnLength(); j++)
                if(this.get(i, j) != null)
                    return new int[]{i, j};
        return new int[]{-1, -1};
    }

    /** Finds first occurrence of non-null element
     * @return First non-null <code>QuadNode</code> in row-major sequential order of all elements
     */
    public QuadNode<T> getFirstNonNullElement() {
        int[] indexPair = this.getFirstNonNullIndex();
        if (indexPair[0] == -1 || indexPair[1] == -1)
            return null;
        return this.get(indexPair[0], indexPair[1]);
    }

    /** Finds out if <code>matrix</code> is a jagged 2D array
     * @return Whether different rows have differing lengths
     */
    public boolean isJagged(){ return Arrays.stream(this.matrix).parallel().allMatch(n -> n.length == this.getColumnLength()); }

    /** If type T extends <code>Number</code>, finds sum of <code>data</code> in all non-null elements in <code>matrix</code>
     * @return Sum of <code>data</code> in entire <code>matrix</code> as a <code>double</code> value
     */
    public double sum(){
        if(this.getFirstNonNullElement() == null)
            return -1;
        if(Number.class.isInstance(this.getFirstNonNullElement().getData()))
            return Arrays
                .stream(this.matrix)
                .flatMap(Arrays::stream)
                .parallel()
                .mapToDouble(n -> ((Number)n.getData()).doubleValue())
                .sum();
        return Double.MIN_VALUE;
    }

    //MUTATORS
    /** Sets a new element at given indices
     * @param rowIndex 0-based index for row
     * @param columnIndex 0-based index for column
     * @param node <code>QuadNode</code> to be placed at given indices
     */
    public void set(int rowIndex, int columnIndex, QuadNode<T> node){
        try {
            if(rowIndex <= -1 || columnIndex <= -1 || rowIndex >= this.getRowLength() || columnIndex >= this.getColumnLength())
                throw new IllegalArgumentException("Indices out of bounds!");
        } catch (IllegalArgumentException e){
            e.printStackTrace();
        }
        this.matrix[rowIndex][columnIndex] = node;
    }

    /** Sets <code>marker</code> of all non-null elements in <code>matrix</code> to the same <code>boolean</code> value
     * @param newMarker Either <code>true</code> or <code>false</code>
     */
    public void setAllMarkers(boolean newMarker){ Arrays.stream(this.matrix).flatMap(Arrays::stream).forEach(n -> n.setMarker(newMarker)); }

}
