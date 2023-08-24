//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//
//using namespace std;
//
//typedef long double ld;
//
//struct Point{
//    int ind;
//    int x, y;
//    Point(){};
//    Point(int x, int y) : x(x), y(y) {};
//
////    double take_mod() {
////        return ::sqrt(x*x + y*y);
////    }
//};
//
//double scal(Point& b, Point& a) {
//    return a.x*b.x + a.y*b.y;
//}
//
//double vec(Point& a, Point& b) {
//    return a.x*b.y - a.y*b.x;
//}
//
//double length (Point& a, Point& b) {
//    return ::sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
//}
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    int n, x_a, y_a;
//    cin >> n >> x_a >> y_a;
//    Point A(x_a, y_a);
//    vector<Point> points(n);
//    for (int i = 0; i < n; ++i) {
//        int x, y;
//        cin >> x >> y;
//        points[i] = Point(x, y);
//    }
//    double cur_deg = 0;
//    auto cur_dot = points[0];
//    for (int i = 1; i < n; i++) {
//        cur_deg += ::atan2(scal(cur_dot, points[i]), vec(cur_dot, points[i]));
//        cur_dot = points[i];
//    }
//    cout << cur_deg;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//long long INF = 1e10 + 10;
//
//int main() {
//    long n;
//    cin >> n;
//    long long x1Res = -INF, y1Res = -INF, x2Res = INF, y2Res = INF;
//    long long x1, y1, x2, y2;
//    for (long long i = 0; i < n; i++) {
//        cin >> x1 >> y1 >> x2 >> y2;
//        if ((x1 <= x2) && (y1 <= y2)) {
//            x1Res = max(x1Res, x1);
//            y1Res = max(y1Res, y1);
//            x2Res = min(x2Res, x2);
//            y2Res = min(y2Res, y2);
//        }
//    }
//    cout << x1Res << " " << y1Res << " " << x2Res << " " << y2Res;
//}