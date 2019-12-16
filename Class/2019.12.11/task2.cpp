#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

//помощна функция за пресмятане спрямо операцията
int evaluate(int x, int y, char op){
   if(op=='+')return x+y;
   return x*y;
}

//функция, пресмятаща израза
int calculate(char* a){
    //result - досегашния резултат; x - текущо число
    //op - поредна операция
    int result=0, x=0;
    char op='+';
    //докато не срещнем край на израза
    //(край на низа или затваряща скоба)
    while(a[0]!='\0' && a[0]!=')'){
        //ако срещнем число
        if(a[0]>='0' && a[0]<='9'){
            //го запазваме
            x=atoi(a);
            //подминаваме
            while(a[1]!='\0' && a[1]>='0' && a[1]<='9')a++;
            //и пресмятаме резултата
            result = evaluate(result, x, op);
        }
        //ако срещнем отваряща скоба, т.е. нов израз
        else if(a[0]=='('){
            //го пресмятаме
            x = calculate(a+1);
            //подминаваме
            while(a[0]!=')')a++;
            //и пресмятаме резултата
            result = evaluate(result, x, op);
        }
        //ако срещнем операция, я запазваме
        else op=a[0];
        //контролно извеждане
        //cout<<"result="<<result<<endl;
        //преминаваме към следващ символ
        a++;
    }
    return result;
}


int main(){
    char a[128];
    cin>>a;
    cout<<calculate(a)<<endl;


    return 0;
}