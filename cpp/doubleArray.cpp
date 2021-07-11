#include <iostream>
#include <vector>
#include <algorithm>

#include <math.h>

#include <stdlib.h>

using namespace std; 
/*
member double array
*/
// 2차 배열의 회전 (90도)
// 2차 배열의 길 찾기

template<class T>
class doubleArray{
	
	T** dataStream;
	
	public:
		doubleArray();
		doubleArray(T** dataStream);
		~doubleArray();
		
		// 우측으로 90도 회전 
		char** rotate90(char** data, int row, int col);
		// 좌측으로 90도 회전
		char** rotate270(char** data, int row, int col);
		// 상하반 전 
		char** upToDown(char** data, int row, int col);
		// 좌우대칭
		char** backToFront(char** data, int row, int col);
		
		// 입력 스트림에서 타일깔기  
		char** pastSeet(char** data, int row, int col);
		
		// 입력에서 길찾기 BST 
		char** BSTsearch(
			char** data, int row, int col, int s_x,int s_y, int d_x, int d_y);
			
};

template<class T>
doubleArray<T>::doubleArray(){
}
template<class T>
doubleArray<T>::doubleArray(T** dataStream){
	int collen = sizeof(*(dataStream+1))/sizeof(T);
	int rowlen = sizeof(*dataStream)/sizeof(*(dataStream+1));
	this->dataStream = (T**)malloc(rowlen*sizeof(T*));
	for( int i=0; i<rowlen; i++ ){
		*(this->dataStream+i) = (T*)malloc(collen*sizeof(T));
	}
	this->dataStream = dataStream;
}
template<class T>
doubleArray<T>::~doubleArray(){
	
}
template<class T>
char** doubleArray<T>::rotate90(char** data, int row, int col){
	// 오른쪽으로 회전 
	/*
	ex]
	0  1  2  3      12  8 4 0  0,0=4,0 0,1=3,0
	4  5  6  7      13  9 5 1
	8  9  10 11     14 10 6 2
	12 13 14 15     15 11 7 3
	*/
	char** result = (char**)malloc(sizeof(char*)*col);
	for(int i=0; i<col; i++)
		*(result+i) = (char*)malloc(sizeof(char)*row);
	for(int i=0; i<col; i++)
		for(int j=0; j<row; j++)
			*(*(result+i)+j) = *(*(data+row-j-1)+i);
	return result;
}
template<class T>
char** doubleArray<T>::rotate270(char** data, int row, int col){
	// 왼쪽으로 회전 
	/*
	ex]
	0  1  2  3      3 7 11 15 0,0=0,4 0,1=1,4
	4  5  6  7      2 6 10 14
	8  9  10 11     1 5 9  13
	12 13 14 15     0 4 8  12
	*/
	char** result = (char**)malloc(sizeof(char*)*col);
	for(int i=0; i<col; i++)
		*(result+i) = (char*)malloc(sizeof(char)*row);
	for(int i=0; i<col; i++)
		for(int j=0; j<row; j++)
			*(*(result+i)+j) = *(*(data+j)+col-i-1);
	return result;
}
template<class T>
char** doubleArray<T>::upToDown(char** data, int row, int col){
	// 위아래 상하반전 
	/*
	ex]
	0  1  2  3      12 13 14 15 0,0=4,0 0,1=4,1
	4  5  6  7      8  9  10 11
	8  9  10 11     4  5  6  7
	12 13 14 15     0  1  2  3
	*/
	char** result = (char**)malloc(sizeof(char*)*row);
	for(int i=0; i<row; i++)
		*(result+i) = (char*)malloc(sizeof(char)*col);
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			*(*(result+i)+j) = *(*(data+row-i-1)+j);
	return result;
}
template<class T>
char** doubleArray<T>::backToFront(char** data, int row, int col){
	// 앞뒤 반전 
	/*
	ex]
	0  1  2  3      3  2  1  0 0,0=0,4 0,1=0,2
	4  5  6  7      7  6  5  4 1,0=1,4 1,1=1,2
	8  9  10 11     11 10 9  8
	12 13 14 15     15 14 13 12
	*/
	char** result = (char**)malloc(sizeof(char*)*row);
	for(int i=0; i<row; i++)
		*(result+i) = (char*)malloc(sizeof(char)*col);
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			*(*(result+i)+j) = *(*(data+i)+col-j-1);
	return result;
}

