#include <iostream>
using namespace std;

class student {
    private :
         static int studentTotal;
    public :
        string name;
        string status;
        int age;

        student(string pName, int pAge){
            name = pName;
            age =pAge;
            status ="new student";
            ++studentTotal;
            cout<< name<<" created "<<"status"<<status<<endl;
            cout<<endl;
        }
        ~student(){
            cout<<name<<"destroyed"<<endl;
            --studentTotal;
            cout<<endl;
        }
        static int getstudentTotal(){
            return studentTotal;
        }



};
int student :: studentTotal =0;



