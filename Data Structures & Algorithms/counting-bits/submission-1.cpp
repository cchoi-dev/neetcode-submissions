class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> retVec;
        for (int i = 0; i <= n; i++) {
            retVec.push_back(countBitsForInt(i));
        }

        return retVec;
    }

    int countBitsForInt(int n) {
        int sum = 0;
        for (int i = 0; i < 32; i++) {
            sum += (n & 0x01);
            n = n >> 1;
        }
        return sum;
    }
};
