#include"Produit.h"
Produit::Produit() : nom_("outil"), reference_(0), prix_(0) {}
Produit::Produit(string nom, int reference, double prix) : nom_(nom), reference_(reference), prix_(prix) {}
string Produit::obtenirNom()const {
	return nom_;
}
int Produit::obtenirReference()const {
	return reference_;
}
double Produit::obtenirPrix() const {
	return prix_;

}
void Produit::modifierNom(string nom) {
	nom_ = nom;
}
void Produit::modifierReference(int reference) {
	reference_ = reference;
}
void Produit::modifierPrix(double prix) {
	prix_ = prix;
}
void Produit::afficher()const {
	cout << "Le nom du produit est : " << nom_ << endl;
	cout << "La reference du produit est : " << reference_ << endl;
	cout << "Le prix du produit est : " << prix_ << endl;
}