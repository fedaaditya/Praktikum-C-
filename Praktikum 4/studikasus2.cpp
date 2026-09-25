#include <iostream>

using namespace std;

int main() {
    int ulangi;

    do {
        int total_hadir = 0;
        int hadir;

        for (int i = 1; i <= 5; i++) {
            cout << "Apakah mahasiswa hadir di hari ke-" << i << "? (1 untuk hadir, 0 untuk tidak hadir): ";
            cin >> hadir;
            
            if (hadir == 1) {
                total_hadir++;
            }
        }

        double persentase = (total_hadir / 5.0) * 100;

        cout << "Persentase Kehadiran: " << persentase << "%" << endl;
        cout << "Status Kehadiran: ";

        if (persentase > 75) {
            cout << "Baik" << endl;
        } else if (persentase >= 50 && persentase <= 75) {
            cout << "Cukup" << endl;
        } else {
            cout << "Kurang" << endl;
        }

        cout << "Ingin mengecek kehadiran untuk mahasiswa lain? (1 untuk ya, selain itu untuk tidak): ";
        cin >> ulangi;

    } while (ulangi == 1);

    return 0;
}