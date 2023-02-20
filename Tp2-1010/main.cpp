/**************************************************
* Titre: Travail pratique #1 - Main.cpp
* Date: 20 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA
**************************************************/

#include "Produit.h"
#include "Rayon.h"
#include "client.h"
#include "panier.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	//C'est à vous de voir si vous devez allouer dynamiquement ou non les élèments

	//1-  Creez 15 objets du classe produit
	Produit* produits[15];

	for (int i = 0; i < 15; i++) {
		produits[i] = new Produit("une vaste" + to_string(i), i, i * 10);
	}
	//2-  Modifiez le nom, la référence, le prix de  troisieme objet Produit créé
	produits[2]->modifierNom("objet avec le nom modifie");
	produits[2]->modifierPrix(12345);
	produits[2]->modifierReference(20);
	//   afficher les attributs de cet objet Produit
	produits[2]->afficher();
	//3-  Creez un objet du classe rayon à l'aide du constructeur par défaut
	Rayon rayoncree;
	//4-  Modifiez la catégorie  du rayon
	rayoncree.modifierCategorie("nouvelle categorie");
	// 5- Ajouter 6 produits de  votre choix dans le rayon créé
	for (int i = 0; i < 6; i++) {
		rayoncree.ajouterProduit(produits[i]);
	}



	// 6- afficher le contenu du rayon
	rayoncree.afficher();
	//7-  Creez un objet de classe client à l'aide du constructeur
	Client clientcree("Bouchra Nour Elyakine", "dahamni", 1909765, "H3T1J4", 1999);
	//8-  afficher l'etat des attributs du client
	cout << clientcree.obtenirNom();
	cout << clientcree.obtenirPrenom();
	cout << clientcree.obtenirIdentifiant();
	cout << clientcree.obtenirCodePostal();
	cout << clientcree.obtenirDateNaissance();
	//9-   Le client achete 9 produits
	for (int i = 0; i<9; i++) {
		clientcree.acheter(produits[i]);
	}
	//10- Afficher le contenu du panier du client
	clientcree.afficherPanier();
	//11- livrer le panier du client
	clientcree.livrerPanier();
	//12- afficher le contenu du panier du client
	clientcree.afficherPanier();
	//13-  terminer le programme correctement
	for (int i = 0; i < 5; i++) {
		delete produits[i];
	}
	system("pause");
	return 0;
}
