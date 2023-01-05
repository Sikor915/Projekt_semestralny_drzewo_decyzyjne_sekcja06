// TODO List
//  1. Czytanie parametrów drzewa decyzyjnego i przechowanie ich. Mo¿na w sumie u¿yæ struktury do tego by pó¿niej by³o ³atwiej z if-ami mo¿e --- DONE
// 
//  2. Porównywanie wartoœci do drzewa decyzyjnego - tu by w sumie przyda³o siê to parami sprawdzaæ (tzn. wyskok[0] i wzrost[0]) --- DONE (gównianie ale jest)
// 
//  3. Opracowaæ jak wywo³aæ ten program z konsoli i wraz z podaniem parametrów (plików tekstowych) - ja u¿ywa³em cl /EHsc Projekt_semestralny_drzewo_decyzyjne.cpp i potem .\Projekt_semestralny(...) --- Half-Done
// 
//  4. Opracowaæ ¿eby program podawa³ instrukcje co jak zrobiæ gdy u¿ytkownik nie poda plików wejœciowych a tak¿e mo¿e niech poda lokalizacjê gdzie zapisa³ plik tekstowy z wynikiem --- DONE
//
//  5. Opisaæ wszystko z pomoc¹ Doxygena - ogarn¹æ w ogóle jak siê to coœ robi --- DONE
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
        //      <jakie s¹ indeksy, jaka zmienna jest przechowywana>
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

