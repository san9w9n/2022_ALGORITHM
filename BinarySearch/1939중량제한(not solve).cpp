#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> V;
bool visited[10010];
int A, B, ans;

void btk(int land, int cost) {
  int size;
  if (visited[land]) return;
  if (land == B) {
    ans = max(cost, ans);
    return;
  }
  visited[land] = true;
  vector<pair<int, int>>& tmp = V[land];
  size = tmp.size();

  for (int i=0; i<size; i++) {
    int next = tmp[i].first;
    int next_cost = tmp[i].second;
    if (next_cost > cost) continue;
    btk(next, next_cost);
    visited[land] = false;
  }
}

void solve() {
  int N, M, cost, land;

  ans = 0;
  cin >> N >> M;
  V.resize(N+3);

  for (int i=0; i<M; i++) {
    cin >> A >> B >> cost;
    V[A].push_back({B, cost});
    V[B].push_back({A, cost});
  }
  cin >> A >> B;
  btk(A, INT32_MAX);
  cout << ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();
  return 0;
}
