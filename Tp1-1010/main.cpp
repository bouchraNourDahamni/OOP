/**************************************************
* Titre: Travail pratique #2 - Main.cpp
* Date: 25 janvier 2018
* Auteur: Bouchra Nour Elyakin Dahamni et safiatou Diallou 
**************************************************/

#include "Produit.h"
#include "Rayon.h"
#include "Client.h"
#include "Panier.h"
#include <string>
#include <iostream>

using namespace std;

#define NB_PRODUCTS 15

/**
*Répondez aux questions ici :
* 1/ L'utilite de l'operateur = et le constrcuteur par copie : si on definit pas l'opreteur = et le constructeur de copie le compilateur les generent par defaut , le construteur de copie va copier les attributs d'un objet dans un autre objet nouvellement crée et l'operateur d'assignation va affecter les attibuts d'un objet dans un autre objet.
* 2/ il est absolument necessaire de les implemeter lorsque on a des attributs qui sont des pointeurs qui veut dire si la classe fait de l'allocation dynamique, car si on va copier uniquement les attributs (shallow copy) on aura plusieurs pointeurs qui pointe sur le meme espace memoire , a la fin lorsque on appelle le destructeur sa peux causer une erreur d'execution car il va essayer de faire delete sur objet deja delete (il va faire delete avec le premier pointeur mais si le deuxieme pointeur pointe sur le meme endroit que le premier lorsque il fait delete avec le deuxieme pointeur il n'arrive pas car l'esapce memoire est deja desaloué ) ou sa peut causer une fuite de memoire aussi lorsque j'affacete les attributs et je perds l'addresse de l'esapce memoire je peux plus desalouer l'esapce dont j'ai perdu l'adresse.
* 3/ si l'objet existe deja on appelle l'operateur d'affectation , lorsque je crée un nouvelle espace memoire ce que veut dire quand je cree un nouveau objet qui est une copie d'un autre objet j'appelle le constructeur de copie 
**/

int main()
{
	Produit* unProduit = new Produit();
	// Faire saisir à l'utilisateur les attributs du produit unProduit selon le format de la capture d'écran de l'énoncé
	cout << "saisissez les attributs pour un produit :";
	cin >> *(unProduit);
	// Afficher le Produit unProduit
	cout << "le produit saissie est : " << *unProduit ;

	// Creation de 15 produits
	Produit * produits[NB_PRODUCTS];
	double echantillonPrix[NB_PRODUCTS] = { 12.56, 50.0, 34.0, 56.0, 77.0, 91.0, 21.0, 34.0, 88.0, 65.0, 42.0, 72.0, 82.0, 53.0, 68.0 };

	for (int i = 0; i < NB_PRODUCTS; i++)
		produits[i] = new Produit("p" + to_string(i), i, echantillonPrix[i]);

	// Modification du nom, de la référence, du prix du troisieme produit créé
	produits[2]->modifierNom("p20");
	produits[2]->modifierPrix(100);
	produits[2]->modifierReference(31);

	cout << "Le produit p20 est moins cher que le produit p1 ? ";
	// Comparer le prix du produit p20 et p1 à l'aide de la surcharge d'un operateur
	if (produits[1] > produits[2]) {
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	// Cration d'un rayon sport
	Rayon sport;

	// Modification la catégorie  du rayon
	sport.modifierCategorie("sport");

	// Ajoutez les 10 premiers produits de dans le rayon créé
	for ( int i = 0; i < 10 ; i++)
	{
		sport += produits[i];
    }
	// Ajoutez encore une fois le produit p0 dans le rayon sport
	sport += produits[0];
	// Affichez le contenu du rayon
	cout << &sport;
	// Affichez le nombre de doublons du premier produit dans le rayon sport
	cout << "le nombre de doublons du produit:  " << *produits[0]<< " " << sport.compterDoublons(*(produits[0]));
	// Creation d'un client
	Client martine("Bellaiche", "Martine", 1111, "H2T3A6", 199004);
    // Martine achète les 5 derniers porduits
	for (int i = 10 ; i < 15; i++) {
		martine.acheter(produits[i]);
    }

	// Copie du client martine dans un autre client puis changment de son nom, prenom et identifiant pour "Paul Martin 689"
	Client paul = Client(martine);
	paul.modifierNom("Martin");
	paul.modifierPrenom("Paul");
	paul.modifierIdentifiant(689);

	cout << "Test identifiant paul: " << boolalpha << (689 == paul) << endl << endl;

	// Paul achete le produit p0
	paul.acheter(produits[0]);

	// Livrez le panier de Paul
	paul.livrerPanier();

	// Affichez le panier de Paul et de Martine
	cout <<paul;
	cout <<martine ;
   // Afichez le produit le plus cher du panier de martine
	Panier* panier = martine.obtenirPanier();
	cout << "Le produit le plus cher  " << martine.obtenirPrenom() << " a achete  : " << *panier->trouverProduitPlusCher();
	 // Terminer le programme correctement
	for (int i = 0; i < NB_PRODUCTS; i++) {
		delete produits[i];
	}
	delete unProduit;
	system("pause");
	return 0;
	 
}