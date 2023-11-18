class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int variable = 0 ;
        for(auto x : operations){
            if(x == "++X" || x == "X++") variable++;
            else variable-- ;
        }

        return variable ;
        
    }
};
