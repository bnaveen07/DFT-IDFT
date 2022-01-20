//
// Created by Naveen on 17-12-2021.
//

#include <iostream>
#include <cmath>
#include<iomanip>
#define PI 3.14159265
using namespace std;


class calc{
    int N;
protected:float w,c[16],s[16],cDft[16],sDft[16];
public:
    //Constructor to initialize length N
    calc(int x){
        N=x;
        cout<<"Parent Constructor called 2"<<endl;
    }
    calc(){
        cout<<"Parent Constructor called 1"<<endl;
    }
    //Destructor to print message
    ~calc(){
        cout<<"Destructor called"<<endl;
    }
    //setting the real part co-efficients
    void setC(int n,float cn[]){
        for(int i=0;i<n;i++){
            c[i]=cn[i];
        }
    }
    //Setting the imaginary part co-efficients
    void setS(int n,float sn[]){
        for(int i=0;i<n;i++){
            s[i]=sn[i];
        }
    }
    friend class idft; //friend class IDFT
};

class dft: public calc{
public:
    dft(int x): calc(){
        cout<<"Child Constructor called"<<endl;
    }
    void calcDFT(int N){
        for(int k=0;k<N;k++){
            cDft[k]=0;
            sDft[k]=0;
            for(int j=0;j<N;j++){
                w=(2*PI*k*j)/N;
                cDft[k]+= (c[j] * cos(w) + s[j] * sin(w));
                sDft[k]+=(s[j] * cos(w) - c[j] * sin(w) );
            }
            cout<<setprecision(2);
            cout<<fixed<<cDft[k]<<" "<<fixed<<sDft[k]<<"i"<<endl;
        }
    }
};

class idft{
    public:
        void calcIDFT(calc &idft) {
            for (int k = 0; k < idft.N; k++) {
                idft.cDft[k]=0;
                idft.sDft[k]=0;
                for (int n = 0; n < idft.N; n++) {
                    idft.w = (-1) * (2 * PI * k * n) / idft.N;
                    idft.cDft[k] += (idft.c[n] * cos(idft.w) + idft.s[n] *sin(idft.w));
                    idft.sDft[k] += (idft.c[n]*sin(idft.w) - idft.s[n] * cos(idft.w)) ;
                }
                idft.cDft[k] /= idft.N;
                idft.sDft[k] /= idft.N;
                cout<<setprecision(2);
                cout << fixed<< idft.cDft[k] << " " <<fixed <<-idft.sDft[k]<<"i"<< endl;
            }
        }
};

