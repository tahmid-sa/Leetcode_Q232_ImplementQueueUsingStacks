#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        if (stk1.empty()) {
            stk1.push(x);
            return;
        }

        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }

        stk1.push(x);

        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }

    int pop() {
        int top = 0;

        if (!stk1.empty()) {
            top = stk1.top();
            stk1.pop();
        }
        
        return top;
    }

    int peek() {
        return stk1.top();
    }

    bool empty() {
        return stk1.empty();
    }

    stack<int> stk1, stk2;
};

int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    int param_2 = obj->pop();
    obj->push(5);
    int param_3 = obj->pop();
    int param_4 = obj->pop();
    int param_5 = obj->pop();
    int param_6 = obj->pop();

    bool param_7 = obj->empty();

    return 0;
}