class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        vector<int> knowMe(mat.size(),0);
        vector<int> iKnowThem(mat.size(),0);
        
        for(int i=0; i < mat.size(); i++){
            for(int j=0; j < mat[0].size(); j++){
                if(mat[i][j] == 1){
                    knowMe[j]++;
                    iKnowThem[i]++;
                }
            }
        }
        
        for(int i =0; i < mat.size(); i++){
            if(knowMe[i] == mat.size()-1 && iKnowThem[i] == 0 ){
                return i;
            }
        }
        
        return -1;
        
    }
};
