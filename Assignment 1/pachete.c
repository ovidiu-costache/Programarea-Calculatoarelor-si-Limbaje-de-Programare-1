#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARTIERE 33
#define MAX_PACHETE 51

typedef struct {
    int id;
    char *nume;
} Cartier;

typedef struct {
    int id;
    int adresa[18];
    int idCartier;
    int strada;
    int numar;
    int prioritate;
    int codMesaj;
    float greutate;
    char *mesaj;
} Pachet;

typedef struct {
    int id;
    int nrPachete;
    int pachete[51];
} Postas;

void citireDate(Cartier cartier[], int *nrC, Pachet pachet[], int *nrP) {
    int i, j;
    char sir[100];

    scanf("%d", nrC);
    // Sar peste caracterul newline ramas
    getchar();

    for (i = 0; i < *nrC; i++) {
        cartier[i].id = i;
        fgets(sir, sizeof(sir), stdin);
        // Sterg caracterul newline adaugat in urma citirii cu fgets
        sir[strlen(sir) - 1] = '\0';
        cartier[i].nume = (char *) malloc (strlen(sir) + 1);
        strcpy(cartier[i].nume, sir);
    }

    scanf("%d", nrP);
    //Sar peste caracterul newline ramas
    getchar();

    for (i = 0; i < *nrP; i++) {
        pachet[i].id = i;
        for (j = 0; j < 18; j++) 
            scanf("%d", &pachet[i].adresa[j]);

        scanf("%d %f", &pachet[i].prioritate, &pachet[i].greutate);
        // Consum newline-ul ramas in buffer
        getchar();

        fgets(sir, sizeof(sir), stdin);
        // Sterg caracterul newline adaugat in urma citirii cu fgets
        sir[strlen(sir) - 1] = '\0';
        pachet[i].mesaj = (char *) malloc (strlen(sir) + 1);
        strcpy(pachet[i].mesaj, sir);
    }
}

void cerinta_1(Cartier cartier[], int nrC, Pachet pachet[], int nrP) {
    int i, j;

    for (i = 0; i < nrC; i++) 
        printf("%d %s\n", cartier[i].id, cartier[i].nume);

    for (i = 0; i < nrP; i++) {
        printf("%d\n", pachet[i].id);

        for (j = 0; j < 18; j++) {
            printf("%d", pachet[i].adresa[j]);
            if (j != 17) 
                printf(" ");
        }
        printf("\n");

        printf("%d %.3f\n", pachet[i].prioritate, pachet[i].greutate);
        printf("%s\n", pachet[i].mesaj);
    }
}

int transformare(int v[], int n) {
    int i, rez = 0, p = 1;

    for (i = n - 1; i >= 0; i--) {
        rez += v[i] * p;
        // Calculez puterile lui 2
        p *= 2;
    }

    return rez;
}

void extragere(Pachet pachet[], int nrP) {
    int i, j, k, cartier[5], strada[5], numar[8];
    // Functia extrage cartierul, strada si numarul din vectorul "adresa"
    for (i = 0; i < nrP; i++) {
        for (j = 0; j < 5; j++)
            cartier[j] = pachet[i].adresa[j];

        k = -1;
        for (j = 5; j < 10; j++)
            strada[++k] = pachet[i].adresa[j];

        k = -1;
        for (j = 10; j < 18; j++)
            numar[++k] = pachet[i].adresa[j];
        // Transform datele din binar
        pachet[i].idCartier = transformare(cartier, 5);
        pachet[i].strada = transformare(strada, 5);
        pachet[i].numar = transformare(numar, 8);
    }
}

void cerinta_2(Pachet pachet[], int nrP) {
    int i;
    extragere (pachet, nrP);

    for (i = 0; i < nrP; i++) {
        printf("%d\n", i);
        printf("%d ", pachet[i].idCartier);
        printf("%d ", pachet[i].strada);
        printf("%d\n", pachet[i].numar);
    }
}

