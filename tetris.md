/*
경계조건
- 벽과의 충돌
- 기존 블록과의 충돌
- 게임오버 조건
- 회전 불가 조건 - 회전해서 지형지물에 부딫히면 안돌아간다.

조작 함수
- 아래-바로꽂기
- 위-우회전
- 왼쪽, 오른쪽

블록 - 각 회전에 따른 형태를 정의해주어야한다.
- 네모 - block_O
- 막대 - block_I
- 기역1, 기역2 - block_J, block_L
- 번개1, 번개2 - block_Z, block_S
- 꽂이 - block_T

각각의 중심축을 정하기 : 회전을 위해서
랜덤함수로 블록 자동으로 나오게 설정
1초마다 자동으로 아래로 간다.

참고
https://blockdmask.tistory.com/51
*/
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define SPACE_WIDTH 12
#define SPACE_HEIGHT 21

#define BLOCK_O 1
#define BLOCK_I 2
#define BLOCK_Z 3
#define BLOCK_S 4
#define BLOCK_J 5
#define BLOCK_L 6
#define BLOCK_T 7

// 가로 0, 11은 WALL, 세로 20도 WALL
char space[SPACE_WIDTH][SPACE_HEIGHT] = {0};

// 3차원 배열로 블록을 정의한다.
// 4*4 공간으로 표현한다.
block[7][4][4]={
	{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
	{{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
	{{},{},{},{}},
	{{},{},{},{}},
	{{},{},{},{}},
	{{},{},{},{}},
	{{},{},{},{}}
};


void MoveRight(char blockNumber){
	switch (blockNumber){
		case 0:
			
	}
	
}

void MoveLeft(char blockNumber){
	
}

void MoveDown(){
	
}

void TurnBlcok(){
	
}