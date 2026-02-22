#include <stdio.h>
#include <stdbool.h>
void GameOver(int fcount, int val, bool start, int rcount, int bcount, bool *over){
	
	if(fcount == 3 || val >= 20 || !start && ((rcount > 0 && bcount == 0) || (rcount == 0 && bcount > 0))){
		*over = true;
	}
}

int checker(Pos target, Pos arr[], count){ //checks if a cell is a member of a set
	for(int i = 0; i < count; i++){
		if(target.x == arr[i].x && target.y == arr[i].y){
			return 1;
		}
	}
	
	return 0;
}

void getrid(Pos target, Pos arr[], int *count){
	int i;
	int remdex;
	for(i = 0; i < *count; i++){
		if(pos.x == arrF[i].x && pos.y == arrF[i].y){
			remdex = i;
		}
	}

	for(int j = remdex; j < count-1; j++){
		arr[j] = arr[j+1];				
	}
	(*count)--;	
}

void remove(Pos arrR[], Pos arrB[], int *rcount, int *bcount, Pos target, bool *go){
	if(*go){
		
	}
	
	else{
		
	}
}

void replace(Pos arrR[], Pos arrB[], Pos arrS[], Pos arrT[], int *rcount, int *bcount, int *scount, int *tcount, Pos target, bool *found){
	*found = false;
	int r = 0, b = 0;

	if(checker(target, arrR, *rcount)){
		r = 1;
	}

	if(checker(target, arrB, *bcount)){
		b = 1;
	}
	
	if(*go){
		if(b){
				
		}
		if(r){
			*found = true;
		}
		if(!r){

		}
		
	}
	else{
		
	}
}
	
void expand(Pos arrR[], Pos arrB[], Pos arrS[], Pos arrT[], int *rcount, int *bcount, int *scount, int *tcount, Pos target, bool *found, bool *go){	
	int a, b;
	a = target.x;
	b = target.y;
	Pos neighbors[4];
	int n = 0;
	
	if (a > 1){ //up
		neighbors[n++] = (Pos){a-1, b};
		replace(arrR, arrB, arrS, arrT, rcount, bcount, scount, tcount, neighbors[n-1], found);
	}
	if(a < 3){ //down
		neighbors[n++] = (Pos){a+1, b};
		replace(arrR, arrB, arrS, arrT, rcount, bcount, scount, tcount, neighbors[n-1], found);
	}
	if(b > 1){ //left
		neighbors[n++] = (Pos){a, b-1};
		replace(arrR, arrB, arrS, arrT, rcount, bcount, scount, tcount, neighbors[n-1], found);
	}
	if(b < 3){ //right
		neighbors[n++] = (Pos){a, b+1};
		replace(arrR, arrB, arrS, arrT, rcount, bcount, scount, tcount, neighbors[n-1], found);
	}

	remove(arrR, arrB, rcount, bcount, target, go);

}

void update(Pos target, Pos arrR[], Pos arrB[], Pos arrS[], Pos arrT[], int *rcount, int *bcount, int *scount, int *tcount, bool *found, bool *go){
	int s = 0, t = 0;

	if(checker(target, arrS, *scount)){
		s = 1;
	}
	
	if(checker(target, arrT, *tcount)){
		t = 1;
	}
	
	if(!s){
		arrS[*scount] = target;
		(*scount)++;
		*good = !(*good);
	}
	
	if(!(*good) && !t){
		arrT[*tcount] = target;
		(*tcount)++;
		expand(arrR, arrB, arrS, arrT, rcount, bcount, scount, tcount, target, found, go);
	}
}

void nextplayermove(Pos pos, bool *good, bool *start, bool *go, bool *found, Poss arrF[], Pos arrR[], Pos arrB[], Pos arrS[], Pos arrT[] int *rcount, int *bcount,
 int *scount, int *fcount, int *tcount, int *val){

	*good = false;
	
	if(*start){     //start phase

		if(checker(pos, arrF, fcount)){
			*good = true;
			getrid(pos, arrF, fcount);
		}
		
		if(*good){
			arrS[*scount] = pos;
			(*scount)++;
			
			if(*go){
				arrR[*rcount] = pos;
				(*rcount)++;
			}
			else{
				arrB[*bcount] = pos;
				(*bcount)++;
			}
			*go = !(*go);
			*good =!(*good);
			(*val)++;

		}
		
		if(*rcount == 1 && *bcount == 1){
			*start = false;
		}	
		
	}
	
	else{     //expand phase
		if(*go){
			for(int i = 0; i < *rcount && !(*good); i++){
				if(pos.x == arrR[i].x && pos.y ==arrR[i].y){
					*good = true;
				}
			}
		}
		else{
			for(int j = 0; j < *bcount && !(*good); j++){
				if(pos.x == arrB[j].x && pos.y ==arrB[j].y){
					*good = true;
				}
			}			
		}
		
		if(*good){
			*go = !(*go);
			*good = false;
			(*val)++;
			update(pos, arrR, arrB, arrS, arrT, rcount, bcount, scount, tcount, found, go);
		}
	}
	
}