template<class T>
char** doubleArray<T>::pastSeet(char** data, int row, int col){
	// 시트 변경 
	
	/*
	ex] a-z이 길이고 0이 벽일때 주어진 타일을 선택하여 설치하기 
	2017 NHN 하반기 타일문제 응용
	벽 : 0 - θ 
	타일a :      b:      c: 
	┌─┐   ┌┬┐  ㉠㉡㉢ 
	│┾│   ├┾┤  ㉣㉤㉥ 
	└─┘   └┴┘  ㉦㉧㉨ 
	0 0 0 0 c
	a a 0 0 c
	a a 0 0 c
	0 b b 0 c
	0 b b 0 0
	*/
	char tilesA[3][3]= {
								{'1','2','3'},
								{'4','5','6'},
								{'7','8','9'}
								};
	char tilesB[3][3]= {
								{'a','b','c'},
								{'d','e','f'},
								{'g','h','i'}
								};
	char tilesC[3][3]= {
								{'j','k','l'},
								{'m','n','o'},
								{'p','q','r'}
								};
	
	char** result = (char**)malloc(sizeof(char*)*row);
	for(int i=0; i<row; i++)
		*(result+i) = (char*)malloc(sizeof(char)*col);
	
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++){
			// 주어진 값과 상하좌우가 같은지 비교. 
			char item = *(*(data+i)+j); 
			bool upside=(i-1<0 ? false : (*(*(data+i-1)+j) != item ? false : true)), 
				downside=(i+1>=row ? false : (*(*(data+i+1)+j) != item ? false : true)), 
				leftside=(j-1<0 ? false : (*(*(data+i)+j-1) != item ? false : true)), 
				rightside=(j+1>=col ? false : (*(*(data+i)+j+1) != item ? false : true));
				
			int cnt = 0;
			switch(item){
				case 'a':
					if(upside && downside && leftside && rightside){
						*(*(result+i)+j) = *(*(tilesA+1)+1);
						break;
					}
					if(downside && leftside && rightside){
						*(*(result+i)+j) = *(*(tilesA+0)+1);
						break;
					}
					if(upside && leftside && rightside){
						*(*(result+i)+j) = *(*(tilesA+2)+1);
						break;
					}
					if(downside && leftside && upside){
						*(*(result+i)+j) = *(*(tilesA+1)+2);
						break;
					}
					if(upside && downside && rightside){
						*(*(result+i)+j) = *(*(tilesA+1)+0);
						break;
					}
					
					if(downside && leftside){
						*(*(result+i)+j) = *(*(tilesA+0)+2);
						break;
					}
					if(downside && rightside){
						*(*(result+i)+j) = *(*(tilesA+0)+0);
						break;
					}
					if(upside && leftside){
						*(*(result+i)+j) = *(*(tilesA+2)+2);
						break;
					}
					if(upside && rightside){
						*(*(result+i)+j) = *(*(tilesA+2)+0);
						break;
					}
					*(*(result+i)+j) = 'z';
					break;
				case 'b':
					if(upside && downside && leftside && rightside){
						*(*(result+i)+j) = *(*(tilesB+1)+1);
						break;
					}
					if(downside && leftside && rightside){
						*(*(result+i)+j) = *(*(tilesB+0)+1);
						break;
					}
					if(upside && leftside && rightside){
						*(*(result+i)+j) = *(*(tilesB+2)+1);
						break;
					}
					if(downside && leftside && upside){
						*(*(result+i)+j) = *(*(tilesB+1)+2);
						break;
					}
					if(upside && downside && rightside){
						*(*(result+i)+j) = *(*(tilesB+1)+0);
						break;
					}
					
					if(downside && leftside){
						*(*(result+i)+j) = *(*(tilesB+0)+2);
						break;
					}
					if(downside && rightside){
						*(*(result+i)+j) = *(*(tilesB+0)+0);
						break;
					}
					if(upside && leftside){
						*(*(result+i)+j) = *(*(tilesB+2)+2);
						break;
					}
					if(upside && rightside){
						*(*(result+i)+j) = *(*(tilesB+2)+0);
						break;
					}
					*(*(result+i)+j) = 'z';
					break;
				case 'c':
					if(upside && downside && leftside && rightside){
						*(*(result+i)+j) = *(*(tilesC+1)+1);
						break;
					}
					if(downside && leftside && rightside){
						*(*(result+i)+j) = *(*(tilesC+0)+1);
						break;
					}
					if(upside && leftside && rightside){
						*(*(result+i)+j) = *(*(tilesC+2)+1);
						break;
					}
					if(downside && leftside && upside){
						*(*(result+i)+j) = *(*(tilesC+1)+2);
						break;
					}
					if(upside && downside && rightside){
						*(*(result+i)+j) = *(*(tilesC+1)+0);
						break;
					}
					
					if(downside && leftside){
						*(*(result+i)+j) = *(*(tilesC+0)+2);
						break;
					}
					if(downside && rightside){
						*(*(result+i)+j) = *(*(tilesC+0)+0);
						break;
					}
					if(upside && leftside){
						*(*(result+i)+j) = *(*(tilesC+2)+2);
						break;
					}
					if(upside && rightside){
						*(*(result+i)+j) = *(*(tilesC+2)+0);
						break;
					}
					*(*(result+i)+j) = 'z';
					break;
				default:
					// 벽인경우.
					*(*(result+i)+j) = '0';
					break;	
			}
		}
	return result;
}