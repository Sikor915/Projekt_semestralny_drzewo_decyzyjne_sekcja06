// TODO List
//  1. Czytanie parametrów drzewa decyzyjnego i przechowanie ich. Mo¿na w sumie u¿yæ struktury do tego by pó¿niej by³o ³atwiej z if-ami mo¿e --- DONE
// 
//  2. Porównywanie wartoœci do drzewa decyzyjnego
// 
//  3. Opracowaæ jak wywo³aæ ten program z konsoli i wraz z podaniem parametrów (plików tekstowych) - ja u¿ywa³em cl /EHsc Projekt_semestralny_drzewo_decyzyjne.cpp i potem .\Projekt_semestralny(...)
// 
//  4. Opracowaæ ¿eby program podawa³ instrukcje co jak zrobiæ gdy u¿ytkownik nie poda plików wejœciowych a tak¿e mo¿e niech poda lokalizacjê gdzie zapisa³ plik tekstowy z wynikiem
//
//  5. Opisaæ wszystko z pomoc¹ Doxygena - ogarn¹æ w ogóle jak siê to coœ robi
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
        std::string atrybut; // Wartoœæ do testu np. wzrost albo wysokoœæ skoku
        std::string znakTestu; // Znak wykonywanego testu ( '<', '>', '='). Do wykorzystania z jakimœ switch-case
        double wymaganie{}; // Test
        int indeks{}; // Indeks nastêpnego punktu drzewa decyzyjnego
        std::string klasyfikacja; // Klasyfikacja je¿eli test siê powiedzie (ex.: je¿eli wzrost < 190 cm to klasyfikacj¹ bêdzie "Koszykówka"
        std::string klasyfikacjaOstateczna; // Klasyfikacja przy koñcu drzewa
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


    //Tu jest tylko wypisanie wektora wartoœci

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

