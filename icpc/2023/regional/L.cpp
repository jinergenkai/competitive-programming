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
  int m; cin >> m;
  string s; cin >> s;

  if (m == 1) {
    cout << "YES" << endl;
    return;
  }

  while(s.size() < m) s = "0" + s; //On^2
  
  //create string
  string tmp = "";
  for (int i = 1; i <= m-2; i++) {
    tmp.push_back('0');
  }
  tmp = '1' + tmp + '1';

  // cerr << 's' << s << ' ' << 't' << tmp << endl;
  //check s > tmp;
  if (s.size() > tmp.size() || s >= tmp) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;

}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) { freopen("input.txt", "r", stdin); }
  int t = 1; 
  cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o