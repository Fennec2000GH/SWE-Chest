package Array;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;
import java.util.function.Function;
import java.util.List;
import java.util.stream.Collectors;

import com.google.common.base.Preconditions;

public abstract class ArrayUtils {

    /** Implementation of Kadane's algorithm. Aims to find contiguous sub-array with maximal sum of elements.
     * @param arr Array of <code>Number</code>
     * @return Sub-array of largest contiguous sum of elements
     */
    public static Number[] kadaneArray(Number[] arr){
        if(arr == null)
            return null;
        double maxSum = 0, sum = 0;
        int maxLeftIndex = 0, maxRightIndex = 0, leftIndex = 0, rightIndex;
        for(rightIndex = 0; rightIndex <= arr.length - 1; rightIndex++){
            sum += arr[rightIndex].doubleValue();
            if(sum < 0) {
                leftIndex = rightIndex + 1;
                sum = 0;
            }
            if(sum > maxSum){
                maxSum = sum;
                maxLeftIndex = leftIndex;
                maxRightIndex = rightIndex;
            }
        }
        Number[] output = new Number[maxRightIndex - maxLeftIndex + 1];
        for(int i = 0; i <= output.length - 1; i++)
            output[i] = arr[i + maxLeftIndex];
        return output;
    }

    /** Finds the longest contiguous sub-array that has increasing elements.
     * @param arr Array of <code>Number</code>
     * @param strictlyIncreasing Whether equal numbers constitute increase or not
     * @return Longest contiguous sub-array of increasing elements, or first occurrence if multiple sub-arrays have the
     * same optimal length
     */
    public static Number[] longestIncreasingSubarray(Number[] arr, boolean strictlyIncreasing){
        if(arr == null)
            return null;
        int maxLength = 1, length = 1, maxLeftIndex = 0, maxRightIndex = 0, leftIndex = 0, rightIndex;
        double diff;
        for(rightIndex = 1; rightIndex <= arr.length - 1; rightIndex++){
            diff = arr[rightIndex].doubleValue() - arr[rightIndex - 1].doubleValue();
            if(diff > 0 || diff == 0 && strictlyIncreasing)
                ++length;
            else {
                leftIndex = rightIndex;
                length = 1;
            }
            if(length > maxLength){
                maxLength = length;
                maxLeftIndex = leftIndex;
                maxRightIndex = rightIndex;
            }
        }
        Number[] output = new Number[maxRightIndex - maxLeftIndex + 1];
        for(int i = 0; i <= output.length - 1; i++)
            output[i] = arr[i + maxLeftIndex];
        return output;
    }

