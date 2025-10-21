#include<iostream>
#include<cstdlib>  // this library has random function
#include<ctime>
using namespace std;

int check_weather(); // function for checking the weather . it is a function prototype


int main(){
    srand(time(0)); // helps generate a random number everytime
cout << "the weather is ";
    check_weather();  // calling the weather function

    return 0;
}

// .....................declaration/defining of weather function...........................

int check_weather() {

    int weather = 1+rand() % 3; // generates a number between 1 and 3

    if (weather==1) {
        cout << "sunny"; // prints sunny if 1
    }
    else if(weather==2) {
        cout << "windy"; // prints windy if 2
    }
    else {
        cout << "rainy"; // prints rainy if 3
    }
}