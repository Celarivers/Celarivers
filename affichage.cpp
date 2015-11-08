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
#ifndef BUFFER_OFFSET
#define BUFFER_OFFSET(offset) ((char*)NULL + (offset))
#endif
#include "affichage.h"
#include <deque>
#include <cmath>

Affichage2::Affichage2()
{
vertex=0;
couleur=0;
program=0;
}
bool Affichage2::charger(std::string Vertex, std::string Couleur)
{
vertex=0;
couleur=0;
program=0;
vertex = glCreateShader(GL_VERTEX_SHADER);
if(vertex == 0)
return false;

const GLchar* chaineCodeSource = Vertex.c_str();
glShaderSource(vertex, 1, &chaineCodeSource, 0);
glCompileShader(vertex);
GLint erreurCompilation(0);
glGetShaderiv(vertex, GL_COMPILE_STATUS, &erreurCompilation);
if(erreurCompilation != GL_TRUE)
{GLint tailleErreur(0);
glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &tailleErreur);
char tabErreur[tailleErreur+1];
char*erreur = tabErreur;
glGetShaderInfoLog(vertex, tailleErreur, &tailleErreur, erreur);
erreur[tailleErreur] = '\0';

glDeleteShader(vertex);
return false;
}

GLuint couleur = glCreateShader(GL_FRAGMENT_SHADER);
if(couleur == 0)
return false;
const GLchar* chaineCodeSource2 = Couleur.c_str();
glShaderSource(couleur, 1, &chaineCodeSource2, 0);
glCompileShader(couleur);
GLint erreurCompilation2(0);
glGetShaderiv(couleur, GL_COMPILE_STATUS, &erreurCompilation2);
if(erreurCompilation2 != GL_TRUE)
{GLint tailleErreur(0);
glGetShaderiv(couleur, GL_INFO_LOG_LENGTH, &tailleErreur);
char tabErreur[tailleErreur+1];
char*erreur = tabErreur;
glGetShaderInfoLog(couleur, tailleErreur, &tailleErreur, erreur);
erreur[tailleErreur] = '\0';
glDeleteShader(couleur);
return false;
}

// les 2 shaders sont compilés et prêt !
program = glCreateProgram();
glAttachShader(program, vertex);
glAttachShader(program, couleur);
//glBindAttribLocation(program, 2, "in_TexCoord0");
glLinkProgram(program);
GLint erreur2(0);
glGetProgramiv(program, GL_LINK_STATUS, &erreur2);
if(erreur2 != GL_TRUE)
{
GLint tailleErreur(0);
glGetProgramiv(program, GL_INFO_LOG_LENGTH, &tailleErreur);
char tabErreur[tailleErreur+1];
char*pointeur=tabErreur;
glGetShaderInfoLog(program, tailleErreur, &tailleErreur, pointeur);
pointeur[tailleErreur] = '\0';
glDeleteProgram(program);
return false;
}
glDeleteShader(vertex);
glDeleteShader(couleur);
}
Affichage2::~Affichage2()
{
glDeleteProgram(program);
}
GLuint Affichage2::getProgram()
{
return program;
}

point::point()
{
    X=0;
    Y=0;
    Z=0;
}

point::point(double X2, double Y2, double Z2)
{
    X = X2;
    Y = Y2;
    Z = Z2;
}
double point::getX ()
{
    return X;
}
double point::getY()
{
    return Y;
}
double point::getZ()
{
    return Z;
}
void point::setX (double nombre)
{
X = nombre;
}
void point::setY(double nombre)
{
    Y = nombre;
}
void point::setZ(double nombre)
{
    Z = nombre;
}
point& point::operator+= (point valeur)
{
X += valeur.X;
Y += valeur.Y;
Z += valeur.Z;
return *this;
}
void point::afficher()
{
std::cout << "point" << std::endl << "X : " << X << std::endl << "Y : " <<Y<< std::endl << "Z : " << Z << std::endl;
}
anglePts point::calculAngles()
{
double adj;
double opp;
double hyp;
double angle;
adj = X;
opp = Z;
hyp = sqrt(double(adj * adj) + double(opp * opp));
angle = acos(adj/hyp) * 180/3.14159265358979323846;
if(adj < 0 && opp <0)
{
angle = 180 - angle;
angle += 180;
}
else if(adj > 0 && opp <0)
{
angle = 90 - angle;
angle += 270;
}


double adj2;
double opp2;
double angle2;
double hyp2;
opp2 = Y;
hyp2 = sqrt(double (hyp * hyp) + double(opp2*opp2));
angle2 = asin(opp2/hyp2)*180/3.14159265358979323846;

return anglePts(angle, angle2, 0, hyp2, 0);
}
void point::calculPoint(anglePts angles)
{
double X3 = cos(angles.angleY * 3.14159265358979323846/180) * angles.longueur1;
double Z3 = cos(angles.angleY * 3.14159265358979323846/180) * angles.longueur1;
double Y3 = sin(angles.angleY *3.14159265358979323846/180) * angles.longueur1;

X3 *= cos(angles.angleX * 3.14159265358979323846/180);
Z3 *= sin(angles.angleX * 3.14159265358979323846/180);
X = X3;
Y = Y3;
Z = Z3;
}
anglePts::anglePts(double a, double b, double c, double d, double e)
{
   angleX =a;
   angleY =b;
   angleZ =c;
   longueur1 =d;
   longueur2 =e;
}
anglePts::anglePts()
{
    angleX =0;
   angleY =0;
   angleZ =0;
   longueur1 =0;
   longueur2 =0;
}
void anglePts::setX(double a)
{
angleX = a;
}
void anglePts::setY(double a)
{
angleY = a;
}
double anglePts::getX()
{
return angleX;
}
double anglePts::getY()
{
return angleY;
}

