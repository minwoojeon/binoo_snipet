#include <iostream>
#include <vector>
#include <algorithm>

#include <math.h>

#include <stdlib.h>

using namespace std; 
/*
member calculator
*/

class calcul{
	public:
		// 정수 
		int add(int a, int b);
		int sub(int a, int b);
		int mul(int a, int b);
		int div(int a, int b);
		
		// 유리수 
		double add(double a, double b);
		double sub(double a, double b);
		double mul(double a, double b);
		double div(double a, double b);
		
		// 지수로 
		double pow(double a, double b);
		// 평 균  
		double mean(double* datapt, int len);
		// 분산 
		double variance(double* datapt, int len); 
		// 표준편차 
		double deviation(double* datapt, int len); 
};
int calcul::add(int a, int b){
	return a+b;
}
int calcul::sub(int a, int b){
	return a-b;
}
int calcul::mul(int a, int b){
	return a*b;
}
int calcul::div(int a, int b){
	return (b==0 ? 0 : a/b);
}
double calcul::add(double a, double b){
	return a+b;
}
double calcul::sub(double a, double b){
	return a-b;
} 
double calcul::mul(double a, double b){
	return a*b;
}
double calcul::div(double a, double b){
	return (b==0 ? 0 : a/b);
}

double calcul::mean(double* data, int len){
	long double sum = 0;
	for(int i=0; i<len; i++)
		sum += *(data+i);
	return sum/len;
	// printf("%0.2lf", maen); 소수아래 2자리반올림 
}
double calcul::variance(double* data, int len){
	long double sum = 0, mean = 0;
	for(int i=0; i<len; i++)
		sum += *(data+i);
	mean = sum/len;
	sum = 0;
	for(int i=0; i<len; i++){
		sum += powl((*(data+i) - mean), 2);
	}
	return sum/len;
}
double calcul::deviation(double* data, int len){
	long double sum = 0, mean = 0;
	for(int i=0; i<len; i++)
		sum += *(data+i);
	mean = sum/len;
	sum = 0;
	for(int i=0; i<len; i++){
		sum += powl((*(data+i) - mean), 2);
	}
	sum = powl((sum/len), 1/2);
	return sum;
}