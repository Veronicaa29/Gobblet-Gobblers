#pragma once
#include <iostream>
#include "Coordonate.h"
#include "Pozitie.h"
#include "Jucator.h"

using namespace std;

class Joc
{
	int tip_mutare;

	Coordonate ultima_mutare;
	Coordonate ultima_mutare_c;

	Piesa piesa_curenta;

	Pozitie tabla[3][3];

	Jucator jucator1, jucator2;
	Jucator jucator_curent, adversar;

public:

	Joc();

	void adauga_piesa_pe_pozitie(int linie, int coloana); // push
	void scoate_piesa_de_pe_pozitie(int linie, int coloana); //pop
	int ia_piesa_jucator_din_varf(int linie, int coloana); // top -> aflu jucatorul care detine piesa din varf
	int ia_piesa_marime_din_varf(int linie, int coloana); // top -> aflu marimea piesei din varf

	int verif_adaugare_piesa_pe_pozitie(int linie, int coloana);
	int verif_daca_mai_sunt_piese();
	int verif_piesa_apartine_jucatorului();
	int verif_daca_jucatorul_are_piese_neacoperite();
	void verificare_marime();

	//cauta o piesa de la un jucator anume -> verifica sa apartina acelui jucator 
	int cauta_linie_piesa();
	int cauta_coloana_piesa();

	//cauta piesa curenta -> verifica si marime si jucator
	int cauta_linie_piesa_curenta();
	int cauta_coloana_piesa_curenta();

	void realegere_pozitie();
	void schimb_de_jucatori();

	void tip_mutare_1(); //pun piesa pe tabla din exterior
	void tip_mutare_2(); //mut o piesa de pe tabla
	void undo(); //refacere mutare

	//pentru player vs computer 
	void imita_mutarea_adversarului(int linie, int coloana);
	void acopera_piesa_adversarului(int linie, int coloana);
	int cauta_pereche_pe_linie(int linie, int coloana, int jucator);
	int cauta_pereche_pe_coloana(int linie, int coloana, int jucator);
	int cauta_pereche_pe_diagonala_principala(int jucator);
	int cauta_pereche_pe_diagonala_secundara(int jucator);
	int verif_existenta_pereche_pe_tabla(int linie, int coloana, int jucator);
	int cauta_a_treia_casuta(int a, int b);
	void completare_pereche(int marime, int linie, int coloana);
	void blocare_adversar(int linie, int coloana);
	void strategie_de_blocare_a_adversarului(int linie_a, int coloana_a, int linie_p, int coloana_p, int linie_f, int coloana_f);
	void cauta_perechi_de_piese(int linie, int coloana, int linie_a, int coloana_a); //nu am ca parametru int jucator pt ca e o functie folosita doar de computer

	void afisare_tabla();
	void afisare_coordonate();

	int verif_castigator(int a, int b, int c);
	int castigator();
	void afisare_castigator(int a, int varianta_joc);

	void player_vs_player();
	void player_vs_computer();
};



