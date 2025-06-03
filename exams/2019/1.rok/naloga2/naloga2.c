#include <stdio.h>
#include <stdlib.h>

typedef struct Vozlisce Vozlisce;
struct Vozlisce {
    int podatek;
    Vozlisce *naslednje;
};

Vozlisce* create_list(int arr[], int length){
    Vozlisce* start = (Vozlisce*) malloc(sizeof(Vozlisce));
    start->podatek = arr[0];

    Vozlisce* list = start;

    for(int i = 1; i < length; i++) {
        Vozlisce* new = (Vozlisce*) malloc(sizeof(Vozlisce));
        new->podatek = arr[i];
        list->naslednje = new;
        list = list->naslednje;            
    }
    list->naslednje = NULL;
    
    return start;
}

Vozlisce* obrni(Vozlisce* zacetek) {
    if(zacetek->naslednje == NULL) return zacetek;

    Vozlisce* start = obrni(zacetek->naslednje);

    Vozlisce* node = zacetek->naslednje;
    node->naslednje = zacetek;
    node->naslednje->naslednje = NULL;

    return start;
}

void print_list(Vozlisce* list) {

    printf("[%d]", list->podatek);
    list = list->naslednje;

    while(list != NULL) {
        printf("->[%d]",list->podatek);
        list = list->naslednje;
    }
    printf("\n");
}

int main() {

    int arr[] = {7, 2, 6, 9, 3};
    int length = 5;

    Vozlisce* l = create_list(arr, length);

    print_list(l);

    Vozlisce* new = obrni(l);

    print_list(new);

    return 0;
}