void distribuirePachete(Postas postas[], int nrC, Pachet pachet[], int nrP) {
    int i, idCartier, nrPacheteCurente;
    extragere(pachet, nrP);

    // Initializez fiecare postas cu ID-ul sau si setez nr. de pachete la 0
    for (i = 0; i < nrC; i++) {
        postas[i].id = i;
        postas[i].nrPachete = 0;
    }

    for (i = 0; i < nrP; i++) {
        idCartier = pachet[i].idCartier;
        nrPacheteCurente = postas[idCartier].nrPachete;
        // Adaug pachetul curent in lista de pachete a postasului corespunzator
        postas[idCartier].pachete[nrPacheteCurente] = pachet[i].id;
        // Incrementez nr. de pachete pt. acest postas
        postas[idCartier].nrPachete++;
    }
}

void afisarePostasi(Postas postas[], int nrC, Pachet pachet[], int nrP) {
    int i, j;

    for (i = 0; i < nrC; i++) {
        printf("%d %d", postas[i].id, postas[i].nrPachete);

        // Daca postasul are pachete, trecem pe linia urmatoare pt. a le afisa
        if(postas[i].nrPachete != 0)
            printf("\n");

        for (j = 0; j < postas[i].nrPachete; j++) {
            // Afisez ID-ul fiecarui pachet din lista postasului
            printf("%d", postas[i].pachete[j]);
            if (j != postas[i].nrPachete - 1)
                printf(" ");
        }

        // Daca nu este ultimul postas, adaug o linie noua pt. separare
        if (i != nrC - 1)
            printf("\n");
    }
    printf("\n");
}

void cerinta_3(Postas postas[], int nrC, Pachet pachet[], int nrP) {
    extragere(pachet, nrP);
    distribuirePachete(postas, nrC, pachet, nrP);
    afisarePostasi(postas, nrC, pachet, nrP);
}

void sorteazaPachete(Postas postas[], int nrC, Pachet pachet[], int nrP) {
    int i, j, k;
    
    // Am fost nevoit sa impart conditiile pe mai multe randuri pt.
    // A nu depasi limita de 80 de caract.
    for (i = 0; i < nrC; i++) {
        for (j = 0; j < postas[i].nrPachete - 1; j++)
            for (k = 0; k < postas[i].nrPachete - 1; k++) {
                // Compar gradul de prioritate a doua pachete consecutive
                if (pachet[postas[i].pachete[k]].prioritate < 
                pachet[postas[i].pachete[k + 1]].prioritate) {
                    // Schimb locul pachetelor daca prioritatea este mai mica
                    int aux = postas[i].pachete[k];
                    postas[i].pachete[k] = postas[i].pachete[k + 1];
                    postas[i].pachete[k + 1] = aux;
                }
                else {
                    // Daca prioritatile sunt egale, compar greutatea
                    if (pachet[postas[i].pachete[k]].prioritate == 
                    pachet[postas[i].pachete[k + 1]].prioritate && 
                    pachet[postas[i].pachete[k]].greutate < 
                    pachet[postas[i].pachete[k + 1]].greutate) {
                            int aux = postas[i].pachete[k];
                            postas[i].pachete[k] = postas[i].pachete[k + 1];
                            postas[i].pachete[k + 1] = aux;
                        }
                }
            }
    }
    // In timpul sortarii, pachetele sunt redistribuite corect postasilor
}

void cerinta_4(Postas postas[], int nrC, Pachet pachet[], int nrP) {
    extragere(pachet, nrP);
    distribuirePachete(postas, nrC, pachet, nrP);
    sorteazaPachete(postas, nrC, pachet, nrP);
    afisarePostasi(postas, nrC, pachet, nrP);
}

void inversareMesaj(Pachet pachet[], int nrP) {
    // Voi folosi o matrice pt. a stoca cuvintele din mesaj
    char cuvinte[256][256];
    int i, j, k;

    for (i = 0; i < nrP; i++) {
        char *p, cp[256], aux[256] = "";
        k = -1;
        // In "p" voi avea toate cuvintele din mesajul initial
        p = strtok(pachet[i].mesaj, " .,!?:");
        while (p != NULL) {
            // Copiez cuvantul curent, pt. ca orice modificare a lui "p"
            // Poate afecta sirul initial, deoarece este pointer catre acesta
            strcpy(cp, p);
            // Stochez cuvantul in matricea de cuvinte
            strcpy(cuvinte[++k], cp);
            p = strtok(NULL, " .,!?:");
        }

        for (j = k; j >= 0; j--) {
            // Adaug fiecare cuvant in sens invers in "aux"
            strcat(aux, cuvinte[j]);
        }

        // Inlocuiesc mesajul initial cu cel inversat
        strcpy(pachet[i].mesaj, aux);
    }
}

