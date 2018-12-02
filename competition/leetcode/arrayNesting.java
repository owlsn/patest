import java.util.HashSet;
public class arrayNesting{

    HashSet<Integer> set = new HashSet<Integer>();

    public static void main(String argv[]){
        int[] input = {5,4,0,3,1,6,2};
        arrayNesting an = new arrayNesting();
        int output = an.arrayNesting(input);
        System.out.print(output);
    }

    public int arrayNesting(int[] nums) {
        int max = 0, temp;
        for(int i = 0; i < nums.length; i ++){
            temp = this.max_length(nums, i);
            if(temp > max){
                max = temp;
            }
        }
        return max;
    }

    private int max_length(int[] nums, int k){
        int count = 0;
        while (!set.contains(k)){
            set.add(k);
            count ++;
            k = nums[k];
        }
        return count;
    }

}