#include <iostream>
#include <string>
using namespace std;

template <typename T>
int linearSearch (const T list[], T key, int arraySize){
	for (int i=0; i<arraySize; i++){
		if (list[i]==key){
			return i;
		}
	}
	return -1;
}

int main (){
	int list[]={1,4,4,2,5,-3,6,2};
	cout << "ints: \n" << linearSearch(list,4,8) << endl;
	cout << linearSearch(list,-4,8) << endl;
	cout << linearSearch(list,-3,8) << endl << endl;

	double list2[]={9.2,4.5,3};
	cout << "doubles: \n" << linearSearch(list2, 9.2, 3) << endl;
	cout << linearSearch(list2, 42.7, 3) << endl << endl;

	string list3[]={"bob","billy","sue","joe"};
	string a="billy";
	string b="phillip";
	cout << "strings: \n" << linearSearch(list3, a, 4) << endl;
	cout << linearSearch(list3, b, 4) << endl << endl;
	return 0;
}
