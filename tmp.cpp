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
//#include <stack>
//typedef long double ld;
//typedef long long ll;
//#define all(a) a.begin(), a.end()
//#define null nullptr
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int SIZE = 1e5 + 5;
//const int MOD = 1e9;
//typedef long long ll;
//
//inline int butiful(string& num) {
//    int c = 0;
//    for (char i : num) {
//        if (i != '0') {
//            c++;
//        }
//    }
//    return c;
//}
//
//
//string operation(string& num, int b) {
//
//}
//
//int solve(string& num, int cur = 0) {
//    int b = butiful( num);
//    if (b == 0) {
//        return cur;
//    }
//    string tmp = operation(num, b);
//    return solve(tmp, ++cur);
//}
//
////bool test(int n) {
////    int len = rand();
////    string res;
////    for (int i = 0; i < len; ++i) {
////        res += (rand() % 2) + '0';
////    }
////    solve(res) ==
////}
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    int n;
//    cin >> n;
//    string num;
//    cin >> num;
//    for (int i = 0; i < n; ++i) {
//        num[i] = (num[i] == '1' ? '0' : '1');
//        cout << solve(num) << '\n';
//        num[i] = (num[i] == '1' ? '0' : '1');
//    }
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
//#include <stack>
//typedef long double ld;
//typedef long long ll;
//#define all(a) a.begin(), a.end()
//#define null nullptr
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int SIZE = 1e5 + 5;
//const int MOD = 1e9;
//typedef long long ll;
//
//inline ostream& operator << (ostream& out, vector<int>& a) {
//    for (int i: a) {
//        out << i << ' ';
//    }
//    return out;
//}
//
//vector<int> dp;
//
//void calc(int n, vector<int>& a) {
//    for (int i = 0; i < n; ++i) {
//        for (int j = i + 1; j < n; ++j) {
//            if (a[i] > a[j]) {
//                dp[i] ++;
//            }
//        }
//    }
//}
//
//inline void happy(int n, vector<int>& arr, int val) {
//    dp[n - 1] = 0;
//    for (int i = 0; i < n - 1; ++i) {
//        dp[i] = dp[i + 1];
//        if (arr[i] > val) {
//            dp[i] ++;
//        }
//    }
//    cout << accumulate(all(dp), 0) << '\n';
//}
//
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    int n;
//    cin >> n;
//    dp.resize(n);
//    vector<int> arr(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> arr[i];
//    }
//    calc(n, arr);
//    cout << accumulate(all(dp), 0) << '\n';
//    for (int i = 0; i < n - 1; ++i) {
//        vector<int> tmp;
//        tmp.insert(tmp.begin(), arr.begin() + 1, arr.end());
//        tmp.push_back(arr[0]);
//        happy(n, tmp, arr[0]);
//        arr = tmp;
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
//#include <stack>
//typedef long double ld;
//typedef long long ll;
//#define all(a) a.begin(), a.end()
//#define null nullptr
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int SIZE = 1e5 + 5;
//const int MOD = 1e9;
//typedef long long ll;
//
//inline ostream& operator << (ostream& out, vector<int>& a) {
//    for (int i: a) {
//        out << i << ' ';
//    }
//    return out;
//}
//
//
//bool can(string& originalString, string& mask) {
//    if (originalString.empty()) {
//        return true;
//    }
//    for (int i = 1; i <= originalString.length(); ++i) {
//        std::string prefix = originalString.substr(0, i);
//        if (prefix == mask.substr(0, prefix.length())) {
//            auto tmp = originalString.substr(i);
//            if (can(tmp, mask)) {
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    string s;
//    string conv;
//    cin >> s;
//    for (int i = 0; i < s.size(); ++i) {
//        conv.push_back(s[i] == 'A' ? '1' : '0');
//    }
//    int l = ((conv.size() / 2) + (conv.size() % 2)), r = conv.size();
//    while(l != r - 1) {
//        int mid = (l + r) / 2;
//        string mask; for (int i = 0; i < mid; ++i) {mask+='1';}
//        if (can(conv, mask)) {
//
//        }
//    }
//    cout << s << endl;
//    return 0;
//}
