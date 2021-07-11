#include <iostream>
#include <vector>
#include <algorithm>

#include <math.h>

#include <stdlib.h>

using namespace std; 
/*
member structure
*/
// 스택
template<class T>
class Stack{
	private:
		int top;
		
		T* dataStack;
		
	public:
		Stack();
		int getSize();
		void push(T data);
		T pop();
};
template<class T>
Stack<T>::Stack(){
	this->top = 0;
}
template<class T>
int Stack<T>::getSize(){
	return this->top;
}
template<class T>
void Stack<T>::push(T data){
	// 오버플로우 if( this.top >= 최대수 ) return;
	T* buf = new T[this->getSize()+1];
	for(int i=0; i<this->getSize(); i++){
		*(buf+i) = *(this->dataStack+i);
	}
	buf[this->getSize()] = data;
	this->dataStack = buf;
	this->top++;
}
template<class T>
T Stack<T>::pop(){
	// 언더플로우 
	if(this->top <= 0) return;
	this->top--;
	return *(this->dataStack+this->top);
}