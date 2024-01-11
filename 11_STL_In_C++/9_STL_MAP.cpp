#include <iostream>
#include <map>

using namespace std;

int main() {
    // Create a map with string keys and int values
    map<string, int> myMap;

    // Insert key-value pairs using insert method
    myMap.insert(make_pair("one", 1));
    myMap.insert(make_pair("two", 2));
    myMap.insert(make_pair("three", 3));

    // Display elements using iterators
    cout << "Elements in the map:" << endl;
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Access values using keys
    string keyToFind = "two";
    auto it = myMap.find(keyToFind);
    if (it != myMap.end()) {
        cout << keyToFind << ": " << it->second << " is found in the map." << endl;
    } else {
        cout << keyToFind << " is not found in the map." << endl;
    }



    map<int,string>map2;

    map2[1] = "SSSS";
    map2[3] = "aaaaa";
    map2[2] = "bbbbb";

    for(auto a:map2){
        cout <<a.first << " "<< a.second << endl;
    }

    //erase 
    map2.erase(2);
    cout << endl << "After eraser " << endl;
  for(auto a:map2){
        cout <<a.first << " "<< a.second << endl;
    }
    return 0;
}
