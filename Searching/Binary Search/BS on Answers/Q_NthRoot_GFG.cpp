class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    int low = 1 , high = m;
	    while(low <= high){
	        int mid = (low + high)/2;
	        if(pow(mid,n) == m) return mid;
	        else if(pow(mid,n) < m){
	            low = mid+1 ;
	        }
	        else high=mid-1;
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
