//  panier.cpp
//  Created by Martine Bellaiche on 18-01-22.
//  Copyright © 2018 Martine Bellaiche. All rights reserved.
//

#include <string>
#include "Produit.h"

#ifndef PANIER_H
#define PANIER_H
class Panier
{
public:
	/* un constructeur par paramaetre
	* il recoit la capacite en param
	* initialise la capacite du tableau dynamique
	* alloue l'espace memoire du tableau dynamique
	* initialise nombre contenu a 0
	* intialise total a payer a 0
	*/
	Panier(int capacite = 0);
	// methodes d'accès
	/* la methode obtenirContenuPanier
	* retourne le pointeur qui pointe vers le tableau dynamique de pointeures d'objets
	*/
	Produit **  obtenirContenuPanier()const;
	/* la methode obtenirNombreContenu
	*retourne le nombre de produits
	*/
	int obtenirNombreContenu()const;
	/* la methode d'acces qui retourne le total a payer */

	double obtenirTotalApayer()const;

	// méthodes de modification

	// autres méthodes
	/* methode ajouter
	*prend en parametre un pointeur a un obejt produit et l'ajoute au tableau de produits
	* si la capacite est attenite on double la capacite pour pouvoir ajouter le pointeur de l'objet produit
	* faire la mise ajour du total a payer
	*/
	void ajouter(Produit * prod);
	/* la methode livrer qui supprine le contenu du tableau
	*re-intialise l'etat des autres attributs
	* elle prend rien en param
	*/
	void livrer();
	/* methode qui affiche l'etat des attributs */
	void afficher()const;

private:

	Produit * * contenuPanier_;
	int  nombreContenu_;
	int capaciteContenu_;
	double totalAPayer_;
};

#endif


