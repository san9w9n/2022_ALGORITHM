#include <bits/stdc++.h>
using namespace std;
int V, E;

struct edge_t {
  int s, e, c;
};

int unionArr[10001];

struct comp {
  bool operator()(edge_t& a, edge_t& b) {
    return a.c > b.c;
  }
};

int getParent(int s) {
  int tmp = s;
  while (unionArr[s] != s) s = unionArr[s];
  return unionArr[tmp] = s;
}

void makeUnion(int s, int e) {
  int sParent = getParent(s);
  int eParent = getParent(e);
  unionArr[eParent] = sParent;
}

void solve() {
  int s, e, c;
  priority_queue<edge_t, vector<edge_t>, comp> PQ;

  cin >> V >> E;
  for (int i=0; i<E; i++) {
    cin >> s >> e >> c;
    PQ.push({s, e, c});
    unionArr[s] = s;
    unionArr[e] = e;
  }

  int cnt = 1, ans = 0;
  while (!PQ.empty() && cnt!=V) {
    edge_t cur = PQ.top(); PQ.pop(); 
    if (getParent(cur.s) == getParent(cur.e)) continue;
    makeUnion(cur.s, cur.e);
    ans += cur.c;
    cnt++;
  }
  cout << ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();
  return 0;
}