class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return sub(n, n);
    }
    
    vector<string> sub(int m, int n){
        if(m==0) return vector<string>({""});
        if(m==1) return vector<string>({"1", "0", "8"});
        vector<string>res;
        vector<string>temp = sub(m-2, n);
        for(int i = 0; i<temp.size(); i++){            
            if(m != n) res.push_back("0" + temp[i] + "0");
            res.push_back("1"+temp[i]+"1");
            res.push_back("8"+temp[i]+"8");
            res.push_back("6"+temp[i]+"9");
            res.push_back("9"+temp[i]+"6");
        }

        return res;
    }
};
