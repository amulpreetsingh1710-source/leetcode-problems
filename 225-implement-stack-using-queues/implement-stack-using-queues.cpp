class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty()){        // copy q1 to q2
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);              // push element in q1

        while(!q2.empty()){      // copy q2 to q1
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */