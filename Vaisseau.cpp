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
SOFTWARE.*/#include "Vaisseau.h"
joueur::joueur()
{
vitesse = 0;
axeX = 1;
axeY = 1;
gaz = 0;
angleX = 0;
angleY = 0;
vitesseMax = 0;
guilde = 0;
empire= 0 ;
id = 0;
level = 0;
couleur = 0;
modele = 0;
}
joueur::joueur(char Modele, anglePts Angles, affichage*Modelisation, point Position, char Couleur, std::string Pseudo, int Level, int ID)
{

modele = Modele;
setAngles(Angles);
modelisation = Modelisation;
setPosition(Position);
couleur = Couleur;
pseudo = Pseudo;
level = Level;
id = ID;
if(modele == 0)
{
//collision.initialiser(3.5, 3.5, 7.5);
//collision.setPosition(Position);
//collision.placer(angles.angleX, angles.angleY, 0);
}
}
void joueur::setPosition(point Position)
{
position = Position;
//collision.setPosition(Position);
//collision.placer(angles.angleX, angles.angleY, 0);
}
void joueur::setAngles(anglePts Angles)
{
angles = Angles;
//collision.placer(Angles.angleX, Angles.angleY, 0);
}
anglePts joueur::getAngles()
{
return angles;
}
void joueur::update()
{
        if(vitesse == 0 && gaz == 0)
        {

        }
        else if (vitesse == vitesseMax && gaz == 1)
        {

        }
        else
        {
            if(gaz == 0)
            {
                vitesse-=0.1;
            }
            else
            {
                vitesse+=0.1;
            }
            if(vitesse > vitesseMax)
            {
                vitesse = vitesseMax;
            }
            else if (vitesse <0)
            {
                vitesse = 0;
            }
        }
        if(axeX == 0)
        {
           angleX-=4;
        }
        else if (axeX == 2)
        {
            angleX+=4;
        }
        if(axeY == 0)
        {
            angleY-=4;
        }
        else if (axeY == 2)
        {
            angleY+=4;
        }
        /*if(angleX < 0)
            angleX = 360 + angleX;
        else if(angleX > 360)
            angleX = 360-angleX;
        if(angleY < 0)
            angleY = 360 + angleY;
        else if(angleY > 360)
            angleY = 360-angleY;*/
            angleX%=360;
            angleY%=360;
update2();
}
void joueur::update2()
{
point position2 = actualiserPosition();
position.setX(position.getX() + position2.getX());
position.setY(position.getY() + position2.getY());
position.setZ(position.getZ() + position2.getZ());

if(position.getX() > 250)
{
position.setX(-250);
}
else if (position.getX() < -250)
{
position.setX(250);
}
            if(position.getY() > 250)
            {
            position.setY(250);
            }
            else if (position.getY() < -250)
            {
            position.setY(-250);
            }
            if(position.getZ() > 250)
            {
            position.setZ(-250);
            }
            else if (position.getZ() < -250)
            {
            position.setZ(250);
            }

}
void joueur::afficher(glm::mat4 modelview, glm::mat4 projection,GLuint program)
{

float angle_X = 360-angleX;
float angle_Y = 360-angleY;
angle_X += 180;
angle_X *= 3.14159265358979323846/180;
angle_Y *= 3.14159265358979323846/180;
/*modelview = glm::translate(modelview, glm::vec3(position.getX(), position.getY(), position.getZ()));
modelview = glm::rotate(modelview, angle_X, glm::vec3(0, 1, 0));
modelview = glm::rotate(modelview, angle_Y, glm::vec3(0, 0, 1));*/



modelview = glm::translate(modelview, glm::vec3(position.getX(), position.getY(), position.getZ()));
modelview = glm::rotate(modelview, angle_X, glm::vec3(0, 1, 0));
modelview = glm::rotate(modelview, angle_Y, glm::vec3(0, 0, 1));
glUniformMatrix4fv(glGetUniformLocation(program, "modelview"), 1, GL_FALSE,glm::value_ptr(modelview));
glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE,glm::value_ptr(projection));
if(modele == 0)
modelisation->afficher(0, &couleur, true);
modelview = glm::rotate(modelview, -angle_Y, glm::vec3(0, 0, 1));
modelview = glm::rotate(modelview, -angle_X, glm::vec3(0, 1, 0));

