#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Room {
    int number;
    string type;
    double price;
    bool booked;
    string guest;
};

int linearSearch(vector<Room> rooms, int num) {
    for (int i = 0; i < rooms.size(); i++) {
        if (rooms[i].number == num) {
            return i;
        }
    }
    return -1;
}

void bubbleSort(vector<Room>& rooms) {
    int n = rooms.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (rooms[j].price > rooms[j + 1].price) {
                Room temp    = rooms[j];
                rooms[j]     = rooms[j + 1];
                rooms[j + 1] = temp;
            }
        }
    }
    cout << "Rooms sorted by price!\n";
}

void showRooms(vector<Room> rooms) {
    cout << "\n--- All Rooms ---\n";
    for (int i = 0; i < rooms.size(); i++) {
        cout << "Room " << rooms[i].number
             << " | "   << rooms[i].type
             << " | $"  << rooms[i].price
             << " | "   << (rooms[i].booked ? "Booked by " + rooms[i].guest : "Available")
             << "\n";
    }
}

void bookRoom(vector<Room>& rooms) {
    int num;
    cout << "Enter room number: ";
    cin >> num;

    int i = linearSearch(rooms, num);

    if (i == -1) {
        cout << "Room not found.\n";
        return;
    }
    if (rooms[i].booked) {
        cout << "Room is already booked.\n";
        return;
    }

    cout << "Enter guest name: ";
    cin.ignore();
    getline(cin, rooms[i].guest);
    rooms[i].booked = true;
    cout << "Room booked successfully!\n";
}

void cancelBooking(vector<Room>& rooms) {
    int num;
    cout << "Enter room number to cancel: ";
    cin >> num;

    int i = linearSearch(rooms, num);

    if (i == -1) {
        cout << "Room not found.\n";
        return;
    }
    if (!rooms[i].booked) {
        cout << "Room is not booked.\n";
        return;
    }

    rooms[i].booked = false;
    rooms[i].guest  = "";
    cout << "Booking cancelled.\n";
}

void searchRoom(vector<Room> rooms) {
    int num;
    cout << "Enter room number to search: ";
    cin >> num;

    int i = linearSearch(rooms, num);

    if (i == -1) {
        cout << "Room not found.\n";
        return;
    }

    cout << "Room " << rooms[i].number
         << " | "   << rooms[i].type
         << " | $"  << rooms[i].price
         << " | "   << (rooms[i].booked ? "Booked by " + rooms[i].guest : "Available")
         << "\n";
}

int main() {

    vector<Room> rooms = {
        {101, "Single",  50.0,  false, ""},
        {102, "Single",  50.0,  false, ""},
        {201, "Double",  90.0,  false, ""},
        {202, "Double",  90.0,  false, ""},
        {301, "Suite",  180.0,  false, ""},
        {302, "Suite",  200.0,  false, ""},
    };

    int choice;

    cout << "Welcome to Hotel C++\n";

    do {
        cout << "\n1. Show all rooms\n";
        cout << "2. Book a room\n";
        cout << "3. Cancel a booking\n";
        cout << "4. Search a room\n";
        cout << "5. Sort rooms by price\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if      (choice == 1) showRooms(rooms);
        else if (choice == 2) bookRoom(rooms);
        else if (choice == 3) cancelBooking(rooms);
        else if (choice == 4) searchRoom(rooms);
        else if (choice == 5) bubbleSort(rooms);
        else if (choice == 0) cout << "Goodbye!\n";
        else                  cout << "Invalid choice.\n";

    } while (choice != 0);

    return 0;
}
