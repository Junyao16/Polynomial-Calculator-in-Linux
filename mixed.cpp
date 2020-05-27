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
            value(suffix_expr);
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
           if(i=len-1)return 0;
           if(!((exp[i+1]>='A'&&exp[i+1]<='Z')||(exp[i+1]>='a'&&exp[i+1]<='z')||exp[i+1]=='('||exp[i+1]=='$'))return 0;
       }
       if(exp[i]==')'){
           r++;
           if(i=len-1)break;
           else if(!(exp[i+1]==')'||exp[i+1]=='!'||exp[i+1]=='+'||exp[i+1]=='*'))return 0;
       }
       if(exp[i]=='+'||exp[i]=='*'){
           if(i=len-1)return 0;
           if(!((exp[i+1]>='A'&&exp[i+1]<='Z')||(exp[i+1]>='a'&&exp[i+1]<='z')||exp[i+1]=='('||exp[i+1]=='$'))return 0;
       }
       if(exp[i]=='!'){
           if(i=len-1)break;
           else if(!(exp[i+1]=='*'||exp[i+1]=='+'||exp[i+1]==')'))return 0;
       }
       if(exp[i]=='$'){
           if(i=len-1) return 0;
           if(exp[i+1]!='[')return 0;
           int j = i+2;
           for(;j<len;j++){
               if(exp[j]==']'){
                   if(!((exp[i+1]>='A'&&exp[i+1]<='Z')||(exp[i+1]>='a'&&exp[i+1]<='z')||exp[j+1]=='(')) return 0;
                   break;
               }
           }
           if(j==len)return 0;
           i=j;
       }
       if((exp[i]>='A'&&exp[i]<='Z')||(exp[i]>='a'&&exp[i]<='z')){
           if(!((exp[i+1]>='A'&&exp[i+1]<='Z')||(exp[i+1]>='a'&&exp[i+1]<='z')||exp[i+1]==')'||exp[i+1]=='!'||exp[i+1]=='+'||exp[i+1]=='*'))return 0;
       }
   }
   if(l!=r)return 0;

   string name;

   for(int i=0;i<len;i++){
        if((exp[i]>='A'&&exp[i]<='Z')||(exp[i]>='a'&&exp[i]<='z'))name=name+exp[i];
        else{
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
        else if(exp[i]=='('){
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
    return n_exp;
}

void value(string exp){

}

