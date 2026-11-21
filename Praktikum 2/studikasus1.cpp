#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main(){

    string nama;
    int jamkerja;
    int tarifperjam;
    int gajitotal;

    cout << "Nama Karyawan: ";
    cin >> nama;

    cout << "Jam Kerja: ";
    cin >> jamkerja;

    cout << "Tarif Per Jam: ";
    cin >> tarifperjam;

    gajitotal = jamkerja * tarifperjam;

    cout << endl;

    cout << left << setw(15) << "Nama";
    cout << right << setw(12) << "Jam Kerja";
    cout << right << setw(15) << "Tarif Per Jam";
    cout << right << setw(15) << "Gaji Total" << endl;

    cout << setw(57) << "---------------------------------------------------------" << endl;

    cout << left << setw(15) << nama;
    cout << right << setw(12) << jamkerja;
    cout << right << setw(15) << tarifperjam;
    cout << right << setw(15) << gajitotal << endl;

    return 0;
}