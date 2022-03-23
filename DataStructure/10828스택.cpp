#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000


class Stack {
private:
    int bucket[MAXN+1];
    int front;
    int cnt;
public:
    Stack() {
        cnt = 0;
        front = MAXN;
    }

    bool empty() {
        return !cnt;
    }

    int top() {
        int idx = (front+1) % (MAXN+1);
        return empty() ? -1 : bucket[idx];
    }

    int size() {
        return cnt;
    }

    void push(int x) {
        cnt++;
        bucket[front] = x;
        front = (!front) ? MAXN : front-1;
    }

    int pop() {
        if (empty()) return -1;
        cnt--;
        front = (front+1) % (MAXN+1);
        return bucket[front];
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Stack S; int N, num;
    string cmd;

    cin >> N;
    while (N--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> num;
            S.push(num);
        } else if (cmd == "top") {
            cout << S.top() << "\n";
        } else if (cmd == "size") {
            cout << S.size() << "\n";
        } else if (cmd=="pop") {
            cout << S.pop() << "\n";
        } else if (cmd=="empty") {
            cout << S.empty() << "\n";
        }
    }
    

    return 0;
}