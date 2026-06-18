#include <iostream>
#include <string>
using namespace std;

// Lớp cơ sở (Cha)
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {
        cout << "Person ctor được gọi\n";
    }
};

// Lớp dẫn xuất cấp 1
class Employee : public Person {
protected:
    int employeeId;
    double salary;
public:
    // Gọi constructor của Person qua initializer list
    Employee(string n, int a, int id, double s) 
        : Person(n, a), employeeId(id), salary(s) {
        cout << "Employee ctor được gọi\n";
    }
};

// Lớp dẫn xuất cấp 2 (Con cuối)
class Manager : public Employee {
private:
    string department;
    int teamSize;
public:
    // Gọi constructor của Employee qua initializer list
    Manager(string n, int a, int id, double s, string dept, int size)
        : Employee(n, a, id, s), department(dept), teamSize(size) {
        cout << "Manager ctor được gọi\n";
    }

    void display() const {
        cout << "\n--- THÔNG TIN MANAGER ---\n";
        cout << "Tên: " << name << "\nTuổi: " << age 
             << "\nID: " << employeeId << "\nLương: " << salary 
             << "\nPhòng ban: " << department << "\nSố thành viên nhóm: " << teamSize << "\n";
    }
};

int main() {
    Manager m("Nguyễn Văn A", 35, 1001, 2500.5, "IT", 10);
    m.display();
    return 0;
}
