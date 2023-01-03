// TODO List
//  1. Czytanie parametr�w drzewa decyzyjnego i przechowanie ich. Mo�na w sumie u�y� struktury do tego by p�niej by�o �atwiej z if-ami mo�e --- DONE
// 
//  2. Por�wnywanie warto�ci do drzewa decyzyjnego - tu by w sumie przyda�o si� to parami sprawdza� (tzn. wyskok[0] i wzrost[0]) --- DONE (g�wnianie ale jest)
// 
//  3. Opracowa� jak wywo�a� ten program z konsoli i wraz z podaniem parametr�w (plik�w tekstowych) - ja u�ywa�em cl /EHsc Projekt_semestralny_drzewo_decyzyjne.cpp i potem .\Projekt_semestralny(...) --- Half-Done
// 
//  4. Opracowa� �eby program podawa� instrukcje co jak zrobi� gdy u�ytkownik nie poda plik�w wej�ciowych a tak�e mo�e niech poda lokalizacj� gdzie zapisa� plik tekstowy z wynikiem --- DONE
//
//  5. Opisa� wszystko z pomoc� Doxygena - ogarn�� w og�le jak si� to co� robi
// 
//  6. Have fun

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

int main()
{
    std::string nazwaPlikuWejsciowego, nazwaPlikuDrzewa;

    struct PunktDrzewaDecyzyjnego
    {
        std::string atrybut; // Jaki atrybut testowa� np. wzrost albo wysoko�� skoku
        std::string znakTestu; // Znak wykonywanego testu ( '<', '>'). Do wykorzystania z jakim� switch-case
        double wymaganie{}; // Warto�� do kt�rej b�dziemy przyr�wnywa�
        int indeks{}; // Indeks nast�pnego punktu drzewa decyzyjnego
        std::string klasyfikacja; // Klasyfikacja je�eli test si� powiedzie (ex.: je�eli wzrost < 190 cm to klasyfikacj� b�dzie "Koszyk�wka")
        std::string klasyfikacjaOstateczna; // Klasyfikacja przy ko�cu drzewa
    };
    //      <jakie s� indeksy, jaka zmienna jest przechowywana>
    std::map<int, PunktDrzewaDecyzyjnego> DrzewoDecyzyjne;

    std::cout << "Program obsluguje i bada przynaleznosc zawodnikow o specyficznych parametrach do poszczegolnych dyscyplin (koszykowka i lekkoatletyka)." << std::endl;
    std::cout << "Prosze podanie nazwy pliku z danymi razem z rozszerzeniem .txt a potem nazwy pliku drzewa decyzyjnego takze z rozszerzeniem .txt" << std::endl;
    std::cout << "Prosze sie upewnic ze pliki sa odpowiednio przygotowane tzn. plik z danymi posiada dwie kolumny wzrost i wysokosc (w tej kolejnosci) a drzewo jest opisane w ten sposob" << std::endl;
    std::cout << "<indeks wej�cia> <atrybut> <operator> <warto��> <indeks wyj�cia NIE> <indeks wyj�cia TAK>; gdzie operator to znak mniejszy lub wiekszy\n" << std::endl;
    std::cin >> nazwaPlikuWejsciowego >> nazwaPlikuDrzewa;
    std::cout << std::endl;

    if (nazwaPlikuWejsciowego == "" or nazwaPlikuDrzewa == "")
    {
        std::cout << "Wyglada na to ze nie podales nazwy pliku/plikow. Aby program dzialal musi on dostac nazwy dwoch istniejacych i odpowiednio przygotowanych plikow";
    }
    else
    {


        std::ifstream plikWejsciowy(nazwaPlikuWejsciowego);

        std::vector<double> wzrost;
        std::vector<double> wyskok;
        std::vector<double> koszykowka, lekkoatletyka;

        if (plikWejsciowy.is_open())
        {
            std::string linia;
            while (std::getline(plikWejsciowy, linia)) {
                std::stringstream ss(linia);
                double wartosc1, wartosc2;
                ss >> wartosc1 >> wartosc2;
                if (!ss.fail())
                {
                    wzrost.push_back(wartosc1);
                    wyskok.push_back(wartosc2);
                }
            }

            plikWejsciowy.close();
        }
        else
        {
            std::cout << "Podany plik nie istnieje!!!" << std::endl;
            return 1;
        }

        std::ifstream wejscie(nazwaPlikuDrzewa);

        PunktDrzewaDecyzyjnego Punkt;
        int indeks{}, indeksMaksymalny{}, indeksTestowanych{};

        if (wejscie.is_open())
        {
            std::string linia;

            while (std::getline(wejscie, linia))
            {
                std::stringstream ss(linia);
                ss >> indeksMaksymalny;
            }

            wejscie.close();
        }
        else
        {
            std::cout << "Podany plik nie istnieje!!!" << std::endl;
            return 1;
        }
        // tu zczytuje indeks maksymalny drzewa decyzyjnego

        std::ifstream wejscie2(nazwaPlikuDrzewa);

        if (wejscie2.is_open())
        {
            std::string linia;

            while (std::getline(wejscie2, linia))
            {
                // Dop�ki mo�na wczyta� co� z pliku Drzewa do s�owa
                static std::string kosz{};
                static std::string znakTestu{};
                std::stringstream ss(linia);
                ss >> indeks;
                if (indeks != indeksMaksymalny)
                {
                    std::getline(ss, kosz, ' ');
                    std::string RzeczDoTestu;
                    std::getline(ss, RzeczDoTestu, ' ');
                    std::getline(ss, znakTestu, ' ');
                    double Test;
                    ss >> Test;
                    std::getline(ss, kosz, ' ');
                    int kolejnyIndeks;
                    ss >> kolejnyIndeks;
                    std::getline(ss, kosz, ' ');
                    std::string Klasyfikacja;
                    std::getline(ss, Klasyfikacja, ' ');

                    // Dodanie nowego punktu drzewa i zapisanie tego do mapy z indeksem = "indeks"
                    PunktDrzewaDecyzyjnego Punkt{ RzeczDoTestu, znakTestu, Test ,kolejnyIndeks, Klasyfikacja };
                    DrzewoDecyzyjne[indeks] = Punkt;
                }
                else
                {
                    // Tutaj jest zczytywanie dla ostatniego indeksu drzewa
                    std::getline(ss, kosz, ' ');
                    std::string RzeczDoTestu;
                    std::getline(ss, RzeczDoTestu, ' ');
                    std::getline(ss, znakTestu, ' ');
                    double Test;
                    ss >> Test;
                    std::getline(ss, kosz, ' ');
                    std::string KlasyfikacjaNie;
                    std::string Klasyfikacja;
                    std::getline(ss, KlasyfikacjaNie, ' ');
                    std::getline(ss, Klasyfikacja, ' ');
                    PunktDrzewaDecyzyjnego Punkt{ RzeczDoTestu, znakTestu, Test , 0, Klasyfikacja, KlasyfikacjaNie };
                    DrzewoDecyzyjne[indeks] = Punkt;
                }

            }
            wejscie2.close();
            indeks = 0;
        }
        else
        {
            std::cout << "Podany plik nie istnieje!!!" << std::endl;
            return 1;
        }
        // Tu zczytuje samo drzewo decyzyjne

        // ---------------------------------------------------

        for (double wartosc : wzrost)
        {
            while (indeks <= indeksMaksymalny)
            {
                if (DrzewoDecyzyjne[indeks].atrybut == "wzrost")
                {

                    if (DrzewoDecyzyjne[indeks].znakTestu == "<")
                    {
                        if (wzrost[indeksTestowanych] < DrzewoDecyzyjne[indeks].wymaganie)
                        {
                            if (DrzewoDecyzyjne[indeks].klasyfikacja == "koszykowka")
                            {
                                koszykowka.push_back(wzrost.at(indeksTestowanych));
                                koszykowka.push_back(wyskok.at(indeksTestowanych));
                                indeksTestowanych++;
                                indeks = 2;
                            }
                            else
                            {
                                lekkoatletyka.push_back(wzrost.at(indeksTestowanych));
                                lekkoatletyka.push_back(wyskok.at(indeksTestowanych));
                                indeksTestowanych++;
                                indeks = 2;
                            }
                        }
                        else
                        {
                            if (indeks == indeksMaksymalny)
                            {
                                if (DrzewoDecyzyjne[indeks].klasyfikacjaOstateczna == "lekkoatletyka")
                                {
                                    lekkoatletyka.push_back(wzrost.at(indeksTestowanych));
                                    lekkoatletyka.push_back(wyskok.at(indeksTestowanych));
                                    indeksTestowanych++;
                                    indeks++;
                                }
                                else
                                {
                                    koszykowka.push_back(wzrost.at(indeksTestowanych));
                                    koszykowka.push_back(wyskok.at(indeksTestowanych));
                                    indeksTestowanych++;
                                    indeks++;
                                }

                            }
                            else
                            {
                                indeks++;
                            }
                        }
                    }
                    else
                    {
                        if (wzrost[indeksTestowanych] > DrzewoDecyzyjne[indeks].wymaganie)
                        {
                            if (DrzewoDecyzyjne[indeks].klasyfikacja == "koszykowka")
                            {
                                koszykowka.push_back(wzrost.at(indeksTestowanych));
                                koszykowka.push_back(wyskok.at(indeksTestowanych));
                                indeksTestowanych++;
                                indeks = 2;
                            }
                            else
                            {
                                lekkoatletyka.push_back(wzrost.at(indeksTestowanych));
                                lekkoatletyka.push_back(wyskok.at(indeksTestowanych));
                                indeksTestowanych++;
                                indeks = 2;
                            }
                        }
                        else
                        {
                            if (indeks == indeksMaksymalny)
                            {
                                if (DrzewoDecyzyjne[indeks].klasyfikacjaOstateczna == "lekkoatletyka")
                                {
                                    lekkoatletyka.push_back(wzrost.at(indeksTestowanych));
                                    lekkoatletyka.push_back(wyskok.at(indeksTestowanych));
                                    indeksTestowanych++;
                                    indeks++;
                                }
                                else
                                {
                                    koszykowka.push_back(wzrost.at(indeksTestowanych));
                                    koszykowka.push_back(wyskok.at(indeksTestowanych));
                                    indeksTestowanych++;
                                    indeks++;
                                }
                            }
                            else
                            {
                                indeks++;
                            }
                        }
                    }

                }
                else
                {
                    if (DrzewoDecyzyjne[indeks].znakTestu == "<")
                    {
                        if (wyskok[indeksTestowanych] < DrzewoDecyzyjne[indeks].wymaganie)
                        {
                            if (DrzewoDecyzyjne[indeks].klasyfikacja == "koszykowka")
                            {
                                koszykowka.push_back(wzrost.at(indeksTestowanych));
                                koszykowka.push_back(wyskok.at(indeksTestowanych));
                                indeksTestowanych++;
                                indeks = 2;
                            }
                            else
                            {
                                lekkoatletyka.push_back(wzrost.at(indeksTestowanych));
                                lekkoatletyka.push_back(wyskok.at(indeksTestowanych));
                                indeksTestowanych++;
                                indeks = 2;
                            }
                        }
                        else
                        {
                            if (indeks == indeksMaksymalny)
                            {
                                if (DrzewoDecyzyjne[indeks].klasyfikacjaOstateczna == "lekkoatletyka")
                                {
                                    lekkoatletyka.push_back(wzrost.at(indeksTestowanych));
                                    lekkoatletyka.push_back(wyskok.at(indeksTestowanych));
                                    indeksTestowanych++;
                                    indeks++;
                                }
                                else
                                {
                                    koszykowka.push_back(wzrost.at(indeksTestowanych));
                                    koszykowka.push_back(wyskok.at(indeksTestowanych));
                                    indeksTestowanych++;
                                    indeks++;
                                }
                            }
                            else
                            {
                                indeks++;
                            }
                        }
                    }
                    else
                    {
                        if (wyskok[indeksTestowanych] > DrzewoDecyzyjne[indeks].wymaganie)
                        {
                            if (DrzewoDecyzyjne[indeks].klasyfikacja == "koszykowka")
                            {
                                koszykowka.push_back(wzrost.at(indeksTestowanych));
                                koszykowka.push_back(wyskok.at(indeksTestowanych));
                                indeksTestowanych++;
                                indeks = 2;
                            }
                            else
                            {
                                lekkoatletyka.push_back(wzrost.at(indeksTestowanych));
                                lekkoatletyka.push_back(wyskok.at(indeksTestowanych));
                                indeksTestowanych++;
                                indeks = 2;
                            }
                        }
                        else
                        {
                            if (indeks == indeksMaksymalny)
                            {
                                if (DrzewoDecyzyjne[indeks].klasyfikacjaOstateczna == "lekkoatletyka")
                                {
                                    lekkoatletyka.push_back(wzrost.at(indeksTestowanych));
                                    lekkoatletyka.push_back(wyskok.at(indeksTestowanych));
                                    indeksTestowanych++;
                                    indeks++;
                                }
                                else
                                {
                                    koszykowka.push_back(wzrost.at(indeksTestowanych));
                                    koszykowka.push_back(wyskok.at(indeksTestowanych));
                                    indeksTestowanych++;
                                    indeks++;
                                }
                            }
                            else
                            {
                                indeks++;
                            }
                        }
                    }
                }
            }
            indeks = 0;
        }

        for (const auto& p : koszykowka)
        {
            static int licznik{};
            std::cout << p << " ";
            licznik++;
            if (licznik % 2 == 0)
            {
                std::cout << std::endl;
            }
        }


        std::ofstream plikWyjsciowy;
        plikWyjsciowy.open("plikWyjsciowy.txt");

        if (plikWyjsciowy.is_open())
        {
            plikWyjsciowy << "Koszykowka" << std::endl;
            int licznik{};

            for (double& liczba : koszykowka)
            {
                plikWyjsciowy << liczba << " ";
                licznik++;
                if (licznik % 2 == 0)
                {
                    plikWyjsciowy << std::endl;
                }
            }

            plikWyjsciowy << std::endl;
            plikWyjsciowy << "Lekkoatletyka" << std::endl;

            for (double& liczba : lekkoatletyka)
            {
                plikWyjsciowy << liczba << " ";
                licznik++;
                if (licznik % 2 == 0)
                {
                    plikWyjsciowy << std::endl;
                }
            }
            plikWyjsciowy.close();
            std::cout << "\nWszystkie dane zostaly zapisane w pliku tekstowym o nazwie 'plikWyjsciowy.txt' w folderze z calym kodem." << std::endl;
        }
        
    }
}

