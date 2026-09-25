#include <iostream>

using namespace std;

int main() {
    int ulangi;

    do {
        int jumlah_mapel;
        double total_nilai = 0;
        double rata_rata;

        cout << "Masukkan jumlah mata pelajaran: ";
        cin >> jumlah_mapel;

        for (int i = 1; i <= jumlah_mapel; i++) {
            double nilai;
            cout << "Masukkan nilai mata pelajaran ke-" << i << ": ";
            cin >> nilai;
            total_nilai += nilai;
        }


        rata_rata = total_nilai / jumlah_mapel;


        cout << "Rata-rata Nilai: " << rata_rata << endl;
        cout << "Prestasi: ";


        if (rata_rata > 85) {
            cout << "Sangat Baik" << endl;
        } else if (rata_rata >= 70 && rata_rata <= 85) {
            cout << "Baik" << endl;
        } else if (rata_rata >= 50 && rata_rata < 70) {
            cout << "Cukup" << endl;
        } else {
            cout << "Perlu Peningkatan" << endl;
        }


        cout << "Ingin menghitung nilai untuk siswa lain? (1 untuk ya, selain itu untuk tidak): ";
        cin >> ulangi;

    } while (ulangi == 1);

    return 0;
}