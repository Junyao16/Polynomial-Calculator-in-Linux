#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Polynomial{
private:
    vector <double> factor;
    string name;
public:
    
    Polynomial plus(Polynomial operand1, Polynomial operand2);
    Polynomial devirate(Polynomial operand);
    Polynomial multiplicate(Polynomial operand1, Polynomial operand2);
    double integral(double upper_limit, double lower_limit, Polynomial operand);
};
