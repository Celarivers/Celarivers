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
SOFTWARE.*/
#include "envoiSecurise2.h"
conversation::conversation()
{
    taille = 0;
    etape = true;// true = en cours de réception d'une taille (2 octets)
    erreur = false;
    uint16_t nombre(10);
    uint8_t *octet(reinterpret_cast<uint8_t*>(&nombre));
    if(octet[1] == 10)
    {
little = false;
    }
    else
    {
little = true;
    }
}
bool conversation::actualiser()
{
    if(notReady.size() > 100000)
    {
        erreur = true;
        return false;
    }/// gérer le not ready
// on envoie par petits bouts de 1000 octets
    bool continuer(true);
    while(notReady.size() > 0)
    {
        std::size_t aEnvoyer(0);
        std::size_t sended(0); // les données envoyes
        if(notReady.size() < 1000)
            aEnvoyer = notReady.size();
        else
            aEnvoyer = 1000;
        int8_t paquet2[aEnvoyer];
        for(unsigned int nombre(0); nombre < aEnvoyer; ++nombre)
        {
            paquet2[nombre] = notReady[nombre];
        }
        uint16_t envoyes(0);
        sended=0;
        while(envoyes >= aEnvoyer && continuer)
        {
            sf::Socket::Status statut = TCP->send(&paquet2[envoyes], aEnvoyer, sended);
            envoyes += sended;
            if(sf::Socket::Status::Error == statut)
            {
                erreur = true;
                return false;
            }
            else if(sf::Socket::Status::NotReady == statut)
            {
                continuer = false;
            }
            else if(sf::Socket::Status::Disconnected == statut)
            {
                erreur = true;
                return false;
            }
            for(unsigned int nombre(0); nombre < sended; ++nombre)
                notReady.pop_back();
        }
    }
///fin
    std::size_t received(0); // les données reçues
    sf::Socket::Status statut = TCP->receive(paquet, 10240, received);
    if(statut == sf::Socket::Error)
    {
        erreur = true;
        return false;
    }
    if(received > 0)
    {
        for(unsigned int nombre(0); nombre < received; ++nombre)
            historiqueReception.push_back(paquet[nombre]);
    }
    if(etape)
    {
        if(historiqueReception.size()>= 2)
        {

            uint16_t taille2(0);

            int8_t*octet3(reinterpret_cast<int8_t*>(&taille2));
            if(little)
            {
            octet3[0] = historiqueReception[1];
            octet3[1] = historiqueReception[0];
            }
            else
            {
            octet3[0] = historiqueReception[0];
            octet3[1] = historiqueReception[1];
            }
            taille = taille2;
            historiqueReception.pop_front();
            historiqueReception.pop_front();
            etape = false;
        }
    }
    else
    {
        if(historiqueReception.size() >= taille)
        {

            etape = true;
            resultat.push_back(std::deque<int8_t>());
            for(unsigned int nombre(0); nombre < taille; ++nombre)
            {
                resultat[resultat.size()-1].push_back(historiqueReception[nombre]);
            }
            for(unsigned int nombre(0); nombre < taille; ++nombre)
                historiqueReception.pop_front();
            taille = 0;
        }
    }
    return true;
}
bool conversation::envoyer(int8_t tableau[], uint16_t tailleTableau)
{
    if(notReady.size() > 0)
    {
        int8_t la_taille[2];
        uint8_t octetsEnvoyes2(0);
        int8_t *octet = reinterpret_cast<int8_t*>(&tailleTableau);
        if(little)
        {
        la_taille[0] = octet[1];
        la_taille[1] = octet[0];
        }
        else
        {
         la_taille[0] = octet[0];
        la_taille[1] = octet[1];
        }
        notReady.push_back(la_taille[0]);
        notReady.push_back(la_taille[1]);
        for(unsigned int nombre(0); nombre < tailleTableau; ++nombre)
        {
            notReady.push_back(tableau[nombre]);
        }
    }
    else
    {
        int8_t la_taille[2];
        uint8_t octetsEnvoyes2(0);
        int8_t *octet = reinterpret_cast<int8_t*>(&tailleTableau);
        if(little)
        {
         la_taille[0] = octet[1];
        la_taille[1] = octet[0];
        }
        else

        {
            la_taille[0] = octet[0];
        la_taille[1] = octet[1];
        }
        unsigned int nombre4(octetsEnvoyes2);
        while(nombre4 < 2)
        {
            std::size_t resultat2(0);
            sf::Socket::Status statut = TCP->send(&la_taille[nombre4], 2-nombre4, resultat2);

            if(statut == sf::Socket::Status::Error|| statut == sf::Socket::Status::Disconnected)
            {
                erreur = true;
                return false;
            }
            nombre4+=resultat2;
            resultat2=0;
            if(statut == sf::Socket::Status::NotReady)
            {
                for(unsigned int nombre(octetsEnvoyes2); nombre < 2; ++nombre)
                    notReady.push_back(la_taille[nombre]);
                for(unsigned int nombre(0); nombre < tailleTableau; ++nombre)
                    notReady.push_back(tableau[nombre]);
                return true;
            }
        }

        uint16_t octetsEnvoyes(0);
        unsigned int nombre2(octetsEnvoyes);
        while(nombre2 < tailleTableau)
        {
            std::size_t resultat2(0);
            sf::Socket::Status statut = TCP->send(&tableau[nombre2], tailleTableau-nombre2, resultat2);
            if(statut == sf::Socket::Status::Error || statut == sf::Socket::Status::Disconnected)
            {
                erreur = true;
                return false;
            }
            nombre2+=resultat2;
            resultat2=0;
            if(statut == sf::Socket::Status::NotReady)
            {
                for(unsigned int nombre3(octetsEnvoyes); nombre3 < tailleTableau; ++nombre3)
                    notReady.push_back(tableau[nombre3]);
                return true;
            }
        }
    }
    return true;
}
