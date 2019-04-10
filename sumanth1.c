#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *f1();
void *f2();
void *f3();
void *f4();
int n,a[20],max=0,min=0;
float s=0, avg=0;

void *f1(){
	max=a[0];
	int i;
	for(i=1;i<=n;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
}
void *f2(){
	min=a[0];
	int i;
	for(i=1;i<n;i++){
		if(min>a[i]){
			min=a[i];
		}
	}
}
void *f3(){
	int i;
	for(i=0;i<n;i++){
		s=s+a[i];
	}
	avg = s/i;
}
void *f4()
{
	pthread_t t1,t2,t3;
	pthread_create(&t1,NULL,f1,NULL);
	pthread_create(&t2,NULL,f2,NULL);
	pthread_create(&t3,NULL,f3,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	printf("\nThe maximum value is:%d\n",max);
	printf("\nThe minimum value is:%d\n",min);
	printf("\nThe average value is:%f\n",avg);
}
int main(){
	printf("Enter no. of Elements :");
	scanf("%d", &n);
	printf("Enter values in Array:");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	pthread_t th;
	printf("Elements in Array are:[%d]",a[n]);
	pthread_create(&th,NULL,f4,NULL);
	pthread_join(th,NULL);
}
