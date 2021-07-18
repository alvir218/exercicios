package one.digitalinnovation.javabasico1.arrays16;

public class Arrays1 {
    public static void main(String[] args) {

        Integer[] integers = new Integer[3];

        int[] ints = {1,2,3,4,5,6};

        integers[0] = 5;

        System.out.println("tamanho do array integers contando do 1: \n"
                + integers.length);
         //3

        System.out.println("tamanho do array ints contando do 1: \n"
                + ints.length);
          //6

          //percorrer array
        System.out.println("percorrendo array");
        for(int i = 0; i < 6; i++){
            System.out.println(ints[i]);
        }

          //array multidimensional
          //matrix
        int[][] matrix = {{7,8,9,10},{11,12,13}};

          //varredura matrix
        System.out.println("varredura na matrix");
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[i].length; j++){
                System.out.println(matrix[i][j]);
            }
        }
    }
}
