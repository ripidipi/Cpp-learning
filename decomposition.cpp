//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <numeric>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//ll INF = 1e9 + 9;
//
//struct Block {
//    vector<int> arr;
//    int maxx, len;
//    void build() {
//        len = arr.size();
//        maxx = *max_element(arr.begin(), arr.end());
//    }
//    int fullAsk() {
//        return maxx;
//    }
//    int partAsk(int l, int r) {
//        return *max_element(arr.begin() + l, arr.begin()+ r + 1);
//    }
//    void change(int pos, int val) {
//        arr[pos] = val;
//        maxx = *max_element(arr.begin(), arr.end());
//    }
//};
//
//struct SQRT {
//    vector<Block> bl;
//    int len, sz; // долинна и количество
//    SQRT() {};
//    SQRT(const vector<int>& a){
//        int n = a.size();
//        len = (int)::sqrt(n);
//        sz = 0;
//        for (int i = 0; i < n; ++i) {
//            int b = i / len;
//            if (b == sz) {
//                bl.push_back(Block());
//                sz++;
//            }
//            bl[b].arr.push_back(a[i]);
//        }
//        for (int i = 0; i < sz; ++i){
//            bl[i].build();
//        }
//    }
//    int ask(int l, int r) {
//        int posl = l / len, posinl = l % len;
//        int posr = r / len, posinr = r % len;
//        if (posl == posr) {
//            return bl[posl].partAsk(posinl, posinr);
//        }
//        int ans = -INF;
//        if (posinl != 0) {
//            ans = max(ans, bl[posl].partAsk(posinl, bl[posl].len - 1));
//            posl++;
//        }
//        if (posinr != bl[posr].len - 1) {
//            ans = max(ans, bl[posr].partAsk(0, posinr));
//            posr--;
//        }
//        for (int i = posl; i <= posr; ++i) {
//            ans = max(ans, bl[i].fullAsk());
//        }
//        return ans;
//    }
//    void change(int pos, int val) {
//        int posb = pos / len, posinb = pos % len;
//        bl[posb].change(posinb, val);
//    }
//};
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    SQRT s(a);
//    int q;
//    cin >> q;
//    for (int i = 0; i < n; ++i) {
//        char type;
//        cin >> type;
//        if (type == 's') {
//            int l, r;
//            cin >> l >> r;
//            cout << s.ask(l - 1, r - 1) << ' ';
//        } else {
//            int pos, val;
//            cin >> pos >> val;
//            s.change(pos - 1, val);
//        }
//    }
//    return 0;
//}
//
//
//
//
//





//
//struct Block {
//    vector<int> arr;
//    int summ, len, c;
//    bool has;
//    void build() {
//        len = arr.size();
//        summ = accumulate(arr.begin(), arr.end(), 0);
//        c = 0;
//        has = false;
//    }
//    void push() {
//        if (has) {
//            for (int i = 0; i < len; ++i) {
//                arr[i] = c;
//            }
//            summ = c * len;
//            has = false;
//        }
//    };
//    int fullAsk() {
//        return (has ? c * len : summ);
//    }
//    int partAsk(int l, int r) {
//        return accumulate(arr.begin() + l, arr.begin()+ r + 1, 0);
//    }
//    void fullChange(int val) {
//        c = val;
//        has = true;
//    }
//    void partChange(int l, int r, int val) {
//        push();
//        for (int i = l; i <= r; ++i) {
//            arr[i] = val;
//        }
//        summ = accumulate(arr.begin(), arr.end(), 0);
//    }
//};

//struct SQRT {
//    vector<Block> bl;
//    int len, sz; // долинна и количество
//    SQRT() {};
//    SQRT(const vector<int>& a){
//        int n = a.size();
//        len = (int)::sqrt(n);
//        sz = 0;
//        for (int i = 0; i < n; ++i) {
//            int b = i / len;
//            if (b == sz) {
//                bl.push_back(Block());
//                sz++;
//            }
//            bl[b].arr.push_back(a[i]);
//        }
//        for (int i = 0; i < sz; ++i){
//            bl[i].build();
//        }
//    }
//    int ask(int l, int r) {
//        int posl = l / len, posinl = l % len;
//        int posr = r / len, posinr = r % len;
//        if (posl == posr) {
//            return bl[posl].partAsk(posinl, posinr);
//        }
//        int ans = 0;
//        if (posinl != 0) {
//            ans += bl[posl].partAsk(posinl, bl[posl].len - 1);
//            posl++;
//        }
//        if (posinr != bl[posr].len - 1) {
//            ans += bl[posr].partAsk(0, posinr);
//            posr--;
//        }
//        for (int i = posl; i <= posr; ++i) {
//            ans += bl[i].fullAsk();
//        }
//        return ans;
//    }
//    void change(int l, int r, int val) {
//        int posl = l / len, posinl = l % len;
//        int posr = r / len, posinr = r % len;
//        if (posl == posr) {
//            bl[posl].partChange(posinl, posinr, val);
//            return;
//        }
//        int ans = 0;
//        if (posinl != 0) {
//            bl[posl].partChange(posinl, bl[posl].len - 1, val);
//            posl++;
//        }
//        if (posinr != bl[posr].len - 1) {
//            bl[posr].partChange(0, posinr, val);
//            posr--;
//        }
//        for (int i = posl; i <= posr; ++i) {
//            bl[i].fullChange(val);
//        }
//    }
//
//};































