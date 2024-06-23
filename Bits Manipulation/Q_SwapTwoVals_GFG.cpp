class Solution{   
public:
    pair<int, int> get(int a, int b){
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        return {a,b};
    }
};
