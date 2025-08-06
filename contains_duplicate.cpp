
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> ocurrence;

        for(int num : nums){
            if(ocurrence.find(num) != ocurrence.end()){
                return true;
            }else{
                ocurrence.insert(num);
            }
        }
        return false;
    }
};