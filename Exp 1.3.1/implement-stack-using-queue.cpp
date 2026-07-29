#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
    }

    void push(int x) {
        q.push(x);
        int n = q.size();
        while (n > 1) {
            q.push(q.front());
            q.pop();
            n--;
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;

    st.push(1);
    st.push(2);

    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << (st.empty() ? "true" : "false") << endl;

    return 0;
}
