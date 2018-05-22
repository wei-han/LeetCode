//use bucket
class NumArray {
private:
    struct bucket{
        vector<int> val;
        int sum;
    };
    vector<bucket> array;
    int bucketSize;
    int bucketNum;
public:
    NumArray(vector<int> nums) {
        int len = nums.size();
        bucketNum = (int)sqrt(2*len);
        bucketSize = bucketNum/2;
        while(bucketSize*bucketNum < len)bucketSize++;
        array.resize(bucketNum);
        
        for(int i = 0, k = 0; i<bucketNum; i++){
            int temp = 0;
            array[i].val.resize(bucketSize);
            for(int j = 0; j<bucketSize && k <len; j++, k++){
                temp+= nums[k];
                array[i].val[j] = (nums[k]);
            }
            array[i].sum = temp;
        }
    }
    
    void update(int i, int val) {
        int bucketNo = i/bucketSize;
        int eleNo = i%bucketSize;
        int diff = val - array[bucketNo].val[eleNo];
        array[bucketNo].val[eleNo] = val;
        array[bucketNo].sum += diff;
    }
    
    int sumRange(int i, int j) {
        int beginBucketNo = i/bucketSize;
        int beginEleNo = i%bucketSize;
        int endBucketNo = j/bucketSize;
        int endEleNo = j%bucketSize;
        
        int res = 0;
        if(beginBucketNo == endBucketNo){
            for(int k = beginEleNo; k<= endEleNo; k++ ){
                res+= array[beginBucketNo].val[k];
            }
        }
        else{
            for(int k = beginBucketNo+1; k<endBucketNo; k++){
                res+= array[k].sum;
            }
            
            for(int k = beginEleNo; k<bucketSize; k++){
                res +=  array[beginBucketNo].val[k];
            }
            for(int k = 0; k<=endEleNo; k++){
                res +=  array[endBucketNo].val[k];
            }
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */




//time exceeds limit
class NumArray {
public:
    NumArray(vector<int> nums) {
        array.push_back(0);
        int sum = 0;
        for(int ele: nums){
            sum += ele;
            array.push_back(sum);
        }
    }
    
    void update(int i, int val) {
        int diff = sumRange(i,i) - val;
        for(int j = i+1; j<array.size(); j++){
            array[j]-=diff;
        }
    }
    
    int sumRange(int i, int j) {
        return array[j+1] - array[i];
    }
private:
    vector<int> array;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
