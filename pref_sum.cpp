//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <numeric>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//inline int sum(int l1, int l2, int r1, int r2,
//               vector<vector<int>>& pref ) {
//    int ans = pref[r1][r2];
//    if (l1 > 0) {
//        ans -= pref[l1 - 1][r2];
//    }
//    if (l2 > 0) {
//        ans -= pref[r1][l2 - 1];
//    }
//    if (l1 > 0 && l2 > 0) {
//        ans += pref[l1 - 1][l2 - 1];
//    }
//    return ans;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> a(n, vector<int>(m));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin>> a[i][j];
//        }
//    }
//    vector<vector<int>> pref(n, vector<int>(m));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            pref[i][j] = a[i][j];
//            if (i > 0) {
//                pref[i][j] += pref[i - 1][j];
//            }
//            if (j > 0) {
//                pref[i][j] += pref[i][j - 1];
//            }
//            if (i > 0 && j > 0) {
//                pref[i][j] -= pref[i - 1][j - 1];
//            }
//        }
//    }
//    int q;
//    cin >> q;
//    for (int i = 0; i < q; ++i) {
//        int l1, l2, r1, r2;
//        cin >> l1 >> r1 >> l2 >> r2;
//        cout << sum(l1 - 1, l2 - 1, r1 - 1, r2 - 1, pref);
//    }
//    return 0;
//}
//
//
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <numeric>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//inline int pref_sum(int i, vector<int>& a, vector<int>& pref) {
//    return pref[i-1] + a[i];
//}
//
//inline int summ(int l, int r, const vector<int>& pref) {
//    return pref[r] - (l == 0 ? 0 : pref[l - 1]);
//}
//
//ll INF = 1e9 + 9;
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    vector<int> pref(n);
//    pref[0]= a[0];
//    for (int i = 1; i < n; ++i) {
//        pref[i] = pref_sum(i, a, pref);
//    }
//    vector<int> maxpref(n);
//    int minn = min(pref[0], 0);
//    maxpref[0] = max(a[0], 0);
//    for (int i = 1; i < n; ++i) {
//        maxpref[i] = pref[i] - minn;
//        minn = min(minn, pref[i]);
//    }
//    vector<int> maxsuff(n);
//    maxsuff[n - 1] = max(a[n - 1], 0);
//    minn = min(summ(n - 1, n - 1, pref), 0);
//    for (int i = n - 2; i > -1; --i) {
//        maxsuff[i] = summ(i, n - 1, pref) - minn;
//        minn = min(minn, summ(i, n - 1, pref));
//    }
//    vector<int> maxsuff2(n);
//    maxsuff2[n - 1] = maxsuff[n - 1];
//    for (int i = n - 2; i > -1; --i) {
//        maxsuff2[i] = max(maxsuff2[i + 1], maxsuff[i]);
//    }
//    int ans = maxsuff2[0];
//    for (int i = 0; i < n - 1; ++i) {
//        ans = max(ans, maxpref[i] + maxsuff2[i + 1]);
//    }
//    ans = max(ans, maxpref[n - 1]);
//    cout << ans << '\n';
//    return 0;
//}


















//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <numeric>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//inline int ask(int x1, int x2, int y1, int y2, vector<vector<int>>& pref) {
//    return pref[x2][y2] - pref[x2][y1 - 1] - pref[x1 - 1][y2] + pref[x1 - 1][y1 - 1];
//}
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n, m, k;
//    cin >> n >> m >> k;
//    vector<vector<int>> a(n+1, vector<int>(m+1));
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            cin >> a[i][j];
//        }
//    }
//    vector<vector<int>> pref(n+1, vector<int>(m+1, 0));
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + a[i][j];
//        }
//    }
//    for (int i = 0; i < k; ++i) {
//        int x1, x2, y1, y2;
//        cin >> x1 >> y1 >> x2 >> y2;
//        cout << ask(x1, x2, y1, y2, pref) << '\n';
//    }
//}