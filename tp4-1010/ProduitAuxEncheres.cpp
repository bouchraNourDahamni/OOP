#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(double prix)
    : Produit(),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom,
                                       int reference, double prix)
    : Produit(fournisseur, nom, reference, prix),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

double ProduitAuxEncheres::obtenirPrixInitial() const
{
    return prixInitial_;
}

Client *ProduitAuxEncheres::obtenirEncherisseur() const
{
    return encherisseur_;
}

void ProduitAuxEncheres::afficher() const
{
	Produit::afficher();
	cout << "       prix initial:    " << prixInitial_ << endl;
	cout << "       encherisseur:    " << encherisseur_->obtenirNom() << endl;
    // TODO
}
 
void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
    prixInitial_ = prixInitial;
}

void ProduitAuxEncheres::mettreAJourEnchere(Client *encherisseur, double nouveauPrix)
{ 
	/* mettre ajour enchere d'abord on s'assure que l'encherisseur n'enchere pas sur sa propore offre
	puis si ce n'est pas le cas on modifie le prix puis on enleve le prduit du l'ancien encherisseur et 
	on met ajour l'attribut encherissuer */
	if (encherisseur_ != encherisseur) {
		modifierPrix(nouveauPrix);
		if (encherisseur != nullptr) {
			encherisseur->ajouterProduit(this);
		}
		if (encherisseur_ != nullptr)
		{
			encherisseur_->enleverProduit(this);
		}
		encherisseur_ = encherisseur;
	}
    // TODO
}
 
