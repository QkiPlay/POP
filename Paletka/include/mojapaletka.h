#ifndef MOJAPALETKA_H
#define MOJAPALETKA_H

#include "paletka.h"

class mojapaletka : public paletka{
public:
    mojapaletka(int szerokosc, int pozycja, int maxwychylenie);
    bool krok() override;
};

#endif // MOJAPALETKA_H
