#include<iostream>
#include<vector>
using namespace std;


int helper(vector<int>& values, vector<int>& weights, int i, int knapsackWeight, vector<vector<int>>& memo) {
    if (i == 0 || knapsackWeight == 0) return 0;

    if (memo[i][knapsackWeight] != -1) {
        return memo[i][knapsackWeight];
    }

    if (weights[i-1] <= knapsackWeight) {
        //Take it
        int take = values[i-1] + helper(values, weights, i-1, knapsackWeight-weights[i-1], memo);
        //Skip it
        int skip = helper(values, weights, i-1, knapsackWeight, memo);

        memo[i][knapsackWeight] = max(take, skip);
    }

    return memo[i][knapsackWeight];
}


int memoizationBasedApproachForKnapsackProblem(vector<int>& values, vector<int>& weights, int knapsackCapacity) {
    int n = values.size();
    vector<vector<int>> memo(n+1, vector<int>(knapsackCapacity + 1, -1));
    return helper(values, weights, n, knapsackCapacity, memo);
}

int main() {

    vector<int> weights = {1, 3, 4, 5};
    vector<int> values  = {1, 4, 5, 7};
    int capacity = 7;

    cout << memoizationBasedApproachForKnapsackProblem(values, weights, capacity) << endl;

}


