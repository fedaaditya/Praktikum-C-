#include <iostream>
using namespace std;

int main() {
    int nilai;
    cout << "Masukan Nilai:";
    cin >> nilai;

    string hasil = (nilai >=90)? "Grade A" : (nilai >=80)? "Grade B"
                                           : (nilai >=70)? "Grade C"
                                           : (nilai >=60)? "Grade D" 
                                           : "Grade E";

    cout << "Grade tersebut adalah" << hasil << endl;
    return 0;

}