/**
* Problem NO : 69
*/
class Solution {
public:
    int mySqrt(int x) {
        // Binary Search
        if (x <= 1) return x ;
        int start = 1 ; int end = x ; int mid = -1 ;
        while (start <= end)
        {
            mid = ( start + end ) / 2 ;
            
            //converting mid to long to handle large values
            long long square = static_cast<long long>(mid) * mid ;
            if(square > x) end = mid - 1;
            else if (square == x) return mid ;
            else start = mid + 1 ;
        }

        return static_cast<int>(std::round(end));

        
    }
};
