//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//#include <string>
//
//using namespace std;
//
//void cut(vector<vector<int>>& a) {
//    a[0].resize(12);
//    for (int i = 1; i < 6; ++i) {
//        for (int j = 6 + i; j < 12; ++j) {
//            a[i][j] = 0;
//        }
//    }
//    for (int i = 11; i > 6; --i) {
//        for (int j = 12 - (i - 6); j < 12 ; ++j) {
//            a[i][j] = 0;
//        }
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    vector<vector<int>> a(12, vector<int>(12, 0));
//    int strti, strtj, fini, finj;
//    char strt, fin;
//    ::scanf("%c%d %c%d", &strt, &strtj, &fin, &finj);
//    strti = strt - 'a' + 1, fini = fin - 'a' + 1;
//    for (int j = strtj + 1; j < 12; ++j) {
//        a[strti][j] = 1;
//    }
//    for (int j = strtj - 1; j > 0; --j) {
//        a[strti][j] = 1;
//    }
//    if (strti < 6) {
//        for (int i = 1; strti-i > 0; ++i) {
//            a[strti-i][strtj] = 1;
//        }
//        for (int i = 1; strti-i > 0 && strtj-i > 0; ++i) {
//            a[strti-i][strtj-i] = 1;
//        }
//        int j = 1;
//        while (strti + j < 6) {
//            a[strti+j][strtj] = 1;
//            j++;
//        }
//        for (int i = 0; strti + j + i < 12 && strtj - i > 0; ++i) {
//            a[strti + j + i][strtj - i] = 1;
//        }
//        j = 1;
//        while (strti + j < 6) {
//            a[strti + j][strtj + j] = 1;
//            j++;
//        }
//        for (int i = 0; strti + i + j < 12; ++i) {
//            a[strti + i + j][strtj + j] = 1;
//        }
//    } else if (strti == 6) {
//        for (int i = 1; i < 12; ++i) {
//            a[i][strtj] = 1;
//        }
//        for (int i = 1; strti - i > 0 && strtj - i > 0; ++i) {
//            a[strti - i][strtj - i] = 1;
//        }
//        for (int i = 1; strti + i < 12 && strtj - i > 0; ++i) {
//            a[strti + i][strtj - i] = 1;
//        }
//    } else {
//        for (int i = 1; strti+i < 12; ++i) {
//            a[strti+i][strtj] = 1;
//        }
//        for (int i = 1; strti+i < 12 && strtj-i > 0; ++i) {
//            a[strti + i][strtj - i] = 1;
//        }
//        int j = 1;
//        while (strti - j > 6) {
//            a[strti - j][strtj] = 1;
//            j++;
//        }
//        for (int i = 0; strti - j - i > 0 && strtj - i > 0; ++i) {
//            a[strti - j - i][strtj - i] = 1;
//        }
//        j = 1;
//        while (strti - j > 6) {
//            a[strti - j][strtj + j] = 1;
//            j++;
//        }
//        for (int i = 0; strti - i - j > 0; ++i) {
//            a[strti - i - j][strtj + j] = 1;
//        }
//    }
//    int summ = 0;
//    cut(a);
//    a[strti][strtj] = 0;
//    a[fini][finj] = 0;
//
//    for (int j = finj + 1; j < 12; ++j) {
//        summ += a[fini][j];
//    }
//    for (int j = finj - 1; j > 0; --j) {
//        summ += a[fini][j];
//    }
//    if (fini < 6) {
//        for (int i = 1; fini-i > 0; ++i) {
//            summ += a[fini-i][finj];
//        }
//        for (int i = 1; fini-i > 0 && finj-i > 0; ++i) {
//            summ += a[fini-i][finj-i];
//        }
//        int j = 1;
//        while (fini + j < 6) {
//            summ += a[fini+j][finj];
//            j++;
//        }
//        for (int i = 0; fini + j + i < 12 && finj - i > 0; ++i) {
//            summ += a[fini + j + i][finj - i];
//        }
//        j = 1;
//        while (fini + j < 6) {
//            summ += a[fini + j][finj + j];
//            j++;
//        }
//        for (int i = 0; fini + i + j < 12; ++i) {
//            summ += a[fini + i + j][finj + j];
//        }
//    } else if (fini == 6) {
//        for (int i = 1; i < 12; ++i) {
//            summ += a[i][finj];
//        }
//        for (int i = 1; fini - i > 0 && finj - i > 0; ++i) {
//            summ += a[fini - i][finj - i];
//        }
//        for (int i = 1; fini + i < 12 && finj - i > 0; ++i) {
//            summ += a[fini + i][finj - i];
//        }
//    } else {
//        for (int i = 1; fini + i < 12; ++i) {
//            summ += a[fini+i][finj];
//        }
//        for (int i = 1; fini+i < 12 && finj-i > 0; ++i) {
//            summ += a[fini + i][finj - i];
//        }
//        int j = 1;
//        while (fini - j > 6) {
//            summ += a[fini - j][finj];
//            j++;
//        }
//        for (int i = 0; fini - j - i > 0 && finj - i > 0; ++i) {
//            summ += a[fini - j - i][finj - i];
//        }
//        j = 1;
//        while (fini - j > 6) {
//            summ += a[fini - j][finj + j];
//            j++;
//        }
//        for (int i = 0; fini - i - j > 0; ++i) {
//            summ += a[fini - i - j][finj + j];
//        }
//    }
//    cout << summ << '\n';
//    return 0;
//}
//
//
