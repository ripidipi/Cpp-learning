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
//    int key, prior, sz;
//    node *l, *r;
//    node() :l(nullptr), r(nullptr), sz(0) {};
//    node(int key) :key(key), prior(superRand()), l(nullptr), r(nullptr), sz(1) {}
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
//void split(node* root, node*& l, node*& r, int x) {
//    if (!root) {
//        l = r = nullptr;
//        return;
//    }
//    if(root->key < x) {
//        split(root->r, root->r, r, x);
//        l = root;
//    } else {
//        split(root->l, l, root->l, x);
//        r = root;
//    }
//}
//
//void merge(node*& root, node* l, node* r) {
//    if(!l || !r) {
//        root = (!l ? r : l);
//        return;
//    }
//    if(l->prior > r->prior) {
//        merge(l->r, l->r, r);
//        root = l;
//        update(l);
//    } else {
//        merge(r->l, l, r->l);
//        root = r;
//        update(r);
//    }
//    update(root);
//}
//node *tmp1, *tmp2, *tmp3;
//
//void insert(node*& root, int x) {
//    node* ins = getNode(x);
//    split(root, tmp1, tmp2, x);
//    merge(root, tmp1, ins);
//    merge(root, root, tmp2);
//}
//
//void erase(node*& root, int x) {
//    split(root, tmp1, tmp2, x);
//    split(tmp2, tmp2, tmp3, x + 1);
//    merge(root, tmp1, tmp3);
//}
//
//void eraseOne(node*& root, int x) {
//    if(!root) {return;}
//    if(root->key == x) {
//        merge(root, root->l, root->r);
//    } else if (root->key > x) {
//        eraseOne(root->l, x);
//    } else {
//        eraseOne(root->r, x);
//    }
//    update(root);
//}
//
//bool find(node* root, int x) {
//    if(!root) {
//        return false;
//    }
//    if(root->key == x) {
//        return true;
//    }
//    if(root->key > x) {
//        return find(root->l, x);
//    } else {
//        return find(root->r, x);
//    }
//}
//
//int getkth(node* root, int k) {
//    if (getSz(root->l) > k) {
//        getkth(root->l, k);
//    } else if (getSz(root->l) == k) {
//        return root->key;
//    } else {
//        getkth(root->r, k - getSz(root->l) - 1);
//    }
//}
//
//int getnum(node* root, int x) {
//    if (!root) {
//        return 0;
//    }
//    if (root->key == x) {
//        return getSz(root->l);
//    } else if (root->key > x) {
//        return getnum(root->l, x);
//    } else {
//        return getnum(root->r, x) + getSz(root->l) + 1;
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    node* root = new node;
//    return 0;
//}
//
//
//
//
//
