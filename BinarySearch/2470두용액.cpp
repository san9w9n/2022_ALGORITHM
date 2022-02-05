#include <bits/stdc++.h>
using namespace std;

long long liquid[100010];

void solve() {
  int N;
  cin >> N;
  for (int i=0; i<N; i++) cin >> liquid[i];
  sort(liquid, liquid+N);

  int left = 0, right = N-1;
  long long l_ans = liquid[left], r_ans = liquid[right];
  long long ans = r_ans + l_ans;

  while (left < right) {
    long long val = liquid[left] + liquid[right];
    if (abs(ans) > abs(val)) {
      ans = val;
      l_ans = liquid[left];
      r_ans = liquid[right];
    }
    if (val <= 0) left++;
    else right--;
  }
  cout << l_ans << " " << r_ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();
  return 0;
}