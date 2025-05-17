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

// Represents a university student with name, ID, and a privately held grade
class Mahasiswa {
public:
    string name;
    string nim;

    // Constructor initializes public attributes and sets default grade
    Mahasiswa(const string& name, const string& nim)
        : name(name), nim(nim), grade(0.0f) {}

private:
    // Grade is private and can only be modified by Dosen
    float grade;
