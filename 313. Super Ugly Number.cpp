class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(n,INT_MAX);
        vector<int> ptr(primes.size(),0);
        res[0] = 1;
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j< primes.size(); j++){
                res[i] = min(res[i], res[ptr[j]]*primes[j]);
            }
            
            for(int j = 0; j<primes.size(); j++){
                if(res[i] == res[ptr[j]]*primes[j])ptr[j]++;
            }
        }
        return res[n-1];
    }
};
