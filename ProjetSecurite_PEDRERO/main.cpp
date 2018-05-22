#include <iostream>
#include <string>

using namespace std;

int main()
{
    string commande = "";
    while(commande != "exit") {
        cout << "Tapez un message pour l'afficher ; ou exit pour quitter l'application : " << endl;
        getline(cin, commande);

        string commandeComplete = "echo \"" + commande + "\"";
        system(commandeComplete.c_str());
    }

    return 0;
}