affichage::affichage()
{
textures = false;
}
bool affichage::chargerFichier(std::string obj, bool mtl, bool positionnements, std::string MTL)
{
std::vector<std::vector<forme> > formes;
textures = false;
std::vector<point> conteneurVertices;
std::vector<point> conteneurNormales;
std::vector<textureC> conteneurTextures;
std::ifstream fichier (obj.c_str(), std::ios::in | std::ios::binary);
if(!fichier)
{
return false;
}
int8_t caractere(0);
fichier.seekg (0, std::ios::end);
uint32_t taille = fichier.tellg();
fichier.seekg(0, std::ios::beg);
bool continuer (true);

// saut de ligne 10
while(continuer)
{
//++position;
//caractere = tableau[position];
fichier.read((char*)&caractere, 1);
if(caractere == int8_t('v'))
{
    //++position;
    //caractere = tableau[position];
    fichier.read((char*)&caractere, 1);
    if(caractere == 'n')
    {
// normale
std::string x;
std::string y;
std::string z;
unsigned int situation(0);
bool continuer2(true);
while (continuer2)
{
    //++position;
    //caractere = tableau[position];
    fichier.read((char*)&caractere, 1);
    if(caractere != ' ' && caractere != 10)
    {
    if(situation == 0)
    x.push_back(char(caractere));
    else if(situation == 1)
    y.push_back(char(caractere));
    else if(situation == 2)
    z.push_back(char(caractere));
    }
    else if (caractere == ' ')
    {
    ++situation;
    }
    else if (caractere == 10)
    {
    continuer2 = false;
    }
}
std::istringstream flux0(x);
std::istringstream flux1(y);
std::istringstream flux2(z);
double px(0);
double py(0);
double pz(0);
flux0 >> px;
flux1 >> py;
flux2 >> pz;

conteneurNormales.push_back(point(px,py,pz));

    }
    else if (caractere == 't')
    {
// texture
std::string x;
std::string y;
std::string z;
unsigned int situation(0);
bool continuer2(true);
while (continuer2)
{
    //++position;
    //caractere = tableau[position];
    fichier.read((char*)&caractere, 1);
    if(caractere != ' ' && caractere != 10)
    {
    if(situation == 0)
    x.push_back(char(caractere));
    else if(situation == 1)
    y.push_back(char(caractere));
    }
    else if (caractere == ' ')
    {
    ++situation;
    }
    else if (caractere == 10)
    {
    continuer2 = false;
    }
}
std::istringstream flux0(x);
std::istringstream flux1(y);
double tx(0);
double ty(0);
flux0 >> tx;
flux1 >> ty;


conteneurTextures.push_back(textureC(tx,ty)); // textureC a faire !!!!!!!!!!!!!!!
    }
    else if (caractere == ' ')
    {
//vertex
std::string x;
std::string y;
std::string z;
unsigned int situation(0);
bool continuer2(true);
while (continuer2)
{
    //++position;
    //caractere = tableau[position];
    fichier.read((char*)&caractere, 1);
    if(caractere != ' ' && caractere != 10)
    {
    if(situation == 0)
    x.push_back(char(caractere));
    else if(situation == 1)
    y.push_back(char(caractere));
    else if(situation == 2)
    z.push_back(char(caractere));
    }
    else if (caractere == ' ')
    {
    ++situation;
    }
    else if (caractere == 10)
    {
    continuer2 = false;
    }
}

std::istringstream flux0(x);
std::istringstream flux1(y);
std::istringstream flux2(z);
double px(0);
double py(0);
double pz(0);
flux0 >> px;
flux1 >> py;
flux2 >> pz;

conteneurVertices.push_back(point(px,py,pz));
    }
    else
    {
bool continuer2(true);
while(continuer2)
{

fichier.read((char*)&caractere, 1);
if(caractere == 10)
continuer2=false;
}
    }
}
else if(caractere == '#')
{
bool continuer2(true);
while(continuer2)
{
//++position;
//if(tableau[position] == 10)
fichier.read((char*)&caractere, 1);
if(caractere == 10)
continuer2=false;
}
}
else if (caractere == 'f')
{
unsigned int etape(0);
//++position;

fichier.seekg(1, std::ios::cur);
std::vector <std::string> vertices;
std::vector <std::string> textures;
std::vector <std::string> normales;
bool continuer2=true;


vertices.push_back(std::string());
textures.push_back(std::string());
normales.push_back(std::string());
while(continuer2)
{
//++position;
//caractere = tableau[position];
fichier.read((char*)&caractere, 1);
if(caractere == '/')
{
++etape; // mini-etape
}
else if (caractere == ' ')
{
etape = 0;
vertices.push_back(std::string());
textures.push_back(std::string());
normales.push_back(std::string());
}
else if(caractere == 10)
continuer2=false;
else
{
if(etape == 0)
{
vertices[vertices.size() - 1 ] += caractere;
}
else if (etape == 1)
{
textures[textures.size() - 1 ] += caractere;
}
else if (etape == 2)
{
normales[normales.size() - 1 ] += caractere;
}
}
if(fichier.tellg()>= taille)
 {continuer2 = false;
  continuer = false;
 }

}
bool texture;
if(textures[0].size() > 0)
texture = true;
else
texture = false;
formes[formes.size()-1].push_back(forme()); // formes dans la classe | après la boucle.
// pour remplacerles atof :
/*std::istringstream flux ();
flux >> double (ou int);*/
if(texture)
{
for(unsigned int quantite(0); quantite < vertices.size(); ++quantite) // ...
{
std::istringstream flux0(vertices[quantite]);
std::istringstream flux1(normales[quantite]);
std::istringstream flux2(textures[quantite]);
int ver(0);
int nor(0);
int tex(0);
flux0 >> ver;
flux1 >> nor;
flux2 >> tex;
formes[formes.size()-1][formes[formes.size()-1].size() - 1].push(conteneurVertices[ver-1], conteneurNormales[nor-1], conteneurTextures[tex-1]); // refaire pour chaque quantitée dans les vectors.
}
}
else
{
for(unsigned int quantite(0); quantite < vertices.size(); ++quantite) // ...
{
std::istringstream flux0(vertices[quantite]);
std::istringstream flux1(normales[quantite]);
int ver(0);
int nor(0);
flux0 >> ver;
flux1 >> nor;
formes[formes.size()-1][formes[formes.size()-1].size() - 1].push(conteneurVertices[ver-1], conteneurNormales[nor-1]); // refaire pour chaque quantitée dans les vectors.
}
}
}
else if (caractere == 'o')
{
formes.push_back(std::vector<forme>());
bool continuer2(true);
while(continuer2)
{
//++position;
//if(tableau[position] == 10)
fichier.read((char*)&caractere, 1);
if(caractere == 10)
continuer2=false;
}
}
else if (caractere == 'u')
{
fichier.read((char*)&caractere, 1);
if(caractere == 's')
{
fichier.read((char*)&caractere, 1);
if(caractere == 'e')
{fichier.read((char*)&caractere, 1);
if(caractere == 'm')
{
fichier.read((char*)&caractere, 1);
if(caractere == 't')
{
fichier.read((char*)&caractere, 1);
if(caractere == 'l')
{
fichier.seekg(1, std::ios::cur);
fichier.read((char*)&caractere, 1);
std::string nomMtl;
while(caractere != 10)
{
nomMtl.push_back(caractere);
fichier.read((char*)&caractere, 1);
}
if(materiaux.size() > 0)
{
bool dejaExistant(true);
for(unsigned int nombre(0); nombre < materiaux.size(); ++nombre)
{
if(materiaux[nombre].nom == nomMtl)
dejaExistant=false;
}
if(dejaExistant)
{
materiaux.push_back(materiel());
materiaux[materiaux.size()-1].nom = nomMtl;
materiaux[materiaux.size()-1].nombre.push_back(formes.size());
}
}
else
{
materiaux.push_back(materiel());
materiaux[materiaux.size()-1].nom = nomMtl;
materiaux[materiaux.size()-1].nombre.push_back(formes.size());
}
}
}
}
}
}
}
else
{
bool continuer2(true);
while(continuer2)
{
//++position;
//if(tableau[position] == 10)
fichier.read((char*)&caractere, 1);
if(caractere == 10)
continuer2=false;
}
}
if(fichier.tellg() >= taille)
continuer = false;
}



















if(positionnements)
// replacement
{for(unsigned int nombreVector(0); nombreVector < formes.size(); ++nombreVector)
{

double xsup(formes[nombreVector][0].getVertices(0).getX());
double xinf(formes[nombreVector][0].getVertices(0).getX());
double ysup(formes[nombreVector][0].getVertices(0).getY());
double yinf(formes[nombreVector][0].getVertices(0).getY());
double zsup(formes[nombreVector][0].getVertices(0).getZ());
double zinf(formes[nombreVector][0].getVertices(0).getZ());
for(uint32_t nombre(0); nombre < formes[nombreVector].size(); ++nombre) // ya un bug la dedans
{

for(uint32_t nombre2(0); nombre2 < formes[nombreVector][nombre].getNbVertices(); ++nombre2) // condition pour l'accès à tous les vertices.
{

point verifPts = formes[nombreVector][nombre].getVertices(nombre2);

if(verifPts.getX() < xinf)
{
xinf = verifPts.getX();
}
if(verifPts.getX() > xsup)
{
xsup = verifPts.getX();
}
if(verifPts.getY() < yinf)
{
yinf = verifPts.getY();
}
if(verifPts.getY() > ysup)
{
ysup = verifPts.getY();
}
if(verifPts.getZ() < zinf)
{
zinf = verifPts.getZ();
}
if(verifPts.getZ() > zsup)
{
zsup= verifPts.getZ();
}
}}
point positionnement;
positionnement.setX(double(xsup+xinf)/2);
positionnement.setY(double(ysup+yinf)/2);
positionnement.setZ(double(zsup+zinf)/2);


for(uint32_t nombre(0); nombre < formes[nombreVector].size(); ++nombre)
{
formes[nombreVector][nombre].addition(positionnement);
}}

}














double nombreTriangles(0);
double nombreQuads(0);










/*std::cout << "premier point : " << std::endl;
formes[0][0].getVertices(0).afficher();*/
//communication des données
for(unsigned int nombre(0); nombre < formes.size(); ++nombre)
{
elements.push_back(element());

for(unsigned int nombre2(0); nombre2<formes[nombre].size(); ++nombre2)
{
std::vector<float> vertices;
//remplissage
for(unsigned int nombre3(0); nombre3 < formes[nombre][nombre2].getNbVertices(); ++nombre3)
{
point envoi = formes[nombre][nombre2].getVertices(nombre3);
vertices.push_back(envoi.getX());
vertices.push_back(envoi.getY());
vertices.push_back(envoi.getZ());
}
if(vertices.size() == 9)
{elements[nombre].pushTriangle(vertices);
++nombreTriangles;
}
else if (vertices.size() == 12)
{elements[nombre].pushRectangle(vertices);
++nombreQuads;}
/*else
elements[nombre].pushPolygone(vertices, couleurs);*/
vertices.clear();

}
}

















if(mtl)
{
unsigned int position(0);
std::ifstream fichier2 (MTL.c_str(), std::ios::in | std::ios::binary);
if(fichier2)
{
int8_t caractere(0);
fichier2.seekg (0, std::ios::end);
uint32_t taille = fichier2.tellg();
fichier2.seekg(0, std::ios::beg);
bool continuer (true);

// saut de ligne 10
unsigned int identifiantMtl(0);
while(continuer)
{
++position;
//caractere = tableau[position];
fichier2.read((char*)&caractere, 1);
if(caractere == int8_t('K'))
{
    ++position;
    //caractere = tableau[position];
    fichier.read((char*)&caractere, 1);
    if(caractere == 'd')
    {
// normale
std::string x;
std::string y;
std::string z;
unsigned int situation(0);
bool continuer2(true);
unsigned int identifiantMateriel(0);
while (continuer2)
{
    ++position;
    //caractere = tableau[position];
    fichier.read((char*)&caractere, 1);
    if(caractere != ' ' && caractere != 10)
    {
    if(situation == 0)
    x.push_back(char(caractere));
    else if(situation == 1)
    y.push_back(char(caractere));
    else if(situation == 2)
    z.push_back(char(caractere));
    }
    else if (caractere == ' ')
    {
    ++situation;
    }
    else if (caractere == 10)
    {
    continuer2 = false;
    }
}
std::istringstream flux0(x);
std::istringstream flux1(y);
std::istringstream flux2(z);
double px(0);
double py(0);
double pz(0);
flux0 >> px;
flux1 >> py;
flux2 >> pz;

materiaux[identifiantMtl].couleurs = point(px, py, pz);

    }
    else if (caractere == 'a')
    {bool continuer2(true);
while(continuer2)
{

fichier.read((char*)&caractere, 1);
if(caractere == 10)
continuer2=false;
}
    }
    else if (caractere == 's')
    {bool continuer2(true);
while(continuer2)
{

fichier.read((char*)&caractere, 1);
if(caractere == 10)
continuer2=false;
}
    }
    else
    {
bool continuer2(true);
while(continuer2)
{

fichier.read((char*)&caractere, 1);
if(caractere == 10)
continuer2=false;
}
    }
}
else if(caractere == '#')
{
bool continuer2(true);
while(continuer2)
{
//++position;
//if(tableau[position] == 10)
fichier.read((char*)&caractere, 1);
if(caractere == 10)
continuer2=false;
}
}
else if(caractere == 'n')
{
fichier.read((char*)&caractere, 1);
if(caractere == 'e')
{fichier.read((char*)&caractere, 1);
if(caractere == 'w')
{
    fichier.read((char*)&caractere, 1);
    if(caractere == 'm')
    {
        fichier.read((char*)&caractere, 1);
        if(caractere == 't')
        {
            fichier.read((char*)&caractere, 1);
            if(caractere == 'l')
            {
            fichier.seekg(1, std::ios::cur);
fichier.read((char*)&caractere, 1);
std::string nomMtl;
while(caractere != 10)
{
nomMtl.push_back(caractere);
fichier.read((char*)&caractere, 1);
}
bool running(true);
for(unsigned int nombre(0); nombre < materiaux.size() && running; ++nombre)
{
if(nomMtl == materiaux[nombre].nom)
{
running = false;
identifiantMtl = nombre;
}
}
            }
        }
    }
}
}



}
else
{
bool continuer2(true);
while(continuer2)
{
//++position;
//if(tableau[position] == 10)
fichier.read((char*)&caractere, 1);
if(caractere == 10)
continuer2=false;
}
}
if(fichier2.tellg() >=taille)
continuer = false;
}
fichier2.close();
std::vector<point> ordreMateriaux;
std::vector<unsigned int> nombres;
std::vector<point> ordreMateriaux2;
std::deque<unsigned int> nombres2;
int plusPetit(-1);
unsigned int nombre2(0);
for(unsigned int nombre(0); nombre <materiaux.size(); ++nombre)
{
for(unsigned int nombre2(0); nombre2 < materiaux[nombre].nombre.size(); ++nombre2)
{
nombres.push_back(materiaux[nombre].nombre[nombre2]);
ordreMateriaux.push_back(materiaux[nombre].couleurs);
}
}
std::vector<std::vector<std::vector<float> > >floatCouleurs;
std::vector<unsigned int> plusGrandQue;
for(unsigned int nombre(0); nombre < ordreMateriaux.size(); ++nombre)
{
unsigned int nombre3(0);
for(unsigned int nombre4(0); nombre4<ordreMateriaux.size(); ++nombre4)
{
if(nombres[nombre4] > plusPetit)
plusGrandQue.push_back(nombres[nombre4]);
}
nombre3=plusGrandQue[0];
for(unsigned int nombre4(0); nombre4 < plusGrandQue.size(); ++nombre)
{
if(nombre3 > plusGrandQue[nombre4])
{
nombre3 = plusGrandQue[nombre4];
}
}
plusPetit = nombre3;
ordreMateriaux2.push_back(ordreMateriaux[nombre3]);
nombres2.push_back(nombre3);
}
//ordreMateriaux2 : les couleurs
//nombres2 : les endroits
unsigned int cible(0);
unsigned int compteur(0);
for(unsigned int nombre(0); nombre < formes.size(); ++nombre)
{
floatCouleurs.push_back(std::vector<std::vector<float> >());
for(unsigned int nombre2(0); nombre < formes[nombre].size(); ++nombre)
{
floatCouleurs[nombre].push_back(std::vector<float>());
for(unsigned int nombre3(0); nombre3 < formes[nombre][nombre3].getNbVertices(); ++nombre3)
{
if(compteur >= nombres2[0] && nombres2.size() > 0)
{
cible = nombres2[0];
nombres2.pop_front();
}
floatCouleurs[nombre][nombre2].push_back(ordreMateriaux2[cible].getX());
floatCouleurs[nombre][nombre2].push_back(ordreMateriaux2[cible].getY());
floatCouleurs[nombre][nombre2].push_back(ordreMateriaux2[cible].getZ());
++compteur;
}
}}


///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
///################################################################################################################
}
else
return false;}



















// nombre = vector principal
/* bientôt disponible
std::vector<unsigned int> numerosTriangles;
std::vector<unsigned int> numerosRectangles;
std::vector<unsigned int> numerosPolygones;
for(unsigned int nombre2; nombre2 < formes[nombre].size(); ++nombre2)
{
if(formes[nombre][nombre2].getNbVertices() == 3)
numerosTriangles.push_back(nombre2);
else if (formes[nombre][nombre2].getnbVertices() == 4)
numerosRectangles.push_back(nombre2);
else if (formes[nombre)[nombre2].getNbVertices() > 4)
numerosPolygones.push_back(nombre2);
}
*/





fichier.close();

return true;
}
textureC::textureC(double x, double y)
{
    a = x;
    b = y;
}
double textureC::getX()
{
return a;
}
double textureC::getY()
{
return b;
}
//forme
//3 vector + fonction dessiner
//+ 1 vector multiplié par le nombre de couleurs possibles
//pour les matériaux, donner la couleur
forme::forme()
{
textures = false;
}
void forme::vider()
{
vertices.clear();
normales.clear();
conteneurTextures.clear();
couleurs.clear();
}
void forme::dessiner(anglePts Angles, point Position)
{
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

textures = false;
if(vertices.size() == 4)
glBegin(GL_QUADS);
else if(vertices.size() == 3)
glBegin(GL_TRIANGLES);
else if (vertices.size() >= 4)
glBegin(GL_POLYGON);

if(textures)
{
for(unsigned int nombre(0); nombre < vertices.size(); ++nombre)
{glTexCoord2d(conteneurTextures[nombre].getX(), conteneurTextures[nombre].getY());
 glVertex3d(vertices[nombre].getX(), vertices[nombre].getY(), vertices[nombre].getZ());
}
}
else
{
for(unsigned int nombre(0); nombre < vertices.size(); ++nombre)
{
/*point affichagePts = vertices[nombre];
double angleY(0);
double hypotenuse = sqrt(double(affichagePts.getX()*affichagePts.getX())+double(affichagePts.getY()*affichagePts.getY()));
double sinus =affichagePts.getY()/hypotenuse;
double cosinus =affichagePts.getX()/hypotenuse;
angleY = asin(sinus)*180/M_PI;

if(affichagePts.getX() > 0)
{
angleY = 180-angleY;
}
affichagePts.setY(sin(double(angleY+ Angles.angleY)*M_PI/180)*hypotenuse);
affichagePts.setX(cos(double(angleY+ Angles.angleY)*M_PI/180)*hypotenuse);


double angleX(0);
double hypotenuse2 = sqrt(double(affichagePts.getZ()*affichagePts.getZ())+double(affichagePts.getX()*affichagePts.getX()));
double cosinus2 =affichagePts.getZ()/hypotenuse2;
double sinus2 =affichagePts.getX()/hypotenuse2;
angleX = acos(cosinus2)*180/M_PI;
if(affichagePts.getZ() < 0 && affichagePts.getX() <0)
{
angleX = 180 - angleX;
angleX += 180;
}
else if(affichagePts.getZ() > 0 && affichagePts.getX() <0)
{
angleX = 90 - angleX;
angleX += 270;
}

affichagePts.setX(sin(double(angleX+ Angles.angleX)*M_PI/180)*hypotenuse2);
affichagePts.setZ(cos(double(angleX+ Angles.angleX)*M_PI/180)*hypotenuse2);
affichagePts.setY(affichagePts.getY() + Position.getY());
affichagePts.setZ(affichagePts.getZ() + Position.getZ());
affichagePts.setX(affichagePts.getX() + Position.getX());*/

glColor3ub(couleurs[nombre].getX(), couleurs[nombre].getY(), couleurs[nombre].getZ());
glVertex3d(vertices[nombre].getX(), vertices[nombre].getY(), vertices[nombre].getZ());

}
}

glEnd();
}
void forme::setAngles(anglePts angles)
{
Angles = angles;
}
void forme::setPositon (point position)
{
Position = position;
}
void forme::setColor(point Couleur, unsigned int nombre)
{
couleurs[nombre] = Couleur;
}
point forme::getVertices(unsigned int nombre)
{
return vertices[nombre];
}
void forme::addition(point valeur)
{
for(unsigned int nombre(0); nombre < vertices.size(); ++nombre)
{

vertices[nombre].setX(vertices[nombre].getX() - valeur.getX());
vertices[nombre].setY(vertices[nombre].getY() - valeur.getY());
vertices[nombre].setZ(vertices[nombre].getZ() - valeur.getZ());
}

}
int forme::getNbVertices()
{
return vertices.size();
}
void affichage::replacer()/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{}
double affichage::distance(point a)
{
double distanceXZ = sqrt(double(a.getX()*a.getX()) + double(a.getZ()*a.getZ()));
return sqrt(distanceXZ + double(a.getY() * a.getY()));
}
void forme::push(point ver, point nor, textureC tex)
{
vertices.push_back(ver);
normales.push_back(nor);
conteneurTextures.push_back(tex);
}
void forme::push(point ver, point nor)
{
vertices.push_back(ver);
normales.push_back(nor);
textures = false;
}
void affichage::afficher(uint8_t nombre,char *color, bool couleur)
{
elements[nombre].dessiner(color, couleur);
/*glRotated(-Angles.angleY, 0, 0, 1);
glRotated(-Angles.angleX, 0, 1, 0);
glTranslated(-Position.getX(), -Position.getY(), -Position.getZ());*/
}
point forme::calculerPoint(anglePts angles)
{
double X3 = cos(angles.angleY * 3.14159265358979323846/180) * angles.longueur1;
double Z3 = cos(angles.angleY * 3.14159265358979323846/180) * angles.longueur1;
double Y3 = sin(angles.angleY * 3.14159265358979323846/180) * angles.longueur1;

X3 *= cos(angles.angleX * 3.14159265358979323846/180);
Z3 *= sin(angles.angleX * 3.14159265358979323846/180);
return point (X3, Y3, Z3);
}


