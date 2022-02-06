#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll liquid[100010];

void solve() {
  int N;
  ll left, right, ans = LLONG_MAX, fix;
  ll l_ans, mid_ans, r_ans;

  cin >> N;
  for (int i=0; i<N; i++) cin >> liquid[i];
  sort(liquid, liquid+N);

  for (int i=0; i<N-2; i++) {
    fix = liquid[i];
    left = i+1; 
    right = N-1;
    while (left < right) {
      ll val = liquid[left] + fix + liquid[right];
      if (abs(ans) > abs(val)) {
        ans = val;
        l_ans = fix;
        r_ans = liquid[right];
        mid_ans = liquid[left];
      }
      if (val<0) left++;
      else if (val>0) right--;
      else {
        i=N;
        break;
      }
    }
  }
  cout << l_ans << " " << mid_ans << " " << r_ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();
  return 0;
}