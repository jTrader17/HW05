#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

template <typename T>
bool allSet(vector<T>& q){
	bool test=true;
	int size=q.size();
	for(int i=0; i<size; i++){
		if (q[i]==NULL){
			test=false;
		}
	}
	if (!test){
		return false;
	}
	else
		return true;

}

template <typename T>
void shuffleVector (vector<T>& v){
	srand(time(NULL));
	unsigned int size= v.size();
	int modNum=size, x, y=0;
	vector<T> tempVector(size);
	for(int i=0; i<size; i++){
		tempVector[i]=NULL;
	}
	while(!allSet(tempVector)){
		x=rand()%modNum;
		if (tempVector[x]==NULL){
			T a;
			a=v[y]; 
			tempVector[x]=a;
			y++;
		}
	}
	for (int i=0; i<size; i++){
		v[i]=tempVector[i];
	}
}
int main(){
	vector<int> intVector(7);
	intVector[0]=1;
	intVector[1]=2;
	intVector[2]=3;
	intVector[3]=4;
	intVector[4]=5;
	intVector[5]=6;
	intVector[6]=7;
	shuffleVector(intVector);
	for(int i=0; i<7; i++){
		cout << intVector[i] << endl;
	}
	return 0;
}