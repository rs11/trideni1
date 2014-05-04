// trideni1.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "TData.h"
#include <stdio.h>
#include <stdlib.h>

struct TData input = { 0, NULL };
struct TData output = { 0, NULL };

char* nactiSoubor(char* jmeno, int* pDelka);
int pocetCiselVRetezi(char* s);
void tiskniCisla(TData* pTD);
void setridCisla(TData* pDest, TData* pSrc);
int naplnCislaZRetezce(char* s, struct TData* pTD);

int _tmain(int argc, _TCHAR* argv[])
{
	char* p=0;
	int delka=0;
	p = nactiSoubor("cisla.txt", &delka);
	if (p == 0)
	{
		printf("Chyba\n");
		return 1;
	}
	int pocetCisel = pocetCiselVRetezi(p);
	printf("Pocet cisel v souboru: %d\n", pocetCisel);
	CreateData(&input, pocetCisel);
	CreateData(&output, pocetCisel);

    int a=naplnCislaZRetezce(p, &input);
	printf("Pocet prevedenych cisel: %d\n", a);
	printf("\nVstupni cisla: "); tiskniCisla(&input);
    setridCisla(&output,&input);
    printf("\nVystupni cisla: "); tiskniCisla(&output);

	DestroyData(&input);
	DestroyData(&output);
	return 0;
}

void setridCisla(TData* pDest, TData* pSrc)
{
  int i;
  for(i=0;i<pDest->iSize;i++)
  {
    pDest->iValue[i]=pSrc->iValue[i];
  }
}

void tiskniCisla(TData* pTD)
{
  int i;
  for(i=0;i<pTD->iSize;i++)
  {
    if(i) printf(", ");
    printf("%f",pTD->iValue[i]);
  }
  printf("\n");
}

int naplnCislaZRetezce(char* s, TData* pTD)
{
  int i=0;
  while(i<pTD->iSize)
  {
    pTD->iValue[i++]=atof(s);
    while(*s) { s++; if(*s=='|') { s++; break; } }
    if(*s==0) break;
  }
  return (i);
}

int pocetCiselVRetezi(char* s)
{
	int delka = strlen(s);
	int i;
	int pocet_cisel = 1;
	for (i = 0; i<delka; i++) { if (s[i] == '|') { pocet_cisel++; } }
	return pocet_cisel;
}

long delkasouboru(FILE *pFile)
{
	long size = 0;
	if(pFile != NULL)
	{
		long pozice = ftell(pFile);
		fseek(pFile, 0, SEEK_END);
		size = ftell(pFile);
		fseek(pFile, pozice, SEEK_SET);
	}
	return size;
}

char* nactiSoubor(char* jmeno, int* pDelka)
{
	FILE * pFile;
	*pDelka = 0;
	pFile = fopen(jmeno, "r");
	if (pFile == 0)
	{
		printf("Chyba cteni souboru: %s\n", jmeno);
		return 0;
	}

	int delka = delkasouboru(pFile);
	printf("Delka souboru: %d\n", delka);
	// alokuje misto pro nacteni retezce
	char* data = (char *)malloc(delka*sizeof(char));
	int delka2 = fread(data, sizeof(char), delka, pFile);
	fclose(pFile);
	if (delka != delka2)
	{
		printf("Chyba cteni souboru\n");
		free(data);
		return 0;
	}
	*pDelka = delka;
	return data;
}
