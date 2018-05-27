//color sort and virtual indexing.
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        auto midptr = nums.begin()+len/2;
        nth_element(nums.begin(), midptr, nums.end());
        
        int midnum = *midptr;
        
        int i = 0, j = 0, n = len-1;
        #define A(i) nums[(1+2*i)%(len|1)]

        while(j<=n){
            if(A(j)>midnum){
                swap(A(i++), A(j++));
            }
            else if(A(j)<midnum){
                swap(A(j), A(n--));
            }
            else{
                j++;
            }
        }
    }
};
