#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int A[1005], B[1005];
unordered_map<int, int> AM;
unordered_map<int, int> BM;

void solve() {
  cin >> T >> N;
  for (int i=0; i<N; i++) 
    cin >> A[i];
  cin >> M;
  for (int i=0; i<M; i++) 
    cin >> B[i];

  vector<int> A_sum;
  for (int i=0; i<N; i++) {
    int sum = A[i];
    
    if (AM.find(sum) == AM.end()) {
      AM[sum] = 1;
      A_sum.push_back(sum);
    } else {
      AM[sum] = AM[sum] + 1;
    }
    for (int j=i+1; j<N; j++) {
      sum += A[j];
      if (AM.find(sum) == AM.end()) {
        AM[sum] = 1;
        A_sum.push_back(sum);
      } else {
        AM[sum] = AM[sum] + 1;
      }
    }
  }
  for (int i=0; i<M; i++) {
    int sum = B[i];
    if (BM.find(sum) == BM.end()) 
      BM[sum] = 1;
    else 
      BM[sum] = BM[sum] + 1;
    for (int j=i+1; j<M; j++) {
      sum += B[j];
      if (BM.find(sum) == BM.end())
        BM[sum] = 1;
      else 
        BM[sum] = BM[sum] + 1;
    }
  }
  
  int Asize = A_sum.size();
  long long ans = 0;
  for (int i=0; i<Asize; i++) {
    int val = T - A_sum[i];
    long long Acnt = AM[A_sum[i]];
    auto it = BM.find(val);
    if (it != BM.end()) {
      long long Bcnt = (*it).second;
      ans += Acnt * Bcnt;
    }
  }
  cout << ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();
  return 0;
}