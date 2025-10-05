# Tema 1

### Data postării: 28.11.

## Deadline: 20.12.2024 ora 23:

## 1 Specificat,ii

Se dores,te implementarea unui sistem care să funct,ioneze conform următoarelor specificat,ii:

- Oras,ul este împărt,it înnrCcartiere.
    - Uncartiereste o structură ce cont,ine:
       ∗ id– un întreg;
       ∗ nume– un s,ir de caractere (char*) ce nu poate cont,ine spat,iu.
- Unpacheteste reprezentat printr-o structură ce cont,ine următoarele câmpuri:
    - id– un întreg;
    - adresă– un vector de 18 elemente (int[18]) cont,inând doar valori 0 sau 1;
    - idCartier– un întreg;
    - strada– un întreg;
    - număr– un întreg;
    - prioritate– o valoare din mult,imea {1, 2, 3, 4, 5}, unde:
       ∗ 5 = prioritate maximă;
       ∗ 1 = prioritate minimă.
    - greutate– un număr real (float);
    - mesaj– un s,ir de caractere (char*) reprezentând un scurt mesaj care însot,es,te
       pachetul:
          ∗ Mesajul poate cont,ine doar litere, cifre, spat,ii s,i semne de punctuat,ie (.,!?:)
             s,i se termină cu un newline (’\n’).
    - codificare mesaj– un întreg calculat după distribuirea pachetului (task I).
- Fiecare pachet are o adresă reprezentată printr-un vector de 18 pozit,ii ce ret,ine doar
    valori 0 sau 1, cu următoarea semnificat,ie:
       - Primele 5 pozit,ii reprezintă id-ul cartierului, următoarele 5 reprezintă strada, iar
          următoarele 8 reprezintă numărul.

```
Observat,ie
```
```
Pentru câmpurile de tip char*(nume_cartierşimesaj)trebuie să alocat,i spat,iu
exact cât este necesar, nu mai mult!
```

- Fiecare pos,tas, va avea un id ce coincide cu id-ul cartierului de care este responsabil, el
    trebuind să distribuie pachetele din acel cartier. Structura prin care e definit pos,tas,ul
    cont,ine următoarele câmpuri:
       - id– un întreg din intervalul [0, 31], unde 32 este numărul maxim de pos,tas,i;
       - nrPachete– un întreg din intervalul [0, 49], unde 50 este numărul maxim de pachete
          distribuite de un pos,tas,;
       - un vector cu pachetele pe care le are de distribuit.
- Există unpos,tas,s,efcare primes,te init,ial toate pachetele s,i are responsabilitatea de a le
    distribui către pos,tas,ii simpli, astfel încât fiecare să primească pachetele corespunzătoare
    cartierului său.
- După primirea pachetelor, pos,tas,ii:
    1. Ordonează pachetelede care sunt responsabili în funct,ie de:
       - Prioritate– pachetele cu prioritate mai mare sunt distribuite primele;
       - Greutate– dacă două pachete au aceeas,i prioritate, pachetul cu greutatea mai
          mare este distribuit primul.
    2. Codifică mesajulprimit împreună cu pachetul după următorul algoritm:
       - Inversează ordinea cuvintelor din propozit,ie, eliminând toate semnele de punctuat,ie.
       - Exemplu: dacă mesajul init,ial este"Ana, are cel mult 3 mere.", după pre-
          lucrare, mesajul devine"mere3multcelareAna".
    3. Calculează un codcare este suma produselor dintre codul ASCII al fiecărui car-
       acter s,i pozit,ia pe care acesta se află în interiorul s,irului, după ce s-au efectuat
       prelucrările anterioare.
          - Numerotarea pozit,iilor caracterelor începe de la 0.
    4. Codul finaleste restul împărt,irii codului anterior la produsul dintre numărul casei
       s,i numărul străzii pachetului respectiv, la care se adună 1.

```
codMOD(casa∗strada+ 1)
```
Pos,tas,ul s,ef va verifica dacă fiecare cod primit este corect, deoarece unii pos,tas,i obis,nuiesc
să modifice mesajele din anumite pachete. Verificarea codurilor o face folosindu-se de acelas,i
algoritm pe care l-au folosit s,i destinatarii pentru a genera codul pentru fiecare pachet.

## 2 Cerint,a I

