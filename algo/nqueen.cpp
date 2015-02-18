
#include <stdio.h>

int check(int x, int &y, int tb[15][15], int N)
{
	for(int i=1; i<=y; i++)
	{
		if(	tb[y-i][x] == 1 ||
			(x>=i && (tb[y-i][x-i] == 1))||
			(x+i<N && (tb[y-i][x+i] == 1)))
			return 0;
	}
	
	return 1;
}

int xlayer(int x, int &y, int tb[15][15], int N)
{
	int i;
	for(i=0; i<N; i++)
	{
		if(check(i, y, tb, N) == 0)
			continue;
		else
		{
			
			tb[y][i] = 1;
			y++;
			if(y == N)
				return 1;
			if(xlayer(0, y, tb, N) == 1)
				break;
			tb[y][i] = 0;
		}
	}
	if(y == N)
		return 1;
	y--;
	return 0;
}

int ylayer(int &x, int &y, int tb[15][15], int N)
{
	
	if(xlayer(x, y, tb, N) == 1)
	{
		x = 0;
		y = 0;
		return 1;
	}
	else
	{
		x = 0;
		y = 0;
		return 0;
	}
	
}

int main()
{
	// H<= 99 W <= 99
	int testcase;
	
	scanf("%d", &testcase);
	while(testcase--)
	{
		int N;
		int x = 0, y = 0;
		scanf("%d", &N);

		int result = 0;
		for(int i=0; i<N; i++)
		{
			int tb[15][15] = {0,};
			tb[0][i] = 1;
			y++;
			if(ylayer(x, y, tb, N) == 1)
				result++;
		}
		printf("%d\n", result);
	}

	return 0;
}