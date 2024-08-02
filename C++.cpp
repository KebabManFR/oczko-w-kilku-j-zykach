#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int graczP = 0;
int przeciwnikP = 0;

bool graczSkonczyl = false;
bool przeciwnikSkonczyl = false;

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
    cout << "Otrzymales karte o wartosci: " << karta << " (Suma punktow: " << graczP << ")\n";
}

void dajKartePrzeciwnikowi() {
    int karta = losujKarte();
    przeciwnikP += karta;
    cout << "Przeciwnik otrzymal karte o wartosci: " << karta << " (Suma punktow: " << przeciwnikP << ")\n";
}

int main() {
    srand((unsigned)time(NULL));
    cout << "Witamy w oczku!\n";

    dajKarteGraczu();
    dajKartePrzeciwnikowi();

    char wybor;
    while (!graczSkonczyl) {
        cout << "Czy chcesz dobrać kartę? (t/n): ";
        cin >> wybor;
        if (wybor == 't') {
            dajKarteGraczu();
            if (graczP > 21) {
                cout << "Masz wiecej niz 21 punktow. Przegrales!\n";
                return 0;
            }
        } else {
            graczSkonczyl = true;
        }
    }

    while (!przeciwnikSkonczyl) {
        if (przeciwnikP < 17) {
            dajKartePrzeciwnikowi();
            if (przeciwnikP > 21) {
                cout << "Przeciwnik ma wiecej niz 21 punktow. Wygrales!\n";
                return 0;
            }
        } else {
            przeciwnikSkonczyl = true;
        }
    }

    cout << "Masz " << graczP << " punktow, przeciwnik ma " << przeciwnikP << " punktow.\n";

    if (graczP > przeciwnikP) {
        cout << "Wygrales!\n";
    } else if (graczP < przeciwnikP) {
        cout << "Przegrales!\n";
    } else {
        cout << "Remis!\n";
    }

    return 0;
}
