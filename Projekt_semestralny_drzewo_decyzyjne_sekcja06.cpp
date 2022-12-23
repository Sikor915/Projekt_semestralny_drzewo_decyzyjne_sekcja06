// TODO List
//  1. Czytanie parametrów drzewa decyzyjnego i przechowanie ich. Mo¿na w sumie u¿yæ struktury do tego by pó¿niej by³o ³atwiej z if-ami mo¿e
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
#include <ctime>
#include <sstream>
#include <fstream>
#include <vector>

int main()
{
    /*srand(time(NULL));
    std::ofstream plik ("plik.txt");
    if (plik.is_open())
    {
        int rozmiar = rand() % 10;
        for (int i = 0; i < rozmiar; i++)
        {
            plik << rand() % 100 - 50 << std::endl;
        }
        plik.close();
    }

    std::ifstream plik_z_liczbami("plik.txt");
    int liczba;

    while (plik_z_liczbami >> liczba)
    {
        std::cout << liczba << std::endl;
    }*/

    // To wy¿ej to test jak dzia³a wywo³ywanie funkcji z Developer PowerShell

    std::ifstream plikWejsciowy("plikWejsciowy.txt");

    std::vector<std::vector<double>> wartosci;

    if (plikWejsciowy.is_open())
    {
        std::string linia;
        while (plikWejsciowy >> linia) 
        {
            std::stringstream ss(linia);
            std::vector<double> wiersz;
            double wartosc;
            while (ss >> wartosc) 
            {
                //if (ss.fail()) // Pomijane s¹ rzeczy które nie s¹ zmiennymi typu double
                //{
                //    ss.clear();
                //    std::string kosz;
                //    ss >> kosz;
                //    continue;
                //}

                //To wy¿ej jest tak w sumie nie potrzebne ale zostawiam na wszelki wypadek, mo¿e to jeszcze wykorzystam
                wiersz.push_back(wartosc);
            }
            wartosci.push_back(wiersz);
        }
        plikWejsciowy.close();
    }
    for (const auto& wiersz : wartosci) 
    {
        static int licznik{ 0 };
        for (const auto& wartosc : wiersz) 
        {
            std::cout.width(5);
            std::cout << wartosc << " ";
            licznik++;
            if (licznik % 2 == 0)
            {
                std::cout << std::endl;
            }
        }
        
    }

}

