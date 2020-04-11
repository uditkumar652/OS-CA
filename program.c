#include<stdio.h>
#include<pthread.h>

int a[50],num,iter;

void *thread1()
{
	int sum=0;
	float avg=0;

	for(iter=0;iter<num;iter++)
	{
		sum+=a[iter];
	}
	avg=sum/num;
	printf("The average value is:: %f",avg);
}

void *thread2()
{
	int min=a[0];
	for(iter=1;iter<num;iter++)
	{
		if(min>a[iter])
		    min=a[iter];
	}
	printf("\nThe Minimum value is:: %d",min);
}


int main()
{
	printf("Enter Number of Elements::");
	scanf("%d",&num);
	for(iter=0;iter<num;iter++)
	     sacnf("%d",&a[iter]);
	
	pthread_t t1,t2,t3;
	n=pthread_create(&t1,NULL,&thread1,NULL);
	pthread_join(t1,NULL);

	n=pthread_create(&t2,NULL,&thread2,NULL);
	pthread_join(t2,NULL);

	return 0;
}
