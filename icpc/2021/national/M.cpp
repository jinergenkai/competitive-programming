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
  int n; cin >> n;

  cout << n*(n-1) + 1 << endl;

  for (int i = 1; i <= n; i++) {
    cout << i << " ";
  }
  cout << endl;

  vector<vi> table(n+1, vi(n+1, 0));
  int cnt = n;
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-1; j++) {
      table[i][j] = ++cnt;
    }
  }

  int trans = 0;
  for (int count = 0; count < n-1; count++) {
    for (int timer = 0; timer < n-1; timer++) {
      cout << count+1 << " ";
      for (int pos = 0; pos < n-1; pos++) {
        cout << table[(timer + pos * count)%(n-1)][pos] << " ";
      }
      cout << endl;
    }
  }

  for (int i = 0; i < n-1; i++) {
    cout << n << " ";
    for (int j = 0; j < n-1; j++) {
      cout << table[j][i] << " ";
    } 
    cout << endl;
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