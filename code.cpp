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
void addVillager(map<string, tuple<int, string, string>> &villagerData);
void delVillager(map<string, tuple<int, string, string>> &villagerData);

int main() {
    map<string, tuple<int, string, string>> villagerData;

    //Insert elements initially
    villagerData["Audie"] = make_tuple(5, "Human", "bazinga");
    villagerData["Raymond"] = make_tuple(7, "Human", "woohoo!");
    villagerData["Marshal"] = make_tuple(2, "Cat", "it's so over");

    cout << "Villager details:" << endl;
    int choice = 0;
    while (choice != 6) {
        display(villagerData);
        choice = menu();
        if (choice == 1) 
            addVillager(villagerData);
        else if (choice == 2)
            delVillager(villagerData); 
        else if (choice == 3) 
            changeFriendship(villagerData, "Increase");
        else if (choice == 4) 
            changeFriendship(villagerData, "Decrease");
        else if (choice == 5)
            searchVillager(villagerData);
        cout << endl;
    }

    return 0;
}

//Menu option, displays options and asks user for a choice
int menu() {
    int choice;
    cout << "1. Add Villager\n 2. Delete Villager\n 3. Increase Friendship\n4. Decrease Friendship\n5. Search for Villager\n6. Exit" << endl;
    cout << "Choice: ";
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        cout << "Choice should be between 1-4" << endl;
        cout << "Choice: ";
        cin >> choice;
    } 

    return choice;
}

//Displays all the data in the map 
void display(map<string, tuple<int, string, string>> villagerData) {
    for (auto pair : villagerData) {
        cout << pair.first << " [";
        cout << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << "]" << endl;
    }
    cout << endl;
}

//Asks user for a villager to change friendship, then depending on whether it's increase or decreasae, will change the data of their friendship level
void changeFriendship(map<string, tuple<int, string, string>> &villagerData, string choice) {
    string name;
    cout << "Choose villager to increase friendship: ";
    cin >> name;

    //Finds villager
    auto it = villagerData.find(name);
    while (it == villagerData.end()) {
        cout << "Not found. \n Choose villager to increase friendship: ";
        cin >> name;
    } 

    //Choice on whether to increase/decrease, doesn't do it if it's over 10 or under 0
    if (choice == "Increase") {
        if (get<0>(it->second) < 10)
            get<0>(it->second) += 1;
    } else if (choice == "Decrease") {
        if (get<0>(it->second) > 0)
            get<0>(it->second) -= 1;
    }
}

//Searches for villager through the map data, then outputs its finding
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

//Asks user for data input, then adds a villager to the map
void addVillager(map<string, tuple<int, string, string>> &villagerData) {
    int friendship;
    string name, species, catchphrase;

    if (villagerData.find(name) == villagerData.end()) //Name exists
        return;

    cout << "Villager name: ";
    cin >> name;
    cout << "Friendship level: ";
    cin >> friendship;
    while (friendship > 10 || friendship < 0) {
        cout << "Enter friendship level between 0-10: ";
        cin >> friendship;
    }
    cout << "Species: ";
    cin >> species;
    cout << "Catchphrase: ";
    cin >> catchphrase;

    villagerData[name] = make_tuple(friendship, species, catchphrase);
    cout << name << " added." << endl;
}

//Finds a villager in the map, then deletes their data
void delVillager(map<string, tuple<int, string, string>> &villagerData) {

    villagerData.erase("Raymond");
}
