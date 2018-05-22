#include "stdio.h"
#include "math.h"

int main(){
    // max money is the starting money, we can not have more than that.
    unsigned int max_money = 100;
    // buys is the numper of buys we want to make.
    unsigned int buys;
    // the current money
    unsigned int money = max_money;

    printf("vous avez 100€\n");
    printf("svp entrez le nombre d'achats que vous souhaitez faire (max 20)\n");
    scanf("%u", &buys);
    // checks that the buys does not overflow (<0 will be > 20).
    if (buys>20){
        printf("max 20... try again");
        exit(0);
    }
    for (int i = 0; i<buys; i++){
        printf("quel est le cout de l'achat");
        float cout;
        scanf("%f", &cout);
        // checks that no value under 0
        if ((int)(money - cout) > money){
            printf("cout invalide \n");
            exit(0);
        }
        // checks that we have enough money.
        if (money < cout){
            printf("vous ne pouvez pas vous n'avez que %d\n", money);
            exit(0);
        }
        // remove your money !!
        money=round((float)(money -cout));
        printf("il vous reste %u\n", money);
    }
    // this is it.
    printf("il vous reste %u\n", money);
}