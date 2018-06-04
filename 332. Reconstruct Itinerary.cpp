class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> graph;
        vector<string> ans;
        stack<string> rev;
        
        if(tickets.size() == 0) return ans;
        for(auto item: tickets){
            graph[item.first].insert(item.second);
        }
		rev.push("JFK");
        
        while(!rev.empty()){
            string top = rev.top();
            if(graph[top].empty()){
                ans.push_back(top);
                rev.pop();
            }
            else{
                rev.push(*(graph[top].begin()));
                graph[top].erase(graph[top].begin());
            }
        }
        reverse (ans.begin(), ans.end());
        return ans;
    }
};
