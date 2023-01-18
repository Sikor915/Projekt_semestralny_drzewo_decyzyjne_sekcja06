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
 *  @param atrybuty referencja do wektora wektorów przechowujacy atrybuty z pliku wejsciowego
 *  @param nazwyAtrybutow referencja do wektora zawierajacego nazwy atrybutow z pliku wejsciowego
 */

void pobierzDane(std::string nazwaPliku, std::vector<std::vector<double>>& atrybuty, std::vector<std::string>& nazwyAtrybutow);

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
 *  @param nazwyAtrybutow referencja do wektora zawierajacego nazwy atrybutow z pliku wejsciowego
 *  @param atrybuty referencja do wektora wektorów przechowujacy atrybuty z pliku wejsciowego
 *  @param indeksMaksymalny referencja do maksymalnego indeksu drzewa
 *  @param koszykowka referencja do wektora przechowywujacego graczy przydzielonych do koszykowki
 *  @param lekkoatletyka referencja do wektora przechowywujacego graczy przydzielonych do lekkoatletyki
 *  @param DrzewoDecyzyjne referencja do mapy drzewa decyzyjnego
 */

void porownaj(std::vector<std::string>& nazwyAtrybutow,std::vector<std::vector<double>>& atrybuty, int& indeksMaksymalny, std::vector<double>& koszykowka, std::vector<double>& lekkoatletyka, std::map<int, PunktDrzewaDecyzyjnego>& DrzewoDecyzyjne);

/** Funkcja zapisuje wektory z graczami koszykowki i lekkoatletyki do pliku wyjsciowego
 *  @param koszykowka referencja do wektora z graczami koszykowki
 *  @param lekkoatletyka referencja do wektora z graczami lekkoatletyki
 *  @param nazwaPlikuWyjsciowego zmienna przechowujaca nazwe pliku z koncowym efektem kodu
 */

void zapiszDoPliku(std::vector<double>& koszykowka, std::vector<double>& lekkoatletyka, std::string nazwaPlikuWyjsciowego);


#endif
