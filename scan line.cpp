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
