class Vector2D {
    vector<vector<int>>::iterator i, iend;
    int j = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        iend = vec2d.end();
    }

    int next() {
        return (*i)[j++];
    }

    bool hasNext() {
        while(i!=iend && j==(*i).size())
        {
            i++;
            j=0;
        }
        return i!=iend;

    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
