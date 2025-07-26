#include <bits/stdc++.h>
using namespace std;

class Solution {
    #define pii pair<int,int>

    bool countLineIntersection(vector<pii> &coordinates)
    {
        int lines = 0;
        int overlap =0;

        for(int i = 0;i<coordinates.size();i++)
        {
            if(coordinates[i].second==0) overlap--;
            else
            overlap++;

            if(overlap==0)
            lines++;

        }

        return lines>=3;
    }

    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {

            vector<pii> x_coordinates, y_coordinates;


            for(auto &rectangle : rectangles)
            {
                y_coordinates.push_back(make_pair(rectangle[1],1));
                y_coordinates.push_back(make_pair(rectangle[3],0));
                x_coordinates.push_back(make_pair(rectangle[0],1));
                x_coordinates.push_back(make_pair(rectangle[2],0));
            }

            sort(y_coordinates.begin(),y_coordinates.end());
            sort(x_coordinates.begin(), x_coordinates.end());
            
        return (countLineIntersection(y_coordinates) or countLineIntersection(x_coordinates));
    }
    
};

int main()
{
    Solution sl;
    int n = 5;

    vector<vector<int>> rectangles = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};

    if(sl.checkValidCuts(n,rectangles)) cout<<"true";
    else cout<<"false";


}