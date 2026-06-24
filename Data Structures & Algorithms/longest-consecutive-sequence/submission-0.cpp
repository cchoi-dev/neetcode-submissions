class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // We need to find a way to determine the 'starting points' of
        // where we start counting the potential sequences
        // That is to say, if we have 2,3,4,5 and 12,13,14,15,16,
        // we need to determine that we're counting from 2 and also from 12
        
        // Perhaps I can add a hash map that keeps track of all elements we've
        // found already, which we continue to iterate through (from our starting points)
        vector<int> startingPoints;
        unordered_map<int, bool> foundNums;

        for (auto num : nums) {
            if (foundNums.contains(num)) {
                continue;
            }
            else if (!foundNums.contains(num - 1)) {
                // No chain - this is a starting number
                startingPoints.push_back(num);
            }
            foundNums[num] = true; 
        }

        int currLongestChain = 0;
        // Now traverse through the hash map
        for (auto startingPoint : startingPoints) {
            int currNum = startingPoint;
            int chainLength = 0;
            while (foundNums.contains(currNum)) {
                chainLength++;
                currNum++;
            }
            if (chainLength > currLongestChain) {
                currLongestChain = chainLength;
            }
        }

        return currLongestChain;
    }
};
