//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <string>
//#include <algorithm>
//#include <numeric>
//#include <map>
//#include <set>
//#include <cmath>
//
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-8;
//const double INF = 1e9;
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.precision(30);
//    string s;
//    cin >> s;
//    int n = s.size();
//    vector<vector<int>> dp(n, vector<int>(n));
//    for (int i = 0; i < n; ++i) {
//        dp[i][i] = 1;
//    }
//    for (int len = 2; len <= n; ++len) {
//        for (int l = 0; l + len <= n; ++l) {
//            int r = l + len - 1;
//            if (s[l] == s[r]) {
//                dp[l][r] = dp[l + 1][r - 1] + 2;
//            } else {
//                dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
//            }
//        }
//    }
//    cout << dp[0][n - 1] << '\n';
//    return 0;
//}
//




//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <string>
//#include <algorithm>
//#include <numeric>
//#include <map>
//#include <set>
//#include <cmath>
//
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-8;
//const double INF = 1e9;
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.precision(30);
//    string s;
//    cin >> s;
//    int n = s.size();
//    vector<vector<int>> dp(n, vector<int>(n));
//    for (int i = 0; i < n; ++i) {
//        dp[i][i] = 1;
//    }
//    for (int len = 2; len <= n; ++len) {
//        for (int l = 0; l + len <= n; ++l) {
//            int r = l + len - 1;
//            dp[l][r] = dp[l][r - 1] + dp[l + 1][r] - dp[l + 1][r - 1];
//            if (s[l] == s[r]) {
//                dp[l][r] += (dp[l + 1][r - 1] + 1);
//            }
//        }
//    }
//    cout << dp[0][n - 1] << '\n';
//    return 0;
//}
//



//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <string>
//#include <algorithm>
//#include <numeric>
//#include <map>
//#include <set>
//#include <cmath>
//
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-8;
//const int INF = 1e9;
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.precision(30);
//    int L, n;
//    cin >> L >> n;
//    vector<int> x(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> x[i];
//    }
//    x.insert(x.begin(), 0);
//    x.push_back(L);
//    n += 2;
//    vector<vector<int>> dp(n, vector<int>(n));
//    for (int len = 3; len <= n; ++len) {
//        for (int l = 0; l + len <= n; ++l) {
//            int r = l + len - 1;
//            dp[l][r] = INF;
//            for (int k = l + 1; k <= r - 1; ++k) {
//                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r]);
//            }
//            dp[l][r] += (x[r] - x[l]);
//        }
//    }
//    cout << dp[0][n - 1 ] << '\n';
//    return 0;
//}
//




//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <string>
//#include <algorithm>
//#include <numeric>
//#include <map>
//#include <set>
//#include <cmath>
//
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-8;
//const int INF = 1e9;
//
//
//int n;
//vector<vector<int>> dp;
//vector<vector<pair<int, int>>> gr(n);
//
//void dfs(int v, int p = -1) {
//    for (auto& [u, w] : gr[v]) {
//        if (u != p) {
//            dfs(u, v);
//            dp[v][0] += max(dp[u][0], dp[u][1]);
//        }
//    }
//    for (auto& [u, w] : gr[v]) {
//        if(u != p) {
//            dp[v][1] = max(dp[v][1], dp[u][0] + w + dp[v][0] - max(dp[u][0], dp[u][1]));
//        }
//    }
//}
//
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.precision(30);
//    int n;
//    cin >> n;
//    gr.resize(n);
//    dp.resize(n, vector<int>(2));
//    for (int i = 0; i < n; ++i) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        u--; v--;
//        gr[u].push_back({v, w});
//        gr[v].push_back({u, w});
//    }
//    dfs(0);
//    cout << max(dp[0][1], dp[0][0]) << '\n';
//    return 0;
//}
//

