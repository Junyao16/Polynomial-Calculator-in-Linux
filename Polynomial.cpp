#include<iostream>
#include<string>
#include<vector>
#include"Polynomial.h"

using namespace std;

Polynomial::Polynomial(vector<double> nums, string str){
    factor = nums;
    name = str;
}

Polynomial Polynomial::plus(Polynomial operand1, Polynomial operand2){
    return operand1;
}

Polynomial Polynomial::devirate(Polynomial operand){
    return operand;
}

Polynomial Polynomial::multiplicate(Polynomial operand1, Polynomial operand2){
    return operand1;
}

double Polynomial::integral(double upper_limit, double lower_limit, Polynomial operand){
    return 0;
}
