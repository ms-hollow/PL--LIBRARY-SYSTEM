#include "bookFunctions.h"

//BOOK FUNCTIONS
//The getInfo() function prompts the user to enter information about a book, including all details from the Struct book. It stores this information in the infoBook struct variable.

void getInfoBook(){
    fflush stdin;
    printf("ENTER BOOK TITLE: ");
    scanf("%[^\n]", infoBook.title);
    fflush stdin;
    printf("ENTER AUTHOR: ");
    scanf("%[^\n]", infoBook.author);
    fflush stdin;
    printf("ENTER YEAR PUBLISHED: ");
    scanf("%s", infoBook.year);
    printf("ENTER REFERENCE NUMBER: ");
    scanf("%s", infoBook.refNum);
    printf("ENTER MATERIAL: ");
    scanf("%s", infoBook.material);
    fflush stdin;
    printf("ENTER BOOK CATEGORY: ");
    scanf("%[^\n]", infoBook.category);
    printf("ENTER SHELF NO.: ");
    scanf("%d", &infoBook.shelfNo);
    printf("ENTER TOTAL NO. STOCK: ");
    scanf("%d", &infoBook.totalStock);
    printf("ENTER TOTAL NO. OF BORROWER: ");
    scanf("%d", &infoBook.borrower);
}


//The addBook() function adds a new node to the book linked list in alphabetical order, with the info struct as its data.
int addBook(){
BOOK *q, *p, *n;

    n= (BOOK*) malloc(sizeof(BOOK));    //allocates memory to n.
    *n= infoBook;                           //copy info of the book to n.

    p=q=headBook;                           //point all pointers to head.
    while(p!=NULL && strcmp(infoBook.title, p->title)>=0){
        q=p;
        p=p->nxt;
    }

    if(p==headBook){    //if to insert at the head.
        headBook=n;
    }
    else{           //if to insert in between or at the end.
        q->nxt=n;
    }

    n->nxt=p;  //insert p at the end which contains next node or NULL.
}

//The locateBook() function searches for the book node with a given book reference number and returns a pointer to that node if it is found.
struct book *locateBook(char refNum[]){
BOOK *p;

    p=headBook;
    while(p!=NULL && strcmp(refNum, p->refNum)!=0){
        p=p->nxt;
    }

    return p;
}

