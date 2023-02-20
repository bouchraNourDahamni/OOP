#include "Gestionnaire.h"

vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

void Gestionnaire::afficherLesProfils() const
{
    // TODO
	cout << "Les profils :" << endl;
	for (Usager*usager : usagers_) {
		usager->afficherProfil();
	}

}

double Gestionnaire::obtenirChiffreAffaires() const
{
	double chiffreAffaires = 0.0;
	for (Usager*usager : usagers_) {
		chiffreAffaires += usager->obtenirTotalAPayer();
	}
	return chiffreAffaires;
    // TODO
}

void Gestionnaire::ajouterUsager(Usager *usager)
{ 
	bool trouve = false;
   for (int i = 0; i < usagers_.size() && ! trouve ;i++) {
		if (usagers_[i] == usager)
			trouve = true;
	}
	if(!trouve)
		usagers_.push_back(usager);

    // TODO
}

void Gestionnaire::reinitialiser()
{
  /* on fait appelle a la fonction reinitialiser selon le type d'usage Client ou Fournisseur grace au polymorphisme*/
	for (Usager*usager : usagers_) {
		usager->reinitialiser();
	}

    // TODO
}

void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{ 
	/* si la condition est vrai on met ajour les produit aux encheres */
	if (montant > produit->obtenirPrix()) {
		produit->mettreAJourEnchere(client, montant);
	 }
    // TODO
}
