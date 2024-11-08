#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int mod = 998244353; const int N = 1000111;

struct Point {
  int x, y, value; //x*x + y*y = value*value
  double corner;
};


// sin = opposite / hypotenuse
void testcase() {

  int n; n = 3000;
  int count = 0;
  int max = 0;

  vector<Point> points;
  map<double, bool> dict; 

  for (int i = 1; i <= n; i++ ) {
    for (int j = 1; j < i; j++) {
      int test = i * i + j * j;
      int stest = sqrt(test);
      if (stest* stest == test && dict[(double)i/stest] == false) {
        points.push_back({i, j, stest, (double)i/stest});
        dict[(double)i/stest] = true;
        points.push_back({j, i, stest, (double)j/stest});
        dict[(double)j/stest] = true;
        max += i + j;
        count += 2;
      }
    }
  }
  // cerr << "count " << count << endl;
  // cerr << "max " << max << endl;

  sort(all(points), [&](Point a, Point b) {
    return a.corner < b.corner;
  });

  cin >> n;

  if (n <= 2) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  int x = -1000000;
  int y = -1000000;

  for (int i = 0; i < n-1; i++) {
    cout << x << " " << y << endl;

    if (i == n-2) break;

    x += points[i].x;
    y += points[i].y;
  }
  cout << x << " " << -1000000 << endl;

}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) { freopen("input.txt", "r", stdin); }
  int t = 1; 
  //cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o