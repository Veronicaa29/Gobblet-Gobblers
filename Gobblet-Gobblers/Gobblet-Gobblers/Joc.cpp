#include "Joc.h"

Joc::Joc()
{
    tip_mutare = 0;

    //initializare jucatori
    jucator1.jucator = 1;
    jucator2.jucator = 2;

    jucator1.pieseMari = 2;
    jucator1.pieseMedii = 2;
    jucator1.pieseMici = 2;

    jucator2.pieseMari = 2;
    jucator2.pieseMedii = 2;
    jucator2.pieseMici = 2;

    jucator_curent.jucator = 0;
    adversar.jucator = 0;

    //initializare tabla de joc
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            tabla[i][j].totalPiese = 0;
            tabla[i][j].piese[0].jucator = 0;
            tabla[i][j].piese[0].marime = 0;
        }
    }

    //initializare coordonate
    ultima_mutare.linie_initiala = -1;
    ultima_mutare.coloana_initiala = -1;

    ultima_mutare.linie_finala = -1;
    ultima_mutare.coloana_initiala = -1;

    ultima_mutare.tip_mutare = 0;

    ultima_mutare_c.linie_initiala = -1;
    ultima_mutare_c.coloana_initiala = -1;

    ultima_mutare_c.linie_finala = -1;
    ultima_mutare_c.coloana_finala = -1;

    ultima_mutare_c.tip_mutare = 0;
}

void Joc::adauga_piesa_pe_pozitie(int linie, int coloana)
{
    tabla[linie][coloana].totalPiese++; // varf++;

    tabla[linie][coloana].piese[tabla[linie][coloana].totalPiese].marime = piesa_curenta.marime;
    tabla[linie][coloana].piese[tabla[linie][coloana].totalPiese].jucator = piesa_curenta.jucator;

    if (tip_mutare == 1)
    {
        if (piesa_curenta.marime == 1)
        {
            if (piesa_curenta.jucator == 1)
            {
                jucator1.pieseMici--;
            }
            else
            {
                jucator2.pieseMici--;
            }
        }
        else if (piesa_curenta.marime == 2)
        {
            if (piesa_curenta.jucator == 1)
            {
                jucator1.pieseMedii--;
            }
            else
            {
                jucator2.pieseMedii--;
            }
        }
        else if (piesa_curenta.marime == 3)
        {
            if (piesa_curenta.jucator == 1)
            {
                jucator1.pieseMari--;
            }
            else
            {
                jucator2.pieseMari--;
            }
        }
    }
}

void Joc::scoate_piesa_de_pe_pozitie(int linie, int coloana)
{
    tabla[linie][coloana].totalPiese--; // varf--
}

int Joc::ia_piesa_jucator_din_varf(int linie, int coloana)
{
    return tabla[linie][coloana].piese[tabla[linie][coloana].totalPiese].jucator;
}

int Joc::ia_piesa_marime_din_varf(int linie, int coloana)
{
    return tabla[linie][coloana].piese[tabla[linie][coloana].totalPiese].marime;
}

int Joc::verif_adaugare_piesa_pe_pozitie(int linie, int coloana)
{
    if (tabla[linie][coloana].totalPiese == 0 || tabla[linie][coloana].piese[tabla[linie][coloana].totalPiese].marime < piesa_curenta.marime) return 1;
    else return 0;
}

int Joc::verif_daca_mai_sunt_piese()
{
    if (jucator_curent.jucator == 1)
    {
        if (piesa_curenta.marime == 1 && jucator1.pieseMici != 0)
        {
            return 1;
        }
        if (piesa_curenta.marime == 2 && jucator1.pieseMedii != 0)
        {
            return 1;
        }
        if (piesa_curenta.marime == 3 && jucator1.pieseMari != 0)
        {
            return 1;
        }
    }
    else if (jucator_curent.jucator == 2)
    {
        if (piesa_curenta.marime == 1 && jucator2.pieseMici != 0)
        {
            return 1;
        }
        if (piesa_curenta.marime == 2 && jucator2.pieseMedii != 0)
        {
            return 1;
        }
        if (piesa_curenta.marime == 3 && jucator2.pieseMari != 0)
        {
            return 1;
        }
    }

    return 0;
}

int Joc::verif_piesa_apartine_jucatorului()
{
    if (jucator_curent.jucator == piesa_curenta.jucator) return 1;
    return 0;
}

int Joc::verif_daca_jucatorul_are_piese_neacoperite()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabla[i][j].piese[tabla[i][j].totalPiese].jucator == jucator_curent.jucator)
            {
                return 1;
            }
        }
    }

    return 0;
}

void Joc::verificare_marime()
{
    int ok = 0;
    if (piesa_curenta.marime != 1 && piesa_curenta.marime != 2 && piesa_curenta.marime != 3)
    {
        ok = 0;
        do
        {
            cout << "Dimensiunea aleasa nu exista. Alegeti alta dimensiune pentru piesa : ";
            cin >> piesa_curenta.marime;
            cout << endl;
            if (piesa_curenta.marime == 1 || piesa_curenta.marime == 2 || piesa_curenta.marime == 3) ok = 1;
        } while (!ok);
    }
}

int Joc::cauta_linie_piesa()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabla[i][j].piese[tabla[i][j].totalPiese].jucator == jucator_curent.jucator)
            {
                return i;
            }
        }
    }
}

int Joc::cauta_coloana_piesa()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabla[i][j].piese[tabla[i][j].totalPiese].jucator == jucator_curent.jucator)
            {
                return j;
            }
        }
    }
}

int Joc::cauta_linie_piesa_curenta()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabla[i][j].piese[tabla[i][j].totalPiese].jucator == jucator_curent.jucator &&
                tabla[i][j].piese[tabla[i][j].totalPiese].marime == piesa_curenta.marime) return i;
        }
    }
    return -1;
}

int Joc::cauta_coloana_piesa_curenta()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabla[i][j].piese[tabla[i][j].totalPiese].jucator == jucator_curent.jucator &&
                tabla[i][j].piese[tabla[i][j].totalPiese].marime == piesa_curenta.marime) return j;
        }
    }
    return -1;
}

