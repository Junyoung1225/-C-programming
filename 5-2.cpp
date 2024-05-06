#include<iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;


void half(double& n) {
	n = n / 2;
}
int main() {
	double n = 20;
	half(n);
	cout << n;
}