    /** Swap 2 elements in the same <code>Number</code> arry
     * @param arr Array of <code>Number</code>
     * @param i Nonnegative index
     * @param j Nonnegative index
     */
    public static void swap(Number[] arr, int i, int j){
        Preconditions.checkNotNull(arr, "Array cannot be null!");
        Preconditions.checkElementIndex(i, arr.length, "Index i out of bounds!");
        Preconditions.checkElementIndex(j, arr.length, "Index j out of bounds!");
        Number temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    /** Reverses and provides a copy of reversed given <code>Number</code> array
     * @param arr Array of <code>Number</code>
     * @return Reversed copy of <code>arr</code>
     */
    public static Number[] reverseArray(Number[] arr){
        if(arr == null)
            return null;
        else if(arr.length <= 1) {
            Number[] array = new Number[arr.length];
            try {
                Preconditions.checkElementIndex(0, arr.length);
            } catch (IndexOutOfBoundsException e){
                return array;
            }
            array[0] = arr[0];
            return array;
        }
        Number[] output = Arrays.copyOf(arr, arr.length);
        for(int i = 0; i < arr.length / 2; i++)
            ArrayUtils.swap(output, i, arr.length - 1 - i);
        return output;
    }

    /** Constructs the reversed array based on <code>arr</code> array but keeping elements located at specified indices fixed
     * in original order.
     * @param arr Array of <code>Number</code>
     * @param fixedIndex Varargs of indices to fix down certain elements and abstain them from the reversal process
     * @return Reversed array with certain elements fixed in original order
     */
    public static Number[] reverseArrayWithFixedIndex(Number[] arr, int... fixedIndex){
        if(fixedIndex.length == 0)
            return Arrays.copyOf(arr, arr.length);
        Number[] output = new Number[arr.length];
        ArrayList<Integer> fixedIndexList = (ArrayList<Integer>)Arrays.stream(fixedIndex).parallel().boxed().collect(Collectors.toList());
        int rightIndex = output.length - 1;
        for(int i = 0; i < rightIndex; i++)
            if(fixedIndexList.contains(i))
                output[i] = arr[i];
            else {
                while(fixedIndexList.contains(rightIndex) && rightIndex >= 1) {
                    output[rightIndex] = arr[rightIndex];
                    --rightIndex;
                }
                Number temp = arr[i];
                output[i] = arr[rightIndex];
                output[rightIndex] = temp;
            }
            return output;
    }

//    public static List<List<Number>> subarraysLessThan(Number[] arr, double upperBound){
//        Number[] reducedArr = (Number[])Arrays
//                .stream(arr)
//                .mapToDouble(Number::doubleValue)
//                .sorted()
//                .filter(n -> n <= upperBound)
//                .boxed()
//                .toArray();
//        ArrayList<Number[]>[][] jaggedCube = new ArrayList[reducedArr.length][reducedArr.length];
//        for()
//
//    }
//    public static List<List<Number>> subarraysGreaterThan(Number[] arr, int lowerBound){}
//    public static List<List<Number>> subarraysAtMost(Number[] arr, int upperBound){}
//    public static List<List<Number>> subarraysAtLeast(Number[] arr, int lowerBound){}

    /** Find index of first occurrence of <code>null</code> in given array
     * @param <T> Data type of object
     * @param arr  Array where which to search for <code>null</code>
     * @return Index of first occurrence of <code>null</code>, or -1 if not found in <code>arr</code>
     */
    public static <T> int indexOfNull(T[] arr){
        try {
            Preconditions.checkNotNull(arr, "Array cannot be null!");
        } catch (NullPointerException e) {
            return -1;
        }
        for(int i = 0; i < arr.length; i++)
            if(arr[i] == null)
                return i;
        return -1;
    }

    /** Find index of first occurrence of an <code>Object</code> in given array
     * @param <T> Data type of object
     * @param arr Array where which to search for a target number
     * @param target <code>Object</code> to search for
     * @return Index of first occurrence of <code>target</code>, or -1 if not found in <code>arr</code>
     */
    public static <T> int indexOf(T[] arr, T target){
        try {
            Preconditions.checkNotNull(arr, "Array cannot be null!");
        } catch (NullPointerException e) {
            return -1;
        }
        for(int i = 0; i < arr.length; i++)
            if(arr[i].equals(target))
                return i;
        return -1;
    }

    /** Find index of first occurrence of a number in given array
     * @param arr <code>Number</code> array where which to search for a target number
     * @param target <code>Number</code> to search for
     * @return Index of first occurrence of <code>target</code>, or -1 if not found in <code>arr</code>
     */
    public static int indexOf(Number[] arr, Number target){
        try {
            Preconditions.checkNotNull(arr, "Array cannot be null!");
        } catch (NullPointerException e) {
            return -1;
        }
        for(int i = 0; i < arr.length; i++)
            if(arr[i].equals(target))
                return i;
        return -1;
    }

    /** Finds index of first occurrence of given sub-array within a longer array
     * @param arr Longer <code>Number</code> array where which to search for a shorter sub-array
     * @param subarray Shorter <code>Number</code> array
     * @param hashFunc Hash function that returns an <code>Integer</code> value for any <code>Number</code> array
     * @return Index of first occurrence of <code>subarray</code> in <code>arr</code>, or -1 if not found
     */
    public static int indexOf(Number[] arr, Number[] subarray, Function<Number[], Integer> hashFunc){
        if(arr == null || subarray == null || arr.length < subarray.length)
            return -1;
        Integer subArrayHashValue = hashFunc.apply(subarray), partialArrHashValue;
        Number[] partialArr;
        for(int i = 0; i <= arr.length - subarray.length; i++){
            partialArr = Arrays.copyOfRange(arr, i, i + subarray.length);
            partialArrHashValue = hashFunc.apply(partialArr);
            if(subArrayHashValue.equals(partialArrHashValue))
                if(ArrayUtils.compare(subarray, partialArr) == 0)
                    return i;
        }
        return -1;
    }

    /** Find sum of all elements in a <code>Number</code> array
     * @param arr Array of <code>Number</code>
     * @return Sum of all elements in <code>arr</code> as a <code>double</code>
     */
    public static double sum(Number[] arr){
        if(arr.length == 0)
            return 0;
        return Arrays.stream(arr).parallel().mapToDouble(Number::doubleValue).sum();
    }

    /** Compares lexicographically 2 arrays of <code>Number</code>
     * @param arr1 First <code>Number</code> array
     * @param arr2 Second <code>Number</code> array
     * @return 0 if both arrays are lexicographically equal, 1 if <code>arr1</code> is lexicographically greater than
     * <code>arr2</code>, or -1 if <code>arr1</code> is lexicographically less than <code>arr2</code>
     */
    public static int compare(Number[] arr1, Number[] arr2){
        if(arr1 == null && arr2 == null)
            return 0;
        else if(arr1 == null)
            return -1;
        else if(arr2 == null)
            return 1;
        int index = 0;
        while(index <= Math.max(arr1.length, arr2.length) - 1){
            if(arr1[index].doubleValue() > arr2[index].doubleValue())
                return 1;
            else if(arr1[index].doubleValue() < arr2[index].doubleValue())
                return -1;
            try {
                Preconditions.checkElementIndex(index, arr1.length);
            } catch (IndexOutOfBoundsException e) {
                return -1;
            }
            try {
                Preconditions.checkElementIndex(index, arr2.length);
            } catch (IndexOutOfBoundsException e) {
                return 1;
            }
            ++index;
        }
        return 0;
    }
}
