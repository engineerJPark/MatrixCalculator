#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TEXT_LENGTH 512
#define MATMAXNUMBER 10
#define ERRORTEST printf("no error\n"); fflush(stdin);

typedef struct Matrix{
	int n;
	int m;	// row and column
	char ** matData; // data of matrix
	char * textMat;
} Matrix;


void showMatrix(Matrix * matStruct){
	printf("\n");
	for(int i = 0; i < matStruct->n; i++){
		for(int j = 0; j < matStruct->m; j++){
			printf("%d ", (matStruct->matData)[i][j]);
		}
		printf("\n");
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
		(matStruct->matData)[i] = (float*)calloc(matStruct->m, sizeof(float) * matStruct->m);
	}
	
	int len = strlen(matStruct->textMat);
	int num = 0;	// temporary space for sum
	int numtemp[10] = {0}; // temporary space for number from textMat
	char z, i = 0;
	char x, y = 0; // row and column
	
	for(i = 0; i <= len; i++){
		if(((matStruct->textMat)[i] == ',') || ((matStruct->textMat)[i] == NULL)){ 
			for(int j = 1; j <= z; j++){
				//multiply 10 for z-j times
				for(int k = 1; k <= (z - j); k++){
					numtemp[j - 1] = numtemp[j - 1] * 10;
				}
				num = num + numtemp[j - 1];
			}
			(matStruct->matData)[x][y] = num;
			
			// initializtion
			num = 0;
			while(z){
				numtemp[z] = 0;
				z--;
			}
			y++;
			if(y > matStruct->m){ y=0; x++; }
		}
		else{
			// turn character to integer
			numtemp[z] = (matStruct->textMat)[i] - '0';
			z++;
		}
	}
	
	showMatrix(matStruct);
}