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
SOFTWARE.*/#include <cmath>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstdio>
#include "windows.h"
#include <SFML/Network.hpp>
#include "affichage.h"
#include "Vaisseau.h"
#include <sys/time.h>
#include <chrono>
#include <list>
#ifndef BUFFER_OFFSET
#define BUFFER_OFFSET(offset) ((char*)NULL + (offset))
#endif
#include <queue>
#include "envoiSecurise2.h"
bool finDuThread(true);
void ThreadReseau()
{
std::chrono::time_point<std::chrono::system_clock> FPS;

while(finDuThread)
{

}
}
uint16_t identification(sf::RenderWindow *window, conversation*TCP, sf::Font *police, std::list<joueur>::iterator player, affichage *Vaisseau, bool &ok)
{
bool little;
        uint16_t nombre50(10);
    uint8_t *octet50(reinterpret_cast<uint8_t*>(&nombre50));
    if(octet50[1] == 10)
    {
little = false;
    }
    else
    {
little = true;
    }
bool versionOK(false);
sf::Texture connexion;
sf::Sprite connexion2;
connexion.loadFromFile("identification.png");
connexion2.setTexture(connexion);
connexion2.setPosition(sf::Vector2f(0, 0));
bool continuer(true);
sf::Text Pseudo;
sf::Text MotDePasse;
std::string pseudo2("Pseudo");
std::wstring motDePasse2(L"*****");
Pseudo.setFont(*police);
Pseudo.setCharacterSize(40);
Pseudo.setString(pseudo2);
Pseudo.setPosition(sf::Vector2f(300,288));
Pseudo.setColor(sf::Color::Red);
MotDePasse.setFont(*police);
MotDePasse.setCharacterSize(40);
MotDePasse.setString(motDePasse2);
MotDePasse.setPosition(sf::Vector2f(300,388));
MotDePasse.setColor(sf::Color::Black);
std::chrono::time_point<std::chrono::system_clock> limite;
int selection(0);
sf::Text acceptationContrat;
std::string contrat ("Copyright (c) 2015 Chapuis Paul");
contrat.push_back(10);
contrat.push_back(10);
contrat+="Ce logiciel est distribue sous licence MIT.";
acceptationContrat.setString(contrat);
acceptationContrat.setPosition(sf::Vector2f(0,0));
acceptationContrat.setCharacterSize(20);
acceptationContrat.setColor(sf::Color::Black);
acceptationContrat.setFont(*police);
float rapport1(1);
float rapport2(1);
std::string etat2("Etat : Aucunes tentatives.");
sf::Text etat;
etat.setFont(*police);
etat.setCharacterSize(40);
etat.setString(etat2);
etat.setPosition(sf::Vector2f(200,500));
etat.setColor(sf::Color::Black);
std::string ancienPseudo;
uint16_t identifiant16bits(0);
int8_t confirmation[3];
uint8_t identification2(5);
uint16_t version(0);
confirmation[0] = *reinterpret_cast<int8_t*>(&identification2);
int8_t *octetIdentification(reinterpret_cast<int8_t*>(&version));
if(little)
{
confirmation[1] = octetIdentification[1];
confirmation[2] = octetIdentification[0];
}
else
{
confirmation[1] = octetIdentification[0];
confirmation[2] = octetIdentification[1];
}
TCP->envoyer(confirmation, 3);
while(continuer)
{
if(TCP->erreur)
{
etat2 = "Erreur : Serveur non-accessible";
}
if(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-limite).count()>=16)
{window->clear(sf::Color::Black);
window->draw(connexion2);
window->draw(Pseudo);
window->draw(MotDePasse);
window->draw(etat);
window->draw(acceptationContrat);
window->display();
limite = std::chrono::system_clock::now();
}

sf::Event event;
if(window->pollEvent(event))
{
if (event.type == sf::Event::TextEntered)
{
if(selection == 0)
{
if (event.text.unicode < 128 && event.text.unicode != 8&&event.text.unicode != 13 &&event.text.unicode != 9&& pseudo2.size() < 254)
pseudo2.push_back(event.text.unicode);
}
else if (selection == 1)
{
if (event.text.unicode < 256 && event.text.unicode != 8&&event.text.unicode != 13 &&event.text.unicode != 9&& motDePasse2.size() < 254)
motDePasse2.push_back(event.text.unicode);
}
if(event.text.unicode == 8)
{
if(selection == 0 && pseudo2.size() > 0)
{
   pseudo2 = pseudo2.substr(0, pseudo2.size()-1);
}
else if(selection==1 && motDePasse2.size() > 0)
{
motDePasse2 = motDePasse2.substr(0, motDePasse2.size()-1);
}
}
std::string pseudo3;
std::wstring motDePasse3;
std::wstring motDePasse4;
motDePasse4.clear();
for(unsigned int nombre(0); nombre < motDePasse2.size(); ++nombre)
{
motDePasse4.push_back('*');
}
Pseudo.setString(pseudo2);
MotDePasse.setString(motDePasse4);
sf::FloatRect limites = Pseudo.getLocalBounds();
        if(limites.width >= 170) ///################################################################"
        {
//(800-x)
bool continuer = true;
unsigned int nombre2(0);
/// trouver le nombre le plus à droite.
nombre2 = pseudo2.size()-1;
float position2 = Pseudo.findCharacterPos(nombre2).x;
unsigned int nombre3(0);
for(unsigned int nombre(pseudo2.size()); nombre >0 && continuer; --nombre)
{
sf::Vector2f positionCharacter = Pseudo.findCharacterPos(nombre);
if(position2-positionCharacter.x >= 170)
{
continuer = false;
nombre3 = nombre;
}
}
for(unsigned int nombre(nombre3); nombre < pseudo2.size(); ++nombre)
{
pseudo3.push_back(pseudo2[nombre]);
}
Pseudo.setString(pseudo3);
        }
sf::FloatRect limites2 = MotDePasse.getLocalBounds();
        if(limites2.width >= 170) ///################################################################"
        {
bool continuer = true;
unsigned int nombre2(0);
/// trouver le nombre le plus à droite.
nombre2 = motDePasse4.size()-1;
float position2 = MotDePasse.findCharacterPos(nombre2).x;
unsigned int nombre3(0);
for(unsigned int nombre(motDePasse4.size()); nombre >0 && continuer; --nombre)
{
sf::Vector2f positionCharacter = MotDePasse.findCharacterPos(nombre);
if(position2-positionCharacter.x >= 170)
{
continuer = false;
nombre3 = nombre;
}
}
for(unsigned int nombre(nombre3); nombre < motDePasse4.size(); ++nombre)
{
motDePasse3.push_back('*');
}
MotDePasse.setString(motDePasse3);
        }

if(event.text.unicode == uint32_t(13) && pseudo2.size() > 0 && motDePasse2.size() > 0 && versionOK)
{
uint16_t taille2(0);
taille2 += pseudo2.size();
taille2 += motDePasse2.size()*4;
taille2 += 3;
int8_t tableau[taille2];
uint8_t identifiant(0);
tableau[0] = *reinterpret_cast<int8_t*>(&identifiant);
uint8_t taillePseudo(pseudo2.size());
uint8_t tailleMdp(motDePasse2.size());
tableau[1] = *reinterpret_cast<int8_t*>(&taillePseudo);
tableau[2] = *reinterpret_cast<int8_t*>(&tailleMdp);
uint16_t positionInitialisation(3);
for(unsigned int nombre(0); nombre < pseudo2.size(); ++nombre)
{
tableau[positionInitialisation] = pseudo2[nombre];
++positionInitialisation;

}
for(unsigned int nombre(0); nombre < motDePasse2.size(); ++nombre)
{
uint32_t caractere = motDePasse2[nombre];
int8_t *octet = reinterpret_cast<int8_t*>(&caractere);
if(little)
{
tableau[positionInitialisation] = octet[3];
++positionInitialisation;
tableau[positionInitialisation] = octet[2];
++positionInitialisation;
tableau[positionInitialisation] = octet[1];
++positionInitialisation;
tableau[positionInitialisation] = octet[0];
++positionInitialisation;
}
else
{
tableau[positionInitialisation] = octet[0];
++positionInitialisation;
tableau[positionInitialisation] = octet[1];
++positionInitialisation;
tableau[positionInitialisation] = octet[2];
++positionInitialisation;
tableau[positionInitialisation] = octet[3];
++positionInitialisation;
}
}
TCP->envoyer(tableau, taille2);
ancienPseudo = pseudo2;
pseudo2.clear();
motDePasse2.clear();
}
}
else if (event.type == sf::Event::Closed)
{
ok = false;
return 0;
}
else if (event.type == sf::Event::KeyPressed)
{
if (event.key.code == sf::Keyboard::Down)
{
if(selection != 1)
{++selection;
Pseudo.setColor(sf::Color::Black);
MotDePasse.setColor(sf::Color::Red);
}
}
else if (event.key.code == sf::Keyboard::Up)
{
if(selection != 0)
{--selection;
Pseudo.setColor(sf::Color::Red);
MotDePasse.setColor(sf::Color::Black);
}
}
}
}

TCP->actualiser();
if(TCP->resultat.size() > 0)
{

std::deque<int8_t> receptionIdentifiant = TCP->resultat[0];
TCP->resultat.pop_front();
uint8_t motif(0);
motif = *reinterpret_cast<uint8_t*>(&receptionIdentifiant[0]);
if(motif == 7)
{

int8_t *octet(reinterpret_cast<int8_t*>(&identifiant16bits));
if(little)
{
octet[0] = receptionIdentifiant[2];
octet[1] = receptionIdentifiant[1];
}
else
{
octet[0] = receptionIdentifiant[1];
octet[1] = receptionIdentifiant[2];
}
player->modele = *reinterpret_cast<uint8_t*>(&receptionIdentifiant[3]);
player->empire = *reinterpret_cast<uint8_t*>(&receptionIdentifiant[4]);
player->id = identifiant16bits;
player->pseudo = ancienPseudo;
if(player->modele == 0)
{
player->modelisation = Vaisseau;
player->vitesseMax = 4;
}
else
{
player->modelisation = Vaisseau;
player->vitesseMax = 4;
}
if(player->empire == 0)
{
player->couleur = 'r';
}
else if(player->empire == 1)
{
player->couleur = 'v';
}
else if(player->empire == 2)
{
player->couleur = 'b';
}
else if(player->empire == 3)
{
player->couleur = 'r';
}
else if(player->empire == 4)
{
player->couleur = 'b';
}
continuer = false;
}
else if (motif == 0)
{
uint8_t resultatConnecte(0);
resultatConnecte = *reinterpret_cast<uint8_t*>(&receptionIdentifiant[1]);
if(resultatConnecte == 1)
{
etat2 = "Etat : Identification reussi.";
etat.setString(etat2);
}
else if (resultatConnecte == 0)
{
etat2 = "Etat : Echec de l'identification.";
etat.setString(etat2);
}
}
else if (motif == 9)
{
uint8_t resultat = *reinterpret_cast<int8_t*>(&receptionIdentifiant[1]);
if(resultat == 1)
{
versionOK = true;
}
else
{
etat2 = "Etat : Version non-compatible.";
etat.setString(etat2);
}
}
}
}
return identifiant16bits;
}
point calculerPoint(anglePts angles)
{
double X3 = cos(angles.angleY * 3.14159265358979323846/180) * angles.longueur1;
double Z3 = cos(angles.angleY * 3.14159265358979323846/180) * angles.longueur1;
double Y3 = sin(angles.angleY *3.14159265358979323846/180) * angles.longueur1;

X3 *= cos(angles.angleX * 3.14159265358979323846/180);
Z3 *= sin(angles.angleX * 3.14159265358979323846/180);
return point (X3, Y3, Z3);
}
double calculerAngle(double angle)
{
return sin(angle * 3.14159265358979323846/180);
}
double calculerAngle2(double angle)
{
return cos(angle *3.14159265358979323846/180);
}
int main(){
sf::Color couleursDorigine[324];
for(unsigned int nombre(0); nombre < 324; ++nombre)
{
couleursDorigine[nombre] = sf::Color(0, 0, 0, 255);
}
uint8_t gachette2(0);
uint8_t axe_X2(1);
uint8_t axe_Y2(1);
    uint8_t positionX(0);
    uint8_t positionY(0);
    uint16_t identifiant16bits(0);
    std::chrono::time_point<std::chrono::system_clock> commandes;
    std::chrono::time_point<std::chrono::system_clock> timeOut;
     std::chrono::time_point<std::chrono::system_clock> defilementCredits;
int8_t paquetUDP[10240];
bool little;
        uint16_t nombre50(10);
    uint8_t *octet50(reinterpret_cast<uint8_t*>(&nombre50));
    if(octet50[1] == 10)
    {
little = false;
    }
    else
    {
little = true;
    }
if(CLOCKS_PER_SEC < 1000)
{

}
sf::ContextSettings settings(24, 0, 0, 3,3);
sf::RenderWindow window(sf::VideoMode(800, 600), "Fly in Celarivers", sf::Style::Default, settings);

GLenum initialisationGLEW( glewInit());
if(initialisationGLEW != GLEW_OK)
{
return 0;}

std::string shader1("#version 150 core");
shader1+=char(10);
shader1+="in vec3 in_Vertex;";
shader1+=char(10);
shader1+="in vec3 in_Color;";
shader1+=char(10);
shader1+="uniform mat4 projection;";
shader1+=char(10);
shader1+="uniform mat4 modelview;";
shader1+=char(10);
shader1+="out vec3 color;";
shader1+=char(10);
shader1+="void main()";
shader1+=char(10);
shader1+="{";
shader1+=char(10);
shader1+="gl_Position = projection * modelview * vec4(in_Vertex, 1.0);";
shader1+=char(10);
shader1+="color = in_Color;";
shader1+=char(10);
shader1+="}";

std::string shader2 ("#version 150 core");
shader2+= char(10);
shader2+="in vec3 color;";
shader2+= char(10);
shader2+="out vec4 out_Color;";
shader2+= char(10);
shader2+="void main()";
shader2+= char(10);
shader2+="{";
shader2+= char(10);
shader2+="out_Color = vec4(color, 1.0);";
shader2+= char(10);
shader2+="}";

std::string shader3("#version 150 core");
shader3+=char(10);
shader3+="in vec3 in_Vertex;";
shader3+=char(10);
shader3+="uniform mat4 projection;";
shader3+=char(10);
shader3+="uniform mat4 modelview;";
shader3+=char(10);
shader3+="void main()";
shader3+=char(10);
shader3+="{";
shader3+=char(10);
shader3+="gl_Position = projection * modelview * vec4(in_Vertex, 1.0);";
shader3+=char(10);
shader3+="}";
std::string shader4 ("#version 150 core");
shader4+= char(10);
shader4+="out vec4 out_Color;";
shader4+= char(10);
shader4+="void main()";
shader4+= char(10);
shader4+="{";
shader4+= char(10);
shader4+="out_Color = vec4(0.0,1.0,0.0, 1.0);";
shader4+= char(10);
shader4+="}";
Affichage2 shader;
Affichage2 shaderTextures;

shader.charger(shader1, shader2);
shaderTextures.charger(shader3, shader4);

glm::mat4 projection = glm::perspective(70.0, (double) 800/600,1.0,800.0);
glm::mat4 modelview = glm::mat4(1.0);
anglePts angles;
angles.angleX=0;
angles.angleY=0;
angles.longueur1 = 1;
point position(0, 0, 0);
anglePts angleCamera;
angleCamera.angleX=0;
angleCamera.angleY=0;
angleCamera.longueur1 = 15;
affichage Vaisseau;
if(!Vaisseau.chargerFichier("vaisseau Jeux.obj", 0, 1, "vaisseau Jeux.mtl"))
{
return 0;
}
int element(0);

Vaisseau.charger2(0);
joueur scorpion(0, anglePts(70, 0, 0, 0, 0), &Vaisseau, point(250, 6, 0), 'b', "Kayaba", 300,  0);
joueur scorpion2(0, anglePts(0, 0, 0, 0, 0), &Vaisseau, point(245, 0, 3), 'v', "Midorima", 300,  0);
std::string ipServeur = "celarivers.ddns.net";
//std::string ipServeur = "127.0.0.1";
sf::IpAddress IPserveur2(ipServeur);

sf::TcpSocket connexion;
sf::UdpSocket connexion2;

connexion.setBlocking(false);
connexion2.setBlocking(false);
bool connecte(false);
sf::Socket::Status status = connexion.connect(ipServeur, 53425);
int8_t paquet[10240];
conversation TCP;
TCP.paquet = paquet;
TCP.TCP = &connexion;

if (status == sf::Socket::Done || status == sf::Socket::NotReady)
{
 connecte = true;

}
else if (status == sf::Socket::Error)
{

}
if(connecte == false)
{

return 0;
}


sf::Font police;
if(!police.loadFromFile("arial.ttf"))
{
return 0;
}
std::list<joueur> joueurs;
joueurs.emplace_back();
bool ok (true);
identifiant16bits = identification(&window, &TCP, &police, joueurs.begin(), &Vaisseau, ok);
if(ok)
{
if(connexion2.bind(53427) != sf::Socket::Status::Done)
{

}

std::string texte;
texte = "message";
sf::Text messagesTchat;
sf::Text texteVitesse;
messagesTchat.setFont(police);
messagesTchat.setString(texte);
messagesTchat.setPosition(sf::Vector2f(16, 575));
messagesTchat.setCharacterSize(10);
messagesTchat.setColor(sf::Color::Black);

texteVitesse.setFont(police);
texteVitesse.setPosition(sf::Vector2f(800-130, 245));
texteVitesse.setCharacterSize(15);
texteVitesse.setColor(sf::Color::Black);
    double tailleFenetrelongueur;
    double tailleFenetrelargeur;
    double rotationX (0);
    double rotationY (0);
    double nombreD=60;
    //Cube.comparerR(cube2);
    sf::Texture skybox;
    sf::Texture conversation;
    bool modificationCouleur(true);

    sf::Texture radar ;
    sf::Texture Carte;
sf::Texture speed;
Carte.loadFromFile("Carte.png");
skybox.loadFromFile("skybox espace.png");
conversation.loadFromFile("Conversation.png");
conversation.setSmooth(true);
sf::Sprite Conversation;
sf::Sprite Carte2;
sf::Sprite speed2;

    sf::Texture menu ;
    sf::Texture menuSelection;
    sf::Texture menuNormal;
menu.loadFromFile("menu.png");
menuSelection.loadFromFile("selectionne.png");
menuNormal.loadFromFile("non-selectionne.png");
menuSelection.setSmooth(true);
menuNormal.setSmooth(true);
sf::Sprite spriteMenuNormal;
sf::Sprite spriteMenuSelection;
spriteMenuNormal.setTexture(menuNormal);
spriteMenuSelection.setTexture(menuSelection);
spriteMenuNormal.setScale(0.75, 0.75);
spriteMenuSelection.setScale(0.75, 0.75);
uint8_t choix(1);
sf::Text les_textesMenu[1];
sf::Vector2f lesPositionsMenu[1];
sf::Vector2f lesPositionsTexteMenu[1];
lesPositionsMenu[0] = sf::Vector2f(15, 340);
les_textesMenu[0].setCharacterSize(25);
les_textesMenu[0].setFont(police);
les_textesMenu[0].setString("Credits");
les_textesMenu[0].setColor(sf::Color::Red);
les_textesMenu[0].setPosition(sf::Vector2f(22, 337));
menu.setSmooth(true);
sf::Sprite menu2;
menu2.setTexture(menu);
sf::Vector2f positionMenu(-127.0, 0);
menu2.setPosition(positionMenu);
bool affichageMenu(false);
bool ouvrirMenu(false);
bool menuOuvert(false);
bool fermerMenu(false);
std::chrono::time_point<std::chrono::system_clock> tempsMenu;
float positionInferieur(-172.0);
menu2.setScale(0.75, 0.75);
positionInferieur *= 0.75;
bool creditsOuverts(false);
uint8_t identifiantFenetreCredits(0);
std::unique_ptr<sf::RenderWindow> fenetreCredits;
sf::Text texteCredits;
std::string texteDuCredit("CREDITS : ");
texteDuCredit.push_back(10);
texteDuCredit.push_back(10);
texteDuCredit += "Programmation : Paul Chapuis";
texteDuCredit.push_back(10);
texteDuCredit += "Modelisations : Abdelkrim Benhabib";
texteDuCredit.push_back(10);
texteDuCredit.push_back(10);
texteDuCredit+="REMERCIEMENTS : ";
texteDuCredit.push_back(10);texteDuCredit.push_back(10);
texteDuCredit+="Fly in Celarivers utilise SFML, merci a Laurent Gomila pour avoir conçu SFML. (http://www.sfml-dev.org/index-fr.php)";
texteDuCredit.push_back(10);
texteDuCredit+="Fly in Celarivers utilise OpenGL, Glew, Glm, merci a Khronos pour avoir concu des outils. (https://www.opengl.org/)";
texteDuCredit.push_back(10);
texteDuCredit+="Merci a Lynix, Soin, gbdivers, Bacelar, Str4nger, votre aide a ete précieuse ! ";
texteDuCredit.push_back(10);
texteDuCredit.push_back(10);
texteDuCredit+="Fly in celarivers est distribue sous licence MIT";
texteDuCredit.push_back(10);
texteDuCredit+="LICENCE : ";
texteDuCredit.push_back(10);texteDuCredit.push_back(10);
texteDuCredit+="The MIT License (MIT)";
texteDuCredit.push_back(10);
texteDuCredit.push_back(10);
texteDuCredit+="Copyright (c) 2015 Chapuis Paul";
texteDuCredit.push_back(10);
texteDuCredit.push_back(10);
texteDuCredit+="Permission is hereby granted, free of charge, to any person obtaining a copy";
texteDuCredit.push_back(10);
texteDuCredit+="of this software and associated documentation files (the ""Software""), to deal";
texteDuCredit.push_back(10);
texteDuCredit+="in the Software without restriction, including without limitation the rights";
texteDuCredit.push_back(10);
texteDuCredit+="to use, copy, modify, merge, publish, distribute, sublicense, and/or sell";
texteDuCredit.push_back(10);
texteDuCredit+="copies of the Software, and to permit persons to whom the Software is";
texteDuCredit.push_back(10);
texteDuCredit+="furnished to do so, subject to the following conditions:";
texteDuCredit.push_back(10);
texteDuCredit.push_back(10);
texteDuCredit+="The above copyright notice and this permission notice shall be included in all";
texteDuCredit.push_back(10);
texteDuCredit+="copies or substantial portions of the Software.";
texteDuCredit.push_back(10);
texteDuCredit.push_back(10);
texteDuCredit+="THE SOFTWARE IS PROVIDED ""AS IS"", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR";
texteDuCredit.push_back(10);
texteDuCredit+="IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,";
texteDuCredit.push_back(10);
texteDuCredit+="FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE";
texteDuCredit.push_back(10);
texteDuCredit+="AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER";
texteDuCredit.push_back(10);
texteDuCredit+="LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,";
texteDuCredit.push_back(10);
texteDuCredit+="OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE";
texteDuCredit.push_back(10);
texteDuCredit+="SOFTWARE.";
texteCredits.setString(texteDuCredit);
texteCredits.setFont(police);
texteCredits.setCharacterSize(10);
sf::Vector2f positionCredits(0, 20);
texteCredits.setPosition(sf::Vector2f(0, 20));
texteCredits.setColor(sf::Color::Black);
uint8_t selectionMenuX(0);
uint8_t selectionMenuY(0);
Conversation.setTexture(conversation);
speed.loadFromFile("vitesse.png");
speed2.setTexture(speed);
Carte2.setTexture(Carte);
Conversation.setPosition(sf::Vector2f(0,295));
Carte2.setScale(0.5, 0.5);
speed2.setScale(0.5, 0.5);
Carte2.setPosition(sf::Vector2f(800-237, 0)); //19.5 + 198
speed2.setPosition(sf::Vector2f(800-237, 237));
std::vector<std::vector<sf::Vertex> > vertices;
unsigned int x(0);
unsigned int y(0);
for(unsigned int nombre(0); nombre < 324; ++nombre)
{
vertices.push_back(std::vector<sf::Vertex>());
for(unsigned int nombre2(0); nombre2 < 4; ++nombre2)
{
vertices[vertices.size()-1].push_back(sf::Vertex());
vertices[vertices.size()-1][0].color = couleursDorigine[nombre];
vertices[vertices.size()-1][0].position=sf::Vector2f(582.0 + (x*11),19.5+(y*11));
vertices[vertices.size()-1].push_back(sf::Vertex());
vertices[vertices.size()-1][1].color = couleursDorigine[nombre];
vertices[vertices.size()-1][1].position=sf::Vector2f(582.0 + ((x+1)*11),19.5+(y*11));
vertices[vertices.size()-1].push_back(sf::Vertex());
vertices[vertices.size()-1][2].color = couleursDorigine[nombre];
vertices[vertices.size()-1][2].position=sf::Vector2f(582.0 + ((x+1)*11),19.5+((y+1)*11));
vertices[vertices.size()-1].push_back(sf::Vertex());
vertices[vertices.size()-1][3].color = couleursDorigine[nombre];
vertices[vertices.size()-1][3].position=sf::Vector2f(582.0 + (x*11),19.5+((y+1)*11));
}
++x;
if(x == 18)
{x=0;
++y;

}
}
bool running = true;
double angleX(0);
double angleY(0);
point camera(0 , 0, 0);
unsigned int compteurFPS(0);
const GLubyte *version(glGetString(GL_VERSION));
std::vector <float> ligne2;
bool prison(true);
for(int nombre(-250); nombre <= 250; nombre+=50)
{
ligne2.push_back(float(nombre));
ligne2.push_back(250.0);
ligne2.push_back(250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(-250.0);
ligne2.push_back(250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(250.0);
ligne2.push_back(-250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(-250.0);
ligne2.push_back(-250.0);
}

for(int nombre(-250); nombre <= 250; nombre+=50)
{
ligne2.push_back(250.0);
ligne2.push_back(250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(250.0);
ligne2.push_back(-250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(-250.0);
ligne2.push_back(250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(-250.0);
ligne2.push_back(-250.0);
ligne2.push_back(float(nombre));
}

for(int nombre(-250); nombre <= 250; nombre+=50)
{
ligne2.push_back(250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(250.0);
ligne2.push_back(-250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(250.0);
ligne2.push_back(250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(-250.0);
ligne2.push_back(-250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(-250.0);

}

for(int nombre(-250); nombre <= 250; nombre+=50)
{
ligne2.push_back(250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(250.0);
ligne2.push_back(250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(-250.0);
ligne2.push_back(-250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(250.0);
ligne2.push_back(-250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(-250.0);
}
for(int nombre(-250); nombre <= 250; nombre+=50)
{
ligne2.push_back(float(nombre));
ligne2.push_back(-250.0);
ligne2.push_back(250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(-250.0);
ligne2.push_back(-250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(250.0);
ligne2.push_back(250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(250.0);
ligne2.push_back(-250.0);
}
for(int nombre(-250); nombre <= 250; nombre+=50)
{
ligne2.push_back(250.0);
ligne2.push_back(250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(-250.0);
ligne2.push_back(250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(250.0);
ligne2.push_back(-250.0);
ligne2.push_back(float(nombre));
ligne2.push_back(-250.0);
ligne2.push_back(-250.0);
ligne2.push_back(float(nombre));
}
GLuint vboLignes2(0);
glGenBuffers(1, &vboLignes2);
glBindBuffer(GL_ARRAY_BUFFER,vboLignes2);
uint16_t taille3 = ligne2.size() * sizeof(float);
glBufferData(GL_ARRAY_BUFFER, taille3,ligne2.data(), GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0);
std::vector<float> lignes;
bool pairImpair(true);
for(int nombre(-250); nombre <= 250; nombre+=10)
{
if(pairImpair)
{
lignes.push_back(nombre);
lignes.push_back(-255);
lignes.push_back(-255);
lignes.push_back(nombre+10);
lignes.push_back(-255);
lignes.push_back(-255);
lignes.push_back(nombre);
lignes.push_back(255);
lignes.push_back(-255);
lignes.push_back(nombre+10);
lignes.push_back(255);
lignes.push_back(-255);
lignes.push_back(nombre);
lignes.push_back(-255);
lignes.push_back(255);
lignes.push_back(nombre+10);
lignes.push_back(-255);
lignes.push_back(255);
lignes.push_back(nombre);
lignes.push_back(255);
lignes.push_back(255);
lignes.push_back(nombre+10);
lignes.push_back(255);
lignes.push_back(255);
lignes.push_back(-255);
lignes.push_back(-255);
lignes.push_back(nombre);
lignes.push_back(-255);
lignes.push_back(-255);
lignes.push_back(nombre+10);
lignes.push_back(255);
lignes.push_back(-255);
lignes.push_back(nombre);
lignes.push_back(255);
lignes.push_back(-255);
lignes.push_back(nombre+10);
lignes.push_back(-255);
lignes.push_back(255);
lignes.push_back(nombre);
lignes.push_back(-255);
lignes.push_back(255);
lignes.push_back(nombre+10);
lignes.push_back(255);
lignes.push_back(255);
lignes.push_back(nombre);
lignes.push_back(255);
lignes.push_back(255);
lignes.push_back(nombre+10);
lignes.push_back(-255);
lignes.push_back(nombre);
lignes.push_back(-255);
lignes.push_back(-255);
lignes.push_back(nombre+10);
lignes.push_back(-255);
lignes.push_back(255);
lignes.push_back(nombre);
lignes.push_back(-255);
lignes.push_back(255);
lignes.push_back(nombre+10);
lignes.push_back(-255);
lignes.push_back(-255);
lignes.push_back(nombre);
lignes.push_back(255);
lignes.push_back(-255);
lignes.push_back(nombre+10);
lignes.push_back(255);
lignes.push_back(255);
lignes.push_back(nombre);
lignes.push_back(255);
lignes.push_back(255);
lignes.push_back(nombre+10);
lignes.push_back(255);
}
if(pairImpair)
pairImpair = false;
else if (pairImpair == false)
pairImpair = true;

}
double taille = lignes.size();
GLuint vboLignes(0);
glGenBuffers(1, &vboLignes);
glBindBuffer(GL_ARRAY_BUFFER,vboLignes);
taille = lignes.size() * sizeof(float);
glBufferData(GL_ARRAY_BUFFER, taille,lignes.data(), GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0);
sf::Clock frequenceAxes;
















unsigned int compteurBoucles(0);
bool mesure(false);
std::chrono::time_point<std::chrono::system_clock> Clavier;
std::chrono::time_point<std::chrono::system_clock> Fps;
std::chrono::time_point<std::chrono::system_clock> Clavier2;
unsigned int calibrageFps(16);
unsigned int calibrageClavier(24);
unsigned int compteurFps2(0);
unsigned int compteurClavier(10);
unsigned int compteurClavier2(0);
unsigned int une_seconde = time(0);
unsigned int une_seconde2 = time(0);
sf::Clock frequenceA;
sf::Clock frequenceClavier;
sf::Thread reseau(&ThreadReseau);
//reseau.launch();
sf::Mutex mutex;
float attente(40);
timeOut = std::chrono::system_clock::now();
bool texte2(false);
sf::Text Messages;
Messages.setFont(police);
Messages.setPosition(sf::Vector2f(8, 288));
Messages.setCharacterSize(10);
Messages.setColor(sf::Color::Black);
std::vector<sf::Vertex> differences;
std::string les_messages;
Messages.setString(les_messages);
std::vector<std::string> historiqueMessages; // ne pas compter les 10
float longueurs[128];
float longueurs2[128];
for(uint8_t nombre(0); nombre < 128; ++nombre)
{
longueurs[nombre] = police.getGlyph(nombre, 10, false).bounds.width;
longueurs2[nombre] = police.getGlyph(nombre, 10, false).advance;
}
sf::Text explicationCommandes;
std::wstring explications (L"F1 : Communiquer avec les autres joueurs.");
explications.push_back(uint32_t(10));
explications += L"F2 : Afficher le menu.";
explications.push_back(uint32_t(10));
explications += L"F3 : Changer de vue.";
explications.push_back(uint32_t(10));
explicationCommandes.setColor(sf::Color(255, 255, 255, 255));
explicationCommandes.setString(explications);
explicationCommandes.setCharacterSize(25);
explicationCommandes.setStyle( sf::Text::Bold);
explicationCommandes.setPosition(sf::Vector2f(0,0));
explicationCommandes.setFont(police);
bool effacement(false);
std::chrono::time_point<std::chrono::system_clock> tempsEffacement;
tempsEffacement = std::chrono::system_clock::now();
bool efface(false);
uint8_t valeurEffacement(255);
    while (running)
    {
if(ouvrirMenu && std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-tempsMenu).count()>= 20)
{

++positionMenu.x;
++positionMenu.x;
++positionMenu.x;
menu2.setPosition(positionMenu);
if(positionMenu.x >=0.0)
{
ouvrirMenu = false;
menuOuvert = true;
}
tempsMenu = std::chrono::system_clock::now();
}
else if(fermerMenu && std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-tempsMenu).count()>= 20)
{

--positionMenu.x;
--positionMenu.x;
--positionMenu.x;
menu2.setPosition(positionMenu);
if(positionMenu.x <= positionInferieur)
{
fermerMenu = false;
menuOuvert = false;
affichageMenu = false;
}
tempsMenu = std::chrono::system_clock::now();
}
if(efface == false)
{
if(effacement == false&&std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now()-tempsEffacement).count()>= 5)
{
effacement = true;
tempsEffacement = std::chrono::system_clock::now();
}
else if (effacement && std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-tempsEffacement).count()>= 20)
{
tempsEffacement = std::chrono::system_clock::now();
--valeurEffacement;
explicationCommandes.setColor(sf::Color(255, 255, 255, valeurEffacement));
if(valeurEffacement == 0)
efface=true;
}
}
if(TCP.erreur)
{
return 0;
}
        sf::Event event;


        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {running = false;
            mutex.lock();
            finDuThread = false;
            mutex.unlock();
            }else if (event.type == sf::Event::Resized)
            {glViewport(0, 0, event.size.width, event.size.height);
            tailleFenetrelongueur = event.size.width;
            tailleFenetrelargeur = event.size.height;
            }
            else if(event.type == sf::Event::TextEntered && texte2)
            {
        if (event.text.unicode < 128 && event.text.unicode != 8&&event.text.unicode != 13 &&event.text.unicode != 9&& texte.size() < 254)
        texte += static_cast<char>(event.text.unicode);
        if(event.text.unicode == 8)
        if(texte.size() > 0)
        texte = texte.substr(0, texte.size()-1);
        std::string texte3;//110
        messagesTchat.setString(texte);
        sf::FloatRect limites = messagesTchat.getLocalBounds();
        if(limites.width >= 80) ///################################################################"
        {
//(800-x)
bool continuer = true;
unsigned int nombre2(0);
/// trouver le nombre le plus à droite.
nombre2 = texte.size()-1;
float position2 = messagesTchat.findCharacterPos(nombre2).x;
unsigned int nombre3(0);
for(unsigned int nombre(texte.size()); nombre >0 && continuer; --nombre)
{
sf::Vector2f positionCharacter = messagesTchat.findCharacterPos(nombre);
if(position2-positionCharacter.x >= 80)
{
continuer = false;
nombre3 = nombre;
}
}
for(unsigned int nombre(nombre3); nombre < texte.size(); ++nombre)
{
texte3.push_back(texte[nombre]);
}
messagesTchat.setString(texte3);
        }
        else
        {
    messagesTchat.setString(texte);
        }

        if(event.text.unicode == 13 && texte.size() > 0)
        {
int8_t data[texte.size()+2];
uint8_t taille = texte.size();
uint8_t type =1;
data[0] = *reinterpret_cast<int8_t*>(&type);
data[1] = *reinterpret_cast<int8_t*>(&taille);
uint16_t positionData(0);
for(uint16_t nombre(2); nombre <taille+2; ++nombre)
{
data[nombre] = *reinterpret_cast<int8_t*>(&texte[positionData]);
++positionData;
}
TCP.envoyer(data, taille+2);
            texte.clear();
            texte3.clear();
            messagesTchat.setString(texte3);
        }
            }
            else if(event.type == sf::Event::KeyPressed)
            {
            if(event.key.code == sf::Keyboard::F1)
            {
            if(texte2)
            {
                texte2 = false;
                messagesTchat.setColor(sf::Color::Black);
            }

            else
            {
               texte2 = true;
            messagesTchat.setColor(sf::Color::Red);
            }



            }
            else if (event.key.code == sf::Keyboard::F2)
            {
            if(ouvrirMenu || menuOuvert)
            {
            fermerMenu = true;
            ouvrirMenu = false;
            }
            else
            {
            ouvrirMenu = true;
            affichageMenu = true;
            fermerMenu = false;
            }}
            else if(menuOuvert)
            {
            if (event.key.code == sf::Keyboard::Up)
            {
if(bool(choix-1 == 0) == false)
{
les_textesMenu[choix-1].setColor(sf::Color::Black);
--choix;
les_textesMenu[choix-1].setColor(sf::Color::Red);
}

            }
            else if (event.key.code == sf::Keyboard::Down)
{
if(bool(choix+1 == 2) == false)
{
les_textesMenu[choix-1].setColor(sf::Color::Black);
++choix;
les_textesMenu[choix-1].setColor(sf::Color::Red);
}
}
else if (event.key.code == sf::Keyboard::Return)
{
if(choix == 1) // Le joueur souhaite voir les crédits
{
if(creditsOuverts == false)
{
creditsOuverts = true;
fenetreCredits.reset(new sf::RenderWindow(sf::VideoMode(600,264), "Crédits", sf::Style::Default, settings));
}

}
}
            }

            }
            }
if(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-Clavier2).count()>=30 && texte2==false &&menuOuvert == false)
{
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
--angleCamera.angleX;
--angleCamera.angleX;
}
else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
{
++angleCamera.angleX;
++angleCamera.angleX;
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
{
++angleCamera.angleY;
++angleCamera.angleY;
}
else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
{
--angleCamera.angleY;
--angleCamera.angleY;
}

if(angleCamera.angleX < 0)
angleCamera.angleX =360;
else if(angleCamera.angleX > 360)
angleCamera.angleX = 0;
if(angleCamera.angleY < 0)
angleCamera.angleY =360;
else if(angleCamera.angleY > 360)
angleCamera.angleY = 0;

Clavier2 = std::chrono::system_clock::now();
}
if(creditsOuverts)
{
sf::Event event2;
while(fenetreCredits->pollEvent(event2))
{
if(event2.type == sf::Event::Closed)
{
fenetreCredits->close();
creditsOuverts = false;
}
}
}
if(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-defilementCredits).count()>=100 && creditsOuverts)
{
--positionCredits.y;
if(positionCredits.y <= -200)
{
fenetreCredits->close();
creditsOuverts=false;
}
texteCredits.setPosition(positionCredits);
defilementCredits = std::chrono::system_clock::now();
}
if(sf::milliseconds(16) < frequenceA.getElapsedTime())
//if(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-Fps).count()>=16)
{
if(creditsOuverts)
{
fenetreCredits->setActive();
fenetreCredits->clear(sf::Color::Blue);
fenetreCredits->draw(texteCredits);
fenetreCredits->display();
}

window.setActive();
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glEnable(GL_DEPTH_TEST);
point pointCamera = calculerPoint(angleCamera);
std::list<joueur>::iterator iterateur;
bool continuer = true;
std::list<joueur>::iterator iterateur2;
for(iterateur = joueurs.begin(); iterateur != joueurs.end() && continuer; ++iterateur)
{
if(iterateur->id==identifiant16bits)
{iterateur2 = iterateur;
continuer = false;
}}
point position2 = iterateur2->getPosition();
std::ostringstream ss;
ss << iterateur2->vitesse;
std::string la_vitesse(ss.str());
la_vitesse+=" m/sec";
texteVitesse.setString(la_vitesse);
pointCamera.setX(pointCamera.getX()+position2.getX());
pointCamera.setY(pointCamera.getY()+position2.getY());
pointCamera.setZ(pointCamera.getZ()+position2.getZ());
glm::mat4 projection = glm::perspective(70.0, (double) 800/600,1.0,1000.0);
glm::mat4 modelview = glm::lookAt(glm::vec3(pointCamera.getX(), pointCamera.getY(), pointCamera.getZ()), glm::vec3(position2.getX(), position2.getY(), position2.getZ()), glm::vec3(0, 1, 0));
glUseProgram(shader.getProgram());/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*for(unsigned int nombre(0); nombre < 15; ++nombre)
scorpion.afficher(modelview, projection, shader.getProgram());
scorpion2.afficher(modelview, projection, shader.getProgram());*/

for(iterateur = joueurs.begin(); iterateur != joueurs.end(); ++iterateur)
iterateur->afficher(modelview, projection, shader.getProgram());
glUseProgram(shaderTextures.getProgram());
glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "modelview"), 1, GL_FALSE,glm::value_ptr(modelview));
glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "projection"), 1, GL_FALSE,glm::value_ptr(projection));
if(prison)
{
glBindBuffer(GL_ARRAY_BUFFER, vboLignes2);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);
glDrawArrays(GL_LINES, 0, ligne2.size()/3);
glDisableVertexAttribArray(0);
}
else
{
glBindBuffer(GL_ARRAY_BUFFER, vboLignes);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);
glDrawArrays(GL_LINES, 0, lignes.size()/3);
glDisableVertexAttribArray(0);
}

glBindBuffer(GL_ARRAY_BUFFER,0);
glUseProgram(0);
window.pushGLStates();

//scorpion.afficherPseudo(modelview,projection,shader.getProgram(),window,police);
//scorpion2.afficherPseudo(modelview,projection,shader.getProgram(),window,police);
for(iterateur = joueurs.begin(); iterateur != joueurs.end(); ++iterateur)
iterateur->afficherPseudo(modelview,projection,shader.getProgram(),window,police);
window.draw(Conversation);
for(unsigned int nombre(0); nombre < differences.size()/4; ++nombre)
window.draw(&differences[nombre*4], 4, sf::Quads);

window.draw(messagesTchat);
window.draw(Carte2);

for(unsigned int nombre(0); nombre < 18*18; ++nombre)
window.draw(&vertices[nombre][0], vertices[nombre].size(), sf::Quads);
//window.draw(&vertices2[0], vertices2.size(), sf::Lines);
window.draw(speed2);
window.draw(texteVitesse);
window.draw(Messages);
if(affichageMenu)
window.draw(menu2);
if(menuOuvert && fermerMenu == false)
{
for(unsigned int nombre(0); nombre < 1; ++ nombre)
{

if(choix-1 == nombre)
{
spriteMenuSelection.setPosition(lesPositionsMenu[nombre]);
window.draw(spriteMenuSelection);
window.draw(les_textesMenu[nombre]);
}
else
{
spriteMenuNormal.setPosition(lesPositionsMenu[nombre]);
window.draw(spriteMenuNormal);
window.draw(les_textesMenu[nombre]);
}
}

}
if(efface == false)
window.draw(explicationCommandes);
window.popGLStates();
window.display();
if(position.getZ() > 250)
position.setZ(-250);
if(position.getZ() < -250)
position.setZ(250);
if(position.getX() > 250)
position.setX (-250);
if(position.getX() < -250)
position.setX (250);
if(position.getY() > 250)
position.setY(-250);
if(position.getY() < -250)
position.setY(250);
/*fps2 = clock();
fps2*CLOCKS_PER_SEC/1000;*/
//Fps = std::chrono::system_clock::now();

frequenceA.restart();
++compteurFPS;}
/// gérer la connection
std::size_t received(0);
short unsigned int port(53427);
sf::IpAddress Serveur;
connexion2.receive(paquetUDP, std::size_t(1500), received,Serveur, port);

if(received > 0 && IPserveur2 == Serveur)
{
uint8_t identifiant(0);
identifiant = *reinterpret_cast<uint8_t*>(&paquetUDP[0]);
if(identifiant == 0 && joueurs.size() > 0)
{
if(received > 1)
{
uint8_t nombreJoueurs(0);
nombreJoueurs = *reinterpret_cast<uint8_t*>(&paquetUDP[1]);
uint16_t taillePossible(4*3);
taillePossible *= nombreJoueurs;
taillePossible += nombreJoueurs*4;
taillePossible += nombreJoueurs*3;
taillePossible += nombreJoueurs*2;
taillePossible += 2;
taillePossible += nombreJoueurs*4;

if(received >= taillePossible)
{
uint16_t positionBuffer(2);
std::vector<uint16_t> identifiants;
std::vector<point> les_points;
std::vector<uint16_t> angles;
std::vector<uint8_t> commandes;
std::vector<float> vitesses;
for(unsigned int nombre(0); nombre < nombreJoueurs; ++nombre)
{
uint16_t ID(0);
int8_t *octet(reinterpret_cast<int8_t*>(&ID));
if(little)
{
octet[1] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[0] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;

}
else
{
octet[0] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[1] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
}
identifiants.push_back(ID);
}
for(unsigned int nombre(0); nombre < nombreJoueurs; ++nombre)
{
float tableauFloat[3];
for(unsigned int nombre2(0); nombre2 < 3; ++nombre2)
{
float nombre3(0);
 int8_t *octet(reinterpret_cast<int8_t*>(&nombre3));
if(little)
{
octet[3] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[2] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[1] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[0] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
}
else
{
octet[0] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[1] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[2] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[3] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
}
tableauFloat[nombre2] = nombre3;
}
les_points.push_back(point(tableauFloat[0], tableauFloat[1],tableauFloat[2]));
}
/// les points sonts faits.
// angles
for(unsigned int nombre(0); nombre < nombreJoueurs*2; ++nombre)
{
int16_t angle(0);
int8_t *octet(reinterpret_cast<int8_t*>(&angle));
if(little)
{
octet[1] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[0] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
}
else
{
octet[0] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[1] = *reinterpret_cast<int8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
}
angles.push_back(angle);
}
/// angles fait
// faire commandes
for(unsigned int nombre(0); nombre < nombreJoueurs; ++nombre)
{
commandes.push_back(*reinterpret_cast<uint8_t*>(&paquetUDP[positionBuffer]));
++positionBuffer;
commandes.push_back(*reinterpret_cast<uint8_t*>(&paquetUDP[positionBuffer]));
++positionBuffer;
commandes.push_back(*reinterpret_cast<uint8_t*>(&paquetUDP[positionBuffer]));
++positionBuffer;
}
/// commandes fini
// faire vitesses
for(unsigned int nombre(0); nombre < nombreJoueurs; ++nombre)
{
float vitesse(0);
int8_t *octet(reinterpret_cast<int8_t*>(&vitesse));
if(little)
{
octet[3]= *reinterpret_cast<uint8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[2]=*reinterpret_cast<uint8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[1]=*reinterpret_cast<uint8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[0]=*reinterpret_cast<uint8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
}
else
{
octet[0]=*reinterpret_cast<uint8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[1]=*reinterpret_cast<uint8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[2]=*reinterpret_cast<uint8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
octet[3]=*reinterpret_cast<uint8_t*>(&paquetUDP[positionBuffer]);
++positionBuffer;
}
vitesses.push_back(vitesse);
}
// utilisation des informations précédemment acquises
// nous avons les identifiants
// une petite comparaison est nécessaire pour chaque joueur
std::list<joueur>::iterator iterateur;
for(iterateur = joueurs.begin(); iterateur != joueurs.end(); ++iterateur)
{
bool continuer = true;
for(unsigned int nombre(0); nombre < identifiants.size() && continuer; ++nombre)
{
if(iterateur->id == identifiants[nombre])
{
uint8_t positionDonnees = nombre;
continuer = false;
uint16_t positionAngles(positionDonnees*2);
uint16_t positionCommandes(positionDonnees*3);
iterateur->miseAjour(les_points[positionDonnees], angles[positionAngles], angles[positionAngles+1], commandes[positionCommandes], commandes[positionCommandes+1], commandes[positionCommandes+2], vitesses[positionDonnees]);
///########################################################################################################################################################################################################################################################################################
}
}
}
}
}
}

}
TCP.actualiser();
if(TCP.resultat.size() > 0)
{

uint8_t identifiant(0);
std::deque<int8_t> buffer = TCP.resultat[0];
TCP.resultat.pop_back();
identifiant = *reinterpret_cast<uint8_t*>(&buffer[0]);
if(identifiant == 0)
{

}
else if (identifiant == 1)// texte
{
unsigned int limiteX(110);
unsigned int limiteY(270);
std::string texteRecu;
std::string texteRecu2;
uint16_t tailleTexte(0);
int8_t *octet(reinterpret_cast<int8_t*>(&tailleTexte));
if(little)
{
octet[0] = *reinterpret_cast<int8_t*>(&buffer[2]);
octet[1] = *reinterpret_cast<int8_t*>(&buffer[1]);
}
else
{
octet[0] = *reinterpret_cast<int8_t*>(&buffer[1]);
octet[1] = *reinterpret_cast<int8_t*>(&buffer[2]);
}
for(uint16_t nombre(3); nombre < tailleTexte+3; ++nombre)
{
texteRecu2.push_back(*reinterpret_cast<char*>(&buffer[nombre]));
}
/// se charger de la réception.
if(modificationCouleur)
modificationCouleur = false;
else
modificationCouleur = true;
texteRecu.push_back(10);
texteRecu+= texteRecu2;
Messages.setString(texteRecu);
sf::FloatRect limites;
limites = Messages.getLocalBounds();
char caractere(10);
if(limites.width > limiteX)
{
std::vector<uint32_t> les10;
float longueurLigne(0);
for(unsigned int nombre(0); nombre < texteRecu.size(); ++nombre)
{
if(texteRecu[nombre] != 10)
{
if(nombre != texteRecu.size()-1)
{longueurLigne+=police.getKerning(texteRecu[nombre], texteRecu[nombre+1], 10);}
longueurLigne+=longueurs2[texteRecu[nombre]];
}
if(longueurLigne >= limiteX)
{
les10.push_back(nombre);
longueurLigne=0;
}}
for(unsigned int nombre(0); nombre < les10.size(); ++nombre)
{
texteRecu.insert(les10[nombre], &caractere);
}
}
historiqueMessages.push_back(texteRecu);
les_messages+=historiqueMessages[historiqueMessages.size()-1];
Messages.setString(les_messages);
limites = Messages.getLocalBounds();
unsigned int debut(0);
unsigned int fin(0);
unsigned int compteur = historiqueMessages[historiqueMessages.size()-1].size();
debut = les_messages.size() - compteur;
fin = les_messages.size();
float plusHaut(Messages.findCharacterPos(debut).y);
float plusBas(Messages.findCharacterPos(debut).y);
for(unsigned int nombre(debut); nombre < fin; ++nombre)
{
float valeurY = Messages.findCharacterPos(nombre).y;
if(plusHaut > valeurY)
plusHaut = valeurY;
if(plusBas < valeurY)
plusBas = valeurY;

}
if(modificationCouleur)
{differences.push_back(sf::Vertex(sf::Vector2f(float(6), plusHaut+float(12)), sf::Color(255,0,0,100)));
differences.push_back(sf::Vertex(sf::Vector2f(float(126), plusHaut+float(12)), sf::Color(255,0,0,100)));
differences.push_back(sf::Vertex(sf::Vector2f(float(126), plusBas+float(12)), sf::Color(255,0,0,100)));
differences.push_back(sf::Vertex(sf::Vector2f(float(6), plusBas+float(12)), sf::Color(255,0,0,100)));
}
else
{
differences.push_back(sf::Vertex(sf::Vector2f(float(6), plusHaut+float(12)), sf::Color(0,255,0,100)));
differences.push_back(sf::Vertex(sf::Vector2f(float(126), plusHaut+float(12)), sf::Color(0,255,0,100)));
differences.push_back(sf::Vertex(sf::Vector2f(float(126), plusBas+float(12)), sf::Color(0,255,0,100)));
differences.push_back(sf::Vertex(sf::Vector2f(float(6), plusBas+float(12)), sf::Color(0,255,0,100)));
}
limites = Messages.getLocalBounds();
while(limites.height > limiteY)
{
for(unsigned int nombre(0); nombre < 4; ++nombre)
differences.erase(differences.begin());
//12
unsigned int compteur2(0);
unsigned int fin2(historiqueMessages[0].size());
for(unsigned int nombre(0); nombre < fin2; ++nombre)
{
if(les_messages[nombre] == 10)
++compteur2;
}
for(unsigned int nombre(0); nombre < differences.size(); ++nombre)
{
differences[nombre].position.y-=12*compteur2;
}
for(unsigned int nombre(0); nombre < fin2; ++nombre)
les_messages.erase(les_messages.begin());
historiqueMessages.erase(historiqueMessages.begin());
Messages.setString(les_messages);
limites = Messages.getLocalBounds();
}
}
else if (identifiant == 2)
{

}
else if (identifiant == 3) // ajout d'un joueur
{
uint16_t positionBuffer(1);
std::list<joueur>::iterator iterateur;
bool valide(true);
uint16_t ID(0);
if(little)
{
int8_t *octet (reinterpret_cast<int8_t*>(&ID));
octet[0] = buffer[1];
octet[1] = buffer[2];
int8_t octet2(0);
octet2=octet[0];
octet[0] = octet[1];
octet[1] = octet2;
}
else
{
int8_t *octet (reinterpret_cast<int8_t*>(&ID));
octet[0] = buffer[1];
octet[1] = buffer[2];
}

for(iterateur = joueurs.begin(); iterateur != joueurs.end() && valide; ++iterateur)
{
if(ID == iterateur->id)
valide = false;
}




if(valide)
{
joueurs.push_back(joueur());
iterateur = joueurs.begin();
iterateur->id = ID;
iterateur->modele = *reinterpret_cast<uint8_t*>(&buffer[3]);
iterateur->empire = *reinterpret_cast<uint8_t*>(&buffer[4]);
uint8_t taillePseudonyme(0);
taillePseudonyme = *reinterpret_cast<uint8_t*>(&buffer[5]);
if(buffer.size() >= taillePseudonyme + 6)
{
uint16_t positionBuffer(6);
std::string pseudonyme;
for(unsigned int nombre(0); nombre < taillePseudonyme; ++nombre)
{
pseudonyme.push_back( *reinterpret_cast<char*>(&buffer[positionBuffer]));
++positionBuffer;
}
iterateur->pseudo = pseudonyme;
}
else
{
joueurs.erase(iterateur);
}
}
}
else if (identifiant == 4) // supression d'un joueur
{
uint16_t ID(0);
if(little)
{
int8_t *octet (reinterpret_cast<int8_t*>(&ID));
octet[0] = buffer[2];
octet[1] = buffer[1];
}
else
{
int8_t *octet (reinterpret_cast<int8_t*>(&ID));
octet[0] = buffer[1];
octet[1] = buffer[2];
}
if(ID != identifiant16bits)
{
if(joueurs.size() > 0)
{
std::list<joueur>::iterator nombre;
bool continuer = true;
for(nombre = joueurs.begin(); nombre != joueurs.end() && continuer; ++nombre)
{
if(nombre->id == ID)
{
joueurs.erase(nombre);
continuer = false;
}
}
}
}
}
else if (identifiant == 5) /// garder le joueur ayant l'ID = identifiant16bits
{
std::list<joueur>::iterator iterateur;
std::list<joueur>::iterator iterateur2;
while(joueurs.size() != 1)
{
bool continuer = true;
for(iterateur = joueurs.begin(); iterateur!=joueurs.end() && continuer; ++iterateur)
{
if(iterateur->id != identifiant16bits)
{iterateur2 = iterateur;
continuer = false;
}
}
joueurs.erase(iterateur2);
}
vertices[(18*positionY)+positionX][0].color = couleursDorigine[(18*positionY)+positionX];
vertices[(18*positionY)+positionX][1].color = couleursDorigine[(18*positionY)+positionX];
vertices[(18*positionY)+positionX][2].color = couleursDorigine[(18*positionY)+positionX];
vertices[(18*positionY)+positionX][3].color = couleursDorigine[(18*positionY)+positionX];
positionX = *reinterpret_cast<uint8_t*>(&buffer[1]);
positionY = *reinterpret_cast<uint8_t*>(&buffer[2]);

vertices[(18*positionY)+positionX][0].color = sf::Color(255, 0, 0, 255);
vertices[(18*positionY)+positionX][1].color = sf::Color(255, 0, 0, 255);
vertices[(18*positionY)+positionX][2].color = sf::Color(255, 0, 0, 255);
vertices[(18*positionY)+positionX][3].color = sf::Color(255, 0, 0, 255);
}
else if (identifiant == 6)
{
uint8_t nombreJoueurs(0);
nombreJoueurs = *reinterpret_cast<uint8_t*>(&buffer[1]);
joueur traitementJoueurs[nombreJoueurs];
uint16_t positionBuffer(2);
uint8_t taillesPseudos[nombreJoueurs];
for(unsigned int nombre(0); nombre < nombreJoueurs; ++nombre)
{
taillesPseudos[nombre] = *reinterpret_cast<uint8_t*>(&buffer[positionBuffer]);
++positionBuffer;
}
for(unsigned int nombre(0); nombre < nombreJoueurs; ++nombre)
for(unsigned int nombre1(0); nombre1 < taillesPseudos[nombre]; ++nombre1)
{
traitementJoueurs[nombre].pseudo.push_back(*reinterpret_cast<char*>(&buffer[positionBuffer]));
++positionBuffer;
}
if(little) //   ID
{
for(unsigned int nombre(0); nombre < nombreJoueurs; ++nombre)
{
uint16_t ID(0);
int8_t *octet (reinterpret_cast<int8_t*>(&ID));
octet[0] = buffer[positionBuffer];
++positionBuffer;
octet[1] = buffer[positionBuffer];
++positionBuffer;
int8_t octet2(0);
octet2=octet[0];
octet[0] = octet[1];
octet[1] = octet2;
traitementJoueurs[nombre].id = ID;
}
}
else
{
for(unsigned int nombre(0); nombre < nombreJoueurs; ++nombre)
{
uint16_t ID(0);
int8_t *octet (reinterpret_cast<int8_t*>(&ID));
octet[0] = buffer[positionBuffer];
++positionBuffer;
octet[1] = buffer[positionBuffer];
++positionBuffer;
traitementJoueurs[nombre].id = ID;
}
}
/// empire, modèles
for(unsigned int nombre(0); nombre < nombreJoueurs; ++nombre)
{
traitementJoueurs[nombre].empire = *reinterpret_cast<uint8_t*>(&buffer[positionBuffer]);
++positionBuffer;
traitementJoueurs[nombre].modele =*reinterpret_cast<uint8_t*>(& buffer[positionBuffer]);
++positionBuffer;
}
for(unsigned int nombre(0); nombre < nombreJoueurs; nombre)
joueurs.push_back(traitementJoueurs[nombre]);
}
}

if(frequenceClavier.getElapsedTime() >= sf::milliseconds(200) /*clavier>clavier2+25*/)
//if(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-Clavier).count()>=calibrageClavier)
{
uint8_t gachette(0);
uint8_t axe_X(1);
uint8_t axe_Y(1);
++compteurClavier;
        if(texte2==false &&menuOuvert == false) {
if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
gachette = 1;
            }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
            {
axe_X = 0;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
            {
axe_X = 2;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
            {
axe_Y = 2;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
            {
axe_Y = 0;
            }
         }

        frequenceClavier.restart();
        if((std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-timeOut).count()>=5000) == false)
        {int8_t paquet[4];
        uint8_t identifiant(0);
        paquet[0] = *reinterpret_cast<int8_t*>(&identifiant);
         paquet[1] = *reinterpret_cast<int8_t*>(&gachette);
          paquet[2] = *reinterpret_cast<int8_t*>(&axe_X);
          paquet[3] = *reinterpret_cast<int8_t*>(&axe_Y);
        connexion2.send(paquet, 4,IPserveur2,53426);}
if(axe_X != axe_X2 || gachette != gachette2 || axe_Y != axe_Y2)
{
timeOut = std::chrono::system_clock::now();
}
}








        if(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-commandes).count()>=attente)
        {
        if(joueurs.size()>0)
        {
          std::list<joueur>::iterator iterateur;
          for(iterateur = joueurs.begin(); iterateur != joueurs.end(); ++iterateur)
          {
           iterateur->update();
          }
        }
        commandes = std::chrono::system_clock::now();
        }
}
}
uint8_t identifiant(4);
int8_t tableau[1];
tableau[0] = *reinterpret_cast<int8_t*>(&identifiant);
TCP.envoyer(tableau, 1);
    return 0;
}
