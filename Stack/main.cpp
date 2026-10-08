#include <iostream>
using namespace std;

class Person {
    private:
    string name;
    int age;
    int id;
    float salary;
    public:
    Person(){
        salary=1000;
    }

    // overload constructor
    Person(float s){
        salary=s;
    }

    // copey constructor
    Person(const Person &p){
        name=p.name;
        age=p.age;
        id=p.id;
        salary=p.salary;
    }

    void setName(string n){
        name=n;
    }

    void setAge(int a){
        age=a;
    }

    void setId(int i){
        id=i;
    }

    void setSalary(float s){
        salary=s;
    }

    string getName() {
    return name;
    }
    int getAge() {
        return age;
    }
    int getId() {
        return id;
    }
    float getSalary() {
        return salary;
    }

};

int main() {
   
    Person p;
    Person p1;


    p.setName("ali");
    p.setAge(20);
    p.setId(1);
    p.setSalary(2000);
        Person p2(p);

    cout<<"p id: "<<p.getId()<<endl;
    cout<<"p name: "<<p.getName()<<endl;
    cout<<"p age: "<<p.getAge()<<endl;
    cout<<"p salary: "<<p.getSalary()<<endl;
    
    cout<<"p2 id: "<<p2.getId()<<endl;
    cout<<"p2 name: "<<p2.getName()<<endl;
    cout<<"p2 age: "<<p2.getAge()<<endl;
    cout<<"p2 salary: "<<p2.getSalary()<<endl;


   // p2.setName("mohamed");
 //   cout<<"p2 name: "<<p2.getName()<<endl;

    return 0;
}

