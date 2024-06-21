class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long low = 1;
        long long high = x;
        long long ans = 1;
        while(low <= high){
            long long mid = (low + high)/2;
            if(mid * mid <= x){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid -1;}
        }
        return ans;
    }
};
