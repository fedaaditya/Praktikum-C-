#include <iostream>
using namespace std;


int getDiskon(long harga) {
    if (harga > 500000) return 10;
    if (harga == 500000) return 5;
    return 0;
}


long hitungTotalRekursif(long* harga, int n) {
    if (n <= 0) return 0; 
    
    long hargaBarang = harga[n - 1];
    long diskon = hargaBarang * getDiskon(hargaBarang) / 100;
    long hargaSetelahDiskon = hargaBarang - diskon;
    
    return hargaSetelahDiskon + hitungTotalRekursif(harga, n - 1);
}

int main() {
    int n;
    cout << "Input:\n";
    cout << "Masukkan jumlah barang: ";
    cin >> n;


    long* harga = new long[n];

    for (int i = 0; i < n; i++) {
        cout << "Masukkan harga barang " << i + 1 << ": ";
        cin >> harga[i];
    }

    cout << "\nOutput:\n";
    for (int i = 0; i < n; i++) {
        int diskon = getDiskon(harga[i]);
        if (diskon > 0) {
            cout << "Diskon untuk barang " << i + 1 << ": " << diskon << "%\n";
        } else {
            cout << "Diskon untuk barang " << i + 1 << ": Tidak ada diskon\n";
        }
    }

    long total = hitungTotalRekursif(harga, n);
    cout << "Total harga setelah diskon: " << total << endl;


    delete[] harga;
    return 0;
}