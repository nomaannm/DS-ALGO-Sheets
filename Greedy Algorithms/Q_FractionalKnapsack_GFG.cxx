class CustomComparator {
    public:
        CustomComparator() = default;
        
        bool operator()(pair<int,int> a, pair<int,int> b) const {
           return (static_cast<double>(a.first)/a.second) > (static_cast<double>(b.first)/b.second);
        }
};

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<int,int>> temp;
        for(auto i = 0; i < val.size(); i++){
            temp.push_back({val[i], wt[i]});
        }
        
        sort(temp.begin(), temp.end(), CustomComparator());
        
        double max = 0;
        
        for(const auto& item : temp){
            if(capacity == 0) break;
            
            if(item.second <= capacity){
                max += item.first;
                capacity -= item.second;
            } else {
                double calculated = (static_cast<double>(item.first)/item.second) * capacity;
                max += calculated;
                capacity = 0;
            }
            
            
        }
        
        return max;
    }
};
