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
class functionoverloading{
    public:
void add(int x){
    int b=x++;
    cout<<"when number added to it's increament"<<x+b;
}
void add(float x,int a){
    float result=x+a;
    cout<<"This will print floating and integer sum"<<result<<endl;
}
void add(float x,float y){
    float sum=x+y;
    cout<<"sum of two floating numbe is :"<<sum<<endl;
}
};

int main(){
    string a="Hackor";
    myclass obj(2);
    student obj1(a,21,'A');
    functionoverloading obj2;
    obj2.add(2.3,5);
    return -1;
}
