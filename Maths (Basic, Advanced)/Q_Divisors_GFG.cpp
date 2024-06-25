void print_divisors(int n) {
        vector<int> ans;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0) {
                ans.push_back(i);
                if(n / i != i) ans.push_back(n/i);
            }
        }
        sort(begin(ans), end(ans));
        for(auto x : ans){
            cout << x << " ";
        }
}
