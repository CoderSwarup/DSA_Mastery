#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
    string str;
    cin >> str;

    // unordered_map
    unordered_map<char, int> charMap;

    for(int i = 0; i < str.size(); i++) {
        charMap[str[i]]++;  // Count the frequency of each character
    }

    // Iterate through charMap
    for(auto i : charMap) {
        cout << i.first << " -> " << i.second << endl;
    }

    int q;
    cin >> q;

    while(q--) {
        char x;
        cin >> x;
        cout << x << " Appears : " << charMap[x] << " times" << endl;
    }

    return 0;
}
