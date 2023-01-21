/** Program jest uniwersalna implementacja drzewa decyzyjnego
 * 
 *  @date 2023-01-21
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
 *  @todo Naprawic porownywanie i zapisywanie do wektorow bo program nie jest uniwersalny :( - zamiast wektorow 'koszykowka' i 'lekkoatletyka' trzeba by uzyc listy wektorow o dlugosci == ilosci klasyfikacji --- DONE
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
        std::map<int, PunktDrzewaDecyzyjnego> drzewoDecyzyjne;
        std::map<int, std::vector<std::pair<std::string, double>>> atrybuty;
        std::vector<std::string> nazwyAtrybutow;
        std::set<std::string> nazwyPrzydzielenia;
        std::map<std::string, std::vector<double>> przydzieleni;
        int indeksMaksymalny{}, indeksTestowanych{};

        pobierzDane(nazwaPlikuWejsciowego, atrybuty, nazwyAtrybutow);

        pobierzIndeks(nazwaPlikuDrzewa, indeksMaksymalny);

        pobierzDrzewo(nazwaPlikuDrzewa, drzewoDecyzyjne, indeksMaksymalny, nazwyPrzydzielenia);

        porownanie(drzewoDecyzyjne, atrybuty, indeksMaksymalny, przydzieleni);

        zapiszDoPliku(nazwaPlikuWyjsciowego, przydzieleni, nazwyPrzydzielenia, nazwyAtrybutow);

        plikWejsciowy.close();
        plikDrzewa.close();
    }
    else
    {
        std::cout << "Wyglada na to ze nie podales nazwy pliku/plikow albo podane pliki nie istnieja. Aby program dzialal musi on dostac nazwy dwoch istniejacych i odpowiednio przygotowanych plikow";
        std::cout << std::endl;
    }
}

