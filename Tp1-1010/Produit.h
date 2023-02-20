/********************************************
* Titre: Travail pratique #2 - Produit.h
* Date: 25 janvier 2018
* Auteur: Bouchra Nour ELyakin Dahamni et Safiatou Diallou
*******************************************/

#pragma once

#include <string>
#include <iostream>

using namespace std;

class Produit
{

public:
	Produit(const string& nom = "outil", int reference = 0, double prix = 0.0);

	string obtenirNom() const;
	int obtenirReference() const;
	 double obtenirPrix() const; 

	void modifierNom(const string& nom);
	void modifierReference(int reference);
	void modifierPrix(double prix);

	// TODO: Ajouter la surcharge de l'op�rateur >
	bool operator>(Produit const& produit)const;
	// TODO: Ajouter la surcharge de l'op�rateur <
	bool operator<(Produit const& produit)const;
   // TODO: Ajouter la surcharge de l'operateur ==
	bool operator==(Produit const& produit)const;
	friend istream& operator>>(istream& flux, Produit& produit);
   // TODO: Ajouter la surcharge de l'opérateur >>
	friend ostream& operator<< (ostream& flux, const Produit& produit);
	// TODO: Cette methode doit �tre remplac�e par la surcharge de l'op�rateur <<
	/*void afficher() const;*/

private:
	string nom_;
	int reference_;
	double prix_;
};

