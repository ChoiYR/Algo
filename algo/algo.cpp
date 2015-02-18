#include <stdio.h>

int input[30][30];
int Make[30][30];


int find(int x, int y)
{
	if(input[y][x] == 1)
	{
		if(input[y][x+1] == 1)
		{
			Make[y][x+1] = 10;
			find(y, x+1);
		}
		if(input[y+1][x] == 1)
		{
			Make[y+1][x] = 10;
			find(y+1, x);
		}
		if(input[y][x-1] == 1)
		{
			Make[y][x-1] = 10;
			find(y, x-1);
		}
		if(input[y-1][x] == 1)
		{
			Make[y-1][x] = 10;
			find(y-1, x);
		}

		return 1;
	}
	else
		return 0;

	
}

int main()
{
	//몇개의 별자리가 있는가?
	int testcase;
	int length;
	scanf("%d", &testcase);
	while(testcase--)
	{
		scanf("%d", &length);
		for(int j=0; j<length; j++)
		{
			for(int i=0; i<length; i++)
			{
				scanf("%d", &input[j][i]);
			}
		}

		for(int j=0; j < length; j++)
			for(int i=0; i < length; i++)
		getchar();
	}
	return 0;
}