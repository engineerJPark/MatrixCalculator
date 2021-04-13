#include<stdio.h>

//Mat은 행렬의 주소
//*Mat은 행렬의 하나의 행을 지정
//**Mat은 행렬의 하나의 원소(열)를 지정한다.
typedef struct Matrix{
int n, m;	//행렬의 행과 열의 크기
char** Mat;	//행렬 그자체
} Matrix;

void getMatrix(Matrix Matpar);
void initializeMatrix(Matrix MatStruct);
void showMatrix(Matrix Matpar);

void main(){
	//생성된 행렬 개수를 세는 변수.
	i = 0;
	//행렬구조체의 주소가 저장되는 곳. 배열로 쉽게 접근할 예정이다.
	Matrix *MatBox;
	//초기 행렬 초기화. 초기 모든 행렬 원소가 0이 되도록 한다.
	Matrix initMat;
	MatBox[0] = initMat;
	//안내문
	printf("최대 5x5 행렬을 지원합니다.\n\n");
	printf("행렬의 값을 텍스트로 입력해주세요. ','는 열 방향에서 왼쪽으로 오른쪽으로 하나씩 개행시킵니다.\n");
	printf("숫자와 , . 외의 값을 입력하시면 에러납니다...\n");
	printf("0이라고 생략하지 말아주세요!\n");
	//초기행렬 입력
	getMatrix(initMat);

	//작동 중에 해야할것
	while(1){
		//행렬수정
		
		//행렬추가

		//전치

		//리듀스

		//역행렬
		
		//determinant

		//합

		//곱

		//Eigenvalue

		//Eigenvector
		
		//연산식 입력 및 결과 show
	}
}

//text형태로 행렬을 받는다. ','로 숫자를 구분한다.
void getMatrix(Matrix Matpar){
	printf("행의 크기 n, 열의 크기 m을 차례로 입력하세요.");
	scanf("%d", &n);
	scanf("%d", &m);

	char * textMat = (char)Malloc(512);
	scanf("%s", textMat);
	char len = strlen(textMat);
	
	char num = 0;	//숫자를 임시로 저장할 공간이다.
	char numtemp[10] = {};
	char z = 0, k = 1;
	char x,y = 0;
	
	//문자를 행과 열로 나눠준다.
	for(i = 0; i <= len; i++){
		if(textMat[i]!=","||textMat[i]!="."){//숫자 입력. 10진수 단위로 또 만들어줘야한다.
			numtemp[z] = atoi(textMat[i]);
			z++;
		}
		elseif(textMat[i]==","||textMat[i]==NULL){//쉼표나 마지막표시(널값) 들어온 경우 
			for(j=1;j<=z;j++){//z-j번씩 10을 곱해준다음 더해준다. 된다.
				for(k=1;k<=(z-j);k++){
					num = num + numtemp[j]*10;
				}
			}
			Matpar[x][y] = num;	//정확한 위치에 num을 대입
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

//5x5행렬을 전부 0으로 초기화한다.
void initializeMatrix(Matrix MatStruct){
	printf("행렬의 행 크기는?");
	scanf("%d", &(Mat.n));
	printf("행렬의 행 크기는?");
	scanf("%d", &(Mat.m));
	//이제 행과 열을 모두 0으로 초기화한다.
	MatStruct.Mat = (char**)Malloc(sizeof(char*) * n);
	for(i = 0; i < n; i++){
		MatStruct.Mat[i] = (int*)calloc(m, sizeof(int) * m);
	}
}


// getMatrix에서 행,열 크기 제한 걸기
// showMatrix 함수 만들기
// initializeMatrix를 getMatrix 안에 넣기