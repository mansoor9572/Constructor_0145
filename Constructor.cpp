#include <iostream>  
#include <string>    

using namespace std; 

// Forward declarations allow classes to be referenced before definition
class Mahasiswa;
class Dosen;
class Staff;

// Universitas offers controlled access to private salary information
class Universitas {
public:
    // Friend function to display a lecturer's private salary
    static void lihatGajiDosen(Dosen* d);
    // Friend function to display a staff member's private salary
    static void lihatGajiStaff(Staff* s);
};