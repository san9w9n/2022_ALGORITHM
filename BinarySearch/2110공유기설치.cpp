#include <bits/stdc++.h>
using namespace std;

int house[200200];
int N, C;
long ans = -1;

void solve() {
  long left, right;

  cin >> N >> C;

  for (int i=0; i<N; i++) 
    cin >> house[i];
  sort(house, house+N);
  left = house[0];
  right = house[N-1];

  for (int i=0; i<N; i++) {
    house[i] -= left;
  }
  left = house[0];
  right = house[N-1];
  
  if (C==2) {
    cout << right - left;
    return;
  }

  while (left <= right) {
    long mid = (right + left) / 2;
    int prev = 0, cnt = 1;
    for (int cur=1; cur<N; cur++) {
      int length = house[cur] - house[prev];
      if (length >= mid) {
        prev = cur;
        cnt++;
      }
    }
    if (cnt >= C) left = mid+1;
    else right = mid-1;
    
    if (ans < mid && cnt >= C) ans = mid;
  }
  cout << ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();
  return 0;
}