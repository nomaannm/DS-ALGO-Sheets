// CODING NINJAS 
// FACTORIAL PROBLEM FOR STORING IN ARRAY
long long fact(long long n){
    if(n == 0 || n == 1) return 1;
    return n * fact(n-1);
}

vector<long long> factorialNumbers(long long n) {
    vector<long long> ans;
    long long i = 1;
    ans.push_back(i);
    long long store = 1;
    while(store <= n){
        i++;
        store = fact(i);
        if(store <= n){
            ans.push_back(store);
        }
    }
    return ans;
}
