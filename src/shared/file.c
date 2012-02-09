#include <stdio.h>
#include <stdlib.h>

#include "file.h"

/***************************************
**	Fonction de création de la file
**	param : nombre d'éléments max
**	retour : adresse de la pile alloué
****************************************/
File* creerFile(int max)
{
	//ressources
	File* f = NULL;

	//allocation de la file
	f = (File*)malloc(sizeof(File));
	if(!f){
		perror("\nErreur lors de l'allocation : ");
		exit(EXIT_FAILURE);}

	//allocation du tableau dynamique
	f->element = (void**)malloc(sizeof(void*)*max);
	if(!f->element){
		perror("\nErreur lors de l'allocation du tableau d'éléments : ");
		exit(EXIT_FAILURE);}
		
	//remplissage
	f->max = max;

	f->nb = -1;

	return f;
}

int fileVide(File* f)
{
	//ressources
	int ret;

	//essai
	if(f->nb == -1)
		ret = 1;

	else
		ret = 0;

	return ret;
}

void enfiler(File*f,void* valeur)
{
	//enfiler
	f->nb++;
	f->element[f->nb] = valeur;
}

int defiler(File* f,void** valeur)
{
	//ressources
	int i;
	int ret;

	//defiler
	if(!fileVide(f))
	{
		*valeur = f->element[0];
		for(i = 0 ; i < f->nb ; i++)
			f->element[i]=f->element[i+1];

		f->nb--;
		ret = 1;
	}
	else
		ret=0;

	return ret;
}

/*void listerFile(File* f)
{
	//ressources
	int i;

	//listage
	for(i=0;i<=f->nb;i++)
		printf("%d ; ",f->element[i]);

	printf("\n");

}*/

void detruireFile(File* f)
{
	free(f->element);
	free(f);
}
