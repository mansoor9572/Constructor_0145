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