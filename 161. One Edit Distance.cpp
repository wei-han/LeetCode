class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if(m-n>1) return false;
        if(m<n) return isOneEditDistance(t, s);
        int mismatch = false;
        for(int i = 0; i<n;i++){
            if(s[i]!=t[i]){
                mismatch = true;
                if(m==n) {
                    s[i] = t[i];
                }
                else {
                    t.insert(i,1,s[i]);
                }
                break;
            }
        }
        return (mismatch && s==t) || (!mismatch&&m-n==1);
    }
};
