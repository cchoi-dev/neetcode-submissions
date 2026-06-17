class Solution {
public:
    int climbStairs(int n) {
        // The number of ways we can reach a step n is the addition
        // of the number of ways we can reach step n-1 + n-2,
        // as the only way we can reach that step is by 1 or 2 steps.
        // We can use this insight to develop our algorithm (is this a DP problem?).

        if (n <= 2) {
            return n;
        }
        vector<int> stepsToIdx(n+1);
        stepsToIdx[0] = 0;
        stepsToIdx[1] = 1;
        stepsToIdx[2] = 2;
        for (int i = 3; i <= n; i++) {
            stepsToIdx[i] = stepsToIdx[i-1] + stepsToIdx[i-2];
        }

        return stepsToIdx[n];
    }
};
