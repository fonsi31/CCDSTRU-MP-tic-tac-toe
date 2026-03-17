#include "../include/header.h"

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
	
	Pos R[9]; //stores player R cells
	int rcount = 0;
	
	Pos B[9]; //stores player B cells
	int bcount = 0;
	
	Pos S[9];
	int scount = 0;
	
	Pos T[9];
	int tcount = 0;
	
	Pos F[9]; //Contains free cells
	int fcount = 9;
	
	for (int i = 0; i < 9; i++) {
    	F[i] = M[i];
	}	
	
	do{
		Pos pos;
		do{
			system("cls");
			display(M, R, B, rcount, bcount);
			
			if(start){
				printf("*****Starting Phase*****\n");
				printf("Pick a starting position\n");
				
			}
			else{
				printf("*****Expansion Phase*****\n");
				printf("Note: A player can only pick a cell that is in their possesion\n");
			}	
					
			if(go){
				printf("Enter a cell for R (x y): ");
			}
			else{
				printf("Enter a cell for B (x y): ");
			}
    		scanf("%d %d", &pos.x, &pos.y);
    		nextplayermove(pos, &good, &start, &go, &found, F, R, B, S, T, &rcount, &bcount, &scount, &fcount, &tcount, &val);
    		
		}while(!good);
		
		GameOver(fcount, val, start, rcount, bcount, &over);
	} while(!over);
	
	printf("\nGame Over\n");
	
	if(rcount > bcount){
		printf("R WON");
		
	}
	else if(bcount > rcount){
		printf("B WON");
	}
	else{
		printf("draw");
	}
	printf("\n");
	printf("\nFinal Board:\n");
	display(M, R, B, rcount, bcount);
	
	return 0;
}






