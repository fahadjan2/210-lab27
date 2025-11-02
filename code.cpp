// COMSC-210 | Lab 27 | Fahad Fawad Ahmad 
// IDE used: Visual Studio
#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int menu();

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerData;

    // insert elements into the map
    villagerData["Audie"] = make_tuple(5, "Human", "bazinga");
    villagerData["Raymond"] = make_tuple(7, "Human", "woohoo!");
    villagerData["Marshal"] = make_tuple(2, "Cat", "it's so over");

    // access the map using a range-based for loop
    cout << "Villagers and their data (range-based for loop):" << endl;
    for (auto pair : villagerData) {
        cout << pair.first << ": ";
        cout << get<0>(pair.second) << " " << get<1>(pair.second) << " " << get<2>(pair.second) << endl;
    }
    int choice = menu();
    // delete an element
    villagerData.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerData.find(searchKey);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        cout << get<0>(it->second) << " " << get<1>(it->second) << " " << get<2>(it->second) << endl;
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl;

    return 0;
}

int menu() {
    int choice;
    cout << "1. Increase Friendship\n2. Decrease Friendship\n3. Search for Villager\n4. Exit" << endl;
    cout << "Choice: ";
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        cout << "Choice should be between 1-4" << endl;
        cout << "Choice: ";
        cin >> choice;
    } 

    return choice;
}