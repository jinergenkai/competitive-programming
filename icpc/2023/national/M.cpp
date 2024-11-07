#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
const int inf = 1e9 + 7; const int N = 1000111;


int n;
string randomS, s;

// string ans = "100"; // for testing
int countInteract = 0;

// for testing
// int interact(char ask, string s) {
//   countInteract++;
//   if (ask == '?') {
//     int cnt = 0;
//     for (int i = 0; i < s.size(); i++) {
//       if (s[i] == ans[i]) {
//         cnt++;
//       }
//     }
//     return (s.size()-cnt) > cnt;
//   }
//   return (ans == s);
// }

int interact(char ask, string s) {
  countInteract++;
  cout << ask << " " << s << endl;
  cout.flush();

  if (ask == '!') {
    exit(0);
  }

  int get; cin >> get;
  return get;
}

char flip(char c) {
  return (c == '0' ? '1' : '0');
}


void testcase() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    randomS.push_back('0');
  }
  // if first randomS == 1 swap to 0.
  if (interact('?', randomS) == 1) {
    for (int i = 0; i < n; i++) {
      randomS[i] = '1';
    }
  }

  //check when flip from 1 to mid.
  auto checkFlip = [&](int mid) {
    string newS = randomS;
    for (int i = 0; i < mid; i++) {
      newS[i] = flip(newS[i]);
    }
    return interact('?', newS);
  };

  int l = 0, r = n-1, mid = 0;
  // find LR adjacent each other. interact L = 0, R = 1.
  while (l+1 < r) {
    int mid = (l + r) / 2;
    if (checkFlip(mid) == 0) {
      l = mid; 
    } else {
      r = mid;
    }
  }


  s = randomS;
  for (int i = 0; i <= l; i++) {
    s[i] = flip(s[i]);
  }

  // get result from s; when flip one char. if change into 1, then keep it. else flip it.
  string res = "";
  for (int i = 0; i < n; i++) {

    s[i] = flip(s[i]);
    int isChange = interact('?', s);
    s[i] = flip(s[i]);

    if (isChange == 1) {
      res.push_back(s[i]);
    }
    else {
      res.push_back(flip(s[i]));
    }
  }

  // cerr << "countInteract: " << countInteract << endl;
  // cerr << "res: " << res << endl;
  // cerr << "ans: " << ans << endl;
  // cerr << "res == ans: " << (res == ans) << endl;
  interact('!', res);
}

int32_t main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) { freopen("input.txt", "r", stdin); }
  int t = 1; 
  //cin >> t; 
  while(t--) testcase();
}
//   ／))      /)／)
//  (・   )o  (・   )o