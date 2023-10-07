/**
Question No : 278
*/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int badVersions = 0 ;
        for(int i {1} ; i <= n ; i++)
        {
            if(isBadVersion(i))
            {
                badVersions++ ;
                return i ;

            }
            else {
                badVersions += 0;

            }
        }
        return 0 ;
    }
};
