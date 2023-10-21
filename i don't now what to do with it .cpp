////#include <iostream>
////#include <vector>
////#include <chrono>
////#include <string>
////#include <algorithm>
////#include <numeric>
////#include <map>
////#include <set>
////#include <cmath>
////#include <random>
////#include <unordered_map>
////#include <stack>
////typedef long double ld;
////typedef long long ll;
////#define all(a) a.begin(), a.end()
////#define null nullptr
////
////using namespace std;
////
////const double eps = 1e-7;
////const int INF = 1e9;
////const int SIZE = 1e5 + 5;
////const int LOG = 17;
////const int MOD = 1e9 + 7;
////
////inline ostream& operator << (ostream& out, vector<int>& a) {
////    for (int i: a) {
////        out << i << ' ';
////    }
////    return out;
////}
////
////random_device randomizer;
////mt19937 gen(randomizer());
////uniform_int_distribution<int> dist(1, (int)1e9);
////
////int superRand() {
////    return dist(gen);
////}
////
////struct Node {
////    int key, prior, sz;
////    Node *l, *r;
////    Node() :l(null), r(null), sz(0) {};
////    Node(int key) :key(key), prior(superRand()), l(null), r(null), sz(1) {};
////};
////
////int sz = 0;
////Node nodes[SIZE];
////
////inline Node* getNew(int key) {
////    nodes[sz] = Node(key);
////    return &nodes[sz++];
////}
////
////inline int getSz(Node* root) {
////    return (root ? root->sz : 0);
////}
////
////inline void updata(Node* root) {
////    if (root) {
////        root->sz = getSz(root->l) + getSz(root->r) + 1;
////    }
////}
////
////void split(Node* root, Node*& l, Node*& r, int x) {
////    if (!root) {
////        l = r = null;
////        return;
////    }
////    if (root->key < x) {
////        split(root->r, root->r, r, x);
////        l = root;
////        updata(l);
////    } else {
////        split(root->l, l, root->l, x);
////        r = root;
////        updata(r);
////    }
////}
////
////void merge(Node*& root, Node* l, Node* r) {
////    if (!l || !r) {
////        root = (l ? l : r);
////        return;
////    }
////    if (l->prior > r->prior) {
////        merge(l->r, l->r, r);
////        root = l;
////    } else {
////        merge(r->l, l, r->l);
////        root = r;
////    }
////    updata(root);
////}
////
////Node* unite(Node*& l, Node*& r) {
////    if (!l || !r) {
////        return l ? l : r;
////    }
////    if (l->prior < r->prior) {
////        swap(l, r);
////    }
////    Node* lt, *rt;
////    split(r, lt, rt, l->key);
////    l->l = unite(l->l, lt);
////    l->r = unite(l->r, rt);
////    return l;
////}
////
////Node *tmp1, *tmp2, *tmp3;
////
////bool exist(Node* root, int key) {
////    if(!root) {
////        return false;
////    }
////    if(root->key == key) {
////        return true;
////    }
////    if (root->key < key) {
////        return exist(root->r, key);
////    } else {
////        return exist(root->l, key);
////    }
////}
////
////
////void insert(Node*& root, int key) {
////    Node* ins = getNew(key);
////    if (exist(root, key)) {
////        return;
////    }
////    split(root, tmp1, tmp2, key);
////    merge(root, tmp1, ins);
////    root = unite(root, tmp2);
////}
////
////void erase(Node*& root, int key) {
////    split(root, tmp1, tmp2, key);
////    split(tmp2, tmp2, tmp3, key + 1);
////    root = unite(tmp1, tmp3);
////}
////
////int next(Node* root, int key) {
////    Node copy = *root;
////    split(root, tmp1, tmp2, key);
////    split(tmp2, tmp2, tmp3, key + 1);
////    if (!tmp3) {
////        return -1;
////    }
////    root = &copy;
////    return min(tmp3->key, (tmp3->l ? tmp3->l->key : INF));
////}
////
////int prev(Node* root, int key) {
////    Node copy = *root;
////    split(root, tmp1, tmp2, key);
////    if (!tmp1) {
////        return -1;
////    }
////    root = &copy;
////    return max(tmp1->key, (tmp1->r ? tmp1->r->key : -INF));
////}
////
////int subkth(Node* root, int k) {
////    if (!root) {
////        return -1;
////    }
////    if (getSz(root) > k) {
////        return subkth(root->l, k);
////    } else if (getSz(root) == k) {
////        return root->key;
////    } else {
////        return subkth(root->r, k - getSz(root) - 1);
////    }
////}
////
////int kth(Node* root, int k) {
////    if (!root) {
////        return -1;
////    }
////    Node copy = *root;
////    int val = subkth(root, k);
////    if (val == -1) {
////        return -1;
////    }
////    split(root, tmp1, tmp2, val + 1);
////    root = &copy;
////    return subkth(tmp1, k);
////}
////
////
////int main() {
////    ios_base::sync_with_stdio(false);
////    cin.tie(0);
////    cout.tie(0);
////    Node *root = null;
////    int n;
////    string s;
////    while(cin >> s >> n) {
////        if (s == "insert") {
////            insert(root, n);
////        }
////        else if (s == "exists") {
////            cout << (exist(root, n) ? "true" : "false") << endl;
////        }
////        else if (s == "next") {
////            int ans = next(root, n);
////            if (ans == -1) {
////                cout << "none"<< endl;
////            } else {
////                cout << ans<< endl;
////            }
////        }
////        else if (s == "prev") {
////            int ans = prev(root, n);
////            if (ans == -1) {
////                cout << "none"<< endl;
////            } else {
////                cout << ans<< endl;
////            }
////        }
////        else if (s == "delete") {
////            erase(root, n);
////        }
////        else if (s == "kth") {
////            int ans = kth(root, n);
////            if (ans == -1) {
////                cout << "none"<< endl;
////            } else {
////                cout << ans << endl;
////            }
////        }
////    }
////    return 0;
////}
//
//
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <limits.h>
//#include <stdio.h>
//#include <algorithm>
//
//#define null nullptr
//#define int long long
//const int none = LLONG_MAX;
//#define endl '\n'
//
//const int truee = -2656734345;
//const int fals = -412543435;
//
//struct DD
//{
//private:
//    struct Node
//    {
//        int size;
//        int val;
//        int priority;
//        Node* left = null;
//        Node* right = null;
//        Node(int v) : val(v), size(1), priority(rand()) {}
//    };
//    int _size(Node* n)
//    {
//        return n ? n->size : 0;
//    }
//    void update(Node* n)
//    {
//        if (n)
//            n->size = 1 + _size(n->left) + _size(n->right);
//    }
//    Node* root = null;
//    Node* merge(Node* l, Node* r)
//    {
//        if (!l || !r)
//            return l ? l : r;
//        if (l->priority > r->priority)
//        {
//            l->right = merge(l->right, r);
//            update(l);
//            return l;
//        }
//        else
//        {
//            r->left = merge(l, r->left);
//            update(r);
//            return r;
//        }
//    }
//    int min(Node* t)
//    {
//        if (!t)
//            return none;
//        while (t->left)
//            t = t->left;
//        return t->val;
//    }
//    int max(Node* t)
//    {
//        if (!t)
//            return none;
//        while (t->right)
//            t = t->right;
//        return t->val;
//    }
//    void split(Node* t, int val, Node*& l, Node*& r)
//    {
//        if (t == null)
//        {
//            r = l = null;
//            return;
//        }
//        if (t->val > val)
//        {
//            r = t;
//            split(r->left, val, l, r->left);
//            update(r);
//        }
//        else
//        {
//            l = t;
//            split(l->right, val, l->right, r);
//            update(l);
//        }
//    }
//    bool exists(Node* t, int key)
//    {
//        if (t == nullptr)
//            return false;
//        if (t->val < key)
//            return exists(t->right, key);
//        if (t->val > key)
//            return exists(t->left, key);
//        return true;
//    }
//    int next(Node* t, int val)
//    {
//        Node* l = null, * r = null;
//        split(t, val, l, r);
//        int res = min(r);
//        root = merge(l, r);
//        return res;
//    }
//    int prev(Node* t, int val)
//    {
//        Node* l = null, * r = null;
//        split(t, val - 1, l, r);
//        int res = max(l);
//        root = merge(l, r);
//        return res;
//    }
//    void splitInd(Node* t, int ind, Node*& l, Node*& r)
//    {
//        if (!t)
//        {
//            l = r = null;
//            return;
//        }
//        int ls = _size(t->left);
//        if (ls >= ind)
//        {
//            r = t;
//            splitInd(t->left, ind, l, r->left);
//            update(r);
//        }
//        else
//        {
//            l = t;
//            splitInd(t->right, ind - ls - 1, l->right, r);
//            update(l);
//        }
//    }
//public:
//    int prev(int x)
//    {
//        return prev(root, x);
//    }
//    bool exists(int key)
//    {
//        return exists(root, key);
//    }
//    void push(int key)
//    {
//        if (exists(key))
//            return;
//        Node* l = null, * r = null;
//        split(root, key, l, r);
//        root = merge(merge(l, new Node(key)), r);
//    }
//    void remove(int key)
//    {
//        if (!exists(key))
//            return;
//        Node* l = null, * r = null;
//        split(root, key - 1, l, r);
//        Node* l1 = null, * r1 = null;
//        split(r, key, l1, r1);
//        root = merge(l, r1);
//    }
//    int next(int val)
//    {
//        return next(root, val);
//    }
//    int operator[](int ind)
//    {
//        if (!root || ind > root->size)
//            return none;
//        Node* l = null, * r = null;
//        splitInd(root, ind, l, r);
//        int res = max(l);
//        root = merge(l, r);
//        return res;
//    }
//};
//
//bool exists(std::vector<int>& vec, int val)
//{
//    for (auto i : vec)
//        if (i == val)
//            return true;
//    return false;
//}
//
//void push(std::vector<int>& vec, int val)
//{
//    if (exists(vec, val))
//        return;
//    vec.push_back(val);
//    std::sort(std::begin(vec), std::end(vec));
//}
//void erase(std::vector<int>& vec, int val)
//{
//    std::vector<int> buff;
//    for (auto i : vec)
//        if (i != val)
//            buff.push_back(i);
//    std::swap(vec, buff);
//}
//int next(std::vector<int>& vec, int val)
//{
//    int res = none;
//    for (auto i : vec)
//        if (i > val && i < res)
//            res = i;
//    return res;
//}
//int prev(std::vector<int>& vec, int val)
//{
//    int res = -none;
//    for (auto i : vec)
//        if (i < val && i > res)
//            res = i;
//    return (res == -none ? none : res);
//}
//
//int kth(std::vector<int>& vec, int ind)
//{
//    std::sort(std::begin(vec), std::end(vec));
//    return (ind >= vec.size() ? none : vec[ind]);
//}
//
//std::vector<int> rough(std::vector<std::pair<std::string, int>>& ve)
//{
//    std::vector<int> ans;
//    std::vector<int> vec;
//    for (int i = 0; i < ve.size(); i++)
//    {
//        std::string cmd = ve[i].first;
//        int x = ve[i].second;
//        if (cmd == "insert")
//            push(vec, x);
//        if (cmd == "delete")
//            erase(vec, x);
//        if (cmd == "exists")
//            ans.push_back(exists(vec, x) ? truee : fals);
//        if (cmd == "next")
//        {
//            int a = next(vec, x);
//            ans.push_back(a);
//        }
//        if (cmd == "prev")
//        {
//            int a = prev(vec, x);
//            ans.push_back(a);
//        }
//        if (cmd == "kth")
//        {
//            int a = kth(vec, x - 1);
//            ans.push_back(a);
//        }
//    }
//    return ans;
//}
//
//std::vector<int> solve(std::vector<std::pair<std::string, int>>& q)
//{
//    DD tree;
//    std::vector<int> ans;
//    for (int i = 0; i < q.size(); i++)
//    {
//        std::string cmd = q[i].first;
//        int x = q[i].second;
//        if (cmd == "insert")
//            tree.push(x);
//        if (cmd == "delete")
//            tree.remove(x);
//        if (cmd == "exists")
//            ans.push_back(tree.exists(x) ? truee : fals);
//        if (cmd == "next")
//        {
//            int a = tree.next(x);
//            ans.push_back(a);
//        }
//        if (cmd == "prev")
//        {
//            int a = tree.prev(x);
//            ans.push_back(a);
//        }
//        if (cmd == "kth")
//        {
//            int a = tree[x];
//            ans.push_back(a);
//        }
//    }
//    return ans;
//}
//
//void test()
//{
//    const int cmdCnt = 400;
//    std::vector<std::pair<std::string, int>> vec;
//    for (int i = 0; i < cmdCnt; i++)
//    {
//        std::string s;
//        int cmd = rand() % 6;
//        if (cmd == 0)
//            s = "insert";
//        if (cmd == 1)
//            s = "delete";
//        if (cmd == 2)
//            s = "exists";
//        if (cmd == 3)
//            s = "next";
//        if (cmd == 4)
//            s = "prev";
//        if (cmd == 5)
//            s = "kth";
//        int x = rand() % 10 + 1;
//        vec.push_back({ s, x });
//    }
//    std::vector<int> right = rough(vec);
//    std::vector<int> check = solve(vec);
//    if (right != check)
//    {
//        for (auto i : vec)
//            std::cout << i.first << ' ' << i.second << endl;
//        exit(0);
//    }
//}
//
//signed main()
//{
//    const bool tes = false;
//    if (tes)
//        for (int i = 0; i < 1349991; i++)
//        {
//            std::cout << i << endl;
//            test();
//        }
//    std::vector<std::pair<std::string, int>> vec;
//    std::string b1;
//    int b2;
//    while (std::cin >> b1 >> b2)
//        vec.push_back({ b1, b2 });
//    std::vector<int> ans = solve(vec);
//    for (auto i : ans)
//    {
//        if (i == none)
//            std::cout << "none" << endl;
//        else if (i == fals)
//            std::cout << "false" << endl;
//        else if (i == truee)
//            std::cout << "true" << endl;
//        else
//            std::cout << i << endl;
//    }
//    return 0;
//}




