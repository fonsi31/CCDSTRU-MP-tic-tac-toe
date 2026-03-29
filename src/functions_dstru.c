#include "../include/header.h"

/**
 *Constantly checks if the conditions that will end the game is met
 *Sets *over to true if conditions are met
*/
void GameOver(int fcount, int val, bool start, int rcount, int bcount, bool *over){
	if((fcount == 3 || val >= 20 || !start) && ((rcount > 0 && bcount == 0) || (rcount == 0 && bcount > 0))){
		*over = true;
	}
}

/**
 *Checks if a cell is a member of a set
 *Returns 1 if a cell belongs to a set, returns 0 otherwise
*/
int checker(Pos target, Pos arr[], int count){
	for(int i = 0; i < count; i++){
		if(target.x == arr[i].x && target.y == arr[i].y){
			return 1;
		}
	}
	return 0;
}

/**
 *Removes a cell from a set
*/
void getrid(Pos target, Pos arr[], int *count){
	int remdex = -1;

	for(int i = 0; i < *count && remdex == -1; i++){
	    if(target.x == arr[i].x && target.y == arr[i].y){
	        remdex = i;
	    }
	}
	if(remdex != -1){
		for(int j = remdex; j < *count - 1; j++){
			arr[j] = arr[j+1];
		}
		(*count)--;
	}
}

/**
 *Removes a cell from a player's possession after using that cell to expand
 *It also removes that cell from set S and set T
*/
void removePos(Pos arrR[], Pos arrB[], Pos arrS[], Pos arrT[], int *rcount, int *bcount,int *scount, int *tcount, Pos target, bool *go){
	
	if (*go)
		getrid(target, arrR, rcount);
	else
		getrid(target, arrB, bcount);
		
	getrid(target, arrS, scount);
	getrid(target, arrT, tcount);
	
}

/**
 *Transfers a cell from one player to the other if it falls within expansion range.
*/
void replace(Pos arrR[], Pos arrB[], Pos arrS[], Pos arrT[], Pos arrF[], int *rcount, int *bcount, int *scount, int *tcount, int *fcount, Pos target, bool *found, bool *go){
	*found = false;
	if(*go){
		if(checker(target, arrB, *bcount)){
			getrid(target, arrB, bcount);
			*found = true;
		}
		
		if(checker(target, arrR, *rcount)){
			*found = true;
		}
		else{
			arrR[*rcount] = target;
			(*rcount)++;
			getrid(target, arrF, fcount);
		}
		
	}
	else{
		if(checker(target, arrR, *rcount)){
			getrid(target, arrR, rcount);
			*found = true;
		}
		
		if (checker(target, arrB, *bcount)){
			*found = true;
		}
		else{
			arrB[*bcount] = target;
			(*bcount)++;
			getrid(target, arrF, fcount);
		}
	}
	
	if(*found && !checker(target, arrS, *scount)){
		arrS[*scount] = target;
		(*scount)++;
	}
	
	else if(*found && !checker(target, arrT, *tcount)){
		arrT[*tcount] = target;
		(*tcount)++;
		expand(arrR, arrB, arrS, arrT, arrF, rcount, bcount, scount, tcount, fcount, target, found, go);
	}
}

/**
 *Determines which cells a player can take during expansion
*/	
void expand(Pos arrR[], Pos arrB[], Pos arrS[], Pos arrT[], Pos arrF[], int *rcount, int *bcount, int *scount, int *tcount, int *fcount, Pos target, bool *found, bool *go){	
	int a, b;
	a = target.x;
	b = target.y;
	Pos neighbors[4];
	int n = 0;

	removePos(arrR, arrB, arrS, arrT, rcount, bcount, scount, tcount, target, go);
	
	if(*go){
		if (a > 1){ //up
			neighbors[n++] = (Pos){a-1, b};
			replace(arrR, arrB, arrS, arrT, arrF, rcount, bcount, scount, tcount, fcount, neighbors[n-1], found, go);
		}
	}
	else{
		if(a < 3){ //down
			neighbors[n++] = (Pos){a+1, b};
			replace(arrR, arrB, arrS, arrT, arrF, rcount, bcount, scount, tcount, fcount, neighbors[n-1], found, go);
		}
	}

	if(b > 1){ //left
		neighbors[n++] = (Pos){a, b-1};
		replace(arrR, arrB, arrS, arrT, arrF, rcount, bcount, scount, tcount, fcount, neighbors[n-1], found, go);
	}
	if(b < 3){ //right
		neighbors[n++] = (Pos){a, b+1};
		replace(arrR, arrB, arrS, arrT, arrF, rcount, bcount, scount, tcount, fcount, neighbors[n-1], found, go);
	}
}

/**
 * Determines if a player can use a cell for expansion
*/
void update(Pos target, Pos arrR[], Pos arrB[], Pos arrS[], Pos arrT[], Pos arrF[], int *rcount, int *bcount, int *scount, int *tcount, int *fcount, bool *found, bool *go, bool *good){
	if(!checker(target, arrS, *scount)){
		arrS[*scount] = target;
		(*scount)++;
	}
	else if(checker(target, arrS, *scount) && !checker(target, arrT, *tcount)){ //Expansion only happens if a cell belongs to S but doesn't belongs to T
		arrT[*tcount] = target;
		(*tcount)++;
		expand(arrR, arrB, arrS, arrT, arrF, rcount, bcount, scount, tcount, fcount, target, found, go);
	}
}

/**
 * Validates the selected cell and maintains proper turn tracking between players.
*/
void nextplayermove(Pos pos, bool *good, bool *start, bool *go, bool *found, Pos arrF[], Pos arrR[], Pos arrB[], Pos arrS[], Pos arrT[], int *rcount, int *bcount,
 int *scount, int *fcount, int *tcount, int *val){
	*good = false;
	if(*start){     //start phase (both players will pick their starting position)

		if(checker(pos, arrF, *fcount)){
			*good = true;
			getrid(pos, arrF, fcount);
		}
		
		if(*good){
			(*val)++;
			if(*go){
				arrR[*rcount] = pos;
				(*rcount)++;
				arrS[*scount] = pos;
				(*scount)++;
			}
			else{
				arrB[*bcount] = pos;     
				(*bcount)++;
				arrS[*scount] = pos;
				(*scount)++;
			}
			*go = !(*go);
		}
		if(*rcount == 1 && *bcount == 1){ //Proceed to expand phase once both players successfuly picked a starting position
			*start = false;
		}	
	}
	
	else{     //expand phase
		if((*go && checker(pos, arrR, *rcount)) || (!(*go) && checker(pos, arrB, *bcount))){ //checks if the input is already on the player's posession
			*good = true;
			(*val)++;
			update(pos, arrR, arrB, arrS, arrT, arrF, rcount, bcount, scount, tcount, fcount, found, go, good);
			*go = !(*go);
		}
	}
}

/**
 * Displays the board
*/
void display(Pos arrM[], Pos arrR[], Pos arrB[], int rcount, int bcount){
	printf("\n");
	for (int i = 0; i < 9; i++){
    	if(checker(arrM[i], arrR, rcount)){
        	printf("  R  ");
    	}
    	else if(checker(arrM[i], arrB, bcount)){
        	printf("  B  ");
    	}
    	else{
        	printf("(%d,%d)", arrM[i].x, arrM[i].y);
    	}

    	if(i == 2 || i == 5 || i == 8){
        	printf("\n");
    	}
	}	
}
