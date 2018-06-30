class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        next_permutation(begin(str), end(str));
        auto res = stol(str);
        return (res>INT_MAX || res <= n) ? -1: res;
    }
};
