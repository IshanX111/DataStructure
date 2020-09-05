#include<bits/stdc++.h>
using namespace std;
string stc[100];
int top=-1;
bool isOperand(char c)
{

    if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='1' && c<='9'))
    {

        return true;

    }
    else
    {

        return false;
    }

}
void push(string val)
{
    if(top>=99)
        cout<<"Stack Overflow"<<endl;
    else
    {
        top++;
        stc[top]=val;
    }
}
bool isEmpty()
{

    if(top>-1)
    {
        return false;
    }
    else
    {
        return true;
    }

}
void pop()
{
    if(top<=-1)
    {
        //cout<<"Stack Underflow"<<endl;
    }
    else
    {

        top--;
    }
}

string PostfixToInfix(string s)
{

    int i;
    int l=0;
    for(i=0; s[i]!='\0'; i++)
    {
        l++;
    }

    for(i=0; i<l; i++)
    {
        if(isOperand(s[i]))
        {
            string x="";
            x+=s[i];
            push(x);
        }
        else
        {
            string x1=stc[top];
            pop();
            string x2=stc[top];
            pop();
            push("("+x2+s[i]+x1+")");

        }

    }
    return stc[top];
}
int main()
{

    string x;
    cout<<"Enter Postfix Expression : ";
    cin>>x;
    string y=PostfixToInfix(x);
    cout<<"The Infix Expression is : "<<y<<endl;

}

