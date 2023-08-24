//#include<iostream>
////#include<cstdio>
//#include<algorithm>
//#include<vector>
//#include<cmath>
//#include<string>
//#include<numeric>
//#include<random>
//#include<fstream>
//
//using namespace std;
//
//typedef long long ll;
//typedef long double ld;
//
//inline int super_rand() {
//    return (rand() << 15) + rand();
//}
//
//struct Node {
//    int key, prior, sz;
//    ll sum;
//    Node* l, * r;
//    Node() :l(nullptr), r(nullptr),sum(0), sz(0) {}
//    Node(int key) :l(nullptr), r(nullptr), key(key), prior(super_rand()), sz(1), sum(key) {}
//};
//
//const int SIZE = 1e5 + 342;
//
//Node nodes[SIZE];
//int sz = 0;
//
//inline Node* getNode(int x) {
//    nodes[sz] = Node(x);
//    return &nodes[sz++];
//}
//
//inline int get_sz(Node* root) {
//    return (root ? root->sz : 0);
//}
//
//inline ll get_sum(Node* root) {
//    return(root ? root->sum : 0);
//}
//
//inline void update(Node*& root) {
//    if (root) {
//        root->sz = get_sz(root->l) + get_sz(root->r) + 1;
//        root->sum = get_sum(root->l) + get_sum(root->r) + root->key;
//    }
//}
//
//Node* tmp1, * tmp2, * tmp3;
//
//void split(Node* root, Node*& l, Node*& r, int x) {
//    if (!root) {
//        l = nullptr;
//        r = nullptr;
//        return;
//    }
//    if (root->key < x) {
//        split(root->r, root->r, r, x);
//        l = root;
//    }
//    else {
//        split(root->l, l, root->l, x);
//        r = root;
//    }
//    update(l);
//    update(r);
//}
//
//void merge(Node*& root, Node* l, Node* r) {
//    if (!l || !r) {
//        root = (l ? l : r);
//        return;
//    }
//    if (l->prior > r->prior) {
//        merge(l->r, l->r, r);
//        root = l;
//    }
//    else {
//        merge(r->l, l, r->l);
//        root = r;
//    }
//    update(root);
//}
//
//bool find(Node* root, int x) {
//    if (!root) {
//        return false;
//    }
//    if (root->key == x) {
//        return true;
//    }
//    if (root->key > x) {
//        return find(root->l, x);
//    }
//    else {
//        return find(root->r, x);
//    }
//}
//
//void insert(Node*& root, int x) {
//    Node* ins = getNode(x);
//    if (!root) {
//        root = ins;
//        return;
//    }
//    split(root, tmp1, tmp2, x);
//    merge(root, tmp1, ins);
//    merge(root, root, tmp2);
//
//}
//
//void eraseall(Node*& root, int x) {
//    split(root, tmp1, tmp2, x);
//    split(root, tmp2, tmp3, x + 1);
//    merge(root, tmp1, tmp3);
//}
//
//void eraseone(Node*& root, int x) {
//    if (!root) {
//        return;
//    }
//    if (root->key == x) {
//        merge(root, root->l, root->r);
//    }
//    else if (root->key > x) {
//        eraseone(root->l, x);
//    }
//    else {
//        eraseone(root->r, x);
//    }
//    update(root);
//}
//
//int getkth(Node* root, int k) {
//    if (get_sz(root->l) > k) {
//        return getkth(root->l, k);
//    }
//    else if (get_sz(root->l) == k) {
//        return root->key;
//    }
//    else {
//        return getkth(root->r, k - get_sz(root->l) - 1);
//    }
//}
//
//int getnum(Node* root, int x) {
//    if (!root) {
//        return 0;
//    }
//    if (root->key == x) {
//        return get_sz(root->l);
//    }
//    else if (root->key > x) {
//        return getnum(root->l, x);
//    }
//    else {
//        return getnum(root->r, x) + get_sz(root->l) + 1;
//    }
//}
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    cout.precision(40);
//
//    Node* root = nullptr;
//
//    string s;
//    int x;
//
//    while(cin >> s >> x) {
//        if (s[0] == 'i') {
//            if (!find(root, x))insert(root, x);
//        }
//        else if (s[0] == 'd') {
//            if (find(root, x)) eraseone(root, x);
//        }
//        else if (s[0] == 'e') {
//            cout << (find(root, x) ? "true\n" : "false\n");
//        } else if (s[0] == 'n') {
//            int g = getnum(root, x);
//            if (get_sz(root) <= g + find(root, x)) {
//                cout << "none\n";
//            }
//            else{
//                cout << getkth(root, g + find(root, x)) << '\n';
//            }
//        } else if (s[0] == 'k') {
//            if (get_sz(root) <= x) {
//                cout << "none\n";
//            }
//            else {
//                cout << getkth(root, x) << '\n';
//            }
//        }
//        else {
//            int k = getnum(root, x);
//            if (k == 0) {
//                cout << "none\n";
//            }
//            else {
//                cout << getkth(root, k - 1) << '\n';
//            }
//        }
//
//    }
//
//}


