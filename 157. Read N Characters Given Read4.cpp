// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        int temp = 4;
        for(int i = 0; i<=n/4&&temp!=0; i++){
            temp = read4(buf + count);
            count +=temp;
        }
        return min(count, n);
    }
};
