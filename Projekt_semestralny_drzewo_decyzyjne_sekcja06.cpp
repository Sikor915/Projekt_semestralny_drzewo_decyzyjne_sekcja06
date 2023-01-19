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
 *  @todo Naprawic porownywanie i zapisywanie do wektorow bo program nie jest uniwersalny :( - zamiast wektorow 'koszykowka' i 'lekkoatletyka' trzeba by uzyc listy wektorow o dlugosci == ilosci klasyfikacji
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
#include <set>
#include "Funkcje.h"

int main(int argc, char*argv[])
{
    std::string nazwaPlikuWejsciowego{ argv[2] }, nazwaPlikuDrzewa{ argv[4] }, nazwaPlikuWyjsciowego{argv[6]};
    std::ifstream plikWejsciowy(nazwaPlikuWejsciowego);
    std::ifstream plikDrzewa(nazwaPlikuDrzewa);

    if (plikWejsciowy.good() and plikDrzewa.good())
    {
        //      <jakie s¹ indeksy, jaka zmienna jest przechowywana>
        std::map<int, PunktDrzewaDecyzyjnego> DrzewoDecyzyjne;
        //std::map<int, wektorA> Atrybuty;
        std::vector<std::vector<std::pair<std::string, double>>> Atrybuty;
        std::vector<std::string> nazwyAtrybutow;
        std::set<std::string> nazwyPrzydzielenia;
        int indeksMaksymalny{}, indeksTestowanych{};

        pobierzDane(nazwaPlikuWejsciowego, Atrybuty, nazwyAtrybutow);

        pobierzIndeks(nazwaPlikuDrzewa, indeksMaksymalny);

        pobierzDrzewo(nazwaPlikuDrzewa, DrzewoDecyzyjne, indeksMaksymalny, nazwyPrzydzielenia);

        funkcja(DrzewoDecyzyjne, Atrybuty, indeksMaksymalny);

//        zapiszDoPliku(nazwaPlikuWyjsciowego);

        plikWejsciowy.close();
        plikDrzewa.close();
    }
    else
    {
        std::cout << "Wyglada na to ze nie podales nazwy pliku/plikow albo podane pliki nie istnieja. Aby program dzialal musi on dostac nazwy dwoch istniejacych i odpowiednio przygotowanych plikow";
        std::cout << std::endl;
    }
}

