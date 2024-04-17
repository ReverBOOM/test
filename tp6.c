#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa{
    char nama[50];
    char nim[50];
    float ipk;
    struct Mahasiswa *next;
} Mahasiswa;

int main() {
    Mahasiswa* head = NULL;
    Mahasiswa* current = NULL;
    Mahasiswa* prev = NULL;
    Mahasiswa* newMahasiswa = NULL;

    int selector;
    while(1){
        printf("1. Add Mahasiswa\n");
        printf("2. Remove Mahasiswa\n");
        printf("3. Print Mahasiswa\n");
        printf("4. Exit\n");
        printf("Select: ");
        scanf("%d", &selector);
        printf("\n");

        if(selector == 1){
            Mahasiswa* newMahasiswa = (Mahasiswa*)malloc(sizeof(Mahasiswa));
            printf("Nama: ");
            scanf("%s", newMahasiswa->nama);
            printf("NIM: ");
            scanf("%s", newMahasiswa->nim);
            printf("IPK: ");
            scanf("%f", &newMahasiswa->ipk);
            printf("\n");
            newMahasiswa->next = head;
            head = newMahasiswa;

        } else if(selector == 2){
            char nim[50];
            printf("NIM: ");
            scanf("%s", nim);
            printf("\n");

            Mahasiswa* current = head;
            Mahasiswa* prev = NULL;
            while(current != NULL){
                if(strcmp(current->nim, nim) == 0){
                    if(prev == NULL){
                        head = current->next;
                    } else {
                        prev->next = current->next;
                    }
                    free(current);
                    break;
                }
                prev = current;
                current = current->next;
            }
        } else if(selector == 3){
            Mahasiswa* current = head;
            while(current != NULL){
                printf("Nama: %s\n", current->nama);
                printf("NIM: %s\n", current->nim);
                printf("IPK: %.2f\n", current->ipk);
                printf("\n");

                current = current->next;
            }
        } else if(selector == 4){
            break;
        }

    }

    return 0;
}