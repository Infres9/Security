
/*
README: 
Ce programme récupère 4 entrées de l'utilisateur (en 4 fois ou en une fois)
Effectue la somme des quatre nombre et l'affiche
Quand une entrée invalide est donnée, le nombre est considéré comme valant 0
Il est possible de rentrer plusieurs nombre en une fois, en les séparant par un caractère qui n'est pas un nombre
*/

#include <iostream>
#include <string>
#include <limits>

int main(void)
{
    
    while(true){
        int value;
        int *arry = new int[4];

        std::cin.clear();

        for(int i = 0; i < 4;++i){
            std::cout << "Ecrire un nombre : \n";
            if(!(std::cin >> value)){//Mauvaise valeur
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                value = 0;
            }
            arry[i] = value;
        }
        
        long long somme = 0;
        for(int i = 0; i < 4; ++i)
            somme += arry[i];
        
        std::cout << "Somme = " << somme << std::endl;
        
        delete arry;
        
    }
    
}
