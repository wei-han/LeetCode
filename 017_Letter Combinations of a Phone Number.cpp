class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits == "") return ans;
        ans.push_back("");// without this, line 16 will be invalid always 
        
        vector<string> cell={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        for (int i = 0; i < digits.length(); i++)
        {       
            vector<string> temp;
            
            string candidate = cell[digits[i] - '0'];
            
            for (int j = 0; j < ans.size(); j++)
            {
                for(int k = 0; k < candidate.length(); k++)
                {
                    temp.push_back(ans[j]+candidate[k]);
                }
            }        
            ans.swap(temp);
        }
        return ans;
    }
};



//solution with queue
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits == "") return ans;
        
        queue<string> temp;
        temp.push("");
        
        string candidates[] =  {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        for(int i = 0; i<digits.size(); i++){
            string candidate = candidates[digits[i] - '0'];
            while(temp.front().size() == i){
                for(int j = 0; j<candidate.size(); j++)
                    temp.push(temp.front() + candidate[j]);
                temp.pop();                
            }
        }
        
        while(!temp.empty()){
            ans.push_back(temp.front());
            temp.pop();
        }
        
        return ans;
    }
};
