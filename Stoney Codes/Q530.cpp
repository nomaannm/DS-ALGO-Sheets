/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    void getInorderTraversal(TreeNode* root){
        if(root == nullptr) return;
        getInorderTraversal(root->left);
        v.push_back(root->val);
        getInorderTraversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr) return INT_MAX;
        
        getInorderTraversal(root);
        int minDiff = INT_MAX;
        for(int i=0; i < v.size()-1; i++){
            minDiff = min(minDiff, abs(v[i] - v[i+1]));
        }

        return minDiff;

    }
};
