#include <iostream>
using namespace std;

void calculateSquare(int &number) {
    number *= number; 
}

int main() {
    int num = 5;
    int nilaiAwal = num;
    
    calculateSquare(num);
    
    cout << "Kuadrat dari " << nilaiAwal << " adalah " << num << endl;
    
    return 0;
}