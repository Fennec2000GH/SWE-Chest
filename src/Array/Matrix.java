package Array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.Collectors;

public abstract class Matrix {
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

    public static int[] maximumSumRectangle(){}
}
