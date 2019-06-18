/*
File	: nbtree_d.h
Author	: SN
Last Updt : 25-5-2011
*/

#ifndef nbtree_d_H
#define nbtree_d_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bTreeNode *bAddr;
typedef int bType;

typedef struct bTreeNode{
	bAddr right,left;
	bType info;
	int height;
	
}ElmtTree;

struct bTree{
	bAddr root;
};

/* ---------------- Konstruktor Tree ---------------- */
void bCreate(bTree *x);
//Membuat tree kosong (X.root=NULL)

/* ---------------- Alokasi node baru Tree ---------------- */
bAddr bCNode(bType X);
//Alokasi untuk membuat node baru

/* ---------------- Operasi-operasi Tree ---------------- */
void bInsert(bTree *tRoot, bAddr parent, bType X);
// Menambah element pada node parent

bAddr bSearch(bAddr root, bType src);
// Mencari node dengan info ttn dan mengembalikan addressnya

int max(int a, int b);

int height(bAddr N);

/* ---------------- TRAVERSAL Tree ---------------- */
void bPost(bAddr root); // Postorder traversing
void bPre(bAddr root); // Preorder traversing
void bIn(bAddr root); // Inorder traversing
void bLevelOrder(bAddr root,int curLevel, int desLevel); // Levelorder traversing

/* ---------------- PRINT TREE ---------------- */
void bPrint(bAddr node, char tab[]);

#endif
