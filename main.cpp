#include <iostream>

#include "dft.cpp"
#define PI 3.14159265

/*Concepts Used are:
Classes
Objects
Inheritance
Polymorphism
Abstraction
Encapsulation
Friend Class
Constructor
Destructor*/

int main(){
    int choice,n;
    float x[100],y[100];
    cout<<"Enter 0 for DFT"<<endl;
    cout<<"Enter 1 for IDFT"<<endl;
    cin>>choice;
    if(choice >=2) {
        cout << "Invaild Choice" << endl;
        return 0;
    }
    cout<<"Enter the length of Signal N = "<<endl;
    cin>>n;
    calc calc_obj(n);
    idft idft_obj;
    dft dft(n);
    cout<<"Enter the Signal real part coefficients"<<endl;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    cout<<"Enter the signal imaginary co-efficients"<<endl;
    for(int i=0;i<n;i++){
        cin>>y[i];
    }
    if(choice==0){
        dft.setC(n,x);
        dft.setS(n,y);
        dft.calcDFT(n);
    }
    else if(choice==1){
      calc_obj.setC(n,x);
       calc_obj.setS(n,y);
        idft_obj.calcIDFT(calc_obj);
    }
    else{
        cout<<"Invalid Choice"<<endl;
    }
    return 0;
};
