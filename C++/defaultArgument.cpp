#include <iostream>
using namespace std;

double volumeKubus(double p = 1, double l = 1, double t = 1);

int main() {
    cout<<"Volume kubus : " << volumeKubus(3,4,5)<<endl;
    cout<<"Volume kubus : " << volumeKubus(3,4)<<endl;
    cout<<"Volume kubus : " << volumeKubus(3)<<endl;
    cout<<"Volume kubus : " << volumeKubus()<<endl;
}

double volumeKubus(double p, double l, double t) {
    return p * l * t;
}