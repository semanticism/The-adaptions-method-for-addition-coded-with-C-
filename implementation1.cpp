#include <iostream>
using namespace std;
unsigned int v = 0; // \/ These two values are added up to create what will be saved into array
unsigned int A[] = {0,3,3};
unsigned int B[] = {0,3,3};
unsigned int l = sizeof(A)/4;
unsigned int array[] = {0,0,0};
unsigned int oarray[] = {0,0,0};
unsigned int base = 10;
int debugarray(){ //A debug function that prints
	unsigned int i = 0;
	while(i<l){
		cout << array[i];
		cout << '\n';
		i=i+1;
	}
}
int E(int x){
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
int P(){
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
		if(array[v]>9){ //It skips the cauculations if it's bigger than nine
			g=array[v]/base; //I used the / operation to an intenger
			array[v-1]=array[v-1]+(g); //So tnat 32/10=3
			array[v]=array[v]-(g*base); //The remainer is 32-(3*10)=2
		}
		debugarray();
		v=v+1;
		cout << '\n';
	}
	displayarray();
	cout << '\n';
}
int add(){ //It adds the two vectors together
	v=0;
	while(v<l){
		array[v]=A[v]+B[v];
		v=v+1;
	}
}
int setl(){ //Sets OARRAY to be ARRAY
	unsigned int i = 0;
	while(i<l){
		oarray[i]=array[i];
		i=i+1;
	}
}
int alllegal(){ //Are all numbers in the vector < base number
	int i = 0;
	bool r = 0;
	while (i<l | r==1){
		r = r | (array[i]<base);
		i=i+1;
	}
	return r;
	
}
int checkarrays(){ //This checks if the adapted vector and the initial vector are all the same, returning 0, if not, it returns 1
	int i = 0;
	bool r = 0;
	while (i<l | r==1){
		r = r | (oarray[i] != array[i]);
		i=i+1;
	}
	return r;
}
int main(){
	add();
	while(checkarrays()){ //You could try to use alllegal() instead of checking if there's no effect is seen when applying the function
		setl();       //and delete this line but that doesn't work in my computer so I'm not sure
		adjust();
	}
	debugarray();
	cout << '\n' << sizeof(A)/4 << '\n' << P();
	return 0;
}
