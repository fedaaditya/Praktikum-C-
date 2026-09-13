#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
 
int main() {
    double height;
    double weight;

    cout << "Height: ";
    cin >> height;

    cout << "Weight: ";
    cin >> weight;

    cout << endl;

    double heightmeter = height / 100.0;
    double bmi = weight / (heightmeter * heightmeter);

    string status;

    if (bmi >= 18.5 && bmi <= 24.9) {
        status = "Ya";
    } else {
        status = "Tidak";
    }

    cout << fixed << setprecision(2) << "BMI1: " << bmi << endl;
    cout << "Status Berat Badan Ideal: " << status << endl;

    return 0;
}
