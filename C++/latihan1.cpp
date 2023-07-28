#include <iostream>

using namespace std;

double konversiFahrenheitKeCelcius (double);
float konversiFahrenheitKeCelcius (float);
int konversiFahrenheitKeCelcius (int);

double inputanFahrenheit;


int main() {
    // Program menghitung konversi dari derajat Fahrenheit ke Celcius 
    cout<<"Masukkan nilai inputan Fahrenheit untuk dikonversi : ";
    cin>>inputanFahrenheit;
    cout<<"Hasil Konversi : "<<konversiFahrenheitKeCelcius(inputanFahrenheit)<<endl;

    return 0;
}

double konversiFahrenheitKeCelcius(double inputFahrenheit) {
    double hasilCelcius = (inputFahrenheit - 32) * 5 / 9;

    return hasilCelcius;
}

float konversiFahrenheitKeCelcius(float inputFahrenheit) {
    float hasilCelcius = (inputFahrenheit - 32) * 5 / 9;

    return hasilCelcius;
}

int konversiFahrenheitKeCelcius(int inputFahrenheit) {
    int hasilCelcius = (inputFahrenheit - 32) * 5 / 9;

    return hasilCelcius;
}