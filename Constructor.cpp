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
    private:
    // Lecturer's academic rank is managed by Staff only
    string rank;
    // Lecturer's salary is exposed only through Universitas functions
    double salary;

    // Allow Staff to change the lecturer's rank
    friend class Staff;

    // Allow Universitas to view the lecturer's salary
    friend void Universitas::lihatGajiDosen(Dosen*);
};
// Represents a staff member with ID and private salary information
class Staff {
public:
    // Staff member's full name
    string name;
    // Staff identification number
    string staffID;


    // Constructor initializes staff details and salary value
    Staff(const string& name,
          const string& staffID,
          double salary)
        : name(name), staffID(staffID), salary(salary) {}

    // Method for updating a lecturer's rank through a pointer
    void ubahPangkat(Dosen* d, const string& newRank) {
        d->rank = newRank; // Directly modifies the private rank field
    }

private:
    // Private salary for staff, viewed only by Universitas friend
    double salary;

    // Allow Universitas to view the staff member's salary
    friend void Universitas::lihatGajiStaff(Staff*);
};
// Implementation of Universitas functions to reveal private salary data
void Universitas::lihatGajiDosen(Dosen* d) {
    cout << "Salary of Dosen " << d->name
         << " is: " << d->salary << endl;
}
