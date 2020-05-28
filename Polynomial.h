#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Polynomial{
private:
    vector <double> factor;

public:
    Polynomial();
    Polynomial(double a0);
    string name;
    void input();
    void output();
    Polynomial plus(Polynomial operand1, Polynomial operand2);
    Polynomial derivate(Polynomial operand);
    Polynomial multiplicate(Polynomial operand1, Polynomial operand2);
    double integral(double lower_limit, double upper_limit);
    double value(double x);
};
