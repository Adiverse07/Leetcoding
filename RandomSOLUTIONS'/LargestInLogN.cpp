#include <bits/stdc++.h>
using namespace std;

int findlargest(const vector<int> &arr, int left,int right)
{
 if(left==right)
  {
    return arr[left];
  }

  int mid = left + (right-left) / 2;

  int leftmax = findlargest(arr,left, mid);
  int rightmax = findlargest(arr,mid+1,right);

  return max(leftmax,rightmax);
}

int main()
{
    vector<int> arr =  {2,3,6,1,4,8,10,9,2};
    int left = 0;
    int right = arr.size()-1;

    int maxEle =  findlargest(arr,left,right);

    cout<<maxEle;

}

   