#include<iostream>
#include<cstdlib>
using namespace std;

string operationDecider(string, string, int);   //Function to check the mission status
void Delivery_Results(string);  //Function to provide Delivery results
int BatteryUpdate(int, string); // Function to update the Battery level

// Declaring the global Variables for summary
int success_Missions =0;
int failed_Missions =0;
int delayed_Missions =0;
int main(){
    cout<< "\n\n-------------------------------------\n";
    cout<< "| Drone delivery Simulation started |\n";
    cout<< "-------------------------------------\n\n";
    int battery = 100;
    cout<<"Battery: "<<battery<<"%"<<endl<<endl;
    string weather, obstacle, result;
    srand(time(0));
    for(int i = 1; i<=3; i++){
        int w = rand()%3;
        if(w ==0 ) weather= "sunny";
        else if(w==1) weather= "rainy";
        else weather = "windy";
        obstacle = (rand()%2 ==0) ? "YES" : "NO";
        //battery = 10 + rand()% 91;
        result= operationDecider(weather, obstacle, battery);
        Delivery_Results(result);
        battery= BatteryUpdate(battery, result);
        cout<<endl;
        
    }
        cout <<"\n\nSuccessful Deliveries: " <<success_Missions<<endl;
        cout<<"Failed Deliveries: "<<failed_Missions<<endl;
        cout<<"Delayed Deliveries: "<<delayed_Missions<<endl;
        cout<<"Battery Left: "<<battery;

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

void Delivery_Results(string result) {
    /*This function according to the output of status
     of delivery prints the result of Delivery.*/
    if (result=="Success") {
        cout << "Your parcel was delivered."<<endl;
        success_Missions++;
    }
    else  if (result=="Fail") {
        cout << "The mission failed due to obstacle or rainy weather."<< endl;
        failed_Missions++;
    }
    else if (result=="Delay") {
        cout << "The mission delayed due to rain."<<endl;
        delayed_Missions++;
    }
    else if (result == "Recharge") {
        cout << "Drone returned to base for recharging."<<endl;
    }
}

int BatteryUpdate(int batteryLevel, string result) {
    /*This function checks the delivery status and according to
      that updates the battery of drone.
     */
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
/*If battery exceeds 100 or becomes less than zero which are impractical
 then battery is updated to either to 100 or 0 . */
    if (batteryLevel > 100) batteryLevel = 100;
    if (batteryLevel < 0) batteryLevel = 0;

    return batteryLevel;
}
