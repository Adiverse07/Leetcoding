#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector< vector<int>> arr(6,vector<int>(6,0));
    int totalsum = 0;
    for(int i =0;i<6;i++)
    {
        for(int j =0;j<6;j++)
        {
            arr[i][j] =1;
        }
    }

   for(int i =0;i<6;i++)
    {
        for(int j =0;j<6;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    

    for(int i =0;i<6-2;i++)
    {
        for(int j =0;j<6-2;j++)
        {
            int hgsum = (arr[i][j] + arr[i][j+1] +arr[i][j+2]) + arr[i+1][j+1] + (arr[i+2][j] + arr[i+2][j+1]+arr[i+2][j+2]);
            if(totalsum<hgsum)
            totalsum = hgsum;
        }
    }

    cout<<endl<<totalsum;
}