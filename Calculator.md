# 참고할 사이트

https://stackoverflow.com/questions/26652992/struct-anonymous-has-no-member-named
https://devzone.nordicsemi.com/f/nordic-q-a/11555/no-member-named-power-in-nrf_twi_type-aka-struct-anonymous
https://stackoverflow.com/questions/16799360/struct-has-no-member-named/16799503
https://stackoverflow.com/questions/30168454/struct-has-no-member-named
https://www.daniweb.com/programming/software-development/threads/436924/struct-x-has-no-member-named-y
https://www.linuxquestions.org/questions/programming-9/gcc-error-%91foo%92-has-no-member-named-%91bar%92-877951/


# 프로젝트를 하면서 배운 점

앞으로는 프로그램을 짤 때, 함수(기능)별로 구분하고 그에 해당하는 기능들을 하나씩 추가해서 테스트 우선해보는 방식으로 작성해야겠다. 진짜 에러가 끝도 없어.
https://m.blog.naver.com/PostView.naver?blogId=whdgml1996&logNo=221038044040&proxyReferer=https:%2F%2Fwww.google.com%2F
https://onsil-thegreenhouse.github.io/programming/c/2018/08/08/c_tutorial_12/

함수를 따로 만들기


다중배열과 포인터 표현
http://pelex529.blogspot.com/2009/01/2.html
https://mynameisdabin.tistory.com/32
https://mynameisdabin.tistory.com/9?category=786516

포인터 정리
https://pridiot.tistory.com/217
https://kookyungmin.github.io/language/2017/08/11/C04/
https://skmagic.tistory.com/67
https://www.youtube.com/watch?v=g1Bu4FiJVyQ

포인터와 문자열
https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=dw5637&logNo=100043598497
https://dojang.io/mod/page/view.php?id=337

이중포인터
https://chanywa.com/343

NULL, \0의 차이
https://code4human.tistory.com/116

올린 질문
https://stackoverflow.com/questions/67724797/cant-find-the-problem-of-stack-smashing-detected-unknown-terminat?noredirect=1#

배운 것
디버거 꼭 쓰자. 디버거를 얼마나 잘 쓰는지가 프로그램의 완성 시간을 가른다.



----

# Test

```
#include <stdio.h>
#include <stdlib.h>

void initialize(char * a){
	a = malloc(sizeof(char));
}
// 주소값이더라도 scope를 벗어나면 그냥 해제된다 이말이다....
// 이중으로 포인터를 사용하거나, 아니면 main에서 사용하거나.


int main(){
	char *a;
	
	initialize(a);
	
	*a = 1;
	
	return 0;
}
```

```
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TEXT_LENGTH 512
#define MATMAXNUMBER 10
#define ERRORTEST printf("no error\n");

typedef struct Matrix{
	int n;
	int m;	//행렬의 행과 열의 크기
	char ** matData;	//행렬의 data
	char * textMat;
} Matrix;

//5x5행렬을 전부 0으로 초기화한다.
void initializeMatrix(Matrix * matStruct){
	//이제 행과 열을 모두 0으로 초기화한다.
	matStruct->matData = malloc(sizeof(char*) * matStruct->n);
	for(int i = 0; i < matStruct->n; i++){
		matStruct->matData[i] = calloc(matStruct->m, sizeof(float) * matStruct->m);
	}
	matStruct->textMat = malloc(TEXT_LENGTH);
}
// 이렇게 -> 연산자를 사용해서 접근하는데도안된다?
// 대체 왜인가? ->는 *. 아닌가? 왜 안되징?
// matStruct의 주소 복사본이 들어가는 거 아닌가...
// 왜 안되나..?
// 어쨌든 전역변수 선언을 하던가... 아니면, 어떻게 하나...
```

```
#include <stdio.h>
int main(){
	Matrix * a;
	initializeMatrix(a);
	
	a->matData[1][1] = 1;
	
	return 0;
}
```


/*----------------*/
// scope를 벗어낫다고 malloc으로 할당받은 메모리가 해제되지는 않는다는 것이다.

```
#include <stdio.h>

int main(){
	int *p;
	
	{
		p = malloc(80);
	}
	
	*p = 1;
	printf("%d\n", *p);
}
```

/*이거는 오류가 난다.*/

```
#include <stdio.h>

void func(int *p){
	p = malloc(80);
}

int main(){
	int *p;
	
	func(p);
	
	*p = 1;
	printf("%d\n", *p);
}
```

/*이건 된다. 이런 경우를 위해서 이중포인터가 존재한다.*/
```
#include <stdio.h>

void func(int **p){
	*p = malloc(80);
}

int main(){
	int *p;
	
	func(&p);
	
	*p = 1;
	printf("%d\n", *p);
}
```

