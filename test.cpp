#include <iostream>
using namespace std;

bool isSpecial(char c) {
    return c == '*' || c == '$' || c == '#' || c == '&';
}

bool isAlphabet(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    string s;
    cin >> s;

    string res = "";
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (isSpecial(s[i])) {
            // Skip the special character
            i++;

            // Now find and skip the first alphabet to the right
            while (i < n && !isAlphabet(s[i])) {
                res += s[i]; // Keep non-alphabet characters
                i++;
            }
            // Skip the alphabet (if exists)
            if (i < n && isAlphabet(s[i])) {
                i++;
            }

            i--; // adjust because the for-loop will do i++
        } else {
            res += s[i];
        }
    }

    cout << res << endl;
    return 0;
}
