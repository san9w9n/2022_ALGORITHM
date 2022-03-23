#include <bits/stdc++.h>
using namespace std;
#define MAX_N 2000000

class Queue {
private:
    int bucket[MAX_N+1];
    int front, rear;
    int cnt;
public:
    Queue() {
        cnt = 0;
        front = 0;
        rear = 1;
    }

    bool empty() {
        return !cnt;
    }

    void push(int x) {
        cnt++;
        bucket[rear] = x;
        rear = (rear+1)%(MAX_N+1);
    }
    
    int size() {
        return cnt;
    }

    int pop() {
        if (empty()) return -1;
        cnt--;
        front = (front+1)%(MAX_N+1);
        return bucket[front];
    }

    int ffront() {
        return empty() ? -1 : bucket[(front+1)%(MAX_N+1)];
    }

    int back() {
        int idx = rear-1;
        if (idx<0) idx = MAX_N;
        return empty() ? -1 : bucket[idx];
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Queue Q; int N, num;
    string cmd;

    cin >> N;
    while (N--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> num;
            Q.push(num);
        } else if (cmd == "front") {
            cout << Q.ffront() << "\n";
        } else if (cmd == "size") {
            cout << Q.size() << "\n";
        } else if (cmd=="pop") {
            cout << Q.pop() << "\n";
        } else if (cmd=="empty") {
            cout << Q.empty() << "\n";
        } else if (cmd=="back") {
            cout << Q.back() << "\n";
        }
    }

    return 0;
}