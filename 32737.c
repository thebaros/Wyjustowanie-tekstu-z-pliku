#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>


void spacjeWBuforze(char buf[],int rozmiar) {
	int i;
	for ( i = 0;i< rozmiar+2;i++) {
		buf[i] = ' ';
	};
		buf[rozmiar] = '\n';
		buf[rozmiar + 1] = '\0';
}

int main()
{
	FILE *plik;
	FILE *plikNowy;


	plik = fopen("test1.txt", "r");

	//Blad odczytu
	if (plik == NULL)
	{
		perror("Blad przy odczycie pliku.\n");
		exit(EXIT_FAILURE);
	}

	//
	plikNowy = fopen("test2.txt", "w+");
	//


	char znak;
	int rozmiar_Wiersza = 77;
	//wielkosc bufora musi byc o 2 wieksza!
	char bufor[79];
	int indeksBuforu = 0;
	bool nowaLinia = false;


	spacjeWBuforze(bufor, rozmiar_Wiersza);
	while ((znak = fgetc(plik)) != EOF) {
		if (znak != '\n' && znak != '.' && indeksBuforu != rozmiar_Wiersza) {
			if (nowaLinia == false) {
				bufor[indeksBuforu] = znak;
				indeksBuforu++;
			};
			if (nowaLinia && znak == ' ') {
				nowaLinia = false;
			}
		};
		if (znak == '.') {
			bufor[indeksBuforu] = znak;
			fputs(bufor, plikNowy);
			spacjeWBuforze(bufor, rozmiar_Wiersza);
			indeksBuforu = 0;
			nowaLinia = true;
		};
		if (indeksBuforu == rozmiar_Wiersza) {

			fputs(bufor, plikNowy);
			spacjeWBuforze(bufor, rozmiar_Wiersza);
			indeksBuforu = 0;
		};
		
	}


		//Zamkniecie plikow
		fclose(plik);
		fclose(plikNowy);

}
