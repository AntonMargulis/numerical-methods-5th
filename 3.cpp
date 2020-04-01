#include <iostream>
#include <cmath>

using namespace std;

// func = x^2 * e^x
double myFunc(double arg) {
    double current, res;
  	double eps = 0.000001;
    int n = 1;
    current = 1;
    res = current;
    while (abs(current)>eps) {
        current*= arg / n;
        res+= current;
        n++;
    }

    res = res * arg * arg;
    return res;
}

double lagrange(double x0, double x1, double x2, double x3, double x) {
	double L0, L1, L2, L3, func0, func1, func2, func3, res;

	func0 = myFunc(x0);
	func1 = myFunc(x1);
	func2 = myFunc(x2);
	func3 = myFunc(x3);

	L0 = (x-x1)*(x-x2)*(x-x3)/((x0-x1)*(x0-x2)*(x0-x3));
	L1 = (x-x1)*(x-x2)*(x-x3)/((x1-x0)*(x1-x2)*(x1-x3));
	L2 = (x-x1)*(x-x2)*(x-x3)/((x2-x0)*(x2-x1)*(x2-x3));
	L3 = (x-x1)*(x-x2)*(x-x3)/((x3-x0)*(x3-x1)*(x3-x2));

	res = func0*L0 + func1*L1 + func2*L2 + func3*L3;

	return res;
}


double newton(double x0, double x1, double x2, double x3, double x) {
	double P0, P1, P2, P3, func0, func1, func2, func3, res;

	func0 = myFunc(x0);
	func1 = myFunc(x1);
	func2 = myFunc(x2);
	func3 = myFunc(x3);

	P0 = func0;
	P1 = (func0-func1)/(x0-x1);
	P2 = (func1-func2)/(x1-x2);
	P3 = (func2-func3)/(x2-x3);

	res = P0 + (x-x0)*P1 + (x-x0)*(x-x1)*(P1-P2)/(x0-x2) + (x-x0)*(x-x1)*(x-x2)*(P1-P2)/(x0-x2) - (P2-P3)/(x1-x3)/(x0-x3);
	cout << "Second diff in 0.2 (х2) = " << res << "\n";

	return res;
}



int main() {
	double x0, x1, x2, x3, x;
	x0 = -1.2;
	x1 = -0.7;
	x2 = -0.2;
	x3 =  0.3;
	x  = -0.5;

	double resLagrange = lagrange (x0, x1, x2, x3, x);
	double resNewton = newton (x0, x1, x2, x3, x);
	cout << resLagrange << "\n" << resNewton << "\n";

	return 0;
}


/*
[-1.2,-0.7,-0.2,0.3,-0.5]

лагранж на питоне:

import numpy as np
import matplotlib.pyplot as plt
x=np.array([2,5,-6,7,4,3,8,9,1,-2], dtype=float)
y=np.array([-1,77,-297,249,33,9,389,573,-3,-21], dtype=float)
def lagranz(x,y,t):
    z=0
    for j in range(len(y)):
        p1=1; p2=1
        for i in range(len(x)):
            if i==j:
                p1=p1*1; p2=p2*1   
            else: 
                p1=p1*(t-x[i])
                p2=p2*(x[j]-x[i])
        z=z+y[j]*p1/p2
    return z
xnew=np.linspace(np.min(x),np.max(x),100)
ynew=[lagranz(x,y,i) for i in xnew]
plt.plot(x,y,'o',xnew,ynew)
plt.grid(True)
plt.show()
*/










