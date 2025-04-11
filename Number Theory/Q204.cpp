class Solution {
public:
    int countPrimes(int n) {
        vector<bool> arePrimes(n+1, true);
        if(n <= 2) return 0;
        
        arePrimes[0] = arePrimes[1] = false;

        for(int i=2; i*i <= n; i++){
            if(arePrimes[i]){
                for(int j=i*i; j <= n; j += i){
                    arePrimes[j] = false;
                }
            }
        }

        int count = 0;
        for(int i=0; i < n; i++){
            if(arePrimes[i]) count += 1;
        }


        return count;
    }
};
