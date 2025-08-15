/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

#include <vector>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        int i = 0;
        int j, k;
        while(i < nums.size()-2){
            if(i > 0 && nums[i] == nums[i-1]){
                i++;
                continue;
            }
            j = i+1;
            k = nums.size()-1;
            while(j < k){
                if(nums[i]+nums[j] + nums[k] == 0){
                    std::vector triplet = {nums[i], nums[j], nums[k]};
                    result.push_back(triplet);
                    while(j < k && nums[k] == nums[k-1] && nums[j] == nums[j+1]){
                        j++;
                        k--;
                    }
                    j++;
                    k--;
                }else if(nums[i]+nums[j]+nums[k] > 0){
                    k--;
                }else{
                    j++;
                }
            }
            i++;
        }
        return result;
    }
};