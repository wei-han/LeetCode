class Solution {
    vector<unordered_set<int>> make(int numCourses, vector<pair<int,int>>& pre){
        vector<unordered_set<int>> graph(numCourses);
        for(auto item: pre){
            graph[item.second].insert(item.first);
        }
        return graph;
    }
    
    vector<int> compute(vector<unordered_set<int>> graph){
        vector<int> degree(graph.size(), 0);
        for(auto item: graph){
            for(auto neig: item)
            degree[neig]++;
        }
        return degree;
    }
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make(numCourses, prerequisites);
        vector<int> degree = compute(graph);
        vector<int> res;
        for(int i = 0; i<numCourses; i++){
            int j = 0;
            for(;j<numCourses;j++)
                if(degree[j]==0) break;
            if(j==numCourses) return {};
            res.push_back(j);
            degree[j] = -1;
            
            for(auto item: graph[j]) degree[item]--;
        }
        return res;
    }
};
