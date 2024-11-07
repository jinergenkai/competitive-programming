#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int N = 1000111;

int value[3] = {'S', 'P', 'R'};


// just brute force all possible k
// Complexity: O(n + n/2 + n/3 + ... + n/n) ~ O(n log n)
void testcase() {
  string s; cin >> s; 
  int n; n = s.size();s += '@';
  vector<vi> count(3, vi(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      count[j][i] = count[j][i-1] + (s[i-1] == value[j]);
    }
  }

  int res = 0, valueK = 0;
  for (int k = 2; k <= n; k++) {

    int ans = 0;
    for (int i = 1; i <= n; i += k) {
      int end = min(n, i + k - 1);
      int maxCount = 0;
      for (int j = 0; j < 3; j++) {
        maxCount = max(maxCount, count[j][end] - count[j][i-1]);
      }
      ans += maxCount;
    }

    if (res <= ans) {
      res = ans;
      valueK = k;
    }
  }
  cout << valueK << endl;

}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int t = 1; 
  cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o