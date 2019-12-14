package LinkedStructures;
import java.util.HashSet;
import java.util.List;
import java.util.stream.Collectors;

public abstract class LinkedListUtils {
    //MEMBER FUNCTIONS
    /** Finds first occurrence of <code>Node</code> that contains given value for <code>data</code>
     * @param <T> Data type of <code>Node</code>
     * @param head Head of given linked list
     * @param targetData Value for <code>data</code> to search for
     * @return First <code>Node</code> to contain <code>targetData</code>, otherwise returns <code>null</code> if none exist
     **/
    public static <T> Node<T> get(Node<T> head, T targetData){
        if(head == null)
            return null;
        Node<T> possibleLoop = LinkedListUtils.hashCycleDetection(head);
        Node<T> p = head;
        int loopHeadCounter = 0;
        while(p != null){
            if(p.getData().equals(targetData))
                return p;
            if(p == possibleLoop)
                ++loopHeadCounter;
            if(loopHeadCounter >= 2)
                return null;
            p = p.getNext();
        }
        return null;
    }

    /** Finds first occurrence of <code>Node</code> that contains given value for <code>marker</code>
     * @param <T> Data type of <code>Node</code>
     * @param head Head of given linked list
     * @param targetMarker Value for <code>marker</code> to search for
     * @return First <code>Node</code> to contain <code>targetMarker</code>, otherwise returns <code>null</code> if none exist
     */
    public static <T> Node<T> get(Node<T> head, boolean targetMarker){
        if(head == null)
            return null;
        Node<T> possibleLoop = LinkedListUtils.hashCycleDetection(head);
        Node<T> p = head;
        int loopHeadCounter = 0;
        while(p != null){
            if(p.getMarker() == targetMarker)
                return p;
            if(p == possibleLoop)
                ++loopHeadCounter;
            if(loopHeadCounter >= 2)
                return null;
            p = p.getNext();
        }
        return null;
    }

    /** Finds first occurrence of <code>Node</code> that contains given value for both <code>data</code> and <code>marker</code>
     * @param <T> Data type of <code>Node</code>
     * @param head Head of given linked list
     * @param targetData Value for <code>data</code> to search for
     * @param targetMarker Value for <code>marker</code> to search for
     * @return First <code>Node</code> to contain both <code>targetData</code> and <code>targetMarker</code>,
     * otherwise returns <code>null</code> if none exist
     */
    public static <T> Node<T> get(Node<T> head, T targetData, boolean targetMarker){
        if(head == null)
            return null;
        Node<T> possibleLoop = LinkedListUtils.hashCycleDetection(head);
        Node<T> p = head;
        int loopHeadCounter = 0;
        while(p != null){
            if(p.getData().equals(targetData) && p.getMarker() == targetMarker)
                return p;
            if(p == possibleLoop)
                ++loopHeadCounter;
            if(loopHeadCounter >= 2)
                return null;
            p = p.getNext();
        }
        return null;
    }

    /** Gets an unmodifiable list view of all <code>Node</code> with <code>marker</code> set to <code>true</code>,
     * although sequential order of original linked list is not guaranteed.
     * @param <T> Data type of <code>Node</code>
     * @param head Head of given linked list
     * @return Unmodifiable list view of <code>Node</code> marked <code>true</code>
     */
    public static <T> List<Node<T>> getMarked(Node<T> head){
        HashSet<Node<T>> markedSet = new HashSet<>();
        Node<T> p = head;
        while(p != null && !markedSet.contains(p)){
            if(p.getMarker())
                markedSet.add(p);
            p = p.getNext();
        }
        return markedSet.stream().parallel().collect(Collectors.toUnmodifiableList());
    }

    /** Gets an unmodifiable list view of all <code>Node</code> with <code>marker</code> set to <code>false</code>,
     * although sequential order of original linked list is not guaranteed.
     * @param <T> Data type of <code>Node</code>
     * @param head Head of given linked list
     * @return Unmodifiable list view of <code>Node</code> marked <code>false</code>
     */
    public static <T> List<Node<T>> getUnmarked(Node<T> head){
        HashSet<Node<T>> unmarkedSet = new HashSet<>();
        Node<T> p = head;
        while(p != null && !unmarkedSet.contains(p)){
            if(!p.getMarker())
                unmarkedSet.add(p);
            p = p.getNext();
        }
        return unmarkedSet.stream().parallel().collect(Collectors.toUnmodifiableList());
    }

    /** Sets <code>marker</code> to be <code>true</code> for all <code>Node</code> in linked list
     * @param <T> </T>Data type of <code>Node</code>
     * @param head Head of given linked list
     * @param newMarker New <code>boolean</code> value to assign to <code>marker</code> for all <code>Node</code> in linked list
     **/
    public static <T> void markAll(Node<T> head, boolean newMarker) {
        Node<T> possibleLoop = LinkedListUtils.hashCycleDetection(head);
        Node<T> p = head;
        int loopHeadCounter = 0;
        while(p != null) {
            if(p == possibleLoop)
                ++loopHeadCounter;
            if(loopHeadCounter >= 2)
                break;
            p.setMarker(newMarker);
            p = p.getNext();
        }
    }

