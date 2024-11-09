#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int mod = 998244353; const int N = 1000111;

int a[1011][1011];

//* Main function
void testcase() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c; cin >> c;
      a[i][j] = c - 'A';
    }
  }

  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vi corner = {a[i][j], a[i][m - j - 1], a[n - i - 1][j], a[n - i - 1][m - j - 1]};
      int mx = inf;
      for (int chooseCorner = 0; chooseCorner < 4; chooseCorner++) {
        int cnt = 0;
        for (int index = 0; index < 4; index++) {
          int minMove = min((corner[chooseCorner] - corner[index] + 26) % 26, (corner[index] - corner[chooseCorner] + 26) % 26);
          cnt += minMove;
        }
        mx = min(mx, cnt);
      }
      ans += mx;
    }
  }
  cout << ans/4 << endl;
}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) { freopen("input.txt", "r", stdin); }
  int t = 1; 
  //cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o

// 　＼(⊆／)／
// 12m