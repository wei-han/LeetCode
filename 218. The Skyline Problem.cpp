class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, cmp> pq;
        vector<pair<int,int>> res;
        
        int len = buildings.size();
        int i = 0, last = 0;
        
        while(i<len ||  (!pq.empty())){
            if(pq.empty() ||
               ((i < len) && (buildings[i][0] <= pq.top().first) && (buildings[i][2] > pq.top().second))){
                if(!res.empty()&&res.back().first == buildings[i][0]){
                    res.back().second = max(res.back().second, buildings[i][2]);
                }
                else{
                    res.push_back({buildings[i][0], buildings[i][2]});
                }
                pq.push({buildings[i][1],buildings[i][2]});
                last = buildings[i][0];
                i++;
                continue;
            }
            
            if((i<len) && (buildings[i][0]<=pq.top().first)){
                if(buildings[i][1]>pq.top().first){
                    pq.push({buildings[i][1], buildings[i][2]});
                }
                i++;
                continue;
            }
            if(!pq.empty()){
                int t = pq.top().first;
                pq.pop();
                if(t>last){
                    while((!pq.empty()) && pq.top().first <= t) pq.pop();
                    int h = pq.empty()? 0 : pq.top().second;
                    res.push_back({t, h});
                    last = t;
                }
            }
            
        }
        return res;
    }
    
    private:
    struct cmp{
      bool operator()(pair<int, int> a, pair<int, int> b){
          return (a.second <= b.second);
        }
    };
};
