//sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> nums(n, true);
        nums[0] = false;
        nums[1] = false;
        for(int i = 0; i*i < n; i++){
            if(nums[i]){
                for(int j = i*i; j<n; j+=i){
                    nums[j] = false;
                }                    
            }
        }

        return count(nums.begin(), nums.end(), true);
    }
};
