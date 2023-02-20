#include"Panier.h"
Panier::Panier(int capacite) :capaciteContenu_(capacite), nombreContenu_(0), totalAPayer_(0) {
	contenuPanier_ = new Produit*[capacite];
}
Produit** Panier::obtenirContenuPanier()const {
	return contenuPanier_;
}
int Panier::obtenirNombreContenu()const {
	return nombreContenu_;
}
double Panier::obtenirTotalApayer()const {
	return totalAPayer_;
}
void Panier::ajouter(Produit* produit) {
	if (nombreContenu_ >= capaciteContenu_) {
		/* crer un nouveau tableau et on doublera la capacite du
		tableau actuel  */
		Produit** nouveauTableau = new Produit*[capaciteContenu_*2];
		// Copier tous les produits precedents 
		for (int i = 0; i < nombreContenu_; i++) {
			nouveauTableau[i] = contenuPanier_[i];
		}
		delete[]contenuPanier_;
		contenuPanier_ = nouveauTableau;

	}
	contenuPanier_[nombreContenu_++] = produit;
	totalAPayer_ += (produit->obtenirPrix());

}
void Panier::livrer() {
	delete[] contenuPanier_;
	nombreContenu_ = 0;
	capaciteContenu_ = 0;
	contenuPanier_ = nullptr;
	totalAPayer_ = 0;
}
void Panier::afficher()const {
	cout << "le total a payer est" << totalAPayer_;
	cout << "le nombre de produits est " << nombreContenu_;
	for (int i = 0; i < nombreContenu_; i++) {
		contenuPanier_[i]->afficher();
	}
	 


}