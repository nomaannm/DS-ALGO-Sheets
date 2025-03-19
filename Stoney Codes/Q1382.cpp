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
    void getInorderTraversal(TreeNode* root, vector<int>& v){
        if(root == nullptr) return;
        getInorderTraversal(root->left, v);
        v.push_back(root->val);
        getInorderTraversal(root->right, v);
    }
    TreeNode* solve(int l, int r, vector<int>& arr){
        if(l > r) return nullptr;

        int mid = l + (r-l)/2;

        TreeNode* root = new TreeNode(arr[mid]);
        root->left = solve(l, mid-1, arr);
        root->right = solve(mid+1, r, arr);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        getInorderTraversal(root, arr);
        int r = arr.size()-1;
        return solve(0, r, arr);

        
    }
};
