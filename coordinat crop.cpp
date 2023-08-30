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
//    int l;
//    cin >> l;
//    vector<int> a(l);
//    for (int i = 0; i < l; ++i) {
//        cin >> a[i];
//    }
//    vector<int> b = a;
//    sort(all(b));
//    b.resize(unique(all(b)) - b.begin());
//    for (int i = 0; i < l; ++i) {
//        a[i] = lower_bound(all(b), a[i]) - b.begin();
//    }
//}