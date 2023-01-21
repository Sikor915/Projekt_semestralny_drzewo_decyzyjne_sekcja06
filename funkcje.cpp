#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include "Funkcje.h"

void pobierzDane(std::string nazwaPliku, std::map<int, std::vector<std::pair<std::string, double>>>& atrybuty, std::vector<std::string>& nazwyAtrybutow)
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
            std::string nazwa1{};
            std::stringstream ss2(linia);
            double wartosc{};
            std::vector<std::pair<std::string, double>> tempVector;
            std::pair<std::string, double> tempPair;
            for (int i = 0; i < nazwyAtrybutow.size(); i++)
            {
                ss2 >> wartosc;
                nazwa1 = nazwyAtrybutow[i];
                tempPair.first = nazwa1;
                tempPair.second = wartosc;
                tempVector.push_back(tempPair);
            }
            atrybuty[licznik] = tempVector;
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

void pobierzDrzewo(std::string nazwaPliku, std::map<int, PunktDrzewaDecyzyjnego>& drzewo, int& indeksMaksymalny, std::set<std::string> & nazwyPrzydzielenia)
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
                std::string RzeczDoTestu;
                double Test;
                int kolejnyIndeks;
                std::string Klasyfikacja;
                std::getline(ss, kosz, ' ');
                std::getline(ss, RzeczDoTestu, ' ');
                std::getline(ss, znakTestu, ' ');
                ss >> Test;
                std::getline(ss, kosz, ' ');
                ss >> kolejnyIndeks;
                std::getline(ss, kosz, ' ');
                std::getline(ss, Klasyfikacja, ' ');
                nazwyPrzydzielenia.insert(Klasyfikacja);

                // Dodanie nowego punktu drzewa i zapisanie tego do mapy z indeksem = "indeks"
                PunktDrzewaDecyzyjnego Punkt{ RzeczDoTestu, znakTestu, Test ,kolejnyIndeks, Klasyfikacja };
                drzewo[indeks] = Punkt;
            }
            else
            {
                // Tutaj jest zczytywanie dla ostatniego indeksu drzewa
                std::string RzeczDoTestu;
                double Test;
                std::string KlasyfikacjaNie;
                std::string Klasyfikacja;
                std::getline(ss, kosz, ' ');
                std::getline(ss, RzeczDoTestu, ' ');
                std::getline(ss, znakTestu, ' ');
                ss >> Test;
                std::getline(ss, kosz, ' ');
                std::getline(ss, KlasyfikacjaNie, ' ');
                std::getline(ss, Klasyfikacja, ' ');
                nazwyPrzydzielenia.insert(KlasyfikacjaNie);
                nazwyPrzydzielenia.insert(Klasyfikacja);

                PunktDrzewaDecyzyjnego Punkt{ RzeczDoTestu, znakTestu, Test , indeksMaksymalny+1, Klasyfikacja, KlasyfikacjaNie };
                drzewo[indeks] = Punkt;
            }

        }
        wejscie.close();
    }
    else
    {
        std::cout << "Podany plik nie istnieje!!!" << std::endl;
        return;
    }
}

void porownanie(std::map<int, PunktDrzewaDecyzyjnego>& drzewo, std::map<int, std::vector<std::pair<std::string, double>>>& atrybuty, int& indeksMax, std::map<std::string, std::vector<double>>& przydzieleni)
{
    int indeksTestowanych{}, indeks{}, indeksTestowanych1{};
    std::vector <double> tempVector{};
    std::vector <double> tempVector2{};
    while(indeksTestowanych < atrybuty.size())
    {
        while (indeks <= indeksMax)
        {
            if (indeksTestowanych == atrybuty.size())
            {
                indeksTestowanych++;
                break;
            }
            if (drzewo[indeks].znakTestu == "<")
            {
                if (atrybuty[indeksTestowanych][indeksTestowanych1].first == drzewo[indeks].atrybut)
                {
                    if (atrybuty[indeksTestowanych][indeksTestowanych1].second < drzewo[indeks].wymaganie)
                    {
                        for (int i = 0; i < atrybuty[indeksTestowanych].size(); i++)
                        {
                            przydzieleni[drzewo[indeks].klasyfikacja].push_back(atrybuty[indeksTestowanych][i].second);
                        }
                        indeksTestowanych1 = 0;
                        indeksTestowanych++;
                        indeks = 0;
                    }
                    else
                    {
                        if (indeks == indeksMax)
                        {
                            for (int i = 0; i < atrybuty[indeksTestowanych].size(); i++)
                            {
                                przydzieleni[drzewo[indeks].klasyfikacjaOstateczna].push_back(atrybuty[indeksTestowanych][i].second);
                            }
                            indeksTestowanych++;
                        }
                        indeks = drzewo[indeks].indeks;
                        indeksTestowanych1 = 0;
                    }
                }
                else
                {
                    indeksTestowanych1++;
                }
            }
            else
            {
                if (atrybuty[indeksTestowanych][indeksTestowanych1].first == drzewo[indeks].atrybut)
                {
                    if (atrybuty[indeksTestowanych][indeksTestowanych1].second > drzewo[indeks].wymaganie)
                    {
                        for (int i = 0; i < atrybuty[indeksTestowanych].size(); i++)
                        {
                            przydzieleni[drzewo[indeks].klasyfikacja].push_back(atrybuty[indeksTestowanych][i].second);
                        }
                        indeksTestowanych1 = 0;
                        indeksTestowanych++;
                        indeks = 0;
                    }
                    else
                    {
                        if (indeks == indeksMax)
                        {
                            for (int i = 0; i < atrybuty[indeksTestowanych].size(); i++)
                            {
                                przydzieleni[drzewo[indeks].klasyfikacjaOstateczna].push_back(atrybuty[indeksTestowanych][i].second);
                            }
                            indeksTestowanych++;
                        }
                        indeks = drzewo[indeks].indeks;
                        indeksTestowanych1 = 0;
                    }
                }
                else
                {
                    indeksTestowanych1++;
                }
            }
        }
        indeks = 0;
    }
}

void zapiszDoPliku(std::string nazwaPlikuWyjsciowego, std::map<std::string, std::vector<double>> przydzieleni, std::set<std::string> nazwyPrzydzielenia, std::vector<std::string> nazwyAtrybutow)
{
    std::ofstream plikWyjsciowy;
    plikWyjsciowy.open(nazwaPlikuWyjsciowego);
    int licznik{};

    if (plikWyjsciowy.is_open())
    {
        for (const auto& przydzial : nazwyPrzydzielenia)
        {
            plikWyjsciowy << przydzial << std::endl;

            for (double j = 0; j < przydzieleni[przydzial].size(); j++)
            {
                plikWyjsciowy << std::setw(5);
                plikWyjsciowy << przydzieleni[przydzial][j] << " ";
                licznik++;

                if (licznik == nazwyAtrybutow.size())
                {
                    plikWyjsciowy << std::endl;
                    licznik = 0;
                }
            }
        }
        plikWyjsciowy.close();
        std::cout << "\nWszystkie dane zostaly zapisane w pliku tekstowym o nazwie " << nazwaPlikuWyjsciowego <<   " w folderze z calym kodem." << std::endl;
        std::cout << "Jezeli w pliku nic sie nie wypisalo to oznacza ze plik wejsciowy/drzewa o takiej nazwie nie zostal odnaleziony" << std::endl;
        std::cout << "Pamietaj o tym by wpisac nazwe pliku w taki sposob: 'plikWejsciowy.txt'. Dopisz rozszerzenie" << std::endl;
    }
}