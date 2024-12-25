#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For formatted output

using namespace std;

class ParkingSpot {
public:
    int spotNumber;
    string vehicleType;
    bool isOccupied;

    ParkingSpot(int num) : spotNumber(num), isOccupied(false), vehicleType("") {}
};

class ParkingLot {
private:
    vector<ParkingSpot> spots;
    int bikeSpots;
    int carSpots;

public:
    ParkingLot(int totalBikeSpots, int totalCarSpots) : bikeSpots(totalBikeSpots), carSpots(totalCarSpots) {
        for (int i = 1; i <= bikeSpots + carSpots; i++) {
            spots.emplace_back(i);
        }
    }

    void displayHeader(const string& title) {
        cout << "\n=========================================" << endl;
        cout << "          " << title << "          " << endl;
        cout << "=========================================" << endl;
    }

    void parkVehicle(string vehicleType) {
        displayHeader("Park a Vehicle");
        if (vehicleType == "Bike" || vehicleType == "Car") {
            int start = (vehicleType == "Bike") ? 0 : bikeSpots;
            int end = (vehicleType == "Bike") ? bikeSpots : spots.size();

            for (int i = start; i < end; i++) {
                if (!spots[i].isOccupied) {
                    spots[i].isOccupied = true;
                    spots[i].vehicleType = vehicleType;
                    cout << "\n" << vehicleType << " parked successfully at Spot " << spots[i].spotNumber << "!" << endl;
                    return;
                }
            }
            cout << "\nSorry, no available spots for " << vehicleType << "!" << endl;
        } else {
            cout << "\nInvalid vehicle type!" << endl;
        }
    }

    void removeVehicle(int spotNumber) {
        displayHeader("Remove a Vehicle");
        if (spotNumber > 0 && spotNumber <= spots.size() && spots[spotNumber - 1].isOccupied) {
            spots[spotNumber - 1].isOccupied = false;
            string removedVehicle = spots[spotNumber - 1].vehicleType;
            spots[spotNumber - 1].vehicleType = "";
            cout << "\n" << removedVehicle << " removed from Spot " << spotNumber << "!" << endl;
        } else {
            cout << "\nInvalid or empty spot!" << endl;
        }
    }

    void displayParkingStatus() {
        displayHeader("Parking Lot Status");
        cout << setw(10) << "Spot No" << setw(15) << "Status" << setw(15) << "Vehicle Type" << endl;
        cout << "-----------------------------------------" << endl;
        for (auto &spot : spots) {
            cout << setw(10) << spot.spotNumber 
                 << setw(15) << (spot.isOccupied ? "Occupied" : "Empty") 
                 << setw(15) << (spot.isOccupied ? spot.vehicleType : "-") 
                 << endl;
        }
    }
};

int main() {
    int bikeSpots, carSpots;

    cout << "=========================================" << endl;
    cout << "       Welcome to the Parking System     " << endl;
    cout << "=========================================" << endl;

    cout << "\nEnter the number of Bike spots: ";
    cin >> bikeSpots;
    cout << "Enter the number of Car spots: ";
    cin >> carSpots;

    ParkingLot parkingLot(bikeSpots, carSpots);

    int choice;
    do {
        parkingLot.displayHeader("Main Menu");
        cout << "1. Park Vehicle" << endl;
        cout << "2. Remove Vehicle" << endl;
        cout << "3. Display Parking Status" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string vehicleType;
            cout << "Enter vehicle type (Bike/Car): ";
            cin >> vehicleType;
            parkingLot.parkVehicle(vehicleType);
            break;
        }
        case 2: {
            int spotNumber;
            cout << "Enter spot number to remove vehicle: ";
            cin >> spotNumber;
            parkingLot.removeVehicle(spotNumber);
            break;
        }
        case 3:
            parkingLot.displayParkingStatus();
            break;
        case 4:
            parkingLot.displayHeader("Thank You!");
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        default:
            cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}