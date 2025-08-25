#include "consola.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

UI* creeazaUI()
{
	UI *consola=(UI*)malloc(sizeof(UI));
	consola->service = creeazaService();
	return consola;
}

void afiseazaUI(List* lst)
{
	for (int i = 0;i < lst->dim;i++)
		afiseazaMedicament(lst->med[i]);
}

void print_menu()
{
	printf("\n1.Adauga medicament in lista\n");
	printf("2.Sterge stocul unui medicament\n");
	printf("3.Modifica medicament\n");
	printf("4.Afiseaza medicamentele sortate dupa nume sau cantitate\n");
	printf("5.Afiseaza medicamentele care au cantitatea mai mica decat una data\n");
	printf("6.Afiseaza medicamentele a caror nume incepe cu o litera data\n");
	printf("7.Afiseaza medicamentele existente\n");
	printf("8.UNDO\n");
	printf("9.REDO\n");
	printf("10.Iesire\n\n");
	printf("Introduceti optiunea dorita:   optiune=");
}

void afiseazaMedicament(Medicament* x)
{
	printf("Cod: %d   ", x->cod);
	printf("Nume: %s   ", x->nume);
	printf("Concentratie: %d%%   ", x->concentratie);
	printf("Cantitate: %d\n", x->cantitate);
}

void adaugaUI(UI* consola)
{
	int cod, cantitate;
	char* nume=(char*)malloc(sizeof(char)*30);
	int concentratie;
	while (printf("\nIntroduceti codul: cod="), scanf_s("%d", &cod) != 1 || cod < 0) {
		printf("Cod invalid! Introduceti un intreg pozitiv!\n");
		while (getchar() != '\n'); // Golește buffer-ul
	}
	while (getchar() != '\n');
	printf("Introduceti numele: nume=");
	fgets(nume,30,stdin);
	nume[strcspn(nume, "\n")] = 0;
	while (printf("Introduceti concentratia: concentratie="), scanf_s("%d", &concentratie) != 1 || concentratie < 0) {
		printf("Concentratie invalida! Introduceti un numar rational pozitiv!\n");
		while (getchar() != '\n'); // Golește buffer-ul
	}
	while (printf("Introduceti cantitatea: cantitate="), scanf_s("%d", &cantitate) != 1 || cantitate < 0) {
		printf("Cantitate invalida! Introduceti un numar intreg pozitiv!\n");
		while (getchar() != '\n'); // Golește buffer-ul
	}
	Medicament* med = creeazaMedicament(cod, nume, concentratie, cantitate);
	int ok = adaugaMedicament(consola->service,med);
	printf("\n");
	if (ok == 1)
		printf("Adaugarea s-a efectuat cu succes!\n");
	else if (ok == -1)
		printf("Medicamentul introdus se afla deja in lista! Codul unic este asociat deja unui element");
	else if (ok == 0)
		printf("Datele sunt invalide! Codul, cantitatea si concentratia nu pot fi negative, iar numele trebuie sa contina cel putin un caracter!\n");
	printf("\n");
	free(nume);
}


void stergeUI(UI* consola)
{
	int cod;
	while (printf("\nIntroduceti codul medicamentului pe care doriti sa il stergeti: cod="), scanf_s("%d", &cod) != 1 || cod < 0) {
		printf("Cod invalid! Introduceti un intreg pozitiv!\n");
		while (getchar() != '\n'); // Golește buffer-ul
	}
	int ok = stergeMedicament(cod, consola->service);
	if (ok == 1)
		printf("Stergerea s-a efectuat cu succes!\n");
	else
		printf("Medicamentul nu a fost gasit in lista!\n");
}

