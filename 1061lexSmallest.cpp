#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, char> parent;

    char find(char c) {
        if (parent[c] != c)
            parent[c] = find(parent[c]);
        return parent[c];
    }

    void unite(char a, char b) {
        char pa = find(a);
        char pb = find(b);

        if (pa == pb) return;

        // Attach the lexicographically larger to the smaller
        if (pa < pb)
            parent[pb] = pa;
        else
            parent[pa] = pb;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // Initialize each character to itself
        for (char c = 'a'; c <= 'z'; ++c)
            parent[c] = c;

        for (int i = 0; i < s1.size(); i++) {
            unite(s1[i], s2[i]);
        }

        // Build result by replacing each char with its smallest equivalent
        for (int i = 0; i < baseStr.size(); i++) {
            baseStr[i] = find(baseStr[i]);
        }

        return baseStr;
    }
};

int main() {
    string s1 = "leetcode";
    string s2 = "programs";
    string baseStr = "sourcecode";

    Solution sl;
    cout << sl.smallestEquivalentString(s1, s2, baseStr) << endl;
}
