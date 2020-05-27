#include<iostream>

#include<string>
#include"Polynomial.h"
#include"mixed.h"

using namespace std;

//a new vector to save polynomials
vector<Polynomial>polynomial;

int control(){
   

    while(1){
    //print the surface
        cout << "===========================Polynomial Calculator===========================" <<endl;
        cout << "1.input polynomial 2.mixed calculation 3.display polynomial 4.exit " <<endl;
        cout << "Please choose:";
    
        string action;
        cin >> action;
        if(action=="1"){
            //A
            A:Polynomial new_poly;
            new_poly.input();
            polynomial.push_back(new_poly);
            cout<<"SUCCEED!Do you want to continue?(y/n)";
           
            string tmp;
            cin>>tmp;
            if(tmp=="n")continue;
            else goto A;
            

        }
        if(action=="2"){
            mixed_control();
        }
        if(action=="3"){
            //B
            B:cout<<"Please input the name of the polynomial you want to display:";
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
            cout<<"Do you want to continue?(y/n)";
           
            string tmp;
            cin>>tmp;
            if(tmp=="n")continue;
            else goto B;
        }
        if(action=="4"){
            return 0;
        }
        
    }
    return 0;
}
