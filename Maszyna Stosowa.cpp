#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;


struct Element
{
	int liczba;
	Element * nastepny;
	Element();
};
Element::Element()
{
	nastepny = 0;
}


struct Lista
{
	Element * glowa;

	void DodajLiczbe(int liczba);
	void WyswietlListe();
	void UsunZeSzczytu();
	void DodajDwie();
	void ZamienMiejscami();
	void PrzesunZWierz();
	Lista();
};

Lista::Lista()
{
	glowa = 0;
}

void Lista::DodajLiczbe(int liczba)
{
	Element *nowy = new Element;
	nowy->liczba = liczba;

	nowy->nastepny = glowa;
	glowa = nowy;



}

void Lista::WyswietlListe()
{
	Element *tymczasowy = glowa;

	while (tymczasowy)
	{
		cout << tymczasowy->liczba << " ";
		tymczasowy = tymczasowy->nastepny;
	}

}

void Lista::UsunZeSzczytu()
{
	Element *tymczasowy = glowa;
	Element *tymczasowy2 = tymczasowy->nastepny;
	glowa = tymczasowy2;
	tymczasowy = NULL;
}

void Lista::DodajDwie()
{
	Element *glowa1 = glowa;
	Element *tymczasowy = glowa;
	int zmienna = tymczasowy->liczba;

	if (tymczasowy != 0)
	{
		tymczasowy = tymczasowy->nastepny;
		glowa = tymczasowy;
	}
	zmienna += tymczasowy->liczba;
	tymczasowy->liczba = zmienna;
	glowa1 = NULL;
}

void Lista::ZamienMiejscami()
{
	Element *tymczasowy1 = glowa;
	Element *tymczasowy2 = glowa->nastepny;
	Element *tymczasowy3 = glowa->nastepny->nastepny;
	glowa = tymczasowy2;
	tymczasowy2->nastepny = tymczasowy1;
	tymczasowy1->nastepny = tymczasowy3;

}
void Lista::PrzesunZWierz()
{
	
	Element *nowa_gl;
	Element *tymczasowa1;
	Element *tymczasowa2 = glowa->nastepny;
	Element *przypadgowa_Gl = glowa;
	glowa = tymczasowa2;

	if (przypadgowa_Gl->liczba > 1)
	{
		nowa_gl = glowa->nastepny;
		while (przypadgowa_Gl->liczba > 1)
		{
			tymczasowa2 = tymczasowa2->nastepny;
			przypadgowa_Gl->liczba--;
		}
		tymczasowa1 = tymczasowa2;
		glowa->nastepny = tymczasowa2->nastepny;
		tymczasowa1->nastepny = glowa;
		glowa = nowa_gl;
	}
	przypadgowa_Gl = NULL; 


	}


int main()
{

	Lista *main = new Lista;
	int input;


	char znak[1001], *p, q;


	while (fgets(znak, 1001, stdin))
		{
			
		for (p = znak; p < p + (sizeof znak); p++)
		{


			if (*p == '\n')
				break;

			if (*p >= '0' && *p <= '9')
			{
				input = *p;
				input -= 48;
				while (*(p + 1) >= '0' && *(p + 1) <= '9')
				{
					input *= 10;
					input += *(p + 1) - 48;
					p++;
				}
				main->DodajLiczbe(input);
			}
			
			q = *p;

			switch (q)
			{
			case 'p': main->WyswietlListe();
				break;
			case'x': main->UsunZeSzczytu();
				break;
			case '+': main->DodajDwie();
				break;
			case 's': main->ZamienMiejscami();
				break;
			case 'r':
				main->PrzesunZWierz();
				break;
			case 'q': delete(main); return 0;
			}
		}
	}


}