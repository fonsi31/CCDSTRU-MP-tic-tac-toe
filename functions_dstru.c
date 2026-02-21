#include <stdio.h>
#include <stdbool.h>
bool GameOver(int fcount, int val, bool start, int rcount, int bcount){
	
	if(fcount == 3 || val >= 20 || !start && ((rcount > 0 && bcount == 0) || (rcount == 0 && bcount > 0))){
		return true;
	}
	
	return false;
}

void remove(Pos arr[], int *count, Pos target){
	
}

void replace(Pos arr[], Pos target, int count){
	
}
      
void expand(Pos arr[], int *count, int additional, Pos target[]){	
	
}

void update(Pos target, Pos arrS[], Pos arrT[], int *scount, int *tcount, *good){
	*good = false;
	
	int j, k;
	int i, m;
	
	j = 0;
	k = 0;
	for (i = 0; i < *scount; i++){
		if(target == arrS[i]){
			j = 1;;
		}
	}
	
	for (m = 0; i < *tcount; m++){
		if(target == arrT[m]){
			k = 1;
		}		
	}
	
	if(j == 0){
		arrS[*scount] = target;
		(*scount)++;
		*good = !(*good);
	}
	
	else if(!(*good) && j == 1 && k == 0){
		arrT[*tcount] = target;
		(*tcount)++;
		expand();
	}
}

void nextplayermove(Pos pos, bool *good, bool *over, bool *start, bool *go, Poss arrF[], Pos arrR[], Pos arrB[], Pos arrS[], int *rcount, int *bcount, int *scount, int *fcount, int *val){
	
	if (!(*over) && *start && *go){
		arrR[*rcount] = pos;
		arrS[*scount] = pos;
		(*rcount)++;
		(*scount)++;
		(*fcount)--;
		*good = true;
	}
	
	else if (!(*over) && *start && !(*go)){
		arrR[*bcount] = pos;
		arrS[*scount] = pos;
		(*bcount)++;
		(*scount)++;
		(*fcount)--;
		*good = true;
	}
	
	int j = 0;
	int k = 0;
	
	for(int i = 0; i < *rcount; i++){
		if(pos.x == arrR[i].x && pos.y == arrR[i].y){
			j = 1;
		}
	}
	
	for(int l = 0; l < *bcount; l++){
		if(pos.x == arrB[l].x && pos.y == arrB[l].y){
			k = 1;
		}		
	}
	
	if (!(*over) && !(*start) && ((*go && j == 1) || (!(*go) && k ==1))){
		update();
		*good = true;
	}
	
	if(*start && *rcount == 1 && *bcount == 1){
		*start = false;
	}
	
	if(!(*over) && *good){
		*good = !(*good);
		*go = !(*go);
		(*val)++;
	}	
}