1. (20 p) Să se implementeze o funct,ie care cites,te de la tastatură următoarele date:
    - nrC– numărul de cartiere s,i de pos,tas,i;
    - Pe următoarelenrClinii se primes,te numele fiecărui cartier;
    - nrP– numărul total de pachete;
    - Pe următoarele4 * nrPlinii se va primi fiecare pachet (câte patru linii / pachet):
       - adresa pachetului (18 valori 0 sau 1);
       - prioritatea;
       - greutatea;


- mesajul – acesta are lungimea de maxim 100 de caractere.

```
Atâtid-urile cartierelor cât s,i cele ale pachetelor se vor completa automat începând de
la valoarea 0. Nu se vor citi de la tastatură!
```
2. (15 p) Să se implementeze o funct,ie care, pentru un pachet dat, să extragă din adresa
    acestuia:
       - cartierul;
       - strada;
       - numărul;

```
completând câmpurile corespunzătoare din structura pachetului.
```
3. (15 p) Să se implementeze o funct,ie care distribuie pachetele pos,tas,ilor.
4. (20 p) Scriet,i o funct,ie care, primind un vector de structuri de tip pachet, să ordoneze
    pachetele din vector:
       - în funct,ie de prioritate (descrescător);
       - dacă mai multe pachete au aceeas,i prioritate, să fie ordonate după greutate (tot
          descrescător);
       - dacă există pachete cu aceeas,i greutate s,i aceeas,i prioritate, acestea să fie lăsate în
          ordinea naturală.
5. (20 p) Scriet,i funct,iile pentru a calcula codificarea mesajului:

```
(a) funct,ie care să inverseze ordinea cuvintelor dintr-un text s,i să elimine semnele de
punctuat,ie;
(b) funct,ie care primes,te ca parametru un pachet s,i calculează codul mesajului conform
algoritmului specificat mai sus.
```
## 3 Cerint,ă II

6. (30 p) Scriet,i o funct,ie care, primindid-ul pos,tas,ului, să altereze doar acele coduri care
    au cel put,in o cifră care se regăses,te înid-ul pos,tas,ului.
       - Exemplu: pentru pos,tas,ul cuid-ul 6, acesta va altera codul 246, dar nu va altera
          codul 281 (fiindcă primul cont,ine cifra 6, iar al doilea, nu).
       - Dacă pos,tas,ul areid-ul 13, atunci el va altera codul 4913, dar nu va altera codul
          408.

```
Se va folosi o funct,ie auxiliară care să altereze (modifice) codul unui mesaj după următorul
algoritm:
```
```
(a) Se calculează factorii primi aiid-ului pos,tas,ului. Aces,ti factori primi vor reprezenta
pozit,iile bit,ilor modificat,i.
```
- Dacăid-ul este 0, atunci vom considera doar valoarea 0 ca "divizor".
- În cazul lui 1, singurul divizor va fi considerat 1.
(b) Fiecare bit aflat pe pozit,iile descrise la pasul anterior va fi “inversat” (1 devine 0, 0
devine 1).


- Bit,ii se vor modifica o singură dată, chiar dacă factorul apare la o putere mai
    mare decât 1.
- Dacă există factori mai mari decât 31, atunci acei factori se vor ignora pe par-
    cursul algoritmului.
(c) Numerotarea bit,ilor începe de la 0 s,i se face de la dreapta la stânga.

```
Funct,ia primes,te ca parametri codul s,iid-ul unui pos,tas,.
```
7. (10 p) Scriet,i o funct,ie pentru atribuirea unui scor fiecărui pos,tas,, scorul fiind egal cu
    numărul de pachete distribuite corect / numărul total de pachete distribuite.
       - Un pachet se consideră distribuit corect dacă este corect codul corespunzător lui.

```
Observat,ie
```
```
Considerăm că dacă un pos,tas,nu are niciun pachet de livrat acesta va avea scorul
0.
```
## 4 Formatul fis,ierelor

### 4.1 Input

Formatul unui fis,ier de intrare este următorul:

1. numărul cerint,ei care urmează să fie rezolvată (1-7)
2. nC= numărul de cartiere / pos,tas,i
3. nClinii cu numele cartierelor (pentru fiecare nume avem un s,ir de caractere fără spat,ii)
4. nP= numărul de pachete
5. cate 4 linii pentru fiecare pachet:

