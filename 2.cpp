#include <iostream>
#include <cmath>

// правую производную от правой производной для точки х=0

using namespace std;

// в точке х* = 0.2 (х2)
void diff(double *x, double *y) {
	double leftDiff, rightDiff, diff, secondDiff, rightDiffrightDiff, tmpRightDiff;

	// левая производная для 0.2 (х2)
	leftDiff = (y[2]-y[1]) / (x[2]-x[1]);
	// cout << "Left diff in 0.2 (х2) = " << leftDiff << "\n";
	// правая производная для 0.2 (х2)
	rightDiff = (y[3]-y[2]) / (x[3]-x[2]);
	cout << "Right diff in 0.2 (х2) = " << rightDiff << "\n";
	// производная для 0.2 (х2)
	diff = (y[3]-y[1]) / (x[3]-x[1]);
	// cout << "Diff in 0.2 (х2) = " << diff << "\n";
	// вторая производная для 0.2 (х2)
	secondDiff = (y[3]-y[2]-y[2]+y[1]) / ((x[3]-x[2])*(x[2]-x[1]));
	cout << "Second diff in 0.2 (х2) = " << secondDiff << "\n";

	// доп. задание от 16.10
	// правая производная для 0.0 (х1)
	tmpRightDiff = (y[2]-y[1]) / (x[2]-x[1]);
	cout << "Right diff in 0.0 (х1) = " << tmpRightDiff << "\n";
	// правая производная от правой производной в 0.0 (x1)
	rightDiffrightDiff = (rightDiff - tmpRightDiff) / (x[2]-x[1]);
	cout << "Right diff_right diff in 0.0 (х1) = " << rightDiffrightDiff << "\n";
}

int main() {
	int num = 5;
	double *dots_X = new double[num];
	double *dots_Y = new double[num];
	dots_X[0] = -0.2;
	dots_X[1] = 0;
	dots_X[2] = 0.2;
	dots_X[3] = 0.4;
	dots_X[4] = 0.6;
	dots_Y[0] = 1.7722;
	dots_Y[1] = 1.5708;
	dots_Y[2] = 1.3694;
	dots_Y[3] = 1.1593;
	dots_Y[4] = 0.9273;
	for(int i=0; i < num; i++) {
		// cin >> dots_X[i];
		cout << "X" << i << " = " << dots_X[i] << "\n"; 
	}
	for(int i=0; i < num; i++) {
		// cin >> dots_Y[i];
		cout << "Y" << i << " = " << dots_Y[i] << "\n";
	}

	// double *diffRes = new double[num];
	diff(dots_X, dots_Y);

	delete [] dots_X;
	delete [] dots_Y;
	return 0;
}


