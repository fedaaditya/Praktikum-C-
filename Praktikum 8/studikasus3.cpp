#include <iostream>
using namespace std;


void cetakMatriksRekursif(int** arr, int baris, int kolom, int barisSekarang = 0) {
    
    if (barisSekarang == baris) {
        return; 
    }

    
    for (int j = 0; j < kolom; j++) {
        cout << arr[barisSekarang][j] << " ";
    }
    cout << endl;

    
    cetakMatriksRekursif(arr, baris, kolom, barisSekarang + 1);
}

int main() {
    
    int baris = 3, kolom = 3;

    
    int** matriks = new int*[baris];
    for (int i = 0; i < baris; i++) matriks[i] = new int[kolom];

    
    int** transpose = new int*[kolom];
    for (int i = 0; i < kolom; i++) transpose[i] = new int[baris];

    
    cout << "Input:\n\n";
    cout << "Matriks:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cin >> matriks[i][j];
            
            
            transpose[j][i] = matriks[i][j];
        }
    }

    
    cout << "\nOutput:\n\n";
    
    cout << "Matriks asli:\n";
    
    cetakMatriksRekursif(matriks, baris, kolom);

    cout << "\nMatriks transpose:\n";
    
    cetakMatriksRekursif(transpose, kolom, baris);

    
    for (int i = 0; i < baris; i++) delete[] matriks[i];
    for (int i = 0; i < kolom; i++) delete[] transpose[i];
    delete[] matriks;
    delete[] transpose;

    return 0;
}