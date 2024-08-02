using System;

class Program
{
    static int graczP = 0;
    static int przeciwnikP = 0;

    static bool graczSkonczyl = false;
    static bool przeciwnikSkonczyl = false;

    static int LosujKarte()
    {
        Random random = new Random();
        int karta = random.Next(1, 14);
        switch (karta)
        {
            case 1:
                return 11;
                break;

            case 11:
                return 2;
                break;

            case 12:
                return 3;
                break;

            case 13:
                return 4;
                break;

            default:
                return karta;
                break;
        }
    }

    static void dajKarteGraczu()
    {
        int karta = LosujKarte();
        graczP += karta;
        Console.WriteLine("Otzrymałeś kartę o wartości " + karta.ToString() + " (Suma punktów: " + graczP.ToString() + ")");
    }

    static void dajKartePrzeciwnikowi()
    {
        int karta = LosujKarte();
        przeciwnikP += karta;
        Console.WriteLine("Przeciwnik otrzymał kartę o wartości " + karta.ToString() + " (Suma punktów: " + przeciwnikP.ToString() + ")");
    }

    static void Main()
    {
        Random random = new Random();
        Console.WriteLine("Witamy w oczku!");
        dajKarteGraczu();
        dajKartePrzeciwnikowi();

        char wybor;
        while (!graczSkonczyl)
        {
            Console.WriteLine("Czy chcesz dobrać kartę? (t/n)");
            wybor = Console.ReadKey().KeyChar;
            if (wybor == 't')
            {
                dajKarteGraczu();
                if (graczP > 21)
                {
                    Console.WriteLine("Masz więcej niż 21 punktów. Przegrałeś!");
                    break;
                }
            }
            else
            {
                graczSkonczyl = true;
            }
        }

        while (!przeciwnikSkonczyl)
        {
            if (przeciwnikP < 17)
            {
                dajKartePrzeciwnikowi();
                if (przeciwnikP > 21)
                {
                    Console.WriteLine("Przeciwnik ma więcej niż 21 punktów. Wygrałeś!");
                }
            }
            else
            {
                przeciwnikSkonczyl = true;
            }
        }

        Console.WriteLine("Masz " + graczP.ToString() + " punktów, przeciwnik ma " + przeciwnikP.ToString() + " punktów.");
        if (graczP > przeciwnikP)
        {
            Console.WriteLine("Wygrałeś!");
        }
        else if (graczP < przeciwnikP)
        {
            Console.WriteLine("Przegrałeś!");
        }
        else
        {
            Console.WriteLine("Remis!");
        }
    }
}
