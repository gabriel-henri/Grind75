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

 /*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000 
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        vector<vector<int>> result;
        vector<vector<TreeNode*>> temp;
        temp.push_back({root});

        while(!temp.empty()){
            vector<TreeNode*> nivel = temp.back();
            temp.pop_back();

            vector<TreeNode*> new_nivel;
            vector<int> vals;

            for(TreeNode* no:nivel){
                vals.push_back(no->val);
                if(no->left != nullptr){
                    new_nivel.push_back(no->left);
                }
                if(no->right != nullptr){
                    new_nivel.push_back(no->right);
                }
            }
            result.push_back(vals);
            if(!new_nivel.empty())
                temp.push_back(new_nivel);
        }
        return result;
    }
};