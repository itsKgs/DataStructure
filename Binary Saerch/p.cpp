#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<pair<int, int>> segments;
    int i = 0;

    // Group consecutive 'K' and 'V' together
    while (i < n) {
        int j = i + 1;
        while (j < n && s[j] == s[i]) {
            j++;
        }
        segments.push_back({(s[i] == 'K' ? 0 : 1), j - i});
        i = j;
    }

    int maxLength = 0;

    for (int i = 0; i < segments.size(); i++) {
        int key = segments[i].first;  // 0 for 'K', 1 for 'V'
        int val = segments[i].second;

        if (key == 0) {  // 'K' segment
            maxLength = max(maxLength, val);
        } else if (val == 1) {  // Single 'V' between 'K' segments
            if (i > 0 && i + 1 < segments.size()) {
                maxLength = max(maxLength, segments[i - 1].second + segments[i + 1].second + 1);
            }
        }
    }

    cout << maxLength << endl;
    return 0;
}