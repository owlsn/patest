public class arrangeCoins{

    public static void main(String argv[]){
        int input = 0;
        arrangeCoins ac = new arrangeCoins();
        int output = ac.arrangeCoins(input);
        System.out.print(output);
    }

    public int arrangeCoins(int n) {
        long sum = 0;
        int i = 0;
        if(n == 0){
            return 0;
        }
        while (sum < n){
            sum += i ++;
        }
        return (n == sum) ?i - 1:i - 2;
    }

}