void calculareCod(Pachet pachet[], int nrP) {
    int i, j;
    // "cod" este dclarat ca long long pt. ca se poate ajunge la nr. mari
    long long cod;

    extragere(pachet, nrP);
    inversareMesaj(pachet, nrP);

    for (i = 0; i < nrP; i++) {
        cod = 0;
        for (j = 0; j < strlen(pachet[i].mesaj); j++) {
            // Obtin valoarea ASCII a caracterului curent
            int litera = pachet[i].mesaj[j];
            cod = cod + litera * j;
        }
        pachet[i].codMesaj = cod % (pachet[i].numar * pachet[i].strada + 1);
    }
}

void afisarePostasiCod(Postas postas[], int nrC, Pachet pachet[], int nrP) {
    int i, j;

    for (i = 0; i < nrC; i++) {
        printf("%d %d", postas[i].id, postas[i].nrPachete);
        if (postas[i].nrPachete != 0)
            printf("\n");
        for (j = 0; j < postas[i].nrPachete; j++) {
            printf("%d ", postas[i].pachete[j]);
            // Afisez codul mesajului asociat acestui pachet
            printf("%d", pachet[postas[i].pachete[j]].codMesaj);
            if (j < postas[i].nrPachete - 1)
                printf("\n");
        }
        printf("\n");
    }
}

void cerinta_5(Postas postas[], int nrC, Pachet pachet[], int nrP) {
    distribuirePachete(postas, nrC, pachet, nrP);
    sorteazaPachete(postas, nrC, pachet, nrP);
    extragere(pachet, nrP);
    inversareMesaj(pachet, nrP);
    calculareCod(pachet, nrP);
    afisarePostasiCod(postas, nrC, pachet, nrP);
}

int contineCifra(int idPostas, int cod) {
    int i, k, frecventa[11], cifre[11];
    k = -1;

    // Initializez vectorul de frecventa cu zero
    for (i = 0; i <= 9; i++)
        frecventa[i] = 0;

    // Calculez frecventa cifrelor din "idPostas"
    while (idPostas != 0) {
        frecventa[idPostas % 10]++;
        idPostas /= 10;
    }

    // Stochez cifrele care apar in idPostas intr-un vector "cifre"
    for (i = 0; i <= 9; i++) 
        if (frecventa[i] >= 1)
            cifre[++k] = i;

    // Verific daca cel putin o cifra din "cod" se afla in vectorul "cifre"
    while (cod != 0) {
        for (i = 0; i <= k; i++)
            if (cifre[i] == cod % 10)
                return 1;
        cod /= 10;
    }

    // Daca nu am gasit nicio cifra comuna, returnez zero
    return 0;
}

void factoriPrimi(int idPostas, int factPrimi[], int *dim) {
    if (idPostas == 0) {
        *dim = 1;
        factPrimi[0] = 0;
    }
    else 
        if (idPostas == 1) {
            *dim = 1;
            factPrimi[0] = 1;
        }
        else {
            int d, p, k;
            d = 2; k = -1;

            // Impart "idPostas" cu factori primi, incepand cu 2
            while (idPostas != 1) {
                // Resetez puterea la care apare factorul prim curent
                p = 0;

                // Verific daca d este divizor al lui idPostas
                while (idPostas % d == 0) {
                    idPostas /= d;
                    p++;
                }

                // Daca am gasit un factor prim, il adaug in vector
                if (p > 0)
                    factPrimi[++k] = d;
                d++; // Incrementez "d" pt. a verifica urmatorul divizor
            }

            // Setez dimensiunea vectorului de factori primi
            *dim = k + 1;
        }
}

