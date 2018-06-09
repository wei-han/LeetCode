//not a good solution
class Solution {
public:
    bool canWin(string s) {
        int len = s.size();
        for(int i = 0; i<len-1; i++){
            if(s.substr(i,2)=="++"){
                string next = s.substr(0,i) + "--" + s.substr(i+2);
                if(!canWin(next)) return true;
            }
        }
        return false;
    }
};
