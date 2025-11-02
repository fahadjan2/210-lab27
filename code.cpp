// COMSC-210 | Lab 27 | Fahad Fawad Ahmad 
// IDE used: Visual Studio
#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int menu();
void display(map<string, tuple<int, string, string>> villagerData);
void changeFriendship(map<string, tuple<int, string, string>> &villagerData, string);
void searchVillager(map<string, tuple<int, string, string>> &villagerData);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerData;

    // insert elements into the map
    villagerData["Audie"] = make_tuple(5, "Human", "bazinga");
    villagerData["Raymond"] = make_tuple(7, "Human", "woohoo!");
    villagerData["Marshal"] = make_tuple(2, "Cat", "it's so over");

    cout << "Villager details:" << endl;
    int choice = 0;
    while (choice != 4) {
        display(villagerData);
        choice = menu();
        if (choice == 1) {
            changeFriendship(villagerData, "Increase");
        } else if (choice == 2) {
            changeFriendship(villagerData, "Decrease");
        } else if (choice == 3) {
            searchVillager(villagerData);
        }
        cout << endl;
    }
    /* delete an element
    villagerData.erase("Raymond");

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl;
    */

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

void display(map<string, tuple<int, string, string>> villagerData) {
    for (auto pair : villagerData) {
        cout << pair.first << ": ";
        cout << get<0>(pair.second) << " " << get<1>(pair.second) << " " << get<2>(pair.second) << endl;
    }
    cout << endl;
}

void changeFriendship(map<string, tuple<int, string, string>> &villagerData, string choice) {
    string name;
    cout << "Choose villager to increase friendship: ";
    cin >> name;

    auto it = villagerData.find(name);
    while (it == villagerData.end()) {
        cout << "Not found. \n Choose villager to increase friendship: ";
        cin >> name;
    } 

    if (choice == "Increase")
        get<0>(it->second) += 1;
    else if (choice == "Decrease")
        get<0>(it->second) -= 1;
}

//Searches for villager through the map data, and then returns the iterator to the villager if found
void searchVillager(map<string, tuple<int, string, string>> &villagerData) {
    string searchKey;
    cout << "Villager to search: ";
    cin >> searchKey;
    auto it = villagerData.find(searchKey);
    if (it != villagerData.end()) {
        cout << "\nFound " << searchKey << "'s data: ";
        cout << get<0>(it->second) << " " << get<1>(it->second) << " " << get<2>(it->second) << endl;
    } else
        cout << endl << searchKey << " not found." << endl;
}