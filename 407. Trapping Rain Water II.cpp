class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if(m==0) return 0;
        int n = heightMap[0].size();
        typedef pair<int, int> cell;
        priority_queue<cell, vector<cell>, greater<cell>> pq;
        vector<bool> visit(m*n, false);
        int res = 0;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i ==0 || i==m-1 || j==0 || j==n-1){
                    visit[i*n+j] = true;
                    pq.push({heightMap[i][j], i*n+j});                    
                }
            }
        }
        cell dirs[4] = {{0,1},{0,-1},{-1,0},{1,0}};
        while(!pq.empty()){
            cell temp = pq.top();
            pq.pop();
            int x = temp.second/n, y = temp.second%n;
            for(auto dir: dirs){
                int newx = x+dir.first, newy = y+dir.second;
                if(newx < 0 || newx > m-1 || newy <0 || newy > n-1 || visit[newx*n + newy]) continue;
                res += max(0, temp.first - heightMap[newx][newy]);
                pq.push({max(heightMap[newx][newy],temp.first), newx*n + newy});
                visit[newx*n+newy] = true;
            }
        }
        return res;
    }
};
