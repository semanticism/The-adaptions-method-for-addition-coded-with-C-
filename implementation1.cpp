#include <iostream>
using namespace std;
unsigned int v = 0;
unsigned int A[] = {0,3,3};
unsigned int B[] = {0,3,3};
unsigned int l = sizeof(A)/4;
unsigned int array[] = {0,0,0};
unsigned int oarray[] = {0,0,0};
unsigned int base = 10;
int debugarray(){
	unsigned int i = 0;
	while(i<l){
		cout << array[i];
		cout << '\n';
		i=i+1;
	}
}
int E(int x){ //base^exponent
	unsigned int i=0;
	unsigned int r=1;
	if(x<0){
		r=1/(E(-1*x));
	}else{
		while(i<x){
			r=r*base;
			i=i+1;
		}
	}
	return r;
}
int P(){ //Interprets the vector
	unsigned int i = 0;
	unsigned int r = 0;
	while(i<l){
		r=r+array[i]*E((l-1)-i);
		i=i+1;
	}
	return r;
}
int displayarray(){
	v=0;
	char a;
	while(v<l){
		a=array[v]+48;
		cout << a;
		v=v+1;
	}
}
int adjust(){
	v=0;
	unsigned int g=0;
	while(v<l){
		debugarray();
		if(array[v]>9){
			g=array[v]/base;
			array[v-1]=array[v-1]+(g);
			array[v]=array[v]-(g*base);
		}
		debugarray();
		v=v+1;
		cout << '\n';
	}
	displayarray();
	cout << '\n';
}
int add(){
	v=0;
	while(v<l){
		array[v]=A[v]+B[v];
		v=v+1;
	}
}
int setl(){
	unsigned int i = 0;
	while(i<l){
		oarray[i]=array[i];
		i=i+1;
	}
}
int checkarrays(){ //Check if there's a difference between oarray and array, oarray being a variable which we store the state before the adjustement to then check if there's no difference and if so stop
	int i = 0;
	bool r = 0;
	while (i<l & r==0){
		r = r | (oarray[i] != array[i]);
		i=i+1;
	}
	return r;
}
int main(){
	add();
	while(checkarrays()){
		setl();
		adjust();
	}
	debugarray();
	cout << '\n' << sizeof(A)/4 << '\n' << P();
	return 0;
}