void afisareCodAlterat(Postas postas[], int nrC, Pachet pachet[], int nrP) {
    int i, j, idPostas, cod, factori[100], dim, k;

    for (i = 0; i < nrC; i++) {
        printf("%d %d", postas[i].id, postas[i].nrPachete);
        if (postas[i].nrPachete != 0)
            printf("\n");
        for (j = 0; j < postas[i].nrPachete; j++) {
            printf("%d ", postas[i].pachete[j]);
            idPostas = postas[i].id;
            cod = pachet[postas[i].pachete[j]].codMesaj;

            // Verific daca "cod" are cel putin o cifra in comun cu "idPostas"
            if (contineCifra (idPostas, cod) == 1) {
                // Calculez factorii primi pt. "idPostas"
                factoriPrimi (idPostas, factori, &dim);
                int biti = 0;

                // Pt. fiecare fact. prim, setez bitul corespunzator
                for(k = 0; k < dim; k++)
                    biti |= (1 << factori[k]); // Setez bitul corespunzator

                // Alterez codul mesajului folosind XOR cu valoarea "biti"
                cod ^= biti;
            }

            // Actualizez codul mesajului pt. pachetul curent
            pachet[postas[i].pachete[j]].codMesaj = cod;
            printf("%d", pachet[postas[i].pachete[j]].codMesaj);
            if (j < postas[i].nrPachete - 1)
                printf("\n");
        }
        printf("\n");
    }
}

void cerinta_6(Postas postas[], int nrC, Pachet pachet[], int nrP) {
    distribuirePachete(postas, nrC, pachet, nrP);
    sorteazaPachete(postas, nrC, pachet, nrP);
    extragere(pachet, nrP);
    inversareMesaj(pachet, nrP);
    calculareCod(pachet, nrP);
    afisareCodAlterat(postas, nrC, pachet, nrP);
}

void afisareScor(Postas postas[], int nrC, Pachet pachet[], int nrP) {
    int i, j, k, cod, idPostas, factori[100], dim;
    int pacheteDistribuiteCorect;

    for (i = 0; i < nrC; i++) {
        printf("%d ", postas[i].id);
        pacheteDistribuiteCorect = 0;

        for (j = 0; j < postas[i].nrPachete; j++) {
            idPostas = postas[i].id;
            cod = pachet[postas[i].pachete[j]].codMesaj;

            if (contineCifra(idPostas, cod) == 1) {
                factoriPrimi(idPostas, factori, &dim);
                int biti = 0;
                for(k = 0; k < dim; k++)
                    biti |= (1 << factori[k]);
                cod ^= biti;
            }

            // Verific daca codul mesajului alterat este corect
            if (pachet[postas[i].pachete[j]].codMesaj == cod)
                pacheteDistribuiteCorect++;
        }

        // Calculez procentul de pachete distribuite corect
        float procent = pacheteDistribuiteCorect / (float) postas[i].nrPachete;

        // Daca nu exista pachete distribuite corect sau nu exista pachete
        // Setez procentul la zero
        if (pacheteDistribuiteCorect == 0 || postas[i].nrPachete == 0)
            procent = 0;
        printf("%.3lf\n", procent);
    }
}

void cerinta_7(Postas postas[], int nrC, Pachet pachet[], int nrP) {
    distribuirePachete(postas, nrC, pachet, nrP);
    sorteazaPachete(postas, nrC, pachet, nrP);
    extragere(pachet, nrP);
    inversareMesaj(pachet, nrP);
    calculareCod(pachet, nrP);
    afisareScor(postas, nrC, pachet, nrP);
}

int main() {
    int nrCerinta, nrC, nrP;
    // Declar array-ul pt. cartiere, pachete si postasi
    Cartier cartier[MAX_CARTIERE];
    Pachet pachet[MAX_PACHETE];
    Postas postas[MAX_CARTIERE];

    scanf("%d", &nrCerinta);
    citireDate(cartier, &nrC, pachet, &nrP);

    // In functie de cerinta citita, apelez functia corespunzatoare
    switch (nrCerinta) {
        case 1:
            cerinta_1(cartier, nrC, pachet, nrP);
            break;
        case 2:
            cerinta_2(pachet, nrP);
            break;
        case 3:
            cerinta_3(postas, nrC, pachet, nrP);
            break;
        case 4:
            cerinta_4(postas, nrC, pachet, nrP);
            break;
        case 5:
            cerinta_5(postas, nrC, pachet, nrP);
            break;
        case 6:
            cerinta_6(postas, nrC, pachet, nrP);
            break;
        case 7:
            cerinta_7(postas, nrC, pachet, nrP);
            break;
        default:
            break;
    }

    return 0;
}
