
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
//x1, y1
//(b % a) * x1 + a * y1 = g
//x, y? - a * x + b * y = g;
//(b % a) = b - (b / a) * a
//(b - (b / a) * a) * x1 + a * y1 = g
//a * (y1 - (b / a) * x1) + b * x1 = g
//x = y1 - (b / a) * x1
//y = x1
//*/
//
///*
//a * x + b * y = c: c кратно g
//ax + by = g
//a(2x) + b(2y) = 2g
//a(c / g) * x + b(c / g) * y = g * (c / g) = c
//*/
//
///*
//a % b = (a % b + b) % b = (a % b < 0 ? a % b + b : a % b);
//*/
///*
//   a * x + b * y = c
//   x1 = x + b / g
//   y1 = y - a / g
//   a * x1 + b * y1 = a * (x + b / g) + b * (y - a / g) = c
//   ax + ab / g + by - ab / g = c
//   */
///*
//b >= a
//gcd(a, b) = gcd(a, b - a) = gcd(a, b - 2a) = ... = gcd(a, b % a) =
//gcd(b % a, a) = gcd(b % a, a - b % a) = gcd(b % a, a - 2(b % a))
//a > b
//gcd(a, b) = gcd(b % a, a) = gcd(b, a)
//
//
//МЕГАНОД
//МЕГАНОК?
//*/
//int difant(int a, int b, int &x, int &y) {
//    if (a == 0) {
//        x = 0;
//        y = 1;
//        return b;
//    }
//    int x1, y1;
//    int g = difant(b % a, a, x1, y1);
//    x = y1 - (b / a) * x1;
//    y = x1;
//    return g;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int a, b, c;
//    cin >> a >> b >> c;
//    int s1 = 1, s2 = 1;
//    if (a < 0) {
//        a = -a;
//        s1 = -1;
//    }
//    if (b < 0) {
//        b = -b;
//        s2 = -1;
//    }
//    int xC, yC;
//    int gC = difant(a, b, xC, yC);
//    if (c % gC !=0) {
//        cout << "Impossible" << '\n';
//        return 0;
//    }
//    xC *= (c/gC);
//    yC *= (c/gC);
//    a*=s1;
//    xC*=s1;
//    yC*=s2;
//    b *=s2;
//    cout  << xC << ' '<< yC << ' ' << gC << '\n';
//    return 0;
//}
