/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int>hash;
        for(Interval item: intervals){
            hash[item.start] +=1;
            hash[item.end]-=1;
        }
        int res = 0, temp = 0;
        for(auto item: hash){
            res = max(res, temp+=item.second);
        }
        return res;
    }
};
