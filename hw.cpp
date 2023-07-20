////#include <iostream>
////#include <algorithm>
////#include <vector>
////#include <cmath>
////#include <numeric>
////
////using namespace std;
////
////typedef long double ld;
////typedef long long ll;
////
////inline pair<int, int> make_cur_pair (pair<int, int>& a) {
////    if (a.first > a.second) {
////        return {a.second - 1, a.first - 1};
////    } else {
////        return {a.first - 1, a.second - 1};
////    }
////}
////
////
////int main () {
////    ios_base::sync_with_stdio(false);
////    cin.tie(0);
////    cout.tie(0);
////    int n, m, a0;
////    cin >> n >> m >> a0;
////    vector<int> a(n);
////    a[0] = a0;
////    for (int i = 1; i < n; ++i) {
////        a[i] = (23 * a[i - 1] + 21563) % 16714589;
////    }
////    vector<int> logs(n + 1);
////    logs[1] = 0;
////    for (int i = 2; i <= n; ++i) {
////        logs[i] = logs[i / 2] + 1;
////    }
////    vector<vector<int>> sparse (logs[n] + 1, vector<int> (n));
////    for (int i = 0; i < n; ++i) {
////        sparse[0][i] = a[i];
////    }
////    for (int level = 1; (1 << level) <= n; ++level) {
////        for (int i = 0; i + (1 << level) <= n; ++i) {
////            sparse[level][i] = min(sparse[level - 1][i], sparse[level - 1][i + (1 << (level - 1))]);
////        }
////    }
////    int u0, v0;
////    cin >> u0 >> v0;
////    vector<pair<int, int>> req(m);
////    vector<int> ans(m);
////    req[0] = {u0, v0};
////    pair<int, int> cur_base = make_cur_pair(req[0]);
////    int level_base = logs[cur_base.second - cur_base.first + 1];
////    ans[0] = min(sparse[level_base][cur_base.second - (1 << level_base) + 1], sparse[level_base][cur_base.first]);
////    for (int i = 1; i < m; ++i) {
////        req[i] = {((17 * req[i - 1].first + 751 + ans[i - 1] + 2 * i) % n) + 1, ((13 * req[i - 1].second + 593 + ans[i - 1] + 5 * i) % n) + 1};
////        pair<int, int> cur = make_cur_pair(req[i]);
////        int level = logs[cur.second - cur.first - 1];
////        ans[i] = min(sparse[level][cur.second - (1 << level) + 1], sparse[level][cur.first]);
////    }
////    for (int i = 0; i < m; ++i) {
////        cout << req[i].first << ' ' << req[i].second << ' ' <<  ans[i] << '\n';
////    }
//////    cout << req[m - 1].first << ' ' << req[m - 1].second << ' ' << ans[m - 1] << '\n';
////}
//
//
//
//
//
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
//
//struct Block {
//    vector<int> arr;
//    int len;
//    void build () {
//        len = arr.size();
//    }
//    int partSum (int l, int r) {
//        int c = 0;
//        for (int i = l; i <= r; ++i) {
//            c += arr[i];
//        }
//        return c;
//    }
//    int fullSum () {
//        int c = 0;
//        for (int i = 0; i < len; ++i) {
//            c += arr[i];
//        }
//        return c;
//    }
//    vector<int> slice(int l, int r) {
//        vector<int> cur;
//        for (int i = l; i <= r; ++i) {
//            cur.push_back(arr[i]);
//        }
//        return cur;
//    }
//    vector<int> fullget() {
//        return arr;
//    }
//    vector<int> partget(int l, int r) {
//        return slice(l, r);
//    }
//    void partChange (int l, int r, vector<int>& a, int j) {
//        for (int i = l; i <= r; ++i) {
//            arr[i] = a[j];
//            j++;
//        }
//    }
//};
//struct Q {
//    vector<Block> bl;
//    int len, sz;
//    Q(){}
//    Q(vector<int>& a) {
//        int n = a.size();
//        len = sqrt(n);
//        sz = 0;
//        for (int i = 0; i < n; ++i) {
//            int b = i / len;
//            if (b == sz) {
//                bl.push_back(Block());
//                sz++;
//            }
//            bl[b].arr.push_back(a[i]);
//        }
//        for (int i = 0; i < sz; ++i) {
//            bl[i].build();
//        }
//    }
//    int summ(int l, int r) {
//        int posl = l / len, posinl = l % len;
//        int posr = r / len, posinr = r % len;
//        if (posl == posr) {
//            return bl[posl].partSum(posinl, posinr);
//        }
//        int ans = 0;
//        if (posinl != 0) {
//            ans += bl[posl].partSum(posinl, bl[posl].len - 1);
//            posl++;
//        }
//        if (posinr != bl[posr].len - 1) {
//            ans += bl[posr].partSum(0, posinr);
//            posr--;
//        }
//        for (int i = posl; i <= posr; ++i) {
//            ans += bl[i].fullSum();
//        }
//        return ans;
//    }
//    vector<int> getArr (int l, int r) {
//        vector<int> splt;
//        int posl = l / len, posinl = l % len;
//        int posr = r / len, posinr = r % len;
//        vector<int> curpref, cursuff;
//        if (posl == posr) {
//            splt = bl[posl].partget(posinl, posinr);
//            return splt;
//        }
//
//        if (posinl != 0) {
//            curpref = bl[posl].partget(posinl, bl[posl].len - 1);
//            posl++;
//        }
//        if (posinr != bl[posr].len - 1) {
//            cursuff = bl[posr].partget(0, posinr);
//            posr--;
//        }
//        splt.insert(splt.end(), curpref.begin(), curpref.end());
//        for (int i = posl; i <= posr; ++i) {
//            curpref = bl[i].fullget();
//            splt.insert(splt.end(), curpref.begin(), curpref.end());
//        }
//        splt.insert(splt.end(), cursuff.begin(), cursuff.end());
//        return splt;
//    }
//    void turn(int l, int r) {
//        vector<int> arr = getArr(l, r);
//        int j = 0;
//        reverse(arr.begin(), arr.end());
//        int posl = l / len, posinl = l % len;
//        int posr = r / len, posinr = r % len;
//        if (posl == posr) {
//            bl[posl].partChange(posinl, posinr, arr, j);
//            return;
//        }
//        if (posinl != 0) {
//            bl[posl].partChange(posinl, bl[posl].len - 1, arr, j);
//            j += bl[posl].len - posinl;
//            posl++;
//        }
//        for (int i = posl; i <= posr; ++i) {
//            if ((posinr != bl[posr].len - 1) && i == posr) {
//                bl[posr].partChange(0, posinr, arr, j);
//                j += posinr;
////                if (j == arr.size()) {
////                    cout << 'Yes!' << '\n';
////                } else {
////                    cout << j << ' ' << arr.size() << '\n';
////                }
//            }
//            bl[i].partChange(0, bl[i].len, arr, j);
//            j += bl[i].len - 1;
//        }
//    }
//
//};
//
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    Q s(a);
//    for (int i = 0; i < m; ++i) {
//        int q, l, r;
//        cin >> q >> l >> r;
//        l--, r--;
//        if (q == 0) {
//            cout << s.summ(l, r) << '\n';
//        } else {
//            s.turn(l, r);
//        }
//    }
//}



