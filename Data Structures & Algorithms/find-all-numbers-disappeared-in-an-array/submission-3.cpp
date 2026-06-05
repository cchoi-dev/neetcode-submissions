class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Last time I solved this, I used a hash map to keep track of what
        // values we'd encountered. Whenever we encounter a value,
        // it's marked as 'found' in the map. At the end, I traverse this
        // map and add any values that weren't found.
        // vector<int> retVec;
        // unordered_map<int, bool> numMap;
        // for (auto num : nums) {
        //     if (!numMap.contains(num)) {
        //         numMap[num] = true;
        //     }
        // }

        // for (int i = 1; i <= nums.size(); i++) {
        //     if (!numMap.contains(i)) {
        //         retVec.push_back(i);
        //     }
        // }
        // return retVec;

        // Key insight: we don't really care how many times something
        // has shown up. We just care whether a value is present or not.
        // Values 1 - n, in a sorted array, would be in indices 0 - n-1.
        // As such, what we could do is 'mark' the array at its corresponding
        // spot on the input array, then traverse it at the end to determine
        // which values have not shown up yet by seeing if that index was unmarked.
        // In this case, our mark will be a negative value.
        vector<int> retVec;
        for (int i = 0; i < nums.size(); i++) {
            int currVal = abs(nums[i]);
            // Value already marked - continue
            if (nums[currVal-1] < 0) {
                continue;
            }
            nums[currVal-1] *= -1;
        }

        for (int i = 0; i< nums.size(); i++) {
            if (nums[i] > 0) {
                retVec.push_back(i+1);
            }
        }
        return retVec;
    }
};