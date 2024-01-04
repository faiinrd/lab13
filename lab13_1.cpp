#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sumAM=0;
    for(int i=0;i<N;i++){
        sumAM+=A[i];
        B[0] = sumAM/N;
    }

    double sumSD=0;
    for(int i=0;i<N;i++){
        sumSD+=pow(A[i]-B[0],2);
        B[1] = sqrt(sumSD/N);
    }

    double sumGM=1;
    for(int i=0;i<N;i++){
        sumGM*=A[i];
        B[2] = pow(sumGM,1.0/N);
    }

    double sumHM=0;
    for(int i=0;i<N;i++){
        sumHM+=1/A[i];
        B[3] = N/sumHM;
    }

    double max=0;
    for(int i=0;i<N;i++){
        if(A[i]>max){
            max=A[i];
        }
        B[4]=max;
    }
    
    double min=A[0];
    for(int i=0;i<N;i++){
        if(A[i]<min){
            min=A[i];
        }
        B[5]=min;
    }
}
