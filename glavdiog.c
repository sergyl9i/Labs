#include <stdio.h>
#define N 8


int main()
{	

int massive[N][N];
int ZMEIKA[N][N];
		printf("Massive with glavdiagonal\n");
for (int i = 0; i < N; ++i){
	for (int j = 0; j < N; ++j){
		if ((i+j) < N - 1)
			massive[i][j]=0;
		else
			massive[i][j]=1;
		printf("%4d",massive[i][j]);
    }
	printf("\n");
}
for (int i = 0; i < N; ++i){
	for (int j = 0; j < N; ++j){
			ZMEIKA[i][j]=0;
	}
}
int g=0;	
printf("Vvedite pervoe chislo\n");
scanf("%d",&g);
int m=1;
if(N%2 != 0)
ZMEIKA[N/2][N/2]=N*N+g-1;
		printf("Zapolnenie massiva po spiral\n");
for (int i = 0; i < (N/2); ++i){
	for (int j = i; j < N-m*i; ++j){
		ZMEIKA[i][j]=g;
		g++;
	}
	for (int k = i+1; k < N-m*i-1; ++k){
    	ZMEIKA[k][N-i-1]=g;
  		g++;
    }
    for (int z = N-m*i-1; z > m*i; --z){
    	ZMEIKA[N-1-i][z]=g;
    	g++;
    }
    for (int l = N-m*i-1; l > m*i;--l){
    	ZMEIKA[l][i]=g;
    	g++; 	
    }
}
for (int i = 0; i < N; ++i){
	for (int j = 0; j < N; ++j){
		printf("%4d",ZMEIKA[i][j]);
		}
	printf("\n");
	}
	return 0;
}