#include <iostream>
#include <string>
using namespace std;

template <typename T>

bool isSorted(const T list[], int size){
	bool asc=true, des=true;
	for (int i=0; i<size-1; i++){
		if (list[i]>list[i+1])
			asc=false;
	}
		for (int i=0; i<size-1; i++){
		if (list[i]<list[i+1])
			des=false;
	}
		if (asc || des)
			return true;
		else
			false;
}

int main (){
	const int a[5]={6,5,4,3,2};
	const double b[5]={3.4,4.5,9.9,1,2};
	const string c[4]={"bob","phil","pete","joe"};
	cout << "int: " << isSorted(a,5) << endl;
	cout << "double: " << isSorted(b,5) << endl;
	cout << "string: " << isSorted(c,4) << endl;
	return 0;
}