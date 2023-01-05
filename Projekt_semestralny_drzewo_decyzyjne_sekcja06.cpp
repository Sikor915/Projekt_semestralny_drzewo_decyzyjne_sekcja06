// TODO List
//  1. Czytanie parametr�w drzewa decyzyjnego i przechowanie ich. Mo�na w sumie u�y� struktury do tego by p�niej by�o �atwiej z if-ami mo�e --- DONE
// 
//  2. Por�wnywanie warto�ci do drzewa decyzyjnego - tu by w sumie przyda�o si� to parami sprawdza� (tzn. wyskok[0] i wzrost[0]) --- DONE (g�wnianie ale jest)
// 
//  3. Opracowa� jak wywo�a� ten program z konsoli i wraz z podaniem parametr�w (plik�w tekstowych) - ja u�ywa�em cl /EHsc Projekt_semestralny_drzewo_decyzyjne.cpp i potem .\Projekt_semestralny(...) --- Half-Done
// 
//  4. Opracowa� �eby program podawa� instrukcje co jak zrobi� gdy u�ytkownik nie poda plik�w wej�ciowych a tak�e mo�e niech poda lokalizacj� gdzie zapisa� plik tekstowy z wynikiem --- DONE
//
//  5. Opisa� wszystko z pomoc� Doxygena - ogarn�� w og�le jak si� to co� robi --- DONE
// 
//  6. Have fun

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include "Funkcje.h"

int main()
{
    std::string nazwaPlikuWejsciowego, nazwaPlikuDrzewa;

    std::cout << "Program obsluguje i bada przynaleznosc zawodnikow o specyficznych parametrach do poszczegolnych dyscyplin (koszykowka i lekkoatletyka)." << std::endl;
    std::cout << "Prosze podanie nazwy pliku z danymi razem z rozszerzeniem .txt a potem nazwy pliku drzewa decyzyjnego takze z rozszerzeniem .txt" << std::endl;
    std::cout << "Prosze sie upewnic ze pliki sa odpowiednio przygotowane tzn. plik z danymi posiada dwie kolumny wzrost i wysokosc (w tej kolejnosci) a drzewo jest opisane w ten sposob" << std::endl;
    std::cout << "<indeks wejscia> <atrybut> <operator> <wartosc> <indeks wyjscia NIE> <indeks wyjscia TAK>; gdzie operator to znak mniejszy lub wiekszy\n" << std::endl;
    std::cin >> nazwaPlikuWejsciowego >> nazwaPlikuDrzewa;
    std::cout << std::endl;

    if (nazwaPlikuWejsciowego == "" or nazwaPlikuDrzewa == "")
    {
        std::cout << "Wyglada na to ze nie podales nazwy pliku/plikow. Aby program dzialal musi on dostac nazwy dwoch istniejacych i odpowiednio przygotowanych plikow";
    }
    else
    {
        //      <jakie s� indeksy, jaka zmienna jest przechowywana>
        std::map<int, PunktDrzewaDecyzyjnego> DrzewoDecyzyjne;
        std::vector<double> wzrost;
        std::vector<double> wyskok;
        std::vector<double> koszykowka, lekkoatletyka;
        int indeksMaksymalny{}, indeksTestowanych{};
        
        pobierzDane(nazwaPlikuWejsciowego, wzrost, wyskok);

        pobierzIndeks(nazwaPlikuDrzewa, indeksMaksymalny);

        pobierzDrzewo(nazwaPlikuDrzewa, DrzewoDecyzyjne, indeksMaksymalny);

        porownaj(wzrost, wyskok, indeksMaksymalny, koszykowka, lekkoatletyka, DrzewoDecyzyjne);

        zapiszDoPliku(koszykowka, lekkoatletyka);
        
    }
}

