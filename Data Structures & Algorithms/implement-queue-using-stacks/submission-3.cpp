class MyQueue {
private:
    stack<int> s1; // For pushing (Input)
    stack<int> s2; // For popping/peeking (Output)

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        int res = peek(); // Ensure s2 is populated
        s2.pop();
        return res;
    }

    int peek() {
        // If s2 is empty, transfer everything from s1
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};