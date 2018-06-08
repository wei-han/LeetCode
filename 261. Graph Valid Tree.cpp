//union-find with path compression
class Solution {
public:
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> nodes(n, -1);
        for(int i = 0; i<edges.size(); i++){
            int left = find(nodes, edges[i].first);
            int right = find(nodes, edges[i].second);
            if(right == left) return false;
            nodes[left] = nodes[right]==-1?right:nodes[right];
        }
        return n-1==edges.size();
    }
    
    
    int find(vector<int>parent, int i){
        if(parent[i]==-1) return i;
        return find(parent, parent[i]);
    }
};