point forme::getNormale(unsigned int nombre)
{
return normales[nombre];
}
bool forme::texture()
{
if(conteneurTextures.size() > 0)
return true;
else
return false;
}
textureC forme::getTexture(unsigned int nombre)
{
return conteneurTextures[nombre];
}
element::element()
{
char couleur = 'r';
int utilisation= 0;
int nombresTableaux = 0;
identifiantVBO = 0;
triangles.clear();
couleursTriangles.clear();
couleursTriangle2.clear();
couleursTriangles3.clear();
Couleur = false;
mtl = false;
}//rouge vert bleu
void element::envoieCouleurs(std::vector<float> colors)
{
couleursTriangles.clear();
for(unsigned int nombre(0); nombre < colors.size(); ++nombre)
couleursTriangles.push_back(colors[nombre]);
}
void element::charger()
{
mtl = true;
glGenBuffers(1, &identifiantVBO2);
glBindBuffer(GL_ARRAY_BUFFER, identifiantVBO2);
std::vector<float> envoi;
for(unsigned int nombre(0); nombre < triangles.size(); ++nombre)
envoi.push_back(triangles[nombre]);
for(unsigned int nombre(0); nombre < triangles.size(); ++nombre)
envoi.push_back(couleursTriangles4[nombre]);
double taille(0);
taille = envoi.size() * sizeof(float);
glBufferData(GL_ARRAY_BUFFER, taille,envoi.data(), GL_STATIC_DRAW);
//void *adresseVBO = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void element::charger2()
{
definirCouleurs();
Couleur = true;

glGenBuffers(1, &identifiantVBO);
glBindBuffer(GL_ARRAY_BUFFER, identifiantVBO);
std::vector<float> envoi;
for(unsigned int nombre(0); nombre < triangles.size(); ++nombre)
envoi.push_back(triangles[nombre]);
for(unsigned int nombre(0); nombre < triangles.size(); ++nombre)
envoi.push_back(couleursTriangles[nombre]);
for(unsigned int nombre(0); nombre < triangles.size(); ++nombre)
envoi.push_back(couleursTriangle2[nombre]);
for(unsigned int nombre(0); nombre < triangles.size(); ++nombre)
envoi.push_back(couleursTriangles3[nombre]);
double taille(0);
taille = envoi.size() * sizeof(float);
glBufferData(GL_ARRAY_BUFFER, taille,envoi.data(), GL_STATIC_DRAW);
//void *adresseVBO = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void element::dessiner(char *color, bool couleurs)
{//refaire les offsets
if(couleurs && Couleur)
{unsigned int offset(triangles.size()*sizeof(float));
glBindBuffer(GL_ARRAY_BUFFER, identifiantVBO);

glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,BUFFER_OFFSET(0));
if(*color == 'r')
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0,BUFFER_OFFSET(offset));
else if(*color == 'v')
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0,BUFFER_OFFSET(offset*2));
else if(*color == 'b')
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0,BUFFER_OFFSET(offset*3));

