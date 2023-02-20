/********************************************
* Titre: Travail pratique #2 - Produit.cpp
* Date: 25 janvier 2018
* Auteur: Bouchra Nour ELyakin Dahamni et Safiatou Diallou
*******************************************/

#include "Produit.h"

Produit::Produit(const string& nom, int reference, double prix) :
	nom_{ nom },
	reference_{ reference },
	prix_{ prix }
{}

// Methodes d'acces
string Produit::obtenirNom() const
{
	return nom_;
}

int Produit::obtenirReference() const
{
	return reference_;
}

 double Produit::obtenirPrix() const
{
	return prix_;
} 


// Methodes de modification
void Produit::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Produit::modifierReference(int reference)
{
	reference_ = reference;
}

void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}

/*void Produit::afficher() const
{
	cout << "nom : " << nom_
		<< "\t ref : " << reference_
		<< "\t prix : " << prix_;
}*/
bool Produit::operator>(const Produit & produit) const {
	return (prix_ > produit.prix_ );
}
bool Produit::operator<(const Produit & produit) const{
	return(prix_ < produit.prix_);
}
bool Produit::operator==( const Produit & produit)const{
	return(nom_ == produit.nom_ && reference_ == produit.reference_ && prix_ == produit.prix_);
}
ostream& operator<<(ostream& flux, const Produit& produit) {
	return flux << "---- > nom : " << produit.nom_ <<"     ref :" << produit.reference_ <<"              "<< "prix : "  << produit.prix_ << endl ;
}
istream& operator>>(istream& flux, Produit& produit) {
	flux >> produit.nom_ >> produit.reference_ >> produit.prix_;
	return flux;
}




