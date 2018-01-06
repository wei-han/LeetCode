class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        while (true){
        int pos = partition(nums, left, right);
        if (pos == k-1) return nums[pos];
        if (pos < k-1) left = pos + 1;
        if (pos > k-1) right = pos - 1;
        }
    }
    
    int partition(vector<int>& nums, int left, int right){
        int l = left +1;
        int r = right;
        int pivot = nums[left];
        while(l <= r){
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
            
            // some problems here
            if(nums[l] < pivot &&  nums[r] > pivot)
                swap(nums[l++], nums[r--]);
        }
        swap(nums[left], nums[r]);
        return r;

    }
};
