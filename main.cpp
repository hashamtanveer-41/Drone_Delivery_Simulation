#include<iostream>

using namespace std;

//Function to check the mission status
string operationDecider();
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