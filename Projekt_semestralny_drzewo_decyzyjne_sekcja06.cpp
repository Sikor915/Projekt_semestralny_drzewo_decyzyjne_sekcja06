/** Program jest uniwersalna implementacja drzewa decyzyjnego
 * 
 *  @date 2023-01-21
 * 
 *  @author Kacper Sikorski, I rok Informatyki, 3 grupa dziekanska, sekcja 06 PPK
 * 
 *  @todo Czytanie parametrow drzewa decyzyjnego i przechowanie ich. Mozna w sumie uzyc struktury do tego by pozniej bylo latwiej z if-ami moze --- DONE
 *  
 *  @todo Porownywanie wartosci do drzewa decyzyjnego - tu by w sumie przydalo sie to parami sprawdzac (tzn. wyskok[0] i wzrost[0]) --- DONE
 *
 *  @todo Opracowac jak wywolac ten program z konsoli i wraz z podaniem parametrow (plikow tekstowych) - wchodzisz do CMD do projektu -> x64 -> Debug -> nazwa.exe i lecisz --- DONE
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
    if (argc == 7)
    {
        std::string arg1{ argv[1] }, arg3{ argv[3] }, arg5{ argv[5] };
        std::string nazwaPlikuWejsciowego{}, nazwaPlikuDrzewa{}, nazwaPlikuWyjsciowego{};   
        
        if (arg1 == "-i")
        {
            nazwaPlikuWejsciowego = argv[2];
        }
        else if (arg1 == "-t")
        {
            nazwaPlikuDrzewa = argv[2];
        }
        else if (arg1 == "-o")
        {
            nazwaPlikuWyjsciowego = argv[2];
        }
        if (arg3 == "-i")
        {
            nazwaPlikuWejsciowego = argv[4];
        }
        else if (arg3 == "-t")
        {
            nazwaPlikuDrzewa = argv[4];
        }
        else if (arg3 == "-o")
        {
            nazwaPlikuWyjsciowego = argv[4];
        }
        if (arg5 == "-i")
        {
            nazwaPlikuWejsciowego = argv[6];
        }
        else if (arg5 == "-t")
        {
            nazwaPlikuDrzewa = argv[6];
        }
        else if (arg5 == "-o")
        {
            nazwaPlikuWyjsciowego = argv[6];
        }
        std::ifstream plikWejsciowy(nazwaPlikuWejsciowego);
        std::ifstream plikDrzewa(nazwaPlikuDrzewa);

        if (plikWejsciowy.good() and plikDrzewa.good())
        {
            mapaDrzewa drzewoDecyzyjne;
            std::map<int, wektorParSD> atrybuty;
            std::vector<std::string> nazwyAtrybutow;
            std::set<std::string> nazwyPrzydzielenia;
            mapaSvD przydzieleni;
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
    else
    {
        std::cout << "Wyglada na to ze nie zostala podana odpowiednia liczba argumentow programu" << std::endl;
        std::cout << "Aby program funkcjonowal poprawnie potrzebuje on dostac nastepujace dane:" << std::endl << std::endl;
        std::cout << "-i 'nazwaPlikuWejsciowego'.txt -t 'nazwaPlikuDrzewa'.txt -o 'nazwaPlikuWyjsciowego'.txt" << std::endl;
        std::cout << "Prosze upewnic sie, ze przy wlaczaniu programu zostala podana odpowiednia ilosc argumentow i zostaly one odpowiednio przygotowane" << std::endl;
    }
    
}

