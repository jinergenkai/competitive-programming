#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int N = 1000111;

int n, scoreA, scoreB;
int res = 0;
int value[30];

//if a or b reaches n points first and a - b < 2 then no more points are allowed
//if a or b has not reached n then the difference is allowed.
//if a and b both reach n points then a - b must >= 2
bool check(int a, int b) {
  if (a == scoreA && b == scoreB) {
    if ((a >= n || b >= n) && abs(a - b) >= 2) {
      res++;
    }
  }

  // play too much
  if (a > scoreA || b > scoreB) return false;

  // play too less
  if (a < n && b < n) return true;

  // if one player over n points but no one leading by at least 2 points
  if (abs(a - b) >= 2) return false;

  return true;
}

void backtrack(int i, int a, int b) {
  for (auto j : {0, 1}) {
    value[i] = j;

    (j == 0 ? a: b) += 1;

    if (!check(a, b)) {
      (j == 0 ? a: b) -= 1;
      continue;
    }

    if (a + b < scoreA + scoreB)
      backtrack(i + 1, a, b);

    (j == 0 ? a: b) -= 1;
  }
}

void testcase() {
  cin >> n >> scoreA >> scoreB;
  res = 0;

  backtrack(0, 0, 0);

  cout << res << endl;
}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int t = 1; 
  cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o