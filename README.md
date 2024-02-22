# Descriere generala
---
Gobblet Gobblers redefineste clasicul X și 0, aducând o dimensiune nouă jocului. Cu pioni mici, medii și mari, poți domina adversarul prin acoperirea pieselor acestuia. Piesele pot fi mutate strategic pe tablă, oferind un nivel suplimentar de complexitate. 

# Reguli joc
---
+ In total, un jucator are 6 piese. Acestea sunt de 3 tipuri : mari, medii, mici.
+ Cand ii vine randul, fiecare jucator are doua posibilitati: poate alege o piesa din fata sa pe care sa o puna pe tabla de joc sau poate muta o piesa de-a sa de pe tabla de joc. Piesa de pe tabla de joc poate fi mutata intr-un spatiu liber, dar si peste un alt gobblet mai mic, al sau sau al adversarului.
+ La fel ca la X si 0, un jucator castiga atunci cand are pe linie, coloana sau oricare dintre diagonale 3 piese una dupa alta.

# Functionalitati proiect
---
+ Proiectul ofera doua variante de joc : player vs player, players vs computer.
+ Computerul cuprinde implementarea urmatoarelor miscari :
  - imita miscarea playerului
  - acopera piesele playerului
  - recunoaste perechile de cate doua piese de pe tabla de joc, atat ale adversarului, cat si perechile proprii
+ Pentru varianta de joc player vs computer, am implementat o inteligenta artificiala cu o strategie bine elaborata. Computerul nu doar isi prioritizeaza propria victorie, ci si isi ajusteaza strategia pentru a impiedica adversarul să castige.
