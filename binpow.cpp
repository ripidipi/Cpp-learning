//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//typedef long long ll;
//
//ll binPow(ll a, ll p, ll Mod) {
//    if (p == 0) {
//        return 1 % Mod;
//    }
//    if (p == 1) {
//        return a % Mod;
//    }
//    if (p % 2 == 0) {
//        ll tmp = binPow(a, p/2, Mod);
//        return (tmp * tmp) % Mod;
//    }
//    else {
//        ll tmp = binPow(a, p - 1, Mod);
//        return (tmp * a) % Mod;
//    }
//}
//
////ll inv (ll x, ll Mod) {
////    return binPow(x, Mod - 2, Mod);
////}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int x, p, m;
//    cin >> x >> p >> m;
//    cout << binPow(x, p, m) << '\n';
//    return 0;
//}
