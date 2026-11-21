#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main (){

    double jumlahrupiah;
    double kurskonversi;
    
    cout << "Jumlah Rupiah: ";
    cin >> jumlahrupiah;

    cout << "Kurs Konversi: ";
    cin >> kurskonversi;

    cout << endl;

    double jumlahdollar = jumlahrupiah / kurskonversi;

    cout << "Jumlah Rupiah: " << fixed << setprecision(0) << jumlahrupiah << endl;
    cout << fixed << setprecision(2) << "Jumlah Dollar: $ " << jumlahdollar << endl;

    return 0;
}