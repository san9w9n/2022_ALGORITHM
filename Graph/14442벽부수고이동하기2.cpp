#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

bool MAP[1000][1000];
bool check[1000][1000][11];

struct pos_t {
  int x, y, brake, cnt;
};

int solve() {
  char input;
  int N, M, K, r, c;
  cin >> N >> M >> K;

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      cin >> input;
      MAP[i][j] = input - '0';
    }
  }

  queue<pos_t> Q;

  for (int i=0; i<=K; i++)
    check[0][0][i] = 1;
  Q.push({0, 0, K, 1});
  while (!Q.empty()) {
    pos_t pos = Q.front(); Q.pop();
    if (pos.x==N-1 && pos.y==M-1) return pos.cnt;
    for (int d=0; d<4; d++) {
      r=pos.x+dx[d]; c=pos.y+dy[d];
      if (r<0 || c<0 || r>=N || c>=M || check[r][c][pos.brake]) continue;
      if (MAP[r][c] && pos.brake > 0) {
        if (!check[r][c][pos.brake-1]) {
          check[r][c][pos.brake-1] = 1;
          Q.push({r, c, pos.brake-1, pos.cnt+1});
        }
      } else if (!MAP[r][c]) {
        check[r][c][pos.brake] = 1;
        Q.push({r, c, pos.brake, pos.cnt+1});
      }
    }
  }
  return -1; 
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cout << solve();
  return 0;
}