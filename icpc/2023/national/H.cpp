#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int N = 200011;

int a[N];
vector<vi> bit;
vector<vi> xZone;
bool mark[N];

void update(int x, int p, int value) {
  for (int i = p; i <= bit[x].size()-1; i += i &(-i)) {
    bit[x][i] += value;
  }
}

int get(int x, int p) {
  int res = 0;
  for (int i = p; i > 0; i -= i & (-i)) {
    res += bit[x][i];
  }
  return res;
}

void testcase() {
  int n, q; cin >> n >> q;
  bit.resize(n + 1);
  xZone.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mark[a[i]] = true;

    if (xZone[a[i]].empty()) xZone[a[i]].push_back(0), bit[a[i]].push_back(0);
    xZone[a[i]].push_back(i);
    bit[a[i]].push_back(0);
  }


  // init
  for (int x = 1; x <= n; x++) {
    if (mark[x]) {
      for (int j = 1; j < xZone[x].size(); j++) {
        update(x, j, xZone[x][j] * xZone[x][j]);
      }
    }
  }


  int last = 0;
  while(q--) {

    int type; cin >> type;
    
    // type 1: swap values ai ai+1
    if (type == 1) {
      int value; cin >> value;
      value = (value + last - 1) % (n - 1) + 1;  

      int& firstItem = a[value];
      int& secondItem = a[value + 1];

      if (firstItem == secondItem) continue;

      //find index firstItem in xZone by binary search
      int indexF = lower_bound(all(xZone[firstItem]), value) - xZone[firstItem].begin();
      if (indexF == xZone[firstItem].size()) continue;

      update(firstItem, indexF, -value * value);
      update(firstItem, indexF, (value + 1) * (value + 1));

      //find index secondItem in xZone by binary search
      int indexS = lower_bound(all(xZone[secondItem]), value + 1) - xZone[secondItem].begin();
      if (indexS == xZone[secondItem].size()) continue;

      update(secondItem, indexS, -(value + 1) * (value + 1));
      update(secondItem, indexS, value * value);

      swap(xZone[firstItem][indexF], xZone[secondItem][indexS]);
      swap(firstItem, secondItem);
      
      continue;
    }

    int l, r, x; cin >> l >> r >> x;
    l = (l + last - 1) % n + 1;
    r = (r + last - 1) % n + 1;
    if (l > r) swap(l, r);
    x = (x + last - 1) % n + 1;

    if (type == 2) {
      // find leftIndex and rightIndex - leftIndex <= l && r <= rightIndex
      int leftIndex = lower_bound(all(xZone[x]), l) - xZone[x].begin();

      int rightIndex = upper_bound(all(xZone[x]), r) - xZone[x].begin();
      if (rightIndex == xZone[x].size() || xZone[x][rightIndex] > r) {
        rightIndex--;
      }

      if (leftIndex > rightIndex) {
        last = 0;
        cout << last << endl;
        continue;
      }

      last = get(x, rightIndex) - ((leftIndex-1 == 0) ? 0 : get(x, leftIndex-1));
      cout << last << endl;
      continue;
    }

    // type 3
    last = get(x, r) - ((l-1 == 0) ? 0 : get(x, l-1));
    cout << last << endl;


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