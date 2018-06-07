class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> stk;
        int low = INT_MIN;
        for(int i = 0; i<preorder.size(); i++){
            if(stk.empty()|| preorder[i]<preorder[i-1]){
                stk.push(preorder[i]);
                if(preorder[i]<=low) return false;
            }
            else{
                while(!stk.empty() && stk.top()<preorder[i]){                                        
                    low = stk.top();
                    stk.pop();
                }
                stk.push(preorder[i]);
            }
        }
        return true;
    }
};
