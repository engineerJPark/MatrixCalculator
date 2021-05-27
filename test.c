#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TEXT_LENGTH 512
#define MATMAXNUMBER 10
#define ERRORTEST printf("no error\n");

typedef struct Matrix{
	int n;
	int m;	//행렬의 행과 열의 크기
	char ** matData; //행렬의 data
	char * textMat;
} Matrix;


void showMatrix(Matrix * matStruct){
	int i = 0, j = 0; // 각각 행과 열 상징
	printf('\n');
	for(i = 0; i < matStruct->n; i++){
		for(j = 0; j < matStruct->m; j++){
			printf("%d ", matStruct->matData[i][j]);
		}
		printf('\n');
	}
}

int main(){
	Matrix * matStruct = (Matrix *)malloc(sizeof(Matrix));
	
	// data and text Initialization
	matStruct->n = matStruct->m = 2;
	matStruct->textMat = "2,2,2,2";
	
	// Matrix Initialization
	matStruct->matData = (char**)malloc(sizeof(char**) * matStruct->n);
	for(int i = 0; i < matStruct->n; i++){
		matStruct->matData[i] = (float*)calloc(matStruct->m, sizeof(float) * matStruct->m);
	}
	
	char len = strlen(matStruct->textMat);
	char num = 0;	//숫자를 임시로 저장할 공간이다.
	char numtemp[10] = {0}; //숫자를 임시로 저장할 공간이다.
	char z, i = 0;
	char j, k = 1;
	char x, y = 0; // 행과 열을 표현하는 숫자다.
	

	for(i = 0; i <= len; i++){
		if((matStruct->textMat[i] == ',') || (matStruct->textMat[i] == NULL)){ // 여기에 문제가 있는듯 하다.
			//쉼표나 마지막표시(널값) 들어온 경우
			for(j = 1; j <= z; j++){
				//z-j번씩 10을 곱해준다음 더해준다.
				for(k = 1; k <= (z - j); k++){
					numtemp[j - 1] = numtemp[j - 1] * 10;
				}
				num = num + numtemp[j - 1];
			}
			matStruct->matData[x][y] = num;	//정확한 위치에 num을 대입
			
			//한 원소의 입력 후 주요 변수 초기화 작업
			num = 0;
			while(z!=0){
				numtemp[z] = 0;
				z--;
			}
			
			// 행, 열 증가
			y++;
			if(y > matStruct->m){ y=0; x++; }
		}
		else{
			//숫자 입력. 10진수 단위로 또 만들어줘야한다.
			numtemp[z] = (matStruct->textMat[i]) - '0'; // 단일 문자를 알맞은 숫자로 변환시켜주어야한다.
			z++;
		}
	}
	
	ERRORTEST
	
	showMatrix(matStruct);
}

// http://pelex529.blogspot.com/2009/01/2.html