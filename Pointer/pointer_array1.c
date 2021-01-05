
#include <stdio.h> 
int main()
{
		int a[5] = {1,2,3,4,5};
		int *ptr1 = (int*)(&a + 1);
		int *ptr2 = (int*)(a + 1);

		printf("a = %p\n", a);
		printf("&a = %p\n", &a);
		printf("a+1 = %p\n", a+1);
		printf("&a+1 = %p\n", &a+1);

		printf("%x\n", ptr1[-1]);    //the value is 5
		printf("%x\n", *ptr2);       //the value is 2
		return 0;
}
