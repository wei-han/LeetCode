//outdegree - indegree
class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] tree = preorder.split(",");
        int diff = 1;
        for(String c: tree){
            diff--;
            if(diff<0) return false;
            if(!c.equals("#")) diff+=2;
        }
        return diff==0;
    }
}
//stack
class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] tree = preorder.split(",");
        Stack<String> st = new Stack<>();
        for(String c: tree){
            if(!c.equals("#")) st.push(c);
            else{
                while(!st.empty() && st.peek().equals("#")){
                    st.pop();
                    if(st.empty()) return false;
                    st.pop();
                }
                st.push("#");
            }
        }
        return st.size()==1 && st.peek().equals("#");
    }
}
