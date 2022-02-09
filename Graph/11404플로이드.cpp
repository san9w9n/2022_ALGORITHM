#include <bits/stdc++.h>
using namespace std;
#define MAXCITY 101

int graph[MAXCITY][MAXCITY];
int N;

void Floyd_Warshall() {
  for (int k=1; k<=N; k++) 
    for (int i=1; i<=N; i++) 
      for (int j=1; j<=N; j++) 
        graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
}

void solve() {
  int M, s, e, c;
  cin >> N >> M;
  for (int i=0; i<M; i++) {
    cin >> s >> e >> c;
    if (!graph[s][e])
      graph[s][e] = c;
    else
      graph[s][e] = min(graph[s][e], c);
  }
  for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
    if (i==j) graph[i][j] = 0;
    else if (!graph[i][j]) graph[i][j] = INT32_MAX/2;
  }
  Floyd_Warshall();
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      if (graph[i][j] == INT32_MAX/2) cout << "0 ";
      else cout << graph[i][j] << " ";
    }
    cout << "\n";
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();
  return 0;
}