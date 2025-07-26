#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool canAssign(int &mid, vector<int> &workers, vector<int> &tasks , int pills, int strength)
    {
        multiset<int> usable_workers(workers.end()-mid, workers.end());

        for (int i = mid-1;i>=0;i--) // iterating the weakest task, which are first n tasks
        {
            auto curr_worker = --usable_workers.end(); // will return a pointer to last worker + 1, then decrement to point it last worker

            if(*curr_worker < tasks[i])
            {
                if(pills <= 0) return false;


                //optimal strategy:  who to give pills to?
                // we must give pill to the weakest worker who can complete the task
                // he will require at least task-strength strength already // so lower_bound it

                auto weakest_worker = usable_workers.lower_bound(tasks[i]-strength);

                if(weakest_worker == usable_workers.end()) // no one can do the task even after taking the pill
                    return false;

                pills--;

                usable_workers.erase(weakest_worker);
            }
            else
            usable_workers.erase(curr_worker); //if the curr worker can do it without pills
        }

        return true;
        

    }
    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            sort(workers.begin(),workers.end());
            sort(tasks.begin(),tasks.end());

            int low = 0;
            int high =  min(tasks.size(),workers.size());
            int mid;

            int assigned = 0;

            while(low<=high)
            {
                mid = low+(high-low)/2;

                if(canAssign(mid,workers,tasks,pills,strength))
                {
                    assigned = mid;
                    low = mid+1;
                }
                else{
                    high = mid -1;
                }

            }
            return assigned;
        }
    };

int main()
{
    vector<int> tasks = {3,2,1};
    vector<int> workers = {0,3,3};
    int pills = 1;
    int strength = 1;
    Solution sl;

    cout<<sl.maxTaskAssign(tasks,workers,pills,strength);


}