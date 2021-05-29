#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TEXT_LENGTH 512
#define MATMAXNUMBER 10

typedef struct Matrix{
	// row and coloum
	int n;
	int m;
	
	// data of matrix
	char ** matData;
	char textMat[TEXT_LENGTH];
} Matrix;

void parseText2Matrix(Matrix *matStruct){
	int len = strlen(matStruct->textMat);
	int num = 0;	// temporary space for sum
	int numtemp[10] = {0}; // temporary space for number from textMat
	int z, i; // row and column
	int x, y;
	int j, k;
	z = i = x = y = 0;
	
	for(i = 0; i <= len; i++){
		if(((matStruct->textMat)[i] == ',') || i >= len){
			for(j = 1; j <= z; j++){
				//multiply 10 for z-j times
				for(k = 1; k <= (z - j); k++){
					numtemp[j - 1] = numtemp[j - 1] * 10;
				}
				num = num + numtemp[j - 1];
			}
			
			matStruct->matData[x][y] = num;
			
			// initializtion
			num = 0;
			for(; z >= 0; z--){
				numtemp[z] = 0;
			}
			z = 0;
			y++;
			if(y >= matStruct->m){ y=0; x++; }
		}
		else{
			// turn character to integer
			numtemp[z] = matStruct->textMat[i] - '0';
			z++;
		}
	}
}

Matrix *initializeMatrix(Matrix * matStruct){
	//이제 행과 열을 모두 0으로 초기화한다.
	matStruct->matData = malloc(sizeof(char*) * matStruct->n);
	for(int i = 0; i < matStruct->n; i++){
		matStruct->matData[i] = calloc(matStruct->m, sizeof(char*) * matStruct->m);
	}
	return matStruct;
}


void getMatrix(Matrix * matStruct){
	printf("행의 크기 n, 열의 크기 m을 차례로 입력하세요.");
	scanf("%d %d", &(matStruct->n), &(matStruct->m));
	if((matStruct->n) > 5 || (matStruct->m) > 5){
		printf("본 계산기는 5x5까지만 지원합니다.\n");
		return ;
	}

	matStruct = initializeMatrix(matStruct);
	printf("데이터를 입력해주세요.");
	scanf("%s", matStruct->textMat);
	parseText2Matrix(matStruct);
}


void showMatrix(Matrix * matStruct){
	int i = 0, j = 0; // 각각 행과 열 상징
	printf("\n");
	for(i = 0; i < matStruct->n; i++){
		for(j = 0; j < matStruct->m; j++){
			printf("%d ", matStruct->matData[i][j]);
		}
		printf("\n");
	}
}

void editMatrix(Matrix * matStruct){
	printf("%s\n", matStruct->textMat);
	getMatrix(matStruct);
}


void killData(Matrix * matStruct){
	for (int i = 0; i < matStruct->n; i++){
		free(matStruct->matData[i]);
	}
	free(matStruct->matData);
}

int main(){
	int matIndex = 0;
	Matrix *matBox[MATMAXNUMBER];
	
	Matrix initMat;
	matBox[matIndex] = &initMat;
	
	// Information
	printf("최대 5x5 행렬을 지원합니다.\n\n");
	printf("행렬의 값을 텍스트로 입력해주세요. ','는 열 방향에서 왼쪽으로 오른쪽으로 하나씩 개행시킵니다.\n");
	printf("숫자와 , 외의 값을 입력하시면 에러납니다...\n");
	printf("아직까지는 정수형만 지원합니다. 그리고 0인 원소 생략하지 말아주세요!\n");
	
	getMatrix(matBox[matIndex]);
	showMatrix(matBox[matIndex]);
	
	return 0;
}