glEnableVertexAttribArray(0);
glEnableVertexAttribArray(1);

glDrawArrays(GL_TRIANGLES, 0, triangles.size()/3);
glDisableVertexAttribArray(1);
glDisableVertexAttribArray(0);glBindBuffer(GL_ARRAY_BUFFER, 0);
}
else if(mtl&&couleurs==false)
{

unsigned int offset(triangles.size()*sizeof(float));
glBindBuffer(GL_ARRAY_BUFFER, identifiantVBO2);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,BUFFER_OFFSET(0));
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0,BUFFER_OFFSET(offset));
glEnableVertexAttribArray(0);
glEnableVertexAttribArray(1);
glDrawArrays(GL_TRIANGLES, 0, triangles.size()/3);
glDisableVertexAttribArray(1);
glDisableVertexAttribArray(0);
glBindBuffer(GL_ARRAY_BUFFER, 0);
}
}
void element::pushTriangle(std::vector<float> points)
{
for(unsigned int nombre(0); nombre < 9; ++nombre)
triangles.push_back(points[nombre]);
}
void element::pushRectangle(std::vector<float> points)
{
triangles.push_back(points[0]);
triangles.push_back(points[1]);
triangles.push_back(points[2]);
triangles.push_back(points[3]);
triangles.push_back(points[4]);
triangles.push_back(points[5]);
triangles.push_back(points[6]);
triangles.push_back(points[7]);
triangles.push_back(points[8]);
triangles.push_back(points[6]);
triangles.push_back(points[7]);
triangles.push_back(points[8]);
triangles.push_back(points[9]);
triangles.push_back(points[10]);
triangles.push_back(points[11]);
triangles.push_back(points[0]);
triangles.push_back(points[1]);
triangles.push_back(points[2]);
}
element::~element()
{
glDeleteBuffers(1, &identifiantVBO);
}
point forme::getColor(unsigned int nombre)
{
return couleurs[nombre];
}
void forme::pushColor(point color)
{
couleurs.push_back (color);
}
void affichage::charger(unsigned int nombre)
{
elements[nombre].charger();
}
void affichage::charger2(unsigned int nombre)
{
elements[nombre].charger2();
}
float element::distance(point a)
{
float distanceXZ = sqrt(float(a.getX()*a.getX()) + float(a.getZ()*a.getZ()));
return sqrt(distanceXZ + float(a.getY() * a.getY()));
}
void element::definirCouleurs()
{
couleursTriangles.clear();
couleursTriangle2.clear();
couleursTriangles3.clear();


point minimum = point(triangles[0],triangles[1],triangles[2]);
point maximum = point(triangles[0],triangles[1],triangles[2]);
float distanceMinimum(distance(minimum));
float distanceMaximum(distance(maximum));
for(unsigned int nombre(0); nombre < triangles.size(); nombre+=3)
{

float testDistance = distance(point(triangles[nombre],triangles[nombre+1],triangles[nombre+2]));
if(distanceMinimum > testDistance)
{
distanceMinimum = testDistance;
}
if(distanceMaximum < testDistance)
{
distanceMaximum = testDistance;
}
}

for(unsigned int nombre(0); nombre < triangles.size(); nombre+=3)
{
point testPoint = point(triangles[nombre],triangles[nombre+1],triangles[nombre+2]);
float distancePts = distance(testPoint);
distancePts-=distanceMinimum;
float pourcentage = distanceMaximum - distanceMinimum;
distancePts/=pourcentage;
float intensite = 1 - distancePts; // j'ai inversé
intensite *= 105;
intensite += 55;
intensite/=255;
couleursTriangles.push_back(intensite);
couleursTriangles.push_back(0);
couleursTriangles.push_back(0);
couleursTriangle2.push_back(0);
couleursTriangle2.push_back(intensite);
couleursTriangle2.push_back(0);
couleursTriangles3.push_back(0);
couleursTriangles3.push_back(0);
couleursTriangles3.push_back(intensite);
}


}
unsigned int element::getNombreTriangles()
{
return triangles.size()/3;
}
void affichage::definirCouleur(unsigned int nombre)
{
elements[nombre].definirCouleurs();
}
materiel::materiel()
{

}
void element::pushTriangleC(std::vector<float> points)
{
couleursTriangles4.push_back(points[0]);
couleursTriangles4.push_back(points[1]);couleursTriangles4.push_back(points[2]);
}
void element::pushRectangleC(std::vector<float> points)
{
couleursTriangles4.push_back(points[0]);
couleursTriangles4.push_back(points[1]);
couleursTriangles4.push_back(points[2]);
couleursTriangles4.push_back(points[3]);
couleursTriangles4.push_back(points[4]);
couleursTriangles4.push_back(points[5]);
couleursTriangles4.push_back(points[6]);
couleursTriangles4.push_back(points[7]);
couleursTriangles4.push_back(points[8]);
couleursTriangles4.push_back(points[6]);
couleursTriangles4.push_back(points[7]);
couleursTriangles4.push_back(points[8]);
couleursTriangles4.push_back(points[9]);
couleursTriangles4.push_back(points[10]);
couleursTriangles4.push_back(points[11]);
couleursTriangles4.push_back(points[0]);
couleursTriangles4.push_back(points[1]);
couleursTriangles4.push_back(points[2]);
}
