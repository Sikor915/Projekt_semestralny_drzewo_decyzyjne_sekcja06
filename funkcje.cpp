#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include "Funkcje.h"

//void pobierzDane(std::string nazwaPliku, std::map<int, std::map<std::string, double>>& Atrybuty, std::vector<std::string>& nazwyAtrybutow)
//{
//    std::ifstream plikWejsciowy(nazwaPliku);
//
//    if (plikWejsciowy.is_open())
//    {
//        int licznik{};
//        std::string linia, slowo;
//        std::getline(plikWejsciowy, linia);
//        std::stringstream ss;
//        ss << linia;
//        while (ss >> slowo)
//        {
//            if (slowo == "%")
//            {
//                break;
//            }
//            else
//            {
//                nazwyAtrybutow.push_back(slowo);
//            }
//        }
//        while (std::getline(plikWejsciowy,linia))
//        {
//            std::string nazwa{};
//            std::stringstream ss2(linia);
//            double wartosc{};
//            for (int i = 0; i < nazwyAtrybutow.size(); i++)
//            {
//                ss2 >> wartosc;
//                nazwa = nazwyAtrybutow[i];
//                Atrybuty[licznik][nazwa] = wartosc;
//            }
//            licznik++;
//        }
//        plikWejsciowy.close();
//    }
//    else
//    {
//        std::cout << "Podany plik nie istnieje!!!" << std::endl;
//        return;
//    }
//}

void pobierzIndeks(std::string nazwaPliku, int& indeksMaksymalny)
{
    std::ifstream wejscie(nazwaPliku);

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
        return;
    }
}

void pobierzDrzewo(std::string nazwaPliku, std::map<int, PunktDrzewaDecyzyjnego>& drzewo, int& indeksMaksymalny, std::set<std::string>& nazwyPrzydzielenia)
{
    int indeks{};
    std::ifstream wejscie(nazwaPliku);

    if (wejscie.is_open())
    {
        std::string linia;

        while (std::getline(wejscie, linia))
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
                nazwyPrzydzielenia.insert(Klasyfikacja);

                // Dodanie nowego punktu drzewa i zapisanie tego do mapy z indeksem = "indeks"
                PunktDrzewaDecyzyjnego Punkt{ RzeczDoTestu, znakTestu, Test ,kolejnyIndeks, Klasyfikacja };
                drzewo[indeks] = Punkt;
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
                nazwyPrzydzielenia.insert(Klasyfikacja, KlasyfikacjaNie);

                PunktDrzewaDecyzyjnego Punkt{ RzeczDoTestu, znakTestu, Test , 0, Klasyfikacja, KlasyfikacjaNie };
                drzewo[indeks] = Punkt;
            }

        }
        wejscie.close();
        indeks = 0;
    }
    else
    {
        std::cout << "Podany plik nie istnieje!!!" << std::endl;
        return;
    }
}

//void funkcja(std::map<int, PunktDrzewaDecyzyjnego> drzewo, std::map<int, std::map<std::string, double>> Atrybuty, int& indeksMax)
//{
//    int indeksTestowanych{}, indeks{}, indeksTestowanych1{};
//    for (auto& x : Atrybuty)
//    {
//        while (indeks <= indeksMax)
//        {
//            if (drzewo[indeks].znakTestu == "<")
//            {
//                if (Atrybuty[indeksTestowanych][indeksTestowanych1].first == drzewo[indeks].atrybut)
//                {
//                    if (Atrybuty[indeksTestowanych][indeksTestowanych1].second < drzewo[indeks].wymaganie)
//                    {
//                        //Zapis do odpowiedniego wektora przechowujacego przydzialy
//                        indeksTestowanych1 = 0;
//                        indeksTestowanych++;
//                        indeks = 0;
//                    }
//                    else
//                    {
//                        indeks++;
//                        indeksTestowanych1 = 0;
//                    }
//                }
//                else
//                {
//                    indeksTestowanych1++;
//                }
//            }
//            else
//            {
//                if (Atrybuty[indeksTestowanych][indeksTestowanych1].first == drzewo[indeks].atrybut)
//                {
//                    if (Atrybuty[indeksTestowanych][indeksTestowanych1].second > drzewo[indeks].wymaganie)
//                    {
//                        //Zapis do odpowiedniego wektora przechowujacego przydzialy
//                        indeksTestowanych1 = 0;
//                        indeksTestowanych++;
//                        indeks = 0;
//                    }
//                    else
//                    {
//                        indeks++;
//                        indeksTestowanych1 = 0;
//                    }
//                }
//                else
//                {
//                    indeksTestowanych1++;
//                }
//            }
//        }
//    }
//}

//void zapiszDoPliku(std::string nazwaPlikuWyjsciowego)
//{
//    std::ofstream plikWyjsciowy;
//    plikWyjsciowy.open(nazwaPlikuWyjsciowego);
//
//    if (plikWyjsciowy.is_open())
//    {
//        plikWyjsciowy << "Koszykowka" << std::endl;
//        int licznik{};
//
//        for (double& liczba : koszykowka)
//        {
//            plikWyjsciowy << liczba << " ";
//            licznik++;
//            if (licznik % 2 == 0)
//            {
//                plikWyjsciowy << std::endl;
//            }
//        }
//
//        plikWyjsciowy << std::endl;
//        plikWyjsciowy << "Lekkoatletyka" << std::endl;
//
//        for (double& liczba : lekkoatletyka)
//        {
//            plikWyjsciowy << liczba << " ";
//            licznik++;
//            if (licznik % 2 == 0)
//            {
//                plikWyjsciowy << std::endl;
//            }
//        }
//        plikWyjsciowy.close();
//        std::cout << "\nWszystkie dane zostaly zapisane w pliku tekstowym o nazwie " << nazwaPlikuWyjsciowego <<   " w folderze z calym kodem." << std::endl;
//        std::cout << "Jezeli w pliku nic sie nie wypisalo to oznacza ze plik wejsciowy/drzewa o takiej nazwie nie zostal odnaleziony" << std::endl;
//        std::cout << "Pamietaj o tym by wpisac nazwe pliku w taki sposob: 'plikWejsciowy.txt'. Dopisz rozszerzenie" << std::endl;
//    }
//}