```
(a) pe prima linie: 18 numere întregi, 0 sau 1, pe o singură linie, despărt,ite prin câte un
spat,iu;
(b) pe a doua linie: prioritatea (un număr natural între 1 s,i 5)
(c) pe a treia linie: un număr real ce reprezintă greutatea (float);
(d) pe a patra linie: un s,ir de caractere ce reprezintă mesajul.
```
### 4.2 Output

1. Cerint,a 1
    - se afis,ează pe câte o linie separată toate cartierele în formatid_cartier nume_cartier;
    - se afis,ează toate pachetele, 4 rânduri pentru fiecare pachet:
       (a) idPachet
(b) adresa (spat,iu între caracterele din adresă)
(c) prioritate greutate (cu 3 zecimale)
(d) mesaj


2. Cerint,a 2
    - se afis,ează adresa fiecărui pachet pe 2 linii:
       (a) idPachet
(b) idCartier strada numar
3. Cerint,a 3
    - se afis,ează câte 2 linii pentru fiecare pos,tas,:
       (a) idPostas nrPachete
(b) idPachet1 idPachet2 ... idPachetnr
4. Cerint,a 4
    - afis,area ca la 3, doar că pachetele sunt acum sortate
5. Cerint,a 5
    - se afis,ează, pentru fiecare pos,tas,:
       - idPostas nrPachete
       - nrPachete linii care cont,in:idPachet codMesaj
6. Cerint,a 6
    - afis,are ca la 5
7. Cerint,a 7
    - câte o linie pentru fiecare pos,tas,de tipul:idPostas scor(3 zecimale)

## 5 Exemplu

### 5.1 Input

#### 1

#### 2

Cartier
Cartier
3
0 0 0 0 0 1 1 1 0 0 0 1 1 0 0 0 1 0
5
10.
Cel din urma pachet
0 0 0 0 0 1 0 1 0 1 0 1 0 0 0 0 1 0
5
12.
Al treilea pachet
0 0 0 0 1 1 0 1 0 1 1 1 1 0 0 0 1 0
2
22.
Primul, pachet!


### 5.2 Output

1. Cerint,a 1

```
0 Cartier
1 Cartier
0
0 0 0 0 0 1 1 1 0 0 0 1 1 0 0 0 1 0
5 10.
Cel din urma pachet
1
0 0 0 0 0 1 0 1 0 1 0 1 0 0 0 0 1 0
5 12.
Al treilea pachet
2
0 0 0 0 1 1 0 1 0 1 1 1 1 0 0 0 1 0
2 22.
Primul, pachet!
```
2. Cerint,a 2

#### 0

#### 0 28 98

#### 1

#### 0 21 66

#### 2

#### 1 21 226

```
Explicat,ii:
```
- idCartier(codificat în primii 5 bit,i din adresă).
- strada(codificată în următorii 5 bit,i, adică pozit,iile 5-9).
- număr(codificat în ultimii 8 bit,i, pozit,iile 10-17).

```
(a) pachetul 0: [0 0 0 0 0] [1 1 1 0 0] [0 1 1 0 0 0 1 0]
idCartier = 0; strada = 22 + 23 + 24 = 28; număr = 21 + 25 + 26 = 98
(b) pachetul 1: [0 0 0 0 0] [1 0 1 0 1] [0 1 0 0 0 0 1 0]
idCartier = 0; strada = 20 + 2^2 + 2^4 = 21; număr = 21 + 2^6 = 66
(c) pachetul 2: [0 0 0 0 1] [1 0 1 0 1] [1 1 1 0 0 0 1 0]
idCartier = 20 = 1; strada = 20 + 2^2 + 2^4 = 21; număr = 21 + 2^5 + 2^6 + 2^7 = 226
```
3. Cerint,a 3

#### 0 2

#### 0 1

#### 1 1

#### 2


```
Explicat,ii:
```
- pos,tas,ul 0 trebuie să livreze 2 pachete, pachetele cu id 0 s,i 1;
- pos,tas,ul 1 trebuie să livreze 1 pachet, pachetul cu id 2.
4. Cerint,a 4

#### 0 2

#### 1 0

#### 1 1

#### 2

```
Explicat,ii:
```
- pos,tas,ul 0 trebuie să livreze 2 pachete;
- conform ordonării, va trebui să livreze mai întâi pachetul 1 s,i apoi pachetul 0.
5. Cerint,a 5

#### 0 2

#### 1 841

#### 0 1236

#### 1 1

#### 2 2301

