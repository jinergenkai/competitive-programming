#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int N = 1000111;

struct Query {
  char type;
  int oldIndex;
  int version;
  int vertice1;
  int vertice2;
  int result;
};
vector<Query> queries;
int n, query;
int par[N];
int s, u, v;

// handle offline queries
void testcase() {
  cin >> n >> query;

  int curVersion = 0;

  for (int i = 1; i <= query; i++) {
    char x; cin >> x;
    switch (x) {
      case 'A':
        cin >> u >> v;
        queries.push_back({'A', i, curVersion, u, v, 0});
        break;
      case '?':
        cin >> u >> v;
        queries.push_back({'?', i, curVersion, u, v, 0});
        break;
      case 'C':
        curVersion++;
        break;
      case 'Q':
        cin >> s >> u >> v;
        s--; // down ver for Q
        queries.push_back({'Q', i, s, u, v, 0});
    }
  }

  sort(all(queries), [&](Query a, Query b) {
    if (a.version == b.version) {
      if (a.type == 'Q' && b.type != 'Q') return false;
      return a.oldIndex < b.oldIndex;
    }
    return a.version < b.version;
  });

  // Disjoint set
  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }
  function<int(int)> find = [&](int p) {
    return par[p] == p ? p : par[p] = find(par[p]);
  };
  function<void(int, int)> join = [&](int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
      par[u] = v;
    }
  };

  for (auto &q : queries) {
    switch (q.type) {
      case 'A':
        join(q.vertice1, q.vertice2);
        break;
      case '?':
        q.result = find(q.vertice1) == find(q.vertice2);
        break;
      case 'Q':
        q.result = find(q.vertice1) == find(q.vertice2);
        break;
      case 'C':
        break;
    }
  }

  sort(all(queries), [&](Query a, Query b) {
    return a.oldIndex < b.oldIndex;
  });

  for (auto q: queries) {
    if (q.type == '?' || q.type == 'Q') {
      cout << (q.result ? "Y" : "N");
    }
  }
}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) { freopen("input.txt", "r", stdin); }
  int t = 1; 
  //cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o