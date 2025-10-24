#include<iostream>

using namespace std;

//Function to check the mission status
string operationDecider();
//Function to provide Delivery results
void Delivery_Results();

// Declaring the global Variables for summary
int success_Missions =0;
int failed_Missions =0;
int delayed_Missions =0;
int main(){

    return 0;
}
string operationDecider() {
    /* Checking if weather is sunny, there are no obstacles
        and the drone has required charging for the trip */

    int total_Missions = 0;// Counter for number of missions performed

    /*Checking various conditions to determine the operations
     should be Successful, delayed or failed.*/
    if (check_weather()=="sunny" && check_obstacle()=="NO" && check_battery()>=20){
        cout << "Success";
        return "Success";
    }
    if (check_weather()=="rainy" || check_obstacle()=="YES"){
        cout << "Fail";
        return "Fail";
    }
    if (check_weather()=="windy"){
        cout << "Delay";
        return "Delay";
    }
    if (check_battery() < 20) {
        cout << "Recharge";
        return "Recharge";
    }
    return "Unknown";
    // Incrementing total missions
    total_Missions++;
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