/*-----------------------*/
// https://onsil-thegreenhouse.github.io/programming/c/2018/08/08/c_tutorial_12/
// https://thrillfighter.tistory.com/124
```
#include "stdio.h"
#include "malloc.h"

char* get(char *name)
{
	name = malloc(80); // malloc으로 복사된 name의 값을 새로 바꿔주는 것 뿐이다. 원래의 argument를 바꿔주는 것이 아니다.
	printf("Input name : ");
	scanf("%s", name);
	
	return name;
}


int main()
{
	char* str;
	str = get(str);

	printf("name = %s\n", str);

	free(str);

	return 0;
}
```
/*더 정확히 메모리를 이용한 실험*/

```
#include <stdio.h>

void func(int *p){
	printf("In the function\n");
	printf("%x\n", &p);
	printf("%x\n", p);
}

int main(){
	int *p;
	
	func(p);
	
	printf("\n");
	printf("In the main function\n");
	printf("%x\n", &p);
	printf("%x\n", p);
}
```
/*
출력은 아래와 같다.
In the function
3ad55cc8 // 복사된 p의 주소
3ad55dd0 // p가 담고있는 값

In the main function
3ad55ce0 // 원래 p의 주소
3ad55dd0 // p가 담고있는 값

즉 p가 가지고 있는 주소값 자체는 잘 복사되서 전달되지만, func()에 p가 인자로 전달되면서 새로운 복사된 p가 메모리에 새로 배정받는다.
그리고 거기에 있는 값에 영향을 줘봤자, main에 있는 p의 값을 바꿔주진 않는다.
*/

/*
그럼 구조체 연산에 대해선 어떨까
*/
```
typedef struct Test{
	int a;
	int *str;
} Test;

#include <stdio.h>

void func(Test *t){
	
	t->str = malloc(80);
	(t->str) = 1;
	printf("In the function\n");
	printf("%x\n", &t);
	printf("%x\n", t);
	printf("%x\n", &(t->a));
	printf("%x\n", t->a);
	printf("%x\n", &(t->str));
	printf("%x\n", t->str);
}

int main(){
	Test *t = malloc(sizeof(Test));
	
	func(t);
	
	printf("\n");
	printf("In the main function\n");
	printf("%x\n", &t);
	printf("%x\n", t);
	printf("%x\n", &(t->a));
	printf("%x\n", t->a);
	printf("%x\n", &(t->str));
	printf("%x\n", t->str);
}
```
/*
In the function
e4796a18
53ee4260
53ee4260
0
53ee4268
1

In the main function
e4796a40
53ee4260
53ee4260
0
53ee4268
1

보면 func()에서는 아예 넘겨받은 t에 대해서 새로운 struct를 생성해주는 것을 알 수 있다.
*/

----

```
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TEXT_LENGTH 512
#define MATMAXNUMBER 10
#define ERRORTEST printf("no error\n");

typedef struct Matrix{
	// row and coloum
	int n;
	int m;
	
	// data of matrix
	char ** matData;
	char textMat[TEXT_LENGTH];
} Matrix;

Matrix *initializeMatrix(Matrix * matStruct){
	matStruct->matData = malloc(sizeof(char*) * matStruct->n);
	for(int i = 0; i < matStruct->n; i++){
		matStruct->matData[i] = calloc(matStruct->m, sizeof(float) * matStruct->m);
	}
	
	matStruct->matData[0][0] = 1;
	matStruct->textMat[0] = 1;
	
	printf("%x\n", &matStruct);
	printf("%x\n", matStruct);
	printf("%x\n", &(matStruct->matData));
	printf("%x\n", matStruct->matData);
	printf("%x\n", matStruct->matData[0][0]);
	printf("%x\n", &(matStruct->textMat));
	printf("%x\n", matStruct->textMat);
	printf("%x\n", matStruct->textMat[0]);
	
	return matStruct;
}

int main(){
	Matrix * matStruct;
	
	initializeMatrix(matStruct);
	
	printf("\n\n", &matStruct);
	
	printf("%x\n", &matStruct);
	printf("%x\n", matStruct);
	printf("%x\n", &(matStruct->matData));
	printf("%x\n", matStruct->matData);
	printf("%x\n", matStruct->matData[0][0]);
	printf("%x\n", &(matStruct->textMat));
	printf("%x\n", matStruct->textMat);
	printf("%x\n", matStruct->textMat[0]);
	
	
	return 0;
}
```

/*
9b8fc98
9b8fdc0
9b8fdc8
80cd3260
1
9b8fdd0
9b8fdd0
1

9b8fcd0
9b8fdc0
9b8fdc8
80cd3260
1
9b8fdd0
9b8fdd0
1
*/
