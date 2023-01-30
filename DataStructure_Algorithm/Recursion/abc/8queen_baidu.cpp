#include <iostream>
using namespace std;
 
const int N = 8;
int arr[10], total_cnt;
// arr记录每一行(X)皇后的Y坐标
 
bool isPlaceOK(int *a, int n, int c);
void printSol(int *a);
void addQueen(int *a, int n);

int main() {
    addQueen(arr, 1);
    cout << "total: " << total_cnt << " solutions.\n";
    return 0;
}

bool isPlaceOK(int *a, int n, int c) {
    for (int i = 1; i <= n - 1; ++i) {
        if (a[i] == c || a[i] - i == c - n || a[i] + i == c + n)
            return false;
        //检查位置是否可以放
        //c是将要放置的位置
        //a[i] == c如果放在同一列，false
        //a[i] -+ i = c -+ n 如果在对角线上，false
    }
    return true;
}
 
void printSol(int *a) {
    for (int i = 1; i <= N; ++i) { //遍历每一行
        for (int j = 1; j <= N; ++j) { //遍历每一列
            cout << (a[i] == j ? "X" : "-") << " ";;
        } //如果标记数组中这一行的皇后放在j位置，则输出X，否则输出-，
        //用空格分隔
        cout << endl; //每一行输出一个换行
    }
    cout << endl; //每一组数据一个换行分隔
}
 
void addQueen(int *a, int n) {
    if (n > N) { //n代表从第一行开始放置
        printSol(a);
        total_cnt++;
        return ;
    }
    for (int i = 1; i <= N; ++i) { //i从第1列到第N列遍历
        if (isPlaceOK(a, n, i)) {
            a[n] = i; //如果可以放置，就把皇后放在第n行第i列
            addQueen(a, n + 1);
        }
    }
 
}
 