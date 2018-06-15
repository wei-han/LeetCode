class Solution {
public:
    bool judgeCircle(string moves) {
        int ver = 0, hor = 0;
        for(char c: moves){
            if(c =='L') hor--;
            if(c =='R') hor++;
            if(c =='U') ver++;
            if(c =='D') ver--;
        }
        return ver==0 && hor==0;
    }
};
