#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
This is a sample test
to show you_How it works
*/
int main(int argc, char *argv[]) {
	int arr[127]={0},i;
	char c;
	for(i=0;i<2;i++){
		while((c=getchar())!='\n'){
			if(arr[(int)c]==0){
				arr[(int)c]=1;
				printf("%c",c);
			}
		}
	}
	return 0;
}
