#include <iostream>
using namespace std;

int main() {
    
    int barisA = 2, kolomA = 3;
    int barisB = 3, kolomB = 2;

    
    int** A = new int*[barisA];
    for (int i = 0; i < barisA; i++) A[i] = new int[kolomA];

    int** B = new int*[barisB];
    for (int i = 0; i < barisB; i++) B[i] = new int[kolomB];

    int** C = new int*[barisA];
    for (int i = 0; i < barisA; i++) C[i] = new int[kolomB];

    cout << "Input:\n\n";
    cout << "Matriks A (2x3):\n";
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomA; j++) {
            cin >> A[i][j];
        }
    }

    cout << "\nMatriks B (3x2):\n";
    for (int i = 0; i < barisB; i++) {
        for (int j = 0; j < kolomB; j++) {
            cin >> B[i][j];
        }
    }

    
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < kolomA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nOutput:\n\n";
    cout << "Hasil perkalian Matriks A dan B:\n";
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomB; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    
    for (int i = 0; i < barisA; i++) { delete[] A[i]; delete[] C[i]; }
    for (int i = 0; i < barisB; i++) delete[] B[i];
    delete[] A; delete[] B; delete[] C;

    return 0;
}