/********************************************
* Titre: Travail pratique #1 -Rayon.h
* Date: 20 janvier 2018
* Auteur: Bouchra Nour Elyakin Dahamni et Sofiatou Diallo
*******************************************/

#ifndef RAYON_H
#define RAYON_H

#include <string>
#include "Produit.h"
using namespace std;
/*la definition de la classe rayon qui site les specifications du rayon qui est caracterisee par une categorie
*et un tableau dynamique du produit
*/

class Rayon
{
public:
	// Constructeurs par defaut et par parametres
	/*
	*constructeur par defaut qui intialise les attributs categorie a inconnu et le tableau a null
	*la capacite et le nombre de produits a null
	*/
	Rayon();
	/* constructeur par param
	*recoit le nom de la categorie du rayon
	*/
	Rayon(string cat);
	/* destructeur de la classe Rayon*/
	~Rayon();

	// Methodes d'acces
	/*  la methode obtenir categorie pour obtenir la categorie du Rayon
	* retourne  la categorie
	*/
	string obtenirCategorie()const;
	/*
	* la methode obtenirTousProduit pour obtenirtousproduit
	* obtenir le pointeur qui pointe vers le tableau deynamique de pointeurs a un objet produit
	* return tousproduits le double pointeur
	*/
	Produit ** obtenirTousProduits()const;
	/* la methode obtenirCapaciteProduits
	* obtenir la capacite du tableau dynamique
	* return capaciteproduits la taille du tableau dynamique
	*/
	int obtenirCapaciteProduits()const;
	/* la methode obteniNombre Produits
	* nombre de produits
	* return nombre de produits
	*/
	int obtenirNombreProduits()const;


	// Methodes de modification
	/* methode modifier categorie
	* recoit un param qui va etre la nouvelle categorie
	*/
	void modifierCategorie(string cat);

	// autres methodes
	/* la methode ajouter produit
	*ajoute le pointeur d'un objet produit au tabelau dynamique
	*si le tableau est nul on cree le tableau initial avec une capacite de 5
	*si le tableau est non nul et que la capacite est atteinte on augmente la capacite de 5 du tableau dynamique
	*/
	void ajouterProduit(Produit * produit);
	/* la methode afficher
	*afficher le nom de la categorie
	* afficher tous produits
	* afficher la capacite de produit
	* afficher nombre de produits
	*/
	void afficher()const;


private:

	// Attributs prives
	string categorie_;
	Produit ** tousProduits_;
	int capaciteProduits_;
	int nombreProduits_;

};

#endif


