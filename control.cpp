#include<iostream>

#include<string>
#include"Polynomial.h"

using namespace std;

int control(){
    //a new vector to save polynomials
    vector<Polynomial>polynomial;


    while(1){
    //print the surface
        cout << "===========================Polynomial Calculator===========================" <<endl;
        cout << "1.input polynomial 2.mixed calculation 3.display polynomial 4.exit " <<endl;
        cout << "Please choose:";
    
        string action;
        cin >> action;
        if(action=="1"){
            Polynomial new_poly;
            new_poly.input();
            polynomial.push_back(new_poly);
        }
        if(action=="2"){
        }
        if(action=="3"){
            cout<<"Please input the name of the polynomial you want to display:";
            string name;
            cin>>name;
            int i = 0;
            for(; i < polynomial.size();i++){
                if(polynomial[i].name==name){
                    polynomial[i].output();
                    break;
                }
            }
            if(i==polynomial.size()){
                cout<<"There is not a polynomial called "<<name<<"."<<endl;
            }
        }
        if(action=="4"){
            return 0;
        }
    }
    return 0;
}
