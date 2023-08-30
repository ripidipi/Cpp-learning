//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//typedef long long ll;
//
//struct Event {
//    int x, type; // type 0 - open , 1 - close
//    int num;
//    Event() {};
//    Event(int x, int type, int num) :x(x), type(type), num(num) {}
//};
//
//inline bool operator <(const Event& a, const Event& b) {
//    return make_pair(a.x, a.type) < make_pair(b.x, b.type);
//}
//
//
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    vector<Event> ev;
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        int l, r;
//        cin >> l >> r;
//        ev.push_back(Event(l, 0, i));
//        ev.push_back(Event(r, 1, i));
//    }
//    sort(ev.begin(), ev.end());
//    int opened = -1;
//    int ans1 = -1, ans2 = -1;
//    for (auto& e : ev) {
//        if (e.type == 0) {
//            if (opened == -1) {
//                opened = e.num;
//            } else {
//                ans1 = e.num + 1;
//                ans2 = opened + 1;
//                break;
//            }
//        } else {
//            opened = -1;
//        }
//    }
//    cout << ans1 << ' ' << ans2 << '\n';
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//typedef long long ll;
//
//struct Event {
//    int x, type; // type 0 - open , 1 - close
//    int num;
//    Event() {};
//    Event(int x, int type, int num) :x(x), type(type), num(num) {}
//};
//
//inline bool operator <(const Event& a, const Event& b) {
//    return make_pair(a.x, a.type) < make_pair(b.x, b.type);
//}
//
//
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    vector<Event> ev;
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        int l, r;
//        cin >> l >> r;
//        ev.push_back(Event(l, 0, i));
//        ev.push_back(Event(r, 1, i));
//    }
//    sort(ev.begin(), ev.end());
//    int bal = 0, start = -1, ans = 0;
//    for (auto& e : ev) {
//        if (e.type == 0) {
//            bal++;
//            if (bal == 1) {
//                start = e.x;
//            }
//        } else {
//            bal--;
//            if (bal == 0) {
//                ans += (e.x - start);
//            }
//        }
//    }
//    cout << ans << '\n';
//    return 0;
//}



//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//typedef long long ll;
//
//struct Event {
//    int x, type; // type 0 - open , 1 - point,  2 - close
//    int num;
//    Event() {};
//    Event(int x, int type, int num) :x(x), type(type), num(num) {}
//};
//
//inline bool operator <(const Event& a, const Event& b) {
//    return make_pair(a.x, a.type) < make_pair(b.x, b.type);
//}
//
//
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    vector<Event> ev;
//    int n, m;
//    cin >> n >> m;
//    for (int i = 0; i < n; ++i) {
//        int l, r;
//        cin >> l >> r;
//        ev.push_back(Event(l, 0, i));
//        ev.push_back(Event(r, 1, i));
//    }
//    for (int i = 0; i < m; ++i) {
//        int x;
//        cin >> x;
//        ev.push_back(Event(x, 1, i));
//    }
//    vector<int> ans(n);
//    sort(ev.begin(), ev.end());
//    int cnt = 0;
//    vector<int> pref(n);
//    for (auto& e : ev) {
//        if (e.type == 0) {
//            pref[e.num] = cnt;
//        } if (e.type == 1) {
//            cnt ++;
//        } else {
//            ans[e.num] = cnt - pref[e.num];
//        }
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
//struct Event {
//    int x, type;
//    int num;
//    int y1, y2;
//    Event(){};
//    Event(int x, int type, int num, int y1, int y2) :x(x), type(type), num(num), y1(y1), y2(y2) {}
//};
//
//bool operator <(const Event& a, const Event& b) {
//    return make_pair(a.x, a.type) < make_pair(b.x, b.type);
//}
//
//int t[4 * MAXSIZE];
//
//int ask(int v, int l, int r, int askl, int askr) {
//    if (l >= askr || r <= askl) {
//        return 0;
//    }
//    if (l >= askl && r <= askr) {
//        return t[v];
//    }
//    int m = (l + r) / 2;
//    auto val1 = ask(2 * v + 1, l, m, askl, askr);
//    auto val2 = ask(2 * v + 2, m, r, askl, askr);
//    return val1 + val2;
//}
//
//void add(int v, int l, int r, int pos) {
//    if (l == r - 1) {
//        t[l]++;
//        return;
//    }
//    int m = (l + r) / 2;
//    if (m > pos) {
//        add(2 * v + 1, l, m, pos);
//    } else {
//        add(2 * v + 2, m, r, pos);
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    vector<Event> ev;
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        int x1, x2, y1, y2;
//        cin >> x1 >> x2 >> y1 >> y2;
//        ev.push_back(Event(x1, 0, i, y1, y2));
//        ev.push_back(Event(x2, 2, i, y1, y2));
//    }
//    int m;
//    cin >> m;
//    for (int i = 0; i < n; ++i) {
//        int x, y;
//        cin >> x >> y;
//        ev.push_back(Event(x, 1, -1, y, -1 ));
//    }
//    sort(all(ev));
//    int cnt = 0;
//    vector<int> pref(n), ans(n);
//    for (auto& e: ev) {
//        if(e.type == 0) {
//            pref[e.num] = ask(0, 0, MAXSIZE, e.y1, e.y2 + 1);
//        } else if(e.type == 1) {
//            add(0, 0, MAXSIZE, e.y1);
//        } else {
//            ans[e.num] = ask(0, 0, MAXSIZE, e.y1, e.y2 + 1) - pref[e.num];
//        }
//    }
//    return 0;
//}





