#include <iostream>
using namespace std;

int main(){
    int kode_hari;
    cout << "Masukan hari";
    cin >> kode_hari;

    if (kode_hari == 1) {	
	cout << "Hari SENIN" << endl;
    } else if (kode_hari == 2) {
	cout << "Hari SELASA" << endl;
    } else if (kode_hari == 3) {
	cout << "Hari RABU" << endl;
    } else if (kode_hari == 4) {
	cout << "Hari KAMIS" << endl;
    } else if (kode_hari == 5) {        
	cout << "Hari JUMAT" << endl;

    } else if (kode_hari == 6) {
	cout << "Hari SABTU" << endl;					
    } else if (kode_hari == 7) {
	cout << "Hari MINGGU" << endl;    
    } else {
	cout << "Kode yang dimasukkan salah" << endl;    
    }
    return 0;
}

