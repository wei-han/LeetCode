class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(v1.size() >0) q.push({v1.begin(),v1.end()});
        if(v2.size() >0) q.push({v2.begin(),v2.end()});
    }

    int next() {
        vector<int>::iterator it = q.front().first;
        vector<int>::iterator end = q.front().second;
        q.pop();
        if(it+1 != end){
            q.push({it+1, end});
        }
        return *it;
    }

    bool hasNext() {
        return !q.empty();
    }
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
