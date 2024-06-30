	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int index = -1;
	    int maxCount = 0;
	    for(int i = 0; i < n; i++){
	        int cnt_ones = m - LB(arr[i],m);
	        if(cnt_ones > maxCount){
	            maxCount = cnt_ones;
	            index = i;
	            
	        }
	    }
	    
	    return index;
	    
	}
	
	int LB(vector<int> & arr, int& m){
	    int count = 0;
	    int low = 0, high = m-1;
	    int ans = m;
	    while(low <= high){
	        int mid = (low+high)/2;
	        if(arr[mid] >= 1 ){
	            ans = mid;
	            high = mid-1;
	        }
	        else{
	            low = mid+1;
	        }
	    }
	    
	    return ans;
	}
