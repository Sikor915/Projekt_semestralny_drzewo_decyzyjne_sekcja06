/** @File **/

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

/** Struktura opisuje punkt w drzewie decyzyjnym
*   @param atrybut Nazwa atrybutu do testowania
*   @param znakTestu Jaki test ma zostaæ wykonany 
*   @param wymaganie Wartoœæ graniczna (do której bêdziemy przyrównywaæ)
*   @param indeks Indeks nastêpnego punktu drzewa decyzyjnego kiedy test siê nie powiedzie
*   @param klasyfikacja Do której dyscypliny zakwalifikowaæ kiedy test siê powiedzie
*   @param klasyfikacjaOstateczna Wykorzystane przy ostatnim punkcie drzewa kiedy test siê nie powiedzie
*/


struct PunktDrzewaDecyzyjnego
{
    std::string atrybut; // Jaki atrybut testowaæ np. wzrost albo wysokoœæ skoku
    std::string znakTestu; // Znak wykonywanego testu ( '<', '>'). Do wykorzystania z jakimœ switch-case
    double wymaganie{}; // Wartoœæ do której bêdziemy przyrównywaæ
    int indeks{}; // Indeks nastêpnego punktu drzewa decyzyjnego
    std::string klasyfikacja; // Klasyfikacja je¿eli test siê powiedzie (ex.: je¿eli wzrost < 190 cm to klasyfikacj¹ bêdzie "Koszykówka")
    std::string klasyfikacjaOstateczna; // Klasyfikacja przy koñcu drzewa
};

/** Funkcja pobiera dane z pliku wejœciowego (wzrost i wyskok)
 *  @param nazwaPliku nazwa pliku wyjœciowego (w formacie .txt)
 *  @param wzrost referencja na wektor wzrostu
 *  @param wyskok referencja na wektor wyskoku
 */

void pobierzDane(std::string nazwaPliku, std::vector<double>& wzrost, std::vector<double>& wyskok);

/** Funkcja pobiera indeks maksymalny w pliku z drzewem
 *  @param nazwaPliku nazwa pliku drzewa (w formacie .txt)
 *  @param indeksMaksymalny referencja do maksymalnego indeku drzewa
 */

void pobierzIndeks(std::string nazwaPliku, int& indeksMaksymalny);

/** Funkcja pobiera dane z pliku drzewa i zapisuje je do mapy
 *  @param nazwaPliku nazwa pliku drzewa (w formacie .txt)
 *  @param drzewo referencja na mapê drzewa decyzyjnego
 *  @param indeksMaksymalny referencja do maksymalnego indeksu drzewa
 */

void pobierzDrzewo(std::string nazwaPliku, std::map<int, PunktDrzewaDecyzyjnego>& drzewo, int& indeksMaksymalny);

/** Funkcja porównuje dane z pliku wejœciowego do drzewa i przypisuje do odpowiednich dyscyplin
 *  @param wzrost referencja na wektor wzrostu
 *  @param wyskok referencja na wektor wyskoku
 *  @param indeksMaksymany referencja do maksymalnego indeksu drzewa
 *  @param koszykowka referencja do wektora przechowywuj¹cego graczy przydzielonych do koszykówki
 *  @param lekkoatletyka referencja do wektora przechowywuj¹cego graczy przydzielonych do lekkoatletyki
 *  @param DrzewoDecyzyjne referencja do mapy drzewa decyzyjnego
 */

void porownaj(std::vector<double>& wzrost, std::vector<double>& wyskok, int& indeksMaksymalny, std::vector<double>& koszykowka, std::vector<double>& lekkoatletyka, std::map<int, PunktDrzewaDecyzyjnego>& DrzewoDecyzyjne);

/** Funkcja zapisuje wektory z graczami koszykówki i lekkoatletyki do pliku wyjœciowego
 *  @param koszykowka referencja do wektora z graczami koszykówki
 *  @param lekkoatletyka referencja do wektora z graczami lekkoatletyki
 */

void zapiszDoPliku(std::vector<double>& koszykowka, std::vector<double>& lekkoatletyka);


#endif
