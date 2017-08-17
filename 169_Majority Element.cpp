class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int i = 0; i < nums.size(); i++)
        {

                count[nums[i]]++;
                if (count[nums[i]] > nums.size()/2) return nums[i];


        }
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int i = 0; i < nums.size(); i++)
        {
            if(count.find(nums[i]) == count.end())
            {
                count[nums[i]] = 1;
                if (count[nums[i]] > nums.size()/2) return nums[i];
            }
            else
            {
                count[nums[i]]++;
                if (count[nums[i]] > nums.size()/2) return nums[i];                
            }
        }
    }
};
