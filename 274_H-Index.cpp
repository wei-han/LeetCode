//use bucket array to eliminate the repeated counting.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int bucket[len+1] ={0};
        
        for(int i : citations){
            if(i >= len){
                bucket[len]++;
            }
            else{
                bucket[i]++;
            }
        }
        int count = 0;
        for(int i = len; i>=0; i--){
            count += bucket[i];
            if( count>= i) return i;
        }
    }
};

//naive solution
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res = 0;
        for(int i = citations.size(); i>=0; i--){
            int count = 0;
            for(int j = 0; j<citations.size(); j++){
                if(citations[j]>=i) count++;
            }
            if (count >= i) {
                return i;
            }
        }
    }
};
