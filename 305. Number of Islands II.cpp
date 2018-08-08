class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> ans;
        if(m<=0 || n<= 0) return ans;
        vector<int> root(m*n, -1);
        int count =0;
        vector<pair<int, int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        
        for(auto pos: positions){
            int cor = n*pos.first + pos.second;
            root[cor] = cor;
            count++;
            
            for(auto dir: dirs){
                int x = pos.first+dir.first;
                int y = pos.second+dir.second;
                int nb = n*x + y;
                if(x<0||y<0||x>=m||y>=n||root[nb]==-1) continue;
                
                int nbroot = find(root, nb);
                if(nbroot!= cor){
                    root[cor] = nbroot;
                    cor = nbroot;
                    count--;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
    
    int find(vector<int> root, int id){
        while(id != root[id]){
            //root[id] = root[root[id]];
            id = root[id];
        } 
        return id;
    }
};
