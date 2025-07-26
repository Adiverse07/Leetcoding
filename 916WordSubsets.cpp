#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Updates freq_words2 with the maximum frequency of each character across all words in words2
    void setMaxFreq(vector<int> &freq_words2, vector<int> &freq)
    {
        for (int i = 0; i < 26; ++i)
            freq_words2[i] = max(freq_words2[i], freq[i]);
    }

    // Checks if the frequency of all characters in freq_word satisfies freq_words2
    bool isUniversal(vector<int> &freq_word, vector<int> &freq_words2)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (freq_word[i] < freq_words2[i])
                return false;
        }
        return true;
    }

public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        // Calculate the maximum frequency of each character in all words in words2
        vector<int> freq_words2(26);
        for (string word : words2)
        {
            vector<int> freq(26);
            for (char c : word)
                freq[c - 'a']++;
            setMaxFreq(freq_words2, freq);
        }

        // Identify words in words1 that meet the universal criteria
        vector<string> universal_words;
        for (string word : words1)
        {
            vector<int> freq_word(26);
            for (char c : word)
                freq_word[c - 'a']++;
            if (isUniversal(freq_word, freq_words2))
                universal_words.push_back(word);
        }

        return universal_words;
    }
};

int main()
{
    Solution sl;
    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2 = {"e", "o"};

    vector<string> result = sl.wordSubsets(words1, words2);

    for (auto e : result)
        cout << e << " ";
}