#include <iostream>
#include <string>
using namespace std;

class student {
private:
    string name;
    int id;
    int size;
    float *grades;

public:
    student() {
        name = "";
        id = 0;
        size = 0;
        grades = nullptr;
    }

    student(string n, int a, int s) {
        name = n;
        id = a;
        size = s;
        grades = new float[size];
    }

    student(const student &s) {
        name = s.name;
        id = s.id;
        size = s.size;
        grades = new float[size];
        for (int i = 0; i < size; i++)
            grades[i] = s.grades[i];
    }

    void setName(string n) {
         name = n; 
    }
    void setid(int a) { 
        id = a; 
    }
    void setSize(int s) { 
        size = s; grades = new float[size]; 
    }

    void setGrades(float *g) {
        for (int i = 0; i < size; i++)
            grades[i] = g[i];
    }

    string getName() { return name; }
    int getid() { return id; }
    int getSize() { return size; }
    float *getGrades() { return grades; }
};

int main() {
    student s("ali", 20, 5);
    float g[5] = {90.5, 85.0, 77.5, 92.0, 80.0};
    s.setGrades(g);

    student s2(s);

    cout << "s id: " << s.getid() << endl;
    cout << "s name: " << s.getName() << endl;

    cout << "s2 id: " << s2.getid() << endl;
    cout << "s2 name: " << s2.getName() << endl;

    return 0;
}
