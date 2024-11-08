#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int mod = 998244353; const int N = 1000111;

void testcase() {
  int n; cin >> n;
  vector<vi> a(n, vi(n));
  for (auto &i: a) 
    for (auto &j: i) 
      cin >> j;//, cout << j << " \n"[j == i.back()];

  vi res(n, 0);

  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (j < i && a[i][i] < a[i][j]) cnt++;
      if (j > i && a[i][i] > a[i][j]) cnt++;
    }
    res[i] = cnt + 1;
  }
  for (auto i: res)
    cout << i << " ";
}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) { freopen("input.txt", "r", stdin); }
  int t = 1; 
  //cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o