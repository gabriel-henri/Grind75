/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

*/

#include <vector>
#include <queue>

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<bool>> discovered(mat.size(), vector<bool>(mat[0].size(), false));
        queue<pair<int, int>> q;
        vector<int> lin = {-1, 0, 1, 0};
        vector<int> col = {0, 1, 0, -1};

        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    discovered[i][j] = true;
                }
            }
        }
        while(!q.empty()){
            pair<int, int> pos = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int novaLinha = pos.first + lin[i];
                int novaColuna = pos.second + col[i];
                if (novaLinha >= 0 && novaLinha < (int)mat.size() &&
                novaColuna >= 0 && novaColuna < (int)mat[0].size()){
                    if(discovered[pos.first+lin[i]][pos.second+col[i]] == false){
                        q.push({pos.first+lin[i], pos.second+col[i]});
                        discovered[pos.first+lin[i]][pos.second+col[i]] = true;
                        mat[pos.first+lin[i]][pos.second+col[i]] = mat[pos.first][pos.second]+1;
                    }
                }
            }  
        }
        return mat;
    }
};