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

        // An alternative way I think we could do this is to sort the vector
        // and add all values between the prev value and the curr value and
        // add them to the return vector.
        // sort(nums.begin(), nums.end());
        // int prevVal = 0;
        // vector<int> retVec;
        // for (int i = 0; i < nums.size(); i++) {
        //     // If i > curr val, 
        // }
        // int i = 0;
        // for (auto num : nums) {
        //     // If i > num, that means we have 
        //     for (int i = prevVal+1; i < num; i++) {
        //         retVec.push_back(i);
        //     }
        //     prevVal = num;
        // }
        return retVec;
    }
};