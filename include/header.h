#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/* ===== Structs ===== */

typedef struct {
    int x;
    int y;
} Pos;


/* ===== Function Prototypes ===== */

void GameOver(int fcount, int val, bool start, int rcount, int bcount, bool *over);

int checker(Pos target, Pos arr[], int count);

void getrid(Pos target, Pos arr[], int *count);

void display(Pos arrM[], Pos arrR[], Pos arrB[], int rcount, int bcount);

void removePos(Pos arrR[], Pos arrB[], Pos arrS[], Pos arrT[], int *rcount, int *bcount,int *scount, int *tcount, Pos target, bool *go);

void replace(
    Pos arrR[], Pos arrB[], Pos arrS[], Pos arrT[], Pos arrF[], 
	int *rcount, int *bcount, int *scount, int *tcount, int *fcount, 
	Pos target, bool *found, bool *go
);

void expand(
    Pos arrR[], Pos arrB[], Pos arrS[], Pos arrT[], Pos arrF[], 
    int *rcount, int *bcount, int *scount, int *tcount, int *fcount, 
    Pos target, bool *found, bool *go
);

void update(
    Pos target,
    Pos arrR[], Pos arrB[], Pos arrS[], Pos arrT[], Pos arrF[], 
    int *rcount, int *bcount, int *scount, int *tcount, int *fcount, 
    bool *found, bool *go, bool *good
);

void nextplayermove(
    Pos pos,
    bool *good, bool *start, bool *go, bool *found,
    Pos arrF[], Pos arrR[], Pos arrB[], Pos arrS[], Pos arrT[],
    int *rcount, int *bcount, int *scount, int *fcount,
    int *tcount, int *val
);

#endif

