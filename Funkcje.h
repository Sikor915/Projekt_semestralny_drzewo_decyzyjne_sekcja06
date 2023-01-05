#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

#include"Struktura.h"

/** Funkcja pobiera dane z pliku wejsciowego (wzrost i wyskok)
 *  @param nazwaPliku nazwa pliku wyjsciowego (w formacie .txt)
 *  @param wzrost referencja na wektor przechowujacy wzrost osob
 *  @param wyskok referencja na wektor przechowujacy wyskok osob
 */

void pobierzDane(std::string nazwaPliku, std::vector<double>& wzrost, std::vector<double>& wyskok);

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

void pobierzDrzewo(std::string nazwaPliku, std::map<int, PunktDrzewaDecyzyjnego>& drzewo, int& indeksMaksymalny);

/** Funkcja porownuje dane z pliku wejsciowego do drzewa i przypisuje do odpowiednich dyscyplin
 *  @param wzrost referencja na wektor wzrostu
 *  @param wyskok referencja na wektor wyskoku
 *  @param indeksMaksymalny referencja do maksymalnego indeksu drzewa
 *  @param koszykowka referencja do wektora przechowywujacego graczy przydzielonych do koszykowki
 *  @param lekkoatletyka referencja do wektora przechowywujacego graczy przydzielonych do lekkoatletyki
 *  @param DrzewoDecyzyjne referencja do mapy drzewa decyzyjnego
 */

void porownaj(std::vector<double>& wzrost, std::vector<double>& wyskok, int& indeksMaksymalny, std::vector<double>& koszykowka, std::vector<double>& lekkoatletyka, std::map<int, PunktDrzewaDecyzyjnego>& DrzewoDecyzyjne);

/** Funkcja zapisuje wektory z graczami koszykowki i lekkoatletyki do pliku wyjsciowego
 *  @param koszykowka referencja do wektora z graczami koszykowki
 *  @param lekkoatletyka referencja do wektora z graczami lekkoatletyki
 */

void zapiszDoPliku(std::vector<double>& koszykowka, std::vector<double>& lekkoatletyka);


#endif
