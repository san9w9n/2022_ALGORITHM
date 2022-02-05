#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, K, ans;
  cin >> N >> K;

  int left = 1, right = K;

  while (left <= right) {
    int mid = (left + right) / 2;
    int cnt = 0;
    for (int i=1; i<=N; i++) 
      cnt += min(mid/i, N);
    if (cnt >= K) ans = mid, right = mid-1;
    else left = mid+1;
  }
  cout << ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();
  return 0;
}