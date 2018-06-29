class Solution {
public:
    bool detectCapitalUse(string word) {
        if('a'<=word[0] && word[0]<='z'){
            for(char c: word){
                if('A'<=c && c<='Z') return false;
            }
        }
        else{
            bool A=false, a = false;
            for(int i = 1; i<word.size(); i++){
                if('A'<=word[i] &&word[i]<='Z') A=true;
                if('a'<=word[i] &&word[i]<='z') a=true;
                if(A&&a)return false;
            }
        }
        return true;
    }
};
