package LinkedStructures;
import java.util.HashSet;

public abstract class LinkedListUtils {
    //MEMBER FUNCTIONS
    /** Sets <code>marker</code> to be <code>true</code> for all <code>Node</code> in linked list. Note that a linked
     * list with no lopp is assumed.
     * @param <T> </T>Data type of <code>Node</code>
     * @param head Head of given linked list
     */
    public static <T> void markAll(Node<T> head) {
        Node<T> p = head;
        while(p != null) {
            p.setMarker(true);
            p = p.getNext();
        }
    }

    /** Sets <code>marker</code> to be <code>false</code> for all <code>Node</code> in linked list. Note that a linked
     * list with no lopp is assumed.
     * @param <T> </T>Data type of <code>Node</code>
     * @param head Head of given linked list
     */
    public static <T> void unmarkAll(Node<T> head){
        Node<T> p = head;
        while(p != null){
            p.setMarker(false);
            p = p.getNext();
        }


    }

    /** Copy of whole linked list
     * @param <T> </T>Data type of <code>Node</code>
     * @param head Head of given linked list
     * @param deloop Whether to disconnect loop if encountered
     * @return Deep copy of linked list led by <code>head</code>, with the exception of removing the loop if detected
     * and <code>deloop</code> is <code>true</code>
     */
    public static <T> Node<T> copy(Node<T> head, boolean deloop){
        HashSet<Node<T>> catalog = new HashSet<>();
        Node<T> prev = new Node<>(head), p = new Node<>(head.getNext());
        Node<T> output = prev;
        catalog.add(prev);
        while(p != null && !catalog.contains(p)){
            prev.setNext(p);
            catalog.add(p);
            p = p.getNext();
            prev = prev.getNext();
        }

        //if any loop detected must be kept
        if(!deloop)
            prev.setNext(p);
        return output;
    }

//    /**
//     * @param <T> Data type of <code>Node</code>
//     * @param head Head of given linked list
//     * @param length
//     * @return
//     */
//    public static <T> Node<T> copy(Node<T> head, int length){
//
//    }
//
//    /**
//     * @param <T> Data type of <code>Node</code>
//     * @param head Head of given linked list
//     * @param start
//     * @param stop
//     * @return
//     */
//    public static <T> Node<T> copyOfRange(Node<T> head, Node<T> start, Node<T> stop){
//
//    }

    /** Finds the size of linked list
     * @param <T> Data type of <code>Node</code>
     * @param head Head of given linked list
     * @return The number of elements in linked list
     */
    public static <T> int size(Node<T> head){
        if(head == null)
            return 0;
        Node<T> copy = head;
        int size = 1;
        while(copy.getNext() != null) {
            copy = copy.getNext();
            ++size;
        }
        return size;
    }

    /** Finds the number of <code>Node</code> to be traversed to go from one <code>Node</code> to another
     * <code>Node</code>in linked list. If <code>node2</code> sequentially comes first, then the distance correlates to
     * the wrap-around traversal from <code>node1</code> to end of list and then from head of list to <code>node2</code>
     * @param <T> Data type of <code>Node</code>
     * @param head Head of linked list
     * @param node1 First <code>Node</code>
     * @param node2 Second <code>Node</code>
     * @return Distance between <code>node1</code> and <code>node2</code>, or -1 if one or more does not exist in the same linked list
     */
    public static <T> int distance(Node<T> head, Node<T> node1, Node<T> node2){
        if(node1 == null || node2 == null)
            return -1;
        Node<T> copy = node1;
        int dist = 0;
        //first phase: searching until end of linked list
        while(copy != null){
            copy = copy.getNext();
            ++dist;
            if(copy == node2)
                return dist;
            try {
                if (copy == node1)
                    throw new Exception("Loop detected!");
            } catch (Exception e) {
                return -1;
            }
        }
        //second phase: searching wraps around
        copy = head;
        ++dist;
        while(copy != node1 && copy != null){
            copy = copy.getNext();
            ++dist;
            if(copy == node2)
                return dist;
            try {
                if(dist > LinkedListUtils.size(head))
                    throw new Exception("Loop detected");
            } catch (Exception e){
                return -1;
            }
        }
        return -1;
    }

