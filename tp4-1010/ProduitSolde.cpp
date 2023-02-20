#include "ProduitSolde.h"

ProduitSolde::ProduitSolde(int pourcentageRabais)
    : Produit(),
      Solde(pourcentageRabais)
{
}

ProduitSolde::ProduitSolde(Fournisseur *fournisseur, const string &nom,
                           int reference, double prix, int pourcentageRabais)
    : Produit(fournisseur, nom, reference, prix),
      Solde(pourcentageRabais)
{
}

double ProduitSolde::obtenirPrix() const
{
	return Produit::obtenirPrix() - ((pourcentageRabais_ * Produit::obtenirPrix()) / 100) ;/* on tient compte du rabais */
    // TODO
}

void ProduitSolde::afficher() const
{
	Produit::afficher();
	cout << "       rabais:    " << obtenirPourcentageRabais() << "%" << endl;
    // TODO
}