//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//struct Block {
//    vector<int> arr;
//    int len;
//    int maxx;
//    Block(){
//        len = 0;
//        maxx = -1;
//    }
//    void add(int a) {
//        arr.push_back(a);
//        maxx = max(maxx, a);
//        len++;
//    };
//};
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    int sqtrn = ::sqrt(n);
//    vector<Block> lens;
//    lens.push_back(Block());
//    vector<int> vis(n);
//    for (int i = 0; i < n; i++) {
//        int a;
//        cin >> a;
//        if (lens.back().len < sqtrn) {
//            lens.back().add(a);
//        } else {
//            lens.push_back(Block());
//            lens.back().add(a);
//        }
//        vis[i] = 1;
//        for (int j = lens.size() - 1; j > -1; --j) {
//            if (lens[j].maxx > a) {
//                for (int k = lens[j].len - 1; k > -1; --k) {
//                    if (lens[j].arr[k] > a) {
//                        vis[i] = vis[k + j * sqtrn] + 1;
//                        break;
//                    }
//                }
//                break;
//            }
//        }
//        cout << vis[i] << '\n';
//    }
//
//    return 0;
//}




//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> make_pred(vector<int>& ans, vector<int>& pref){
//    vector<int> cur(pref.size()+ans.size()-1);
//    for (int i = 0; i < ans.size() - 1; ++i) {
//        cur[i] = ans[ans.size() - 1] + ans[i];
//    }
//    for (int i = 0; i < pref.size(); ++i) {
//        cur[i + ans.size() - 1] = ans[ans.size() - 1] + pref[i];
//    }
//    return cur;
//}
//
//bool check(vector<int>& tarifs, vector<bool>& state, vector<int>& pred, vector<int>& pref) {
//    for (int &i : pred) {
//        int cur = lower_bound(tarifs.begin(), tarifs.end(), i) - tarifs.begin();
//        int j = 0;
//        bool flag = true;
//        while (tarifs[cur + j] == i) {
//            if (state[cur + j]) {
//                pref.push_back(tarifs[cur + j]);
//                state[cur + j] = 0;
//                flag = false;
//                break;
//            }
//            j++;
//        }
//        if (flag) {
//            return false;
//        }
//    }
//    return true;
//}
//
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n;
//    cin >> n;
//    if (n == 1) {
//        int a1, a2;
//        cin >> a1 >> a2;
//        cout << max(a1, a2) << '\n';
//        return 0;
//    }
//    int s = (1 << n);
//    vector<int> a(s);
//    for (int i = 0; i < s; ++i) {
//        cin >> a[i];
//    }
//    sort(a.begin(), a.end());
//    vector<int> ans;
//    vector<bool> state(s, true);
//    vector<int> pref;
//    state[0] = state[1] = false;
//    ans.push_back(a[1]);
//    for (int i = 1; i < n; ++i) {
//        int ind = find(state.begin(), state.end(), true) - state.begin();
//        if (ind != s) {
//            ans.push_back(a[ind]);
//            state[ind] = false;
//        }
//        vector<int> pred = make_pred(ans, pref);
//        if (!check(a, state, pred, pref)) {
//            cout << "impossible" << '\n';
//            return 0;
//        }
//    }
//    for (int i: ans) {
//        cout << i << '\n';
//    }
//    return 0;
//}
//

