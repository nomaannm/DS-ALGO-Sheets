class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int low = 1;
        int high = x;
        int sqrt = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mid <= x/mid){
                sqrt = mid;
                low = mid+1;

            } 
            else{
                high = mid-1;
            }
    
        }
        
        return sqrt;
    }
};
