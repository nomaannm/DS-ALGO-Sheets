class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1) return 1;
        int totalCandies = n;
        int i = 1;
        
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            int currentPeak = 0;
            while(i < n && ratings[i] > ratings[i-1]){
                currentPeak += 1;
                totalCandies += currentPeak;
                i++;
            }

            int currentValley = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                currentValley += 1;
                totalCandies += currentValley;
                i++;
            }

            totalCandies -= min(currentPeak, currentValley);


        }

        return totalCandies;
        
    }
};
