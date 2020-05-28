#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include"mixed.h"
#include"control.h"
#include"Polynomial.h"

using namespace std;

extern vector<Polynomial> polynomial;

void mixed_control(){
    while(1){
        cout<<"Please input the expression:";
        string exp;
        cin>>exp;
        int judge_exp=judge(exp);
        if(judge_exp!=1){
            cout<<"WRONG EXPRESSION!Do you want to re-input?(y/n)";
            string tmp;
            cin>>tmp;
            if(tmp=="n")return;
            else continue;
        }
        else{
            string suffix_expr=suffix_exp(exp);
            cout<<suffix_expr;
            value(suffix_expr,exp);
            cout<<"SUCCEED! Do you want to continue calculation?(y/n)";
            string tmp;
            cin>>tmp;
            if(tmp=="n")return;
            else continue;
        }
    }


}

int judge(string exp){
   int len=exp.length();
   if(len==0)return 0;
   if(!((exp[0]>='A'&&exp[0]<='Z')||(exp[0]>='a'&&exp[0]<='z')||exp[0]=='('||exp[0]=='$'))return 0;
   if(!((exp[len-1]>='A'&&exp[len-1]<='Z')||(exp[len-1]>='a'&&exp[len-1]<='z')||exp[len-1]==')'||exp[len-1]=='!'))return 0;
   int l = 0;
   int r = 0;
   for(int i = 0; i < len; i++){
       if(exp[i]=='('){
           l++;
           if(i==len-1)return 0;
           if(!((exp[i+1]>='A'&&exp[i+1]<='Z')||(exp[i+1]>='a'&&exp[i+1]<='z')||exp[i+1]=='('||exp[i+1]=='$'))return 0;
       }
       if(exp[i]==')'){
           r++;
           if(i==len-1)break;
           else if(!(exp[i+1]==')'||exp[i+1]=='!'||exp[i+1]=='+'||exp[i+1]=='*'))return 0;
       }
       if(exp[i]=='+'||exp[i]=='*'){
           if(i==len-1)return 0;
           if(!((exp[i+1]>='A'&&exp[i+1]<='Z')||(exp[i+1]>='a'&&exp[i+1]<='z')||exp[i+1]=='('||exp[i+1]=='$'))return 0;
       }
       if(exp[i]=='!'){
           if(i==len-1)break;
           else if(!(exp[i+1]=='*'||exp[i+1]=='+'||exp[i+1]==')'))return 0;
       }
       if(exp[i]=='$'){
           if(i==len-1) return 0;
           if(exp[i+1]!='[')return 0;
           int j = i+2;
           for(;j<len;j++){
               if(exp[j]==']'){
                   if(!((exp[j+1]>='A'&&exp[j+1]<='Z')||(exp[j+1]>='a'&&exp[j+1]<='z')||exp[j+1]=='(')) return 0;
                   break;
               }
           }
           if(j==len)return 0;
           i=j;
       }
       if((exp[i]>='A'&&exp[i]<='Z')||(exp[i]>='a'&&exp[i]<='z')){
           if(i==len-1)break;
           else if(!((exp[i+1]>='A'&&exp[i+1]<='Z')||(exp[i+1]>='a'&&exp[i+1]<='z')||exp[i+1]==')'||exp[i+1]=='!'||exp[i+1]=='+'||exp[i+1]=='*'))return 0;
       }
   }
   if(l!=r)return 0;

   string name;

   for(int i=0;i<len;i++){
        if((exp[i]>='A'&&exp[i]<='Z')||(exp[i]>='a'&&exp[i]<='z'))name=name+exp[i];
        else if(name!="\0"){
            int j = 0;
            for(;j<polynomial.size();j++){
                if(name==polynomial[j].name)break;
            }
            if(j==polynomial.size())return 0;
            name="\0";
        }
   }
   return 1;
}

