/*The MIT License (MIT)

Copyright (c) 2015 Chapuis Paul

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/#ifndef ENVOISECURISE2_H_INCLUDED
#define ENVOISECURISE2_H_INCLUDED
#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <queue>
#include <deque>
#include <memory>
class conversation
{
public:
    sf::TcpSocket *TCP;
    conversation();
    bool actualiser(); // l'actualisation
    uint16_t taille; // la taille de l'octet
    bool etape; // taille ou octet (true ou false)
    bool envoyer(int8_t tableau[], uint16_t tailleTableau); // retourne le nombre d'octets envoyés
    std::deque<int8_t> envoyer2; // le paquet qui doit être envoyé
    std::deque<std::deque<int8_t> > resultat; // la réception
    int8_t *paquet;
    bool erreur;
    std::deque <int8_t>historiqueReception;
    std::deque <int8_t> notReady;
    bool little;
};


#endif // ENVOISéCURISé2_H_INCLUDED
