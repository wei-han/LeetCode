class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size()-1;
        while(low < high){
            int mid = (low + high) / 2;
            int count = 0;
            for(int i = 0; i < nums.size(); i++){
                if( nums[i] <= mid) count++;            
            }
            
            if(count > mid){
                low = low;
                high = mid;
            }
            else{
                low = mid +1;
                high = high;
            }
        }
        return low;
    }
};
