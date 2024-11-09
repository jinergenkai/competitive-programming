#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int mod = 998244353; const int N = 1000111;

struct arr {
  int value;
  int index;
  int result;
};

int n;
int last[N];

int par[N];
int root[N];
int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}
void join(int u, int v) {
  if ((u = find(u)) != (v = find(v))) {
    par[u] = v;
    root[v] += root[u];
    root[u] = 0;
  }
}

//* Main function
void testcase() {
  int n; cin >> n; int m = n*n;
  vector<arr> a; a.push_back({0, 0, 0});

  for (int i = 1; i <= m; i++) {
    par[i] = i;
    root[i] = 1;
  } 

  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    a.push_back({x, 0, 0});

    int lastX = last[x]; 
    if (lastX == 0) lastX = i;
    int pLastX = find(lastX);

    if (root[pLastX] < n) {
      join(pLastX, i);
    }

    last[x] = i;
  }

  int cntGroup = 0;
  int cntPassGroup = 0;
  vi hasGroup(m + 1, 0);

  vector<arr> graph;
  for (int i = 1; i <= m; i++) {
    if (root[i] == n) {
      cntPassGroup++;
      if (hasGroup[find(i)] == 0) cntGroup++;
      hasGroup[find(i)] = cntGroup;
      continue;
    }
    if (root[i] != 0) {
      //                mod       color  
      graph.push_back({root[i], find(i), 0});
    }
  }

  sort(graph.begin(), graph.end(), [](arr a, arr b) {
    return a.value < b.value;
  });

  int l = 0, r = graph.size()-1;
  while(l < r) {
    if (graph[l].value + graph[r].value != n) {
      break;
    }
    hasGroup[find(graph[l].index)] = ++cntGroup;
    hasGroup[find(graph[r].index)] = cntGroup;
    l++; r--;
  }

  int cntOne = 0;
  for (int i = l; i <= r; i++) {
    cntOne += graph[i].value;
  }
  if (cntOne > cntPassGroup) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  for (int i = 1; i <= m; i++) {
    cout << hasGroup[find(i)] << " ";
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