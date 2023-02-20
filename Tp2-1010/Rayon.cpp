#include"Rayon.h"
Rayon::Rayon() : categorie_("inconnu"), tousProduits_(nullptr), capaciteProduits_(0), nombreProduits_(0) {}
Rayon::Rayon(string cat) : categorie_(cat), tousProduits_(nullptr), capaciteProduits_(0), nombreProduits_(0) {}
string Rayon::obtenirCategorie()const {
	return categorie_;
}
Produit** Rayon::obtenirTousProduits()const {
	return tousProduits_;
}
int Rayon::obtenirCapaciteProduits()const {
	return capaciteProduits_;
}
int Rayon::obtenirNombreProduits()const {
	return nombreProduits_;
}
void Rayon::modifierCategorie(string cat) {
	categorie_ = cat;
}
void Rayon::ajouterProduit(Produit* produit) {
	if (nombreProduits_ >= capaciteProduits_) {
		/* crer un nouveau tableau et on augmente la capacite de 5 du
		tableau actuel ou on le met a 5 si on vient juste de commencer*/

		int nouvelleCapacite = (capaciteProduits_ > 0) ? capaciteProduits_ + 5 : 5;
		Produit** nouveauTableau = new  Produit*[nouvelleCapacite];

		// Copier tous les produits precedents 
		for (int i = 0; i < nombreProduits_; i++)
			nouveauTableau[i] = tousProduits_[i];

		//  liberer le tableau precedent
		delete[]tousProduits_;

		// affecter le nouveau
		tousProduits_ = nouveauTableau;
		capaciteProduits_ = nouvelleCapacite;
	}
	tousProduits_[nombreProduits_++] = produit;
}
void Rayon::afficher()const
{
	cout << "La categorie du rayon est :" << categorie_ << endl;
	cout << " le nombre de produits :" << nombreProduits_ << endl;
	for (int i = 0; i < nombreProduits_; i++)
		tousProduits_[i]->afficher();
}
Rayon::~Rayon() {
	delete[] tousProduits_;
	tousProduits_ = 0;

}