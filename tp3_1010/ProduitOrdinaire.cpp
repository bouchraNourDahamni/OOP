/********************************************
* Titre: Travail pratique #3 - ProduitOrdinaire.h
* Date:
* Autevur:
*******************************************/


#include <string>
#include <iostream>
#include "ProduitOrdinaire.h"
#include "Fournisseur.h"
using namespace std;
ProduitOrdinaire::ProduitOrdinaire(Fournisseur& fournisseur,
	const string& nom, int reference ,
	double prix , TypeProduit type , bool estTaxable ):Produit(fournisseur,nom,reference,prix,type),estTaxable_(estTaxable){}
bool ProduitOrdinaire::obtenirEstTaxable()const {
	return estTaxable_;
}
void ProduitOrdinaire::modifierEstTaxable(bool estTaxable) {
	estTaxable_ = estTaxable;
}
ostream& operator<<(ostream& os, const ProduitOrdinaire& produit) {
	os <<"Produit ordinaire" << static_cast<Produit>(produit);
	os << "est taxable :" << boolalpha <<  produit.estTaxable_;
	return os;
}
istream& operator>>(istream& flux, ProduitOrdinaire& produit) {
	flux >> static_cast<Produit&>(produit);
	flux >> produit.estTaxable_;
	return flux;
}
