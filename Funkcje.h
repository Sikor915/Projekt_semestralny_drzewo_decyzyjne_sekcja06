#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

#include"Struktura.h"

typedef std::map<int, PunktDrzewaDecyzyjnego> mapaDrzewa;
typedef std::vector<std::pair<std::string, double>> wektorParSD;
typedef std::map<std::string, std::vector<double>> mapaSvD;

/** Funkcja pobiera dane z pliku wejsciowego 
 *  @param nazwaPliku Nazwa pliku wyjsciowego (w formacie .txt) 
 *  @param atrybuty Referencja do mapy wektorow przechowujacej atrybuty z pliku wejsciowego
 *  @param nazwyAtrybutow Referencja do wektora zawierajacego nazwy atrybutow z pliku wejsciowego
 */

void pobierzDane(std::string nazwaPliku, std::map<int, wektorParSD>& atrybuty, std::vector<std::string>& nazwyAtrybutow);

/** Funkcja pobiera indeks maksymalny w pliku z drzewem
 *  @param nazwaPliku Nazwa pliku drzewa (w formacie .txt)
 *  @param indeksMaksymalny Referencja do maksymalnego indeksu drzewa
 */

void pobierzIndeks(std::string nazwaPliku, int& indeksMaksymalny);

/** Funkcja pobiera dane z pliku drzewa i zapisuje je do mapy
 *  @param nazwaPliku Nazwa pliku drzewa (w formacie .txt)
 *  @param drzewo Referencja na mape drzewa decyzyjnego
 *  @param indeksMaksymalny Referencja do maksymalnego indeksu drzewa
 *  @param nazwyPrzydzielenia Referencja do setu przechowujacego miejsca przydzielenia w drzewie
 */

void pobierzDrzewo(std::string nazwaPliku, mapaDrzewa& drzewo, int& indeksMaksymalny, std::set<std::string>& nazwyPrzydzielenia);

/** Funkcja przyrownoje wartosci z pliku wejsciowego do drzewa decyzyjnego i przypisuje wszystkie dane do odpowiednich miejsc
*	@param drzewo Referencja na mape drzewa decyzyjnego
*	@param atrybuty Referencja na mape wektorow z atrybutami osob z pliku wejsciowego
*	@param indeksMax Referencja na zmienna z maksymalnym indeksem drzewa decyzyjnego
*	@param przydzieleni Referencja na mape przechowujaca przydzielone juz osoby
*/

void porownanie(mapaDrzewa& drzewo, std::map<int, wektorParSD>& atrybuty, int& indeksMax, mapaSvD& przydzieleni);

/** Funkcja zapisuje osoby przydzielone do pliku wyjsciowego
 *  @param nazwaPlikuWyjsciowego Zmienna przechowujaca nazwe pliku z koncowym efektem kodu
 *	@param przydzieleni Mapa z osobami przydzielonymi
 *	@param nazwyPrzydzielenia Set przechowujacy miejsca przydzielenia z drzewa
 *	@param nazwyAtrybutow Wektor z nazwami atrybutow przedstawionych w pliku wejsciowym
 */

void zapiszDoPliku(std::string nazwaPlikuWyjsciowego, mapaSvD przydzieleni, std::set<std::string> nazwyPrzydzielenia, std::vector<std::string> nazwyAtrybutow);

#endif
