#include <bits/stdc++.h>
using  namespace std;

void nameprint(int &n,string &name)
{
    if(n==0)
    return;

    cout<<name<<endl;
    
    nameprint(n,name);
    n--;
}

int main()
{
    string name;
cout<<"Enter the name: ";
cin>>name;
int n;
cout<<"Enter the iterations: ";
cin>>n;

nameprint(n,name);

}