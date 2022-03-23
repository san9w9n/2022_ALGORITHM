#include <bits/stdc++.h>
using namespace std;

queue<int> Q;
int N, K;

void rotate() {
    int cnt = K-1;
    while (cnt--) {
        Q.push(Q.front());
        Q.pop();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for (int i=1; i<=N; i++)
        Q.push(i);

    vector<int> ans;
    while (!Q.empty()) {
        rotate();
        ans.push_back(Q.front());
        Q.pop();
    }

    cout << "<";
    for (int i=0; i<N-1; i++) {
        cout << ans[i] << ", ";
    }
    cout << ans[N-1] << ">";

    return 0;
}