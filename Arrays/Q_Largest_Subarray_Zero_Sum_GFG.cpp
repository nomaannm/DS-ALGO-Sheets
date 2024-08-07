#define MAP_PREFIX_SUM_TO_INDEX map
class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        int maxLen = 0;
        MAP_PREFIX_SUM_TO_INDEX<long long,int> mpp;
        long long sum = 0;
        for(int i= 0; i < n; i++){
            sum += arr[i];
            if(sum == 0){
                maxLen = i+1;
            }
            else{
                if(mpp.find(sum) != mpp.end()){
                    int len = i - mpp[sum];
                    maxLen = (maxLen < len) ? len : maxLen;
                }else{
                    mpp[sum] = i;
                }
            }
        }
        
        return maxLen;
    }
};
