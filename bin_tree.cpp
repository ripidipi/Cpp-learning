//////#include <iostream>
//////#include <vector>
//////#include <algorithm>
//////#include <unordered_map>
//////#include <numeric>
//////#include <cmath>
//////
//////using namespace std;
//////typedef long long ll;
//////
//////const int SIZE = 1e5 + 5;
//////
//////int n;
//////int a[SIZE];
//////int t[4 * SIZE];
//////
//////void build(int v, int l, int r) {
//////    if (l == r - 1) {
//////        t[v] = a[l];
//////        return;
//////    }
//////    int m = (l + r) / 2;
//////    build(2 * v + 1, l, m);
//////    build(2 * v + 2, m, r);
//////    t[v] = t[2 * v + 1] + t[2 * v + 2];
//////}
//////
//////int ask(int v, int l, int r, int askl, int askr)  { // [askl, askr)
//////    if (l >= askr || r <= askl) { // red
//////        return 0;
//////    }
//////    if (l >= askl && r <= askr) {
//////        return t[v];
//////    }
//////    int m = (l + r) / 2;
//////    return ask(2 * v + 1, l, m, askl, askr) + ask(2 * v + 2, m, r, askl, askr);
//////}
//////
//////void change(int v, int l, int r, int pos, int val) {
//////    if (l == r - 1) {
//////        t[v] = val;
//////        return;
//////    }
//////    int m = (l + r) / 2;
//////    if (pos < m) {
//////        change(2 * v + 1, l, r, pos, val);
//////    } else {
//////        change(2 * v + 2, l, r, pos, val);
//////    }
//////    t[v] = t[2 * v + 1] + t[2* v + 2];
//////}
//////
//////int main () {
//////    ios_base::sync_with_stdio(false);
//////    cin.tie(0);
//////    cout.tie(0);
//////    int n;
//////    cin >> n;
//////
//////    return 0;
//////}
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////#include<iostream>
////#include<vector>
////
////using namespace std;
////
////typedef long long ll;
////
////struct node {
////    int left, right, min, max;
////    node *child_left, *child_right;
////};
////
////const int INF = 1e9 * 2;
////
////node* build(int left, int right, vector<int>& values) {
////    if (left > right)
////        return 0;
////    node * res = new node;
////    res->left = left;
////    res->right = right;
////    if (right == left)
////    {
////        res->child_left = res->child_right = 0;
////        res->min = values[left];
////        res->max = values[left];
////    }
////    else
////    {
////        int mid = (left + right) / 2;
////        res->child_left = build(left, mid, values);
////        res->child_right = build(mid + 1, right, values);
////        res->min = min(res->child_left->min, res->child_right->min);
////        res->max = max(res->child_left->max, res->child_right->max);
////    }
////    return res;
////}
////
////int query_min(node * root, int left, int right) {
////    if (right < root->left || left > root->right)
////        return INF;
////    if (left <= root->left && right >= root->right)
////        return root->min;
////    int ans1 = query_min(root->child_left, left, right);
////    int ans2 = query_min(root->child_right, left, right);
////    return min(ans1, ans2);
////}
////
////int query_max(node * root, int left, int right) {
////    if (right < root->left || left > root->right)
////        return -INF;
////    if (left <= root->left && right >= root->right)
////        return root->max;
////    int ans1 = query_max(root->child_left, left, right);
////    int ans2 = query_max(root->child_right, left, right);
////    return max(ans1, ans2);
////}
////
////int query(node * root, int left, int right) {
////    return query_max(root, left, right) - query_min(root, left, right);
////}
////
////void update(node * root, int idx, int val) {
////    if (idx < root->left || idx > root->right)
////        return;
////    if (root->left == root->right)
////    {
////        root->min = root->max = val;
////        return;
////    }
////    update(root->child_left, idx, val);
////    update(root->child_right, idx, val);
////    root->min = min(root->child_left->min, root->child_right->min);
////    root->max = max(root->child_left->max, root->child_right->max);
////}
////
////int main() {
////    int n = 100000, k;
////    cin >> k;
////    vector<int> a(n + 1);
////    for (int i = 1; i <= n; ++i)
////        a[i] = ((long long) i * i % 12345 + (long long) i * i * i % 23456);
////    node * root = build(1, n, a);
////    for (int i = 0; i < k; ++i)
////    {
////        int x, y;
////        cin >> x >> y;
////        if (x > 0)
////            cout << query(root, x, y) << endl;
////        else
////            update(root, -x, y);
////    }
////    return 0;
////}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <unordered_map>
////#include <numeric>
////#include <cmath>
////
////using namespace std;
////typedef long long ll;
////
////const int SIZE = 1e5 + 5;
////
////int n;
////int a[SIZE];
////int t[4 * SIZE];
////
////void build(int v, int l, int r) {
////    if (l == r - 1) {
////        t[v] = (a[l] == 0 ? 1 : 0);
////        return;
////    }
////    int m = (l + r) / 2;
////    build(2 * v + 1, l, m);
////    build(2 * v + 2, m, r);
////    t[v] = t[2 * v + 1] + t[2 * v + 2];
////}
////
////int ask(int v, int l, int r, int askl, int askr)  { // [askl, askr)
////    if (l >= askr || r <= askl) { // red
////        return 0;
////    }
////    if (l >= askl && r <= askr) {
////        return t[v];
////    }
////    int m = (l + r) / 2;
////    return ask(2 * v + 1, l, m, askl, askr) + ask(2 * v + 2, m, r, askl, askr);
////}
////
////
////int getkth(int v, int l, int r, int trgt) {
////    if (l == r - 1) {
////        return l;
////    }
////    int m = (l + r) / 2;
////    if (t[2 * v + 1] > trgt) {
////        return getkth(2 * v + 1, l, m, trgt);
////    } else {
////        return getkth(2 * v + 2, m, r, trgt);
////    }
////}
////
////void change(int v, int l, int r, int pos, int val) {
////    if (l == r - 1) {
////        t[v] = (val == 0 ? 1 : 0);
////        return;
////    }
////    int m = (l + r) / 2;
////    if (pos < m) {
////        change(2 * v + 1, l, r, pos, val);
////    } else {
////        change(2 * v + 2, l, r, pos, val);
////    }
////    t[v] = t[2 * v + 1] + t[2* v + 2];
////}
////
////int main () {
////    ios_base::sync_with_stdio(false);
////    cin.tie(0);
////    cout.tie(0);
////    int n;
////    cin >> n;
////    vector<int> a(n);
////    for (int i = 0; i < n; ++i) {
////        cin >> a[i];
////    }
////    build(0, 0, n);
////    int q;
////    cin >> q;
////    for (int i = 0; i < q; ++i) {
////        char type;
////        cin >> type;
////        if (type == '?') {
////            int pos;
////            cin >> pos;
////            pos--;
////            int before = ask(0, 0, n, 0, pos);
////            int after = ask(0, 0, n, pos + 1, n);
////            int prv = (before != 0 ? getkth(0, 0, n, before-1) : -1);
////            int nxt = (after != 0 ? getkth(0, 0, n, before) : n);
////        } else {
////            int pos, val;
////            cin >> pos >> val;
////            change(0, 0, n, pos-1, val);
////        }
////    }
////
////    return 0;
////}
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
//struct Node {
//    int maxx, cnt;
//    Node() {};
//    Node(int maxx, int cnt) :maxx(maxx), cnt(cnt) {}
//
//};
//
//int n;
//int a[SIZE];
//int t[4 * SIZE];
//
//void build(int v, int l, int r) {
//    if (l == r - 1) {
//        t[v] = (a[l] == 0 ? 1 : 0);
//        return;
//    }
//    int m = (l + r) / 2;
//    build(2 * v + 1, l, m);
//    build(2 * v + 2, m, r);
//    t[v] = t[2 * v + 1] + t[2 * v + 2];
//}
//
//int ask(int v, int l, int r, int askl, int askr)  { // [askl, askr)
//    if (l >= askr || r <= askl) { // red
//        return 0;
//    }
//    if (l >= askl && r <= askr) {
//        return t[v];
//    }
//    int m = (l + r) / 2;
//    return ask(2 * v + 1, l, m, askl, askr) + ask(2 * v + 2, m, r, askl, askr);
//}
//
//
//int getkth(int v, int l, int r, int trgt) {
//    if (l == r - 1) {
//        return l;
//    }
//    int m = (l + r) / 2;
//    if (t[2 * v + 1] > trgt) {
//        return getkth(2 * v + 1, l, m, trgt);
//    } else {
//        return getkth(2 * v + 2, m, r, trgt);
//    }
//}
//
//void change(int v, int l, int r, int pos, int val) {
//    if (l == r - 1) {
//        t[v] = (val == 0 ? 1 : 0);
//        return;
//    }
//    int m = (l + r) / 2;
//    if (pos < m) {
//        change(2 * v + 1, l, r, pos, val);
//    } else {
//        change(2 * v + 2, l, r, pos, val);
//    }
//    t[v] = t[2 * v + 1] + t[2* v + 2];
//}
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    build(0, 0, n);
//    int q;
//    cin >> q;
//    for (int i = 0; i < q; ++i) {
//        char type;
//        cin >> type;
//        if (type == '?') {
//            int pos;
//            cin >> pos;
//            pos--;
//            int before = ask(0, 0, n, 0, pos);
//            int after = ask(0, 0, n, pos + 1, n);
//            int prv = (before != 0 ? getkth(0, 0, n, before-1) : -1);
//            int nxt = (after != 0 ? getkth(0, 0, n, before) : n);
//        } else {
//            int pos, val;
//            cin >> pos >> val;
//            change(0, 0, n, pos-1, val);
//        }
//    }
//
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
//const int SIZE = 1e5 + 5;
//
//struct Node {
//    int max1, max2;
//    Node() {};
//    Node(int max1,int max2) :max1(max1), max2(max2) {}
//
//};
//
//int n;
//int a[SIZE];
//Node t[4 * SIZE];
//
//Node unite (const Node& a, const Node& b) {
//    vector<int> val = {a.max1, a.max2, b.max1, b.max2};
//    sort(val.rbegin(), val.rend());
//    return Node(val[0], val[1]);
//}
//
//void build(int v, int l, int r) {
//    if (l == r - 1) {
//        t[v] = Node(a[l], -1e9);
//        return;
//    }
//    int m = (l + r) / 2;
//    build(2 * v + 1, l, m);
//    build(2 * v + 2, m, r);
//    t[v] = unite(t[2 * v + 1], t[2 * v + 2]);
//}
//
//Node ask(int v, int l, int r, int askl, int askr)  { // [askl, askr)
//    if (l >= askr || r <= askl) { // red
//        return Node(-1e9, -1e9);
//    }
//    if (l >= askl && r <= askr) {
//        return t[v];
//    }
//    int m = (l + r) / 2;
//    return unite(ask(2 * v + 1, l, m, askl, askr), ask(2 * v + 2, m, r, askl, askr));
//}
//
//void change(int v, int l, int r, int pos, int val) {
//    if (l == r - 1) {
//        t[v] = Node(val, -1e9);
//        return;
//    }
//    int m = (l + r) / 2;
//    if (pos < m) {
//        change(2 * v + 1, l, r, pos, val);
//    } else {
//        change(2 * v + 2, l, r, pos, val);
//    }
//    t[v] = unite(t[2 * v + 1], t[2* v + 2]);
//}
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n;
//    cin >> n;
//
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
//const int SIZE = 1e5 + 5;
//
//struct Node {
//    int maxx, maxl, maxr, summ, maxval;
//    Node(){};
//    Node(int x, int mval) {
//        int val = max(x, 0);
//        maxx = maxl = maxr = val;
//        summ = x;
//        maxval = mval;
//    }
//
//};
//
//int n;
//int a[SIZE];
//Node t[4 * SIZE];
//
//Node unite (const Node& a, const Node& b) {
//    Node res;
//    res.summ = a.summ + b.summ;
//    res.maxval = max(a.maxval, b.maxval);
//    res.maxl = max(a.maxl, b.maxl + a.summ);
//    res.maxr = max(b.maxr, a.maxr + b.summ);
//    res.maxx = max({a.maxx, b.maxx, a.maxr + a.maxl})
//}
//
//void build(int v, int l, int r) {
//    if (l == r - 1) {
//        t[v] = Node(a[l], a[l]);
//        return;
//    }
//    int m = (l + r) / 2;
//    build(2 * v + 1, l, m);
//    build(2 * v + 2, m, r);
//    t[v] = unite(t[2 * v + 1], t[2 * v + 2]);
//}
//
//Node ask(int v, int l, int r, int askl, int askr)  { // [askl, askr)
//    if (l >= askr || r <= askl) { // red
//        return Node(0, -1e9);
//    }
//    if (l >= askl && r <= askr) {
//        return t[v];
//    }
//    int m = (l + r) / 2;
//    return unite(ask(2 * v + 1, l, m, askl, askr), ask(2 * v + 2, m, r, askl, askr));
//}
//
//void change(int v, int l, int r, int pos, int val) {
//    if (l == r - 1) {
//        t[v] = Node(val, val);
//        return;
//    }
//    int m = (l + r) / 2;
//    if (pos < m) {
//        change(2 * v + 1, l, r, pos, val);
//    } else {
//        change(2 * v + 2, l, r, pos, val);
//    }
//    t[v] = unite(t[2 * v + 1], t[2* v + 2]);
//}
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    build(0, 0, n);
//    int q;
//    cin >> q;
//    for (int i = 0; i < q; ++i) {
//        char type;
//        cin >> type;
//        if (type == '?') {
//            int pos;
//            cin >> pos;
//            pos--;
//            int before = ask(0, 0, n, 0, pos);
//            int after = ask(0, 0, n, pos + 1, n);
//            int prv = (before != 0 ? getkth(0, 0, n, before-1) : -1);
//            int nxt = (after != 0 ? getkth(0, 0, n, before) : n);
//        } else {
//            int pos, val;
//            cin >> pos >> val;
//            change(0, 0, n, pos-1, val);
//        }
//    }
//
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
//const int SIZE = 1e5 + 5;
//
//int n;
//int a[SIZE];
//int t[4 * SIZE];
//int c[4 * SIZE];
//
//void push(int v) {
//    c[2 * v + 1] += c[v];
//    c[2 * v + 2] += c[v];
//    c[v] = 0;
//}
//
//void update(int v, int l, int r, int m) {
//    t[v] = t[2 * v + 1] + t[2 * v + 2] + c[2 * v + 1] * (m - l) + c[2 * v + 2] * (r - m);
//}
//
//int ask(int v, int l, int r, int askl, int askr) {
//    if (l >= askr || r <= askl) {
//        return 0;
//    }
//    if (l >= askl && r <= askr) {
//        return t[v] + c[v] * (r - l);
//    }
//    push(v);
//    int m = (l + r) / 2;
//    int x = ask(2 * v + 1, l, m, askl, askr);
//    int y = ask(2 * v + 2, m, r, askl, askr);
//    update(v, l, r, m);
//    return x + y;
//}
//
//void change(int v, int l, int r, int askl, int askr, int val) {
//    if (l >= askr || r <= askl) {
//        return;
//    }
//    if (l >= askl && r <= askr) {
//        c[v] += val;
//        return;
//    }
//    push(v);
//    int mid = (l + r) / 2;
//    change(2 * v + 1, l, mid, askl, askr, val);
//    change(2 * v + 2, mid, r, askl, askr, val);
//    update(v, l, r, mid);
//}
//
//void build(int v, int l, int r) {
//    if (l == r - 1) {
//        t[v] = a[l];
//        return;
//    }
//    int m = (l + r) / 2;
//    build(2 * v + 1, l, m);
//    build(2 * v + 2, m, r);
//    t[v] = t[2 * v + 1] + t[2 * v + 2];
//}
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n;
//    cin >> n;
//
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
//const int SIZE = 1e5 + 5;
//
//int n;
//int a[SIZE];
//int t[4 * SIZE];
//int c[4 * SIZE];
//bool has[4 * SIZE];
//
//
//void push(int v) {
//    if (has[v]) {
//        c[2 * v + 1] += c[v];
//        c[2 * v + 2] += c[v];
//        has[2 * v + 1] = true;
//        has[2 * v + 2] = true;
//        has[v] = false;
//    }
//}
//
//void update(int v, int l, int r, int m) {
//    t[v] = (has[2 * v + 1] ? c[2 * v + 1] * (m - l) : t[2 * v + 1]) +
//           (has[2 * v + 2] ? c[2 * v + 2] * (r - m) : t[2 * v + 2]);
//}
//
//int ask(int v, int l, int r, int askl, int askr) {
//    if (l >= askr || r <= askl) {
//        return 0;
//    }
//    if (l >= askl && r <= askr) {
//        return (has[v] ? c[v] * (r - l) : t[v]);
//    }
//    push(v);
//    int m = (l + r) / 2;
//    int x = ask(2 * v + 1, l, m, askl, askr);
//    int y = ask(2 * v + 2, m, r, askl, askr);
//    update(v, l, r, m);
//    return x + y;
//}
//
//void change(int v, int l, int r, int askl, int askr, int val) {
//    if (l >= askr || r <= askl) {
//        return;
//    }
//    if (l >= askl && r <= askr) {
//        c[v] = val;
//        has[v] = true;
//        return;
//    }
//    push(v);
//    int mid = (l + r) / 2;
//    change(2 * v + 1, l, mid, askl, askr, val);
//    change(2 * v + 2, mid, r, askl, askr, val);
//    update(v, l, r, mid);
//}
//
//void build(int v, int l, int r) {
//    if (l == r - 1) {
//        t[v] = a[l];
//        return;
//    }
//    int m = (l + r) / 2;
//    build(2 * v + 1, l, m);
//    build(2 * v + 2, m, r);
//    t[v] = t[2 * v + 1] + t[2 * v + 2];
//}
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n;
//    cin >> n;
//
//    return 0;
//}
