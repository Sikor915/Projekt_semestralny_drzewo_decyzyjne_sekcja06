// TODO List
//  1. Czytanie parametr�w drzewa decyzyjnego i przechowanie ich. Mo�na w sumie u�y� struktury do tego by p�niej by�o �atwiej z if-ami mo�e
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

    // To wy�ej to test jak dzia�a wywo�ywanie funkcji z Developer PowerShell

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
                //if (ss.fail()) // Pomijane s� rzeczy kt�re nie s� zmiennymi typu double
                //{
                //    ss.clear();
                //    std::string kosz;
                //    ss >> kosz;
                //    continue;
                //}

                //To wy�ej jest tak w sumie nie potrzebne ale zostawiam na wszelki wypadek, mo�e to jeszcze wykorzystam
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

