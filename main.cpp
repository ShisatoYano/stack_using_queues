#include <bits/stdc++.h>
using namespace std;

class Stack {
    // inbuilt queues
    queue<int> q1, q2;

    int current_size;

public:
    Stack() {
        current_size = 0;
    }

    int size() {
        return current_size;
    }

    void push(int x) {
        current_size++;

        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> q_tmp = q1;
        q1 = q2;
        q2 = q_tmp;
    }

    int top() {
        if (q1.empty()) {
            return -1;
        }
        return q1.front();
    }

    void pop() {
        if (q1.empty()) {
            return;
        }
        q1.pop();
        current_size--;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Current current_size: " << s.size() << endl;

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << "Current current_size: " << s.size() << endl;

    return 0;
}
