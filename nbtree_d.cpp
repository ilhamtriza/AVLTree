#include <limits.h>
#include <malloc.h>
#include "nbtree_d.h"

void bCreate(bTree *x){
	(*x).root=NULL;
}

bAddr bCNode(bType X){
	bAddr newNode;
	newNode=(bAddr) malloc(sizeof(ElmtTree));
	if (newNode != NULL){
		newNode->info=X;
		newNode->left=NULL;
		newNode->right=NULL;
		newNode->height=1;
	}
	return (newNode);
}

bAddr bInsert(bAddr *tRoot, bType X){
	
	bAddr newNode,temp;
	
	temp=*tRoot;
	
	newNode=bCNode(X);
	
	if (temp == NULL){
		return(newNode);
	}
	
	if 	(X < temp->info){
		temp->left = bInsert(temp->left,X);
	}
	else if (X > temp->info){
		temp->right = bInsert(temp->right,X);
	}
	else{
		return temp;
	}
	
	temp->height = 1 + max(height(temp->left),height(temp->right));
	
//	if (newNode !=NULL){ //Jika penciptaan node baru berhasil
//		if (X >= temp->info){
//			if (temp->right == NULL){
//				temp->right=newNode;
//			}
//			else{
//				bInsert(&(temp->right),X);
//			}
//		}
//		else{
//			if(temp->left == NULL){
//				temp->left=newNode;
//			}
//			else{
//				bInsert(&(temp->left),X);
//			}
//		}
//	}
}


int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

int height(bAddr N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
}

nbAddr nbSearch(nbAddr root, nbType src){
	nbAddr nSrc;
	if (root!=NULL){
		if (root->info==src)
			return root;
		else{
			nSrc=nbSearch(root->fs,src);
			if (nSrc==NULL)
				return nbSearch(root->nb,src);
			else
				return nSrc;
		}
	}
	else{
		return NULL;
	}
}

int nbDepth(nbAddr root)
{
	int y = 0,z = 0;
	
	if(root==NULL)
	{
		return -1;
	}
	else{
		y = nbDepth(root->fs);
		z = nbDepth(root->nb);
		if ( root->parent == NULL || root->parent->fs == root)
		{
			if (y > z)
			{
				return (y+1);	
			}
			else
			{
				return (z+1);	
			}
		}
		else 
		{
			if (y > z)
			{
				return (y);	
			}
			else
			{
				return (z);	
			}
			
		}
		
	}	

//	if(root==NULL)
//	{
//		return -1;
//	}
//	else if(root -> fs == NULL)
//	{	
//		return 0;
//	}
//	else if(root -> fs != NULL){
//		y=nbDepth(root->fs);
//		if ( root -> nb != NULL)
//		{
//			z=nbDepth(root->fs->nb);	
//		}
//		else 
//		{
//			z = y;
//		}
//		if (y < z)
//		{
//			return (y+1);	
//		}
//		else
//		{
//			return (z+1);	
//		}
//	}	
	
}

/* ---------------- TRAVERSAL Tree ---------------- */
void nbPost(nbAddr root){
	if (root!=NULL){
		nbPost(root->fs);
		printf("%d ", root->info);
		nbPost(root->nb);
	}
/*
// Post Order Non Rekursif -> selesai
nbAddr pCur;
	boolean arah;
	arah=0;

	pCur=pTree.root;
	do{
		if(pCur->fs!=NULL && arah==0)
			pCur=pCur->fs;
		else{
			printf("%d ", pCur->info);
			arah=0;
			if (pCur->nb!= NULL)
				pCur=pCur->nb;
			else{
				pCur=pCur->parent;
				arah=1;
			}
		}
	}while(pCur!=NULL);
*/
}

void nbPre(nbAddr root){
	if (root!=NULL){
		printf("%d ", root->info);
		nbPre(root->fs);
		nbPre(root->nb);
	}
/*
// Pre order Non Rekursif -> Selesai
nbAddr pCur;
	boolean arah;
	arah=0;

	pCur=pTree.root;
	printf("%d ", pCur->info);
	do{
		if(pCur->fs!=NULL && arah==0){
			pCur=pCur->fs;
			printf("%d ", pCur->info);
		}else{
			arah=0;
			if (pCur->nb!= NULL){
				pCur=pCur->nb;
				printf("%d ", pCur->info);
			}else{
				pCur=pCur->parent;
				arah=1;
			}
		}
	}while(pCur!=NULL);*/

}

void nbIn(nbAddr root){
	if (root!=NULL){
		nbIn(root->fs);
		if (root->fs==NULL) printf("%d ", root->info);
		if (root->parent !=NULL)
			if (root->parent->fs==root)
				printf("%d ", root->parent->info);
		nbIn(root->nb);
	}

/*
// Inorder non rekursif -> belum selesai
	nbAddr pCur;
	int arah;
	arah=0;

	pCur=pTree.root;
	do{
		if(pCur->fs!=NULL && arah==0){
			pCur=pCur->fs;
		}else{
			if (pCur->nb!= NULL){
				printf("%d ", pCur->info);
				pCur=pCur->nb;
			}else{
					printf("%d ", pCur->info);
					arah=1;
				pCur=pCur->parent;
			}
			if (arah==0 && pCur->parent!=NULL)
				printf("%d ", pCur->parent->info);
			if (arah==0) arah=1;
		}
	}while(pCur!=NULL);
*/
}



void nbLevelOrder(nbAddr root,int curLevel, int desLevel)
{
	if(root!=NULL)
	{
		if(curLevel==desLevel)
			printf("%d  ",root->info);
		nbLevelOrder(root->fs,curLevel+1,desLevel);
		nbLevelOrder(root->nb,curLevel,desLevel);
	}
}

void nbPrint(nbAddr node, char tab[]){
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");
	if (node!=NULL){
		printf("%s%d\n",tab,node->info);
		nbPrint(node->fs,tempTab);
		nbPrint(node->nb,tab);
	}
}
