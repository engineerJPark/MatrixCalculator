// 앞으로는 프로그램을 짤 때, 함수(기능)별로 구분하고 그에 해당하는 기능들을 하나씩 추가해서 테스트 우선해보는 방식으로 작성해야겠다. 진짜 에러가 끝도 없어.
// https://m.blog.naver.com/PostView.naver?blogId=whdgml1996&logNo=221038044040&proxyReferer=https:%2F%2Fwww.google.com%2F
// https://onsil-thegreenhouse.github.io/programming/c/2018/08/08/c_tutorial_12/
// matData의 접근을 포인터 형식으로 바꿔야한다.
// Call by dereference를 해야 argument의 내용물을 실질적으로 바꿀 수 있다.

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
	//이제 행과 열을 모두 0으로 초기화한다.
	matStruct->matData = (char**)malloc(sizeof(char**) * matStruct->n);
	for(int i = 0; i < matStruct->n; i++){
		matStruct->matData[i] = (float*)calloc(matStruct->m, sizeof(float) * matStruct->m);
	}
}

//text형태로 행렬을 받는다. ','로 숫자를 구분한다.
void getMatrix(Matrix * matStruct){
	int n, m = 0;
	printf("행의 크기 n, 열의 크기 m을 차례로 입력하세요.");
	scanf("%d", &n); scanf("%d", &m);
	if(n > 5 || m > 5){ printf("본 계산기는 5x5까지만 지원합니다.\n"); return -1;}
	matStruct->n = n; matStruct->m = m;	
	
	initializeMatrix(matStruct);

	matStruct->textMat = (char*)malloc(TEXT_LENGTH);
	printf("데이터를 입력해주세요.");
	scanf("%s", matStruct->textMat);
	 
	char len = strlen(matStruct->textMat);
	char num = 0;	//숫자를 임시로 저장할 공간이다.
	char numtemp[10] = {0}; //숫자를 임시로 저장할 공간이다.
	char z = 0, k = 1;
	char x, y = 0; // 행과 열을 표현하는 숫자다.
	
	// 문자를 행과 열로 나눠준다.
	// 이거야 말로 그냥 atoi() 쓰면 되는데 왜 이렇게?
	for(int i = 0; i <= len; i++){
		if((matStruct->textMat[i] == ',') || (matStruct->textMat[i] == NULL)){
			//쉼표나 마지막표시(널값) 들어온 경우
			for(int j = 1; j <= z; j++){
				//z-j번씩 10을 곱해준다음 더해준다.
				for(k=1;k<=(z - j);k++){
					numtemp[j] = numtemp[j] * 10;
				}
				num = num + numtemp[j - 1];
			}
			matStruct->matData[x][y] = num;	//정확한 위치에 num을 대입
			num = 0;
			y++; if(y > matStruct->m){y=0; x++;} //열 혹은 행 증가
		}
		else{
			//숫자 입력. 10진수 단위로 또 만들어줘야한다.
			numtemp[z] = matStruct->textMat[i]-48; // 단일 문자를 알맞은 숫자로 변환시켜주어야한다.
			z++;
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
	for(i = 0; i < matStruct->n; i++){
		for(j = 0; j < matStruct->m; j++){
			printf("%d ", matStruct->matData[i][j]);
		}
		printf('\n');
	}
}

void editMatrix(Matrix matStruct){
	printf("%s\n", matStruct->textMat);
	getMatrix(matStruct);
}


void killData(Matrix matStruct){
	for (int i = 0; i < matStruct->n; i++){
		free(matStruct->matData[i]);
	}
	free(matStruct->matData);
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
	//안내문
	printf("최대 5x5 행렬을 지원합니다.\n\n");
	printf("행렬의 값을 텍스트로 입력해주세요. ','는 열 방향에서 왼쪽으로 오른쪽으로 하나씩 개행시킵니다.\n");
	printf("숫자와 , . 외의 값을 입력하시면 에러납니다...\n");
	printf("아직까지는 정수형만 지원합니다. 그리고 0이라고 생략하지 말아주세요!\n");
	//초기행렬 입력
	initializeMatrix(matBox[i]);
	getMatrix(matBox[i]);
	showMatrix(matBox[i]);
	
	return 0;
}