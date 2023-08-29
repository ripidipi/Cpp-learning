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
//random_device rd;
//mt19937 gen(rd());
//uniform_int_distribution<> distr(1, (int)1e9);
//
//inline int superRand() {
//    return distr(gen);
//}
//
//struct node {
//    int val, prior, sz;
//    node *l, *r;
//    node() :l(nullptr), r(nullptr) {};
//    node(int val) :val(val), prior(superRand()), l(nullptr), r(nullptr), sz(1) {}
//};
//
//node nodes[MAXSIZE];
//int sz = 0;
//
//inline node* getNode(int x) {
//    nodes[sz] = node(x);
//    return &nodes[sz++];
//}
//
//inline int getSz(node* root) {
//    return (root ? root->sz : 0);
//}
//
//inline void update(node* root) {
//    if (root) {
//        root->sz = getSz(root->l) + getSz(root->r) + 1;
//    }
//}
//
//void split(node* root, node*& l, node*& r, int k) {
//    if (!root) {
//        l = r = nullptr;
//        return;
//    }
//    if(getSz(root->l) >= k) {
//        split(root->l, l, root->l, k);
//        r = root;
//        update(r);
//    } else {
//        split(root->r, root->r, r, k - getSz(root->l) - 1);
//        l = root;
//        update(l);
//    }
//}
//
//void merge(node*& root, node* l, node* r) {
//    if(!l || !r) {
//        root = (l ? l: r);
//        return;
//    }
//    if(l->prior > r->prior) {
//        merge(l->r, l->r, r);
//        root = l;
//    } else {
//        merge(r->l, l, r->l);
//        root = r;
//    }
//    update(root);
//}
//
//node *tmp1, *tmp2, *tmp3;
//
//void insert(node*& root, int pos, int val) {
//    node *ins = getNode(val);
//    split(root, tmp1, tmp2, pos);
//    merge(root, tmp1, ins);
//    merge(root, root, tmp2);
//}
//
//void erase(node* root, int pos) {
//    split(root, tmp1, tmp2, pos);
//    split(tmp2, tmp2, tmp3, 1);
//    merge(root, tmp1, tmp3);
//}
//
//void print(node* root) {
//    if(!root) {
//        return;
//    }
//    print(root->l);
//    cout << root->val << ' ';
//    print(root->r);
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    node* root = nullptr;
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= n; ++i) {
//        node* ins = getNode(i);
//        merge(root, root, ins);
//    }
//    for(int i = 0; i < m; ++i) {
//        int l, r;
//        cin >> l >> r;
//        split(root, tmp1, tmp3, r);
//        split(tmp1, tmp1, tmp2, l - 1);
//        merge(tmp2, tmp2, tmp1);
//        merge(root, tmp2, tmp3);
//    }
//    print(root);
//    cout << endl;
//    return 0;
//}
//
//
//
//
//