//The updateBook() function prompts the user to enter the ref no., and then searches for the corresponding book node in the linked list. If found, it displays information about the book and prompts the user to choose which information to update. It then updates the chosen information if the user confirms the update.
void updateBook() {
BOOK *p;
int choice,info;
char refNum[14];
char update[51];
int updateInt;

    gotoxy(30,5);printf("\033[31m ___________________________________________________________________________________________________________________");
    gotoxy(30,6);printf("|   _                                                                                                               |");
    gotoxy(30,7);printf("|  (_)  ENTER REFERENCE NUMBER OF THE BOOK:                                                                         |");
    gotoxy(30,8);printf("|    \\                                                                                                              |");
    gotoxy(30,9);printf("|___________________________________________________________________________________________________________________|");
    printf("\033[0m");
    gotoxy(74,7);  scanf("%s", refNum);

    //printf("ENTER REFERENCE NUMBER OF THE BOOK: ");
    //scanf("%s", refNum);
    p = locateBook(refNum);

    if(p==NULL){
        gotoxy(74,11); printf("RECORD NOT FOUND!"); system("pause");
    }

    else{

        displayBook(p, 0, p->nxt);  //display(exact position, start sa 1, end if != p->nxt)
        gotoxy(70,15); printf("[1] BOOK TITLE");
        gotoxy(70,16); printf("[2] AUTHOR");
        gotoxy(70,17); printf("[3] YEAR PUBLISHED");
        gotoxy(70,18); printf("[4] BOOK REFERENCE NUMBER");
        gotoxy(70,19); printf("[5] MATERIAL");
        gotoxy(70,20); printf("[6] CATEGORY");
        gotoxy(70,21); printf("[7] SHELF NO.");
        gotoxy(70,22); printf("[8] TOTAL STOCK");
        gotoxy(70,23); printf("[9] NO. OF BORROWER");
        gotoxy(30,24); printf("_____________________________________________________________________________________________________________________\n");
        gotoxy(30,26); printf("CHOOSE THE INFORMATION YOU WISH TO UPDATE (1-7): ");
        scanf("%d", &info);
        fflush stdin;

        system("cls");

        if(info==1){
            gotoxy(30,8); printf("CURRENT TITLE: %s", p->title);
            gotoxy(30,10); printf("ENTER THE UPDATED INFORMATION: ");
        }
        else if (info==2){
            gotoxy(30,8); printf("CURRENT AUTHOR: %s", p->author);
            gotoxy(30,10); printf("ENTER THE UPDATED INFORMATION: ");
        }
        else if (info==3){
            gotoxy(30,8); printf("CURRENT YEAR PUBLISHED: %s", p->year);
            gotoxy(30,10); printf("ENTER THE UPDATED INFORMATION: ");
        }
        else if (info==4){
            gotoxy(30,8); printf("CURRENT BOOK REFERENCE: %s", p->refNum);
            gotoxy(30,10); printf("ENTER THE UPDATED INFORMATION: ");
        }
        else if (info==5){
            gotoxy(30,8); printf("CURRENT MATERIAL: %s", p->material);
            gotoxy(30,10); printf("ENTER THE UPDATED INFORMATION: ");
        }
        else if (info==6){
            gotoxy(30,8); printf("CURRENT CATEGORY: %s", p->category);
            gotoxy(30,10); printf("ENTER THE UPDATED INFORMATION: ");
        }
        else if (info==7){
            gotoxy(30,8); printf("CURRENT SHELF NO.: %s", p->shelfNo);
            gotoxy(30,10); printf("ENTER THE UPDATED INFORMATION: ");
        }
        else if (info==8){
            gotoxy(30,8); printf("CURRENT STOCK: %s", p->currentStock);
            gotoxy(30,10); printf("ENTER THE UPDATED INFORMATION: ");
        }
        else if (info==9){
            gotoxy(30,8); printf("CURRENT NO. BORROWER: %s", p->borrower);
            gotoxy(30,10); printf("ENTER THE UPDATED INFORMATION: ");
        }


        if(info==7 || info==8 || info==9)
            scanf("%d", &updateInt);
        else{scanf("%[^\n]", update);}
        gotoxy(30,12); printf("_____________________________________________________________________________________________________________________\n");
        gotoxy(30,14); printf("ARE YOU SURE TO UPDATE THE RECORD OF %s?", p->title);
        gotoxy(30,16); printf("[1]YES [2]NO : ");
        scanf("%d", &choice);
        if(choice==1){
            switch(info){
                case 1: strcpy(p->title, update); break;
                case 2: strcpy(p->author, update); break;
                case 3: strcpy(p->year, update); break;
                case 4: strcpy(p->refNum, update); break;
                case 5: strcpy(p->material, update); break;
                case 6: strcpy(p->category, update); break;
                case 7: p->shelfNo= updateInt; break;
                case 8: p->totalStock= updateInt; break;
                case 9: p->borrower= updateInt; break;
            }
        }
    }
}

//The delBook() function prompts the user to enter a ref no., and then searches for the corresponding book node in the linked list. If found, it removes the node from the linked list.
void delBook(){
BOOK *p, *q;
int choice;
char refNum[14];

    printf("ENTER THE REFERENCE NUMBER OF THE BOOK: ");
    scanf("%s", refNum);
    p=headBook;
    while(p!=NULL && strcmp(refNum, p->refNum)!=0){
        q=p;
        p=p->nxt;
    }

    if(p==NULL){
        printf("\nRECORD NOT FOUND!\n"); system("pause");
    }

    else{
        displayBook(p, 0, p->nxt);  //display(exact position, start sa 1, end if != p->nxt)
        printf("\nARE YOU SURE TO DELETE THE RECORD OF %s?\n[1]YES [2]NO : ", p->title);
        fflush stdin;
        scanf("%d", &choice);
        if(choice==1){
            if(p==headBook){
                headBook=p->nxt;
            }

            else{
                q->nxt=p->nxt;
            }
            printf("\n_______________________________________________________");
            printf("\nTHE RECORD OF %s DELETED SUCCESSFULLY.\n", p->title); system("pause");
            free(p);
        }
    }
}