string suffix_exp(string exp){
    int len = exp.length();
    string n_exp;
    stack<string> operate;
    //string tmp;
    for(int i = 0;i<len;i++){
        if((exp[i]>='A'&&exp[i]<='Z')||(exp[i]>='a'&&exp[i]<='z'))n_exp+=exp[i];
        else{
            n_exp+=' ';
        }
        if(exp[i]=='('){
            string tmp; 
            tmp+=exp[i];
            operate.push(tmp);
        }
        else if(exp[i]=='+'){
            while(!operate.empty()&&operate.top()!="("){
                string tmp;
                tmp=operate.top();
                n_exp+=tmp;
                operate.pop();
            }
            string tmp;
            tmp+=exp[i];
            operate.push(tmp);
        }
        else if(exp[i]=='*'){
            while(!operate.empty()&&operate.top()!="("&&operate.top()!="+"){
                string tmp;
                tmp = operate.top();
                n_exp+=tmp;
                operate.pop();
            }
            string tmp;
            tmp+=exp[i];
            operate.push(tmp);
        }
        else if(exp[i]=='$'){
            string tmp;
            tmp+=exp[i];
            int j=i+1;
            while(exp[j]!=']'){
                tmp+=exp[j];
                j++;
            }
            tmp+=exp[j];
            while(!operate.empty()&&operate.top()!="("&&operate.top()!="+"&&operate.top()!="*"){
                string tmp;
                tmp = operate.top();
                n_exp+=tmp;
                operate.pop();
            }
            operate.push(tmp);
            i=j;
        
        }
        else if(exp[i]=='!'){
            string tmp;
            tmp+=exp[i];

            operate.push(tmp);
        }
        else if(exp[i]==')'){
            while(!operate.empty()&&operate.top()!="("){
                string tmp;
                tmp = operate.top();
                n_exp+=tmp;
                operate.pop();
            }
            operate.pop();
        }


    }
    while(!operate.empty()){
        string tmp;
        tmp=operate.top();
        
        n_exp+=tmp;
        n_exp+=" ";
        operate.pop();
    }
    return n_exp;
}

void value(string exp ,string orig){
    int len = exp.length();
    string operand,operate;
    Polynomial operand1,operand2;
    stack<Polynomial> operands;
    for(int i = 0; i < len;i++){
        if((exp[i]>='A'&&exp[i]<='Z')||(exp[i]>='a'&&exp[i]<='z')){
            operand+=exp[i];
        }
        else if(operand!="\0"){
            Polynomial tmp;
            for(int i=0;i<polynomial.size();i++){
                if(polynomial[i].name==operand)tmp = polynomial[i];
            }
            
            operands.push(tmp);
            operand="\0";

        }
        if(exp[i]=='+'||exp[i]=='*'||exp[i]=='!'||exp[i]=='$'){
            
            if(exp[i]=='+'){
                operand1=operands.top();
                operands.pop();
                operand2=operands.top();
                operands.pop();
                

                Polynomial ans = operand1.plus(operand1,operand2);
                operands.push(ans);
            }
            else if(exp[i]=='*'){
                operand1=operands.top();
                operands.pop();
                operand2=operands.top();
                operands.pop();

                Polynomial ans = operand1.multiplicate(operand1,operand2);
                operands.push(ans);
            }
            else if(exp[i]=='!'){
                operand1=operands.top();
                operands.pop();

                Polynomial ans = operand1.derivate(operand1);
                operands.push(ans);

            }
            else if(exp[i]=='$'){
                string lower,upper;
                double lower_limit=0,upper_limit=0;

                i=i+2;
                while(exp[i]!=','){
                    lower+=exp[i];
                    i++;
                }
                i++;
                while(exp[i]!=']'){
                    upper+=exp[i];
                    i++;
                }

                int i = 0;
                for(;i<lower.length();i++){
                    if(lower[i]!='.'){
                        int low= lower[i]-48;
                        lower_limit=lower_limit*10+low;
                    }
                    else{
                        break;
                    }
                }
                int tag= i;
                for(i=i+1;i<lower.length();i++){
                    int low =lower[i]-48;

                    for(int k = 0;k<i-tag;k++){
                        low=low*0.1;
                    }
                    lower_limit=lower_limit+low;
                }

                int j = 0;
                for(;j<upper.length();j++){
                    if(upper[j]!='.'){
                        int up= upper[j]-48;
                       
                        upper_limit=upper_limit*10+up;
                    }
                    else{
                        break;
                    }
                }
                tag= j;
                for(j=j+1;j<upper.length();i++){
                    int up =upper[i]-48;

                    for(int k = 0;k<i-tag;k++){
                        up=up*0.1;
                    }
                    upper_limit=upper_limit+up;
                }     

                operand1= operands.top();
                operands.pop();

                double ans = operand1.integral(lower_limit,upper_limit);

                Polynomial new_poly(ans);

                operands.push(ans);


            }
            

        }
    }

    cout<<orig<<"=";
    operands.top().output();

}

