//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <string>
//#include <algorithm>
//#include <numeric>
//#include <map>
//#include <set>
//#include <cmath>
//#include <random>
//#include <unordered_map>
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int MAXSIZE = 1e5 + 5;
//typedef long double ld;
//typedef long long ll;
//
//void gen(int left, vector<int>& cur, set<int>& used) {
//    if (left == 0) {
//        for (int i: cur) {
//            cout << i << ' ';
//        }
//        cout << '\n';
//        return;
//    }
//    set<int> cp = used;
//    for (auto i: cp) {
//        cur.push_back(i);
//        used.erase(i);
//        gen(left - 1, cur, used);
//        used.insert(i);
//        cur.pop_back();
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n = 5;
//    vector<int> cur;
//    set<int>  b;
//    for (int i = 0; i < n; ++i)
//        b.insert(i);
//    gen(n, cur, b);
//    return 0;
//}
//
//
//
//
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
//#include <random>
//#include <unordered_map>
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int MAXSIZE = 1e5 + 5;
//typedef long double ld;
//typedef long long ll;
//
//void gen(int left, vector<char>& cur, int bal) {
//    if (left == 0) {
//        for (auto& i: cur) {
//            cout << i;
//        }
//        cout << '\n';
//        return;
//    }
//
//    if(left - 1 >= bal + 1) {
//        cur.push_back('(');
//        gen(left - 1, cur, bal + 1);
//        cur.pop_back();
//    }
//    if (bal > 0) {
//        cur.push_back(')');
//        gen(left - 1, cur, bal - 1);
//        cur.pop_back();
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n = 20;
//    vector<char> cur;
//    set<int>  b;
//    for (int i = 0; i < n; ++i)
//        b.insert(i);
//    gen(n, cur, 0);
//    return 0;
//}








//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <string>
//#include <algorithm>
//#include <numeric>
//#include <map>
//#include <set>
//#include <cmath>
//#include <random>
//#include <unordered_map>
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int MAXSIZE = 1e5 + 5;
//typedef long double ld;
//typedef long long ll;
//
//void gen(int left, vector<int>& cur, int last) {
//    if (left == 0) {
//        for (auto& i: cur) {
//            cout << i << ' ';
//        }
//        cout << '\n';
//        return;
//    }
//    for (int i = last; i <= left; ++i) {
//        cur.push_back(i);
//        gen(left - i, cur, i);
//        cur.pop_back();
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n = 6;
//    vector<int> cur;
//    gen(n, cur, 1);
//    return 0;
//}
//
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
//#include <random>
//#include <unordered_map>
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int MAXSIZE = 1e5 + 5;
//typedef long double ld;
//typedef long long ll;
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n, k;
//    cin >> n >> k;
//    vector<bool> used(n);
//    vector<int> ans(n);
//    vector<int> facts(n);
//    facts[0] = 1;
//    for (int i  = 1; i < n; ++i) {
//        facts[i] = facts[i - 1] * i;
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if(used[j]) {
//                continue;
//            }
//            if(k < facts[n - i - 1]) {
//                ans[i] = j;
//                used[j] = true;
//                break;
//            } else {
//                k -= facts[n - i - 1];
//            }
//        }
//    }
//    for (int i : ans) {
//        cout << i << ' ';
//    }
//    return 0;
//}
//
//
//
//
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
//#include <random>
//#include <unordered_map>
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int MAXSIZE = 1e5 + 5;
//typedef long double ld;
//typedef long long ll;
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n, k;
//    cin >> n >> k;
//    vector<vector<int>> dp(n, vector<int>(2));
//    vector<bool> used(n);
//    vector<int> ans(n);
//    dp[0][0] = dp[0][1] = 1;
//    for (int i = 1; i < n; ++i) {
//        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
//        dp[i][1] = dp[i - 1][0];
//    }
//    for (int i = 0; i < n; ++i) {
//        if (k < dp[n - i - 1][0]) {
//            ans[i] = 0;
//        } else {
//            k -= dp[n - i - 1][0];
//            ans[i] = 1;
//        }
//    }
//
//    for (auto& i : ans) {
//        cout << i << ' ';
//    }
//    return 0;
//}





//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <string>
//#include <algorithm>
//#include <numeric>
//#include <map>
//#include <set>
//#include <cmath>
//#include <random>
//#include <unordered_map>
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int MAXSIZE = 1e5 + 5;
//typedef long double ld;
//typedef long long ll;
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n, k;
//    cin >> n >> k;
//    vector<vector<int>> dp(n + 1, vector<int>(n / 2 + 2));
//    dp[0][0] = 1;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j <= n / 2 + 1; ++j) {
//            if (j > 0) {
//                dp[i][j] += dp[i - 1][j - 1];
//            }
//            if (j < n / 2 + 1) {
//                dp[i][j] += dp[i - 1][j + 1];
//            }
//        }
//    }
//    vector<char> ans(n);
//    int bal = 0;
//    for (int i = 0; i < n; ++i) {
//        if (k < dp[n - i - 1][bal + 1]) {
//            ans[i] = '(';
//            bal++;
//        } else {
//            ans[i] = ')';
//            k -= dp[n - i - 1][bal + 1];
//            bal--;
//        }
//    }
//    for (char c : ans) {
//        cout << c;
//    }
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
//#include <random>
//#include <unordered_map>
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int MAXSIZE = 1e5 + 5;
//typedef long double ld;
//typedef long long ll;
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    for (int i = n - 2; i > -1; --i) {
//        if(a[i] < a[i + 1]) {
//            for (int j = n - 1; j > -1; --j) {
//                if(a[j] > a[i]) {
//                    swap(a[i], a[j]);
//                    break;
//                }
//            }
//            reverse(a.begin() + i + 1, a.end());
//            break;
//        }
//    }
//    for (int i = 0; i < n; ++i) {
//        cout << a[i] << ' ';
//    }
//}
//





