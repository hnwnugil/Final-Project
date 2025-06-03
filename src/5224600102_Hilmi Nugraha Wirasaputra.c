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

void addCharacter(char name[], int level, int hp, int mp, int ap, int dp, int exp, char status[]) 
{
    if (characterCount < 100) 
    {
        strcpy(characters[characterCount].name, name);
        characters[characterCount].level = level;
        characters[characterCount].hp = hp;
        characters[characterCount].mp = mp;
        characters[characterCount].ap = ap;
        characters[characterCount].dp = dp;
        characters[characterCount].exp = exp;
        strcpy(characters[characterCount].status, status);
        characterCount++;
    } else 
    {
        printf("Character limit reached.\n");
    }

}

data *searchCharacter(char name[]) 
{
    int low = 0;
    int high = characterCount - 1;
    int mid;
    while (low <= high) 
    {
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

void deleteCharacter(char name[]) 
{
    int low = 0;
    int high = characterCount - 1;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        int cmp = strcmp(characters[mid].name, name);
        if (cmp == 0)
        {
            for (int i = mid; i < characterCount - 1; i++) 
            {
                characters[i] = characters[i + 1];
            }
            characterCount--;
            printf("Character '%s' deleted successfully.\n", name);
            return;
        }
        else if (cmp < 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    printf("Character '%s' not found.\n", name);
}

void sortCharacterbyName(int low, int high) 
{
    //quick sort
    if (low < high) 
    {
        data pivot = characters[low];
        int i = low;
        int j = high;

        while (i < j)
        {
            while (strcmp(characters[i].name, pivot.name) <= 0 && i < high)
            {
                // printf("Comparing %s with pivot %s\n", characters[i].name, pivot.name);
                // printf("i: %d, j: %d\n", i, j);
                
                i++;
            }
            while (strcmp(characters[j].name, pivot.name) > 0 && j > low)
            {
                // printf("Comparing %s with pivot %s\n", characters[j].name, pivot.name);
                // printf("j: %d, i: %d\n", j, i);
                
                j--;
            }
            if (i < j)
            {
                // printf("Swapping %s and %s\n", characters[i].name, characters[j].name);

                data temp = characters[i];
                characters[i] = characters[j];
                characters[j] = temp;
                
                
            }
        }
        // printf("Swapping pivot %s with %s\n", pivot.name, characters[j].name);

        characters[low] = characters[j];
        characters[j] = pivot;

        sortCharacterbyName(low, j - 1);
        sortCharacterbyName(j + 1, high);
    }
}

void updateCharacterStatus(char name[], char newStatus[]) 
{
    data *character = searchCharacter(name);
    if (character != NULL) 
    {
        strcpy(character->status, newStatus);
    } else 
    {
        printf("Character not found.\n");
    }
}

void displayCharacters() 
{
    printf("Character List:\n");
    printf("------------------------------------------------------------------------------\n");
    printf("| %-15s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-8s |\n",

           "Name", "Level", "HP", "MP", "AP", "DP", "EXP", "Status");
    printf("------------------------------------------------------------------------------\n");
    for (int i = 0; i < characterCount; i++) 
    {
        printf("| %-15s | %-5d | %-5d | %-5d | %-5d | %-5d | %-5.2f | %-8s |\n", 
               characters[i].name, 
               characters[i].level, 
               characters[i].hp, 
               characters[i].mp, 
               characters[i].ap, 
               characters[i].dp, 
               characters[i].exp, 
               characters[i].status);
    }
    printf("------------------------------------------------------------------------------\n");

}

int main(int argc, char const *argv[])
{
    addCharacter("Hero", 1, 100, 50, 20, 10, 0.0, "Alive");
    addCharacter("Villain", 2, 120, 60, 25, 15, 0.0, "Alive");
    addCharacter("Sidekick", 1, 80, 40, 15, 5, 0.0, "Alive");
    addCharacter("Mage", 3, 90, 70, 30, 20, 0.0, "Alive");
    addCharacter("Warrior", 4, 150, 80, 35, 25, 0.0, "Alive");
    addCharacter("Rogue", 2, 110, 50, 20, 10, 0.0, "Alive");
    addCharacter("Paladin", 5, 200, 100, 40, 30, 0.0, "Alive");
    addCharacter("Archer", 3, 130, 60, 30, 20, 0.0, "Alive");
    addCharacter("Bard", 2, 90, 50, 20, 10, 0.0, "Alive");

    while (1)
    {
        int choice;
        printf("------------------------------\n");
        printf("              MENU            \n");
        printf("------------------------------\n");
        printf("|%-2d| %-23s |\n", 1, "Add Character");
        printf("|%-2d| %-23s |\n", 2, "Sort Character");
        printf("|%-2d| %-23s |\n", 3, "Search Character");
        printf("|%-2d| %-23s |\n", 4, "Delete Character");
        printf("|%-2d| %-23s |\n", 5, "Update Character Status");
        printf("|%-2d| %-23s |\n", 6, "Display Characters");
        printf("|%-2d| %-23s |\n", 7, "Exit");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            char name[50];
            int level, hp, mp, ap, dp;
            float exp;
            char status[20];
            
            printf("Enter character name: ");
            scanf(" %49[^\n]", name);
            printf("Enter character level: ");
            scanf("%d", &level);
            printf("Enter character HP: ");
            scanf("%d", &hp);
            printf("Enter character MP: ");
            scanf("%d", &mp);
            printf("Enter character AP: ");
            scanf("%d", &ap);
            printf("Enter character DP: ");
            scanf("%d", &dp);
            printf("Enter character EXP: ");
            scanf("%f", &exp);
            printf("Enter character status: ");
            scanf("%15s", status);
            addCharacter(name, level, hp, mp, ap, dp, exp, status);
            printf("Character '%s' added successfully.\n", name);
            break;
        
        case 2:
            sortCharacterbyName(0, characterCount - 1);
            printf("Characters sorted by name.\n");
            break;

        case 3:
            char searchName[50];
            printf("Enter character name: ");
            scanf(" %49[^\n]", searchName);
            sortCharacterbyName(0, characterCount - 1);
            data *foundCharacter = searchCharacter(searchName);
            if (foundCharacter != NULL)
            {
                printf("Character found\n");
                printf("------------------------------------------------------------------------------\n");
                printf("| %-15s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-8s |\n",
                       "Name", "Level", "HP", "MP", "AP", "DP", "EXP", "Status");
                printf("------------------------------------------------------------------------------\n");
                printf("| %-15s | %-5d | %-5d | %-5d | %-5d | %-5d | %-5.2f | %-8s |\n", 
                       foundCharacter->name, 
                       foundCharacter->level, 
                       foundCharacter->hp, 
                       foundCharacter->mp, 
                       foundCharacter->ap, 
                       foundCharacter->dp, 
                       foundCharacter->exp, 
                       foundCharacter->status);
                printf("------------------------------------------------------------------------------\n");
            }
            else
            {
                printf("Character '%s' not found.\n", searchName);
            }
            break;
        case 4:
            char deleteName[50];
            printf("Enter character name: ");
            scanf(" %49[^\n]", deleteName);
            sortCharacterbyName(0, characterCount - 1);
            deleteCharacter(deleteName);
            break;

        case 5:
            char updateName[50];
            char newStatus[20];
            printf("Enter character name: ");
            scanf(" %49[^\n]", updateName);
            printf("Enter new status: ");
            scanf("%s", newStatus);
            updateCharacterStatus(updateName, newStatus);
            break;

        case 6:
            displayCharacters();
            break;
        case 7:
            printf("Exiting the program.\n");
            exit(0);
            break;
        default:
            break;
        }

    }
    
    
    return 0;
}
