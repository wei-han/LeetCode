class Solution {
public:
    bool isStrobogrammatic(string num) {
        int len = num.size();
        for(int i = 0; i<(len+1)/2; i++){
            if(num[i]!='1' &&num[i]!='0' &&num[i]!='8' &&num[i]!='6' &&num[i]!='9') return false;
            if(num[i]=='1'|| num[i]=='0'|| num[i]=='8'){
                if(num[i]!=num[len-i-1]) return false;
            }
            if(num[i]=='6' && num[len-i-1]!='9') return false;
            if(num[i]=='9' && num[len-i-1]!='6') return false;
        }
        return true;
    }
};
