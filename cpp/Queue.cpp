#include <iostream>
#include <vector>
#include <algorithm>

#include <math.h>

#include <stdlib.h>

using namespace std; 
/*
member structure
*/
// 큐
template<class T>
class Queue{
	private:
		// 입력 포인트, 출력포인트 
		int front;
		int rear;
		
		T* data;
		
	public:
		Queue();
		int getSize();
		
		void enqueue(T* data);
		T* dequeue();
};
template<class T>
Queue<T>::Queue(){
	this->front = 0;
	this->rear = 0;
}
template<class T>
int Queue<T>::getSize(){
	return this->front - this->rear;
}
template<class T>
void Queue<T>::enqueue(T* data){
	// 오버플로우 if( this.input_pt >= 최대수 ) return;
	T* buf = new T[this->getSize()+1];
	for( int i=0; i< this->getSize(); i++ ){
		*(buf+i) = *(this->data+i);
	}
	*(buf+this->front) = *data;
	this->data = buf;
	this->front++; 
}
template<class T>
T* Queue<T>::dequeue(){
	// 언더플로우
	if( this->getSize() <= 0 ) return NULL;
	return (this->data+rear++);
}