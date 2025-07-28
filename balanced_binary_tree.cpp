/*
Given a binary tree, determine if it is height-balanced.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true
*/

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

#include <algorithm>
#include <cmath>

 struct HeightB{
    bool balanced;
    int height;
 };

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        HeightB result = dfs(root);
        return result.balanced;
    }

    HeightB dfs(TreeNode* root){
        if(root == nullptr){
            HeightB h = {true, 0};
            return h;
        }

        HeightB r = dfs(root->right);
        HeightB l = dfs(root->left);

        int dif = std::abs(r.height - l.height);
        HeightB result;
        result.balanced = r.balanced && l.balanced && dif <= 1;
        result.height = (std::max(r.height, l.height)) + 1;
        
        return result;
    }
};