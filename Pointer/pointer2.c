#include <stdio.h>

void move_p(int **pointer, int arr[]){
	*pointer = &arr[1];
}

int main()
{
	int arr[]={5, 6, 7, 8, 9};
	int *p = &arr[0];
	move_p(&p, arr);
	printf("%d\n", *p);
}
