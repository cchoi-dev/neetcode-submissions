class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // The brute force solution would be:
        // 1. Get the size of nums to see what range we're checking
        // 2. For each number in that range, we check the nums vector
        //    and see if that value exists within the vector
        // This would result in an O(n^2) time complexity algorithm.

        // The better way to do this would be to make use of the XOR operation
        // When XOR'ing a number with itself, the value cancels itself out back to
        // 0. Knowing this, what we can do is:
        // 1. Get the range.
        // 2. XOR all values in that range.
        // 3. XOR the value with the values in nums.
        // 4. Whatever value remains is the missing number - return.
        int retVal = 0;
        for (int i = 0; i <= nums.size(); i++) {
            retVal = retVal ^ i;
        }

        for (auto num : nums) {
            retVal = retVal ^ num;
        }

        return retVal;
    }
};
