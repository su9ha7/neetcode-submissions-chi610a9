class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

    // Step 2: Initialize variables
    // Start min_price as the first day's price
    int min_price = prices[0]; 
    int max_profit = 0;

    // Step 3: Loop through the prices starting from the second day
    for (int i = 1; i < prices.size(); i++) {
        // Can we make a better profit by selling today?
        int current_profit = prices[i] - min_price;
        
        // Update max_profit if current_profit is higher
        if (current_profit > max_profit) {
            max_profit = current_profit;
        }

        // Update min_price if we found a cheaper day to buy
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
    }

    return max_profit;
        
    }
};
