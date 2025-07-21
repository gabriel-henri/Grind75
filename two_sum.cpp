/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/


#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unsigned int begin = 0;
        unsigned int end = nums.size()-1;
        std::vector<int> index = {0, 0};
        std::vector<int> ordered = nums;
        std::sort(ordered.begin(), ordered.end());
        int first, second;

        while(begin < end){
            if(ordered.at(begin) + ordered.at(end) == target){
                first = ordered.at(begin);
                second = ordered.at(end);
                break;
            }
            else if(ordered.at(begin) + ordered.at(end) > target){
                end--;
            }
            else{
                begin++;
            }
        }
        int ind = 0;
        for(int i = 0; i < nums.size(); i++){
            if(first == nums[i] || second == nums[i]){
                index[ind] = i;
                ind++;
            }
        }
        return index;
    }
};