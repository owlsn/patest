import java.util.ArrayList;
import java.util.List;
class ambiguousCoordinates{

    public static void main(String argv[]){
        String test = "(100)";
        List<String> str = new ArrayList<String>();
        ambiguousCoordinates am = new ambiguousCoordinates();
        str = am.ambiguousCoordinates(test);
        System.out.print(str);
    }

    public List<String> ambiguousCoordinates(String S) {
        List<String> result = new ArrayList<String>();
        String str = S.substring(1, S.length() - 1);
        int len = str.length();
        List<String> pre = new ArrayList<String>();
        List<String> after = new ArrayList<String>();
        String temp = "";
        for(int i = 1; i < len; i ++){
            pre = this.spt(str.substring(0, i));
            after = this.spt(str.substring(i, len));
            if(pre.size() != 0 && after.size() != 0){
                for(int j = 0 ; j < pre.size(); j ++){
                    for(int k = 0 ; k < after.size(); k ++){
                        result.add('(' + pre.get(j) + ", " + after.get(k) + ')');
                    }
                }
            }
        }
        return result;
    }

    private List<String> spt(String S){
        int len = S.length();
        List<String> result = new ArrayList<String>();
        if(len == 0){
            return result;
        }
        if(len == 1){
            result.add(S);
            return result;
        }
        String first = S.substring(0, 1), last = S.substring(len - 1, len);
        if(first.equals("0")){
            if(last.equals("0")){
                return result;
            }
            else{
                result.add("0." + S.substring(1, len));
                return result;
            }
        }
        if(last.equals("0") && !first.equals("0")){
            result.add(S);
            return result;
        }
        for(int i = 1; i < len; i ++){
            result.add(S.substring(0,i) + '.' + S.substring(i, len));
        }
        result.add(S);
        return result;
    }

}