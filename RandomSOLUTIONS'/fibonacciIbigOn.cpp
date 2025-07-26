#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter till what: ";
    cin>>n;

    if(n==1) cout<<0; 

    int prev = 0, curr =1;

    cout<<prev<<" "<<curr<<" ";

    for(int i = 2;i<n;i++)
    {
    int next = prev + curr;
    cout<<next<<" ";
    prev = curr;
    curr = next;
    }
}