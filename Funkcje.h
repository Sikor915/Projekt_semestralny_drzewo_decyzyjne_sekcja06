#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

#include"Struktura.h"



/** Funkcja pobiera dane z pliku wejsciowego (wzrost i wyskok)
 *  @param nazwaPliku nazwa pliku wyjsciowego (w formacie .txt) 
 *  @param Atrybuty referencja do mapy wektorów przechowujacej atrybuty z pliku wejsciowego
 *  @param nazwyAtrybutow referencja do wektora zawierajacego nazwy atrybutow z pliku wejsciowego
 */

void pobierzDane(std::string nazwaPliku, std::map<int, std::map<std::string, double>>& Atrybuty, std::vector<std::string>& nazwyAtrybutow);

/** Funkcja pobiera indeks maksymalny w pliku z drzewem
 *  @param nazwaPliku nazwa pliku drzewa (w formacie .txt)
 *  @param indeksMaksymalny referencja do maksymalnego indeku drzewa
 */

void pobierzIndeks(std::string nazwaPliku, int& indeksMaksymalny);

/** Funkcja pobiera dane z pliku drzewa i zapisuje je do mapy
 *  @param nazwaPliku nazwa pliku drzewa (w formacie .txt)
 *  @param drzewo referencja na mape drzewa decyzyjnego
 *  @param indeksMaksymalny referencja do maksymalnego indeksu drzewa
 */

void pobierzDrzewo(std::string nazwaPliku, std::map<int, PunktDrzewaDecyzyjnego>& drzewo, int& indeksMaksymalny, std::set<std::string>& nazwyPrzydzielenia);

/**



*/

void funkcja(std::map<int, PunktDrzewaDecyzyjnego>& drzewo, std::map<int, std::map<std::string, double>>& Atrybuty, int& indeksMax);

/** Funkcja zapisuje wektory z graczami koszykowki i lekkoatletyki do pliku wyjsciowego
 *  @param koszykowka referencja do wektora z graczami koszykowki
 *  @param lekkoatletyka referencja do wektora z graczami lekkoatletyki
 *  @param nazwaPlikuWyjsciowego zmienna przechowujaca nazwe pliku z koncowym efektem kodu
 */

//void zapiszDoPliku(std::string nazwaPlikuWyjsciowego);


#endif
