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