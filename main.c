#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "functions_dstru.c"

typedef struct {
	int x;
	int y;
} Pos;

int main() {

	bool good = false;
	bool go = true;
	bool start = true;
	bool found = false;
	bool over = false;
	int val = 0;
	
	Pos M[9];
	int m = 1;
	int n = 1;
	
	for(int j = 0; j < 9; j++){
		if(j % 3 == 0 && j != 0){
			m++;
		}
		
		if(n > 3){
			n = 1;
		}
		
		M[j].x = m;
		M[j].y = n;
		n++;
	}
	
	Pos R[9];
	int rcount = 0;
	
	Pos B[9];
	int bcount = 0;
	
	Pos S[9];
	int scount = 0;
	
	Pos T[9];
	int tcount = 0;
	
	Pos F[9];
	int fcount = 9;
	
	for (int i = 0; i < 9; i++) {
    	F[i] = M[i];
	}		
	
	do{
		Pos pos;
		
		printf("Enter cell (x y): ");
    	scanf("%d %d", &pos.x, &pos.y);
    	
		
	
	} while(!GameOver(fcount, val, start, rcount, bcount));
	
	

	return 0;
}
