///// impossible





//// C++ program for above approach
//#include <bits/stdc++.h>
//using namespace std;
//
//// Function to return minimum difference
//// between sum of two subarrays
//pair<vector<int>, vector<int>> minDiffSubArray(vector<int>& arr, int total_sum, int n) {
//    pair<vector<int>, vector<int>> ans;
//    sort(arr.begin(), arr.end());
//    reverse(arr.begin(), arr.end());
//    int sum1 = arr[0], sum2 = arr[1];
//    ans.first.push_back(arr[0]);
//    ans.second.push_back(arr[1]);
//    for (int i = 2; i < n; ++i) {
//        if (sum1 < total_sum / 2 + 1 && sum1 <= sum2) {
//            sum1 += arr[i];
//            ans.first.push_back(arr[i]);
//        } else {
//            sum2 += arr[i];
//            ans.second.push_back(arr[i]);
//        }
//    }
//    return ans;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    vector<int> arr(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> arr[i];
//    }
//    int total_sum = 0;
//    for (int i = 0; i < n; ++i)
//        total_sum += arr[i];
//    int maxx = *max_element(arr.begin(), arr.end());
//    if (maxx > total_sum - maxx) {
//        cout << -1 << '\n';
//        return 0;
//    }
//    pair<vector<int>, vector<int>> ans = minDiffSubArray(arr, total_sum, n);
//    for (int i = 0; i < ans.first.size(); ++i) {
//        cout << ans.first[i] << ' ';
//    }
//    cout << '\n';
//    for (int i = 0; i < ans.second.size(); ++i) {
//        cout << ans.second[i] << ' ';
//    }
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//
//void town_rec(vector<vector<char>>& box, vector<vector<bool>>& state, int n, int m, int i, int j) {
//    if (j - 1 > -1 && (box[i][j - 1] == '#' || (box[i][j - 1] > 64 && box[i][j - 1] < 90)) && state[i][j - 1]) {
//        state[i][j - 1] = false;
//        town_rec(box, state, n, m, i, j - 1);
//    }
//    if (i - 1 > -1 && (box[i - 1][j] == '#' || (box[i - 1][j] > 64 && box[i - 1][j] < 90)) && state[i - 1][j]) {
//        state[i - 1][j] = false;
//        town_rec(box, state, n, m, i - 1, j);
//    }
//    if (i + 1 < n && (box[i + 1][j] == '#' || (box[i + 1][j] > 64 && box[i + 1][j] < 90)) && state[i + 1][j]) {
//        state[i + 1][j] = false;
//        town_rec(box, state, n, m, i + 1, j);
//    }
//    if (j + 1 < m && (box[i][j + 1] == '#' || (box[i][j + 1] > 64 && box[i][j + 1] < 90)) && state[i][j + 1]) {
//        state[i][j + 1] = false;
//        town_rec(box, state, n, m, i, j + 1);
//    }
//}
//
//int field_rec(vector<vector<char>>& box, vector<vector<bool>>& state, vector<vector<bool>>& tmp,
//              int n, int m, int i, int j, int summ, unordered_map<char, int>& owner) {
//    if ((box[i][j] == '.' || (box[i][j] > 64 && box[i][j] < 90)) && state[i][j]) {
//        state[i][j] = false;
//        if (i + 1 < n && state[i + 1][j]) {
//            summ = field_rec(box, state, tmp, n, m, i + 1, j, summ, owner);
//        }
//        if (j + 1 < m && state[i][j + 1]) {
//            summ = field_rec(box, state, tmp, n, m, i, j + 1, summ, owner);
//        }
//        if (i - 1 > -1) {
//            if (state[i - 1][j])
//                summ = field_rec(box, state, tmp, n, m, i - 1, j, summ, owner);
//            else if (box[i - 1][j] == '#' && tmp[i - 1][j]) {
//                tmp[i - 1][j] = false;
//                town_rec(box, tmp, n, m, i - 1, j);
//                summ += 3;
//            }
//        }
//        if (j - 1 > -1) {
//            if (state[i][j - 1])
//                summ = field_rec(box, state, tmp, n, m, i, j - 1, summ, owner);
//            else if (box[i][j - 1] == '#' && tmp[i][j - 1]) {
//                tmp[i][j - 1] = false;
//                town_rec(box, tmp, n, m, i, j - 1);
//                summ += 3;
//            }
//        }
//        if (box[i][j] > 64 && box[i][j] < 90) {
//            owner[box[i][j]] ++;
//            state[i][j] = true;
//        }
//    }
//    if (box[i][j] == '#' && tmp[i][j]) {
//        tmp[i][j] = false;
//        town_rec(box, tmp, n, m, i, j);
//        summ += 3;
//    }
//    return summ;
//}
//
//void field_check(vector<vector<char>>& box, vector<vector<bool>>& state,
//                 int n, int m, int i, int j, unordered_map<char, int>& ans) {
//    vector<vector<bool>> tmp(n, vector<bool>(m, true));
//    unordered_map<char, int> owner = {{ 'R', 0}, {'Y', 0}, {'G', 0}, {'B', 0}, {'K', 0}};
//    int summ = field_rec(box, state, tmp, n, m, i, j, 0, owner);
//
//    vector<char> keys;
//    int maxx = 1;
//    for (const auto& pair: owner) {
//        if (pair.second > maxx) {
//            keys.clear();
//            keys.push_back(pair.first);
//            maxx = pair.second;
//        } else if (pair.second == maxx) {
//            keys.push_back(pair.first);
//        }
//    }
//    for (auto key: keys) {
//        ans[key] += summ;
//    }
//}
//
//int obj_rec(vector<vector<char>>& box, vector<vector<bool>>& state,
//            int n, int m, int i, int j, int summ, unordered_map<char, int>& owner, char type) {
//    if ((box[i][j] == type || (box[i][j] > 64 && box[i][j] < 90)) && state[i][j]) {
//        state[i][j] = false;
//        summ += 1;
//        if (i + 1 < n && state[i + 1][j]) {
//            summ = obj_rec(box, state, n, m, i + 1, j, summ, owner, type);
//        }
//        if (j + 1 < m && state[i][j + 1]) {
//            summ = obj_rec(box, state, n, m, i, j + 1, summ, owner, type);
//        }
//        if (i - 1 > -1 && state[i - 1][j]) {
//            summ = obj_rec(box, state, n, m, i - 1, j, summ, owner, type);
//        }
//        if (j - 1 > -1 && state[i][j - 1]) {
//            summ = obj_rec(box, state, n, m, i, j - 1, summ, owner, type);
//        }
//        if (box[i][j] > 64 && box[i][j] < 90) {
//            owner[box[i][j]] ++;
//            state[i][j] = true;
//            summ --;
//        }
//    }
//    return summ;
//}
//
//void obj_check(vector<vector<char>>& box, vector<vector<bool>>& state,
//               int n, int m, int i, int j, unordered_map<char, int>& ans, char type) {
//    unordered_map<char, int> owner = {{ 'R', 0}, {'Y', 0}, {'G', 0}, {'B', 0}, {'K', 0}};
//    int summ = obj_rec(box, state, n, m, i, j, 0, owner, type);
//
//    vector<char> keys;
//    int maxx = 1;
//    for (const auto& pair: owner) {
//        if (pair.second > maxx) {
//            keys.clear();
//            keys.push_back(pair.first);
//            maxx = pair.second;
//        } else if (pair.second == maxx) {
//            keys.push_back(pair.first);
//        }
//    }
//    for (auto key: keys) {
//        ans[key] += summ;
//    }
//}
//
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//    vector<vector<char>> box(n, vector<char>(m));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> box[i][j];
//        }
//    }
//    unordered_map<char, int> ans = {{ 'R', 0}, {'Y', 0}, {'G', 0}, {'B', 0}, {'K', 0}};
//    vector<vector<bool>>  state(n, vector<bool>(m, true));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            if (state[i][j]) {
//                if (box[i][j] == '.') {
//                    field_check(box, state, n, m, i, j, ans);
//                } else if (box[i][j] == '#' || box[i][j] == '+') {
//                    obj_check(box, state, n, m, i, j, ans, box[i][j]);
//                }
//                state[i][j] = false;
//                if (box[i][j] > 64 && box[i][j] < 90) {
//                    state[i][j] = true;
//                }
//            }
//        }
//    }
//    vector<char> keys;
//    int maxx = 1;
//    for (const auto& pair: ans) {
//        if (pair.second > maxx) {
//            keys.clear();
//            keys.push_back(pair.first);
//            maxx = pair.second;
//        } else if (pair.second == maxx) {
//            keys.push_back(pair.first);
//        }
//    }
//    cout << maxx << '\n';
//    for (char i: keys) {
//        cout << i << ' ';
//    }
//    return 0;
//}
//
//
////4 4
////R##.
////##..
////...Y
////R##.


