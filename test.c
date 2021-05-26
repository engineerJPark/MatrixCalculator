// call by value에 의해서 initialize가 안되는 건지 확인해보기

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

//5x5행렬을 전부 0으로 초기화한다.
void initializeMatrix(Matrix * matStruct){
	matStruct->n = 4;
	matStruct->m = 5;
	//이제 행과 열을 모두 0으로 초기화한다.
	matStruct->matData = (char**)malloc(sizeof(char**) * matStruct->n);
	for(int i = 0; i < matStruct->n; i++){
		matStruct->matData[i] = (float*)calloc(matStruct->m, sizeof(float) * matStruct->m);
	}
}

int main(){
	//생성된 행렬 개수를 세는 변수.
	int i = 0;
	//행렬구조체의 주소가 저장되는 곳. 배열로 쉽게 접근할 목적이다.
	Matrix * matBox[MATMAXNUMBER];
	//초기 행렬 초기화. 초기 모든 행렬 원소가 0이 되도록 한다.
	Matrix initMat;
	initMat.n = initMat.m = 2;
	matBox[i] = &initMat;
	//초기행렬 입력
	initializeMatrix(matBox[i]);
	printf("%d, %d", matBox[i]->n, matBox[i]->m);
	printf("%d, %d", matBox[i]->matData[0][0]);
	
	return 0;
}