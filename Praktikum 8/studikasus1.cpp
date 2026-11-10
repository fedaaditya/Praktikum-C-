#include <iostream>
using namespace std;

float hitungTotalRekursif(int* arr, int n) {
    if (n <= 0) {
        return 0;
    }
    return arr[n - 1] + hitungTotalRekursif(arr, n - 1);
}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    if (n <= 0) {
        cout << "Tidak ada data mahasiswa untuk diproses." << endl;
        return 0;
    }

    int* nilai = new int[n];
    int maxNilai = -1, minNilai = 101;

    for (int i = 0; i < n; i++) {
        cout << "Mahasiswa " << i + 1 << ": ";
        cin >> nilai[i];

        if (nilai[i] > maxNilai) maxNilai = nilai[i];
        if (nilai[i] < minNilai) minNilai = nilai[i];
    }

    float rataRata = hitungTotalRekursif(nilai, n) / n;

    cout << "\nOutput:" << endl;
    cout << "Nilai terbesar: " << maxNilai << endl;
    cout << "Nilai terkecil: " << minNilai << endl;
    cout << "Rata-rata nilai: " << rataRata << endl;

    delete[] nilai;

    return 0;
}