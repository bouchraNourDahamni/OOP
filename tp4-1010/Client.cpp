#include "Client.h"
#include <iostream>
#include "ProduitAuxEncheres.h"

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient)
{
}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

vector<Produit *> Client::obtenirPanier() const
{
    return panier_;
}

double Client::obtenirTotalAPayer()const
{
	double totalAPayer = 0.0;
	for (Produit*produit : panier_) {
		totalAPayer += produit->obtenirPrix();

	}
	return totalAPayer;
    // TODO
}

void Client::afficherPanier() const
{
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
    for (unsigned int i = 0; i < panier_.size(); i++)
        panier_[i]->afficher();
    cout << endl;
}

void Client::afficherProfil() const
{
	Usager::afficherProfil(); // atention ici d'oublier qu'on veut appeler la methode //
	cout << "       code client:    " << codeClient_ << endl;
	cout << "       Panier:    " << panier_.size() << " elements" << endl;
    // TODO
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
    {
        if (panier_[i] == produit)
        {
            panier_[i] = panier_[panier_.size() - 1];
            panier_.pop_back();
            return;
        }
    }
}

void Client::ajouterProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
        if (panier_[i] == produit)
            return;
    panier_.push_back(produit);
}

void Client::reinitialiser()
{
  
	for (Produit*produit : panier_) {
		 
		if (dynamic_cast<ProduitAuxEncheres*>(produit) != nullptr) { /* on verifie si le produit est un produit aux encheres avec le dynamic _cast pour apres mettre ajour le produit aux encheres */
	       ProduitAuxEncheres* produitAuxencheres = dynamic_cast<ProduitAuxEncheres*>(produit);
			produitAuxencheres->mettreAJourEnchere(nullptr,produitAuxencheres->obtenirPrixInitial());
		}
		 
	}
	panier_.clear(); /* on vide le panier du client */
    // TODO
}
