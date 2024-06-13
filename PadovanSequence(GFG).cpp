class Solution
{
    public:
    int padovanSequence(int n)
    {
       const int MOD = 1e9 + 7;
       if(n == 0 || n == 1 || n == 2) return 1;
       
       vector<int> padovan(n+1);
       padovan[0] = padovan[1] = padovan[2] = 1;
       
       for(int i = 3 ; i <= n ; i++){
           padovan[i] =(padovan[i - 2] + padovan[i - 3]) % MOD ;
       }
       
       return padovan[n];
    } 
  
};