//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <numeric>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//ll INF = 1e9 + 9;
//
//struct Block {
//    vector<int> arr, srt;
//    int len, c;
//    void build() {
//        len = arr.size();
//        c = 0;
//        srt = arr;
//        sort(srt. begin(), srt.end());
//        c = 0;
//    }
//    void push() {
//        for (int i = 0; i < len; ++i) {
//            arr[i] += c;
//            srt[i] += c;
//        }
//        c = 0;
//    };
//    int fullAsk(int a, int b) {
//        return upper_bound(srt.begin(), srt.end(), b) - lower_bound(srt.begin(), srt.end(), a);
//    }
//    int partAsk(int l, int r, int a, int b) {
//        push();
//        int ans = 0;
//        for (int i = l; i <= r; ++i) {
//            if (arr[i] >= a && arr[i] <= b)
//                ans ++;
//        }
//        return ans;
//    }
//    void fullChange(int val) {
//        c += val;
//    }
//    void partChange(int l, int r, int val) {
//        push();
//        for (int i = l; i <= r; ++i) {
//            arr[i] += val;
//        }
//        build();
//    }
//};
//
//struct SQRT {
//    vector<Block> bl;
//    int len, sz; // долинна и количество
//    SQRT() {};
//    SQRT(const vector<int>& a){
//        int n = a.size();
//        len = (int)::sqrt(n);
//        sz = 0;
//        for (int i = 0; i < n; ++i) {
//            int b = i / len;
//            if (b == sz) {
//                bl.push_back(Block());
//                sz++;
//            }
//            bl[b].arr.push_back(a[i]);
//        }
//        for (int i = 0; i < sz; ++i){
//            bl[i].build();
//        }
//    }
//    int ask(int l, int r, int a, int b) {
//        int posl = l / len, posinl = l % len;
//        int posr = r / len, posinr = r % len;
//        if (posl == posr) {
//            return bl[posl].partAsk(posinl, posinr, a, b);
//        }
//        int ans = 0;
//        if (posinl != 0) {
//            ans += bl[posl].partAsk(posinl, bl[posl].len - 1, a, b);
//            posl++;
//        }
//        if (posinr != bl[posr].len - 1) {
//            ans += bl[posr].partAsk(0, posinr, a, b);
//            posr--;
//        }
//        for (int i = posl; i <= posr; ++i) {
//            ans += bl[i].fullAsk(a, b);
//        }
//        return ans;
//    }
//    void change(int l, int r, int val) {
//        int posl = l / len, posinl = l % len;
//        int posr = r / len, posinr = r % len;
//        if (posl == posr) {
//            bl[posl].partChange(posinl, posinr, val);
//            return;
//        }
//        int ans = 0;
//        if (posinl != 0) {
//            bl[posl].partChange(posinl, bl[posl].len - 1, val);
//            posl++;
//        }
//        if (posinr != bl[posr].len - 1) {
//            bl[posr].partChange(0, posinr, val);
//            posr--;
//        }
//        for (int i = posl; i <= posr; ++i) {
//            bl[i].fullChange(val);
//        }
//    }
//
//};
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    SQRT s(a);
//    int q;
//    cin >> q;
//    for (int i = 0; i < n; ++i) {
//        char type;
//        cin >> type;
//        if (type == 's') {
//            int l, r;
//            cin >> l >> r;
//            cout << s.ask(l - 1, r - 1) << ' ';
//        } else {
//            int pos, val;
//            cin >> pos >> val;
//            s.change(pos - 1, val);
//        }
//    }
//    return 0;
//}





