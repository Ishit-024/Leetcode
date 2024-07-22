class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            // Updating minPrice to the lowest price seen so far
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            // Calculate the current profit and update maxProfit if it's higher than the previous maxProfit
            int currentProfit = prices[i] - minPrice;
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
        }
        return maxProfit;
    }
};
