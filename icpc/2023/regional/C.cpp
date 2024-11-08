#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int N = 1000111;

int direction[6][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}};

void testcase() {
  int n; cin >> n;

  cout << "YES" << endl << 7 * n << endl;
  for (int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    cout << x << " " << y << " " << 3 << endl;
    for (int j = 0; j < 6; j++) {
      cout << x + direction[j][0] << " " << y + direction[j][1] << " " << 2 << endl;
    } 
  }
}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) { freopen("input.txt", "r", stdin); }
  int t = 1; 
  cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o