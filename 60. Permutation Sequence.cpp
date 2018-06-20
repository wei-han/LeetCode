class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fac(n+1);
        vector<int> num;
        string res;
        fac[0] = 1;
        for(int i = 1; i<n+1; i++){
            fac[i] = i* fac[i-1];
        }
        for(int i =1; i< n+1; i++){
            num.push_back(i);
        }
        
        k--;
        for(int i = 1; i<=n; i++){
            int index = k/fac[n-i];
            res += to_string(num[index]);
            num.erase(num.begin() + index);
            k-=index*fac[n-i];
        }
        return res;
    }
};
