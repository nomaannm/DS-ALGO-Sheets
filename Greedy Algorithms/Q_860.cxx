class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0; 
        int ten = 0;
        for(const auto& bill : bills){
            if(bill == 5) five++;
            if(bill == 10){
                if(five > 0) {
                    ten++;
                    five--;
                }
                else return false;
            }
            if(bill == 20){
                if(five > 0 && ten > 0){
                    five--;
                    ten--;
                } else if(five >= 3){
                    five -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};
