#include <ranges>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complementToIdx;
        vector<int> retVec = {0,0};
        for (auto [idx, num] : views::enumerate(nums)) {
            if (complementToIdx.contains(num)) {
                retVec[0] = complementToIdx[num];
                retVec[1] = idx;
            }
            else {
                complementToIdx[target - num] = idx;
            }
        }
        return retVec;
    }
};
