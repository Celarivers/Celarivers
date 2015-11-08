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
SOFTWARE.*/#ifndef VAISSEAU_H_INCLUDED
#define VAISSEAU_H_INCLUDED
#include <iostream>
#include <string>
#include "Affichage.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class joueur
{
public:
joueur();
void miseAjour(point newPosition, uint16_t newAngleX, uint16_t newAngleY, uint8_t newGaz, uint8_t newAxeX, uint8_t newAxeY, float newVitesse);
joueur(char Modele, anglePts Angles, affichage*Modelisation, point Position, char Couleur, std::string Pseudo, int Level, int ID);
void setPosition(point Position);
void setAngles(anglePts Angles);
void update();
void afficher(glm::mat4 modelview, glm::mat4 projection, GLuint program);
point getPosition();
void afficherPseudo(glm::mat4 modelview, glm::mat4 projection, GLuint program, sf::RenderWindow &fenetre, sf::Font &police);
anglePts getAngles();
//bool collisionBool(joueur &utilisateur);
point calculAngle(point cible, double angle2);
//cubeCol* getCube();
double distance(point a);
uint8_t modele;
anglePts angles;
affichage *modelisation;
point position;
char couleur;
void changerNavette(uint8_t newModele);
std::string pseudo;
int level;
uint16_t id;
uint8_t empire;
uint8_t guilde;
int16_t angleX;
float vitesseMax;
int16_t angleY;
uint8_t gaz;
uint8_t axeX;
uint8_t axeY;
float vitesse;
void update2();
point actualiserPosition();
};

#endif // VAISSEAU_H_INCLUDED
