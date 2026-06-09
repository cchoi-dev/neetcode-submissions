class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // The highest profit is found by finding the largest difference
        // between a given price point and a subsequent larger price point
        // Since we're only interested in finding the maximum profit amount
        // and don't really care much about when those time points are,
        // all we need to do is keep track of the highest profit found so far
        // as we iterate through the vector.
        // As we traverse, we keep updating what the lowest price so far
        // is, as any new 'high' prices should be compared against this
        // new lowest price.
        int currLowest = INT32_MAX;
        int currMaxProfit = 0;
        for (auto price : prices) {
            if (price - currLowest > currMaxProfit) {
                currMaxProfit = price - currLowest;
            }
            if (price < currLowest) {
                currLowest = price;
            }
        }
        return currMaxProfit;
    }
};
