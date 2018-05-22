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
//find_first_of and swap
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        
        while(i<j){
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if(i<j) swap(s[i++], s[j--]);
        }
        return s;
    }
};
