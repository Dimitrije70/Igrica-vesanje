#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void prikazi_stanje(char rec[], char pogodjeno[], int duzina);
int vec_pogodjeno(char slova[], int broj_pokusaja, char slovo);
void prikazi_vesanje(int broj_pokusaja);


int main() {
	char rec[] = "funkcija"; //Реч коју треба погодити
	int duzina = strlen(rec);
	char* pogodjeno = (char*)malloc(duzina * sizeof(char)); //Прати погођена слова
	char pokusaji[100]; //Прати унета слова
	int broj_pokusaja = 0;
	int maksimalni_pokusaji = 6;
	int pogodjena_slova = 0;

	memset(pogodjeno, 0, duzina * sizeof(char));
	memset(pokusaji, 0, sizeof(pokusaji));

	printf("Dobrodosli u igru vesanje!\n\n");

	while (broj_pokusaja < maksimalni_pokusaji && pogodjena_slova < duzina)
	{
		char slovo;
		prikazi_vesanje(broj_pokusaja);
		printf("Trenutno stanje: ");
		prikazi_stanje(rec, pogodjeno, duzina);
		printf("Unesite slovo: ");
		scanf(" %c", &slovo);
		slovo = tolower(slovo);
		
		if (vec_pogodjeno(pokusaji, broj_pokusaja, slovo)) {
			printf("Vec ste uneli ovo slovo.\n");
			continue;
		}

		pokusaji[broj_pokusaja] = slovo;

		int pogodak = 0;
		for (int i = 0; i < duzina; i++)
		{
			if (rec[i] == slovo && !pogodjeno[i]) {
				pogodjeno[i] = 1;
				pogodjena_slova++;
				pogodak = 1;
			}
		}

		if (!pogodak) {
			broj_pokusaja++;
			printf("Pogresno! Preostalo jos %d pokusaja\n", maksimalni_pokusaji - broj_pokusaja);
		}
	}

	if (pogodjena_slova == duzina) {
		printf("Cestitamo! Pogodili ste rec: %s\n", rec);
	}
	else {
		prikazi_vesanje(broj_pokusaja);
		printf("Izgubili ste. Rec je bila %s\n", rec);
	}

	free(pogodjeno);

	system("pause");
	return 0;
}

void prikazi_stanje(char rec[], char pogodjeno[], int duzina)
{
	for (int i = 0; i < duzina; i++)
	{
		if (pogodjeno[i]) {
			printf("%c ", rec[i]);
		}
		else {
			printf("_ ");
		}
	}
	printf("\n");
}

int vec_pogodjeno(char slova[], int broj_pokusaja, char slovo)
{
	for (int i = 0; i < broj_pokusaja; i++)
	{
		if (slova[i] == slovo) {
			return 1;
		}
	}
	return 0;
}

void prikazi_vesanje(int broj_pokusaja)
{
	switch (broj_pokusaja)
	{
	case 0:
		printf("\n");
		printf("  +---+\n");
		printf("  |   |\n");
		printf("      |\n");
		printf("      |\n");
		printf("      |\n");
		printf("      |\n");
		printf("========\n");
		break;
	case 1:
		printf("\n");
		printf("  +---+\n");
		printf("  |   |\n");
		printf("  o   |\n");
		printf("      |\n");
		printf("      |\n");
		printf("      |\n");
		printf("========\n");
		break;
	case 2:
		printf("\n");
		printf("  +---+\n");
		printf("  |   |\n");
		printf("  o   |\n");
		printf("  |   |\n");
		printf("      |\n");
		printf("      |\n");
		printf("========\n");
		break;
	case 3:
		printf("\n");
		printf("  +---+\n");
		printf("  |   |\n");
		printf("  o   |\n");
		printf(" /|   |\n");
		printf("      |\n");
		printf("      |\n");
		printf("========\n");
		break;
	case 4:
		printf("\n");
		printf("  +---+\n");
		printf("  |   |\n");
		printf("  o   |\n");
		printf(" /|\\ |\n");
		printf("      |\n");
		printf("      |\n");
		printf("========\n");
		break;
	case 5:
		printf("\n");
		printf("  +---+\n");
		printf("  |   |\n");
		printf("  o   |\n");
		printf(" /|\\ |\n");
		printf(" /    |\n");
		printf("      |\n");
		printf("========\n");
		break;
	case 6:
		printf("\n");
		printf("  +---+\n");
		printf("  |   |\n");
		printf("  o   |\n");
		printf(" /|\\ |\n");
		printf(" / \\ |\n");
		printf("      |\n");
		printf("========\n");
		break;
	}
}
