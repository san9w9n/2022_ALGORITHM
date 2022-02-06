#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> V;
bool visited[10010];
int A, B;

bool bfs(int limit) {
  queue<pair<int, int>> Q;
  Q.push({A, INT32_MAX});
  visited[A] = true;
  
  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    int curland = cur.first;
    if (curland == B) return true;
    vector<pair<int, int>>& tmp = V[curland];
    int size = tmp.size();
    for (int i=0; i<size; i++) {
      int next = tmp[i].first;
      int nextcost = tmp[i].second;
      if (limit > nextcost || visited[next]) continue;
      visited[next] = true;
      Q.push({next, nextcost});
    }
  }
  return false;
}


void solve() {
  int N, M, cost, land, maxi = 0, mini=INT32_MAX, mid;
  
  cin >> N >> M;
  V.resize(N+3);
  for (int i=0; i<M; i++) {
    cin >> A >> B >> cost;
    V[A].push_back({B, cost});
    V[B].push_back({A, cost});
    maxi = max(maxi, cost);
    mini = min(mini, cost);
  }
  cin >> A >> B;

  int left = mini, right = maxi, ans=0;
  while (left <= right) {
    mid = (left + right) / 2;
    bool result = bfs(mid);
    if (result) {
      ans = mid;
      left = mid+1;
    }
    else 
      right = mid-1;
    memset(visited, 0, sizeof(visited));
  }
  cout << ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();
  return 0;
}
