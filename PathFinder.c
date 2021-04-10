#include <stdio.h>
#include <stdlib.h>

// Task 2: Take Input maxY strings of maxX characters each:
void inputMaze(char maze[], int maxX, int maxY)
{
	for (int i = 0; i < maxX; i++)
	{
		printf("input row %d:", i);
		scanf("%s", &maze[i * maxY]);
	}
}

// Task 3: Print the maze in console
void printMaze(char maze[], int maxX, int maxY)
{
	//printf("Maze:\n");
	// for each row
	for (int i = 0; i < maxX; i++)
	{
		for (int j = 0; j < maxY; j++)
			printf("%c", maze[i*maxY+j]);
		printf("\n");
	}
}

// Task 4: Find the starting point S
int findStart(char maze[], int maxX, int maxY)
{
	printf("Maze:\n");
	// for each row
	for (int i = 0; i < maxX; i++)
		for (int j = 0; j < maxY; j++)
			if (maze[i * maxY + j] == 'S' || maze[i * maxY + j] == 's')
				return i * maxY + j;
	return -1;
}

// Task 5: Find the path towards destination 
int findPath(char maze[], int maxX, int maxY, int x, int y)
{
	if (x < 0 || x >= maxX || y < 0 || y >= maxY)
		return 0;
	if (maze[x * maxY + y] == 'd' || maze[x * maxY + y] == 'D')
		return 1;
	if (maze[x * maxY + y] != '.' && maze[x * maxY + y] != 's' && maze[x * maxY + y] != 'S')
		return 0;

	// do not modify the entry point S
	if (maze[x * maxY + y] != 's' && maze[x * maxY + y] != 'S')
		maze[x * maxY + y] = '+';

	if (findPath(maze, maxX, maxY, x, y-1) == 1) return 1;
	if (findPath(maze, maxX, maxY, x+1, y) == 1) return 1;
	if (findPath(maze, maxX, maxY, x, y+1) == 1) return 1;
	if (findPath(maze, maxX, maxY, x-1, y) == 1) return 1;
	if (maze[x * maxY + y] != 's' && maze[x * maxY + y] != 'S')
		maze[x * maxY + y] = '.';
	return 0;
}

int main()
{
	// Task 1: Input the number of rows and columns of the maze
	int r, c;
	printf("Number of rows: ");
	scanf("%d", &r);

	printf("Number of columns: ");
	scanf("%d", &c);

	if (r * c > 300)
	{
		printf("Number of cells exceeds maximum!\n");
		return 1;
	}

	char maze[302];

	inputMaze(maze, r, c);
	int s = findStart(maze, r, c);
	if (s == -1)
	{
		printf("Maze contains no starting point!\n");
		return 2;
	}

	printMaze(maze, r, c);
	if (findPath(maze, r, c, s / c, s % c) == 1)
	{
		printf("Found path!\n");
		printMaze(maze, r, c);
	}
	else
		printf("No path found!\n");
	return 0;
}

