#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int N = 1000111;

void testcase() {
  int n, m; cin >> n >> m;
  vector<vi> a(n+1, vi(m+1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
    }
  }

  //no team solve all problems
  //each team solve at least one problem
  for (int row = 1; row <= n; row++) {
    int point = a[row][m] - a[row-1][m];
    if (point == 0 || point == m) {
      cout << "NO" << endl;
      return;
    }
  }

  for (int column = 1; column <= m; column++) {
    int point = a[n][column] - a[n][column-1];
    if (point == 0) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) { freopen("input.txt", "r", stdin); }
  int t = 1; 
  cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o