```
Explicat,ii:
```
- pos,tas,ul 0 va livra 2 pachete:
    - pachetul 1, codul mesajului 841
    - pachetul 0, codul mesajului 1236
- pos,tas,ul 1 va livra un pachet:
    - pachetul 2, codul mesajului 2301
6. Cerint,a 6

#### 0 2

#### 1 841

#### 0 1236

#### 1 1

#### 2 2303

```
Explicat,ii:
```
- Init,ial, codul pachetului cu ID 2 era 2301.
- Fiindcă 2301 cont,ine una dintre cifrele care se regăsesc s,i în ID-ul pos,tas,ului (1),
    codul a trebuit să fie alterat/modificat:
       - Factorii primi ai ID-ului pos,tas,ului: 1
       - 2301 în binar: 100011111101


- Penultimul bit al lui 2301 (pozit,ia 1, de la dreapta la stânga) este inversat
- 1000111111[ 0 ]1→1000111111[ 1 ]1 = 2303
- 2301 → 2303
7. Cerint,a 7

#### 0 1.

#### 1 0.

- Pos,tas,ul 0 a reus,it să livreze corect toate pachetele:
    - Pachetul 0→corect
    - Pachetul 1→corect
- Pos,tas,ul 1 nu a reus,it să livreze corect niciun pachet:
    - Pachetul 2→alterat

## 6 Precizări

- Separat,i logica programelor în mai multe funct,ii.
- NUse vor puncta sursele în care tot programul este scris înmain!
- Este interzisă folosireavariabilelor globale! Folosirea acestora va fi depunctată.
- Solut,ia temei va fi scrisă în ANSII C! Nu folosit,i sintaxă sau instruct,iuni specifice limba-
    jului C++.
- Va trebuie săcreat,i un fis,ier READMEîn care să precizat,i numele, grupa, cât timp
    v-a luat implementarea cerint,elor s,i explicat,i, pe scurt în câteva fraze, implementarea
    temei (comentariile din cod vor documenta mai amănunt,it rezolvarea).
- Este recomandat ca liniile de cod s,i cele din fis,ierul README să nu depăs,ească 80 de
    caractere.
- Temele sunt strict individuale. Copierea temelor va fi sanct,ionată cu punctaj 0 pentru
    tot,i cei care au port,iuni de cod identice!
- Persoanele cu port,iuni de cod identiceNUvor primi niciun punctaj pe temă.
- NU copiat,i cod de pe Internet! Se poate ajunge la situat,ia în care doi student,i să
    aibă acelas,i cod, preluat de pe Internet, caz în care ambele teme vor fi punctate in
    TOTALITATE cu 0, des,i student,ii nu au colaborat direct între ei.
- NUfolosit,i tool-uri care generează automat cod pentru rezolvarea temei. Temele vor fi
    comparate cu solut,iile generate de astfel de tool-uri.
- Temele trimise după deadlineNUvor fi luate în considerare.
- Datele de intrare sunt descrise pentru fiecare cerint,ă individual s,i vor fi citite de la tas-
    tatură.


- Toate citirile se fac de la tastatură în codul final al temei! Folosit,i fis,iere sau/s,i redirectarea
    intrării/ies,irii doar pentru testele voastre intermediare!
    Operatorul<poate fi folosit pentru a redirect,iona cont,inutul unui fis,ier către intrarea
    standard a unui program. Spre exemplu, considerăm că avem executabilulpachete(care
    în mod normal cites,te de la tastatură) s,i un fis,ier numit input.txt. Putem utiliza
    următoarea comandă pentru a redirect,iona cont,inutul fis,ieruluiinput.txtcătrea intrarea
    executabiluluipachete:

```
./pachete < input.txt
```
```
De asemenea, putem redirect,iona intrarea unui program s,i să salvăm ies,irea într-un fis,ier
folosind operatorii<s,i>în acelas,i timp:
```
```
./pachete < input.txt > output.txt
```
## 7 Coding Style

Folosit,i un coding style astfel încât codul să fie us,or de citit s,i înt,eles. De exemplu:

- Dat,i nume corespunzătoare variabilelor s,i funct,iilor.
- Nu adăugat,i prea multe linii libere sau alte spat,ii goale unde nu este necesar:
    - nu terminat,i liniile în spat,ii libere, trailing whitespaces;
    - nu adăugat,i prea multe linii libere între instruct,iuni sau la sfârs,itul fis,ierului.
