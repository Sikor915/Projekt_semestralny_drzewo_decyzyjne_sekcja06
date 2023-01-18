#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include "Funkcje.h"

void pobierzDane(std::string nazwaPliku, std::map<int, std::vector<std::pair<std::string, double>>>& Atrybuty, std::vector<std::string>& nazwyAtrybutow)
{
    std::ifstream plikWejsciowy(nazwaPliku);

    if (plikWejsciowy.is_open())
    {
        int licznik{};
        std::string linia, slowo;
        std::getline(plikWejsciowy, linia);
        std::stringstream ss;
        ss << linia;
        while (ss >> slowo)
        {
            if (slowo == "%")
            {
                break;
            }
            else
            {
                nazwyAtrybutow.push_back(slowo);
            }
        }
        while (std::getline(plikWejsciowy,linia))
        {
            std::pair<std::string, double> paraAtrybutow{};
            std::vector<std::pair<std::string, double>> wektorAtrybotow{};
            std::stringstream ss2(linia);
            double wartosc{};
            for (int i = 0; i < nazwyAtrybutow.size(); i++)
            {
                ss2 >> wartosc;
                paraAtrybutow.first = nazwyAtrybutow[i];
                paraAtrybutow.second = wartosc;
                wektorAtrybotow.push_back(paraAtrybutow);
            }
            Atrybuty[licznik] = wektorAtrybotow;
            licznik++;
        }
        plikWejsciowy.close();
    }
    else
    {
        std::cout << "Podany plik nie istnieje!!!" << std::endl;
        return;
    }
}

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

void pobierzDrzewo(std::string nazwaPliku, std::map<int, PunktDrzewaDecyzyjnego>& drzewo, int& indeksMaksymalny)
{
    int indeks{};
    std::ifstream wejscie(nazwaPliku);

    if (wejscie.is_open())
    {
        std::string linia;

        while (std::getline(wejscie, linia))
        {
            // Dopóki mo¿na wczytaæ coœ z pliku Drzewa do s³owa
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

void funkcja(std::map<int, PunktDrzewaDecyzyjnego>& drzewo, std::map<int, std::vector<std::pair<std::string, double>>> & Atrybuty, int& indeksMax)
{
    int indeksTestowanych{}, indeks{};
    for (auto& x : Atrybuty)
    {
        while (indeks <= indeksMax)
        {
            if (drzewo[indeks].znakTestu == "<")
            {
                
            }
            else
            {

            }
        }
    }
}



void zapiszDoPliku(std::vector<double>& koszykowka, std::vector<double>& lekkoatletyka, std::string nazwaPlikuWyjsciowego)
{
    std::ofstream plikWyjsciowy;
    plikWyjsciowy.open(nazwaPlikuWyjsciowego);

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
        std::cout << "\nWszystkie dane zostaly zapisane w pliku tekstowym o nazwie " << nazwaPlikuWyjsciowego <<   " w folderze z calym kodem." << std::endl;
        std::cout << "Jezeli w pliku nic sie nie wypisalo to oznacza ze plik wejsciowy/drzewa o takiej nazwie nie zostal odnaleziony" << std::endl;
        std::cout << "Pamietaj o tym by wpisac nazwe pliku w taki sposob: 'plikWejsciowy.txt'. Dopisz rozszerzenie" << std::endl;
    }
}