class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for( int i = digits.size()-1; i >= 0; i--)
        {
            if(digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                return digits;
            }
        }
        
        digits[0] = 1;
        digits.push_back(0);
        
        return digits;
        
        
    }
};

//a redundant recursive solution!
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        
        plus(digits, len-1);
        
        if(digits[0]==10)    
        {
            vector<int> ans(len+1,0);
            ans[0]=1;
            return ans;
        }
        
        return digits;
        
        
    }
    
    void plus(vector<int>& digits, int k)
    {
        if(digits[k] != 9)
        {
            digits[k]++;
            return;
        }
        else
        {
            if(k==0)
            {
                digits[k]=10;
                return;
            }
            digits[k] = 0;
            plus(digits, k-1);
        }
            
    }
};
