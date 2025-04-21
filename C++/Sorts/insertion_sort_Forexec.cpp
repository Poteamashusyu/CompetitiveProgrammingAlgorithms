#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 挿入ソート(Insertion Sort)関数
 * 
 * @param A {vector<int>&} ソート対象vector
 * 
 * 計算量: O(N^2) (N: 配列(vector)サイズ)
 */
void insertionSort(vector<int>& A) {
    const int N = A.size();

    for(int i = 1; i < N; i++) {
        for(int j = i-1; j >= 0; j--) {
            if(A[j] <= A[j+1]) break;
            swap(A[j], A[j+1]);
        }
    }

    return;
}

int main() {    
    vector<int> A = {3, 0, 6, 8, 1, 7, 5, 9, 2, 4, 1, 3, 2, 4, 0};

    for(const int a : A) cout << a << ' ';
    cout << endl;
    insertionSort(A);
    for(const int a : A) cout << a << ' ';
    cout << endl;

    return 0;
}