//The searchBook() function prompts the user to enter a search a string, and then searches the linked list for any books whose title, author, or category matches the search term. It displays information about any matching books.
void searchBook(){
BOOK *p;
char toSearch[51];
char text[51];
int i, searchCategory;
char* categoryPointer;

<<<<<<< HEAD
    while(searchCategory<0 || searchCategory>5){
        system("cls");
        printf("\nSEARCH BY CATEGORY");
        printf("\n[1] Book Title");
        printf("\n[2] Author");
        printf("\n[3] Year Published");
        printf("\n[4] Material");
        printf("\n[5] Topic Category");
        printf("\nENTER SEARCH CATEGORY [1-5]: ");
        scanf("%d", &searchCategory);
        if(searchCategory<0 || searchCategory>5){
            printf("\nSELECT ONLY FROM 1-5!\n"); system("pause");
        }
    }
=======
    gotoxy(30,5);printf("\033[31m ___________________________________________________________________________________________________________________");
    gotoxy(30,6);printf("|   _                                                                                                               |");
    gotoxy(30,7);printf("|  (_)                                                                                                              |");
    gotoxy(30,8);printf("|    \\                                                                                                              |");
    gotoxy(30,9);printf("|___________________________________________________________________________________________________________________|");
    printf("\033[0m");

    gotoxy(76,15);printf("SEARCH BY CATEGORY");
    gotoxy(76,16);printf("[1] Book Title");
    gotoxy(76,17);printf("[2] Author");
    gotoxy(76,18);printf("[3] Year Published");
    gotoxy(76,19);printf("[4] Material");
    gotoxy(76,20);printf("[5] Topic Category");
    gotoxy(38,7);printf("\033[31mENTER SEARCH CATEGORY [1-5]: ");
    gotoxy(67,7);scanf("%d", &searchCategory);
>>>>>>> 900c0c3484cd7a6775179417f811ecd114545020

    fflush stdin;
    system("cls");

    gotoxy(30,5);printf("\033[31m ___________________________________________________________________________________________________________________");
    gotoxy(30,6);printf("|   _                                                                                                               |");
    gotoxy(30,7);printf("|  (_)  ENTER THE TEXT TO SEARCH:                                                                                   |");
    gotoxy(30,8);printf("|    \\                                                                                                              |");
    gotoxy(30,9);printf("|___________________________________________________________________________________________________________________|");
    printf("\033[0m");
    gotoxy(65,7);  scanf("%[^\n]", toSearch);

    gotoxy(3,12);printf("\033[31m _________________________ _____________________ ________ __________________ ______________ ________________ __________ _____________ __________ _______________");
    gotoxy(3,13);printf("|         TITLE           |       AUTHOR        |  YEAR  | REFERENCE NUMBER |   MATERIAL   |    CATEGORY    | SHELF NO.| TOTAL STOCK | BORROWER | CURRENT STOCK |");
    gotoxy(3,14);printf("|_________________________|_____________________|________|__________________|______________|________________|__________|_____________|__________|_______________|");
    printf("\033[0m");

    p=headBook;
    for(i=-1; p!=NULL;){
        switch(searchCategory){ //ipo-point si pointer kung saang search category.
        case 1: categoryPointer= p->title; break;
        case 2: categoryPointer= p->author; break;
        case 3: categoryPointer= p->year; break;
        case 4: categoryPointer= p->material; break;
        case 5: categoryPointer= p->category; break;
        }

        if(strstr(categoryPointer, toSearch)!=NULL){  //if ang pino-point ni categoryPointer ay may ganitong "substring", print, else next.
            i++;
            gotoxy(5, 6+i); printf("%d.) ", i+1);
            gotoxy(10,6+i); printf("%s", p->title);
            gotoxy(30,6+i); printf("%s", p->author);
            gotoxy(50,6+i); printf("%s", p->year);
            gotoxy(60,6+i); printf("%s", p->refNum);
            gotoxy(80,6+i); printf("%s", p->material);
            gotoxy(95,6+i); printf("%s", p->category);
            gotoxy(110,6+i); printf("%d", p->shelfNo);
            gotoxy(125,6+i); printf("%d", p->totalStock);
            gotoxy(135,6+i); printf("%d", p->borrower);
            gotoxy(145,6+i); printf("%d", p->totalStock-p->borrower);

        }
        p=p->nxt;
    }
    gotoxy(3,19+i); printf("_______________________________________________________________________________________________________________________________________\n");
    gotoxy(3,19+i); system("pause");
}

