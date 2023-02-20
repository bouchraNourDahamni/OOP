#include "ClientPremium.h"
#include <iostream>

ClientPremium::ClientPremium(unsigned int joursRestants)
    : Client(),
      joursRestants_(joursRestants)
{
}

ClientPremium::ClientPremium(const string &nom, const string &prenom, int identifiant,
                             const string &codePostal, unsigned int codeClient,
                             unsigned int joursRestants)
    : Client(nom, prenom, identifiant, codePostal, codeClient),
      joursRestants_(joursRestants)
{
}

unsigned int ClientPremium::obtenirJoursRestants() const
{
    return joursRestants_;
}

double ClientPremium::obtenirTotalAPayer() const
{
	double totalApayer = 0.0;
	for (int i = 0; i < panier_.size(); i++) {
		if (panier_[i]->obtenirPrix() - 5 >= 0) { /* on s'assure qu'apres la remise le prix ne devient pas negative , si non le prix est a zero */
			totalApayer += panier_[i]->obtenirPrix() - 5;
		}
		  
		   
	}
	return totalApayer;
    // TODO
}

void ClientPremium::afficherProfil() const
{
	Client::afficherProfil();
	cout << "       jours restants :" << joursRestants_ << endl;
    // TODO
}

void ClientPremium::modifierJoursRestants(unsigned int joursRestants)
{
    joursRestants_ = joursRestants_;
}
