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


int main()
{
    cout<<"Student Total is "<< student ::getstudentTotal()<<endl;

    student st1("Mamn",40);
    student st2("Mohammed",30);

     cout<<"Student Total is "<< student ::getstudentTotal()<<endl;
    {
        student st3("Sazad",20);
        student st4("Ilyas",22);
        cout<<"Student Total is "<< student ::getstudentTotal()<<endl;
    }
    cout<<"Student Total is "<< student ::getstudentTotal()<<endl;




}
