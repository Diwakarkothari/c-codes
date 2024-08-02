#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isDisjointlyInAll(const vector<string>& messages, const string& substr) {
    for (const string& message : messages) {
        size_t pos = message.find(substr);
        if (pos == string::npos) return false;  // substr not found at all

        size_t nextPos = message.find(substr, pos + substr.size());
        if (nextPos == string::npos) return false;  // substr not found disjointly
    }
    return true;
}

int findLongestDisjointSubstring(const vector<string>& messages) {
    int maxLen = 0;
    string longestSubstring = "";
    string reference = messages[0];
    
    for (int len = 1; len <= reference.size(); ++len) {
        for (int start = 0; start <= reference.size() - len; ++start) {
            string substr = reference.substr(start, len);
            if (isDisjointlyInAll(messages, substr)) {
                if (len > maxLen) {
                    maxLen = len;
                    longestSubstring = substr;
                }
            }
        }
    }
    
    return maxLen;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> messages(n);
        cin.ignore();  // Ignore the trailing newline after the integer input
        for (int i = 0; i < n; ++i) {
            getline(cin, messages[i]);
            // Remove trailing white spaces
            messages[i].erase(messages[i].find_last_not_of(" \n\r\t") + 1);
        }
        cout << findLongestDisjointSubstring(messages) << endl;
    }
    return 0;
}
