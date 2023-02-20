/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date:
* Auteur:
*******************************************/

#include "ProduitAuxEncheres.h"
ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur& fournisseur, const string& nom , int reference,
	double prix , TypeProduit type):Produit(fournisseur,nom,reference,prix,type){}
double ProduitAuxEncheres::obtenirPrixBase()const{
	return prixBase_;
}
int ProduitAuxEncheres::obtenirIdentifiantClient()const {
	return identifiantClient_;
}
void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantclient) {
	identifiantClient_ = identifiantclient;
}
void ProduitAuxEncheres::modifierPrixBase(double prixBase) {
	prixBase_ = prixBase;
}
ostream& operator<<(ostream& flux, const ProduitAuxEncheres & produitAuxEncheres) {
	flux << "Produit aux encheres" << static_cast<Produit>(produitAuxEncheres) << endl ;
	flux << "prix de base " << produitAuxEncheres.prixBase_ << endl;
	flux << "identifiant clint " << produitAuxEncheres.identifiantClient_ << endl;
	return flux;

}
istream& operator>>(istream& flux, ProduitAuxEncheres& produitAuxEncheres) {
	flux >> static_cast<Produit&>(produitAuxEncheres);
	return flux;
	
}