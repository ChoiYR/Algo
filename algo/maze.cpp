#include<stdio.h>
#include<stdlib.h>

typedef struct tagMazeInfo{
	int ColumnSize; // 너비
	int RowSize;	// 높이

	char** Data;	// 동적할당한 2차원 배열을 담기 위한 2차원 포인터
}MazeInfo;

typedef struct tagPosition{
	int X;
	int Y;
}Position;

#define START	'S' // 시작점
#define GOAL	'G' // 탈출구
#define WAY		' ' // 길
#define WALL	'#' // 벽
#define MARKED	'+' // 탈출구 표식
#define INITVALUE	-1 // 
#define MAX_BUFFER	1024

enum DIRECTION	{NORTH, SOUTH, EAST, WEST};
enum RESULT		{FAIL, SUCCEED};

//이동방식: 벽과 지나왔던길은 지나가지 않는다.
int Solve(MazeInfo* Maze);
int MoveTo(MazeInfo* Maze, Position* Current, int Direction);
int GetNextStep(MazeInfo* Maze, Position* Current, int Direction, Position* Next);
int GetMaze(char* FilePath, MazeInfo* Maze);

int Solve(MazeInfo* Maze)
{
	
	int StartFound = FAIL;

	Position Start;
	//Finding Starting Point
	for(int i=0; i<Maze->RowSize; i++)
	{
		for(int j=0; j<Maze->ColumnSize; j++)
		{
			if(Maze->Data[i][j] == START)
			{
				Start.X = i;
				Start.Y	= j;
				StartFound = SUCCEED;
				break;
			}
		}
	}
	if(StartFound == FAIL)
		return FAIL;
	//Finding Starting Point End

	//Just Move 4 way
	int Result;
	if( MoveTo(Maze, &Start, NORTH))
		Result = SUCCEED;
	else if( MoveTo(Maze, &Start, SOUTH))
		Result = SUCCEED;
	else if( MoveTo(Maze, &Start, EAST))
		Result = SUCCEED;
	else if( MoveTo(Maze, &Start, WEST))
		Result = SUCCEED;
	//END : 

	Maze->Data[Start.Y][Start.X] = START;
	
	return Result;
}

//Maze, Start Point, direction 
//return if GOAL	->(not) Marking
//					->
int MoveTo(MazeInfo* Maze, Position* Current, int Direction)
{
	int Dirs[] = {NORTH, SOUTH, WEST, EAST};
	Position Next;

	if(Maze->Data[Current->Y][Current->X] == GOAL)
		return SUCCEED;

	Maze->Data[Current->Y][Current->X] = MARKED;

	for(int i=0; i<4; i++)
	{
		if(GetNextStep(Maze, Current, Dirs[i], &Next) == FAIL)
			continue;

		if(MoveTo(Maze, &Next, NORTH) == SUCCEED)
			return SUCCEED;
	}

	Maze->Data[Current->Y][Current->X] = WAY;
	return 0;
}


//Next	Step: by direction, position set 
//		return:  
int GetNextStep(MazeInfo* Maze, Position* Current, int Direction, Position* Next)
{
	switch(Direction)
	{
		case NORTH:
			Next->X = Current->X;
			Next->Y = Current->Y - 1;


			if(Next->Y == -1)
				return FAIL;
			break;
		case SOUTH:
			Next->X = Current->X;
			Next->Y = Current->Y + 1;

			if(Next->Y == Maze->RowSize)
				return FAIL;
			break;
		case WEST:
			Next->X = Current->X-1;
			Next->Y = Current->Y;

			if(Next->X == -1)
				return FAIL;
			break;
		case EAST:
			Next->X = Current->X+1;
			Next->Y = Current->Y;

			if(Next->X == Maze->ColumnSize)
				return FAIL;
			break;
	}

	if(Maze->Data[Next->Y][Next->X] == WALL)
		return FAIL;
	if(Maze->Data[Next->Y][Next->X] == MARKED)
		return FAIL;

	return SUCCEED;
}

int GetMaze(char* FilePath, MazeInfo* Maze)
{
	return 0;
}

int main()
{
	MazeInfo Maze;

	//Row, Column
	scanf("%d %d", &Maze.RowSize, &Maze.ColumnSize);
	getchar();
	Maze.Data = (char**)malloc(sizeof(char*)*Maze.RowSize);
	for(int i=0; i<Maze.RowSize; i++)
	{
		Maze.Data[i] = (char*)malloc(sizeof(char)*Maze.ColumnSize);		
		gets(Maze.Data[i]);
	}

	Solve(&Maze);

	return 0;
}