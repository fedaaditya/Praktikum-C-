#include <iostream>
using namespace std;

int main() {
    int barisA, kolomA, barisB, kolomB;
    
    // Meminta ukuran matriks terlebih dahulu agar dinamis
    cout << "Masukkan ukuran Matriks A (contoh: 2 3): ";
    cin >> barisA >> kolomA;
    cout << "Masukkan ukuran Matriks B (contoh: 3 2): ";
    cin >> barisB >> kolomB;

    if (kolomA != barisB) {
        cout << "Error: Matriks tidak dapat dikalikan!" << endl;
        return 0;
    }

    // Alokasi memori dinamis
    int** A = new int*[barisA];
    for (int i = 0; i < barisA; i++) A[i] = new int[kolomA];

    int** B = new int*[barisB];
    for (int i = 0; i < barisB; i++) B[i] = new int[kolomB];

    int** C = new int*[barisA];
    for (int i = 0; i < barisA; i++) C[i] = new int[kolomB];

    cout << "\nInput:\n";
    
    // Tampilan persis seperti di PPT
    cout << "Matriks A (" << barisA << "x" << kolomA << "):\n";
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomA; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Matriks B (" << barisB << "x" << kolomB << "):\n";
    for (int i = 0; i < barisB; i++) {
        for (int j = 0; j < kolomB; j++) {
            cin >> B[i][j];
        }
    }

    // Proses Perkalian
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < kolomA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Output Hasil
    cout << "\nOutput:\n";
    cout << "Hasil perkalian Matriks A dan B:\n";
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomB; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // Dealokasi Memori
    for (int i = 0; i < barisA; i++) { delete[] A[i]; delete[] C[i]; }
    for (int i = 0; i < barisB; i++) delete[] B[i];
    delete[] A; delete[] B; delete[] C;

    return 0;
}