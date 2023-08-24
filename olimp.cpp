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
//struct Point {
//    int x, y;
//    Point() {}
//    Point(int x, int y) :x(x), y(y) {};
//};
//
//inline Point operator - (const Point& a, const Point& b) {
//    return Point(a.x - b.x, a.y - b.y);
//}
//
//inline double len(const Point& a) {
//    return hypot(a.x, a.y);
//}
//
//inline int scal(const Point& a, const Point& b) { // abs(a) * abs(b) * cos
//    return (a.x * b.x + a.y * b.y);
//}
//
//inline int vect(const Point& a, const Point& b) { // abs(a) * abs(b) * sin
//    return (a.x * b.y - a.y * b.x);
//}
//
//istream& operator >> (istream& in, Point& p) {
//    in >> p.x >> p.y;
//    return in;
//}
//
//inline bool pointOnLine(const Point& p, const Point& a, const Point& b) {
//    return vect(p - a, b - a) == 0 && scal(p - a, b - a) >= 0;
//}
//
//inline bool pointOfSegment(const Point& p, const Point& a, const Point& b) {
//    return pointOnLine(p, a, b) && pointOnLine(p, b, a);
//}
//
//inline double distToRay(const Point& p, const Point& a, const Point& b) {
//    if (scal(p - a, b - a) >= 0) {
//        return abs(vect(b - a, p - a) / len(a - b));
//    } else {
//        return len(p - a);
//    }
//}
//
//inline double angle(const Point& a, const Point& b) {
//    return ::atan2(vect(a, b), scal(a, b));
//}
//
//inline double aangel(const Point& a, const Point& b) {
//    return abs(angle(a, b));
//}
//
//inline bool eq(double a, double b) {
//    return abs(a - b) < eps;
//}
//
//inline bool operator == (const Point& a, const Point& b) {
//    return a.x == b.x && a.y == b.y;
//}
//
//inline bool pointInAngle(const Point& p, const Point& a, const Point& o, const Point& b) {
//    return eq(aangel(a - o, p - o) + aangel(b - o, p - o), aangel(a - o, b - o)) || p == o;
//}
//
//int main () {
//    cin.tie(0);
//    ios_base::sync_with_stdio(0);
//    cout.precision(40);
//    Point a, b, c;
//    cin >> a >> b >> c;
//    cout << abs(vect(b - a, c - a) / 2.0) << '\n';
//    return 0;
//}

