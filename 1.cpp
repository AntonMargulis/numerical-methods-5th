#include <iostream>
#include <cmath>

using namespace std;

double myСos(double arg, double eps) {
    double current, sum;
    arg = fmod(arg, 2 * M_PI);
    int n = 0;
    current = 1;
    sum = current;
    while(abs(current)>eps) {
        current*= -1 * arg * arg / ((2*n+1)*(2*n+2));
        sum+= current;
        n++;
    }
    cout << "myCos = " << sum << "\t Table value = " << cos(arg) << "\n";
    return sum;
}

double myExp(double arg, double eps) {
    double current, sum;
    int n = 1;
    current = 1;
    sum = current;
    while (abs(current)>eps) {
        current*= arg / n;
        sum+= current;
        n++;
    }
    cout << "myExp = " << sum << "\t\t Table value = " << exp(arg) << "\n";
    return sum;
}

double myLn(double arg, double eps) {
    double current, sum;
    int n = 2;
    int sign = -1;
    arg = arg - 1;
    current = arg;
    sum = current;
    while (abs(current)>eps) {
        current = sign * pow(arg, n) / n;
        sum+= current;
        sign = sign * -1;
        n++;
    }
    return sum;
}

double myLg(double arg, double eps) {
    double numerator, denominator, sum, x;
    int counter;
    counter = 0;
    x = arg;
    while (x > 1 || x < -1) {
    	x = x / 10; 
    	counter = counter + 1;
    }
    numerator = myLn(x, eps);
    denominator = 2.30258;
    sum = (numerator / denominator) + counter;
    cout << "myLg = " << sum << "\t Table value = " << log10(arg) << "\n";
    return sum;
}

int main() {
    double arg, eps;
    eps = 0.00001;
    cout << "enter arg: \n";
    cin >> arg;
    double res;
	res = myСos(arg, eps);
    res = myExp(arg, eps);
    res = myLg(arg, eps);

    return 0;
}
