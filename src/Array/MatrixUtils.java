package Array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;
import java.util.stream.Collectors;

import com.google.common.base.Preconditions;

public abstract class MatrixUtils {
    //MEMBER FUNCTIONS
    /** Checks if all elements in given matrix is <code>null</code>
     * @param matrix 2D <code>Number</code> array
     * @return <code>true</code> if <code>matrix</code> only contains <code>null</code> as elements
     */
    public static boolean isAllNull(Number[][] matrix){
        try {
            Preconditions.checkNotNull(matrix);
        } catch (NullPointerException e) {
            return true;
        }
        return Arrays.stream(matrix).flatMap(Arrays::stream).parallel().allMatch(Objects::isNull);
    }

    /** Checks if any elements in given matrix is <code>null</code>
     * @param matrix 2D <code>Number</code> array
     * @return <code>true</code> if <code>matrix</code> contains any <code>null</code> elements
     */
    public static boolean containsNull(Number[][] matrix) {
        try {
            Preconditions.checkNotNull(matrix);
        } catch (NullPointerException e) {
            return true;
        }
        return Arrays.stream(matrix).flatMap(Arrays::stream).parallel().anyMatch(Objects::isNull);
    }

    /** Checks if given matrix is a jagged 2D array
     * @param matrix 2D <code>Number</code> array
     * @return <code>true</code> if 2 or more rows in <code>matrix</code> have differing lengths
     */
    public static boolean isJagged(Number[][] matrix){
        try {
            Preconditions.checkNotNull(matrix);
        } catch (NullPointerException e) {
            e.printStackTrace();
        }
        return !Arrays.stream(matrix).parallel().allMatch(n -> n.length == matrix[0].length);
    }

    /** Checks whether given matrix can actually contain elements by verifying positive row and column sizes
     * @param matrix 2D <code>Number</code> array
     * @return <code>true</code> if <code>matrix</code> is a non-jagged rectangular 2D array with a positive number of
     * rows and a positive number of columns
     */
    public static boolean isNondegenerate(Number[][] matrix){
        try {
            Preconditions.checkNotNull(matrix);
        } catch (NullPointerException e) {
            return false;
        }
        return matrix.length >= 1 && matrix[0].length >= 1 && !MatrixUtils.isJagged(matrix);
    }

    /** Traverses given matrix in a counterclockwise/clockwise direction from top left element
     * @param matrix
     * @param visited
     * @param print
     */
    public static void spiralTraversal(Number[][] matrix, Number[] visited, boolean print){
        if(matrix == null || matrix.length == 0 || Arrays.stream(matrix).mapToInt(n -> n.length).anyMatch(size -> size != matrix[0].length))
            return;
        visited = new Number[matrix.length * matrix[0].length];
        ArrayList<Number> visitedList = new ArrayList<>();
        if(matrix.length == 1)
            visited = Arrays.copyOf(matrix[0], matrix[0].length);
        else if(Arrays.stream(matrix).mapToInt(n -> n.length).distinct().count() == 1)
            Arrays.stream(matrix).map(n -> n[0]).collect(Collectors.toList()).toArray(visited);
        else {
            int leftBorder, rightBorder, topBorder, bottomBorder;
            for(int layer = 1; layer <= Math.min(matrix.length, matrix[0].length) / 2; layer++){
                leftBorder = layer;
                rightBorder = matrix[0].length - layer + 1;
                topBorder = layer;
                bottomBorder = matrix.length - layer + 1;
                visitedList.addAll(Arrays.asList(Arrays.copyOf(matrix[topBorder - 1], matrix[0].length)));
                for(int i = topBorder + 1; i <= matrix.length - layer; i++)
                    visitedList.add(matrix[i - 1][rightBorder - 1]);
                visitedList.addAll(Arrays.asList(Arrays.copyOf(matrix[bottomBorder - 1], matrix[0].length)));
                for(int i = bottomBorder - 1; i >= topBorder + 1; i--)
                    visitedList.add(matrix[i - 1][leftBorder - 1]);
            }
            if(matrix.length > matrix[0].length && matrix.length % 2 == 1){

            } else if(matrix.length < matrix[0].length && matrix[0].length % 2 == 1){


            } else if(matrix.length % 2 == 1 && matrix[0].length %2 == 1)
                visitedList.add(matrix[matrix.length / 2][matrix.length / 2]);
            visitedList.toArray(visited);
            if(print) {
                for (Number el : visitedList)
                    System.out.print(el + "\t");
                System.out.println("");
            }
        }
    }

    /**
     * @return
     */
    public static int[] maximumSumRectangle(Number[][] matrix){
        try {
            Preconditions.checkNotNull(matrix);
            if(MatrixUtils.containsNull(matrix))
                throw new NullPointerException("Matrix must not contain any null elements!");
            Preconditions.checkArgument(MatrixUtils.isNondegenerate(matrix));
        } catch (NullPointerException | IllegalArgumentException e) {
            e.printStackTrace();
        }
        int left, right;
        double[] sumColumn = new double[matrix.length];
        for(left = 0; left <= matrix.length - 1; left++){
            sumColumn = MatrixUtils.getColumn(left);


        }
    }



}
