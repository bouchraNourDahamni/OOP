/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date:
* Auteur:
*******************************************/
#include "Fournisseur.h"
Fournisseur::Fournisseur(const string&  nom, const string& prenom, int identifiant, const string& codePostal) :Usager(nom, prenom, identifiant, codePostal),contenuCatalogue_(0){
	satisfaction_.niveaux_[NIVEAUX_SATISFACTION] = { 0 };
}
vector<Produit*> Fournisseur::obtenirCatalogue()const {
	return contenuCatalogue_;
}
Satisfaction Fournisseur::obtenirSatisfaction()const {
	return satisfaction_;
}
void Fournisseur::modifierSatisfaction(Satisfaction satisfaction) {
	satisfaction_ = satisfaction;
}
void Fournisseur::noter(int appreciation) {
	++satisfaction_.niveaux_[appreciation];
}
void Fournisseur::ajouterProduit(Produit* produit) {
	contenuCatalogue_.push_back(produit);
}
void Fournisseur::enleverProduit(Produit*produit) {
	for (int i = 0; i < contenuCatalogue_.size(); i++) {
		if (*contenuCatalogue_[i] == *produit) {
			contenuCatalogue_[i] = contenuCatalogue_[contenuCatalogue_.size()-1];
			contenuCatalogue_.pop_back();
		}

	  }
		 
			 
		 
	 
		 
}
Fournisseur& Fournisseur::operator=(const Fournisseur& fournisseur) {
	   static_cast<Usager>(*this) = static_cast<Usager>(fournisseur);
	   return *this;
}
ostream& operator<<(ostream& flux, Fournisseur& fournisseur) {
	flux << "Fournisseur :" << static_cast<Usager>(fournisseur) << endl;
	flux << "notes";
	for (int i = 0; i < NIVEAUX_SATISFACTION; i++) {
		flux << i << ":" << fournisseur.satisfaction_.niveaux_[i] << endl;

	}
	return flux;
}