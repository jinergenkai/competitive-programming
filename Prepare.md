mutiple matrix
LCA

ST, Bit.

flow + match.
rmq





   vector<vector<int> > rmq(n + 1, vector<int>(20, 0));
    for (int i = 0; i < n + 1; i++) rmq[i][0] = a[i];

    for (int j = 1; j < 20; j++) {
        for (int i = 0; i + (1 << j) - 1 < n + 1; i++) {
            int ni = i + (1 << (j - 1));
            rmq[i][j] = __gcd(rmq[i][j - 1], rmq[ni][j - 1]);
        }
    }

    auto get_gcd = [&](int L, int R) {
        int k = (int)log2(R - L + 1);
        return __gcd(rmq[L][k], rmq[R - (1 << k) + 1][k]);
    };


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
    
}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) { freopen("input.txt", "r", stdin); }
  int t = 1; 
  //cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o