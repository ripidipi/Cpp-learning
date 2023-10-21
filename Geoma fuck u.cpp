////#include <iostream>
////#include <vector>
////#include <chrono>
////#include <string>
////#include <algorithm>
////#include <numeric>
////#include <map>
////#include <set>
////#include <cmath>
////
////#define all(a) a.begin(), a.end()
////
////using namespace std;
////
////const double eps = 1e-8;
////const double INF = 1e9;
////
////struct Point {
////    double x, y;
////    Point(){}
////    Point(double x, double y) :x(x), y(y) {}
////};
////
////istream& operator >> (istream& in, Point& a) {
////    in >> a.x >> a.y;
////    return in;
////}
////
////inline Point operator * (const Point& a, double d) {
////    return Point(a.x * d, a.y * d);
////}
////
////inline Point operator - (const Point& a, const Point& b) {
////    return Point(a.x - b.x, a.y - b.y);
////}
////
////inline bool operator == (const Point& a, const Point& b) {
////    return (a.x == b.x && a.y == b.y);
////}
////
////inline double len(const Point& a) {
////    return hypot(a.x, a.y);
////}
////
////inline double scal(const Point& a, const Point& b) { // abs(a) * abs(b) * cos
////    return (a.x * b.x + a.y * b.y);
////}
////
////inline double vect(const Point& a, const Point& b) { // abs(a) * abs(b) * sin
////    return (a.x * b.y - a.y * b.x);
////}
////
////inline double angle(const Point& a, const Point& b) {
////    return ::atan2(vect(a, b), scal(a, b));
////}
////
////inline double aangle(const Point& a, const Point& b) {
////    return abs(angle(a, b));
////}
////
////inline bool eq(double a, double b) {
////    return abs(a - b) < eps;
////}
////
////struct Line {
////    int A, B, C;
////    Line(){}
////    Line(int a, int b, int c) : A(a), B(b), C(c) {}
////    Point getNorm() {
////        return Point(A, B);
////    }
////};
////
////Line getLineBy2Pts(const Point& a, const Point& b) {
////    // (x - a.x) / (b.x - a.x) = (y - a.y) / (b.y - a.y)
////    // (x - a.x) * (b.y - a.y) = (y - a.y) * (b.x - a.x)
////    // x * b.y - a.x * b.y - x * a.y + a.x * a.y = y * b.x - a.y * b.x - y * a.x + a.y * a.y
////    // x * (b.y - a.y) + y * (a.x - b.x) + a.y * b.x - a.x * b.y
////    return Line(b.y - a.y, a.x - b.x, a.y * b.x - a.x * b.y);
////}
////
////Line getLineByPtAndNorm(const Point& p, const Point& norm) {
////    //(norm.x, norm.y, -norm.x * p.x  - norm.y * p.y)
////    // norm.x * p.x + norm.y * p.y + c = 0
////    // c = -norm.x * p.x - norm.y * p.y
////    return Line(norm.x, norm.y, -norm.x * p.x - norm.y * p.y);
////}
////
////double distToLine(const Line& l, const Point& p) {
////    return abs(l.A * p.x + l.B * p.y + l.C) / ::hypot(l.A, l.B);
////}
////
////struct Circle{
////    Point p;
////    double r;
////    Circle(){}
////    Circle(const Point& p, double r) :p(p), r(r) {}
////};
////
////Point normToD(const Point& p, double d) {
////    Point res = p;
////    double l = len(p);
////    res.x /= l;
////    res.y /= l;
////    res.x *= d;
////    res.y *= d;
////}
////
////vector<Point> crossLineAndCircle(const Line& l, const Circle& c) {
////    double d = distToLine(l, c.p);
////    if (d > c.r + eps) {
////        return {};
////    }
////    Point h = normToD(l.getNorm(), d);
////}
////
////int main () {
////    ios_base::sync_with_stdio(false);
////    cin.tie(0);
////    cout.precision(40);
////    Point a, b, c(0, 0);
////    cin >> a >> b;
////
////    return 0;
////}
//
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
//
//using namespace std;
//
//struct Point {
//    double x, y;
//    Point() {}
//    Point(double x, double y) :x(x), y(y) {}
//};
//
//inline Point operator -(const Point& a, const Point& b) {
//    return Point(a.x - b.x, a.y - b.y);
//}
//
//inline Point operator +(const Point& a, const Point& b) {
//    return Point(a.x + b.x, a.y + b.y);
//}
//
//inline Point operator *(const Point& p, double d) {
//    return Point(p.x * d, p.y * d);
//}
//
//inline double len(const Point& a) {
//    return hypot(a.x, a.y);
//}
//
////dot product
//inline double dP(const Point& a, const Point& b) {
//    return a.x * b.x + a.y * b.y;
//}
//
////cross product
//inline double cP(const Point& a, const Point& b) {
//    return a.x * b.y - a.y * b.x;
//}
//
//istream& operator >>(istream& in, Point& p) {
//    in >> p.x >> p.y;
//    return in;
//}
//
//ostream& operator <<(ostream& out, const Point& p) {
//    out << p.x << ' ' << p.y;
//    return out;
//}
//
//inline double triangleSquare(const Point& a, const Point& b, const Point& c) {
//    return abs(cP(b - a, c - a)) / 2.0;
//}
//
//inline bool pointOnRay(const Point& p, const Point& a, const Point& b) {
//    return cP(p - a, b - a) == 0 && dP(p - a, b - a) >= 0;
//}
//
//inline bool pointOnSegment(const Point& p, const Point& a, const Point& b) {
//    return pointOnRay(p, a, b) && pointOnRay(p, b, a);
//}
//
//inline double distToRay(const Point& p, const Point& a, const Point& b) {
//    if (dP(p - a, b - a) >= 0) {
//        return abs(cP(b - a, p - a)) / len(a - b);
//    } else {
//        return len(p - a);
//    }
//}
//
//inline double angle(const Point& a, const Point& b) {
//    return atan2(cP(a, b), dP(a, b));
//}
//
//inline double aangle(const Point& a, const Point& b) {
//    return abs(angle(a, b));
//}
//
//inline bool eq(double a, double b) {
//    return abs(a - b) < eps;
//}
//
//inline bool operator ==(const Point& a, const Point& b) {
//    return a.x == b.x && a.y == b.y;
//}
//
//inline bool pointInAngle(const Point& p, const Point& a, const Point& o, const Point& b) {
//    return eq(aangle(a - o, p - o) + aangle(b - o, p - o), aangle(a - o, b - o)) || p == o;
//}
//
//struct Line {
//    double A, B, C;
//    Line() {}
//    Line(double A, double B, double C) :A(A), B(B), C(C) {}
//    Point getNorm() const {
//        return Point(A, B);
//    }
//};
//
//Line getLineBy2Pts(const Point& a, const Point& b) {
//    //(x - a.x) / (b.x - a.x) = (y - a.y) / (b.y - a.y)
//    //(x - a.x) * (b.y - a.y) = (y - a.y) * (b.x - a.x)
//    //x * b.y - a.x * b.y - x * a.y = y * b.x - a.y * b.x - y * a.x
//    //x * (b.y - a.y) + y * (a.x - b.x) + a.y * b.x - a.x * b.y = 0
//    return Line(b.y - a.y, a.x - b.x, a.y * b.x - a.x * b.y);
//}
//
//Line getLineByPtAndNorm(const Point& p, const Point& norm) {
//    //(norm.x, norm.y, -norm.x * p.x - norm.y * p.y)
//    //norm.x * p.x + norm.y * p.y + C = 0
//    //C = -norm.x * p.x - norm.y * p.y
//    return Line(norm.x, norm.y, -norm.x * p.x - norm.y * p.y);
//}
//
//double distToLine(const Line& l, const Point& p) {
//    return abs(l.A * p.x + l.B * p.y + l.C) / hypot(l.A, l.B);
//}
//
//struct Circle {
//    Point p;
//    double r;
//    Circle() {}
//    Circle(const Point& p, double r) :p(p), r(r) {}
//};
//
//Point normToD(const Point& p, double d) {
//    Point res = p;
//    double l = len(p);
//    res.x /= l;
//    res.y /= l;
//    res.x *= d;
//    res.y *= d;
//    return res;
//}
//
//vector<Point> crossLineAndCircle(const Line& l, const Circle& c) {
//    double d = distToLine(l, c.p);
//    if (d > c.r + eps) {
//        return {};
//    }
//    Point h = normToD(l.getNorm(), d);
//    if (!eq(distToLine(l, c.p + h), 0)) {
//        h = h * (-1);
//    }
//    Point osn = c.p + h;
//    if (eq(d, c.r)) {
//        return { osn };
//    }
//    double halfHord = sqrt(c.r * c.r - d * d);
//    Point coll(-l.B, l.A);
//    coll = normToD(coll, halfHord);
//    Point coll1 = coll * (-1);
//    return { osn + coll, osn + coll1 };
//}
//
//double polygonPerimeter(const vector<Point>& p) {
//    int n = p.size();
//    double ans = 0;
//    for(int i = 0; i < n; ++i) {
//        ans += len(p[(i + 1) % n] - p[i]);
//    }
//    return ans;
//}
//
//double polygoSquare(const vector<Point>& p) {
//    int n = p.size();
//    double ans = 0;
//    for(int i = 0; i < n; ++i) {
//        ans+=cP(p[(i+1) % n], p[i]);
//    }
//    return abs(ans) / 2.0;
//}
//
//
//bool pointInPolygon(const vector<Point>& p, const Point& pt) {
//    int n = p.size();
//    double ans = 0;
//    for (int i = 0; i < n; ++i) {
//        if(pointOnSegment(pt, p[i], p[(i + 1) % n])) {
//            return true;
//        }
//    }
//    for(int i = 0; i < n; ++i) {
//        ans += angle(p[i] - pt, p[(i + 1) % n] - pt);
//    }
//    if(eq(ans, 0)) {
//        return false;
//    } else {
//        return true;
//    }
//}
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    int n;
//    Point pt;
//    cin >> n >> pt;
//    vector<Point> p(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> p[i];
//    }
//    cout << (pointInPolygon(p, pt) ? "YES" : "NO") << '\n';
//    return 0;
//}
//
//bool pointInConvexPolygon(const vector<Point>& p, const Point& pt) {
//    int n = p.size();
//    if (!pointInAngle(pt, p[1], p[0] p[n - 1])) {
//        return false;
//    }
//    int l = 1, r = n - 1;
//    while (l != r - 1) {
//        int m = (l + r) / 2;
//        if(cP(p[m] - p[0], pt - p[0]) >= 0) {
//            l = m;
//        } else {
//            r = m;
//        }
//    }
//    return pointInAngle(pt, p[0], p[l], p[l + 1]);
//
//
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.precision(30);
//    int n;
//    Point a;
//    cin >> n >> a;
//    vector<Point> p(n);
//    for (int i =0 ; i < n; ++i) {
//        cin >> p[i];
//    }
////    int pos = 0, neg = 0;
////    for (int i = 0; i < n; ++i) {
////        Point  cur = p[i];
////        Point nxt = p[(i + 1) % n];
////        Point prv = p[(i - 1 + n) % n];
////        if(cP(nxt - cur, cur - prv) > 0) {
////             pos++;
////        } else if(cP(nxt - cur, cur - prv) < 0){
////            neg++;
////        }
////    }
////    if(pos == 0 || neg == 0) {
////        cout << "YES\n";
////    } else {
////        cout << "NO\n";
////    }
//    cout << (pointInPolygon(p, a) ? "Yes\n" : "NO\n");
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
//struct Point {
//    double x, y;
//    Point(){}
//    Point(double x, double y) :x(x), y(y) {}
//};
//
//istream& operator >> (istream& in, Point& a) {
//    in >> a.x >> a.y;
//    return in;
//}
//
//inline Point operator * (const Point& a, double d) {
//    return Point(a.x * d, a.y * d);
//}
//
//inline Point operator - (const Point& a, const Point& b) {
//    return Point(a.x - b.x, a.y - b.y);
//}
//
//inline bool operator == (const Point& a, const Point& b) {
//    return (a.x == b.x && a.y == b.y);
//}
//
//inline double len(const Point& a) {
//    return hypot(a.x, a.y);
//}
//
//inline double scal(const Point& a, const Point& b) { // abs(a) * abs(b) * cos
//    return (a.x * b.x + a.y * b.y);
//}
//
//inline double vect(const Point& a, const Point& b) { // abs(a) * abs(b) * sin
//    return (a.x * b.y - a.y * b.x);
//}
//
//inline double angle(const Point& a, const Point& b) {
//    return ::atan2(vect(a, b), scal(a, b));
//}
//
//inline double aangle(const Point& a, const Point& b) {
//    return abs(angle(a, b));
//}
//
//inline bool eq(double a, double b) {
//    return abs(a - b) < eps;
//}
//
//struct Line {
//    int A, B, C;
//    Line(){}
//    Line(int a, int b, int c) : A(a), B(b), C(c) {}
//    Point getNorm() {
//        return Point(A, B);
//    }
//};
//
//Line getLineBy2Pts(const Point& a, const Point& b) {
//    // (x - a.x) / (b.x - a.x) = (y - a.y) / (b.y - a.y)
//    // (x - a.x) * (b.y - a.y) = (y - a.y) * (b.x - a.x)
//    // x * b.y - a.x * b.y - x * a.y + a.x * a.y = y * b.x - a.y * b.x - y * a.x + a.y * a.y
//    // x * (b.y - a.y) + y * (a.x - b.x) + a.y * b.x - a.x * b.y
//    return Line(b.y - a.y, a.x - b.x, a.y * b.x - a.x * b.y);
//}
//
//Line getLineByPtAndNorm(const Point& p, const Point& norm) {
//    //(norm.x, norm.y, -norm.x * p.x  - norm.y * p.y)
//    // norm.x * p.x + norm.y * p.y + c = 0
//    // c = -norm.x * p.x - norm.y * p.y
//    return Line(norm.x, norm.y, -norm.x * p.x - norm.y * p.y);
//}
//
//double distToLine(const Line& l, const Point& p) {
//    return abs(l.A * p.x + l.B * p.y + l.C) / ::hypot(l.A, l.B);
//}
//
//struct Circle{
//    Point p;
//    double r;
//    Circle(){}
//    Circle(const Point& p, double r) :p(p), r(r) {}
//};
//
//Point normToD(const Point& p, double d) {
//    Point res = p;
//    double l = len(p);
//    res.x /= l;
//    res.y /= l;
//    res.x *= d;
//    res.y *= d;
//}
//
//vector<Point> crossLineAndCircle(const Line& l, const Circle& c) {
//    double d = distToLine(l, c.p);
//    if (d > c.r + eps) {
//        return {};
//    }
//    Point h = normToD(l.getNorm(), d);
//}
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.precision(40);
//    Point a, b, c(0, 0);
//    cin >> a >> b;
//
//    return 0;
//}






