class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int num1 = 0;
        long long int num2 = 0;
        long long int XORR = 0;
        for (int i = 0; i < N; i++){
            XORR ^= Arr[i];
        }
        
        auto rightmost_bit = (XORR & (XORR-1)) ^ XORR;
        
        for(int i = 0; i < N; i++){
            if(Arr[i] & rightmost_bit) num1 ^= Arr[i];
            else num2 ^= Arr[i];
        }
        vector<long long int> ans = (num1 > num2) ? vector<long long int>{num1,num2} : vector<long long int>{num2,num1};
        return ans;
    }
};
