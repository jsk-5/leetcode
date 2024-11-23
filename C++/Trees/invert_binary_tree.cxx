// https://leetcode.com/problems/invert-binary-tree/
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
    TreeNode* invertTree(TreeNode* root) {
        //BFS 

        if(root == nullptr ) return root;
        deque<TreeNode *> dqe;
        dqe.push_back(root);

        while(!dqe.empty()){
            TreeNode* placeholder = dqe.front()->left;
            dqe.front()->left = dqe.front()->right;
            dqe.front()->right = placeholder;
            if(dqe.front()->left != nullptr){
                dqe.push_back(dqe.front()->left);
            }
            if(dqe.front()->right != nullptr){
                dqe.push_back(dqe.front()->right);
            }
            dqe.pop_front();
        }

        return root;

        
    }
};