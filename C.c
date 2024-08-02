#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int graczP = 0;
int przeciwnikP = 0;

int graczSkonczyl = 0;
int przeciwnikSkonczyl = 0;

int losujKarte() {
    int karta = rand() % 13 + 1;
    if (karta >= 2 && karta <= 10) {
        return karta;
    } else if (karta == 1) {
        return 11;
    } else if (karta == 11) {
        return 2;
    } else if (karta == 12) {
        return 3;
    } else if (karta == 13) {
        return 4;
    }
    return 0;
}

void dajKarteGraczu() {
    int karta = losujKarte();
    graczP += karta;
    printf("Otrzymales karte o wartosci: %d (Suma punktow: %d)\n", karta, graczP);
}

void dajKartePrzeciwnikowi() {
    int karta = losujKarte();
    przeciwnikP += karta;
    printf("Przeciwnik otrzymal karte o wartosci: %d (Suma punktow: %d)\n", karta, przeciwnikP);
}

int main() {
    srand((unsigned)time(NULL));
    printf("Witamy w oczku!\n");

    dajKarteGraczu();
    dajKartePrzeciwnikowi();

    char wybor;
    while (!graczSkonczyl) {
        printf("Czy chcesz dobrac karte? (t/n): ");
        scanf(" %c", &wybor);
        if (wybor == 't') {
            dajKarteGraczu();
            if (graczP > 21) {
                printf("Masz wiecej niz 21 punktow. Przegrales!\n");
                return 0;
            }
        } else {
            graczSkonczyl = 1;
        }
    }

    while (!przeciwnikSkonczyl) {
        if (przeciwnikP < 17) {
            dajKartePrzeciwnikowi();
            if (przeciwnikP > 21) {
                printf("Przeciwnik ma wiecej niz 21 punktow. Wygrales!\n");
                return 0;
            }
        } else {
            przeciwnikSkonczyl = 1;
        }
    }

    printf("Masz %d punktow, przeciwnik ma %d punktow.\n", graczP, przeciwnikP);

    if (graczP > przeciwnikP) {
        printf("Wygrales!\n");
    } else if (graczP < przeciwnikP) {
        printf("Przegrales!\n");
    } else {
        printf("Remis!\n");
    }

    return 0;
}
