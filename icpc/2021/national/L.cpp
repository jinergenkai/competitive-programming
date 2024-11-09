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
  vi a(n); for (int &i : a) cin >> i;


  int mx = sqrt(1e7+1000);
  vi rawPrime(mx + 1, 1);
  rawPrime[0] = rawPrime[1] = 0;
  for (int i = 2; i * i <= mx; i++) {
    if (rawPrime[i]) {
      for (int j = i * i; j <= mx; j += i) {
        rawPrime[j] = 0;
      }
    }
  }
  vi prime;
  for (int i = 2; i <= mx; i++) {
    if (rawPrime[i]) {
      prime.push_back(i);
    }
  }

  for (int i = 0; i < n; i++) {
    int& x = a[i];
    for (int j = 0; j < prime.size(); j++) {
      int p = prime[j];
      while (x % p == 0 && (x/p) % p == 0) {
        x /= p;
      }
    }
  }

  map<int, int> cnt;
  int res = 0;
  for (int i = 0; i < n; i++) {
    res += cnt[a[i]];
    cnt[a[i]]++;
  }
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