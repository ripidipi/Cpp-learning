//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <string>
//#include <fstream>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n;
//    ll c, k;
//    cin >> n >> c >> k;
//    ll Mod = pow((ll)10, k);
//    string s;
//    cin >> s;
//    vector<ll> dp(n);
//    for (int i = 0; i < n; ++i) {
//        if (i < 10) {
//            string cur = s.substr(0, i + 1);
//            if (stoll(cur) <= c && (i == 0 || cur[0] != '0')) {
//                dp[i]++;
//            }
//        }
//        for (int j = i; j >=max(1, i - 10); --j) {
//            string cur = s.substr(j, i - j + 1);
//            if (stoll(cur) <= c && (i == j || cur[0] != '0')) {
//                dp[i] += dp[j - 1];
//                dp[i] %= Mod;
//            }
//        }
//    }
//    cout << dp[n - 1] << '\n';
//    return 0;
//}


//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <string>
//#include <fstream>
//#include <numeric>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    vector<vector<int>> dp(n, vector<int>(10));
//    dp[0] = vector<int>(10, 1);
//    dp[0][0] = 0;
//    for (int i = 1; i < n; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            if (j > 0) {
//                dp[i][j] += dp[i - 1][j - 1];
//            }
//            dp[i][j] += dp[i - 1][j];
//            if (j<9) {
//                dp[i][j] += dp[i -1][j + 1];
//            }
//        }
//    }
//    cout << accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0) << '\n';
//    return 0;
//}


//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <string>
//#include <fstream>
//#include <numeric>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, k;
//    cin >> n >> k;
//    vector<vector<int>> dp(n, vector<int>(k));
//    dp[0] = vector<int>(k, 1);
//    for (int i = 1; i < n; ++i) {
//        if (i % 2 == 0) {
//            dp[i][0] = 0;
//            for (int j = 1; j < k; ++j) {
//                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
//            }
//        } else {
//            dp[i][k - 1] = 0;
//            for (int j = k - 2; j > -1; --j) {
//                dp[i][j] = dp[i][j + 1] + dp[i - 1][j  + 1];
//            }
//        }
//    }
//    for (auto &i: dp) {
//        for (auto &j: i) {
//            cout << j << '\t';
//        }
//        cout << '\n';
//    }
//    cout << accumulate(dp[n-1].begin(), dp[n-1].end(), 0) << '\n';
//    return 0;
//}


//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <string>
//#include <fstream>
//#include <numeric>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    vector<vector<int>> dp(n, vector<int>(10));
//    dp[0] = vector<int>(10, 1);
//    dp[0][0] = 0;
//    for (int i = 1; i < n; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            if (j > 0) {
//                dp[i][j] += dp[i - 1][j - 1];
//            }
//            dp[i][j] += dp[i - 1][j];
//            if (j<9) {
//                dp[i][j] += dp[i -1][j + 1];
//            }
//        }
//    }
//    cout << accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0) << '\n';
//    return 0;
//}


//struct Gangster{
//    int t, w;
//    ll c;
//    Gangster() {};
//    Gangster(int t, int w, ll c): t(t), w(w), c(c) {};
//
//};
//
//bool operator <(const Gangster& a, const Gangster& b) {
//    return a.t < b.t;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, k, t;
//    cin >> n >> k >> t;
//    vector<Gangster> g(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> g[i].t;
//    }
//    for (int i = 0; i < n; ++i) {
//        cin >> g[i].c;
//    }
//    for (int i = 0; i < n; ++i) {
//        cin >> g[i].w;
//    }
//    sort(g.begin(), g.end());
//    vector<ll> dp(n);
//    vector<bool> can(n, false);
//    for (int i = 0; i < n; ++i) {
//        if (g[i].w <= g[i].t) {
//            dp[i] = g[i].c;
//            can[i] = true;
//        }
//        for (int j = 0; j < i; ++j) {
//            if (can[j] &&  g[i].t - g[j].t >= abs(g[i].w - g[j].w)) {
//                dp[i] = max(dp[i], dp[j] + g[i].c);
//            }
//        }
//    }
//    cout << *max_element(dp.begin(), dp.end()) << '\n';
//
//    return 0;
//
//}




//ll psp(int n, int k) {
//    vector<vector<ll>> dp(n + 1, vector<ll>(k+1));
//    dp[0][0] = 1;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j <= k; ++j) {
//            if (j > 0) {
//                dp[i][j] += dp[i-1][j-1];
//            }
//            if (j < k) {
//                dp[i][j] +=dp[i - 1][j + 1];
//            }
//            dp[i][j] %= Mod;
//        }
//    }
//    return dp[n][0];
//}
//



//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, k;
//    cin >> n >> k;
//    if (n > 0 && k == 2) {
//        cout << 2;
//        return 0;
//    } else if (n < k) {
//        cout << pow(2, n);
//        return 0;
//    }
//    vector<pair<int, int>> dp(n+1, make_pair(0, 0));
//    dp[0].first = 0;
//    dp[0].second = 0;
//    for (int i = 1; i <= k; ++i) {
//        dp[i].first = pow(2, (i - 1));
//        dp[i].second = pow(2, (i - 1));
//        for (int i = k; i <= n; ++i) {
//            int curf=0, curs=0;
//            for (int j = 1; j < k; ++j) {
//                curf += dp[i - j].second;
//                curs += dp[i - j].first;
//            }
//            dp[i].first = curf;
//            dp[i].second = curs;
//        }
//    }
//    cout << dp[n].first + dp[n].second;
//    return 0;
//}
