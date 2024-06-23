class Solution{   
public:
    string oddEven(int N){
        if(N & 1 == 1) return "odd";
        else return "even";
    }
};
