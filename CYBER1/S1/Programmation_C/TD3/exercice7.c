#include <stdio.h>

int compareTab(int tabA[], int nA, int tabB[], int nB){
	int value=1;
	for (int i=0; i<nA; i++){
		if (tabA[i]!=tabB[i]){
			value=0;
		}
	}
	printf("%d",value);
	return value;

}

int main(){
	int tableauA[5]={-6,5,2,8,10};
	int nombreA=5;
	int tableauB[5]={-6,5,2,8,10};
	int nombreB=5;
	compareTab(tableauA, nombreA, tableauB, nombreB);
	return 0;
}
