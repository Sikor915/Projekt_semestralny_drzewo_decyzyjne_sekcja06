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
*   @param znakTestu Jaki test ma zosta� wykonany 
*   @param wymaganie Warto�� graniczna (do kt�rej b�dziemy przyr�wnywa�)
*   @param indeks Indeks nast�pnego punktu drzewa decyzyjnego kiedy test si� nie powiedzie
*   @param klasyfikacja Do kt�rej dyscypliny zakwalifikowa� kiedy test si� powiedzie
*   @param klasyfikacjaOstateczna Wykorzystane przy ostatnim punkcie drzewa kiedy test si� nie powiedzie
*/


struct PunktDrzewaDecyzyjnego
{
    std::string atrybut; // Jaki atrybut testowa� np. wzrost albo wysoko�� skoku
    std::string znakTestu; // Znak wykonywanego testu ( '<', '>'). Do wykorzystania z jakim� switch-case
    double wymaganie{}; // Warto�� do kt�rej b�dziemy przyr�wnywa�
    int indeks{}; // Indeks nast�pnego punktu drzewa decyzyjnego
    std::string klasyfikacja; // Klasyfikacja je�eli test si� powiedzie (ex.: je�eli wzrost < 190 cm to klasyfikacj� b�dzie "Koszyk�wka")
    std::string klasyfikacjaOstateczna; // Klasyfikacja przy ko�cu drzewa
};

/** Funkcja pobiera dane z pliku wej�ciowego (wzrost i wyskok)
 *  @param nazwaPliku nazwa pliku wyj�ciowego (w formacie .txt)
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
 *  @param drzewo referencja na map� drzewa decyzyjnego
 *  @param indeksMaksymalny referencja do maksymalnego indeksu drzewa
 */

void pobierzDrzewo(std::string nazwaPliku, std::map<int, PunktDrzewaDecyzyjnego>& drzewo, int& indeksMaksymalny);

/** Funkcja por�wnuje dane z pliku wej�ciowego do drzewa i przypisuje do odpowiednich dyscyplin
 *  @param wzrost referencja na wektor wzrostu
 *  @param wyskok referencja na wektor wyskoku
 *  @param indeksMaksymany referencja do maksymalnego indeksu drzewa
 *  @param koszykowka referencja do wektora przechowywuj�cego graczy przydzielonych do koszyk�wki
 *  @param lekkoatletyka referencja do wektora przechowywuj�cego graczy przydzielonych do lekkoatletyki
 *  @param DrzewoDecyzyjne referencja do mapy drzewa decyzyjnego
 */

void porownaj(std::vector<double>& wzrost, std::vector<double>& wyskok, int& indeksMaksymalny, std::vector<double>& koszykowka, std::vector<double>& lekkoatletyka, std::map<int, PunktDrzewaDecyzyjnego>& DrzewoDecyzyjne);

/** Funkcja zapisuje wektory z graczami koszyk�wki i lekkoatletyki do pliku wyj�ciowego
 *  @param koszykowka referencja do wektora z graczami koszyk�wki
 *  @param lekkoatletyka referencja do wektora z graczami lekkoatletyki
 */

void zapiszDoPliku(std::vector<double>& koszykowka, std::vector<double>& lekkoatletyka);


#endif
