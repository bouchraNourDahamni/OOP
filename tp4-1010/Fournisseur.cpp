#include "Fournisseur.h"
#include <iostream>

Fournisseur::Fournisseur()
    : Usager()
{
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal)
{
}

vector<Produit *> Fournisseur::obtenirCatalogue() const
{
    return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
    for (unsigned int i = 0; i < catalogue_.size(); i++)
        catalogue_[i]->afficher();
    cout << endl;
}

void Fournisseur::afficherProfil() const
{
	Usager::afficherProfil();
	cout << "       catalogue    " << catalogue_.size() << "elements" << endl;
    // TODO
}

void Fournisseur::reinitialiser()
{
	for (Produit*produit : catalogue_) {
		produit->modifierFournisseur(nullptr); /* on met le fournisseur du produit  a nullptr*/
	}
	catalogue_.clear(); /* on vide le catalogue du Fournisseur */
    // TODO
}

void Fournisseur::ajouterProduit(Produit *produit)
{
    for (unsigned int i = 0; i < catalogue_.size(); i++)
        if (catalogue_[i] == produit)
            return;
    Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
    catalogue_.push_back(produit);
}

void Fournisseur::enleverProduit(Produit *produit)
{
    produit->modifierFournisseur(nullptr);
    for (unsigned int i = 0; i < catalogue_.size(); i++)
    {
        if (catalogue_[i] == produit)
        {
            catalogue_[i] = catalogue_[catalogue_.size() - 1];
            catalogue_.pop_back();
            return;
        }
    }
}
