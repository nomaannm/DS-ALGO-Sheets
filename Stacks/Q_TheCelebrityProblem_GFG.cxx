class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int top = 0;
        int bottom = mat.size()-1;
        while(top < bottom){
            if(mat[top][bottom] == 1){
                top++;
            }
            else if(mat[bottom][top] == 1){
                bottom--;
            }
            else{
                top++;
                bottom--;
            }
        }
        if(top > bottom) return -1;
        
        for(int i=0; i < mat.size(); i++){
            if(i == top) continue;
            if(mat[top][i] == 0 && mat[i][top] == 1) return top;
            else return -1;
        }
        
        return top;
        
        
    }
};
