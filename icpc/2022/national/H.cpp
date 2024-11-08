#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int mod = 998244353; const int N = 1000111;

int n; 
typedef vector<vi> matrix;
int matrixSize = 6;

void dpSolve() {
  vi dp(n+1, 0); vi sum(n+1, 0);
  dp[0] = 1; dp[1] = 1; dp[2] = 5;
  sum[0] = 0; sum[1] = 0; sum[2] = 12;

  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-2] * 4 + dp[i-3] * 2;
    dp[i] %= mod;

    sum[i] = dp[i-2] * 12 + dp[i-3] * 12 + sum[i-1] + sum[i-2] * 4 + sum[i-3] * 2;
    sum[i] %= mod;
  }
  cout << sum[n] << endl;
}

matrix operator * (matrix a, matrix b) {
  int n = a.size();
  matrix c(matrixSize, vi(matrixSize));
  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      for (int k = 0; k < matrixSize; k++) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= mod;
      }
    }
  }
  return c;
}

// a^x
matrix pow(matrix a, int x) {
  if (x == 1) return a;

  matrix tmp = pow(a, x/2);
  if (x & 1) return tmp * tmp * a;
  return tmp * tmp;
}

matrix init() {
  return {
    // dp-1 dp-2 dp-3 s-1 s-2 s-3
    {1, 1, 0, 0 , 0, 0},
    {4, 0, 1, 12, 0, 0},
    {2, 0, 0, 12, 0, 0},
    {0, 0, 0, 1 , 1, 0},
    {0, 0, 0, 4 , 0, 1},
    {0, 0, 0, 2 , 0, 0}
  };
}

void matrixSolve() {
  matrix start(matrixSize, vi(matrixSize));
  start[0] = {5, 1, 1, 12, 0, 0};

  start = start * pow(init(), n);
  cout << start[0].back() << endl;
}

void testcase() {
  cin >> n;

  // dpSolve();
  matrixSolve();

}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) { freopen("input.txt", "r", stdin); }
  int t = 1; 
  //cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o