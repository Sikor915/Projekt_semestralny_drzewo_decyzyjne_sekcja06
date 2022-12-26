// TODO List
//  1. Czytanie parametr�w drzewa decyzyjnego i przechowanie ich. Mo�na w sumie u�y� struktury do tego by p�niej by�o �atwiej z if-ami mo�e --- DONE
// 
//  2. Por�wnywanie warto�ci do drzewa decyzyjnego
// 
//  3. Opracowa� jak wywo�a� ten program z konsoli i wraz z podaniem parametr�w (plik�w tekstowych) - ja u�ywa�em cl /EHsc Projekt_semestralny_drzewo_decyzyjne.cpp i potem .\Projekt_semestralny(...)
// 
//  4. Opracowa� �eby program podawa� instrukcje co jak zrobi� gdy u�ytkownik nie poda plik�w wej�ciowych a tak�e mo�e niech poda lokalizacj� gdzie zapisa� plik tekstowy z wynikiem
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
#include <cctype>

int main()
{

    struct PunktDrzewaDecyzyjnego
    {
        std::string atrybut; // Warto�� do testu np. wzrost albo wysoko�� skoku
        std::string znakTestu; // Znak wykonywanego testu ( '<', '>', '='). Do wykorzystania z jakim� switch-case
        double wymaganie{}; // Test
        int indeks{}; // Indeks nast�pnego punktu drzewa decyzyjnego
        std::string klasyfikacja; // Klasyfikacja je�eli test si� powiedzie (ex.: je�eli wzrost < 190 cm to klasyfikacj� b�dzie "Koszyk�wka"
        std::string klasyfikacjaOstateczna; // Klasyfikacja przy ko�cu drzewa
    };
    std::map<int, PunktDrzewaDecyzyjnego> DrzewoDecyzyjne;

    std::ifstream plikWejsciowy("plikWejsciowy.txt");

    std::vector<double> wzrost;
    std::vector<double> wyskok;

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

    std::ifstream wejscie("DrzewoDecyzyjne.txt");

    PunktDrzewaDecyzyjnego Punkt;
    int indeks{}, indeksMaksymalny{};

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

    std::ifstream wejscie2("DrzewoDecyzyjne.txt");

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
                PunktDrzewaDecyzyjnego Punkt{ RzeczDoTestu, znakTestu, Test , 0, KlasyfikacjaNie, Klasyfikacja };
                DrzewoDecyzyjne[indeks] = Punkt;
            }

        }
        wejscie2.close();
    }


    //Tu jest tylko wypisanie wektora warto�ci

    for (const auto& wiersz : wzrost) 
    {
        static int licznik{ 0 };
        std::cout << wiersz << " ";
        
    }
    std::cout << std::endl;
    for (const auto& wiersz : wyskok)
    {
        std::cout << wiersz << " ";
    }





}

