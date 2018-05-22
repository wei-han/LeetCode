class Solution {
public:
    string reverseVowels(string s) {
        vector<char> res(s.size(),'\0');
        vector<char> vowel;
        string ans;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'
               || s[i]=='A'  || s[i]=='E'  || s[i]=='I'  || s[i]=='O'  || s[i]=='U'){
                vowel.push_back(s[i]);
            }
            else{
                res[i] = s[i];
            }
        }
        
        for(int i = 0, j = vowel.size()-1; i<s.size()&&j>=0; i++){
            if(res[i]=='\0'){
                res[i] = vowel[j--];
            }
        }
        
        for(int i = 0; i<res.size(); i++){
            ans+=res[i];
        }
        return ans;
    }
};
