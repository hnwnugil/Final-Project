#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    char name[50];
    int level;
    int hp;
    int mp;
    int ap;
    int dp;
    float exp;
    char status[20];
} data;

data characters[100];

static int characterCount = 0;

void addCharacter(char name[], int level, int hp, int mp, int ap, int dp, int exp, char status[]) {
    if (characterCount < 100) {
        strcpy(characters[characterCount].name, name);
        characters[characterCount].level = level;
        characters[characterCount].hp = hp;
        characters[characterCount].mp = mp;
        characters[characterCount].ap = ap;
        characters[characterCount].dp = dp;
        characters[characterCount].exp = exp;
        strcpy(characters[characterCount].status, status);
        characterCount++;
    } else {
        printf("Character limit reached.\n");
    }

}

data *searchCharacter(char name[]) {
    int low = 0;
    int high = characterCount - 1;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        int cmp = strcmp(characters[mid].name, name);
        if (cmp == 0)
        {
            return &characters[mid];
        }
        else if (cmp < 0) 
        {
            low = mid + 1;
        } else 
        {
            high = mid - 1;
        }
        
    }
    return NULL;
}

void deleteCharacter(char name[]) {

}

void swap(int i, int j) {
    data temp = characters[i];
    characters[i] = characters[j];
    characters[j] = temp;
}

int partition(int low, int high) {
    data *pivot = &characters[low];
    int i = low;
    int j = high;

    while (i < j)
    {

        while (strcmp(characters[i].name, pivot->name) <= 0 && i < high)
        {
            i++;
        }
        while (strcmp(characters[i].name, pivot->name) > 0 && j > low)
        {
            j--;
        }
        if (i < j)
        {
            swap(i, j);
        }
    }
    swap(low, j);
    return j; // Return the partition index
}

void sortCharacterbyName(int low, int high) {
    //quick sort
    if (low < high) {
        int pi = partition(low, high);
        
        sortCharacterbyName(low, pi - 1);
        sortCharacterbyName(pi + 1, high);
    }
}

void updateCharacterStatus(char name[], char newStatus[]) {

}

void displayCharacters() {
    printf("Character List:\n");
    printf("Name\tLevel\tHP\tMP\tAP\tDP\tEXP\tStatus\n");
    for (int i = 0; i < characterCount; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%.2f\t%s\n", 
               characters[i].name, 
               characters[i].level, 
               characters[i].hp, 
               characters[i].mp, 
               characters[i].ap, 
               characters[i].dp, 
               characters[i].exp, 
               characters[i].status);
    }
}

int main(int argc, char const *argv[])
{
    addCharacter("Hero", 1, 100, 50, 20, 10, 0.0, "Alive");
    addCharacter("Villain", 2, 120, 60, 25, 15, 0.0, "Alive");
    addCharacter("Sidekick", 1, 80, 30, 15, 5, 0.0, "Alive");
    addCharacter("Wizard", 3, 90, 70, 30, 20, 0.0, "Alive");
    addCharacter("Rogue", 2, 110, 40, 22, 12, 0.0, "Alive");
    addCharacter("Paladin", 4, 130, 80, 35, 25, 0.0, "Alive");
    addCharacter("Archer", 2, 95, 55, 18, 8, 0.0, "Alive");
    addCharacter("Bard", 1, 85, 45, 17, 7, 0.0, "Alive");
    addCharacter("Monk", 3, 105, 65, 28, 18, 0.0, "Alive");
    addCharacter("Druid", 2, 115, 75, 20, 10, 0.0, "Alive");
    addCharacter("Necromancer", 5, 140, 90, 40, 30, 0.0, "Alive");
    addCharacter("Knight", 3, 125, 85, 32, 22, 0.0, "Alive");
    addCharacter("Assassin", 4, 135, 95, 38, 28, 0.0, "Alive");
    addCharacter("Cleric", 2, 100, 70, 20, 15, 0.0, "Alive");
    addCharacter("Sorcerer", 3, 110, 80, 30, 20, 0.0, "Alive");
    addCharacter("Berserker", 4, 150, 100, 45, 35, 0.0, "Alive");
    addCharacter("Ranger", 2, 105, 60, 20, 10, 0.0, "Alive");
    addCharacter("Warlock", 3, 120, 75, 35, 25, 0.0, "Alive");
    displayCharacters();
    printf("\n");
    printf("\n");
    sortCharacterbyName(0, characterCount - 1);
    displayCharacters();
    
    return 0;
}
