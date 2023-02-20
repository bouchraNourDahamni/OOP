/********************************************
* Titre: Travail pratique #3 - Panier.cpp
* Date:
* Auteur:
*******************************************/

#include "Panier.h"
using namespace std;

Panier::Panier(int idClient) {
	// TODO
	idClient_ = idClient;
	totalAPayer_ = NULL;
}


Panier::~Panier()
{
	contenuPanier_.clear();
}

// methodes d'accès
vector<Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return (int)contenuPanier_.size();
}


int Panier::obtenirIdClient() const {
	return idClient_;
}

double Panier::obtenirTotalApayer() const {
	return totalAPayer_;
}


double Panier::calculerTotalApayer()const
{
	// TODO
	double nouveauPrix = totalAPayer_;
	for (Produit * p : contenuPanier_) {
		if (p->retournerType() == TypeProduitAuxEncheres && static_cast<ProduitAuxEncheres*>(p)->obtenirIdentifiantClient() == idClient_) {
			nouveauPrix += p->obtenirPrix();
		}

	}
	return nouveauPrix;
	
}



void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}


void Panier::modifierIdClient(int idClient) {
	idClient_ = idClient;
}




void Panier::ajouter(Produit * prod)
{
	// TODO
	if (prod->retournerType() == TypeProduitOrdinaire) {
		ProduitOrdinaire* prod2 = static_cast<ProduitOrdinaire*>(prod);
		if (prod2->obtenirEstTaxable())
			totalAPayer_+=prod->obtenirPrix()*TAUX_TAXE + prod->obtenirPrix();
	 }

	contenuPanier_.push_back(prod);
}

void Panier::livrer()
{
	totalAPayer_ = 0;
	contenuPanier_.clear();
}

Produit* Panier::trouverProduitPlusCher()
{
	if (contenuPanier_.empty())
		return nullptr;

	Produit* prodPlusChere = contenuPanier_[0];
	for (unsigned int i = 1; i < contenuPanier_.size(); i++)
		if (*contenuPanier_[i] > *prodPlusChere)
			prodPlusChere = contenuPanier_[i];

	return prodPlusChere;
}

ostream & operator<<(ostream & os, const Panier & panier){

	// TODO
	os << "le panier de";
	 
	for (int i = 0; i < panier.contenuPanier_.size(); i++) {
		if (panier.contenuPanier_[i]->retournerType() == TypeProduitAuxEncheres) {
			ProduitAuxEncheres* produitAuxencheres = static_cast<ProduitAuxEncheres*>(panier.contenuPanier_[i]);
			os << *produitAuxencheres << endl;
		}
		for (int i = 0; i < panier.contenuPanier_.size(); i++)
			if (panier.contenuPanier_[i]->retournerType() ==  TypeProduitOrdinaire){
			ProduitOrdinaire* produitOridanire = static_cast<ProduitOrdinaire*>(panier.contenuPanier_[i]);
			os << *produitOridanire << endl ;
		}
	}
	os << "        ----> total a payer :   " << panier.calculerTotalApayer() << endl;
	return os;
}