//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//struct Point {
//    double x, y;
//    Point() {}
//    Point(double x, double y) :x(x), y(y) {}
//};
//
//inline Point operator -(const Point& a, const Point& b) {
//    return Point(a.x - b.x, a.y - b.y);
//}
//
//inline Point operator +(const Point& a, const Point& b) {
//    return Point(a.x + b.x, a.y + b.y);
//}
//
//inline Point operator *(const Point& p, double d) {
//    return Point(p.x * d, p.y * d);
//}
//
//inline double len(const Point& a) {
//    return hypot(a.x, a.y);
//}
//
////dot product
//inline double dP(const Point& a, const Point& b) {
//    return a.x * b.x + a.y * b.y;
//}
//
////cross product
//inline double cP(const Point& a, const Point& b) {
//    return a.x * b.y - a.y * b.x;
//}
//
//istream& operator >>(istream& in, Point& p) {
//    in >> p.x >> p.y;
//    return in;
//}
//
//ostream& operator <<(ostream& out, const Point& p) {
//    out << p.x << ' ' << p.y;
//    return out;
//}
//
//inline double triangleSquare(const Point& a, const Point& b, const Point& c) {
//    return abs(cP(b - a, c - a)) / 2.0;
//}
//
//inline bool pointOnRay(const Point& p, const Point& a, const Point& b) {
//    return cP(p - a, b - a) == 0 && dP(p - a, b - a) >= 0;
//}
//
//inline bool pointOnSegment(const Point& p, const Point& a, const Point& b) {
//    return pointOnRay(p, a, b) && pointOnRay(p, b, a);
//}
//
//inline double distToRay(const Point& p, const Point& a, const Point& b) {
//    if (dP(p - a, b - a) >= 0) {
//        return abs(cP(b - a, p - a)) / len(a - b);
//    } else {
//        return len(p - a);
//    }
//}
//
//inline double angle(const Point& a, const Point& b) {
//    return atan2(cP(a, b), dP(a, b));
//}
//
//inline double aangle(const Point& a, const Point& b) {
//    return abs(angle(a, b));
//}
//
//const double eps = 1e-8;
//
//inline bool eq(double a, double b) {
//    return abs(a - b) < eps;
//}
//
//inline bool operator ==(const Point& a, const Point& b) {
//    return a.x == b.x && a.y == b.y;
//}
//
//inline bool pointInAngle(const Point& p, const Point& a, const Point& o, const Point& b) {
//    return eq(aangle(a - o, p - o) + aangle(b - o, p - o), aangle(a - o, b - o)) || p == o;
//}
//
//struct Line {
//    double A, B, C;
//    Line() {}
//    Line(double A, double B, double C) :A(A), B(B), C(C) {}
//    Point getNorm() const {
//        return Point(A, B);
//    }
//};
//
//Line getLineBy2Pts(const Point& a, const Point& b) {
//    //(x - a.x) / (b.x - a.x) = (y - a.y) / (b.y - a.y)
//    //(x - a.x) * (b.y - a.y) = (y - a.y) * (b.x - a.x)
//    //x * b.y - a.x * b.y - x * a.y = y * b.x - a.y * b.x - y * a.x
//    //x * (b.y - a.y) + y * (a.x - b.x) + a.y * b.x - a.x * b.y = 0
//    return Line(b.y - a.y, a.x - b.x, a.y * b.x - a.x * b.y);
//}
//
//Line getLineByPtAndNorm(const Point& p, const Point& norm) {
//    //(norm.x, norm.y, -norm.x * p.x - norm.y * p.y)
//    //norm.x * p.x + norm.y * p.y + C = 0
//    //C = -norm.x * p.x - norm.y * p.y
//    return Line(norm.x, norm.y, -norm.x * p.x - norm.y * p.y);
//}
//
//double distToLine(const Line& l, const Point& p) {
//    return abs(l.A * p.x + l.B * p.y + l.C) / hypot(l.A, l.B);
//}
//
//struct Circle {
//    Point p;
//    double r;
//    Circle() {}
//    Circle(const Point& p, double r) :p(p), r(r) {}
//};
//
//Point normToD(const Point& p, double d) {
//    Point res = p;
//    double l = len(p);
//    res.x /= l;
//    res.y /= l;
//    res.x *= d;
//    res.y *= d;
//    return res;
//}
//
//vector<Point> crossLineAndCircle(const Line& l, const Circle& c) {
//    double d = distToLine(l, c.p);
//    if (d > c.r + eps) {
//        return {};
//    }
//    Point h = normToD(l.getNorm(), d);
//    if (!eq(distToLine(l, c.p + h), 0)) {
//        h = h * (-1);
//    }
//    Point osn = c.p + h;
//    if (eq(d, c.r)) {
//        return { osn };
//    }
//    double halfHord = sqrt(c.r * c.r - d * d);
//    Point coll(-l.B, l.A);
//    coll = normToD(coll, halfHord);
//    Point coll1 = coll * (-1);
//    return { osn + coll, osn + coll1 };
//}
//
//double polygonPerimeter(const vector<Point>& p) {
//    int n = p.size();
//    double ans = 0;
//    for(int i = 0; i < n; ++i) {
//        ans += len(p[(i + 1) % n] - p[i]);
//    }
//    return ans;
//}
//
//double polygonSquare(const vector<Point>& p) {
//    int n = p.size();
//    double ans = 0;
//    for(int i = 0; i < n; ++i) {
//        ans+=cP(p[(i+1) % n], p[i]);
//    }
//    return abs(ans) / 2.0;
//}
//
//
//bool pointInPolygon(const vector<Point>& p, const Point& pt) {
//    int n = p.size();
//    double ans = 0;
//    for (int i = 0; i < n; ++i) {
//        if(pointOnSegment(pt, p[i], p[(i + 1) % n])) {
//            return true;
//        }
//    }
//    for(int i = 0; i < n; ++i) {
//        ans += angle(p[i] - pt, p[(i + 1) % n] - pt);
//    }
//    if(eq(ans, 0)) {
//        return false;
//    } else {
//        return true;
//    }
//}
//
//bool pointInConvexPolygon(const vector<Point>& p, const Point& pt) {
//    int n = p.size();
//    if (!pointInAngle(pt, p[1], p[0], p[n - 1])) {
//        return false;
//    }
//    int l = 1, r = n - 1;
//    while (l != r - 1) {
//        int m = (l + r) / 2;
//        if(cP(p[m] - p[0], pt - p[0]) >= 0) {
//            l = m;
//        } else {
//            r = m;
//        }
//    }
//    return pointInAngle(pt, p[0], p[l], p[l + 1]);
//
//
//}
//
//vector<Point> convexHullJarvis(vector<Point>& p) {
//    int n = p.size();
//    int start = 0;
//    for (int i = 1; i < n; ++i) {
//        if (p[i].x < p[start].x || (p[i].x == p[start].x && p[i].y < p[start].y)) {
//            start = i;
//        }
//    }
//    swap(p[start], p[0]);
//    vector<Point> hull;
//    hull.push_back(p[0]);
//    while(true) {
//        int pt = 0;
//        if (hull.back() == p[pt]) {
//            pt++;
//        }
//        for (int i = 0; i < n; ++i) {
//            if (!(p[i] == hull.back()) && (cP(p[i] - hull.back(), p[pt] - hull.back())) < 0 ||
//                (cP(p[i] - hull.back(), p[pt] - hull.back())) == 0 && len(p[i] - hull.back()) > len(p[pt] - hull.back())) {
//                pt = i;
//            }
//        }
//        if (p[pt] == hull[0]) {
//            break;
//        }
//        hull.push_back(p[pt]);
//    }
//    return hull;
//}
//
//Point startForGraham;
//
//inline bool cmp(const Point& a, const Point& b) {
//    double cp = cP(a - startForGraham, b - startForGraham);
//    return cp > 0 || (cp == 0 && len(a - startForGraham) < len(b - startForGraham));
//}
//
//vector<Point> convexHullGraham(vector<Point>& p) {
//    int n = p.size();
//    int start = 0;
//    for (int i = 1; i < n; ++i) {
//        if (p[i].x < p[start].x || (p[i].x == p[start].x && p[i].y < p[start].y)) {
//            start = i;
//        }
//    }
//    swap(p[start], p[0]);
//    startForGraham = p[0];
//    sort(p.begin() + 1, p.end(), cmp);
//    vector<Point> hull;
//    hull.push_back(p[0]);
//    hull.push_back(p[1]);
//    int sz = 2;
//    for(int i = 2; i < n; ++i) {
//        while (hull.size() > 1 && cP(p[i] - hull[sz - 1], hull[sz - 1] - hull[sz - 2]) >= 0) {
//            hull.pop_back();
//            sz--;
//        }
//        hull.push_back(p[i]);
//        sz++;
//    }
//    return hull;
//}
//
//bool isHull(vector<Point>& p) {
//    int n = p.size();
//    int pos = 0, neg = 0;
//    for (int i = 0; i < n; ++i) {
//        if (cP(p[(i - 1 + n) % n] - p[i], p[(i + 1) % n] - p[i]) < 0) {
//            neg++;
//        } else if (cP(p[(i - 1 + n) % n] - p[i], p[(i + 1) % n] - p[i]) > 0){
//            pos++;
//        }
//    }
//    if(pos == 0 || neg == 0) {
//        return true;
//    } else {
//        return false;
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.precision(30);
//    int n;
//    cin >> n;
//    vector<Point> p(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> p[i];
//    }
//    int k;
//    cin >> k;
//    for (int i = 0; i < k; ++i) {
//        Point a;
//        cin >> a;
//        if(pointInConvexPolygon(p, a)) {
//            bool f = true;
//            for (int j = 0; j < n; ++j) {
//                if(pointOnRay(a, p[j], p[(j + 1) % n])) {
//                    cout << "BORDER\n";
//                    f = false;
//                    break;
//                }
//            }
//            if(f)
//                cout << "INSIDE\n";
//        } else {
//            cout << "OUTSIDE\n";
//        }
//    }
//
//    return 0;
//}

