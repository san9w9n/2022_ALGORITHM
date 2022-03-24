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

    void push_front(int x) {
        cnt++;
        bucket[front] = x;
        front = (front-1) < 0 ? MAX_N : front - 1;
    }

    void push_back(int x) {
        cnt++;
        bucket[rear] = x;
        rear = (rear+1) % (MAX_N+1);
    }
    
    int size() {
        return cnt;
    }

    int pop_front() {
        if (empty()) return -1;
        cnt--;
        front = (front+1)%(MAX_N+1);
        return bucket[front];
    }

    int pop_back() {
        if (empty()) return -1;
        cnt--;
        rear = (rear-1 < 0) ? MAX_N : rear-1;
        return bucket[rear];
    }

    int deqFront() {
        return empty() ? -1 : bucket[(front+1)%(MAX_N+1)];
    }

    int deqBack() {
        if (empty()) return -1;
        int idx = (rear-1 < 0) ? MAX_N : rear-1;
        return bucket[idx];
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
        if (cmd == "push_front") {
            cin >> num;
            Q.push_front(num);
        } else if (cmd == "push_back") {
            cin >> num;
            Q.push_back(num);
        } else if (cmd == "front") {
            cout << Q.deqFront() << "\n";
        } else if (cmd=="back") {
            cout << Q.deqBack() << "\n";
        } else if (cmd == "size") {
            cout << Q.size() << "\n";
        } else if (cmd=="pop_front") {
            cout << Q.pop_front() << "\n";
        } else if (cmd=="pop_back") {
            cout << Q.pop_back() << "\n";
        } else if (cmd=="empty") {
            cout << Q.empty() << "\n";
        } else if (cmd=="back") {
            cout << Q.deqBack() << "\n";
        }
    }

    return 0;
}