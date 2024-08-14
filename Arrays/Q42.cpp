class Solution {
public:
    int trap(vector<int>& height) {
        auto prefixMax = getPrefixMax(height);
        auto suffixMax = getSuffixMax(height);
        int total = 0;
        for(int i=0 ; i < height.size(); i++){
            int leftMax = prefixMax[i], rightMax = suffixMax[i];
            if(height[i] < leftMax && height[i] < rightMax){
                total += min(leftMax, rightMax) - height[i];
            }

        }


        return total;


    }

    vector<int> getPrefixMax(vector<int>& height){
        vector<int> arr(height.size());
        arr[0] = height[0];
        for(int i=1; i < height.size(); i++ ){
            arr[i] = max(height[i],arr[i-1]);
        }

        return arr;
    }

    vector<int> getSuffixMax(vector<int>& height){
        vector<int> arr(height.size());
        arr[height.size() - 1] = height[height.size()-1];
        for(int i=height.size()-2 ; i >= 0; i--){
            arr[i] = max(height[i] , arr[i+1] );
        }

        return arr;
    }
};
