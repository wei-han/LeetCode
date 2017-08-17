class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1 = change(version1);
        vector<int> ver2 = change(version2);
        
        int diff = ver1.size() - ver2.size();
        if(diff > 0 ){
            while(diff){
                ver2.push_back(0);
                diff--;
            }
        }
        else{
            while(diff){
                ver1.push_back(0);
                diff++;
            }
        }
        
        for( int i = 0;i<ver1.size();i++)
        {
            if(ver1[i] > ver2[i]) return 1;
            if(ver1[i] < ver2[i]) return -1;
        }
        return 0;
    }
    vector<int> change(string version)
    {
        vector<int> ans;
        int num=0;
        for(int i = 0; i < version.length(); i++)
        {
            if(version.at(i) != '.')
                num = num*10 + (version.at(i) - '0');
            else{
                ans.push_back(num);
                num = 0;                
            }
        }
        ans.push_back(num);
        return ans;
    }
};
