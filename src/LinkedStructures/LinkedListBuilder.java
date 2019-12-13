package LinkedStructures;

public final class LinkedListBuilder<T> {
    //MEMBER VARIABLES
    private Node<T> head, tail;
    private int capacity;

    //MEMBER FUNCTIONS
    //CONSTRUCTORS
    /** Constructor starts new linked list with given value.
     * @param initialData Value of <code>data</code> in head <code>Node</code>
     */
    public LinkedListBuilder(T initialData){
        this.head = new Node<>(initialData);
        this.head.setMarker(true);
        this.tail = this.head;
    }

    /** Constructor starts with a pre-existing <code>Node</code> or linked list
     * @param initialList Value of <code>data</code> in head <code>Node</code>
     */
    public LinkedListBuilder(Node<T> initialList){
        if(initialList == null)
            this.head = new Node<>();
        this.head = initialList;
        this.tail = this.head;
        assert this.tail != null : "Head does not exist";
        while(this.tail.getNext() != null)
            this.tail = thi.getNext();
    }

    //ACCESSORS
    public boolean add(Node<T> node){
    }

    /**
     * @param node
     * @param copy
     * @return
     */
    public boolean add(Node<T> node, boolean copy){
        if(node == null || this.containsReference(node))
            return false;

        //checking whether end of linked list attached to node connects to a pre-existing Node or forms an inner loop

        p.setNext(copy ? new Node<T>(node) : node);
        while(p.getNext() != null)
            p = p.getNext();
        return true;
    }

    /** Checks whether current <code>LinkedListBuilder</code> already contains a <code>Node</code> by value
     * @param node <code>Node</code> to search for
     * @return Whether <code>node</code> already exists in current <code>LinkedListBuilder</code>
     */
    public boolean contains(Node<T> node){
        if(node == null)
            return false;
        Node<T> finder = this.head;
        while(finder != null) {
            if (finder.equals(node))
                return true;
            finder = finder.getNext();
        }
        return false;
    }

    /** Checks whether current <code>LinkedListBuilder</code> contains <code>node</code> by reference
     * @param node <code>Node</code> to search for
     * @return Whether <code>node</code> already exists in current <code>LinkedListBuilder</code> by reference
     */
    public boolean containsReference(Node<T> node){
        if(node == null)
            return false;
        Node<T> finder = this.head;
        while (finder != null){
            if(finder == node)
                return true;
            finder = finder.getNext();
        }
        return false;
    }

    public static void main(String[] args){

    }
}
