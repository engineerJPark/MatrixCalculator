#include<stdio.h>
#define TEXT_LENGTH 512

//matData은 행렬의 주소, *matData은 행렬의 하나의 행을 지정, **matData은 행렬의 하나의 원소(열)를 지정한다.
typedef struct Matrix{
	int n = 0;
	int m = 0;	//행렬의 행과 열의 크기
	char ** matData;	//행렬의 data
	char * textMat;
} Matrix;

void initializeMatrix(Matrix matStruct);
void getMatrix(Matrix matStruct);
void showMatrix(Matrix matStruct);
void editMatrix(Matrix matStruct);

void killData(Matrix matStruct);
void transposeMatrix(Matrix matStruct);

void main(){
	//생성된 행렬 개수를 세는 변수.
	int i = 0;
	//행렬구조체의 주소가 저장되는 곳. 배열로 쉽게 접근할 목적이다.
	Matrix *matBox;
	//초기 행렬 초기화. 초기 모든 행렬 원소가 0이 되도록 한다.
	Matrix initMat;
	matBox[i] = initMat;
	//안내문
	printf("최대 5x5 행렬을 지원합니다.\n\n");
	printf("행렬의 값을 텍스트로 입력해주세요. ','는 열 방향에서 왼쪽으로 오른쪽으로 하나씩 개행시킵니다.\n");
	printf("숫자와 , . 외의 값을 입력하시면 에러납니다...\n");
	printf("0이라고 생략하지 말아주세요!\n");
	//초기행렬 입력
	getMatrix(matBox[i]);
	showMatrix(matBox[i]);
}

//5x5행렬을 전부 0으로 초기화한다.
void initializeMatrix(Matrix matStruct){
	//이제 행과 열을 모두 0으로 초기화한다.
	matStruct.matData = (char**)malloc(sizeof(char**) * matStruct.n);
	for(int i = 0; i < matStruct.n; i++){
		matStruct.matData[i] = (float*)calloc(matStruct.m, sizeof(float) * matStruct.m);
	}
}

//text형태로 행렬을 받는다. ','로 숫자를 구분한다.
void getMatrix(Matrix matStruct){
	int n, m = 0;
	printf("행의 크기 n, 열의 크기 m을 차례로 입력하세요.");
	scanf("%d", &n); scanf("%d", &m);
	if(n > 5 || m > 5){ printf("본 계산기는 5x5까지만 지원합니다.\n"); return;}
	matStruct.n = n; matStruct.m = m;	
	
	initializeMatrix(matStruct);

	matStruct.textMat = (char*)malloc(TEXT_LENGTH);
	scanf("%s", matStruct.textMat);
	char len = strlen(matStruct.textMat);
	
	char num = 0;	//숫자를 임시로 저장할 공간이다.
	char numtemp[10] = {}; //숫자를 임시로 저장할 공간이다.
	char z = 0, k = 1;
	char x, y = 0; // 행과 열을 표현하는 숫자다.
	
	//문자를 행과 열로 나눠준다.
	for(int i = 0; i <= len; i++){
		if(matStruct.textMat[i]!="," || matStruct.textMat[i]!="." || matStruct.textMat[i]!=NULL){
			//숫자 입력. 10진수 단위로 또 만들어줘야한다.
			numtemp[z] = atoi(matStruct.textMat[i]);
			z++;
		}
		else if(matStruct.textMat[i]==","||matStruct.textMat[i]==NULL){
			//쉼표나 마지막표시(널값) 들어온 경우 
			for(j=1;j <= z;j++){
				//z-j번씩 10을 곱해준다음 더해준다.
				for(k=1;k<=(z - j);k++){
					numtemp[j] = numtemp[j]*10;
				}
				num = num + numtemp[j];
			}
			matStruct.matData[x][y] = num;	//정확한 위치에 num을 대입
			num = 0;
			y++; if(y > matStruct.m){y=0; x++;} //열 혹은 행 증가
		}
		else{
			printf("Error 001");
			printf("숫자와 쉼표 외에는 입력하지 마십시오.");
			return;
		}
		//한 원소의 입력 후 주요 변수 초기화 작업
		num = 0;
		while(z!=0){
			numtemp[z] = 0;
			z--;
		}
	}
}

void showMatrix(Matrix matStruct){
	int i = 0, j = 0; // 각각 행과 열 상징
	printf('\n');
	for(i = 0; i < matStruct.n; i++){
		for(j = 0; j < matStruct.m; j++){
			printf("%d ", matStruct.matData[i][j]);
		}
		printf('\n');
	}
}

void editMatrix(Matrix matStruct){
	printf("%s\n", matStruct.textMat);
	getMatrix(matStruct);
}

void transposeMatrix(Matrix matStruct){
	int temp = matStruct.n;
	matStruct.n = matStruct.m;
	matStruct.m = temp;
	
	// killMatrix 부분
	killData(matStruct);
	
	// getMatrix와 비슷하지만 textMat을 그대로 사용해서 처리
	initializeMatrix(matStruct);
	char len = strlen(matStruct.textMat);
	
	char num = 0;	//숫자를 임시로 저장할 공간이다.
	char numtemp[10] = {}; //숫자를 임시로 저장할 공간이다.
	char z = 0, k = 1;
	char x, y = 0; // 행과 열을 표현하는 숫자다.
	
	//문자를 행과 열로 나눠준다.
	for(int i = 0; i <= len; i++){
		if(matStruct.textMat[i]!="," || matStruct.textMat[i]!="." || matStruct.textMat[i]!=NULL){//숫자 입력. 10진수 단위로 또 만들어줘야한다.
			numtemp[z] = atoi(matStruct.textMat[i]);
			z++;
		}
		elseif(matStruct.textMat[i]==","||matStruct.textMat[i]==NULL){//쉼표나 마지막표시(널값) 들어온 경우 
			for(j=1;j<=z;j++){
				//z-j번씩 10을 곱해준다음 더해준다.
				for(k=1;k<=(z-j);k++){
					numtemp[j] = numtemp[j]*10;
				}
				num = num + numtemp[j];
			}
			matStruct.matData[x][y] = num;	//정확한 위치에 num을 대입
			num = 0;
			y++; if(y > m){y=0; x++;} //열 혹은 행 증가
		}
		else{
			printf("Error 001");
			printf("숫자와 쉼표 외에는 입력하지 마십시오.")
			return -1;
		}
		//한 원소의 입력 후 주요 변수 초기화 작업
		num = 0;
		while(z!=0){
			numtemp[z] = 0;
			z--;
		}
	}
}

void killData(Matrix matStruct){
	for (int i = 0; i < matStruct.n; i++){
		free(matStruct.matData[i]);
	}
	free(matStruct.matData);
}
