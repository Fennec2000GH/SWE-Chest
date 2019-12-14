package LinkedStructures;

public final class LinkedListBuilder<T> {
    //MEMBER VARIABLES
    /** First and last <code>Node</code> in linked list
     */
    private Node<T> head, tail;

    /** Preset limit on number of <code>Node</code> allowed in linked list
     */
    private int capacity;

    /** Current count of <code>Node</code> in linked list
     */
    private int size;


    //MEMBER FUNCTIONS
    //CONSTRUCTORS
    /** Constructor starts new linked list with given value for <code>data</code>
     * @param initialData Value of <code>data</code> in head
     */
    public LinkedListBuilder(T initialData){
        this.head = new Node<>(initialData);
        this.head.setMarker(false);
        this.capacity = -1;
        this.size = 1;
    }

    /** Constructor starts new linked list with given values for <code>data</code> and <code>capacity</code>
     * @param initialData Value of <code>data</code> in head
     * @param newCapacity Preset limit on number of <code>Node</code> allowed in linked list
     */
    public LinkedListBuilder(T initialData, int newCapacity){
        this(initialData);
        this.capacity = newCapacity;
    }

    /** Copy/move constructor starts with a pre-existing <code>Node</code> or linked list
     * @param initialList Value of <code>data</code> in head <code>Node</code>
     * @param moveConstructor Whether to use as move constructor
     **/
    public LinkedListBuilder(Node<T> initialList, boolean moveConstructor){
        Node<T> possibleLoop = LinkedListUtils.hashCycleDetection(initialList);
        if(initialList == null)
            this.head = null;
        else if(moveConstructor) {
            this.head = initialList;
            this.tail = LinkedListUtils.getLast(initialList);
        } else {
            this.head = new Node<>(initialList);
            Node<T> prev = this.head, p = initialList.getNext();
            int counter = initialList == possibleLoop ? 1 : 0;
            while(p != null){
                prev.setNext(new Node<>(p));
                if(counter >= 2) {
                    this.tail = prev;
                    break;
                }
                prev = prev.getNext();
                p = p.getNext();
                if(p == possibleLoop)
                    ++counter;
            }
        }
    }

    //ACCESSORS
    /** Finds number of <code>Node</code> in linked list
     * @return Size of linked list
     */
    public int size(){ return this.size; }

    /** Finds the capacity of linked list
     * @return A positive integer if capacity is used, otherwise returns -1
     */
    public int getCapacity(){ return this.capacity; }

    /** Exports current linked list
     * @return Linked list led by <code>head</code>
     */
    public Node<T> getLinkedList(){ return this.head; }

    //MUTATORS
    /** Add additional linked list to the end of current linked list
     * @param head Head of another linked list
     * @return Whether addition is successful or not
     */
    public boolean add(Node<T> head){
        //new linked list must not contain any reference to existing Node in current linked list
        if(LinkedListUtils.stream(head).anyMatch(this::contains))
            return false;
        //capacity must be considered
        if(this.getCapacity() >= 1 && this.size() >= this.getCapacity())
            return false;
        //current linked list ends in a loop
        if(this.tail.getNext() != null){
            Node<T> temp = this.tail.getNext();
            this.tail.setNext(head);
            while(this.tail.getNext() != temp)
                this.tail = this.tail.getNext();
        } else { //current linked list is linear
            this.tail.setNext(head);
            this.tail = LinkedListUtils.getLast(this.head);
        }
        return true;
    }

    /** Checks whether current <code>LinkedListBuilder</code> already contains a linked list by content
     * @param newList <code>Node</code> to search for
     * @return Whether <code>node</code> already exists in current <code>LinkedListBuilder</code>
     */
    public boolean contains(Node<T> newList){
        if(newList == null)
            return false;
        Node<T> p = this.head, q = newList, possibleLoop = LinkedListUtils.hashCycleDetection(this.head);
        int counter = this.head == possibleLoop ? 1 : 0;
        while(p != null){
            while (p.equals(q)){
                p = p.getNext();
                q = q.getNext();
                if(q == null)
                    return true;
                if(p == null)
                    return false;
                if(p == possibleLoop)
                    ++counter;
                if(counter >= 2)
                    break;
            }
            p = p.getNext();
            if(p == possibleLoop)
                ++counter;
            if(counter >= 2)
                break;
        }
        return false;
    }

    public static void main(String[] args){

    }
}
