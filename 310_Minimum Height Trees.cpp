//remove all leaves until one or two are left
public:
    struct node{
        unordered_set<int> neighbor;
        bool isLeaf() {return neighbor.size()==1;}
    };
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<node> nodes(n);
        vector<int> buffer1;
        vector<int> buffer2;
        
        if(n == 1){
            buffer1.push_back(0);
            return buffer1;
        }
        
        if( n == 2){
            buffer1.push_back(0);
            buffer1.push_back(1);
            return buffer1;
        }
        
        for(auto e:edges){
            nodes[e.first].neighbor.insert(e.second);
            nodes[e.second].neighbor.insert(e.first);
        }
        
        for(int i = 0; i<n; i++){
            if(nodes[i].isLeaf()) buffer1.push_back(i);
        }
        
        while(true){
            for(int i: buffer1){
                for(auto n: nodes[i].neighbor){
                    nodes[n].neighbor.erase(i);
                    if(nodes[n].isLeaf()) buffer2.push_back(n);
                }
            }
            
            if(buffer2.empty()){
                return buffer1;
            }
            buffer1.clear();
            swap(buffer1, buffer2);
        }
    }
};