    /** Finds the tail or very last <code>Node</code> in given linked list
     * @param <T> Data type of <code>Node</code>
     * @param head Head of given linked list
     * @return Last element of linked list
     */
    public static <T> Node<T> getLast(Node<T> head){
        if(head == null)
            return null;
        Node<T> copy = head;
        while(copy.getNext() != null)
            copy = copy.getNext();
        return copy;
    }

    /** Advances <code>Node</code> p forward <code>skipSize</code> number of times
     * @param <T> Data type of <code>Node</code>
     * @param p Given <code>Node</code>
     * @param skipSize Number of <code>Node</code> to skip over
     * @return Current <code>Node</code> that <code>p</code> references after skipping forward
     */
    public static <T> Node<T> next(Node<T> p, int skipSize){
        if(p == null || skipSize < 0)
            return null;
        if(skipSize == 0)
            return p;
        Node<T> copy = p;
        for(int counter = 1; counter <= skipSize && copy != null; counter++)
            copy = copy.getNext();
        return copy;
    }

    /** Finds the very next <code>Node</code>, if it exists
     * @param <T> Data type of <code>Node</code>
     * @param p Given <code>Node</code>
     * @return Next <code>Node</code> in front
     */
    public static <T> Node<T> next(Node<T> p){ return p.getNext(); }

    /** Advances <code>p</code> in place physically <code>skipSize</code> elements forward
     * @param <T> Data type of <code>Node</code>
     * @param p Given <code>Node</code>
     * @param skipSize Number of <code>Node</code> to skip over
     */
    public static <T> void advance(Node<T> p, int skipSize){
        if(p == null || skipSize <= 0)
            return;
        for(int counter = 1; counter <= skipSize && p != null; counter++)
            p = p.getNext();
    }

    /** Advanced <code>p</code> only once forward
     * @param <T> Data type of <code>Node</code>
     * @param p Given <code>Node</code>
     */
    public static <T> void advance(Node<T> p){ p = p.getNext(); }

    /** Implementation of Floyd's Cycle Detection Algorithm
     * @param <T> Data type of <code>Node</code>
     * @param headOfLoop Potential starting <code>Node</code> of loop where end of lopp reconnects
     * @return Whether a loop exists with <code>headOfLoop</code> as the starting point. If a loop exists starting
     * at another <code>Node</code>, <code>false</code> will be returned.
     */
    public static <T> boolean floydCycleDetection(Node<T> headOfLoop){
        //head of loop must be non-null and potential head of loop must not be last in linked list
        if(headOfLoop == null || headOfLoop.getNext() == null)
            return false;
        Node<T> slow_P = headOfLoop, fast_P = headOfLoop;
        while(fast_P != null ){
            slow_P = slow_P.getNext();
            fast_P = LinkedListUtils.next(fast_P, 2);
            if(slow_P == fast_P)
                break;
        }
        return slow_P == headOfLoop && fast_P == headOfLoop;
    }

    /** Detects cycle by marking all visited <code>Node</code> with <code>marker</code> turned on. This assumes that all
     * <code>Node</code> initially have <code>false</code> set to <code>marker</code>.
     * @param <T> Data type of <code>Node</code>
     * @param head Head of given linked list
     * @return Head <code>Node</code> of loop if detected, otherwise returns null
     */
    public static <T> Node<T> markerCycleDetection(Node<T> head){
        if(head == null)
            return null;
        Node<T> p = head;
        while(!p.getMarker()) {
            p.setMarker(true);
            p = p.getNext();
        }
        return p;
    }

    /** Detects cycle by
     * @param <T> Data type of <code>Node</code>
     * @param head Head of given linked list
     */
    public static <T> Node<T> hashCycleDetection(Node<T> head){
        HashSet<Node<T>> catalog = new HashSet<>();
        Node<T> p = head;
        while(p != null){
            catalog.add(p);
            p = p.getNext();
            if(catalog.contains(p))
                return p;
        }
        return null;
    }

}
