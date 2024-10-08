#include <bits/stdc++.h>

using namespace std;

class Room
{
    int rNo;
    double rPrice;

public:
    Room()
    {
    }
    Room(int rNo, double rPrice)
    {
        this->rNo = rNo;
        this->rPrice = rPrice;
    }

    // accept data for rooms
    void accept()
    {
        cout << "\nEnter Room ID: ";
        cin >> rNo;
        cout << "\nEnter Room Price: ";
        cin >> rPrice;
    }
    // display data for rooms
    void display()
    {
        cout << "\nRoom ID: " << rNo << endl;
        cout << "\nRoom Price: " << rPrice << endl;
    }

    // display data for rooms in format
    void displayList()
    {
        cout << "\nRoom ID: " << rNo << " Price: " << rPrice << endl;
    }
    // getter for roomId
    int getRid()
    {
        return rNo;
    }
};

class Guest
{
    int gId;
    string gName;
    vector<Room *> bookedRooms;

public:
    Guest()
    {
    }
    Guest(int gId, string gName)
    {
        this->gId = gId;
        this->gName = gName;
    }
    Room *getRoom()
    {
        if (bookedRooms[0])
        {
            Room *r = bookedRooms[0];
            bookedRooms.erase(bookedRooms.begin());
            return r;
        }
        else
        {
            Room *r = NULL;
            return r;
        }
    }
    int oneRoom()
    {
        return bookedRooms.size();
    }
    // displaying all booked rooms in formatted way
    void displayAll()
    {
        cout << "\nID: " << gId << " Guest Name: " << gName << endl;
        for (int i = 0; i < bookedRooms.size(); i++)
        {
            bookedRooms[i]->displayList();
        }
    }
    // displaying all booked rooms
    void displayRooms()
    {
        for (int i = 0; i < bookedRooms.size(); i++)
        {
            bookedRooms[i]->displayList();
        }
    }
    // adding booked room atlast of vector
    void addRoom(Room *r)
    {
        bookedRooms.emplace_back(r);
    }
    // input for guest id and name
    void accept()
    {
        cout << "\nEnter Guest ID: ";
        cin >> gId;
        cout << "\nEnter Guest Name: ";
        cin >> gName;
    }
    // display for guest id and name
    void display()
    {
        cout << "Guest ID: " << gId << endl;
        cout << "Guest Name: " << gName << endl;
    }
    // getter for guest id processing
    int getGid()
    {
        return gId;
    }
};

// menu for our room booking app
int menuBooking()
{
    cout << "0. EXIT." << endl;
    cout << "1. Add New Guest." << endl;
    cout << "2. Book Room." << endl;
    cout << "3. Display Rooms Booked by Guest." << endl;
    cout << "4. Display All Guests and Their Booked Rooms." << endl;
    cout << "5. Leave Room." << endl;
    cout << ":) Enter Choice: ";
    int choice;
    cin >> choice;
    return choice;
}

// function which returns index of fetced guest
int findGuest(vector<Guest *> &guests)
{
    int id;
    cout << "\nEnter Guest ID: ";
    cin >> id;
    for (int i = 0; i < guests.size(); i++)
    {
        if (id == guests[i]->getGid())
        {
            return i;
        }
    }
    return -1;
}

// function which returns index of fetced room
int findRoom(vector<Room *> &rooms)
{
    int r;
    cout << "Book Room ID: ";
    cin >> r;
    for (int i = 0; i < rooms.size(); i++)
    {
        if (r == rooms[i]->getRid())
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    // vector for storing room object
    vector<Room *> rooms;
    rooms.push_back(new Room(1, 100));
    rooms.push_back(new Room(2, 200));
    rooms.push_back(new Room(3, 300));

    // vector for storing guest object
    vector<Guest *> guests;
    guests.push_back(new Guest(1, "Prathamesh"));
    guests.push_back(new Guest(2, "Vishal"));
    guests.push_back(new Guest(3, "Bhushan"));

    int ch;
    while ((ch = menuBooking()) != 0)
    {
        switch (ch)
        {
        // for adding guest
        case 1:
        {
            Guest *g = new Guest();
            g->accept();
            guests.push_back(g);
        }
        break;
        // for booking room
        case 2:
        {
            int index = findGuest(guests);
            if (index != -1)
            {
                if (guests[index]->oneRoom() != 0)
                {
                    cout << "Gueast can book only one room...!" << endl;
                }
                else
                {
                    for (int i = 0; i < rooms.size(); i++)
                    {
                        rooms[i]->displayList();
                    }
                    int indexx = findRoom(rooms);
                    if (indexx != -1)
                    {
                        guests[index]->addRoom(rooms[indexx]);
                        rooms.erase(rooms.begin() + indexx);
                    }
                    else
                    {
                        cout << "Room not found...!" << endl;
                    }
                }
            }
            else
            {
                cout << "Guest not found...!" << endl;
            }
        }
        break;
        // for showing booked rooms with validation
        case 3:
        {
            int index = findGuest(guests);
            if (index != -1)
            {
                guests[index]->displayRooms();
            }
            else
            {
                cout << "Guest not found...!" << endl;
            }
        }
        break;
        // for showing all guests with their booked rooms
        case 4:
        {
            for (int i = 0; i < guests.size(); i++)
            {
                guests[i]->displayAll();
            }
        }
        break;

        case 5:
        {
            int index = findGuest(guests);
            if (index != -1)
            {
                Room *r = guests[index]->getRoom();
                if (r == NULL)
                    cout << "Guest leaved already...!";
                else
                    rooms.emplace_back(r);

                // int i;
                // for (i = 1; i < rooms.size(); i++)
                // {
                //     if (rooms[i - 1]->getRid() < r->getRid() && r->getRid() < rooms[i]->getRid())
                //     {
                //         rooms.insert(rooms.begin() + i, r);
                //         break;
                //     }
                // }
                // if (i==rooms.size())
                // {
                // }
                // else
                // {
                //     rooms.insert(rooms.begin(), r);
                // }

                for (int i = 0; i < rooms.size() - 1; i++)
                {
                    for (int j = 0; j < rooms.size() - 1 - i; j++)
                    {
                        if (rooms[j]->getRid() > rooms[j + 1]->getRid())
                        {
                            swap(rooms[j], rooms[j + 1]);
                        }
                    }
                }
            }
            else
            {
                cout << "Guest not found...!" << endl;
            }
        }
        break;
        default:
            cout << "Try Again...!" << endl;
            break;
        }
    }
}