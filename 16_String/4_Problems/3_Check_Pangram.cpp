#include<iostream>
using namespace std;
#include <vector>

// https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/

bool checkIfPangram(string sentence) {
    vector<bool> alphabet(26,0);

    for(int i=0;i<sentence.size();i++){
        alphabet[sentence[i] - 'a'] = 1;
    }

    for(int i=0;i<alphabet.size();i++){
        if(alphabet[i] ==0){
            return 0;
        }
    }


    return 1;
}
int main(){
    string sentence = "thequickbrownfoxjumpsoverthelazydog";

    cout << checkIfPangram(sentence);


return 0;
}