/********************************************
* Titre: Travail pratique #2 - Client.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#include "Client.h"

Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) :
	nom_{ nom },
	prenom_{ prenom },
	identifiant_{ identifiant },
	codePostal_{ codePostal },
	dateNaissance_{ date },
	monPanier_{ nullptr }
{
} 
/* constrcuteur par copie */
Client::Client(const Client& client):nom_(client.nom_), prenom_(client.prenom_), dateNaissance_(client.dateNaissance_), identifiant_(client.identifiant_), codePostal_(client.codePostal_),monPanier_(nullptr) {
	monPanier_ = new Panier();
	vector <Produit*> contenuPanier2 = client.monPanier_->obtenirContenuPanier();
	for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
		monPanier_->ajouter(contenuPanier2[i]);

	}
}


Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

// Methodes d'acces
string Client::obtenirNom() const
{
	return nom_;
}

string Client::obtenirPrenom() const
{
	return prenom_;
}

int Client::obtenirIdentifiant() const
{
	return identifiant_;
}

string Client::obtenirCodePostal() const
{
	return codePostal_;
}

long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}

// Methodes de modification
void  Client::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Client::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}

void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

void Client::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}

void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// Autres méthodes
void Client::acheter(Produit * prod)
{
	if (monPanier_ == nullptr) {
		monPanier_ = new Panier();
	}
	monPanier_->ajouter(prod);
}

void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}

/*void Client::afficherPanier() const
{
	if (monPanier_ != nullptr) {
		cout << "Le panier de " << prenom_ << ": " << endl;
		monPanier_->afficher();
	}
	else {
		cout << "Le panier de " << prenom_ << " est vide !" << endl;
	}
}*/
void Client::operator= (const Client& client) {
	nom_ = client.nom_;
	prenom_ = client.prenom_;
	identifiant_ = client.identifiant_;
	codePostal_ = client.codePostal_;
	dateNaissance_ = client.dateNaissance_;
	if (this != &client) {
		delete monPanier_;
		monPanier_ = new Panier();
		vector <Produit*> contenuPanier2 = client.monPanier_->obtenirContenuPanier();
		for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
			monPanier_->ajouter(contenuPanier2[i]);
			 
       }
		 
	}
	 
}
ostream& operator<<(ostream& flux, const Client & client) {
	 
	if (client.monPanier_ == nullptr) {
		flux << "le panier de " << client.prenom_ << " est vide ! " << endl;
    }
	else {
		flux << "le panier de " << client.prenom_ << ":" << endl ;
		operator<<(flux, *client.monPanier_);
	}
	return flux;
}
bool Client::operator==(const int id)const {
	return(identifiant_ == id);
}
bool operator==(const int id, const Client& client){
	return (id == client.identifiant_);
}




