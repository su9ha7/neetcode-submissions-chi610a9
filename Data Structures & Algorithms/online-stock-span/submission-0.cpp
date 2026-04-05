class StockSpanner {
private:
    // We store pairs: {price, span}
    stack<pair<int, int>> st;

public:
    StockSpanner() {}
    
    int next(int price) {
        int currentSpan = 1;
        
        // While the previous price is smaller or equal
        while (!st.empty() && st.top().first <= price) {
            // Add the previous day's span to our current span
            currentSpan += st.top().second;
            // We've "absorbed" this day, so pop it
            st.pop();
        }
        
        // Push today's price and its calculated span
        st.push({price, currentSpan});
        
        return currentSpan;
    }
};