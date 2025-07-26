class Solution {

    int vectortonum(vector<int> arr)
    {
        int number = 0;

        for(int i =0;i<3;i++)
        {
            number = number*10 + arr[i];
        }
        return number;

    }
    void findPermute(vector<int> &digits, vector<int> &ds,set<int> &evenDigits, vector<bool> &freq)
    {
        if(ds.size()==3)
        {
            if(ds[2]%2==0 && ds[0]!=0)
                evenDigits.insert(vectortonum(ds));
            
            return;
        }

        for(int i =0;i<digits.size();i++)
        {
            if(!freq[i])
            {
             freq[i]=true;
             ds.push_back(digits[i]);
             findPermute(digits,ds,evenDigits,freq);
             ds.erase(ds.end()-1);
             freq[i]=false;
            }
        }
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
      int n = digits.size();
      vector<bool> freq(n,false);
      vector<int> ds;
    
      set<int> evenDigits;

      findPermute(digits,ds,evenDigits,freq);
     

      return vector(evenDigits.begin(), evenDigits.end()) ;
    }
};