#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


class Solution {
public:
    template<typename Bidirectional_iterator>
    void reverse(Bidirectional_iterator first , Bidirectional_iterator last)
    {
        while(first!=last && first!=--last)
        {
            iter_swap(first, last);
            first++;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if(n==1) return;
        k=k%n;
        reverse(nums.begin(),nums.begin()+(n-k));
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};

int main() {
    Solution sl;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    sl.rotate(nums, k);

    for (int num : nums)
        cout << num << " ";

    return 0;
}