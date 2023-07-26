#include "math/vec3.h" 
#include <iostream>

int main() {
	using namespace std;
	using namespace flux;

	vec3 v(1, 2, 3);
	vec3 v2(2, 1, 3);

	if (v == v2) {
		cout << v << endl;
	}
	else {
		cout << v << v2 << endl;
	}
}