modelview = glm::translate(modelview, glm::vec3(-position.getX(), -position.getY(), -position.getZ()));
/*glUniformMatrix4fv(glGetUniformLocation(program, "modelview"), 1, GL_FALSE,glm::value_ptr(modelview));
glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE,glm::value_ptr(projection));
//collision.afficher();*/
}
point joueur::getPosition()
{
return position;
}
point joueur::calculAngle(point cible, double angle2)
{
//prendre l'angle du point
/*double adj;
double opp;
double hyp;
double angle;
adj = cible.getX();
opp = cible.getZ();
hyp = sqrt(double(adj * adj) + double(opp * opp));
angle = acos(adj/hyp) * 180/3.14159265358979323846;
if(adj < 0 && opp <0)
{
angle = 180 - angle;
angle += 180;
}*/
anglePts angleHorizontale = cible.calculAngles();
//std::cout << "angle : " << angleHorizontale.angleX << std::endl;
/*double angle = angleHorizontale.angleX;
angle-=angle2;
double hyp = angleHorizontale.longueur1;
point resultat;
resultat.setX(cos(angle*3.14159265358979323846/180)*hyp);
resultat.setZ(sin(angle*3.14159265358979323846/180)*hyp);*/
angleHorizontale.angleX-=angle2;
point resultat(0, 0,0);
resultat.calculPoint(angleHorizontale);
return resultat;
}
double joueur::distance(point a)
{
double distanceXZ = sqrt(double(a.getX()*a.getX()) + double(a.getZ()*a.getZ()));
return sqrt(distanceXZ + double(a.getY() * a.getY()));
}
void joueur::afficherPseudo(glm::mat4 modelview, glm::mat4 projection, GLuint program, sf::RenderWindow &fenetre, sf::Font &police)
{
fenetre.resetGLStates();
glm::vec4 matricePts(position.getX(),position.getY()+2,position.getZ(), 1.0f);
glm::vec4 resultat = projection * modelview * matricePts;
resultat /= resultat.w;

if (resultat.z > 0.0f)
{
sf::Text Texte;
Texte.setFont(police);
std::string pseudo2 = pseudo;
if(empire == 1)
{
pseudo2.push_back(10);
pseudo2 += "Revolution";
}
else if (empire == 2)
{
pseudo2.push_back(10);
pseudo2 += "Empire royal";
}
else if (empire == 3)
{
pseudo2.push_back(10);
pseudo2 += "Coalition";
}
else if (empire== 4)
{
pseudo2.push_back(10);
pseudo2 += "Capitale de l'univers";
}
else
{
pseudo2.push_back(10);
pseudo2 += "Aucun empire";
}
Texte.setString(pseudo2);
Texte.setCharacterSize(10);
Texte.setColor(sf::Color::White);
float nombre1 = resultat.x;
float nombre2 = resultat.y;
nombre1 *= 400;
nombre2 *= 300;
nombre1 += 400;
nombre2 += 300;
nombre2 = 600-nombre2;
unsigned int positionFinale = Texte.getCharacterSize();
positionFinale *= pseudo.size();
nombre1 -= positionFinale/2;
Texte.setPosition(sf::Vector2f(nombre1,nombre2));
fenetre.draw(Texte);
}
}
/*bool joueur::collisionBool(joueur &utilisateur)
{
if(collision.comparerR(utilisateur.getCube()))
return true;
return false;
}*/
/*cubeCol* joueur::getCube()
{
return &collision;
}*/
void joueur::miseAjour(point newPosition, uint16_t newAngleX, uint16_t newAngleY, uint8_t newGaz, uint8_t newAxeX, uint8_t newAxeY, float newVitesse)
{
if(newPosition.getX() > -251 && newPosition.getX() < 251 && newPosition.getY() > -251 && newPosition.getY() < 251 && newPosition.getZ() > -251 && newPosition.getZ() < 251)
{
position = newPosition;
}
if(newAngleX < 361)
{
angleX = newAngleX;
}
if(newAngleY < 361)
{
angleY = newAngleY;
}
if(newGaz == 0 || newGaz == 1)
{
gaz = newGaz;
}
if(newAxeX == 0 || newAxeX == 1 || newAxeX == 2 )
{
axeX = newAxeX;
}
if(newAxeY == 0 || newAxeY == 1 || newAxeY == 2 )
{
axeY = newAxeY;
}
if(newVitesse >= 0 && newVitesse <= vitesseMax)
{
vitesse = newVitesse;
}
}
void joueur::changerNavette(uint8_t newModele)
{
modele = newModele;
if(newModele == 0)
{
vitesseMax = 4;
}
}
point joueur::actualiserPosition()
{
double X3 = cos(angleY * 3.14159265358979323846/180) * vitesse;
double Z3 = cos(angleY * 3.14159265358979323846/180) * vitesse;
double Y3 = sin(angleY *3.14159265358979323846/180) * vitesse;

X3 *= cos(angleX * 3.14159265358979323846/180);
Z3 *= sin(angleX * 3.14159265358979323846/180);
return point(X3, Y3, Z3);
}
