class Solution {
    vector<unordered_set<int>>make(int num, vector<pair<int,int>>&pre){
        vector<unordered_set<int>> graph(num);
        for(auto item: pre){
            graph[item.second].insert(item.first);
        }
        return graph;
    }
    
    vector<int> compute(vector<unordered_set<int>> graph){
        vector<int> degree(graph.size(), 0);
        for(auto item: graph){
            for(auto neigh: item){
                degree[neigh]++;
            }
        }
        return degree;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make(numCourses, prerequisites);
        vector<int> degree = compute(graph);
        
        for(int i = 0; i<numCourses; i++){
            int j = 0;
            for(;j<numCourses; j++)
                if(degree[j] == 0) break;
            if(j==numCourses) return false;
            
            degree[j] = -1;
            for(auto item: graph[j]) degree[item]--;
        }
        
        return true;
    }
};


class Solution {
    vector<unordered_set<int>>make(int num, vector<pair<int,int>>&pre){
        vector<unordered_set<int>> graph(num);
        for(auto item: pre){
            graph[item.second].insert(item.first);
        }
        return graph;
    }
    
    bool dfs(vector<unordered_set<int>>& graph, int node, vector<bool>&path, vector<bool>&visited){
        if(visited[node]) return false;
        visited[node] = true;
        path[node] = true;
        for(int item: graph[node]){
            if(path[item] || dfs(graph, item, path, visited))
                return true;
        }
        path[node] = false;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make(numCourses, prerequisites);
        vector<bool>visited(numCourses, false);
        vector<bool>path(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            if(!visited[i] &&dfs(graph, i, path, visited)) return false;
        }           
        return true;
    }
};
