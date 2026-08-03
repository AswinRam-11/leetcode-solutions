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
    void traversal(TreeNode* root, map<int,map<int,multiset<int>>>& store, int vert, int level){
        if(root){
            store[vert][level].insert(root->val);
            traversal(root->left, store, vert-1, level+1);
            traversal(root->right, store, vert+1, level+1);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> store;
        traversal(root,store,0,0);
        vector<vector<int>> ans;
        int i=0;
        for(auto it: store){
            ans.push_back({});
            for(auto gt: it.second){
                for(auto bt: gt.second){
                    ans[i].push_back(bt);
                }
            }
            i++;
        }
        return ans;
    }
};