//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//const ll INF = 1e9 + 9;
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
//    vector<int> p(n+1, -1);
//    vector<int> index(n + 1, -1);
//    vector<int> dp(n + 1, INF);
//    dp[0] = -INF;
//    for (int i = 0; i < n; ++i) {
//        int pos = dp[lower_bound(dp.begin(), dp.end(), a[i])-dp.begin()];
//        dp[pos] =a[i];
//        index[pos] = i;
//        p[i] = index[pos - 1];
//    }
//    int cur = -1;
//    for (int i = n; i > -1; --i) {
//        if (dp[i] != INF) {
//            cur = index[i];
//            break;
//        }
//    }
//    vector<int> ans;
//    while(cur != -1) {
//        ans.push_back(a[cur]);
//        cur = p[cur];
//    }
//    reverse(ans.begin(), ans.end());
//    for (int i : ans) {
//        cout << i << ' ';
//    }
//
//}










//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//inline int get(int i, int j, const vector<vector<int>>& dp) {
//    if (i < 0 || j < 0) {
//        return 0;
//    }
//    return dp[i][j];
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, m;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin>>a[i];
//    }
//    cin >> m;
//    vector<int> b(m);
//    for (int i = 0; i < m; ++i) {
//        cin>>b[i];
//    }
//    vector<vector<int>> p(n, vector<int>(m, -1));
//    vector<vector<int>> dp(n, vector<int>(m));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            if (a[i] == b[j]) {
//                dp[i][j] = get(i - 1, j - 1, dp) + 1;
//                p[i][j] = 0;
//            } else {
//                if (get(i - 1, j, dp) > get(i, j - 1, dp)) {
//                    dp[i][j] = get(i - 1, j, dp);
//                    p[i][j] = 1;
//                }
//                else {
//                    dp[i][j] = get(i, j - 1, dp);
//                    p[i][j] = 2;
//                }
//            }
//        }
//    }
//    int curi = n - 1, curj = m - 1;
//    vector<int> ans;
//    while (curi >= 0 && curj >= 0) {
//        if (p[curi][curj] == 0 ) {
//            ans.push_back(a[curi]);
//            curi--;
//            curj--;
//        } else if (p[curi][curj] == 1) {
//            curi--;
//        } else {
//            curj--;
//        }
//    }
//    reverse(ans.begin(), ans.end());
//    for (int i : ans) {
//        cout << i << ' ';
//    }
//    return 0;
//}
