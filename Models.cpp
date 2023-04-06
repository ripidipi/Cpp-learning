/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct Event {
    int t;
    int type; //0 - клиент пришел, 1 - закончилась стрижка
    int num; //номер клиента
    int num_barber; //номер парикмахера
    Event() {}
    Event(int t, int type, int num, int num_barber)
            :t(t), type(type), num(num), num_barber(num_barber) {}
};

bool operator <(const Event& a, const Event& b) {
    return a.t <= b.t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    set<Event> ev;
    set<pair<int, int>> barbers;
    int m = 3;
    for (int i = 0; i < m; ++i) {
        barbers.insert(make_pair(30, i));
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int h, m;
        cin >> h >> m;
        int min = h * 60 + m;
        ev.insert(Event(min, 0, i, -1));
    }
    queue<int> q;
    vector<int> ans(n);
    while (!ev.empty()) {
        Event e = *ev.begin();
        ev.erase(ev.begin());
        if (e.type == 0) {
            if (!barbers.empty()) {
                pair<int, int> cur = *barbers.begin();
                barbers.erase(barbers.begin());
                ev.insert(Event(e.t + cur.first, 1, e.num, cur.second));
            } else {
                q.push(e.num);
            }
        } else {
            ans[e.num] = e.t;
            if (!q.empty()) {
                int cur = q.front();
                q.pop();
                ev.insert(Event(e.t + 30, 1, cur, e.num_barber));
            } else {
                barbers.insert({ 30, e.num_barber });
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] / 60 << ' ' << ans[i] % 60 << '\n';
    }
}
*/