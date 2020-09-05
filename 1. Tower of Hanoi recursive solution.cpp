#include<bits/stdc++.h>
using namespace std;

void tower_of_hanoi(int n,char from,char aux,char to)
{

    if(n==1)
    {
        cout<<"Move Disk 1 From "<<from<<" to "<<to<<endl;
        return ;
    }
    else
    {
        tower_of_hanoi(n-1,from,to,aux);
        cout<<"Move Disk "<<n<<" from "<<from<<" to "<<to<<endl;
        tower_of_hanoi(n-1,aux,from,to);
    }

}

int main()
{

    int n;
    cout<<"Enter The Number of Disks : ";
    cin>>n;
    tower_of_hanoi(n,'R','A','I');
}
