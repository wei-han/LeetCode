//dp
class Solution {
public:
    int numSquares(int n) {
        vector<int> count;
        count.push_back(0);
        
        while(count.size()<=n){
            int cur = count.size();
            int cnt = INT_MAX;
            for(int i = 1; i*i <= cur; i++){
                cnt = min(cnt, count[cur - i*i] + 1);
            }
            count.push_back(cnt);
        }
        return count[n];
    }
};


//time limit exceeds
class Solution {
public:
    int numSquares(int n) {
        set<int> res;
        sub(n, 0, res);
        return *(res.begin());
    }
    
    void sub(int n, int num, set<int> &res){
        if(n<0) return;
        if(n==0) res.insert(num);
        if(n>0){
            int root = floor(sqrt(n));
            for(int i = root; i>=1; i--){
                num++;
                sub(n-pow(i,2), num, res);
                num--;
            }
        }
    }
};
