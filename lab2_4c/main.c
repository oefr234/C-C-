#define _CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include "consola.h"
#include "testeDomain.h"
#include "testeLista.h"
#include "testeService.h"

int main()
///Functia principala a programului
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	printf("Rulam testele...\n");
	testeDomain();
	/*testeMyList();
	testeService();*/
	printf("Testele au trecut cu succes!\n");
	UI* consola = creeazaUI();
	run(consola);
	distrugeUI(consola);
	_CrtDumpMemoryLeaks();
	return 0;
}
