//#include "testeLista.h"
//#include "MyList.h"
//#include <assert.h>
//
//void testCreeazaLista()
//{
//	List* list1 = creeazaListaVida();
//	assert(list1 != NULL);
//	assert(list1->cp == 1);
//	assert(list1->dim == 0);
//	distrugeLista(list1);
//
//	List* list2 = creeazaListaVida();
//	assert(list2 != NULL);
//	assert(list2->cp == 1);
//	assert(list2->dim == 0);
//	distrugeLista(list2);
//}
//
//void testRedimensionare()
//{
//	List* list1 = creeazaListaVida();
//	redimensionare(list1);
//	assert(list1->cp == 2);
//	redimensionare(list1);
//	assert(list1->cp == 4);
//	redimensionare(list1);
//	assert(list1->cp == 8);
//	distrugeLista(list1);
//}
//
//void testAdaugaSfarsit()
//{
//	List* list = creeazaListaVida();
//	Medicament* m = creeazaMedicament(123, "Test1", 10, 20);
//	adaugaSfarsit(m, list);
//	assert(list->dim == 1);
//	assert(list->cp == 1);
//	
//	Medicament* n = creeazaMedicament(124, "Test2", 20, 21);
//	adaugaSfarsit(n, list);
//	assert(list->dim == 2);
//	assert(list->cp == 2);
//	
//	Medicament* p = creeazaMedicament(125, "Test3", 30, 22);
//	adaugaSfarsit(p, list);
//	assert(list->dim == 3);
//	assert(list->cp == 4);
//
//	assert(list->med[0]->cod == 123);
//	assert(strcmp(list->med[0]->nume, "Test1") == 0);
//	assert(list->med[0]->concentratie - 10 ==0);
//	assert(list->med[0]->cantitate == 20);
//
//	assert(list->med[1]->cod == 124);
//	assert(strcmp(list->med[1]->nume, "Test2") == 0);
//	assert(list->med[1]->concentratie - 20== 0);
//	assert(list->med[1]->cantitate == 21);
//
//	assert(list->med[2]->cod == 125);
//	assert(strcmp(list->med[2]->nume, "Test3") == 0);
//	assert(list->med[2]->concentratie - 30 == 0);
//	assert(list->med[2]->cantitate == 22);
//	distrugeLista(list);
//}
//
//void testStergePoz()
//{
//	List* list = creeazaListaVida();
//	Medicament* m = creeazaMedicament(123, "Test1",10, 20);
//	adaugaSfarsit(m, list);
//
//	Medicament* n = creeazaMedicament(124, "Test2",20, 21);
//	adaugaSfarsit(n, list);
//
//	Medicament* p = creeazaMedicament(125, "Test3", 30, 22);
//	adaugaSfarsit(p, list);
//	
//	Medicament* q = creeazaMedicament(126, "Test4", 40, 23);
//	adaugaSfarsit(q, list);
//	assert(list->dim == 4);
//	assert(list->cp == 4);
//	stergePoz(1, list);
//	assert(list->dim == 3);
//
//	assert(list->med[0]->cod == 123);
//	assert(strcmp(list->med[0]->nume, "Test1") == 0);
//	assert(list->med[0]->concentratie - 10 == 0);
//	assert(list->med[0]->cantitate == 20);
//
//	assert(list->med[1]->cod == 125);
//	assert(strcmp(list->med[1]->nume, "Test3") == 0);
//	assert(list->med[1]->concentratie - 30==0);
//	assert(list->med[1]->cantitate == 22);
//	
//	assert(list->med[2]->cod == 126);
//	assert(strcmp(list->med[2]->nume, "Test4") == 0);
//	assert(list->med[2]->concentratie - 40 ==0);
//	assert(list->med[2]->cantitate == 23);
//
//	distrugeLista(list);
//}
//
//void testeMyList()
//{
//	testCreeazaLista();
//	testRedimensionare();
//	testAdaugaSfarsit();
//	testStergePoz();
//}
