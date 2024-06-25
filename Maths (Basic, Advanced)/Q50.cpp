class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        bool sign = true;
        if(n < 0) sign = false;
        n = abs(n);
        double ans = 1;
        while(n > 0){
            if(n % 2 == 0){
                x *= x;
                n /= 2;
            }
            else{
                ans *= x;
                n -= 1;
            }


        }

        if(!sign) return 1/ans;
        return ans;
        
    }
};
