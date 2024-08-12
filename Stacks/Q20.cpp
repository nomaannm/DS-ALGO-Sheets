class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' ) stck.push(s[i]);
            else{
                if(stck.empty()) return false;
                char ch = stck.top();
                stck.pop();
                if(ch == '(' && s[i] == ')' || ch == '{' && s[i] == '}' || ch == '[' && s[i] == ']'){
                    continue;
                }
                else return false;
            }
        }
        
        return stck.empty();
    }
};
