#include<iostream>
#include<cstdlib>  // this library has random function
#include<ctime>
using namespace std;

int check_obstacle(); // function for checking the weather . it is a function prototype

int main(){
    srand(time(0)); // helps generate a random number everytime
cout << "is there any obstacle? = ";
    check_obstacle();
    return 0;
}
// .....................declaration/defining of obstacle function.........................

int check_obstacle() {
    int obstacle= 1+rand()%2;
    if (obstacle==1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}