////#define _USE_MATH_DEFINES
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
//#include <fstream>
//#include <queue>
//typedef long double ld;
//typedef long long ll;
//typedef unsigned int uint;
//#define all(a) a.begin(), a.end()
//#define null nullptr
//#define Fin ios_base::sync_with_stdio(false); cin.tie(null); cout.precision(40);
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9 + 9;
//const int SIZE = 1e5 + 6;
//const int MOD = 1e9 + 7;
//const int BASE = 256;
//
//
//inline ostream& operator << (ostream& out, vector<int>& a) {
//    for (auto i: a) {
//        out << i << ' ';
//    }
//    return out;
//}
//
//inline ostream& operator << (ostream& out, vector<char>& a) {
//    for (auto i: a) {
//        if (i != '\000')
//            out << i;
//    }
//    return out;
//}
//
//inline int top(stack<pair<int, int>>& s) {
//    return (s.empty() ? -1 : s.top().first);
//}
//
//inline int q_open(vector<int>& arr, stack<pair<int, int>> stk) {
//    int c = 0, ind = (stk.empty() ? -1 : stk.top().second);
//    for (int i : arr) {
//        if (i < ind) {
//            c++;
//        }
//    }
//    if (c == arr.size() && !stk.empty()) {
//        stk.pop();
//        return q_open(arr, stk);
//    }
//    return c;
//}
//
//void solve(string s) {
//    int n = (int)s.size();
//    stack<pair<int, int>> stk;
//    vector<int> cur_ans;
//    vector<int> res;
//    for (int i = 0; i < n; ++i) {
//        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
//            stk.push({s[i], i});
//        } else {
//            if (top(stk) == s[i] - 1 || top(stk) == s[i] - 2) {
//                res.push_back(stk.top().second);
//                res.push_back(i);
//                stk.pop();
////                if(stk.empty()) {
////                    cur_ans = ((int)res.size() < (int)cur_ans.size() ? cur_ans : take(res));
////                    res.clear();
////                }
//            } else {
////                maxx = max(maxx, cur_len);
////                cur_ans = ((int)res.size() < maxx ? cur_ans : res);
//                cur_ans = ((int)res.size() - q_open(res, stk) - 1 <
//                           (int)cur_ans.size() ? cur_ans : res);
//                while(!stk.empty()) {
//                    stk.pop();
//                }
//                res.clear();
//            }
//        }
//    }
////    if(stk.empty()) {
//    cur_ans = ((int)res.size() - q_open(res, stk) - 1 <
//               (int)cur_ans.size() ? cur_ans : res);
////    }
//    if ((int)cur_ans.size() == 0) {
//        cout << "\n";
//        return;
//    }
//    int shift = *min_element(all(cur_ans));
//    int maxx = *max_element(all(cur_ans));
//    int m = maxx - shift + 1;
//    vector<char> fin_ans(maxx - shift + 1);
//    for (int cur_an : cur_ans) {
//        fin_ans[cur_an - shift] = s[cur_an];
//    }
//    for (int i = 0; i < m; ++i) {
//        if (fin_ans[i] == '\000') {
//            if (m - i > i) {
//                vector<char> tmp(m - i);
//                for (int j = 0; j < m - i; ++j) {
//                    tmp[j] = fin_ans[j + i];
//                }
//                fin_ans = tmp;
//                m = (int)fin_ans.size();
//            } else {
//                fin_ans.resize(i);
//            }
//        }
//    }
//    cout << fin_ans << '\n';
//}
//
//int main() {
//    Fin
//    string s;
//    cin >> s;
//    solve(s);
//    return 0;
//}



