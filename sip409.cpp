#include <iostream>
#include <algorithm>

// Class representing a phone
class Phone {
private:
    int batteryPercentage;  // Battery percentage of the phone
    int externalPower;      // External power available to the phone
    bool isActive;          // Flag indicating whether the phone is active or not

public:
    // Constructor to initialize the phone with battery percentage and external power
    Phone(int percentage, int extPower) : batteryPercentage(percentage), externalPower(extPower), isActive(false) {}

    // Method to pull power from the phone's battery
    int pullPower() {
        int pulledPower = std::min(1, batteryPercentage / 100); // Pull 1% or less if battery < 100%
        batteryPercentage -= pulledPower; // Decrease battery percentage
        return pulledPower; // Return the pulled power
    }

    // Method to give power to another phone
    void givePower(Phone& otherPhone) {
        if (batteryPercentage <= 50) { // Only give power if battery <= 50%
            int givenPower = std::min(2, (50 - batteryPercentage) * 2); // Give 2% or less to reach 50%
            otherPhone.receivePower(givenPower); // Receive power on the other phone
            batteryPercentage += givenPower; // Increase battery percentage
        }
    }

    // Method to receive power from another phone
    void receivePower(int receivedPower) {
        batteryPercentage += receivedPower; // Increase battery percentage
    }

    // Method to use external power
    void useExternalPower(int power) {
        externalPower -= power; // Decrease external power
        batteryPercentage += power; // Increase battery percentage
    }

    // Method to turn on the phone
    void turnOn() {
        isActive = true; // Set the active flag to true
        std::cout << "1" << std::endl; // Indicate that the device is active
    }

    // Method to turn off the phone
    void turnOff() {
        isActive = false; // Set the active flag to false
        std::cout << "0" << std::endl; // Indicate that the device is inactive
    }

    // Method to get the battery percentage of the phone
    int getBatteryPercentage() const {
        return batteryPercentage; // Return battery percentage
    }

    // Method to get the external power available to the phone
    int getExternalPower() const {
        return externalPower; // Return external power
    }
};

// Main function
int main() {
    Phone phone1(75, 100); // Phone 1 starts with 75% battery and 100 units of external power
    Phone phone2(20, 0);   // Phone 2 starts with 20% battery and no external power

    phone1.turnOn(); // Turn on Phone 1

    // Phone 1 pulls power and gives power to Phone 2
    int pulledPower = phone1.pullPower();
    phone2.receivePower(pulledPower);
    phone1.givePower(phone2);

    // Phone 1 uses external power
    phone1.useExternalPower(10);

    std::cout << "Phone 1 Battery Percentage: " << phone1.getBatteryPercentage() << std::endl;
    std::cout << "Phone 1 External Power: " << phone1.getExternalPower() << std::endl;
    std::cout << "Phone 2 Battery Percentage: " << phone2.getBatteryPercentage() << std::endl;

    phone1.turnOff(); // Turn off Phone 1

    return 0; // Return 0 to indicate successful execution
}

