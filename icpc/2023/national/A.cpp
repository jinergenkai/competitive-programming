#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
template<typename T, typename... Args> void print(T a, Args... args) {cout << a << " ";print(args...);}
const int inf = 1e9 + 7; const int N = 1000111;

void testcase() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << (c == 0 ? "NO CURVE" : (c < 0) ? "CURVE DOWN" : "CURVE UP") << endl;
}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int t = 1; 
  cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o