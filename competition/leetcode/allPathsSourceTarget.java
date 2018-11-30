import java.util.*;

public class allPathsSourceTarget{

    public static void main(String argv[]){
        int[][] input = {{4,3,1},{3,2,4},{3},{4},{}};
        allPathsSourceTarget all= new allPathsSourceTarget();
        List<List<Integer>> result = all.allPathsSourceTarget(input);
        System.out.print(result);
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int[][] g = new int[graph.length][graph.length];
        for(int i = 0; i < graph.length; i ++){
            for(int j = 0 ; j < graph[i].length; j ++){
                g[i][graph[i][j]] = 1;
            }
        }
        int start = 0, end = g.length - 1;
        Stack<Integer> st = new Stack<Integer>();
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        st.push(start);
        int[] index = new int[g.length];
        int[] in_stack = new int[g.length];
        int temp;
        boolean flag;
        while (!st.empty()){
            temp = st.peek();
            in_stack[temp] = 1;
            flag = true;
            for(int i = (index[temp] != 0 ? index[temp] + 1: 0); i < g.length; i ++){
                if(in_stack[i] != 1 && g[temp][i] == 1){
                    if(i == end){
                        st.push(i);
                        Stack<Integer> t = new Stack<Integer>();
                        List<Integer> list= new ArrayList<Integer>();
                        int integer;
                        while(!st.empty()){
                            integer = st.pop();
                            t.push(integer);
                        }
                        while (!t.empty()){
                            integer = t.pop();
                            st.push(integer);
                            list.add(integer);
                        }
                        result.add(list);
                        st.pop();
                        continue;
                    }
                    else{
                        st.push(i);
                        flag = false;
                        index[temp] = i;
                        break;
                    }
                }
            }
            if(flag){
                temp = st.pop();
                in_stack[temp] = 0;
                index[temp] = 0;
            }
        }
        return result;
    }

}