    /** Copy of whole linked list
     * @param <T> </T>Data type of <code>Node</code>
     * @param head Head of given linked list
     * @return Deep copy of linked list led by <code>head</code>
     */
    public static <T> Node<T> copy(Node<T> head){
        if(head == null)
            return null;
        if(LinkedListUtils.isSingleton(head))
            return new Node<>(head);
        Node<T> prev = new Node<>(head), p = head.getNext(), output = prev, possibleLoop = LinkedListUtils.hashCycleDetection(head);
        int loopHeadCounter = head == possibleLoop ? 1 : 0;
        while(p != null){
            prev.setNext(new Node<>(p));
            prev = prev.getNext();
            if(loopHeadCounter >= 2)
                break;
            p = p.getNext();
            if(p == possibleLoop)
                ++loopHeadCounter;
        }
        return output;
    }

    /** Copy of linked list for a given <code>length</code>
     * @param <T> Data type of <code>Node</code>
     * @param head Head of given linked list
     * @param length Number of <code>Node</code> in total to be in copy, starting from <code>head</code>
     * @return Deep copy of linked list led by <code>head</code> for a given number of <code>Node</code> and will copy
     * whole linked list if <code>length</code> is longer than actual length of linked list
     */
    public static <T> Node<T> copy(Node<T> head, int length){
        try {
            if (length <= -1)
                throw new IllegalArgumentException("Length must be non-negative!");
        } catch (IllegalArgumentException e) {
            e.printStackTrace();
        }
        if(head == null || length == 0)
            return null;
        int counter = 1;
        Node<T> prev = new Node<>(head), p = head.getNext(), output = prev, possibleLoop = LinkedListUtils.hashCycleDetection(head);
        int loopHeadCounter = head == possibleLoop ? 1 : 0;
        while(p != null && counter < length){
            prev.setNext(new Node<>(p));
            prev = prev.getNext();
            if(loopHeadCounter >= 2)
                break;
            p = p.getNext();
            if(p == possibleLoop)
                ++loopHeadCounter;
            ++counter;
        }

        //in case length as parameter equals actual length of linked list and there is a loop present
        if(p == possibleLoop)
            prev.setNext(p);
        return output;
    }

    /** Copy of range of <code>Node</code> from a start <code>Node</code> and end <code>Node</code>. If tail of copy,
     * denoted by <code>stop</code>, is not found, then copy goes all the way to the end of linked list.
     * @param <T> Data type of <code>Node</code>
     * @param head Head of given linked list
     * @param start Head of copy (inclusive)
     * @param stop Tail of copy (exclusive)
     * @return Deep copy of linked list led by <code>head</code> within specified range
     */
    public static <T> Node<T> copyOfRange(Node<T> head, Node<T> start, Node<T> stop){
        if(head == null || start == null || stop == null || start == stop)
            return null; 
        if(LinkedListUtils.isSingleton(head))
            return new Node<>(head);
        Node<T> prev = new Node<>(head), p = head.getNext(), output = prev, possibleLoop = LinkedListUtils.hashCycleDetection(head);
        int loopHeadCounter = head == possibleLoop ? 1 : 0;
        while (p != null && p != stop) {
            prev.setNext(new Node<>(p));
            prev = prev.getNext();
            if(loopHeadCounter >= 2)
                break;
            p = p.getNext();
            if(p == possibleLoop)
                ++loopHeadCounter;
        }
        return output;
    }

    /** Finds out if linked list only contains one <code>Node</code>
     * @param <T> Data type of <code>Node</code>
     * @param head Head of given linked list
     * @return Whether <code>head</code> is the only <code>Node</code> making up linked list
     */
    public static <T> boolean isSingleton(Node<T> head){ return head.getNext() == null; }

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
        if(node1 == node2)
            return 0;
        Node<T> p = node1.getNext(), tail = LinkedListUtils.getLast(head);
        int dist = 0;
        //first phase: searching until end of linked list
        while(p != null){
            ++dist;
            if(p == node2)
                return dist;
            if(p == tail)
                break;
            p = p.getNext();
        }
        //second phase: searching wraps around
        p = head;
        while(p != node1){
            ++dist;
            if(p == node2)
                return dist;
            p = p.getNext();
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
        if(LinkedListUtils.isSingleton(head))
            return head;
        Node<T> p = head, possibleLoop = LinkedListUtils.hashCycleDetection(head);
        int counter = head == possibleLoop ? 1 : 0;
        while(p.getNext() != null) {
            if(counter >= 2)
                break;
            p = p.getNext();
            if(p.getNext() == possibleLoop)
                ++counter;
        }
        return p;
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

    /** Detects cycle by storing and checking traversed <code>Node</code> in a <code>HashSet</code>
     * @param <T> Data type of <code>Node</code>
     * @param head Head of given linked list
     */
    public static <T> Node<T> hashCycleDetection(Node<T> head){
        if(LinkedListUtils.isSingleton(head))
            return null;
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
