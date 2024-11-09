#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int mod = 998244353; const int N = 200111;

struct query {
  int l, r, value;
  int index;
  int result;
};

struct arr {
  int value;
  int index;
};

struct node {
  int suffixValue;
  int count;
};

int n, numQuery;
vector<arr> a;
vector<query> queries;

int singleBit[N];
void singleUpdate(int p, int value) {
  for (; p <= n; p += p & -p) {
    singleBit[p] += value;
  }
}
int singleQuery(int p) {
  int result = 0;
  for (; p > 0; p -= p & -p) {
    result += singleBit[p];
  }
  return result;
}

node bit[N];
void doubleUpdate(int p, node value) {
  for (; p <= n; p += p & -p) {
    bit[p].suffixValue += value.suffixValue;
    bit[p].count += value.count;
  }
}
node doubleQuery(int p) {
  node result = {0, 0};
  for (; p > 0; p -= p & -p) {
    result.suffixValue += bit[p].suffixValue;
    result.count += bit[p].count;
  }
  return result; 
}

//* Main function
void testcase() {
  cin >> n >> numQuery;
  a.resize(n+1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i].value;
    a[i].index = i; 
  }

  for (int i = 0; i < numQuery; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    queries.push_back({x, y, v, i, 0});
  }

  sort(all(queries), [&](query &a, query &b) {
    return a.value < b.value;
  });

  a[0] = {-inf, 0};
  sort(all(a), [&](arr &a, arr &b) {
    return a.value < b.value;
  });

  int indexA = 1;

  for (int i = 0; i < numQuery; i++) {
    while (indexA <= n && a[indexA].value <= queries[i].value) {
      singleUpdate(a[indexA].index, 1);
      indexA++;
    }
    // queries[i].result = singleQuery(queries[i].r) - singleQuery(queries[i].l - 1);
  }

  // create new array from A.
  sort(all(a), [&](arr a, arr b) {
    return a.index < b.index;
  });
  for (int i = 1; i < n; i++) {
    a[i] = {__gcd(a[i].value, a[i+1].value), i};
  }
  sort(all(a), [&](arr a, arr b) {
    return a.value < b.value;
  });

  
  // query again find sequence >= 2.
  indexA = 1;
  for (int i = 0; i < numQuery; i++) {

    // queries[i].r--;

    while (indexA < n && a[indexA].value <= queries[i].value) {
      doubleUpdate(a[indexA].index, {n - a[indexA].index, 1});
      indexA++;
    }
    int ans = doubleQuery(queries[i].r).suffixValue - doubleQuery(queries[i].l - 1).suffixValue;
    int countAns = doubleQuery(queries[i].r).count - doubleQuery(queries[i].l - 1).count;

    queries[i].result += ans - countAns*(n - queries[i].r) ;//+ (queries[i].r - queries[i].l + 1);
  }

  sort(all(queries), [&](query a, query b) {
    return a.index < b.index;
  });

  for (int i = 0; i < numQuery; i++) {
    cout << queries[i].result << endl;
  }
}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) { freopen("input.txt", "r", stdin); }
  int t = 1; 
  //cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o