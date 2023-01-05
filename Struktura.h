#ifndef STRUKTURA_H
#define STRUKTURA_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

/** Struktura opisuje punkt w drzewie decyzyjnym
*   @date 2023-01-05
*   @author Kacper Sikorski, student Politechniki Slaskiej na I roku Informatyki
*   @param atrybut Nazwa atrybutu do testowania
*   @param znakTestu Jaki test ma zostac wykonany
*   @param wymaganie Wartosc graniczna (do ktorej bedziemy przyrownywac)
*   @param indeks Indeks nastepnego punktu drzewa decyzyjnego kiedy test sie nie powiedzie
*   @param klasyfikacja Do ktorej dyscypliny zakwalifikowac kiedy test sie powiedzie
*   @param klasyfikacjaOstateczna Wykorzystane przy ostatnim punkcie drzewa kiedy test sie nie powiedzie
*/
struct PunktDrzewaDecyzyjnego
{
    std::string atrybut;
    std::string znakTestu;
    double wymaganie{};
    int indeks{};
    std::string klasyfikacja;
    std::string klasyfikacjaOstateczna;
};

#endif
