#include<iostream>
using namespace std;
class myclass{
    public:
    myclass(int x){
        int sq=x*x;
        cout<<"square of number is"<<sq<<endl;
    }
    myclass(int x,int y){
        int area=x*y;
        cout<<"Area of rectangle "<<area<<endl;
    }
    myclass(float radius){
        float area=3.14*radius*radius;
        cout<<"area of circle "<< area<<endl;
    }
    ~myclass(){
        cout<<"destructor bein called"<<endl;
    }
};
class student{
    public:
    student(string name,int age, char grade){
        cout<<name<<"\n"<<age<<"\n"<<grade<<endl;
    }
};
int main(){
    string a="Nikhil";
    myclass obj(2);
    student obj1(a,21,'A');
    return -1;
}
