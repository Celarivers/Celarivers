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
SOFTWARE.*/#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include <GL/glew.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
//#include <SFML/OpenGL.hpp>
#include <GL/glew.h>
#include <GL/gl.h>
#include <fstream>
#include <windows.h>
#include <memory>
class Affichage2
{
public:
Affichage2();
bool charger(std::string Vertex, std::string Couleur);
~Affichage2();
GLuint getProgram();
private:
GLuint vertex;
GLuint couleur;
GLuint program;
};
class anglePts
{
public:
anglePts();
anglePts(double a, double b, double c, double d, double e);
void setX(double a);
void setY(double a);
double getX();
double getY();
double angleX;
double angleZ;
double angleY;
double longueur1;
double longueur2;
};
class point
{
public:
point();
point(double X2, double Y2, double Z2);
double getX ();
double getY();
double getZ();
void setX (double nombre);
void setY(double nombre);
void setZ(double nombre);
point& operator+= (point valeur);
void afficher();
anglePts calculAngles();
void calculPoint(anglePts angles);
private:
double X;
double Y;
double Z;
};

class textureC
{
public:
textureC(double x, double y);
double getX();
double getY();
private:
double a;
double b;
};
class materiel
{
public:
materiel(point Couleur);
materiel();
void setNumber(unsigned int number);
point getColor();
std::string getName();
std::string nom;
std::vector<unsigned int> nombre;
point couleurs;
};
class forme // pour opengl 2.1
{
public:
forme();
void setAngles(anglePts angles);
void setPositon (point position);
void setColor(point Couleur, unsigned int nombre);
point getVertices(unsigned int nombre);
point getColor(unsigned int nombre);
point getNormale(unsigned int nombre);// à faire
bool texture(); // à faire
textureC getTexture(unsigned int nombre); // à faire
void addition(point valeur);
int getNbVertices();
void push(point ver, point nor);
void push(point ver, point nor, textureC tex);
void vider();
void dessiner(anglePts Angles, point Position);
point calculerPoint(anglePts angles);
void pushColor(point color);
private:
std::vector<point> vertices;
std::vector<point> normales;
std::vector<point> couleurs;
std::vector<textureC> conteneurTextures;
bool textures;
anglePts Angles;
point Position;
void Couleurs(std::string couleur);
};
class element// pour opengl 3.3 et 2.1
{
public:
element();
void dessiner(char *color, bool couleurs);
void charger();
void charger2();
void pushTriangle(std::vector<float> points);
void pushRectangle(std::vector<float> points);
~element();
float distance(point a);
void definirCouleurs();
unsigned int getNombreTriangles();
void pushTriangleC(std::vector<float> points);
void pushRectangleC(std::vector<float> points);
private:
std::vector<float> triangles;
std::vector<float> couleursTriangles;
std::vector<float> couleursTriangle2;
std::vector<float> couleursTriangles3;
std::vector<float> couleursTriangles4;
void envoieCouleurs(std::vector<float> colors);
char couleur;
int utilisation;//couleur, texture, ou mtl
int nombresTableaux;
GLuint identifiantVBO;
GLuint identifiantVBO2;
bool Couleur;
bool mtl;
};
class affichage
{
public:
affichage();
void charger(unsigned int nombre);
void charger2(unsigned int nombre);
bool chargerFichier(std::string obj, bool mtl, bool positionnements, std::string MTL);
void definirCouleurs(std::string couleur);
void replacer();
void afficher(uint8_t nombre, char *color, bool couleur);
int nbElements();
void modifierAngles(unsigned int nombre);
void definirCouleur(unsigned int nombre);
private:
double distance(point a);
std::vector<materiel> materiaux;
std::vector<element> elements;
bool textures;

};

#endif // AFFICHAGE_H_INCLUDED
