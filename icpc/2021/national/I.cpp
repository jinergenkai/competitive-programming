#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int mod = 998244353; const int N = 1000111;

int n;

int dp[51][16][16][16][16][16];
int tag[51][6];

struct Range {
  int l, r;
};

int getTag(string s) {
  if (s == "dp") return 0;
  if (s == "graph") return 1;
  if (s == "mathgeo") return 2;
  if (s == "ds") return 3;
  if (s == "adhoc") return 4;
  return -1;
}

//* Main function
void testcase() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    for (int j = 0; j < t; j++) {
      string s; cin >> s;
      tag[i][getTag(s)] = 1;
      // cout << getTag(s) << " ";
    }
  }

  int maxP = (1 << 4);
  dp[0][0][0][0][0][0] = 1;
  for (int index = 0; index < n; index++) {
    // dp[index + 1][0][0][0][0][0] = dp[index][0][0][0][0][0];
    for (int p1 = 0; p1 < maxP; p1++) {
      for (int p2 = 0; p2 < maxP; p2++) {
        for (int p3 = 0; p3 < maxP; p3++) {
          for (int p4 = 0; p4 < maxP; p4++) {
            for (int p5 = 0; p5 < maxP; p5++) {
              int nxt1 = p1 + tag[index][0];
              int nxt2 = p2 + tag[index][1];
              int nxt3 = p3 + tag[index][2];
              int nxt4 = p4 + tag[index][3];
              int nxt5 = p5 + tag[index][4];
              dp[index + 1][p1][p2][p3][p4][p5] += dp[index][p1][p2][p3][p4][p5];
              if (nxt1 >= maxP || nxt2 >= maxP || nxt3 >= maxP || nxt4 >= maxP || nxt5 >= maxP) {
                continue;
              }
              dp[index + 1][nxt1][nxt2][nxt3][nxt4][nxt5] += dp[index][p1][p2][p3][p4][p5];
            }
          }
        }
      }
    }
  }
  // cout << dp[6][1][1][0][0][0] << endl;

  vector<Range> range;
  for (int i = 0; i < 5; i++) {
    int l, r; cin >> l >> r;
    range.push_back({l, r});
  }

  int res = 0;

  for (int p1 = range[0].l; p1 <= range[0].r; p1++) {
    for (int p2 = range[1].l; p2 <= range[1].r; p2++) {
      for (int p3 = range[2].l; p3 <= range[2].r; p3++) {
        for (int p4 = range[3].l; p4 <= range[3].r; p4++) {
          for (int p5 = range[4].l; p5 <= range[4].r; p5++) {
            res += dp[n][p1][p2][p3][p4][p5];
          }
        }
      }
    }
  }

  if (range[0].l == 0 && range[1].l == 0 && range[2].l == 0 && range[3].l == 0 && range[4].l == 0) {
    res--;
  }

  cout << res;
}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) { freopen("input.txt", "r", stdin); }
  int t = 1; 
  //cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o