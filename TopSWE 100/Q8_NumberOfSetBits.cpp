class Solution {
public:
    int hammingWeight(int n) {
        if(n == 0 || n == 1) return n;
        int setBits = 0;
        while(n > 1){
            if(n % 2 == 1) setBits++;
            n /= 2;

        }
        setBits++;

        return setBits;
        
    }
};
