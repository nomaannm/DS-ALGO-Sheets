class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    vector<int> primeFactors;
	    for(int i = 2 ; i * i <= N; i++){
	        if(N % i == 0 && isPrime(i)) primeFactors.push_back(i);
	        if(N/i != i && N % (N/i) == 0 && isPrime(N/i)) primeFactors.push_back(N/i);
	    }
	    if(N > 1 && isPrime(N)) primeFactors.push_back(N);
	    return primeFactors;
	}
	
	bool isPrime(int n){
	    if(n <= 1) return false;
	    for(int i = 2; i * i <= n; i++){
	        if(n % i == 0) return false;
	    }
	    return true;
	}
};
