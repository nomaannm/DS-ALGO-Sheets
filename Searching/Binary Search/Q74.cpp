class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto x : matrix){
            if(bs(x,target)) return true;
        }
        return false;
    }

    int bs(vector<int>& row, int target){
        int lo = 0;
        int hi = row.size() - 1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(row[mid] == target) return 1;
            else if(row[mid] < target) lo = mid+1;
            else hi = mid-1;
        }
        return 0;
    }
};
