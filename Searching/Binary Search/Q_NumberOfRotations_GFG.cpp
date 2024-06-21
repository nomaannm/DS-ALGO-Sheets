// Last for-loop can be eliminated by not using built-in 'min()' function and updating the index there.
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    if(n==1) return 0;
	    if((n == 2) && (arr[0] > arr[1])) return 1;
	    int minElement = INT_MAX;
	    int indexOfMinElement = INT_MAX;
	    int low = 0 ;
	    int high = n-1;
	    while(low <= high){
	        int mid = (low + high)/2;
	        minElement = min(minElement, arr[mid]);
	        if(arr[low] <= arr[mid]){
	            minElement = min(minElement,arr[low]);
	            low = mid+1;
	        }
	        else high = mid-1;
	    }
	    
	    for(auto i = 0 ; i < n ; i++){
	        if(arr[i] == minElement){
	            indexOfMinElement = i;
	        }
	    }
	    
	    return indexOfMinElement;
	    
	}

};
