class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> numMap;
        for (auto num : nums) {
            if (!numMap[num]) {
                numMap[num] = true;
            }
            else {
                return true;
            }
        }
        return false;
    }
};