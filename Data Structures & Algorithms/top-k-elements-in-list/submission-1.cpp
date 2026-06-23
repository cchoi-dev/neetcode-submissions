class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // To determine the k most frequent elements, I need
        // to keep a running tally of the count of each number anyways
        // First thing that comes to mind is a hash map for tracking vals
        unordered_map<int, int> numCounts;
        vector<int> retVec;

        for (auto num : nums) {
            if (!numCounts.contains(num)) {
                numCounts[num] = 1;
                continue;
            }
            numCounts[num] += 1;
        }

        vector<tuple<int, int>> scratchVec;
        for (const auto& [num, count] : numCounts) {
            scratchVec.push_back({num, count});
        }

        sort(scratchVec.begin(), scratchVec.end(), [] (auto& a, auto& b) {
            return get<1>(a) > get<1>(b);
        });

        for (int i = 0; i < k; i++) {
            retVec.push_back(get<0>(scratchVec[i]));
        }

        return retVec;
    }
};
