#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fptr;
	fptr = fopen("input.txt","w+");
	int c;
	fscanf(fptr,"%d",&c);
	fscanf(fptr,"%d",&c);
	fscanf(fptr,"%d",&c);
	fscanf(fptr,"%d",&c);
	//fprintf(fptr,"%s", "huanden");
	printf("%d\n",c);
}