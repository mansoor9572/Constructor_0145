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

    // Grant Dosen permission to access and modify grade
    friend class Dosen;
};
// Represents a lecturer with public ID info and private rank and salary
class Dosen {
public:
    // Lecturer's full name
    string name;
    // Lecturer's unique NIDN
    string nidn;

    // Constructor initializes all lecturer attributes
    Dosen(const string& name,
          const string& nidn,
          const string& rank,
          double salary)
        : name(name), nidn(nidn), rank(rank), salary(salary) {}

    // Method for assigning a grade to a student via pointer
    void beriNilai(Mahasiswa* m, float nilai) {
        m->grade = nilai; // Directly sets the student's private grade
    }