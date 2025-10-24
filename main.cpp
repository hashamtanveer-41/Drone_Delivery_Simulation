#include<iostream>

using namespace std;

//Function to check the mission status
string operationDecider(string, string, int);
//Function to provide Delivery results
void Delivery_Results(string);
// Function to update the Battery level
int BatteryUpdate(int, string);

// Declaring the global Variables for summary
int success_Missions =0;
int failed_Missions =0;
int delayed_Missions =0;
int main(){

    return 0;
}
string operationDecider(string weather, string obstacle, int battery) {
    /*Checking various conditions to determine the operations
     should be Successful, delayed or failed.*/
    if (battery < 20) {
        cout << "Recharge needed."<<endl;
        return "Recharge";
    }
    else if (weather == "rainy") {
        cout << "Mission delayed due to rain."<<endl;
        return "Delay";
    }
    else if (obstacle == "YES") {
        cout << "Mission failed due to obstacle."<<endl;
        return "Fail";
    }
    else if (weather == "windy" && battery < 40) {
        cout << "Battery too low for windy weather — returning to base.\n";
        return "Delay";
    }
    else {
        cout << "Mission successful!"<<endl;
        return "Success";
    }

}

void Delivery_Results() {
    int success_Missions = 0;
    int failed_Missions =0;
    int delayed_Missions =0;
    if (operationDecider()=="success") {
        cout << "Your parcel was delivered.";
        success_Missions++;
    }
    if (operationDecider()=="Fail") {
        cout << "The mission failed due to presence of obstacle and rainy weather.";
        failed_Missions++;
    }
    if (operationDecider()=="Delay") {
        cout << "The mission delayed due to rain.";
        delayed_Missions++;
    }

}

int BatteryUpdate(int batteryLevel, string result) {
    if (result == "Success") {
        cout << "Trip completed successfully. 20% Battery is used."<<endl;
        batteryLevel = batteryLevel- 20;
    }
    else if (result == "Fail") {
        cout << "Mission failed. Battery used: 10% battery is used."<<endl;
        batteryLevel =batteryLevel- 10;
    }
    else if (result == "Delay") {
        cout << "Mission delayed.5% battery is used."<< endl;
        batteryLevel = batteryLevel- 5;
    }
    else if (result == "Recharge") {
        cout << "Drone returned to base. The battery increased by 15%."<<endl;
        batteryLevel = batteryLevel- 15;
    }

    if (batteryLevel > 100) batteryLevel = 100;
    if (batteryLevel < 0) batteryLevel = 0;

    return batteryLevel;
}
