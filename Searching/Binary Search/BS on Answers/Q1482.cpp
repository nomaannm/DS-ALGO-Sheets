class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        if(val > bloomDay.size()) return -1;
        int ans = -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for(auto x : bloomDay){
            mini = min(mini,x);
            maxi = max(maxi,x);
        }

        int low = mini, high = maxi;
        while(low <= high){
            int mid = (low + high)/2;
            if(possible(bloomDay,mid,m,k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
        
    }

    bool possible(vector<int>& BDay, int day, int& m , int& k){
        int noOfBouquets = 0;
        int cnt = 0;
        for(int i = 0 ; i < BDay.size() ; i++){
            if(BDay[i] <= day) cnt++;
            else{
                noOfBouquets += (cnt/k);
                cnt = 0;
            }
        }
        noOfBouquets += (cnt/k);
        return noOfBouquets >= m;
    }
};
