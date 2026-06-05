class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Last time I solved this, I used a hash map to keep track of what
        // values we'd encountered. Whenever we encounter a value,
        // it's marked as 'found' in the map. At the end, I traverse this
        // map and add any values that weren't found.
        vector<int> retVec;
        unordered_map<int, bool> numMap;
        for (auto num : nums) {
            if (!numMap.contains(num)) {
                numMap[num] = true;
            }
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (!numMap.contains(i)) {
                retVec.push_back(i);
            }
        }

        return retVec;
    }
};