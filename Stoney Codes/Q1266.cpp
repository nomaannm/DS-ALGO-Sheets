// TC : O(N)
// SC : O(1)
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x1 = points[0][0];
        int y1 = points[0][1];

        int time = 0;
        for(int i=1; i < points.size(); i++){
            int x2 = points[i][0];
            int y2 = points[i][1];

            time += max(abs(x2-x1), abs(y2-y1));
            x1 = x2;
            y1 = y2;
        }

        return time;
        
    }
};
