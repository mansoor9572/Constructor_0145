#include <iostream>
using namespace std;

class angka {
private:
    int *arr;
    int panjang;
public:
    angka(int);     // Constructor
    ~angka();       // Destructor
    void cetakData();
    void isiData();
};
// Constructor allocates the array and immediately fills it with user-provided values
angka::angka(int i) {
    panjang = i;
    arr = new int[i];
    isiData();
}
// Destructor prints the array contents then frees the allocated memory
angka::~angka() {
    cout << endl;
    cetakData();
    delete[] arr;
    cout << "Array memory has been released" << endl;
}
void angka::cetakData() {
    for (int i = 1; i <= panjang; i++) {
        cout << i << ": " << arr[i] << endl;
    }
}

void angka::isiData() {
    for (int i = 1; i <= panjang; i++) {
        cout << i << ": ";
        cin >> arr[i];
    }
    cout << endl;
}

int main() {
    angka belajarcpp(3);                   // Stack allocation: constructor and destructor are called automatically
    angka *ptrBelajarcpp = new angka(5);  // Heap allocation: must manually delete to invoke destructor
    delete ptrBelajarcpp;                 // Destructor called for heap object
    return 0;
}