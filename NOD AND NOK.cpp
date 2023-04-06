//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//int gcd (int a, int b) {
//    if (a == 0)
//        return b;
//    return gcd(b % a, a);
//}
//
//int lcd (int a, int b) {
//    return a  / gcd(a, b) * b;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, g, l, x, v;
//    cin >> n;
//    cin >> v;
////    l = v;
////    g = v;
////    for (int i = 1; i < n; ++i) {
////        cin >> x;
////        //g = gcd(g, x);
////        l = lcd(l, x);
////    }
//    l = lcd(n, v);
//    //cout << g << '\n';
//    cout << l << '\n';
//    return 0;
//}
