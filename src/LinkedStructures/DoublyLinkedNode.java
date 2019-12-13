package LinkedStructures;

/** Variant of <code>Node</code> with both next and previous links
 * @param <T> Data type used for <code>data</code>
 */
public class DoublyLinkedNode<T> extends Node<T> {
    //MEMBER VARIABLES
    public Node<T> prev;

    //MEMBER FUNCTIONS
    //CONSTRUCTORS
    public DoublyLinkedNode(T n){ super(n);}

    //ACCESSORS
    public Node<T> getPrev(){ return this.prev;  }

    //MUTATORS
    public void setPrev(Node<T> node){ this.prev = node; }

}
