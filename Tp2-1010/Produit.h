/********************************************
* Titre: Travail pratique #1 - Produit.h
* Date: 20 janvier 2018
* Auteur: Bouchra Nour Elyakine Dahamni et Safiatou Diallo
*******************************************/

#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <iostream>
using namespace std;
/**
* une classe produit pour citer les caracteristiques d'un produit
*/

class Produit
{
public:
	// Constructeurs par defaut et par parametres
	/**
	constructeur par defaut qui intialise les attributs nom a outil et reference et prix a 0
	*/

	Produit();
	/*constructeurs par parametre qui recoit le nom du produit , sa refernce puis son prix */
	Produit(string nom, int reference, double prix);

	// Methodes d'acces
	/* la methode obtenir nom pour obtenir le nom du produit
	* retourne le nom du produit
	*/
	string obtenirNom()const;
	/* la methode obtenir refernce  pour obtenir la reference du produit
	*retourne la refernce du produit
	*/
	int obtenirReference()const;
	/* la methode obtenir prix pour obtenir le prix du produit
	* retourne le prix du produit
	*/
	double obtenirPrix()const;

	// Methodes de modification
	/*
	* la methode modifer nom pour changer le nom du produit
	* elle prend le parama le nouveau nom du produit
	*/
	void modifierNom(string nom);
	/*
	*la methode modifier refernce pour changer la reference du produit
	* elle prend en parametre la nouvelle reference du produit
	*/
	void modifierReference(int reference);
	/*
	*la methode modifier prix  pour changer le prix  du produit
	* elle prend en parametre le nouveau prix du produit
	*/
	void modifierPrix(double prix);


	// autres methodes
	/* la methode affiche
	* afficher l'etat des attributs
	*/
	void afficher()const;

private:

	// attributs prives
	/* nom_ pour stocker le nom du produit*/
	string nom_;
	/* refernce_  pour stocker la reference du produit*/
	int reference_;
	/* prix_ pour stocker le prix du produit*/
   double prix_;
};

#endif


