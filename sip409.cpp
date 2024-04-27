#include <iostream>
#include <algorithm>

class Phone {
private:
    int batteryPercentage;
    int externalPower;

public:
    Phone(int percentage, int extPower) : batteryPercentage(percentage), externalPower(extPower) {}

    int pullPower() {
        int pulledPower = std::min(1, batteryPercentage / 100); // Pull 1% or less if battery < 100%
        batteryPercentage -= pulledPower;
        return pulledPower;
    }

    void givePower(Phone& otherPhone) {
        if (batteryPercentage <= 50) { // Only give power if battery <= 50%
            int givenPower = std::min(2, (50 - batteryPercentage) * 2); // Give 2% or less to reach 50%
            otherPhone.receivePower(givenPower);
            batteryPercentage += givenPower;
        }
    }

    void receivePower(int receivedPower) {
        batteryPercentage += receivedPower;
    }

    void useExternalPower(int power) {
        externalPower -= power;
        batteryPercentage += power;
    }

    int getBatteryPercentage() const {
        return batteryPercentage;
    }

    int getExternalPower() const {
        return externalPower;
    }
};

int main() {
    Phone phone1(75, 100); // Phone 1 starts with 75% battery and 100 units of external power
    Phone phone2(20, 0);   // Phone 2 starts with 20% battery and no external power

    // Phone 1 pulls power and gives power to Phone 2
    int pulledPower = phone1.pullPower();
    phone2.receivePower(pulledPower);
    phone1.givePower(phone2);

    // Phone 1 uses external power
    phone1.useExternalPower(10);

    std::cout << "Phone 1 Battery Percentage: " << phone1.getBatteryPercentage() << std::endl;
    std::cout << "Phone 1 External Power: " << phone1.getExternalPower() << std::endl;
    std::cout << "Phone 2 Battery Percentage: " << phone2.getBatteryPercentage() << std::endl;

    return 0;
}
