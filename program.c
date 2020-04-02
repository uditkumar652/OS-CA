#include<stdio.h>
#include<pthread.h>

int a[50],num,iter;

void *thread1()
{
	int sum=0;
	float avg=0;
	printf("Enter Number of Elements::");
	scanf("%d",&num);
	for(iter=0;iter<num;iter++)
	     sacnf("%d",&a[iiter]);
	for(iter=0;iter<num;iter++)
	{
		sum+=a[iter];
	}
	avg=sum/num;
	printf("The average value is:: %f",avg);
}


void main()
{
	pthread_t t1;
	n=pthread_create(&t1,NULL,&thread1,NULL);
	pthread_join(t1,NULL);
}
















