//void merge_sort(vector<int>& a, int l, int r) {
//    if (l == r-1) {
//        return;
//    }
//    int m = (l+r)/2;
//    merge_sort(a, l, m);
//    merge_sort(a, m, r);
//    vector<int> tmp;
//    int it1 = l, it2 = m;
//    while (it1 < m || it2 < r) {
//        if (it1 == m) {
//            tmp.push_back(a[it2]);
//            it2++;
//        } else if (it2 == r) {
//            tmp.push_back(a[it1]);
//            it1++;
//        } else {
//            tmp.push_back(a[it2]);
//            it2++;
//        }
//    }
//    copy(tmp.begin(), tmp.end(), a.begin()+l);
//}