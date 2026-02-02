#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int N = 1000;
    int A[N], B[N], C[N];

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }

    cout << "Resultados (primeros 10 elementos):\n";
    for (int i = 0; i < 10; i++) {
        cout << A[i] << " + " << B[i] << " = " << C[i] << endl;
    }

    return 0;
}
