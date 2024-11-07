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
  int n, m, k; cin >> n >> m >> k;
  vi problems(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> problems[i];
  }

  vi res(n + 1, 0);
  for (int left = 1; left <= m; left++) {

    vi cnt(k + 1, 0);
    vi cntSum(k + 1, 0);
    vi pos(n + 1, 0);

    // no one has first solve.
    cnt[0] = n;

    // prefix sum
    for (int i = 0; i <= k; i++) {
      cntSum[i] = (i==0 ? 0 : cntSum[i - 1]) + cnt[i];
    }

    for (int right = left; right <= m && right <= left + k - 1; right++) {
      res[problems[right]] = max(res[problems[right]], cntSum[k] - cntSum[pos[problems[right]]] + 1);

      int& oldPosition = pos[problems[right]];
      cnt[oldPosition]--;
      cnt[oldPosition + 1]++;

      cntSum[oldPosition]--;

      oldPosition++;
    }

    for (int i = 1; i <= n; i++) {
      res[i] = max(res[i], cntSum[k] - cntSum[pos[i]] + 1);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
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