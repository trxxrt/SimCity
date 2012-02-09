#ifndef FILE_H
#define FILE_H

typedef struct {
	int max;
	int nb;
	void** element;
} File;

File* creerFile(int max);
int fileVide(File* f);
void enfiler(File* f, void* valeur);
int defiler(File* f, void** valeur);
//void listerFile(File* f);
void detruireFile(File* f);

#endif
