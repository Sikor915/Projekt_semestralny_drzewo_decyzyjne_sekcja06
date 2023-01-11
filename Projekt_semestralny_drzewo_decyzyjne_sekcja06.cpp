/** Program przyporzadkowuje osoby o danych atrybutach wzrostu i wyskoku do poszczegolnych dyscyplin sportowych (koszykowka albo lekkoatletyka)
 * 
 *  @date 2023-01-05
 * 
 *  @author Kacper Sikorski, I rok Informatyki, 3 grupa dziekañska, sekcja 06 PPK
 * 
 *  @todo Czytanie parametrow drzewa decyzyjnego i przechowanie ich. Mozna w sumie uzyc struktury do tego by pozniej bylo latwiej z if-ami moze --- DONE
 *  
 *  @todo Porownywanie wartosci do drzewa decyzyjnego - tu by w sumie przydalo sie to parami sprawdzac (tzn. wyskok[0] i wzrost[0]) --- DONE (gownianie ale jest)
 *
 *  @todo Opracowac jak wywolac ten program z konsoli i wraz z podaniem parametrow (plikow tekstowych) - ja uzywalem cl /EHsc Projekt_semestralny_drzewo_decyzyjne.cpp i potem .\Projekt_semestralny(...) --- DONE?
 * 
 *  @todo Opracowac zeby program podawal instrukcje co jak zrobic gdy uzytkownik nie poda plikow wejsciowych a takze moze niech poda lokalizacje gdzie zapisal plik tekstowy z wynikiem --- DONE
 *
 *  @todo Opisac wszystko z pomoca Doxygena - ogarnac w ogole jak sie to cos robi --- DONE
 * 
 *  @todo Have fun :)
 *
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include "Funkcje.h"

int main(int argc, char*argv[])
{
    /*
    std::cout << argc << std::endl;
    for (int i = 0; i < 7; i++)
    {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
    */

    std::string nazwaPlikuWejsciowego{ argv[2] }, nazwaPlikuDrzewa{ argv[4] }, nazwaPlikuWyjsciowego{argv[6]};

    /*
    std::cout << "Program obsluguje i bada przynaleznosc zawodnikow o specyficznych parametrach do poszczegolnych dyscyplin (koszykowka i lekkoatletyka)." << std::endl;
    std::cout << "Prosze podanie nazwy pliku z danymi razem z rozszerzeniem .txt a potem nazwy pliku drzewa decyzyjnego takze z rozszerzeniem .txt" << std::endl;
    std::cout << "Prosze sie upewnic ze pliki sa odpowiednio przygotowane tzn. plik z danymi posiada dwie kolumny wzrost i wysokosc (w tej kolejnosci) a drzewo jest opisane w ten sposob" << std::endl;
    std::cout << "<indeks wejscia> <atrybut> <operator> <wartosc> <indeks wyjscia NIE> <indeks wyjscia TAK>; gdzie operator to znak mniejszy lub wiekszy\n" << std::endl;
    std::cin >> nazwaPlikuWejsciowego >> nazwaPlikuDrzewa;
    std::cout << std::endl;
    */

    std::ifstream plikWejsciowy(nazwaPlikuWejsciowego);
    std::ifstream plikDrzewa(nazwaPlikuDrzewa);

    if (plikWejsciowy.is_open() or plikDrzewa.is_open())
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

        zapiszDoPliku(koszykowka, lekkoatletyka, nazwaPlikuWyjsciowego);

        plikWejsciowy.close();
        plikDrzewa.close();
    }
    else
    {
        std::cout << "Wyglada na to ze nie podales nazwy pliku/plikow albo podane pliki nie istnieja. Aby program dzialal musi on dostac nazwy dwoch istniejacych i odpowiednio przygotowanych plikow";
        std::cout << std::endl;
    }
}

