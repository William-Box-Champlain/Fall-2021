//
//  Module-08-Lab-07.cpp
//  Inheritance (the basics)
//

#include <iostream>
#include <string>

using namespace std;

enum Discipline {
    COMPUTER_SCIENCE,
    GAME_PROGRAMMING
};

const string DISCIPLINE_STRINGS[2] = {
    "Computer Science",
    "Game Programming", 
};

/* Class definitions here */
class Person
{
public:
    Person() {
        std::cout << "Person Object created using default Person constructor" << endl;
        pName = "";
    }
    Person(std::string name) {
        std::cout << "Person Object created using alternate Person constructor" << endl;
        pName = name;
    }
    ~Person() { std::cout << "Person Object Destroyed" << endl; }
    virtual std::string getName() {
        return pName;
    }
    void setName(std::string name) {
        pName = name;
    }
protected:
    std::string pName;
};

class Faculty :
    public Person
{
public:
    Faculty() {
        std::cout << "Faculty Object created using default Faculty constructor" << endl;
        pName = "";
        fDepartment = "";
    }
    Faculty(std::string name, Discipline i) {
        std::cout << "Faculty Object created using alternate Faculty constructor" << endl;
        pName = name;
        fDepartment = DISCIPLINE_STRINGS[i];
    }
    ~Faculty() { std::cout << "Faculty Object Destroyed" << endl; }
    void setDepartment(Discipline i) {
        fDepartment = DISCIPLINE_STRINGS[i];
    }
    std::string getDepartment() {
        return fDepartment;
    }
protected:
    std::string fDepartment;
};

class Student :
    public Person
{
public:
    Student() {
        std::cout << "Student Object created using default Student constructor" << endl;
        pName = "";
        sMajor = "";
    }
    Student(std::string name, Discipline i) {
        std::cout << "Student Object created using alternate Student constructor" << endl;
        pName = name;
        sMajor = DISCIPLINE_STRINGS[i];
    }
    ~Student() { std::cout << "Student Object Destroyed" << endl; }
    void setMajor(Discipline i) {
        sMajor = DISCIPLINE_STRINGS[i];
    }
    std::string getMajor() {
        return sMajor;
    }
protected:
    std::string sMajor;
};

/*Here's the main*/

int main()
{

    Faculty prof("Ada Lovelace ", COMPUTER_SCIENCE);
    Student stu("William Box", GAME_PROGRAMMING);

    cout << endl
         << "I, " << stu.getName() << ", am majoring in " << stu.getMajor() << "." << endl;
    cout << "I am taking CSI 240 with Prof. " << prof.getName() << ", who teaches "
         << prof.getDepartment() << " courses." << endl
         << endl;

    return 0;
}
