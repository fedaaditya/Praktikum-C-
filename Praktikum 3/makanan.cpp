#include <iostream>
using namespace std;

int main(){
    int makanan;
    cout << "Masukan makanan";
    cin >> makanan;

    if (makanan == 1) {	
	cout << "Makanan Nasi Goreng" << endl;
    } else if (makanan == 2) {
	cout << "Makanan Mie Goreng" << endl;
    } else if (makanan == 3) {
	cout << "Makanan Bakso" << endl;
    } else if (makanan == 4) {
	cout << "Makanan Sate" << endl;
    } else if (makanan == 5) {        
	cout << "Makanan Gado-Gado" << endl;

    } else if (makanan == 6) {
	cout << "Makanan Soto" << endl;					
    } else if (makanan == 7) {
	cout << "Makanan Nasi Padang" << endl;    
    } else {
	cout << "Kode yang dimasukkan salah" << endl;    
    }
    return 0;
}