void Joc::realegere_pozitie()
{
    int linie, coloana;
    int ok = 0;
    do
    {
        cout << "Piesa nu poate fi plasata pe pozitia aleasa. Alegeti alte coordonate : ";
        cin >> linie >> coloana;
        cout << endl;

        if (linie < 0 || linie > 2 || coloana < 0 || coloana > 2)
        {
            ok = 0;
            do
            {
                cout << "Coordonatele alese nu exista. Alegeti alte coordonate : ";
                cin >> linie >> coloana;
                cout << endl;
                if (linie >= 0 && linie <= 2 && coloana >= 0 && coloana <= 2) ok = 1;
            } while (!ok);
        }

        if (verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
        {
            ok = 1;

            ultima_mutare.linie_finala = linie;
            ultima_mutare.coloana_finala = coloana;

            adauga_piesa_pe_pozitie(linie, coloana);
        }
    } while (!ok);
}

void Joc::schimb_de_jucatori()
{
    if (jucator_curent.jucator == 1)
    {
        jucator_curent.jucator = 2;
        piesa_curenta.jucator = 2;
    }
    else
    {
        jucator_curent.jucator = 1;
        piesa_curenta.jucator = 1;
    }
}

void Joc::tip_mutare_1()
{
    int linie, coloana, ok;

    tip_mutare = 1;

    ultima_mutare.tip_mutare = 1;

    ultima_mutare.linie_initiala = -1;
    ultima_mutare.coloana_initiala = -1;

    cout << "Alegeti dimensiunea piesei : ";
    cin >> piesa_curenta.marime;
    cout << endl;

    verificare_marime();

    cout << "Introduceti coordonatele pozitiei alese : ";
    cin >> linie >> coloana;
    cout << endl;

    if (linie < 0 || linie > 2 || coloana < 0 || coloana > 2)
    {
        ok = 0;
        do
        {
            cout << "Coordonatele alese nu exista. Alegeti alte coordonate : ";
            cin >> linie >> coloana;
            cout << endl;
            if (linie >= 0 && linie <= 2 && coloana >= 0 && coloana <= 2) ok = 1;
        } while (!ok);
    }

    if (verif_daca_mai_sunt_piese() == 1 && verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
    {
        ultima_mutare.linie_finala = linie;
        ultima_mutare.coloana_finala = coloana;

        adauga_piesa_pe_pozitie(linie, coloana);
    }
    else if (verif_daca_mai_sunt_piese() == 0)
    {
        ok = 0;
        do
        {
            cout << "Nu mai sunt piese cu aceasta dimensiune. Introduceti o alta dimensiune : ";
            cin >> piesa_curenta.marime;
            cout << endl;
            if (verif_daca_mai_sunt_piese() == 1)
            {
                if (verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
                {
                    ok = 1;

                    ultima_mutare.linie_finala = linie;
                    ultima_mutare.coloana_finala = coloana;

                    adauga_piesa_pe_pozitie(linie, coloana);
                }
                else
                {
                    realegere_pozitie();
                }
            }
        } while (!ok);
    }
    else if (verif_adaugare_piesa_pe_pozitie(linie, coloana) == 0)
    {
        realegere_pozitie();
    }
}

void Joc::tip_mutare_2()
{
    int linie, coloana, ok;

    tip_mutare = 2;

    ultima_mutare.tip_mutare = 2;

    cout << "Introduceti coordonatele piesei pe care doriti sa o mutati : ";
    cin >> linie >> coloana;
    cout << endl;

    if (linie < 0 || linie > 2 || coloana < 0 || coloana > 2)
    {
        ok = 0;
        do
        {
            cout << "Coordonatele alese nu exista. Alegeti alte coordonate : ";
            cin >> linie >> coloana;
            cout << endl;
            if (linie >= 0 && linie <= 2 && coloana >= 0 && coloana <= 2) ok = 1;
        } while (!ok);
    }

    ultima_mutare.linie_initiala = linie;
    ultima_mutare.coloana_initiala = coloana;

    piesa_curenta.jucator = ia_piesa_jucator_din_varf(linie, coloana);
    piesa_curenta.marime = ia_piesa_marime_din_varf(linie, coloana);

    if (verif_piesa_apartine_jucatorului() == 0)
    {
        ok = 0;
        do
        {
            cout << "Piesa nu va apartine. Alegeti coordonatele unei piesa care va apartine : ";
            cin >> linie >> coloana;
            cout << endl;

            piesa_curenta.jucator = ia_piesa_jucator_din_varf(linie, coloana);
            piesa_curenta.marime = ia_piesa_marime_din_varf(linie, coloana);

            if (verif_piesa_apartine_jucatorului() == 1)
            {
                ok = 1;

                ultima_mutare.linie_initiala = linie;
                ultima_mutare.coloana_initiala = coloana;
            }
        } while (!ok);
    }

    int linie_f, coloana_f;
    cout << "Introduceti coordonatele pozitiei unde doriti sa mutati piesa : ";
    cin >> linie_f >> coloana_f;
    cout << endl;

    if (linie_f < 0 || linie_f > 2 || coloana_f < 0 || coloana_f > 2)
    {
        ok = 0;
        do
        {
            cout << "Coordonatele alese nu exista. Alegeti alte coordonate : ";
            cin >> linie_f >> coloana_f;
            cout << endl;
            if (linie_f >= 0 && linie_f <= 2 && coloana_f >= 0 && coloana_f <= 2) ok = 1;
        } while (!ok);
    }

    if (verif_adaugare_piesa_pe_pozitie(linie_f, coloana_f) == 1)
    {
        ultima_mutare.linie_finala = linie_f;
        ultima_mutare.coloana_finala = coloana_f;

        adauga_piesa_pe_pozitie(linie_f, coloana_f);
        scoate_piesa_de_pe_pozitie(linie, coloana);
    }
    else
    {
        do
        {
            cout << "Piesa nu poate fi plasata pe pozitia aleasa. Reintroduceti coordonatele pozitiei unde doriti sa mutati piesa : ";
            cin >> linie_f >> coloana_f;
            cout << endl;

            if (linie_f < 0 || linie_f > 2 || coloana_f < 0 || coloana_f > 2)
            {
                ok = 0;
                do
                {
                    cout << "Coordonatele alese nu exista. Alegeti alte coordonate : ";
                    cin >> linie_f >> coloana_f;
                    cout << endl;
                    if (linie_f >= 0 && linie_f <= 2 && coloana_f >= 0 && coloana_f <= 2) ok = 1;
                } while (!ok);
            }

            if (verif_adaugare_piesa_pe_pozitie(linie_f, coloana_f) == 1)
            {
                ok = 1;

                ultima_mutare.linie_finala = linie_f;
                ultima_mutare.coloana_finala = coloana_f;

                adauga_piesa_pe_pozitie(linie_f, coloana_f);
                scoate_piesa_de_pe_pozitie(linie, coloana);
            }
        } while (!ok);
    }
}

void Joc::undo()
{
    int marime, jucator;

    if (ultima_mutare.tip_mutare == 1)
    {
        marime = tabla[ultima_mutare.linie_finala][ultima_mutare.coloana_finala].piese[tabla[ultima_mutare.linie_finala][ultima_mutare.coloana_finala].totalPiese].marime;
        jucator = tabla[ultima_mutare.linie_finala][ultima_mutare.coloana_finala].piese[tabla[ultima_mutare.linie_finala][ultima_mutare.coloana_finala].totalPiese].jucator;

        if (jucator == 1)
        {
            if (marime == 1)
            {
                jucator1.pieseMici++;
                scoate_piesa_de_pe_pozitie(ultima_mutare.linie_finala, ultima_mutare.coloana_finala);
            }
            else if (marime == 2)
            {
                jucator1.pieseMedii++;
                scoate_piesa_de_pe_pozitie(ultima_mutare.linie_finala, ultima_mutare.coloana_finala);
            }
            else if (marime == 3)
            {
                jucator1.pieseMari++;
                scoate_piesa_de_pe_pozitie(ultima_mutare.linie_finala, ultima_mutare.coloana_finala);
            }
        }
        else if (jucator == 2)
        {
            if (marime == 1)
            {
                jucator2.pieseMici++;
                scoate_piesa_de_pe_pozitie(ultima_mutare.linie_finala, ultima_mutare.coloana_finala);
            }
            else if (marime == 2)
            {
                jucator2.pieseMedii++;
                scoate_piesa_de_pe_pozitie(ultima_mutare.linie_finala, ultima_mutare.coloana_finala);
            }
            else if (marime == 3)
            {
                jucator2.pieseMari++;
                scoate_piesa_de_pe_pozitie(ultima_mutare.linie_finala, ultima_mutare.coloana_finala);
            }
        }
    }
    else if (ultima_mutare.tip_mutare == 2)
    {
        piesa_curenta.marime = tabla[ultima_mutare.linie_finala][ultima_mutare.coloana_finala].piese[tabla[ultima_mutare.linie_finala][ultima_mutare.coloana_finala].totalPiese].marime;
        piesa_curenta.jucator = tabla[ultima_mutare.linie_finala][ultima_mutare.coloana_finala].piese[tabla[ultima_mutare.linie_finala][ultima_mutare.coloana_finala].totalPiese].jucator;

        adauga_piesa_pe_pozitie(ultima_mutare.linie_initiala, ultima_mutare.coloana_initiala);
        scoate_piesa_de_pe_pozitie(ultima_mutare.linie_finala, ultima_mutare.coloana_finala);
    }

    cout << "Piesa a fost mutata in pozitia initiala : " << endl;
    afisare_tabla();
    cout << endl;
}

void Joc::imita_mutarea_adversarului(int linie, int coloana)
{
    int linie_f, coloana_f, linie_s, coloana_s;

    if (linie == 0 || linie == 2)
    {
        linie_f = 1;
        coloana_f = coloana;

        piesa_curenta.marime = 1;

        if (verif_daca_mai_sunt_piese() == 1)
        {
            if (verif_adaugare_piesa_pe_pozitie(linie_f, coloana_f) == 1)
            {
                tip_mutare = 1;

                ultima_mutare_c.linie_finala = linie_f;
                ultima_mutare_c.coloana_finala = coloana_f;

                adauga_piesa_pe_pozitie(linie_f, coloana_f);
            }
            else
            {
                piesa_curenta.marime = 2;
                if (verif_daca_mai_sunt_piese() == 1)
                {
                    if (verif_adaugare_piesa_pe_pozitie(linie_f, coloana_f) == 1)
                    {
                        tip_mutare = 1;

                        ultima_mutare_c.linie_finala = linie_f;
                        ultima_mutare_c.coloana_finala = coloana_f;

                        adauga_piesa_pe_pozitie(linie_f, coloana_f);
                    }
                }
                else
                {
                    piesa_curenta.marime = 3;
                    if (verif_daca_mai_sunt_piese() == 1)
                    {
                        if (verif_adaugare_piesa_pe_pozitie(linie_f, coloana_f) == 1)
                        {
                            tip_mutare = 1;

                            ultima_mutare_c.linie_finala = linie_f;
                            ultima_mutare_c.coloana_finala = coloana_f;

                            adauga_piesa_pe_pozitie(linie_f, coloana_f);
                        }
                    }
                    else
                    {
                        ///muta o piesa de pe tabla

                        piesa_curenta.marime = 1;

                        linie_s = cauta_linie_piesa_curenta();
                        coloana_s = cauta_coloana_piesa_curenta();

                        if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
                        {
                            tip_mutare = 2;

                            ultima_mutare_c.linie_finala = linie;
                            ultima_mutare_c.coloana_finala = coloana;

                            adauga_piesa_pe_pozitie(linie, coloana);
                            scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
                        }
                        else
                        {
                            piesa_curenta.marime = 2;

                            linie_s = cauta_linie_piesa_curenta();
                            coloana_s = cauta_coloana_piesa_curenta();

                            if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
                            {
                                tip_mutare = 2;

                                ultima_mutare_c.linie_finala = linie;
                                ultima_mutare_c.coloana_finala = coloana;

                                adauga_piesa_pe_pozitie(linie, coloana);
                                scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
                            }
                        }
                    }
                }
            }
        }
    }
    else if (linie == 1)
    {
        linie_f = 0;
        coloana_f = coloana;

        piesa_curenta.marime = 1;

        if (tabla[linie_f][coloana_f].piese[tabla[linie_f][coloana_f].totalPiese].marime != 3)
        {
            if (verif_daca_mai_sunt_piese() == 1)
            {
                if (verif_adaugare_piesa_pe_pozitie(linie_f, coloana_f) == 1)
                {
                    tip_mutare = 1;

                    ultima_mutare_c.linie_finala = linie_f;
                    ultima_mutare_c.coloana_finala = coloana_f;

                    adauga_piesa_pe_pozitie(linie_f, coloana_f);
                }
                else
                {
                    piesa_curenta.marime = 2;
                    if (verif_daca_mai_sunt_piese() == 1)
                    {
                        if (verif_adaugare_piesa_pe_pozitie(linie_f, coloana_f) == 1)
                        {
                            tip_mutare = 1;

                            ultima_mutare_c.linie_finala = linie_f;
                            ultima_mutare_c.coloana_finala = coloana_f;

                            adauga_piesa_pe_pozitie(linie_f, coloana_f);
                        }
                    }
                    else
                    {
                        piesa_curenta.marime = 3;
                        if (verif_daca_mai_sunt_piese() == 1)
                        {
                            if (verif_adaugare_piesa_pe_pozitie(linie_f, coloana_f) == 1)
                            {
                                tip_mutare = 1;

                                ultima_mutare_c.linie_finala = linie_f;
                                ultima_mutare_c.coloana_finala = coloana_f;

                                adauga_piesa_pe_pozitie(linie_f, coloana_f);
                            }
                        }
                        else
                        {
                            ///muta o piesa de pe tabla
                            piesa_curenta.marime = 1;

                            linie_s = cauta_linie_piesa_curenta();
                            coloana_s = cauta_coloana_piesa_curenta();

                            if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
                            {
                                tip_mutare = 2;

                                ultima_mutare_c.linie_finala = linie;
                                ultima_mutare_c.coloana_finala = coloana;

                                adauga_piesa_pe_pozitie(linie, coloana);
                                scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
                            }
                            else
                            {
                                piesa_curenta.marime = 2;

                                linie_s = cauta_linie_piesa_curenta();
                                coloana_s = cauta_coloana_piesa_curenta();

                                if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
                                {
                                    tip_mutare = 2;

                                    ultima_mutare_c.linie_finala = linie;
                                    ultima_mutare_c.coloana_finala = coloana;

                                    adauga_piesa_pe_pozitie(linie, coloana);
                                    scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (tabla[linie_f][coloana_f].piese[tabla[linie_f][coloana_f].totalPiese].marime == 3)
        {
            linie_f = 2;
            coloana_f = coloana;

            piesa_curenta.marime = 1;

            if (verif_daca_mai_sunt_piese() == 1)
            {
                if (verif_adaugare_piesa_pe_pozitie(linie_f, coloana_f) == 1)
                {
                    tip_mutare = 1;

                    ultima_mutare_c.linie_finala = linie_f;
                    ultima_mutare_c.coloana_finala = coloana_f;

                    adauga_piesa_pe_pozitie(linie_f, coloana_f);
                }
                else
                {
                    piesa_curenta.marime = 2;
                    if (verif_daca_mai_sunt_piese() == 1)
                    {
                        if (verif_adaugare_piesa_pe_pozitie(linie_f, coloana_f) == 1)
                        {
                            tip_mutare = 1;

                            ultima_mutare_c.linie_finala = linie_f;
                            ultima_mutare_c.coloana_finala = coloana_f;

                            adauga_piesa_pe_pozitie(linie_f, coloana_f);
                        }
                    }
                    else
                    {
                        piesa_curenta.marime = 3;
                        if (verif_daca_mai_sunt_piese() == 1)
                        {
                            if (verif_adaugare_piesa_pe_pozitie(linie_f, coloana_f) == 1)
                            {
                                tip_mutare = 1;

                                ultima_mutare_c.linie_finala = linie_f;
                                ultima_mutare_c.coloana_finala = coloana_f;

                                adauga_piesa_pe_pozitie(linie_f, coloana_f);
                            }
                        }
                        else
                        {
                            ///muta o piesa de pe tabla

                            piesa_curenta.marime = 1;

                            linie_s = cauta_linie_piesa_curenta();
                            coloana_s = cauta_coloana_piesa_curenta();

                            if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
                            {
                                tip_mutare = 2;

                                ultima_mutare_c.linie_finala = linie;
                                ultima_mutare_c.coloana_finala = coloana;

                                adauga_piesa_pe_pozitie(linie, coloana);
                                scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
                            }
                            else
                            {
                                piesa_curenta.marime = 2;

                                linie_s = cauta_linie_piesa_curenta();
                                coloana_s = cauta_coloana_piesa_curenta();

                                if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
                                {
                                    tip_mutare = 2;

                                    ultima_mutare_c.linie_finala = linie;
                                    ultima_mutare_c.coloana_finala = coloana;

                                    adauga_piesa_pe_pozitie(linie, coloana);
                                    scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Joc::acopera_piesa_adversarului(int linie, int coloana)
{
    int linie_s, coloana_s;

    piesa_curenta.marime = 3;

    if (verif_daca_mai_sunt_piese() == 1)
    {
        tip_mutare = 1;
        adauga_piesa_pe_pozitie(linie, coloana);
    }
    else if (verif_daca_mai_sunt_piese() == 0)
    {
        piesa_curenta.marime = 2;

        if (verif_daca_mai_sunt_piese() == 1 &&
            tabla[linie][coloana].piese[tabla[linie][coloana].totalPiese].marime < 2)
        {
            tip_mutare = 1;
            adauga_piesa_pe_pozitie(linie, coloana);
        }
        else if (verif_daca_mai_sunt_piese() == 0)
        {
            //imita_mutarea_adversarului(tabla, linie, coloana); <- asta era initial
            //muta de pe tabla <- asta e acum

            piesa_curenta.marime = 3;

            linie_s = cauta_linie_piesa_curenta();
            coloana_s = cauta_coloana_piesa_curenta();

            if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
            {
                tip_mutare = 2;

                ultima_mutare_c.linie_finala = linie;
                ultima_mutare_c.coloana_finala = coloana;

                adauga_piesa_pe_pozitie(linie, coloana);
                scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
            }
        }
    }
}

int Joc::cauta_pereche_pe_linie(int linie, int coloana, int jucator)
{
    for (int j = 0; j < 3; j++)
    {
        if (j != coloana && tabla[linie][j].piese[tabla[linie][j].totalPiese].jucator == jucator)
        {
            return j; ///coloana pe care se afla piesa pereche -> piesa se afla pe aceeasi linie
        }
    }
    return -1;
}

int Joc::cauta_pereche_pe_coloana(int linie, int coloana, int jucator)
{
    for (int i = 0; i < 3; i++)
    {
        if (i != linie && tabla[i][coloana].piese[tabla[i][coloana].totalPiese].jucator == jucator)
        {
            return i;
        }
    }
    return -1;
}

int Joc::cauta_pereche_pe_diagonala_principala(int jucator)
{
    if (tabla[0][0].piese[tabla[0][0].totalPiese].jucator == jucator &&
        tabla[1][1].piese[tabla[1][1].totalPiese].jucator == jucator)
    {
        return 1;///caz 1 -> primele 2 casute de pe dp;
    }
    else if (tabla[1][1].piese[tabla[1][1].totalPiese].jucator == jucator &&
        tabla[2][2].piese[tabla[2][2].totalPiese].jucator == jucator)
    {
        return 2;///caz 2 -> ultimele 2 casute de pe dp;
    }
    else if (tabla[0][0].piese[tabla[0][0].totalPiese].jucator == jucator &&
        tabla[2][2].piese[tabla[2][2].totalPiese].jucator == jucator)
    {
        return 3;///caz 3 -> prima si ultima casuta de pe dp;
    }
    return 0;
}

int Joc::cauta_pereche_pe_diagonala_secundara(int jucator)
{
    if (tabla[0][2].piese[tabla[0][2].totalPiese].jucator == jucator &&
        tabla[1][1].piese[tabla[1][1].totalPiese].jucator == jucator)
    {
        return 1;///caz 1 -> primele 2 casute de pe ds;
    }
    else if (tabla[1][1].piese[tabla[1][1].totalPiese].jucator == jucator &&
        tabla[2][0].piese[tabla[2][0].totalPiese].jucator == jucator)
    {
        return 2;///caz 2 -> ultimele 2 casute de pe ds;
    }
    else if (tabla[0][2].piese[tabla[0][2].totalPiese].jucator == jucator &&
        tabla[2][0].piese[tabla[2][0].totalPiese].jucator == jucator)
    {
        return 3;///caz 3 -> prima si ultima casuta de pe ds;
    }
    return 0;
}

int Joc::verif_existenta_pereche_pe_tabla(int linie, int coloana, int jucator)
{
    if (cauta_pereche_pe_linie(linie, coloana, jucator) == -1 && cauta_pereche_pe_coloana(linie, coloana, jucator) == -1 &&
        cauta_pereche_pe_diagonala_principala(jucator) == 0 && cauta_pereche_pe_diagonala_secundara(jucator) == 0)
    {
        return 0;/// nu am nici o pereche de piese pe tabla;
    }
    else return 1;///am cel putin o pereche de piese pe tabla
}

int Joc::cauta_a_treia_casuta(int a, int b)
{
    if (a == 0 && b == 1 || a == 1 && b == 0) return 2;
    else if (a == 0 && b == 2 || a == 2 && b == 0) return 1;
    else if (a == 1 && b == 2 || a == 2 && b == 1) return 0;
}

void Joc::completare_pereche(int marime, int linie, int coloana)
{
    int linie_s, coloana_s;

    tip_mutare = 1;

    if (marime == 0)
    {
        piesa_curenta.marime = 1;
        if (verif_daca_mai_sunt_piese() == 1)
        {
            ultima_mutare_c.linie_finala = linie;
            ultima_mutare_c.coloana_finala = coloana;

            adauga_piesa_pe_pozitie(linie, coloana);
        }
        else
        {
            piesa_curenta.marime = 2;
            if (verif_daca_mai_sunt_piese() == 1)
            {
                ultima_mutare_c.linie_finala = linie;
                ultima_mutare_c.coloana_finala = coloana;

                adauga_piesa_pe_pozitie(linie, coloana);
            }
            else
            {
                piesa_curenta.marime = 3;
                if (verif_daca_mai_sunt_piese() == 1)
                {
                    ultima_mutare_c.linie_finala = linie;
                    ultima_mutare_c.coloana_finala = coloana;

                    adauga_piesa_pe_pozitie(linie, coloana);
                }
                else
                {
                    ///muta o piesa proprie de pe tabla

                    piesa_curenta.marime = 3;

                    linie_s = cauta_linie_piesa_curenta();
                    coloana_s = cauta_coloana_piesa_curenta();

                    if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
                    {
                        tip_mutare = 2;

                        ultima_mutare_c.linie_finala = linie;
                        ultima_mutare_c.coloana_finala = coloana;

                        adauga_piesa_pe_pozitie(linie, coloana);
                        scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
                    }
                }
            }
        }
    }
    else if (marime == 1)
    {
        piesa_curenta.marime = 2;
        if (verif_daca_mai_sunt_piese() == 1)
        {
            ultima_mutare_c.linie_finala = linie;
            ultima_mutare_c.coloana_finala = coloana;

            adauga_piesa_pe_pozitie(linie, coloana);
        }
        else
        {
            piesa_curenta.marime = 3;
            if (verif_daca_mai_sunt_piese() == 1)
            {
                ultima_mutare_c.linie_finala = linie;
                ultima_mutare_c.coloana_finala = coloana;

                adauga_piesa_pe_pozitie(linie, coloana);
            }
            else
            {
                ///muta piesa proprie de pe tabla

                piesa_curenta.marime = 3;

                linie_s = cauta_linie_piesa_curenta();
                coloana_s = cauta_coloana_piesa_curenta();

                if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
                {
                    tip_mutare = 2;

                    ultima_mutare_c.linie_finala = linie;
                    ultima_mutare_c.coloana_finala = coloana;

                    adauga_piesa_pe_pozitie(linie, coloana);
                    scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
                }
            }
        }
    }
    else if (marime == 2)
    {
        piesa_curenta.marime = 3;
        if (verif_daca_mai_sunt_piese() == 1)
        {
            ultima_mutare_c.linie_finala = linie;
            ultima_mutare_c.coloana_finala = coloana;

            adauga_piesa_pe_pozitie(linie, coloana);
        }
        else
        {
            ///muta piesa proprie de pe tabla

            piesa_curenta.marime = 3;

            linie_s = cauta_linie_piesa_curenta();
            coloana_s = cauta_coloana_piesa_curenta();

            if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
            {
                tip_mutare = 2;

                ultima_mutare_c.linie_finala = linie;
                ultima_mutare_c.coloana_finala = coloana;

                adauga_piesa_pe_pozitie(linie, coloana);
                scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
            }
        }
    }
    else if (marime == 3)
    {
        imita_mutarea_adversarului(linie, coloana);
    }
}

void Joc::blocare_adversar(int linie, int coloana)
{
    int linie_s, coloana_s;

    tip_mutare = 1;

    piesa_curenta.marime = 3;
    if (verif_daca_mai_sunt_piese() == 1)
    {
        if (verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
        {
            ultima_mutare_c.linie_finala = linie;
            ultima_mutare_c.coloana_finala = coloana;

            adauga_piesa_pe_pozitie(linie, coloana);
        }
    }
    else if (verif_daca_mai_sunt_piese() == 0)
    {
        piesa_curenta.marime = 2;
        {
            if (verif_daca_mai_sunt_piese() == 1)
            {
                if (verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
                {
                    ultima_mutare_c.linie_finala = linie;
                    ultima_mutare_c.coloana_finala = coloana;

                    adauga_piesa_pe_pozitie(linie, coloana);
                }
            }
            else if (verif_daca_mai_sunt_piese() == 0)
            {
                piesa_curenta.marime = 1;
                if (verif_daca_mai_sunt_piese() == 1)
                {
                    ultima_mutare_c.linie_finala = linie;
                    ultima_mutare_c.coloana_finala = coloana;

                    adauga_piesa_pe_pozitie(linie, coloana);
                }
                else
                {
                    ///muta piesa proprie de pe tabla

                    piesa_curenta.marime = 3;

                    linie_s = cauta_linie_piesa_curenta();
                    coloana_s = cauta_coloana_piesa_curenta();

                    if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie, coloana) == 1)
                    {
                        tip_mutare = 2;

                        ultima_mutare_c.linie_finala = linie;
                        ultima_mutare_c.coloana_finala = coloana;

                        adauga_piesa_pe_pozitie(linie, coloana);
                        scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
                    }
                }
            }
        }
    }
}

void Joc::strategie_de_blocare_a_adversarului(int linie_a, int coloana_a, int linie_p, int coloana_p, int linie_f, int coloana_f)
{
    int linie_s, coloana_s;

    if (tabla[linie_a][coloana_a].piese[tabla[linie_a][coloana_a].totalPiese].marime == 3 &&
        tabla[linie_p][coloana_p].piese[tabla[linie_p][coloana_p].totalPiese].marime == 3)
    {
        ///ambele piese care formeaza perechea sunt mari -> calculatorul incearca sa ocupe a treia casuta pentru a bloca jucatorul
        blocare_adversar(linie_f, coloana_f);
    }
    else if (tabla[linie_a][coloana_a].piese[tabla[linie_a][coloana_a].totalPiese].marime == 2)
    {
        ///una dintre piese este de dimensiune medie -> calculatorul incearca sa acopere acea piesa -> daca nu poate sunt verificate alte piese
        piesa_curenta.marime = 3;
        if (verif_daca_mai_sunt_piese() == 1)
        {
            tip_mutare = 1;

            ultima_mutare_c.linie_finala = linie_a;
            ultima_mutare_c.coloana_finala = coloana_a;

            adauga_piesa_pe_pozitie(linie_a, coloana_a);
        }
        else
        {
            ///muta de pe tabla

            piesa_curenta.marime = 3;

            linie_s = cauta_linie_piesa_curenta();
            coloana_s = cauta_coloana_piesa_curenta();

            if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie_a, coloana_a) == 1)
            {
                tip_mutare = 2;

                ultima_mutare_c.linie_finala = linie_a;
                ultima_mutare_c.coloana_finala = coloana_a;

                adauga_piesa_pe_pozitie(linie_a, coloana_a);
                scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
            }
        }
    }
    else if (tabla[linie_a][coloana_a].piese[tabla[linie_a][coloana_a].totalPiese].marime == 1)
    {
        ///una dintre piese este de dimensiune mica -> calculatorul incearca sa acopere acea piesa -> daca nu poate sunt verificate alte piese
        piesa_curenta.marime = 2;
        if (verif_daca_mai_sunt_piese() == 1)
        {
            tip_mutare = 1;

            ultima_mutare_c.linie_finala = linie_a;
            ultima_mutare_c.coloana_finala = coloana_a;

            adauga_piesa_pe_pozitie(linie_a, coloana_a);
        }
        else
        {
            piesa_curenta.marime = 3;
            if (verif_daca_mai_sunt_piese() == 1)
            {
                tip_mutare = 1;

                ultima_mutare_c.linie_finala = linie_a;
                ultima_mutare_c.coloana_finala = coloana_a;

                adauga_piesa_pe_pozitie(linie_a, coloana_a);
            }
            else
            {
                ///muta de pe tabla

                piesa_curenta.marime = 3;

                linie_s = cauta_linie_piesa_curenta();
                coloana_s = cauta_coloana_piesa_curenta();

                if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie_a, coloana_a) == 1)
                {
                    tip_mutare = 2;

                    ultima_mutare_c.linie_finala = linie_a;
                    ultima_mutare_c.coloana_finala = coloana_a;

                    adauga_piesa_pe_pozitie(linie_a, coloana_a);
                    scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
                }
            }
        }
    }
    else if (tabla[linie_p][coloana_p].piese[tabla[linie_p][coloana_p].totalPiese].marime == 2)
    {
        ///una dintre piese este de dimensiune medie -> calculatorul incearca sa acopere acea piesa -> daca nu poate sunt verificate alte piese
        piesa_curenta.marime = 3;
        if (verif_daca_mai_sunt_piese() == 1)
        {
            tip_mutare = 1;

            ultima_mutare_c.linie_finala = linie_p;
            ultima_mutare_c.coloana_finala = coloana_p;

            adauga_piesa_pe_pozitie(linie_p, coloana_p);
        }
        else
        {
            ///muta de pe tabla

            piesa_curenta.marime = 3;

            linie_s = cauta_linie_piesa_curenta();
            coloana_s = cauta_coloana_piesa_curenta();

            if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie_p, coloana_p) == 1)
            {
                tip_mutare = 2;

                ultima_mutare_c.linie_finala = linie_p;
                ultima_mutare_c.coloana_finala = coloana_p;

                adauga_piesa_pe_pozitie(linie_p, coloana_p);
                scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
            }
        }
    }
    else if (tabla[linie_p][coloana_p].piese[tabla[linie_p][coloana_p].totalPiese].marime == 1)
    {
        ///una dintre piese este de dimensiune mica -> calculatorul incearca sa acopere acea piesa -> daca nu poate sunt verificate alte piese
        piesa_curenta.marime = 2;
        if (verif_daca_mai_sunt_piese() == 1)
        {
            tip_mutare = 1;

            ultima_mutare_c.linie_finala = linie_p;
            ultima_mutare_c.coloana_finala = coloana_p;

            adauga_piesa_pe_pozitie(linie_p, coloana_p);
        }
        else
        {
            piesa_curenta.marime = 3;
            if (verif_daca_mai_sunt_piese() == 1)
            {
                tip_mutare = 1;

                ultima_mutare_c.linie_finala = linie_p;
                ultima_mutare_c.coloana_finala = coloana_p;

                adauga_piesa_pe_pozitie(linie_p, coloana_p);
            }
            else
            {
                ///muta de pe tabla

                piesa_curenta.marime = 3;

                linie_s = cauta_linie_piesa_curenta();
                coloana_s = cauta_coloana_piesa_curenta();

                if (linie_s != -1 && coloana_s != -1 && verif_adaugare_piesa_pe_pozitie(linie_p, coloana_p) == 1)
                {
                    tip_mutare = 2;

                    ultima_mutare_c.linie_finala = linie_p;
                    ultima_mutare_c.coloana_finala = coloana_p;

                    adauga_piesa_pe_pozitie(linie_p, coloana_p);
                    scoate_piesa_de_pe_pozitie(linie_s, coloana_s);
                }
            }
        }
    }
}

void Joc::cauta_perechi_de_piese(int linie, int coloana, int linie_a, int coloana_a)
{
    int marime, caz;

    int linie_p, coloana_p; ///coordonatele unde se afla perechea unei piese
    int linie_f, coloana_f; ///coordonatele unde trebuie pusa a treia piesa -> pt castig

    ///cauta perechi de piese de la jucatorul curent -> pune piesa pe a treia casuta pentru a castiga -> daca nu poate sa faca asta cauta perechi de piese 
    //de la adversar si incearca sa il blocheze

    if (cauta_pereche_pe_linie(linie, coloana, jucator_curent.jucator) != -1)
    {
        ///gaseste pereche pe linie

        linie_p = linie;
        coloana_p = cauta_pereche_pe_linie(linie, coloana, jucator_curent.jucator);

        linie_f = linie;
        coloana_f = cauta_a_treia_casuta(coloana, coloana_p);

        ///trebuie verificat daca exista vreo piesa pe a treia casuta si dimensiunea acesteia

        marime = tabla[linie_f][coloana_f].piese[tabla[linie_f][coloana_f].totalPiese].marime;///marimea piesei de pe casuta a treia ( daca exista )

        ///incearca sa adauge piesa pe a treia casuta pentru a castiga

        completare_pereche(marime, linie_f, coloana_f);

        ///daca marime = 3 -> nu poate sa completeze -> cauta o alta pereche -> nu se gaseste / completeaza o alta pereche -> cautare pereche adversar
    }
    else if (cauta_pereche_pe_coloana(linie, coloana, jucator_curent.jucator) != -1)
    {
        ///gaseste pereche pe coloana

        linie_p = cauta_pereche_pe_coloana(linie, coloana, jucator_curent.jucator);
        coloana_p = coloana;

        linie_f = cauta_a_treia_casuta(linie, linie_p);
        coloana_f = coloana;

        marime = tabla[linie_f][coloana_f].piese[tabla[linie_f][coloana_f].totalPiese].marime;///marimea piesei de pe casuta a treia ( daca exista )

        completare_pereche(marime, linie_f, coloana_f);
    }
    else if (cauta_pereche_pe_diagonala_principala(jucator_curent.jucator) != 0)
    {
        ///gaseste pereche pe diagonala principala;

        caz = cauta_pereche_pe_diagonala_principala(jucator_curent.jucator);

        if (caz == 1)
        {
            linie_f = coloana_f = 2;

            marime = tabla[linie_f][coloana_f].piese[tabla[linie_f][coloana_f].totalPiese].marime;

            completare_pereche(marime, linie_f, coloana_f);
        }
        else if (caz == 2)
        {
            linie_f = coloana_f = 0;

            marime = tabla[linie_f][coloana_f].piese[tabla[linie_f][coloana_f].totalPiese].marime;

            completare_pereche(marime, linie_f, coloana_f);
        }
        else if (caz == 3)
        {
            linie_f = coloana_f = 1;

            marime = tabla[linie_f][coloana_f].piese[tabla[linie_f][coloana_f].totalPiese].marime;

            completare_pereche(marime, linie_f, coloana_f);
        }

    }
    else if (cauta_pereche_pe_diagonala_secundara(jucator_curent.jucator) != 0)
    {
        ///gaseste pereche pe diagonala secundara;

        caz = cauta_pereche_pe_diagonala_secundara(jucator_curent.jucator);

        if (caz == 1)
        {
            linie_f = 2;
            coloana_f = 0;

            marime = tabla[linie_f][coloana_f].piese[tabla[linie_f][coloana_f].totalPiese].marime;

            completare_pereche(marime, linie_f, coloana_f);
        }
        else if (caz == 2)
        {
            linie_f = 0;
            coloana_f = 2;

            marime = tabla[linie_f][coloana_f].piese[tabla[linie_f][coloana_f].totalPiese].marime;

            completare_pereche(marime, linie_f, coloana_f);
        }
        else if (caz == 3)
        {
            linie_f = coloana_f = 1;

            marime = tabla[linie_f][coloana_f].piese[tabla[linie_f][coloana_f].totalPiese].marime;

            completare_pereche(marime, linie_f, coloana_f);
        }
    }
    else
    {
        ///blocheaza adversarul

        if (jucator_curent.jucator == 1)
        {
            adversar.jucator = 2;
        }
        else adversar.jucator = 1;

        if (cauta_pereche_pe_linie(linie_a, coloana_a, adversar.jucator) != -1)
        {
            //a gasit pereche pe linie la adversar

            linie_p = linie_a;
            coloana_p = cauta_pereche_pe_linie(linie_a, coloana_a, adversar.jucator);

            linie_f = linie_a;
            coloana_f = cauta_a_treia_casuta(coloana_a, coloana_p);

            strategie_de_blocare_a_adversarului(linie_a, coloana_a, linie_p, coloana_p, linie_f, coloana_f);
        }
        else if (cauta_pereche_pe_coloana(linie_a, coloana_a, adversar.jucator) != -1)
        {
            //a gasit pereche pe coloana la adversar

            linie_p = cauta_pereche_pe_coloana(linie_a, coloana_a, adversar.jucator);
            coloana_p = coloana_a;

            linie_f = cauta_a_treia_casuta(linie_a, linie_p);
            coloana_f = coloana_a;

            strategie_de_blocare_a_adversarului(linie_a, coloana_a, linie_p, coloana_p, linie_f, coloana_f);
        }
        else if (cauta_pereche_pe_diagonala_principala(adversar.jucator) != 0)
        {
            //a gasit pereche pe diagonala principala la adversar

            caz = cauta_pereche_pe_diagonala_principala(adversar.jucator);

            if (caz == 1)
            {
                linie_a = coloana_a = 0;
                linie_p = coloana_p = 1;
                linie_f = coloana_f = 2;

                strategie_de_blocare_a_adversarului(linie_a, coloana_a, linie_p, coloana_p, linie_f, coloana_f);
            }
            else if (caz == 2)
            {
                linie_a = coloana_a = 1;
                linie_p = coloana_p = 2;
                linie_f = coloana_f = 0;

                strategie_de_blocare_a_adversarului(linie_a, coloana_a, linie_p, coloana_p, linie_f, coloana_f);
            }
            else if (caz == 3)
            {
                linie_a = coloana_a = 0;
                linie_p = coloana_p = 2;
                linie_f = coloana_f = 1;

                strategie_de_blocare_a_adversarului(linie_a, coloana_a, linie_p, coloana_p, linie_f, coloana_f);
            }
        }
        else if (cauta_pereche_pe_diagonala_secundara(adversar.jucator) != 0)
        {
            //a gasit pereche pe diagonala secundara la adversar

            caz = cauta_pereche_pe_diagonala_secundara(adversar.jucator);

            if (caz == 1)
            {
                linie_a = 0;
                coloana_a = 2;

                linie_p = 1;
                coloana_p = 1;

                linie_f = 2;
                coloana_f = 0;

                strategie_de_blocare_a_adversarului(linie_a, coloana_a, linie_p, coloana_p, linie_f, coloana_f);
            }
            else if (caz == 2)
            {
                linie_a = 1;
                coloana_a = 1;

                linie_p = 2;
                coloana_p = 0;

                linie_f = 0;
                coloana_f = 2;

                strategie_de_blocare_a_adversarului(linie_a, coloana_a, linie_p, coloana_p, linie_f, coloana_f);
            }
            else if (caz == 3)
            {
                linie_a = 0;
                coloana_a = 2;

                linie_p = 2;
                coloana_p = 0;

                linie_f = 1;
                coloana_f = 1;

                strategie_de_blocare_a_adversarului(linie_a, coloana_a, linie_p, coloana_p, linie_f, coloana_f);
            }
        }
    }
}

void Joc::afisare_tabla()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << tabla[i][j].piese[tabla[i][j].totalPiese].jucator << " ";
            cout << tabla[i][j].piese[tabla[i][j].totalPiese].marime << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void Joc::afisare_coordonate()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << i << " " << j << "  ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "ATENTIE !!!" << endl;
    cout << "Numarul liniei si numarul cloanei corespunzatoare pozitiei alese vor fi introduse cu spatiu intre. Exemplu : 0 0. Contraexemplu : 00";
    cout << endl;
}

int Joc::verif_castigator(int a, int b, int c)
{
    if (a == b && b == c) return a;
    else return 0;
}

int Joc::castigator()
{
    int i, castig = 0, castig1 = 0;

    for (i = 0; i < 3; i++)
    {
        ///linie
        castig1 = verif_castigator(tabla[i][0].piese[tabla[i][0].totalPiese].jucator, tabla[i][1].piese[tabla[i][1].totalPiese].jucator,
            tabla[i][2].piese[tabla[i][2].totalPiese].jucator);
        if (castig != castig1) castig += castig1;

        ///coloana
        castig1 = verif_castigator(tabla[0][i].piese[tabla[0][i].totalPiese].jucator, tabla[1][i].piese[tabla[1][i].totalPiese].jucator,
            tabla[2][i].piese[tabla[2][i].totalPiese].jucator);
        if (castig != castig1) castig += castig1;
    }

    ///diagonala principala
    castig1 = verif_castigator(tabla[0][0].piese[tabla[0][0].totalPiese].jucator, tabla[1][1].piese[tabla[1][1].totalPiese].jucator,
        tabla[2][2].piese[tabla[2][2].totalPiese].jucator);
    if (castig != castig1) castig += castig1;

    ///diagonala secundara
    castig1 = verif_castigator(tabla[0][2].piese[tabla[0][2].totalPiese].jucator, tabla[1][1].piese[tabla[1][1].totalPiese].jucator,
        tabla[2][0].piese[tabla[2][0].totalPiese].jucator);
    if (castig != castig1) castig += castig1;

    return castig;
}

void Joc::afisare_castigator(int a, int varianta_joc)
{
    if (a == 3) cout << "Egalitate!"; //jucator1.jucator + jucator2.jucator -> 1 + 2 -> 3
    else if (varianta_joc == 2)
    {
        cout << "Jucatorul " << a << " a castigat! Felicitari!";
    }
    else
    {
        if (a == 1) cout << "Ati castigat! Felicitari!";
        else cout << "Calculatorul a castigat. Mai incercati o data.";
    }
}

void Joc::player_vs_player()
{
    int ok, multumit, c;

    int nr_jucatori = 2;

    jucator_curent.jucator = 1;
    piesa_curenta.jucator = 1;

    cout << "COORDONATE :" << endl;
    afisare_coordonate();
    cout << endl;

    int tura = 1;
    do
    {
        cout << "TURA NUMARUL " << tura << endl;
        cout << endl;
        ok = 1; //daca ok se face 0 inseamna ca exista o eroare

        cout << "Este randul jucatorului " << jucator_curent.jucator << endl;

        if (tura < 3 || verif_daca_jucatorul_are_piese_neacoperite() == 0)
        {
            tip_mutare = 1;
        }
        else
        {
            cout << "Daca doriti sa adaugati piesa tastati 1, daca doriti sa mutati piesa pe tabla tastati 2 : ";
            cin >> tip_mutare;
            cout << endl;
            if (tip_mutare != 1 && tip_mutare != 2)
            {
                ok = 0;
                do
                {
                    cout << "Tipul de mutare nu este corect. Introduceti din nou." << endl;
                    cout << endl;
                    cout << "Daca doriti sa adaugati piesa apasati tasta 1, daca doriti sa mutati piesa pe tabla apasati tasta 2 : ";
                    cin >> tip_mutare;
                    cout << endl;
                    if (tip_mutare == 1 || tip_mutare == 2) ok = 1;
                } while (!ok);
            }
        }
        if (tip_mutare == 1)
        {
            tip_mutare_1();
        }
        else if (tip_mutare == 2)
        {
            tip_mutare_2();
        }

        afisare_tabla();

        cout << endl;
        cout << "Sunteti multumit de mutarea facuta? Daca sunteti multumit apasati tasta 1, daca doriti sa refaceti mutarea apasati tasta 0 : ";
        cin >> multumit;
        cout << endl;
        cout << endl;

        if (multumit)
        {
            schimb_de_jucatori();
            tura++;
            c = castigator();

            if (c != 0)
            {
                afisare_castigator(c, nr_jucatori);
                cout << endl;
                break;
            }
        }
        else if (!multumit)
        {
            undo();
        }

        cout << endl;
    } while (castigator() == 0);
}

void Joc::player_vs_computer()
{
    int c, j, s, linie, coloana, linie_a, coloana_a, multumit, nr_jucatori;

    nr_jucatori = 1;
    s = 0;

    jucator_curent.jucator = 1; //player -> jucatorul 1
    piesa_curenta.jucator = 1; //computer -> jucatorul 2

    cout << "COORDONATE :" << endl;
    afisare_coordonate();
    cout << endl;

    int tura = 1;

    //player ul pune primul -> cand e tura impara e randul lui
    //computer ul este al doilea -> cand e tura para pune computer ul

    do
    {
        cout << "TURA NUMARUL " << tura << endl;
        cout << endl;
        int ok = 1; //daca ok se face 0 inseamna ca exista o eroare

        if (tura % 2 == 1)
        {
            cout << "Este randul tau." << endl;
        }
        else
        {
            cout << "Este randul calculatorului." << endl;
            cout << endl;
        }

        if (tura % 2 == 1) //PLAYER
        {
            if (tura < 3 || verif_daca_jucatorul_are_piese_neacoperite() == 0)
            {
                tip_mutare = 1;
            }
            else
            {
                cout << "Daca doriti sa adaugati piesa tastati 1, daca doriti sa mutati piesa pe tabla tastati 2 : ";
                cin >> tip_mutare;
                cout << endl;
                if (tip_mutare != 1 && tip_mutare != 2)
                {
                    ok = 0;
                    do
                    {
                        cout << "Tipul de mutare nu este corect. Introduceti din nou." << endl;
                        cout << endl;
                        cout << "Daca doriti sa adaugati piesa tastati 1, daca doriti sa mutati piesa pe tabla tastati 2 : ";
                        cin >> tip_mutare;
                        cout << endl;
                        if (tip_mutare == 1 || tip_mutare == 2) ok = 1;
                    } while (!ok);
                }
            }

            if (tip_mutare == 1)
            {
                tip_mutare_1();
            }
            else if (tip_mutare == 2)
            {
                tip_mutare_2();
            }

            afisare_tabla();

            cout << endl;
            cout << "Sunteti multumit de mutarea facuta? Daca sunteti multumit apasati tasta 1, daca doriti sa refaceti mutarea apasati 0 : ";
            cin >> multumit;
            cout << endl;
            cout << endl;

        } //END PLAYER
        else //COMPUTER
        {
            if (jucator_curent.jucator == 1) adversar.jucator = 2;
            else adversar.jucator = 1;

            linie_a = ultima_mutare.linie_finala; //linia pe care se afla ultima piesa pusa de adversar pe tabla
            coloana_a = ultima_mutare.coloana_finala; //coloana pe care se afla ultima piesa pusa de adversar pe tabla

            linie = ultima_mutare_c.linie_finala;
            coloana = ultima_mutare_c.coloana_finala;

            if (((linie == -1 && coloana == -1) || verif_existenta_pereche_pe_tabla(linie, coloana, jucator_curent.jucator) == 0) &&
                verif_existenta_pereche_pe_tabla(linie_a, coloana_a, adversar.jucator) == 0) //daca nu exista perechi de doua piese
            {
                if ((tabla[linie_a][coloana_a].piese[tabla[linie_a][coloana_a].totalPiese].marime == 2 && jucator2.pieseMari != 0) ||
                    (tabla[linie_a][coloana_a].piese[tabla[linie_a][coloana_a].totalPiese].marime == 1 && jucator2.pieseMedii != 0)) //acopera piesa adversarului
                {
                    ultima_mutare_c.linie_finala = linie_a;
                    ultima_mutare_c.coloana_finala = coloana_a;

                    acopera_piesa_adversarului(linie_a, coloana_a);
                }
                else if (tabla[linie_a][coloana_a].piese[tabla[linie_a][coloana_a].totalPiese].marime == 3
                    || jucator2.pieseMari == 0 && tabla[linie_a][coloana_a].piese[tabla[linie_a][coloana_a].totalPiese].marime == 2) //imita mutarea adversarului cu o linie mai sus sau mai jos
                {
                    imita_mutarea_adversarului(linie_a, coloana_a);
                }
            }
            else
            {
                cauta_perechi_de_piese(linie, coloana, linie_a, coloana_a);
            }

        } //END COMPUTER

        afisare_tabla();

        if (multumit)
        {
            schimb_de_jucatori();
            tura++;
            c = castigator();

            if (c != 0)
            {
                afisare_castigator(c, nr_jucatori);
                cout << endl;

                break;
            }

        }
        else if (!multumit)
        {
            undo();
        }
        cout << endl;

    } while (castigator() == 0);
}

