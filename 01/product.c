//Write a program which accepts two integers x and y. Now use exec to execute another user defined program that prints the product of x and y

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
	int x;
	int y;
	scanf("%d", &x);
	scanf ("%d", &y);

	execl("'/Users/sudiksha/sudiksha/Acad/Sem_4/Operating_Systems/Assignments/01/xyz.c'", "a", "-ux", NULL);

	

}