//  client.h
//  Created by Martine Bellaiche on 18-01-22.
//  Copyright © 2018 Martine Bellaiche. All rights reserved.
//

#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "panier.h"
using namespace std;
class Client
{
public:
	/*constructeur par defaut et constructeur par parametre
	* prend en param le nom , le prenom,l'identifiant,le codePostal,la date de naissance du client
	*/
	Client(string  nom = "inconnu", string prenom = "inconnu", int identifiant = 0, string codePostal = "inconnu", long date = 0,Panier*panier = nullptr);
	// methodes d'acces
	/* la methode obtenirNom pour obtenir le nom du client
	*retourne le nom du client
	*/

	string obtenirNom()const;
	/*la methode obtenirPrenom pour obtenir le Prenom du client
	*retourne le Prenom du client*/
	string obtenirPrenom()const;
	/*la methode obtenirIdentifiant pour obtenir l'identifiant du client
	*retourne l'identifant du client*/
	int obtenirIdentifiant()const;
	/*la methode obtenirCodepostal pour obtenir le codepostal du client
	*retourne le codepostal  du client*/
	string obtenirCodePostal()const;
	/*la methode obtenirDatedenaissance pour obtenir la date de naissance du client
	*retourne la date de naissance  du client*/
	long obtenirDateNaissance()const;
	// methodes de modification
	/* la methode de modifcation modiferNom
	*prend en param le nom
	* elle modifie le nom du client a nom
	*/
	void modifierNom(string nom);
	/* la methode de modifcation modiferPrenom
	*prend en param le prenom
	* elle modifie le prenom du client a prenom
	*/
	void modifierPrenom(string prenom);
	/* la methode de modifcation modiferIdentifiant
	*prend en param l'identifiant
	* elle modifie l'identifiant du client a identifiant
	*/
	void modifierIdentifiant(int identifiant);
	/* la methode de modifcation modiferCodePostal
	*prend en param le codePostal
	* elle modifie le codepostal du client a codePostal
	*/
	void modifierCodePostal(string codePostal);
	/* la methode de modifcation modiferDateNaissance
	*prend en param la date de naissance
	* elle modifie la date de naissance du client a date
	*/
	void modifierDateNaissance(long date);

	// autres méthodes
	/*  la methode ajoute un produit dans le panier du client
	* si le panier n'existe pas on cree un objet panier de 4 produits
	* on ajoute le produit dans le panier du client
	*/
	void acheter(Produit * prod);
	/* la methode afficher panier
	* afficher le contenu du panier si il n'est pas vide
	*/
	void afficherPanier()const;
	/* la methode permet de livrer le contenu du panier en supprimant le panier actuel*/
	void livrerPanier();


private:

	string nom_;
	string prenom_;
	int identifiant_;
	string codePostal_;
	long dateNaissance_;
	Panier *  monPanier_;
};
#endif /* client_h */

