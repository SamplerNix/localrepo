#include<iostream>
#include<vector>
using namespace std;
class pattern{
    public:
    void pattern1(int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    void pattern2(int n){
        for (int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                cout<< j<<" ";
            }
            cout<<endl;
        }
    }
    void pattern3(int n){
        for(int i=0;i<n;i++){
            for(char j='a';j<='c';j++){
                cout<< j<<" ";
            }
            cout<<endl;
        }
    }
void pattern4(int n){
    for(int i=0;i<=n;i++){
    for(int j=0;j<=i;j++){
        cout<<i<<" ";
    }
    cout<<endl;
}
}
void pattern5(int n){
    for(int i=0;i<=n;i++){
    for(int j=5;j>=i;j--){
        cout<<"*"<<" ";
    }
    cout<<endl;
}
}
void pattern6(int n){
    for(int i=0;i<=n;i++){
    for(int j=i;j>=0;j--){
        cout<<j<<" ";
    }
    cout<<endl;
}
}
};
class d2{
    public:
    void arrays(){
        int rsum=0;
        int csum=0;
        int as[2][3]={{1,2,3},{4,5,6}};
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                rsum+=as[i][j];
            }
            cout<<rsum<<" ";
            rsum=0;
        }
    }
};
int main(){
    pattern obj;
    d2 obj2;
    obj2.arrays();
    // obj.pattern1(5);
    // obj.pattern2(5);
    // obj.pattern3(3);
    // obj.pattern4(5);
    // obj.pattern5(5);
    // obj.pattern6(5);
}