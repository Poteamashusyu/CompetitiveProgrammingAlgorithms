#include <vector>

using namespace std;

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