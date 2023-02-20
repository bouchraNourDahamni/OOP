/**************************************************
* Titre: Travail pratique #3 - main.cpp
* Date:
* Auteur:
**************************************************/

#include "Fournisseur.h"
#include "ProduitOrdinaire.h"
#include "ProduitAuxEncheres.h"
#include "Client.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const int  NB_PRODUCTS = 15;

/**
*R�pondez aux questions ici :
* 1/ il est logique de deriver une classe ProduitAUxencheres et une classe ProduitOrdinaire de la classe Produit car un produitordinaire est un produit c'est un sorte de produit , on voit le verbe �est� donc c'est la notion d'heritage pareill pour produitauxencheres
* 2/
* 2.1 une fois on connait le type de produit on peut le convertir a cette classe derive car le contenuPanier est un vecteur  de pointeur de produit qui sont soit pointeur produit ordinaire soit pointeur produit auxencheres ici on peut convertir le pointeur du type de la classe de base a une classe derive car on etait sur qu'il peut pointe sur cette classe derive vu qu'on a su son type et comme sa on utlisera l'operateur surchage correspondant.
* 2.2Si on le considere pas , on affichera tous les produits du panier avec l'op�rateur g�n�rique d�fini dans Produit et on perdra le polymorphisme des surcharges
**/

int main()
{
	// Creez un objet de classe client � l'aide du constructeur
	Client martine("Bellaiche", "Martine", 1111, "H2T3A6", 199004);

	// creez un objet de la classe client � l'aide du constructeur de copie
	// et modifier sonm identifiant
	Client maCopie(martine);
	maCopie.modifierIdentifiant(777);

	// v�rifier si les copies sont identiques;

	if (maCopie == martine)
		cout << "clients identitiques" << endl;
	else
		cout << " non Identiques " << endl;

	Client unAutreClient("Client", "autre", 2222, "h3T3A7", 20180212);
	unAutreClient = maCopie;

	cout << unAutreClient;

	// Creez un fournisseur
	Fournisseur poly = Fournisseur("Ecole", "Polytechnique", 123456789, "H3T 1J4");
	// afficher le fournisseur
	cout << poly;
	// Creation de 15 Produits Ordinaire
	ProduitOrdinaire* produits[NB_PRODUCTS];
	double echantillonPrix[NB_PRODUCTS] =
	{ 12.56, 50.0, 34.0, 56.0, 77.0, 91.0, 21.0, 34.0, 88.0, 65.0, 42.0, 72.0, 82.0, 53.0, 68.0 };
	for (int i = 0; i < NB_PRODUCTS; i++)
		produits[i] = new ProduitOrdinaire(poly, "p" + to_string(i), i, echantillonPrix[i], TypeProduitOrdinaire, true);

	// Creez un produit aux encheres
	ProduitAuxEncheres* prodAuxEncheres = new ProduitAuxEncheres(poly, "pAuxEncheres", 20,
		100, TypeProduitAuxEncheres);

	// Le client achete les 7 premiers porduits
	for (int i = 0; i < 7; i++)
		martine.acheter(produits[i]);

	// Afficher Panier du client
	cout << martine;

	// afficher le fournisseur
	cout << poly;

	// Client mise sur le produit aux encheres 
	martine.miserProduit(prodAuxEncheres, 500);

	// afficher le produit aux ench�res
	cout << *prodAuxEncheres << endl;

	// Ma copie mise aussi  sur le produit  aux ench�res
	maCopie.miserProduit(prodAuxEncheres, 555);

	// afficher le produit aux ench�res
	cout << *prodAuxEncheres << endl;

	// Afficher Panier du client
	cout << martine << endl;

	// trouver le produit le plus cher du panier
	cout << " Produit le plus cher " << *martine.obtenirPanier()->trouverProduitPlusCher();

	// livrer le panier du client martine
	martine.livrerPanier();

	// Afficher lefournisseur
	cout << poly << endl;

	// Nettoyer la memoire 
	for (int i = 0; i < NB_PRODUCTS; i++) {
		delete produits[i];
	}
	delete prodAuxEncheres;
	 

}
