#include<iostream>
#include<cstdlib>  // this library has random function
#include<ctime>
using namespace std;

int check_battery(); // function for checking the weather . it is a function prototype

int main(){

    srand(time(0)); // helps generate a random number everytime
cout << "remaining battery percentage = ";
   cout << check_battery();  //calling battery function
    cout << "%";
}
// .....................declaration/defining of battery function.........................

int check_battery() {
    int battery= 10+rand()%75;
    return battery;
}