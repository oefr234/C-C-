//#include "service.h"
//#include "testeService.h"
//#include <stdlib.h>
//#include <assert.h>
//#include "consola.h"
//void testCreeazaService()
//{
//	ServiceMed* serv = creeazaService();
//	assert(serv != NULL);
//	assert(serv->lst_med != NULL);
//	assert(serv->validator == 0);
//	distrugeService(serv);
//
//	ServiceMed* serv2 = creeazaService();
//	assert(serv2 != NULL);
//	assert(serv2->lst_med != NULL);
//	assert(serv2->validator == 0);
//	distrugeService(serv2);
//}
//
//void testListaMed()
//{
//	ServiceMed* serv = creeazaService();
//	assert(serv != NULL);
//	List* lst = listaMed(serv);
//	assert(lst == serv->lst_med);
//	distrugeService(serv);
//}
//
//void testCautaMedicament()
//{
//	ServiceMed* serv = creeazaService();
//	assert(serv != NULL);
//	Medicament* m1 = creeazaMedicament(12, "Test1", 11, 20);
//	Medicament* m2 = creeazaMedicament(23, "Test2", 11, 20);
//	Medicament* m3 = creeazaMedicament(34, "Test3", 11, 20);
//	int i,poz;
//	i=adaugaMedicament(m1, serv);
//	i=adaugaMedicament(m2, serv);
//	i=adaugaMedicament(m3, serv);
//	poz = cautaMedicament(12, serv);
//	assert(poz == 0);
//	poz = cautaMedicament(23, serv);
//	assert(poz == 1);
//	poz = cautaMedicament(34, serv);
//	assert(poz == 2);
//	poz = cautaMedicament(123, serv);
//	assert(poz == -1);
//	distrugeService(serv);
//}
//
//void testAdaugaMedicament()
//{
//	ServiceMed* serv = creeazaService();
//	assert(serv != NULL);
//	Medicament* m1 = creeazaMedicament(12, "Test1", 11, 20);
//	Medicament* m2 = creeazaMedicament(23, "Test2", 11, 20);
//	Medicament* m3 = creeazaMedicament(34, "Test3", 11, 20);
//	Medicament* m4 = creeazaMedicament(34, "Test4", 11, 20);
//	Medicament* m5 = creeazaMedicament(-1, "Test4", 11, 20);
//	Medicament* m6 = creeazaMedicament(34, "Test3", 10, 20);
//	Medicament* m7 = creeazaMedicament(12, "Test1", 11, 10);
//	int i;
//	i = adaugaMedicament(m1, serv);
//	assert(i == 1);
//	i = adaugaMedicament(m2, serv);
//	assert(i == 1);
//	i = adaugaMedicament(m3, serv);
//	assert(i == 1);
//	i = adaugaMedicament(m4, serv);
//	assert(i == -1);
//	i = adaugaMedicament(m5, serv);
//	assert(i == 0);
//	i= adaugaMedicament(m6, serv);
//	assert(i == -1);
//	i = adaugaMedicament(m7, serv);
//	assert(i == 1);
//	distrugeService(serv);
//}
//
//void testStergeMedicament()
//{
//	ServiceMed* serv = creeazaService();
//	assert(serv != NULL);
//	Medicament* m1 = creeazaMedicament(12, "Test1", 11, 20);
//	Medicament* m2 = creeazaMedicament(23, "Test2", 11, 20);
//	Medicament* m3 = creeazaMedicament(34, "Test3", 11, 20);
//	Medicament* m4 = creeazaMedicament(35, "Test4", 11, 20);
//	Medicament* m5 = creeazaMedicament(29, "Test5", 11, 20);
//	int i,j;
//	i = adaugaMedicament(m1, serv);
//	i = adaugaMedicament(m2, serv);
//	i = adaugaMedicament(m3, serv);
//	i = adaugaMedicament(m4, serv);
//	i = adaugaMedicament(m5, serv);
//	j = stergeMedicament(23, serv);
//	assert(j == 1);
//	assert(listaMed(serv)->dim == 4);
//	j = stergeMedicament(35, serv);
//	assert(j == 1);
//	assert(listaMed(serv)->dim == 3);
//	j = stergeMedicament(35, serv);
//	assert(j == 0);
//	distrugeService(serv);
//}
//
//void testModificaMedicament()
//{
//	ServiceMed* serv = creeazaService();
//	assert(serv != NULL);
//	Medicament* m1 = creeazaMedicament(12, "Test1", 11, 20);
//	Medicament* m2 = creeazaMedicament(23, "Test2", 11, 20);
//	Medicament* m3 = creeazaMedicament(34, "Test3", 11, 20);
//	int i,j;
//	i = adaugaMedicament(m1, serv);
//	i = adaugaMedicament(m2, serv);
//	i = adaugaMedicament(m3, serv);
//	j = modificaMedicament(30, "Test11", 12, serv);
//	assert(j == 1);
//	assert(serv->lst_med->med[0]->concentratie == 30);
//	assert(strcmp(serv->lst_med->med[0]->nume,"Test11") == 0);
//	j = modificaMedicament(30, "Test11", 13, serv);
//	assert(j == -1);
//	j = modificaMedicament(-30, "Test11", 12, serv);
//	assert(j == 0);
//	j = modificaMedicament(30, "", 12, serv);
//	assert(j == 0);
//	distrugeService(serv);
//}
//
//void testCreeazaCopieMed()
//{
//	ServiceMed* service = creeazaService();
//	List* listaCopie = creeazaCopieMed(service);
//	assert(listaCopie != listaMed(service));
//	assert(listaCopie->cp == listaMed(service)->cp);
//	assert(listaCopie->dim == listaMed(service)->dim);
//	distrugeLista(listaCopie);
//	distrugeService(service);
//}
//
//void testCompara()
//{
//	Medicament* m1 = creeazaMedicament(12, "Test1", 11, 20);
//	Medicament* m2 = creeazaMedicament(23, "Test2", 11, 10);
//	int c = compara(m1, m2, "nume");
//	assert(c < 0);
//	c = compara(m1, m2, "cantitate");
//	assert(c > 0);
//	distrugeMedicament(m1);
//	distrugeMedicament(m2);
//}
//
//void testCompara2()
//{
//	Medicament* m1 = creeazaMedicament(12, "Test1", 11, 20);
//	Medicament* m2 = creeazaMedicament(23, "Test2", 11, 10);
//	Medicament* m3 = creeazaMedicament(34, "Test8", 11, 20);
//	Medicament* m4 = creeazaMedicament(45, "Test7", 11, 40);
//	int c = compara2(m1, m2, "nume",0);
//	assert(c == 0);
//	c = compara2(m1, m2, "cantitate",0);
//	assert(c == 1);
//	c = compara2(m3, m4, "nume", 0);
//	assert(c == 1);
//	c = compara2(m3, m4, "cantitate", 1);
//	assert(c == 1);
//	c = compara2(m2, m3, "nume", 1);
//	assert(c == 1);
//	distrugeMedicament(m1);
//	distrugeMedicament(m2);
//	distrugeMedicament(m3);
//	distrugeMedicament(m4);
//}
//
//void testValideazaCriterii()
//{
//	char* crt = (char*)malloc(sizeof(char) * 10);
//	strcpy(crt, "nume");
//	int reverse = 1;
//	assert(valideazaCriterii(crt, reverse) == 1);
//	reverse = 0;
//	assert(valideazaCriterii(crt, reverse) == 1);
//	strcpy(crt, "cantitate");
//	assert(valideazaCriterii(crt, reverse) == 1);
//	reverse = 1;
//	assert(valideazaCriterii(crt, reverse) == 1);
//	strcpy(crt, "saklda");
//	assert(valideazaCriterii(crt, reverse) == 0);
//	strcpy(crt, "nume");
//	reverse = 2;
//	assert(valideazaCriterii(crt, reverse) == 0);
//	free(crt);
//}
//
//void testSorteaza()
//{
//	ServiceMed* serv = creeazaService();
//	assert(serv != NULL);
//	Medicament* m1 = creeazaMedicament(12, "Test2", 11, 30);
//	Medicament* m2 = creeazaMedicament(23, "Test3", 11, 40);
//	Medicament* m3 = creeazaMedicament(34, "Test1", 11, 20);
//	int i;
//	i = adaugaMedicament(m1, serv);
//	i = adaugaMedicament(m2, serv);
//	i = adaugaMedicament(m3, serv);
//	List* sortat1 = sorteaza(serv, "nume", 0);
//	assert(sortat1->med[0]->cod == 34);
//	assert(sortat1->med[1]->cod == 12);
//	assert(sortat1->med[2]->cod == 23);
//	distrugeLista(sortat1);
//	List* sortat2 = sorteaza(serv, "nume", 1);
//	assert(sortat2->med[0]->cod == 23);
//	assert(sortat2->med[1]->cod == 12);
//	assert(sortat2->med[2]->cod == 34);
//	distrugeLista(sortat2);
//	List* sortat3 = sorteaza(serv, "cantitate", 0);
//	assert(sortat3->med[0]->cod == 34);
//	assert(sortat3->med[1]->cod == 12);
//	assert(sortat3->med[2]->cod == 23);
//	distrugeLista(sortat3);
//	List* sortat4 = sorteaza(serv, "cantitate", 1);
//	assert(sortat4->med[0]->cod == 23);
//	assert(sortat4->med[1]->cod == 12);
//	assert(sortat4->med[2]->cod == 34);
//	distrugeLista(sortat4);
//	List* sortat5 = sorteaza(serv, "sjdhsa", 1);
//	assert(sortat5==NULL);
//	List* sortat6 = sorteaza(serv, "nume", 10);
//	assert(sortat6 == NULL);
//	distrugeService(serv);
//}
//
//void testSorteaza2()
//{
//	ServiceMed* serv = creeazaService();
//	assert(serv != NULL);
//	Medicament* m1 = creeazaMedicament(12, "Test2", 11, 30);
//	Medicament* m2 = creeazaMedicament(23, "Test3", 11, 40);
//	Medicament* m3 = creeazaMedicament(34, "Test1", 11, 20);
//	int i;
//	i = adaugaMedicament(m1, serv);
//	i = adaugaMedicament(m2, serv);
//	i = adaugaMedicament(m3, serv);
//	List* sortat1 = sorteaza2(serv, compara2, "nume",0);
//	assert(sortat1->med[0]->cod == 34);
//	assert(sortat1->med[1]->cod == 12);
//	assert(sortat1->med[2]->cod == 23);
//	distrugeLista(sortat1);
//	List* sortat2 = sorteaza2(serv,compara2, "nume", 1);
//	assert(sortat2->med[0]->cod == 23);
//	assert(sortat2->med[1]->cod == 12);
//	assert(sortat2->med[2]->cod == 34);
//	distrugeLista(sortat2);
//	List* sortat3 = sorteaza2(serv, compara2,"cantitate", 0);
//	assert(sortat3->med[0]->cod == 34);
//	assert(sortat3->med[1]->cod == 12);
//	assert(sortat3->med[2]->cod == 23);
//	distrugeLista(sortat3);
//	List* sortat4 = sorteaza2(serv, compara2,"cantitate", 1);
//	assert(sortat4->med[0]->cod == 23);
//	assert(sortat4->med[1]->cod == 12);
//	assert(sortat4->med[2]->cod == 34);
//	distrugeLista(sortat4);
//	List* sortat5 = sorteaza2(serv, compara2,"sjdhsa", 1);
//	assert(sortat5 == NULL);
//	List* sortat6 = sorteaza2(serv, compara2,"nume", 10);
//	assert(sortat6 == NULL);
//	distrugeService(serv);
//}
//
//void testFiltrareCantitate()
//{
//	ServiceMed* serv = creeazaService();
//	assert(serv != NULL);
//	Medicament* m1 = creeazaMedicament(12, "Test2", 11, 30);
//	Medicament* m2 = creeazaMedicament(23, "Test3", 11, 40);
//	Medicament* m3 = creeazaMedicament(34, "Test1", 11, 20);
//	int i;
//	i = adaugaMedicament(m1, serv);
//	i = adaugaMedicament(m2, serv);
//	i = adaugaMedicament(m3, serv);
//	List* lst = filtrareCantitate(serv, 40);
//	assert(lst->med[0]->cod == m1->cod);
//	assert(strcmp(lst->med[0]->nume ,m1->nume)==0);
//	assert(lst->med[0]->concentratie == m1->concentratie);
//	assert(lst->med[0]->cantitate == m1->cantitate);
//	assert(lst->med[1]->cod == m3->cod);
//	assert(strcmp(lst->med[1]->nume, m3->nume) == 0);
//	assert(lst->med[1]->concentratie == m3->concentratie);
//	assert(lst->med[1]->cantitate == m3->cantitate);
//	distrugeService(serv);
//	distrugeLista(lst);
//}
//
//void testFiltrareNume()
//{
//	ServiceMed* serv = creeazaService();
//	assert(serv != NULL);
//	Medicament* m1 = creeazaMedicament(12, "est2", 11, 30);
//	Medicament* m2 = creeazaMedicament(23, "Test3", 11, 40);
//	Medicament* m3 = creeazaMedicament(34, "Test1", 11, 20);
//	int i;
//	i = adaugaMedicament(m1, serv);
//	i = adaugaMedicament(m2, serv);
//	i = adaugaMedicament(m3, serv);
//	List* lst = filtrareNume(serv, 'T');
//	assert(lst->med[0]->cod == m2->cod);
//	assert(strcmp(lst->med[0]->nume, m2->nume) == 0);
//	assert(lst->med[0]->concentratie == m2->concentratie);
//	assert(lst->med[0]->cantitate == m2->cantitate);
//	assert(lst->med[1]->cod == m3->cod);
//	assert(strcmp(lst->med[1]->nume, m3->nume) == 0);
//	assert(lst->med[1]->concentratie == m3->concentratie);
//	assert(lst->med[1]->cantitate == m3->cantitate);
//	distrugeService(serv);
//	distrugeLista(lst);
//}
//
//void testeService()
//{
//	testCreeazaService();
//	testListaMed();
//	testCautaMedicament();
//	testAdaugaMedicament();
//	testStergeMedicament();
//	testModificaMedicament();
//	testCreeazaCopieMed();
//	testCompara();
//	testSorteaza();
//	testFiltrareCantitate();
//	testFiltrareNume();
//	testValideazaCriterii();
//	testCompara2();
//	testSorteaza2();
//}