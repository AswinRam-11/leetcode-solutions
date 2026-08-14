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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack <TreeNode*> st;
        st.push(root);
        vector<int> ans;
        while(st.top()->left){
            st.push(st.top()->left);
        }
        while(!st.empty()){
            TreeNode* top= st.top();
            st.pop();
            ans.push_back(top->val);
            if(top->right){
                st.push(top->right);
                while(st.top()->left){
                    st.push(st.top()->left);
                }
            }
            
        }
        return ans;
    }
};