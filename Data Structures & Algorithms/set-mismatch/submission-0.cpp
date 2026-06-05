class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // The way I had solved this previously was having a hash map
        // I prepared with numbers from 1 to n (n being nums.size())
        // mapping to 'false'.
        // From here, I would traverse nums and set the values to 'true' if
        // found in the array. If a duplicate was found, I would add this value
        // as the first value in the return vector.
        // Finally, I would go through the map one more time and check for
        // the value still marked 'false'.
        // This is O(n) still... but the result was not as fast as I wanted.
        // How can I make this faster?
        // simply summing up the numbers doesn't work, as there's multiple combinations of
        // mismatches that may result in the same sum result.
        // That said... if I sum the numbers up as I go, once I find the duplicate,
        // all I would need to do is subtract the duplicate from the sum and find the value
        // that way! I'm going to try that.
        int currSum = 0;
        int duplicateNum = 0;
        int expectedSum = 0;
        int i = 1;
        unordered_map<int, bool> numMap;
        for (auto num : nums) {
            currSum += num;
            expectedSum += i++;
            if (numMap.contains(num)) {
                duplicateNum = num;
            }
            else {
                numMap[num] = true;
            }
        }

        // Duplicate num guaranteed to be found on first traversal
        // Find the diff from numMap and return the 2nd number.
        int missingNum = abs(expectedSum - (currSum - duplicateNum));

        vector<int> retVec = {duplicateNum, missingNum};

        return retVec;
    }
};