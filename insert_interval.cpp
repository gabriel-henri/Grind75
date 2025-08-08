/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int searchByBegin(vector<vector<int>>& intervals, int val){
        int b = 0;
        while(b < intervals.size()){
            if(intervals[b][1] >= val){
                return b;
            }
            b++;
        }
        return b;
    }

    int searchByEnd(vector<vector<int>>& intervals, int val){
        int e = intervals.size()-1;
        while(e < intervals.size()){
            if(intervals[e][0] <= val){
                return e;
            }
            e--;
        }
        return e;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> result;

        if(intervals.size() == 0){
            result.push_back(newInterval);
            return result;
        }

        int begin = searchByBegin(intervals, newInterval[0]);
        int end = searchByEnd(intervals, newInterval[1]);

        vector<int> mescla = {0, 0};

        if(begin >= intervals.size()){
            mescla[0] = newInterval[0];
            mescla[1] = newInterval[1];
        }else if(end < 0){
            mescla[0] = std::min(intervals[begin][0], newInterval[0]);
            mescla[1] = newInterval[1];
        }else{
            mescla = {std::min(intervals[begin][0], newInterval[0]),
            std::max(intervals[end][1], newInterval[1])};
        }


        for(int i = 0; i < begin; i++){
            result.push_back(intervals[i]);
        }
        
        result.push_back(mescla);
        
        for(int i = (end+1); i < intervals.size(); i++){
            result.push_back(intervals[i]);
        }
        return result;
    }
};