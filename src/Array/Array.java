package Array;

import java.util.Arrays;

public abstract class Array {
    public static Number[] kadaneIndex(Number[] arr){
        double maxSum = Double.MIN_VALUE, sum = 0;
        int maxLeftIndex, maxRightIndex, leftIndex = 0, rightIndex;
        for(rightIndex = 0; rightIndex <= arr.length - 1; rightIndex++){
            sum += arr[rightIndex].doubleValue();
            if(sum < 0) {
                ++leftIndex;
                sum = 0;
            } else if(sum > maxSum){
                maxSum = sum;
                maxLeftIndex = leftIndex;
                maxRightIndex = rightIndex;
            }
        }
        return Arrays.
    }

}
