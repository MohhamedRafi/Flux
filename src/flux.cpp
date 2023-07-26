#include "math/matrix3.h"
#include "math/vec3.h"
#include <iostream>

int main() {
	using namespace std;
	using namespace flux;

	float arr[3][3] = {{0,1,2}, {1,2,3}, {3,4,5}};
	matrix3 m(arr);

	cout << m << endl;
	cout << m * m << endl;
	cout << m + m << endl;
	cout << m - m << endl;
	cout << 2 * m << endl;
}