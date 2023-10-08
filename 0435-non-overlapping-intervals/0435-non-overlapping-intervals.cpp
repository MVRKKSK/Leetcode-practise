class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int n = intervals.size();
        int count = 0;
        int first = intervals[0][0];
        int second = intervals[0][1];
        for(int i=1;i<n;i++){
            if(second>intervals[i][0]){
                count++;
                second=min(second , intervals[i][1]);
            }
            else{
                first = intervals[i][0];
                second = intervals[i][1];
            }
        }
        return count;
    }
};