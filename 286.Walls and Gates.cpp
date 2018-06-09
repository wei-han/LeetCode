class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int len = rooms.size();
        if(len ==0 ) return;
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(int i = 0; i<rooms.size(); i++){
            for(int j = 0; j < rooms[0].size(); j++){
                if(rooms[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            int i=q.front().first, j = q.front().second;
            q.pop();
            for(auto d:dir){
                int x = i+d.first, y=j+d.second;
                if(x<0 || y<0 || x>=rooms.size() || y>=rooms[0].size() || rooms[x][y]<=rooms[i][j]+1) continue;
                rooms[x][y] = rooms[i][j]+1;
                q.push({x,y});
            }
        }
    }
};