void modificaUI(UI* consola)
{
	int cod;
	while (printf("\nIntroduceti codul medicamentului pe care doriti sa il modificati: cod="), scanf_s("%d", &cod) != 1 || cod < 0) {
		printf("Cod invalid! Introduceti un intreg pozitiv!\n");
		while (getchar() != '\n'); // Golește buffer-ul
	}
	int conc;
	while (printf("\nIntroduceti noua concentratie : concentratie="), scanf_s("%d", &conc) != 1) {
		printf("Concentratie invalida! Introduceti un intreg pozitiv!\n");
		while (getchar() != '\n'); // Golește buffer-ul
	}
	char* nume = (char*)malloc(sizeof(char) * 30);
	while (getchar() != '\n');
	printf("Introduceti noul nume: nume=");
	fgets(nume, 30, stdin);
	nume[strcspn(nume, "\n")] = 0;
	int ok = modificaMedicament(conc, nume, cod, consola->service);
	if (ok == 0)
		printf("Datele introduse sunt invalide!\n");
	else if (ok == -1)
		printf("Medicamentul cu codul introdus nu exista!\n");
	else
		printf("Modificarea s-a realizat cu succes!\n");
}


void sortareUI(UI* consola)
{
	char* crt = (char*)malloc(10 * sizeof(char));
	getchar();
	printf("\nIntroduceti criteriul dupa care doriti sortarea! Introduceti /nume/ sau /cantitate/ : ");
	fgets(crt, 10, stdin);
	crt[strcspn(crt, "\n")] = 0;
	int reverse = 0;
	while (printf("Doriti sortare descrescatoare? Introduceti 1 pentru DA si 0 pentru NU: reverse="), scanf_s("%d", &reverse) != 1) {
		printf("Introduceti un intreg pozitiv!\n");
		while (getchar() != '\n'); // Golește buffer-ul
	}
	List* lst = sorteaza(consola->service, crt, reverse);
	if (lst == NULL)
		printf("Datele introduse au fost invalide!\n");
	else
	{
		afiseazaUI(lst);
		distrugeLista(lst);
	}
	free(crt);
}


void filtreazaCantitateUI(UI* consola)
{
	int cantitate;
	while (printf("\nIntroduceti cantitatea dupa care doriti sa se faca filtrarea : cantitate="), scanf_s("%d", &cantitate) != 1) {
		printf("Cantitate invalida! Introduceti un intreg pozitiv!\n");
		while (getchar() != '\n'); // Golește buffer-ul
	}
	List* lst = filtrareCantitate(consola->service, cantitate);
	if (lst->dim == 0)
		printf("Nu exista medicamente cu stocul mai mic decat acesta!\n");
	else
		afiseazaUI(lst);
	distrugeLista(lst);
}

void filtreazaNumeUI(UI* consola)
{
	char c;
	getchar();
	printf("Introduceti caracterul cu care dorinti sa inceapa numele medicamentelor: c=");
	scanf_s("%c", &c,1);
	List* lst = filtrareNume(consola->service, c);
	if (lst->dim == 0)
		printf("Nu exista elemente care sa inceapa cu acest caracter!\n");
	else
		afiseazaUI(lst);
	distrugeLista(lst);
}



void run(UI* consola)
{
	Medicament* m1 = creeazaMedicament(12, "Test1", 11, 20);
	Medicament* m2 = creeazaMedicament(23, "Test2", 11, 10);
	Medicament* m3 = creeazaMedicament(34, "Test3", 11, 20);

	adaugaMedicament(consola->service,m1);
	adaugaMedicament(consola->service,m2);
	adaugaMedicament(consola->service,m3);
	int ok = 1;
	while (ok)
	{
		print_menu();
		int option;
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
		{
			adaugaUI(consola);
			break;
		}
		case 2:
		{
			stergeUI(consola);
			break;
		}
		case 3:
		{
			modificaUI(consola);
			break;
		}
		case 4:
		{
			sortareUI(consola);
			break;
		}
		case 5:
		{
			filtreazaCantitateUI(consola);
			break;
		}
		case 6:
		{
			filtreazaNumeUI(consola);
			break;
		}
		case 7:
		{
			afiseazaUI(consola->service->lst_med);
			break;
		}
		case 8:
		{
			undo(consola->service);
		}
		case 9:
		{
			redo(consola->service);
		}
		case 10:
		{
			ok = 0;
			break;
		}
		default:
		{
			printf("OPTIUNE INVALIDA!\n");
			break;
		}
		}
	}
}
void distrugeUI(UI* consola)
{
	distrugeService(consola->service);
	free(consola);
}
