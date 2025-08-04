/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than 
⌊n / 2⌋ times. You may assume that the majority element 
always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int begin = 0;
        int end = 0;
        std::pair<int, int> morerep(0, 0);
        int rep = 0;
        while(end < nums.size()){
            if(nums[begin] == nums[end]){
                rep += 1;
                if(rep > morerep.second){
                    morerep.second = rep;
                    morerep.first = nums[end];
                }
                end++;
            }else{
                rep = 0;
                begin = end;
            }
        }
        return morerep.first;
    }
};