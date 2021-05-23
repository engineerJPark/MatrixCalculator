#include<stdio.h>
#define TEXT_LENGTH 512
#define MATMAXNUMBER 10
#define ERRORTEST "no error\n"
// printf(ERRORTEST);

//matData은 행렬의 주소, *matData은 행렬의 하나의 행을 지정, **matData은 행렬의 하나의 원소(열)를 지정한다.
typedef struct Matrix{
	int n;
	int m;	//행렬의 행과 열의 크기
	char ** matData;	//행렬의 data
	char * textMat;
} Matrix;

int main(){
	Matrix matStruct;
	matStruct.textMat = (char*)malloc(TEXT_LENGTH);
	scanf("%s", matStruct.textMat); // 이거 문제.
	printf("%s", matStruct.textMat);
	printf("%c", matStruct.textMat[1]);
	printf("%d", matStruct.textMat[1]-48);
}