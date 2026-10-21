
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Representation d'un client
struct Client {
    int ticket;
    string nom;
    int duree;
    int priorite;
};

// Representation d'un guichet
struct Guichet {
    int numero;
    int charge;
    vector<Client> clients;
};

// Recherche le guichet le moins charge
int trouverGuichetMoinsCharge(const vector<Guichet>& guichets) {
    int indiceMin = 0;

    for (int i = 1; i < static_cast<int>(guichets.size()); i++) {
        if (guichets[i].charge < guichets[indiceMin].charge) {
            indiceMin = i;
        }
    }

    return indiceMin;
}

// Affiche la charge de chaque guichet
void afficherGuichets(const vector<Guichet>& guichets) {
    for (const Guichet& g : guichets) {
        cout << "Guichet " << g.numero
             << " : " << g.charge << " minutes"
             << " | Nombre de clients : " << g.clients.size()
             << endl;
    }
}

// Affecte un client au guichet le moins charge
void affecterClient(vector<Guichet>& guichets, const Client& client) {
    if (guichets.empty()) {
        cout << "Erreur : aucun guichet disponible." << endl;
        return;
    }

    int indice = trouverGuichetMoinsCharge(guichets);

    guichets[indice].clients.push_back(client);
    guichets[indice].charge += client.duree;

    cout << "Client " << client.nom
         << " (ticket " << client.ticket << ") affecte au guichet "
         << guichets[indice].numero << endl;
}

int main() {
    int n_guichets;

    cout << "============================\n";
    cout << "       SMARTQUEUE C++\n";
    cout << " Gestion intelligente des files\n";
    cout << "============================\n\n";

    cout << "Nombre de guichets : ";
    cin >> n_guichets;

    if (cin.fail() || n_guichets <= 0 || n_guichets > 100) {
        cout << "Erreur : entre 1 et 100 guichets." << endl;
        return 1;
    }

    // Initialisation des guichets
    vector<Guichet> guichets(n_guichets);

    for (int i = 0; i < n_guichets; i++) {
        guichets[i].numero = i + 1;
        guichets[i].charge = 0;
    }

    int n_clients;
    cout << "\nNombre de clients : ";
    cin >> n_clients;

    if (cin.fail() || n_clients < 0 || n_clients > 10000) {
        cout << "Erreur : entre 0 et 10000 clients." << endl;
        return 1;
    }

    vector<Client> clients;
    int somme = 0;
    int min_duree = 0;
    int max_duree = 0;

    // Saisie des clients
    for (int i = 0; i < n_clients; i++) {
        Client c;

        c.ticket = i + 1;
        c.priorite = 0;

        cout << "\nNom du client " << c.ticket << " : ";
        cin >> c.nom;

        cout << "Duree de service en minutes : ";
        cin >> c.duree;

        if (cin.fail() || c.duree <= 0) {
            cout << "Erreur : la duree doit etre positive." << endl;
            return 1;
        }

        if (i == 0) {
            min_duree = c.duree;
            max_duree = c.duree;
        } else {
            if (c.duree < min_duree) {
                min_duree = c.duree;
            }

            if (c.duree > max_duree) {
                max_duree = c.duree;
            }
        }

        somme += c.duree;
        clients.push_back(c);
    }

    // Affichage des statistiques
    cout << "\n========== ANALYSE ==========\n";
    cout << "Nombre de clients : " << n_clients << endl;

    if (n_clients > 0) {
        double moyenne = static_cast<double>(somme) / n_clients;

        cout << "Duree moyenne : " << moyenne << " minutes" << endl;
        cout << "Duree minimale : " << min_duree << " minutes" << endl;
        cout << "Duree maximale : " << max_duree << " minutes" << endl;
    } else {
        cout << "Aucun client a traiter." << endl;
    }

    // Repartition automatique
    for (const Client& c : clients) {
        affecterClient(guichets, c);
    }

    // Affichage de la solution
    cout << "\n========== REPARTITION ==========\n";

    for (const Guichet& g : guichets) {
        cout << "\nGuichet " << g.numero << " - Clients : ";

        if (g.clients.empty()) {
            cout << "aucun";
        } else {
            for (const Client& c : g.clients) {
                cout << c.ticket << "(" << c.nom << ") ";
            }
        }

        cout << "\nCharge totale : " << g.charge << " minutes\n";
    }

    // Calcul du temps de finition global
    int tempsFinition = 0;

    for (const Guichet& g : guichets) {
        if (g.charge > tempsFinition) {
            tempsFinition = g.charge;
        }
    }

    cout << "\nTemps de finition global : "
         << tempsFinition << " minutes" << endl;

    cout << "\nSimulation terminee." << endl;

    return 0;
}
