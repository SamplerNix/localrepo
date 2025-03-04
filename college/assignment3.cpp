#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Section 1: Inheritance and Types of Inheritance

// 1. Single Inheritance
// A.
class Employee {
protected:
    string name;
    int id;
    double salary;

public:
    Employee(string name, int id, double salary) {
        this->name = name;
        this->id = id;
        this->salary = salary;
    }
};

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string name, int id, double salary, double bonus) : Employee(name, id, salary) {
        this->bonus = bonus;
    }

    double getTotalSalary() {
        return salary + bonus;
    }

    void displayDetails() {
        cout << "Manager Name: " << name << ", ID: " << id << ", Total Salary: " << getTotalSalary() << endl;
    }
};

// B.
class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

class Student : public Person {
private:
    int studentId;
    string course;

public:
    Student(string name, int age, int studentId, string course) : Person(name, age) {
        this->studentId = studentId;
        this->course = course;
    }

    void displayDetails() {
        cout << "Student Name: " << name << ", Age: " << age << ", ID: " << studentId << ", Course: " << course << endl;
    }
};

class Teacher : public Person {
private:
    int teacherId;
    string subject;

public:
    Teacher(string name, int age, int teacherId, string subject) : Person(name, age) {
        this->teacherId = teacherId;
        this->subject = subject;
    }

    void displayDetails() {
        cout << "Teacher Name: " << name << ", Age: " << age << ", ID: " << teacherId << ", Subject: " << subject << endl;
    }
};

// C.
class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accountNumber, double balance) {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    void displayBalance() {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string accountNumber, double balance) : BankAccount(accountNumber, balance) {}

    void calculateInterest(double rate) {
        balance += balance * rate;
    }
};

// 2. Multilevel Inheritance
// A.
class GraduateStudent : public Student {
private:
    string thesisTitle;

public:
    GraduateStudent(string name, int age, int studentId, string course, string thesisTitle)
        : Student(name, age, studentId, course) {
        this->thesisTitle = thesisTitle;
    }

    void displayDetails() {
        Student::displayDetails();
        cout << "Thesis Title: " << thesisTitle << endl;
    }
};

// B.
class Animal {
public:
    void eat() {
        cout << "Animal is eating." << endl;
    }
};

class Mammal : public Animal {
public:
    void walk() {
        cout << "Mammal is walking." << endl;
    }
};

class Dog : public Mammal {
public:
    void bark() {
        cout << "Dog is barking." << endl;
    }
};

// 3. Multiple Inheritance
// A.
class Sports {
protected:
    string sportName;
    int score;

public:
    Sports(string sportName, int score) {
        this->sportName = sportName;
        this->score = score;
    }
};

class Academics {
protected:
    string subject;
    int marks;

public:
    Academics(string subject, int marks) {
        this->subject = subject;
        this->marks = marks;
    }
};

class StudentPerformance : public Sports, public Academics {
public:
    StudentPerformance(string sportName, int score, string subject, int marks)
        : Sports(sportName, score), Academics(subject, marks) {}

    int getTotalPerformance() {
        return score + marks;
    }

    void displayDetails() {
        cout << "Sport: " << sportName << ", Score: " << score << ", Subject: " << subject << ", Marks: " << marks
             << ", Total Performance: " << getTotalPerformance() << endl;
    }
};

// B.
class Employee2 {
protected:
    int employeeId;
    double salary;

public:
    Employee2(int employeeId, double salary) {
        this->employeeId = employeeId;
        this->salary = salary;
    }
};

class Manager2 : public Employee2, public Person {
private:
    string department;

public:
    Manager2(string name, int age, int employeeId, double salary, string department)
        : Person(name, age), Employee2(employeeId, salary) {
        this->department = department;
    }

    void displayDetails() {
        cout << "Manager Name: " << name << ", Age: " << age << ", ID: " << employeeId << ", Salary: " << salary
             << ", Department: " << department << endl;
    }
};

// 4. Hierarchical Inheritance
class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(string brand, int year) {
        this->brand = brand;
        this->year = year;
    }

    void displayDetails() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

class Car : public Vehicle {
private:
    string fuelType;

public:
    Car(string brand, int year, string fuelType) : Vehicle(brand, year) {
        this->fuelType = fuelType;
    }

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Bike : public Vehicle {
private:
    int engineCC;

public:
    Bike(string brand, int year, int engineCC) : Vehicle(brand, year) {
        this->engineCC = engineCC;
    }

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Engine CC: " << engineCC << endl;
    }
};

// 5. Hybrid Inheritance
// A.
class Vehicle2 {
protected:
    string brand;
    int speed;

public:
    Vehicle2(string brand, int speed) {
        this->brand = brand;
        this->speed = speed;
    }
};

class Car2 : public Vehicle2 {
protected:
    int numDoors;

public:
    Car2(string brand, int speed, int numDoors) : Vehicle2(brand, speed) {
        this->numDoors = numDoors;
    }
};

class Bike2 : public Vehicle2 {
protected:
    bool hasGear;

public:
    Bike2(string brand, int speed, bool hasGear) : Vehicle2(brand, speed) {
        this->hasGear = hasGear;
    }
};

class SportsCar : public Car2, public Bike2 {
public:
    SportsCar(string brand, int speed, int numDoors, bool hasGear)
        : Car2(brand, speed, numDoors), Bike2(brand, speed, hasGear) {}

    void turboMode() {
        cout << "Turbo mode activated!" << endl;
    }
};

// B.
class TeachingAssistant : public Student, public Teacher {
public:
    TeachingAssistant(string name, int age, int studentId, string course, int teacherId, string subject)
        : Student(name, age, studentId, course), Teacher(name, age, teacherId, subject){}

    void displayDetails() {
        Student::displayDetails();
        Teacher::displayDetails();
    }
};

// Section 2: Dynamic Polymorphism and Virtual Functions

// 6. Virtual Function for Method Overriding
class Shape {
public:
    virtual double area() {
        return 0;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) {
        this->radius = radius;
    }

    double area() override {
        return M_PI * pow(radius, 2);
    }
};

class Rectangle : public Shape {
private:
    double length;
    double breadth;

public:
    Rectangle(double length, double breadth) {
        this->length = length;
        this->breadth = breadth;
    }

    double area() override {
        return length * breadth;
    }
};

int main() {
    Manager m("John", 101, 50000, 5000);
    m.displayDetails();

    Student s("Alice", 20, 123, "Physics");
    s.displayDetails();

    Teacher t("Mr. Smith", 40, 456, "Math");
    t.displayDetails();

    BankAccount b("A12345", 1000);
    b.deposit(500);
    b.displayBalance();

    SavingsAccount sa("S12345", 2000);
    sa.calculateInterest(0.05);
}
