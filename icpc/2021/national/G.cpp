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
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  sort(all(a));
  int res = 0;
  for (int i = 0; i < k; i++)
    if (a[i] > 1)
      res += a[i];
  cout << res << " ";

  res = 0;
  for (int i = n-1; i >= 0 && i >= n-k; i--)
    if (a[i] > 1)
      res += a[i];
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


//12m