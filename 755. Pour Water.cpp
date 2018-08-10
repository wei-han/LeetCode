class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for(int i = 0; i< V; i++){
            int j = K;
            while(j>0 && heights[j-1]<=heights[j]) j--;            
            while(j<K && heights[j+1]==heights[j]) j++;
            if(j==K){
                while(j<heights.size()-1&& heights[j+1]<=heights[j])j++;
                while(j>K && heights[j-1] == heights[j]) j--;
            }
            heights[j]++;
        }
        return heights;
    }
};
