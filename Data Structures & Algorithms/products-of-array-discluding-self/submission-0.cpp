class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // My initial thought for this is to get the product of all elements first
        // then, for each index, I can divide this full product value by the value
        // at said index

        // Edge cases:
        // 1. There's 1 zero in the entire vector
        //    In this case, our fullProd gets invalidated and we either need
        //    to re-calculate the prod WITHOUT the 0 OR have pre-calculated it
        // 2. There's 2 or more zeroes in the vector
        //    In this case, everything is 0.
        int fullProd = 1;
        int zeroCount = 0;
        for (auto num : nums) {
            if (num == 0) {
                zeroCount++;
                // In this case, we DON'T multiple the fullProd
                continue;
            }
            fullProd *= num;
        }

        vector<int> retVec;
        for (auto num : nums) {
            if (zeroCount > 1) {
                retVec.push_back(0);
                continue;
            }
            if (zeroCount == 1) {
                if (num == 0) {
                    retVec.push_back(fullProd); 
                }
                else {
                    retVec.push_back(0);
                }
                continue;
            }
            retVec.push_back(fullProd / num);
        }

        return retVec;
    }
};
