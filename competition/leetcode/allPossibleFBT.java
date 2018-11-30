import java.util.ArrayList;
import java.util.List;
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 * 输入：7
 * 输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 */

public class allPossibleFBT{

    public static void main(String argv[]){
        int input = 7;
        List<TreeNode> li = new ArrayList<TreeNode>();
        allPossibleFBT res = new allPossibleFBT();
        li = res.allPossibleFBT(input);
        System.out.print(li);
    }

    /**
     * 生成所有的满二叉树，并返回根节点
     * @param N
     * @return
     */
    public List<TreeNode> allPossibleFBT(int N) {
        List<TreeNode> li = new ArrayList<TreeNode>();
        if(N == 0){
            return li;
        }
        if(N == 1){
            TreeNode root = new TreeNode(0);
            li.add(root);
            return li;
        }
        N = N - 1;
        for(int i = 1; i <= N; i += 2){
            for(TreeNode left: allPossibleFBT(i)){
                for(TreeNode right: allPossibleFBT(N - i)){
                    TreeNode root = new TreeNode(0);
                    root.left = left;
                    root.right = right;
                    li.add(root);
                }
            }
        }
        return li;
    }

}