- Principalul scop al spat,iilor este identarea.
- Fit,i consecvent,i în coding style-ul ales.
- Vă recomandăm să parcurget,i această resursă: Coding style
- Există programe sau extensii pentru editoare text care vă pot formata codul. Este permisă
    utilizarea lor.
- Des,i vă pot ajuta destul de mult, ar fi ideal să încercat,i să respectat,i coding style-ul pe
    măsură ce scriet,i codul.

## 8 Trimiterea temei

Vet,i trimite o arhivăZIPcu numeleEXACTacesta:GRUPA_Nume_Prenume_Tema1.zip
De exemplu:311CC_Popescu_Maria_Tema1.zip
Arhiva va cont,ine următoarele fis,iere:

1. README
2. Makefile
3. pachete.c


```
Atent,ie!
```
```
Vet,i fi depunctat,i complet pentru formatarea incorectă a arhivei(alt nume, alt
tip, alte nume pentru fis,iere, alte fis,iere în plus sau în minus etc.) -0 puncte pe temă.
```
- Pentru întrebări legate de temă se va folosi în mod exclusivFORUM-ultemei, pe care
    vă recomandăm să îl vizitat,i chiar s,i dacă nu avet,i întrebări, întrucât este posibil să aflat,i
    informat,ii noi din întrebările puse de colegii vos,tri, respectiv din răspunsurile date de noi.
- Compilarea nu ar trebui să producă warning-uri (verificat,i prin adăugarea flagului -Wall
    la gcc).

```
Atent,ie!
```
- Temele trebuie să fie încărcate pevmchecker. NU se acceptă teme trimise pe
    e-mail sau altfel decât prin intermediulvmchecker-ului.
- Link vmchecker: https://vmchecker.cs.pub.ro/ui/#PC-CC
- De asemenea, este disponibil un slot de încărcare s,i pe Moodle, ca solut,ie de backup.
    Rezultatul final al temei va fi cel de pe vmchecker. Temele care nu sunt
    încărcate pe vmchecker nu vor fi luate în considerare.

## 9 Punctaj

O temă perfectă valorează130 de puncte.
Punctajul pe cerint,e este următorul:

```
Cerint,a Punctaj
Cerint,a 1 90 puncte
Cerint,a 2 40 puncte
```
```
Atent,ie!
```
```
Depunctările care se pot aplica:
```
- -10 punctepentru lipsa explicat,iilor din README
- -10 punctepentru lipsă comentarii din cod (atent,ie! nu trebuie comentată fiecare
    linie, doar ceea ce este esent,ial pentru a putea fi us,or de înt,eles rezolvarea – detalii
    la curs!)
- -20 punctepentru Coding Style necorespunzător
- Depunctare totală pentru formatarea incorectă a arhivei(alt nume, alt tip,
    alte nume pentru fis,iere, alte fis,iere în plus sau în minus) -0 puncte pe temă

```
O temă care NU compilează va fi punctată cu 0.
Vor exista mai multe teste pentru fiecare problemă în parte. Punctele pe teste sunt
independente, punctajul pe un anumit test nefiind condit,ionat de alte teste.
În fis,ierul README va trebui să descriet,i pe scurt solut,ia pe care at,i ales-o pentru fiecare
problemă s,i alte lucruri pe care le considerat,i utile de ment,ionat
```

## 10 Checker

- Arhiva se va trimite pe vmchecker, unde tema se va testa automat.
- Pentru testarea locală, avet,i disponibil un set de teste s,i un checker local.
- Punctajul acordat pe rularea testelor este cel de pe vmchecker.
- Corectorii îs,i rezervă dreptul de a scădea puncte pentru orice problemă găsită
    în implementare, dacă vor considera acest lucru necesar.

```
Atent,ie!
```
```
Numele fis,ierului sursă trebuie să fiepachete.cpentru a putea fi verificat de checker.
De asemenea, executabilul va avea numele pachete. Recomandăm folosirea fis,ierului
Makefile din arhiva de checker.
```
```
Observat,ie
```
```
Pentru a rula checker-ul trebuie să oferit,i permisiuni fis,ieruluicheck.sh (de exemplu,
chmod a+x check.sh). Testarea implementării se va face utilizând./check.sh. De aseme-
nea, tema va fi testată automat s,i la încărcarea pevmchecker, as,a cum este ment,ionat
în sect,iunile următoare.
```

