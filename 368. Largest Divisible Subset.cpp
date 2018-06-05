class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        int parent[len+1]={0};
        int no[len+1]={0};
        int first;
        int max = 0;
        
        for(int i = len-1; i>=0; i--){
            for(int j = i; j < len; j++){
                if(nums[j]%nums[i]==0 && no[i] <= no[j]){
                    no[i] = no[j]+1;
                    parent[i] = j;
                    
                    if(no[i]>max){
                        max = no[i];
                        first = i;
                    }
                }
            }
        }
        
        vector<int> res;
        for( int i = 0; i<max; i++){
            res.push_back(nums[first]);
            first = parent[first];
        }
        return res;
    }
};
