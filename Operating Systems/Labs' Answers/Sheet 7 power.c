#include <stdlib.h>
#include <pthread.h>

struct nums{
int x;
int y;
};

void* power(void* val){
	struct nums* valT = (struct nums*) val;
	int i=0;
	int result=1;
	for(i;i < valT->y;i++){
		result*=valT->x;
	}

	printf("%d power of %d is %d\n",valT->x,valT->y,result);
	pthread_exit(NULL);
}


void main()
{
	pthread_t thr;
	int num1,num2;
	printf("Please enter the base value\n");
	scanf("%d",&num1);
	printf("Please enter the power value\n");
	scanf("%d",&num2);

	struct nums* num3 = malloc(sizeof(struct nums));
	num3->x=num1;
	num3->y=num2;

	pthread_create(&thr,NULL,power,(void*) num3);

	pthread_exit(NULL);
}

