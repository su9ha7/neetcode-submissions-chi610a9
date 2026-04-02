class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}
    
    void push(int x) {
        // 1. Put the new element at the back
        q.push(x);
        
        // 2. Rotate the queue so the new element is at the front
        // We do this (size - 1) times
        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        // Because of our push trick, the "top" is already at the front
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};