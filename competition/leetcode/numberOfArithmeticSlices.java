import java.util.List;
import java.util.ArrayList;
public class numberOfArithmeticSlices{

    public static void main(String argv[]){
        int[] input = {1,2,3,4,5,6};
        numberOfArithmeticSlices na  = new numberOfArithmeticSlices();
        int output = na.numberOfArithmeticSlices(input);
        System.out.print(output);
    }


    public int numberOfArithmeticSlices(int[] A) {
        //判断等差
        //先将最大子序列切割出来
        List<List<Integer>> index = this.parseList(A);
        int len, count = 0;
        for(int i = 0 ; i < index.size(); i ++){
            //统计个数
            count += this.countNums(A, index.get(i).get(0), index.get(i).get(1));
        }
        return count;
    }

    private int countNums(int[] A, int i, int j){
        int count = 0, len = j - i + 1;
        //从步长为0，个数为3开始判断
        //步长 0...
        //判断条件为 start + (nums - 1) * step + nums
        for(int nums = 3; nums <= len; nums ++){
            for(int start = i; start < j ; start ++){
                if(start + nums - 1 <= j){
                    count ++;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }

    //将所有的子序列切割出来
    private List<List<Integer>> parseList(int[] A){
        int start = -1, end = -1;
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        for(int i = 1 ; i < A.length - 1; i ++){
            if((float) A[i] == ((float)(A[i - 1] + A[i + 1])) / 2){
                start = (start == -1) ? i - 1: start;
                end = i + 1;
                if((i + 1) == A.length - 1){
                    if(start != - 1 && end != -1){
                        List<Integer> index = new ArrayList<Integer>();
                        index.add(start);
                        index.add(end);
                        result.add(index);
                    }
                }
            }
            else{
                if(start != - 1 && end != -1){
                    List<Integer> index = new ArrayList<Integer>();
                    index.add(start);
                    index.add(end);
                    result.add(index);
                }
                start = -1;
                end = -1;
            }
        }
        return result;
    }

}