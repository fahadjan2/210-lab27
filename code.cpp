// COMSC-210 | Lab 27 | Fahad Fawad Ahmad 
// IDE used: Visual Studio
#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<string>> villagerData;

    // insert elements into the map
    villagerData["Audie"] = {5, "Human", "bazinga"};
    villagerData["Raymond"] = {7, "Human", "woohoo!"};
    villagerData["Marshal"] = {2, "Cat", "it's so over"};

    // access the map using a range-based for loop
    cout << "Villagers and their data (range-based for loop):" << endl;
    for (auto pair : villagerData) {
        cout << pair.first << ": ";
        for (auto value : pair.second)
            cout << value << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their data (iterators):" << endl;
    for (map<string, tuple<string>>::iterator it = villagerData.begin(); 
                                               it != villagerData.end(); ++it) {
        cout << it->first << ": ";
        for (auto value : it->second) {
            cout << value << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerData.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerData.find(searchKey);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto value : it->second)  // range loop to traverse the value/vector
            cout << value << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl;

    return 0;
}
