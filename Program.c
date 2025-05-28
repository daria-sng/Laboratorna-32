#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define N 8

struct campsite {
    char title [70];
    char location [80];
    int cost_night;
};

int main(){
    system("chcp 65001");
    struct campsite array[N] = {
        {"White Elephant Camp", "Ukraine", 24},
        {"Camping Sonnenland Lutzmannsburg", "Austria", 32},
        {"NaturCamp Steinwald", "Germany", 26},
        {"Camping Murinsel", "Austria", 30},
        {"Insel-Camp Fehmarn", "Germany", 37},
        {"Thermenland Camping Bad Waltersdorf", "Austria", 33},
        {"Recreatiepark Goorzicht", "Netherlands", 19},
        {"Camp MondSeeLand", "Austria", 36}
    };

    char input_location [80];
    printf("Введіть місцевість ( Ukraine / Austria / Germany / Netherlands ): ");
    scanf("%s", input_location);

    int input_cost;
    printf("Введіть значення ( вартість в € ) для виокремлення дешевого варіанту : ");
    scanf("%d", &input_cost);
    
    FILE *information = fopen("Campsite.txt", "w");
    if(information == NULL){
        printf("Не відбулося відкривання файлу Campsite.txt, спробуйте ще раз!");
        exit(1);
    }
    int i;
    int flag = 0;
    for(i=0; i<N; i+=1){
        if((strcmp(array[i].location, input_location) == 0) && array[i].cost_night < input_cost){
            fprintf(information, "%d кемпінг: \n", i+1);
            printf("%d кемпінг: \n", i+1);
            fprintf(information, "Назва: %s\nМісце розташування: %s\nВартість 1 доби перебування в € : %d\n", array[i].title, array[i].location, array[i].cost_night);
            printf("Назва: %s\nМісце розташування: %s\nВартість 1 доби перебування в €: %d\n", array[i].title, array[i].location, array[i].cost_night);
            flag = 1;
        }
    }
    if(flag == 0){
        fprintf(information, "У програмі немає вказаної місцевості або відсутній дешевий варіант кемпінгу, вибачте за незручності");
        printf("У програмі немає вказаної місцевості або відсутній дешевий варіант кемпінгу, вибачте за незручності");
    }
    fclose (information);
    return 0;
}