class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 0;
        int maxProfit = 0;

        while (sell < prices.size()) {
            int profit = prices[sell] - prices[buy];
        
            if (prices[sell] < prices[buy]) buy = sell;

            maxProfit = max(maxProfit, profit);
            sell++;

        }

        return maxProfit;
    }
};
