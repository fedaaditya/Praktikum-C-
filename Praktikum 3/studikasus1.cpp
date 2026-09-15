#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    string nama;
    int posisi;
    int tarif;
    int jamKerja;
    int GajiTotal;

    cout << "======================= Data Karyawan =======================" << endl;

    cout << "Nama Karyawan : ";
    cin >> nama;

    cout << "Posisi Karyawan : ";
    cin >> posisi;

    cout << "Jam Kerja Karyawan : ";
    cin >> jamKerja;

    if (posisi == 1){
        tarif = 15000;
    }
    else if (posisi == 2){
        tarif = 25000;
    }
    else if (posisi == 3){
        tarif = 35000;    
    }
    else if (posisi == 4){
        tarif = 45000;
    }
    else if (posisi == 5){
        tarif = 55000;
    }

    GajiTotal = tarif * jamKerja;
    cout << "======================= Total Gaji =======================" << endl;
    cout << "Nama Karyawan : " << nama << endl;
    cout << "Total Gaji    : Rp " << GajiTotal << endl;
    return 0;

}