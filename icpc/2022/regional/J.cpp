#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int mod = 998244353; const int N = 1000111;

//* Main function
void testcase() {
  string s;
  vector<char> key = {'I', 'C', 'P', 'C'};

  while(cin >> s) {
    if (s == "$") return; 
    int n = s.size();

    vector<vi> dp(n + 2, vi(4));
    for (int i = n-1; i >= 0; i--) {
      for (int j = 3; j >= 0; j--) {
        if (j == 3 && s[i] == key[j]) {
          dp[i][j] = 1 + dp[i+1][j];
          continue;
        }

        dp[i][j] = dp[i+1][j];
        if (s[i] == key[j]) {
          dp[i][j] += dp[i+2][j+1];
        }
      }
    }

    cout << dp[0][0] << endl;
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