//The displayBook() function displays information about all the books in the linked list.
void displayBook(struct book *p, int start, int end){
int i;

    gotoxy(10,3); printf("TITLE"); gotoxy(30,3); printf("AUTHOR"); gotoxy(50,3); printf("YEAR");
    gotoxy(60,3); printf("REFERENCE NUMBER");  gotoxy(80,3); printf("MATERIAL"); gotoxy(95,3); printf("CATEGORY");
    gotoxy(110,3); printf("SHELF NO."); gotoxy(120,3); printf("TOTAL STOCK"); gotoxy(135,3); printf("BORROWER");
    gotoxy(145,3); printf("CURRENT STOCK");
    gotoxy(5,5); printf("_______________________________________________________________________________________________________________________________________________\n");

    for(i=start; p!=end; i++){
        gotoxy(5, 6+i); printf("%d.) ", i+1);
        gotoxy(10,6+i); printf("%s", p->title);
        gotoxy(30,6+i); printf("%s", p->author);
        gotoxy(50,6+i); printf("%s", p->year);
        gotoxy(60,6+i); printf("%s", p->refNum);
        gotoxy(80,6+i); printf("%s", p->material);
        gotoxy(95,6+i); printf("%s", p->category);
        gotoxy(110,6+i); printf("%d", p->shelfNo);
        gotoxy(120,6+i); printf("%d", p->totalStock);
        gotoxy(135,6+i); printf("%d", p->borrower);
        gotoxy(145,6+i); printf("%d", p->totalStock-p->borrower);
        p=p->nxt;
    }

    gotoxy(5,6+i+1); printf("_______________________________________________________________________________________________________________________________________________\n");
    gotoxy(5,6+i+3); system("pause");
}

//The save(Book) function prints the information of all the book node in a text file.
void saveBook(){
FILE *fp= fopen("bookDetails.txt", "w+");
BOOK *p;

    if(fp==NULL){
        printf("\nTHE FILE ""bookDetails.txt"" DOES NOT EXIST\n");
        system("pause");
    }

    else{
        p=headBook;
        while(p!=NULL){
            fprintf(fp, "%s\n%s\n%s\n%s %s %s %d %d %d\n\n", p->title, p->author, p->category, p->material, p->year, p->refNum, p->shelfNo, p->totalStock, p->borrower);
            p=p->nxt;
        }
        fclose(fp);
    }
}

//retrieveBook() function retrieves all info from the text file and save each book in the linked list.
void retrieveBook(){
FILE *fp= fopen("bookDetails.txt", "r+");
BOOK *p;

    if(fp==NULL){
        printf("THE FILE ""bookDetails.txt"" DOES NOT EXIST\n");
        system("pause");
    }

    else{
        while(1){
            fflush stdin;
            fscanf(fp, "\n%[^\n]\n", &infoBook.title);
            fflush stdin;
            fscanf(fp, "%[^\n]\n", &infoBook.author);
            fflush stdin;
            fscanf(fp, "%[^\n]\n", &infoBook.category);
            fflush stdin;
                  //\n%[^\n]\n%[^\n]\n", &info.title, &info.author, &info.category);;
            fscanf(fp, "%s %s %s %d %d %d", &infoBook.material, &infoBook.year, &infoBook.refNum, &infoBook.shelfNo, &infoBook.totalStock, &infoBook.borrower);

            //decrypting the retrieved info.
            //strcpy(info.title, decrypt(info.title)); strcpy(info.author, decrypt(info.author)); strcpy(info.category, decrypt(info.category));
            //strcpy(info.year, decrypt(info.year)); strcpy(info.ISBN, decrypt(info.ISBN));

            if(!feof(fp)){
                addBook();
                fflush stdin;
            }
            else{break;}
        }
    }
    fclose(fp);
}

//The menuBook() function displays the main menu of the library catalog program and prompts the user to enter a choice. It returns the user's choice.
int menuBook(int choice){
    while(choice<1 || choice>6){
        system("cls");
        printf("\tMANAGE BOOK RECORD\n");
        printf("\nMENU");
        printf("\n[1] ADD RECORD");
        printf("\n[2] UPDATE RECORD");
        printf("\n[3] DELETE RECORD");
        printf("\n[4] SEARCH RECORD");
        printf("\n[5] DISPLAY ALL RECORDS");
        printf("\n[6] GO BACK");
        printf("\nENTER OPTION: ");
        scanf("%d", &choice);
        if(choice<1 || choice>6){
            printf("\nSELECT 1-6 ONLY!\n");
            system("pause");
        }
    }
    return choice;
}
