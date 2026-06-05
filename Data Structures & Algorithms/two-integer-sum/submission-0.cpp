class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // As we traverse array, we can keep track of the numbers
        // we need to 'see' for a target match sum.
        // i.e. If we have a target of 7 and we see a 3, we keep track
        // of the fact that we need to see a value of 4 in the vector.
        // Ultimately what we're interested in are the indices, so what
        // we can do is save each 'complement' in a map as a key that points
        // to the index of the value it complements for the target value.
        unordered_map<int, int> complementToIndex;
        vector<int> retVec = {0, 0};
        for (int i = 0; i < nums.size(); i++) {
            // Store a reference to the 1st number's index so that
            // when we encounter the 2nd number that adds up to the target,
            // we know the indices of both
            if (!complementToIndex.contains(nums[i])) {
                complementToIndex[(target - nums[i])] = i;
            }
            // If we reach a 2nd number, return what we want;
            else {
                retVec[0] = complementToIndex[nums[i]];
                retVec[1] = i;
                break;
            }
        }
        return retVec;
    }
};
