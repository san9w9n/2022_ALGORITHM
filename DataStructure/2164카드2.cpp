#include <bits/stdc++.h>
using namespace std;

int N;

void rotate(queue<int>& Q) {
    Q.push(Q.front());
    Q.pop();
}

int solve() {
    queue<int> Q;
    int cnt = N;

    for (int i=1; i<=N; i++) 
        Q.push(i);
    
    while (cnt > 1) {
        Q.pop();
        rotate(Q);
        cnt--;
    }
    
    return Q.front();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    
    cin >> N;
    cout << solve();
    return 0;
}