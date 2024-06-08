class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> myarr(2);
        double Kelvin = celsius + 273.15;
        double Fahrenheit = celsius * 1.80 + 32.00;
        myarr[0]= Kelvin;
        myarr[1]= Fahrenheit;
        return myarr;
    }
};