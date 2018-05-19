class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int count = len;
        int first = 0;
        int mid;
        int step;
        
        while( count>0 ){
            step = count/2;
            mid = first+step;
            if(citations[mid] < len - mid){
                first = mid+1;
                count -= ( step+1 );
            }
            else{
                count = step;
            }
        }
        return len - first;
    }
};
