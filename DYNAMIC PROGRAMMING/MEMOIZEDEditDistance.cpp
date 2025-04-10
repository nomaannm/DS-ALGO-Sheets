#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int findMinChanges(const string& s1, const string& s2, int i, int j, map<pair<int,int>, int>& memo) {
    if (memo.find({i, j}) != memo.end()) {
        return memo[{i, j}];
    }
    if (i == s1.size()) {
        memo[{i,j}] = s2.size()-j;
        return memo[{i, j}];
    };
    if (j == s2.size()) {
        memo[{i, j}] = s1.size()-i;
        return memo[{i, j}];
    }

    if (s1[i] == s2[j]) {
        return findMinChanges(s1, s2, i+1, j+1, memo);
    } else {
        int insertOp = findMinChanges(s1, s2, i, j+1, memo);
        int deleteOp = findMinChanges(s1, s2, i+1, j, memo);
        int replaceOp = findMinChanges(s1, s2, i+1, j+1, memo);

        memo[{i,j}] = 1 + min({insertOp, deleteOp, replaceOp});
        return memo[{i,j}];
    }
}


int main() {
    map<pair<int,int>, int> memo;
    string s1 = "ehddhbwwkehuewhdllqwgdiqbxwygwydvygkuqewgqdywbwgeqqrbxsuiqugeiue";
    string s2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    cout << "Min Edits : " << findMinChanges(s1, s2, 0, 0, memo) << endl;

}
