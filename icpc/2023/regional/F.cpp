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
  string a, b; cin >> a >> b;

  vector<char> oddA, evenA, oddB, evenB;
  for (int i = 0; i < a.size(); i++) {
    (i % 2 == 0 ? evenA : oddA).push_back(a[i]);
  }
  for (int i = 0; i < b.size(); i++) {
    (i % 2 == 0 ? evenB : oddB).push_back(b[i]);
  }

  sort(all(oddA));
  sort(all(evenA));
  sort(all(oddB));
  sort(all(evenB));

  if (oddA == oddB && evenA == evenB) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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