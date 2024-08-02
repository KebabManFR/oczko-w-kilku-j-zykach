import random
import sys

graczP = 0
przeciwnikP = 0

graczSkonczyl = False
przeciwnikSkonczyl = False

def LosujKarte():
    karta = random.randint(1, 13)
    if karta >= 2 and karta <= 10:
        return karta
    elif karta == 1:
        return 11
    elif karta == 11:
        return 2
    elif karta == 12:
        return 3
    elif karta == 13:
        return 4
    else:
        return 0

def dajKarteGraczu():
    global graczP
    karta = LosujKarte()
    graczP += karta
    print("Otrzymałeś kartę o wartości: " + str(karta) + " (Suma punktów: " + str(graczP) + ")")
    return

def dajKartePrzeciwnikowi():
    global przeciwnikP
    karta = LosujKarte()
    przeciwnikP += karta
    print("Przeciwnik otrzymał kartę o wartości: " + str(karta) + " (Suma punktów: " + str(przeciwnikP) + ")")
    return

print("Witamy w oczku!")
dajKarteGraczu()
dajKartePrzeciwnikowi()

while not graczSkonczyl:
    wybor = input("Czy chcesz dobrać kartę? (t/n): ")
    if wybor == 't':
        dajKarteGraczu()
        if graczP > 21:
            print("Masz więcej niż 21 punktów. Przegrałeś!")
            sys.exit()
    else:
        graczSkonczyl = True

while not przeciwnikSkonczyl:
    if przeciwnikP < 17:
        dajKartePrzeciwnikowi()
        if przeciwnikP > 21:
            print("Przeciwnik ma więcej niż 21 punktów. Wygrałeś!")
            sys.exit()
    else:
        przeciwnikSkonczyl = True

print("Masz " + str(graczP) + " punktów, przeciwnik ma " + str(przeciwnikP) + " punktów.")
if graczP > przeciwnikP:
    print("Wygrałeś!")
elif graczP < przeciwnikP:
    print("Przegrałeś!")
else:
    print("Remis!")