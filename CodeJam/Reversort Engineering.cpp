#include <bits/stdc++.h>

using namespace std;

int t, n, c, f[105][1005];

int canFind(int n, int c) {
    if (1 == n) 
     return 0 == c;
    if (f[n][c] != -1) return f[n][c];
    int res = 0;
    for(int i = 1; (i <= min(c, n)) && res == 0; i++)
        if (canFind(n - 1, c - i))
            res = i;
    f[n][c] = res;
    // cout << n << " " << c << " " << res << endl;
    return res;
}

vector<int> rotate(const vector<int>& a, int from, int to) {
    vector<int> res = a;
    for(int i = from; i < from + (to - from + 1) / 2; i++)
        swap(res[i], res[to - i + from]);
    return res;
}

vector<int> findRes(int n, int c) {
    if (1 == n) 
     return vector<int>(1, 1);
    vector<int> res(n, 0);
    int pos = canFind(n, c);
    res[pos - 1] = 1;
    vector<int> rec = findRes(n - 1, c - pos);
    for(int i = 0; i < rec.size(); i++)
        if (pos-1>i) 
            res[i] = rec[i] + 1;
         else 
            res[i + 1] = rec[i] + 1;
    return rotate(res, 0, pos - 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> t;
    int ntest = 1;
    memset(f, 255, sizeof(f));
    while (t--) {
        cin >> n >> c;
        cout << "Case #" << ntest++ << ": ";
        if (0<canFind(n, c) ) {
            vector<int> res = findRes(n, c);
            for(int i : res)
                cout << i << " ";
            cout << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;   
        }
    }
}
