package LinkedStructures;
import java.util.ArrayList;

public class JaggedLinkedGrid<T> {
    //MEMBER VARIABLES
    /** Backbone array holding
     */
    private ArrayList<ArrayList<Node<T>>> spine;

    /**
     */
    private int rowCapacity, columnCapacity;


    //MEMBER FUNCTIONS
    //CONSTRUCTORS
    /**
     * @param newRowCapacity
     */
    public JaggedLinkedGrid(int newRowCapacity){
        this.spine = new ArrayList<>(newRowCapacity);
        this.rowCapacity = newRowCapacity;
        this.columnCapacity = -1;
    }

    /**
     * @param newRowCapacity
     * @param newColumnCapacity
     */
    public JaggedLinkedGrid(int newRowCapacity, int newColumnCapacity){
        this(newRowCapacity);
        for (ArrayList<Node<T>> row : this.spine)
            row = new ArrayList<>(newColumnCapacity);
        this.columnCapacity = newColumnCapacity;
    }

    public JaggedLinkedGrid()

}
