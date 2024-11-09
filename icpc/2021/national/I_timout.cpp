#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int mod = 998244353; const int N = 53;
const int maxTag = 1 << (5 * 4) - 1;

int dp[N][maxTag];
string tagName[5] = {"dp", "graph", "mathgeo" , "ds", "adhoc"};

int getTagValue(int x, int pos) {
  return (x >> (pos * 4)) & 15;
}
int listTag[N][6];

int convert(string s) {
  if (s == "dp") return 1;
  if (s == "graph") return 2;
  if (s == "mathgeo") return 3;
  if (s == "ds") return 4;
  if (s == "adhoc") return 5;
  return 0;
}

//* Main function
void testcase() {
  int n; cin >> n;

  dp[0][0] = 1;

  for (int i = 1; i <= n; i++) {
    int len; cin >> len;
    int cnt = 0;
    for (int j = 0; j < len; j++) {
      string s; cin >> s;
      listTag[i][cnt++] = convert(s);
    }
  }

  for (int pos = 1; pos <= n; pos++) {
    // dp[pos][0] = 1;
    // get value each tag
    vi tagValue(5);
    for (int mask = 0; mask < maxTag; mask++) {
      dp[pos][mask] = dp[pos - 1][mask];
      for (int j = 0; j < 5; j++) {
        tagValue[j] = getTagValue(mask, j);
      }

      bool canDp = true;
      vi preTagValue = tagValue;
      for (int i = 0; i < 6; i++) {
        if (listTag[pos][i] == 0) {
          continue;
        }
        int& tmp = preTagValue[listTag[pos][i]-1];
        tmp--;
        if (tmp < 0) {
          canDp = false;
        }
      }
      if (!canDp) {
        continue;
      }

      int preMask = 0;
      for (int j = 0; j < 5; j++) {
        preMask += preTagValue[j] << (j * 4);
      }

      dp[pos][mask] += dp[pos - 1][preMask];
    }
  }

  vector<pii> range;
  for (int i = 0; i < 5; i++) {
    int l, r; cin >> l >> r;
    range.push_back({l, r});
  }

  int res = 0;
  for (int mask = 0; mask < maxTag; mask++) {
    bool ok = true;
    for (int i = 0; i < 5; i++) {
      int cnt = getTagValue(mask, i);
      if (cnt < range[i].fi || cnt > range[i].se) {
        ok = false;
        break;
      }
    }
    if (ok) {
      res += dp[n][mask];
    }
  }

  int canZero = 1;
  for (int i = 0; i < 5; i++) {
    if (range[i].fi != 0) {
      canZero = 0;
      break;
    }
  }

  cout << res - canZero << endl;
}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) { freopen("input.txt", "r", stdin); }
  int t = 1; 
  //cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o