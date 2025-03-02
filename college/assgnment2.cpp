#include <iostream>
#include <string>
using namespace std;

// 1. Understanding Classes and Objects
class Student {
public:
    string name;
    int age;
    char grade;

    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }
};

// 2. Constructors and Destructors
class Car {
public:
    string brand;
    string model;
    int year;

    Car(string b, string m, int y)  
    {
        brand=b;
        model=m;
        year=y;
        cout << "Car constructed: " << brand << " " << model << endl;
    }

    ~Car() {
        cout << "Car destroyed: " << brand << " " << model << endl;
    }
};

// 3. Dynamic Memory Allocation (new and delete)
class Book {
public:
    string title;
    double price;

    Book(string t, double p){
        title=t;
        price=p; 
    }

    void display() {
        cout << "Title: " << title << ", Price: " << price << endl;
    }
};

// 4. Function Overloading
class MathOperations {
public:
    int add(int a, int b) { 
        return a + b;
         }
    double add(double a, double b) { 
        return a + b; }
    string add(string a, string b) { 
        return a + b; }
};

// 5. Friend Function
class Rectangle {
private:
    int length;
    int width;

public:
    Rectangle(int l, int w){
        length=l;
        width=w;
    }

    friend int calculateArea(const Rectangle& rect);
};

int calculateArea(const Rectangle& rect) {
    return rect.length * rect.width;
}

// 6. Static Member Function
class Counter {
private:
    static int count;

public:
    Counter() { count++; }
    static int getCount() { return count; }
};

int Counter::count = 0;

// 7. Operator Overloading (+ Operator)
class Complex {
public:
    double real;
    double imaginary;

    Complex(double r, double i){
        real=r;
        imaginary=i;
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
};

// 8. Operator Overloading (== Operator)
class Point {
public:
    int x;
    int y;

    Point(int x, int y){
        this->x=x;
        this->y=y;
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// 9. Overloading Unary ++ Operator
class Counter2 {
public:
    int value;

    Counter2(int val) : value(val) {}

    Counter2 operator++() { // Pre-increment
        ++value;
        return *this;
    }

    Counter2 operator++(int) { // Post-increment
        Counter2 temp = *this;
        value++;
        return temp;
    }
};

// 10. Constructor Overloading
class Person {
public:
    string name;
    int age;

    Person() : name("Unknown"), age(0) {}
    Person(string n) : name(n), age(0) {}
    Person(string n, int a) : name(n), age(a) {}
};

// 11. Friend Function with Two Classes
class ClassB; // Forward declaration

class ClassA {
private:
    int a;

public:
    ClassA(int val){
        a=val;
    }
    friend int sumObjects(const ClassA& objA, const ClassB& objB);
};

class ClassB {
private:
    int b;

public:
    ClassB(int val){
        b=val;
    }
    friend int sumObjects(const ClassA& objA, const ClassB& objB);
};

int sumObjects(const ClassA& objA, const ClassB& objB) {
    return objA.a + objB.b;
}

// 12. Operator Overloading (<< and >> for Input/Output Stream)
class Time {
public:
    int hours;
    int minutes;

    friend ostream& operator<<(ostream& os, const Time& time);
    friend istream& operator>>(istream& is, Time& time);
};

ostream& operator<<(ostream& os, const Time& time) {
    os << time.hours << ":" << time.minutes;
    return os;
}

istream& operator>>(istream& is, Time& time) {
    is >> time.hours >> time.minutes;
    return is;
}

int main() {
    // 1. Student
    Student student;
    student.name = "Alice";
    student.age = 20;
    student.grade = 'A';
    student.displayDetails();

    // 2. Car
    {
        Car car1("Toyota", "Camry", 2020);
    }
    Car car2("Honda", "Civic", 2021);

    // 3. Book
    Book* book = new Book("Cpp book", 20.00);
    book->display();
    delete book;

    // 4. MathOperations
    MathOperations math;
    cout << math.add(1, 2) << endl;
    cout << math.add(1.5, 2.5) << endl;
    cout << math.add("Hello, ", "World!") << endl;

    // 5. Rectangle
    Rectangle rect(5, 10);
    cout << "Area: " << calculateArea(rect) << endl;

    // 6. Counter
    Counter c1, c2, c3;
    cout << "Counter: " << Counter::getCount() << endl;

    // 7. Complex
    Complex comp1(1.0, 2.0), comp2(3.0, 4.0);
    Complex sum = comp1 + comp2;
    cout << "Complex sum: " << sum.real << " + " << sum.imaginary << "i" << endl;

    // 8. Point
    Point p1(1, 2), p2(1, 2), p3(3, 4);
    cout << "p1 == p2: " << (p1 == p2) << ", p1 == p3: " << (p1 == p3) << endl;

    // 9. Counter2
    Counter2 count1(5);
    cout << "Pre-increment: " << (++count1).value << endl;
    cout << "Post-increment: " << (count1++).value << endl;
    cout << "Value: " << count1.value << endl;

    // 10. Person
    Person person1;
    Person person2("Bob");
    Person person3("Charlie", 30);
    cout << person1.name << ", " << person1.age << endl;
    cout << person2.name << ", " << person2.age << endl;
    cout << person3.name << ", " << person3.age << endl;

    // 11. Friend Function with Two Classes
    ClassA a(10);
    ClassB b(20);
    cout << "Sum: " << sumObjects(a, b) << endl;

    // 12. Time
    Time time1;
    cout << "Enter time (hours minutes): ";
    cin >> time1;
    cout << "Time: " << time1 << endl;

    return 0;
}