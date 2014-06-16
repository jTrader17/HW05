#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Vector{
private:
T* elements;
int capacity;
unsigned int size;
public:
	~Vector(){
		delete[] elements;
	}
	Vector<T>(){
		size=0;
		capacity=1;
		elements= new T [capacity];
	}
	Vector<T>(int size){
		capacity=size+1;
		elements= new T [capacity];
	}
	Vector<T>(int size, T defaultValue){
		capacity=size+1;
		elements= new T [capacity];
		for (int i=0; i<size; i++){
			elements[i]=defaultValue;
		}
	}
	void push_back(T element){
		elements[size]=element;
		int a=capacity+1;
		T* tempElements=new T[a];
		for (int i=0; i<size+1; i++){
			tempElements[i]=elements[i];
		}
		delete[] elements;
		elements=tempElements;
		size++;
		capacity++;
	}
	void pop_back(){
		int a=capacity-1;
		T* tempElements=new T[a];
		for (int i=0; i<size-1; i++){
			tempElements[i]=elements[i];
		}
		delete[] elements;
		elements=tempElements;
		size--;
		capacity--;
	}
	unsigned int Size(){
		return size;
	}
	T const at(int index){
		return elements[index];
	}
	void clear(){
		T* a=new T[1];
		a[0]=NULL;
		delete[] elements;
		elements=a;
	}
	void swap (Vector &v2){
		T* temp=v2.elements;
		v2.elements=elements;
		elements=temp;
	}
};

int main(){
	Vector <int> intVector;
	intVector.push_back(6);
	intVector.push_back(4);
	intVector.push_back(2);
	intVector.push_back(42);
	intVector.push_back(5);
	cout << intVector.at(0) << endl;
	cout <<intVector.Size() << endl;
	return 0;
}