////#define _USE_MATH_DEFINES
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
//#include <fstream>
//#include <queue>
//typedef long double ld;
//typedef long long ll;
//typedef unsigned long long ull;
//typedef unsigned int uint;
//#define all(a) a.begin(), a.end()
//#define null nullptr
//#define Fin ios_base::sync_with_stdio(false); cin.tie(null); cout.precision(40);
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9 + 9;
//const ull UINF = (ull)1e17 + 7;
//const int SIZE = 1e5 + 6;
//const int MOD = 1e9 + 7;
//const int BASE = 256;
//
//
//inline ostream& operator << (ostream& out, vector<uint>& a) {
//    for (auto i: a) {
//        out << i << ' ';
//    }
//    return out;
//}
//
//inline ostream& operator << (ostream& out, vector<int>& a) {
//    for (auto i: a) {
//        out << i << ' ';
//    }
//    return out;
//}
//
//inline ostream& operator << (ostream& out, vector<char>& a) {
//    for (auto i: a) {
//        if (i != '\000')
//            out << i;
//    }
//    return out;
//}
//
//uint cur = 0;
//
//uint nextRand24(uint a, uint b) {
//    cur = cur * a + b;
//    return cur >> 8;
//}
//
//uint nextRand32(uint A, uint B) {
//    uint a = nextRand24(A, B), b = nextRand24(A, B);
//    return ((a << 8) ^ b);
//}
//
//vector<uint> gen(uint n, uint a, uint b) {
//    vector<uint> arr(n);
//    for (int i = 0; i < n; ++i) {
//        arr[i] = nextRand32(a, b);
//    }
//    return arr;
//}
//
//ull dist_calc(vector<uint>& arr, ull y) {
//    ull c = 0;
//    for (auto &i: arr)c += abs((ll)y - (ll)i);
//
//    return c;
//}
//
//void solve() {
//    int n;
//    cin >> n;
//    int a, b;
//    cin >> a >> b;
//    auto arr = gen(n, a, b);
//    ull c = 0;
//    for (auto &i: arr) c += i;
//    c /= (int)(arr.size());
//    cout << dist_calc(arr, c) << '\n';
//}
//
//int main() {
//    Fin
//    cout << nextRand32(239, 13);
//    solve();
//    return 0;
//}
//
