#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main (){
    int p;
    int l;
    int t;

    cout << "Panjang: ";
    cin >> p;

    cout << "Lebar: ";
    cin >> l;

    cout << "Tinggi: ";
    cin >> t;

    cout << endl;

    int volume = p * l * t;
    int luaspermukaan = 2 * ((p * l) + (p * t) + (l * t));

    cout << right << setw(20) << "Panjang";
    cout << right << setw(20) << "Lebar";
    cout << right << setw(20) << "Tinggi";
    cout << right << setw(20) << "Volume";
    cout << right << setw(20) << "Luas Permukaan" << endl;

    cout << right << setw(20) << p;
    cout << right << setw(20) << l;
    cout << right << setw(20) << t;
    cout << right << setw(20) << volume;
    cout << right << setw(20) << luaspermukaan << endl;

    return 0;
}