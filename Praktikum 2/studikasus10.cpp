#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    const int n = 5;
    double angka[n];
    double total = 0, rataRata, totalSelisihKuadrat = 0, standarDeviasi;


    for (int i = 0; i < n; i++) {
        cout << "Angka " << (i + 1) << ": ";
        cin >> angka[i];
        total += angka[i];
    }


    rataRata = total / n;


    for (int i = 0; i < n; i++) {
        totalSelisihKuadrat += pow(angka[i] - rataRata, 2);
    }


    standarDeviasi = sqrt(totalSelisihKuadrat / (n - 1));


    cout << fixed << setprecision(2);
    cout << "\nRata-rata: " << rataRata << endl;
    cout << "Standar Deviasi: " << standarDeviasi << endl;

    return 0;
}