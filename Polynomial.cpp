#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include"Polynomial.h"

using namespace std;

void Polynomial::output(Polynomial poly){//output one specific polynomial
    int r = poly.factor.size();
    for(int i = 0; i < poly.factor.size(); i++){
        if(fabs(poly.factor[i])<=1e-10){
            continue;
        }
        else if(fabs(poly.factor[i]-1)<=1e-10){
            if(i==0){
                cout<<"x^"<<r-i-1;;
            }
            else{
                cout<<"+x^"<<r-i-1;
            }
        }
        else if(fabs(poly.factor[i]+1)<=1e-10){
            cout<<"-x^"<<r-i-1;
        }
        else{
            if(i==0){
                printf("%g",poly.factor[i]);
                cout<<"x^"<<r-i-1;
            }
            else if(poly.factor[i]<0){
                printf("%g",poly.factor[i]);
                cout<<"x^"<<r-i-1;
            }
            else {
                cout<<"+";
                printf("%g",poly.factor[i]);
                cout<<"x^"<<r-i-1;
            }

        }
    }


}

Polynomial Polynomial::plus(Polynomial operand1, Polynomial operand2){
    Polynomial new_poly;
    int m = operand1.factor.size();
    int n = operand2.factor.size();
    for(int i = 0; i < m && i < n; i++){
        double adder = operand1.factor[m-1-i]+operand2.factor[n-1-i];
        new_poly.factor.insert(new_poly.factor.begin(),adder);
    }
    if(m<n){
        for(int i=0; i<n-m; i++){
            new_poly.factor.insert(new_poly.factor.begin(),operand2.factor[n-m-i-1]);
        }
    }
    if(m>n){
        for(int i = 0; i <m-n;i++){
            new_poly.factor.insert(new_poly.factor.begin(),operand1.factor[m-n-i-1]);
        }
    }
    return new_poly;
}

Polynomial Polynomial::devirate(Polynomial operand){
    Polynomial new_poly;
    int r = operand.factor.size();
    for(int i=0;i<r-1;i++){
        double new_fac=operand.factor[i]*(r-1-i);
        new_poly.factor.push_back(new_fac);
    }

    return new_poly;
}

Polynomial Polynomial::multiplicate(Polynomial operand1, Polynomial operand2){


    return operand1;
}

double Polynomial::integral(double upper_limit, double lower_limit, Polynomial operand){
    return 0;
}
