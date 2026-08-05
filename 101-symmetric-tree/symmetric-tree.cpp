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
    bool check(TreeNode* lNode, TreeNode* rNode){
        if(!lNode && !rNode) return true;
        if(lNode && rNode){
            return (lNode->val==rNode->val)&&check(lNode->left,rNode->right)&&check(lNode->right,rNode->left);
        }
        return false;
        
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};