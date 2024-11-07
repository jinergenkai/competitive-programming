#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 998244353; const int N = 1000111;


// denote dp[i][j] is the number of ways to dfs move over i nodes and height of i is j.
void testcase() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
  }

  vector<vi> dp(n + 1, vi(n + 1, 0));
  dp[1][0] = 1;
  
  for (int i = 1; i < n; i++) {
    for (int k = 0; k <= i; k++) {
      for (int h = k; h <= i; h++) {
        dp[i+1][k+1] += dp[i][h] % inf * (1LL << (k)) % inf;
        dp[i+1][k+1] %= inf;
      }
    }
  }

  int res = 0;
  for (int i = 0; i <= n; i++) {
    res += dp[n][i];
    res %= inf;
  }
  cout << res << endl;
}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) { freopen("input.txt", "r", stdin); }
  int t = 1; 
  //cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o