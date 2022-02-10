#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int N, M;
int MAP[500][500];
int been[500][500];
int ans;

struct comp {
  bool operator()(pair<int, int>& a, pair<int, int>& b) {
    int acost = MAP[a.first][a.second];
    int bcost = MAP[b.first][b.second];
    if (acost != bcost) 
      return acost < bcost;
    if (a.first != b.first)
      return a.first > b.first;
    return a.second > b.second;
  }
};

void solve() {
  int x, y, r, c, nextX, nextY;
  priority_queue<pair<int, int>, vector<pair<int, int>>, comp> PQ;

  cin >> N >> M;
  for (int i=0; i<N; i++) for (int j=0; j<M; j++)
    cin >> MAP[i][j];

  PQ.push({0, 0});
  been[0][0] = 1;
  while (!PQ.empty()) {
    auto cur = PQ.top(); PQ.pop();
    x = cur.first; y = cur.second;
    while (!PQ.empty()) {
      auto next = PQ.top();
      nextX = next.first; nextY = next.second;
      if (nextX == x && nextY == y) 
        PQ.pop();
      else break;
    }
    if (x==N-1 && y==M-1) 
      continue;
    for (int d=0; d<4; d++) {
      r=x+dx[d]; c=y+dy[d];
      if (r<0 || c<0 || r>=N || c>=M) continue;
      if (MAP[x][y] <= MAP[r][c]) continue;
      been[r][c] += been[x][y];
      PQ.push({r, c});
    }
  }
  cout << been[N-1][M-1];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();
  return 0;
}