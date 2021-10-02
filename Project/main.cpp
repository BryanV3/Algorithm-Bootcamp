#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// item struct
struct items
{
    char name[100];
    int price;
    int stock;
};

// global variables
const int MAX_AMOUNT = 100; // max amount of items

// Menu functions
void mainMenu();
void staffLogin();
void staffMenu();
void customerMenu();
void ownerMenu();

// functions for items
void displayItems();
void addItem();
void printItem(items item); // print an item's properties
void inputItem(items item); // get an item's properties from user
void deleteItem();

// utility
void sentenceCase(char s[]);

int main(){
    mainMenu();
    return 0;
}

//display main menu
void mainMenu()
{
    int choice = -1;
    system("clear");
    puts("Welcome to The Fisherman Market App!");
    puts("What Can We Do To Help You?");
    puts("1. Staff");
    puts("2. Customer");
    puts("3. Shop Owner");
    puts("4. Exit");
    printf(">> ");
    
   
    do
    {
        scanf("%d", &choice);
    }while(!(1 <= choice && choice <= 4));
    
    switch(choice)
    {
        case 1 :
        staffLogin();
        break;

        case 2 :
        customerMenu();
        break;

        case 3 :
        ownerMenu();
        break;

        case 4 :
        puts("Thanks For Using The Program!\n");
        break;
    }
}

// staff login screen
void staffLogin(){
    system("clear");
    char data_id[4][20] = {"2540119280", "2501983982", "123456789", "1234567890"};
    char id[20];
    bool is_valid = false;
    printf("Enter ID :");
    scanf("%s", id);
    
    for(int i = 0; i < 4; i++)
    {
        if(strcmp(id, data_id[i]) == 0)
        {
            is_valid = true;
            break;
        }
    }

    if(is_valid == true)
    {
        printf("Welcome %s!\n", id);
        staffMenu();
    }
    else
    {
        printf("Invalid ID\n");
        getchar();
        puts("Click enter to go back to menu!");
        getchar();
        mainMenu();
    }
}

// display staff menu
void staffMenu()
{
    system("clear");
    puts("UNDER CONSTRUCTION");
} 

// display customer menu
void customerMenu()
{
    system("clear");
    puts("UNDER CONSTRUCTION");
}

// display owner menu
void ownerMenu()
{
    system("clear");
    int choice;
    puts("Welcome Owner!");
    puts("What do you want to do, Boss?");
    puts("1. Display items");
    puts("2. Add item");
    puts("3. Delete item");
    puts("4. Exit");
    printf(">> ");

    do
    {
        scanf("%d", &choice);
    }while(!(1 <= choice && choice <= 4));
    
    switch(choice)
    {
        case 1 :
        displayItems();
        break;

        case 2 :
        addItem();
        break;

        case 3 :
        deleteItem();
        break;

        case 4 :
        printf("Bye bye, Boss!\n");
        break;
    }
}

void displayItems()
{
    system("clear");
    FILE *items_file = fopen("store items.txt", "r");

    // check if item file exists
    if(!items_file)
    {
        puts("WHERE THE HECK IS THE FILE");
        return;
    }
    
    items item[MAX_AMOUNT];

    // get items information
    int index = 0;
    while(fscanf(items_file, "%[^#] # %d # %d\n", item[index].name, &item[index].price, &item[index].stock) != EOF) 
    {
        index++;
    }

    // print items information
    for(int i = 0; i < index; i++)
    {
        printItem(item[i]);
    }

    fclose(items_file);

	getchar();
    puts("Click enter to go back to menu!");
    getchar();
    ownerMenu();
}

void addItem()
{
	FILE *items_file = fopen("store items.txt", "a");
	
	items item;
	inputItem(item);

    // print item information into database
	fprintf(items_file, "%s # %d # %d\n", item.name, item.price, item.stock);

	// print added item's properties
	printf("\nItem added succesfully!\n");
	printItem(item);
	
	fclose(items_file);

	getchar();
    puts("Click enter to go back to menu!");
    getchar();
    ownerMenu();
}

// input information to an item struct
void inputItem(items item){
    system("clear");
	getchar();
	printf("Enter item name : ");
	scanf("%[^\n]", item.name);
    sentenceCase(item.name);
	printf("Enter item price : Rp ");
	scanf("%d", &item.price);
	printf("Enter item stock amount : ");
	scanf("%d", &item.stock);
}

// prints an item's properties
void printItem(items item)
{
    printf("Name  : %s\n", item.name);
    printf("Price : Rp %d\n", item.price);
    printf("Stock : %d\n\n", item.stock);
}

// capitalize a string using sentence case. ex : "Like this string"
void sentenceCase(char s[]){
    s[0] = toupper(s[0]);
    for(int i = 1; s[i] != '\0'; i++){
        s[i] = tolower(s[i]);
    }
}

void deleteItem(){
    puts("UNDER CONSTRUCTION");
    // use sorted file
    // input the file
    // search the file
}
