class MinStack {
private:
    stack<int> st;      // Stores all values
    stack<int> min_st;  // Stores minimums

public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        
        // If min_st is empty, the first value is the min.
        // Otherwise, the new min is the smaller of 'val' or the current top of min_st.
        if (min_st.empty()) {
            min_st.push(val);
        } else {
            min_st.push(min(val, min_st.top()));
        }
    }

    void pop() {
        st.pop();
        min_st.pop(); // Pop both to keep them in sync
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }
};
