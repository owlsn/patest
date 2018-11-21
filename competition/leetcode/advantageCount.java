import java.util.Arrays;

public class advantageCount{

    public static void main(String[] args){
        System.out.println("test");
    }

    public int[] advantageCount(int[] A, int[] B) {
        int len = A.length;
        int[] temp = new int[len];
        Arrays.sort(A);
        Arrays.sort(B);
        for(int i = 0; i < len; i++){
            temp[i] = A[i] - B[i];
        }
        return temp;
    }

}