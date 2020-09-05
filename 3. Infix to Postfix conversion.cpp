#include<bits/stdc++.h>
using namespace std;
char stc[100],top=-1;
void push(char val)
{
    if(top>=99)
    {
        //cout<<"Stack Overflow"<<endl;
    }
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

int defining_precedence(char ch)
{

    if(ch=='^')
    {
        return 4;
    }
    else if(ch=='*' || ch=='/')
    {
        return 3;
    }

    else if(ch=='+' || ch=='-')
    {
        return 2;
    }

    else if(ch=='(')
    {
        return 1;
    }
}

int main()
{
    string s;
    string s1="";
    int i;
    getline(cin,s);
    int l=0;
    ///for checking the size of the string
    for(i=0; s[i]!='\0'; i++)
    {
        l++;
    }
    for(i=0; i<l; i++)
    {
        if(s[i]=='(')
        {
            push(s[i]);
        }
        else if((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z') ||(s[i]>='a' && s[i]<='z'))
        {
            s1+=s[i];
        }
        else if(s[i]=='^' || s[i]=='+' ||s[i]=='-' ||s[i]=='*' ||s[i]=='/' )
        {

            if(isEmpty())
            {
                push(s[i]);
            }
            else
            {
                int check=defining_precedence(stc[top]);
                int check1=defining_precedence(s[i]);
                if(check1>check)
                {
                    push(s[i]);
                }
                else
                {
                    while(check>check1)
                    {
                        s1+=stc[top];
                        pop();
                        if(isEmpty())
                        {
                            break;
                        }
                        check=defining_precedence(stc[top]);

                    }
                    push(s[i]);

                }

            }
        }
        else if(s[i]==')')
        {

            while(stc[top]!='(')
            {

                char ch1=stc[top];
                s1+=ch1;
                pop();

            }
            pop();
        }
        else if(s[i]==' ')
        {
            continue;
        }
    }
    while(!isEmpty())
    {
        s1+=stc[top];
        pop();
    }
    cout<<s1<<endl;

}

