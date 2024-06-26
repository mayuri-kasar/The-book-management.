#include <stdio.h>
#include <string.h>

typedef struct book 
{
    char bookname[20];
    char id[10];
    char authorname[20];
    double price;
    double rating;
} book;

void storebook(book *, int);
void displayer(book *, int);
void addbook(book *, int);
void removebook(book *, int *);
void searchbook(book *, int);
void searchbyname(book *, int);
void searchbyid(book *, int);
void updatebook(book *, int);
void top3(book *, int);
void maxrating(book *, int);

int main() 
{
    int n, choice;
    char c;
    printf("Enter No of books to add in store: ");
    scanf("%d", &n);
    book arr[100];
    storebook(arr, n);

    do {
        printf("\nMENU\n1. Add book\n2. Remove book\n3. Search book\n4. Update book\n5. Top 3\n6. Display book\n7. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addbook(arr, n);
                n++;
                break;
            case 2:
                removebook(arr, &n);
                break;
            case 3 :
                searchbook(arr, n);
                break;
            case 4:	 
                updatebook(arr, n);
                break;
            case 5:
                top3(arr, n);
                break;
            case 6:
                displayer(arr, n);
                break;
            case 7:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
        printf("\nDo You want to Continue (y/n): ");
        fflush(stdin);
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');

    return 0;
}

void storebook(book *arr, int n) 
{
    int i;
    for (i = 0; i < n; i++) {
        fflush(stdin);
        printf("Book Name: ");
        gets(arr[i].bookname);
        printf("Book ISBN: ");
        scanf("%s", &arr[i].id);
        printf("Book Author name: ");
        scanf("%s", &arr[i].authorname);
        printf("Book price: ");
        scanf("%lf", &arr[i].price);
        printf("Book rating: ");
        scanf("%lf", &arr[i].rating);
    }
}

void addbook(book *arr, int n) 
{
    fflush(stdin);
    printf("Book Name: ");
    gets(arr[n].bookname);
    printf("Book ISBN: ");
    scanf("%s", &arr[n].id);
    printf("Book Author name: ");
    scanf("%s", &arr[n].authorname);
    printf("Book Price: ");
    scanf("%lf", &arr[n].price);
    printf("Book rating: ");
    scanf("%lf", &arr[n].rating);
    printf("Book with ISBN Number %s added successfully.\n", arr[n].id);
}

void removebook(book *arr, int *n) 
{
    char id[10];
    printf("Enter the Book ISBN Number to remove: ");
    scanf("%s", id);

    int found = 0;
    for (int i = 0; i<*n; i++)
     {
        if (strcmp(arr[i].id, id) == 0) {
            found = 1;
            for (int j = i; j < *n; j++) {
                arr[j] = arr[j + 1];
            }
            (*n)--;
            printf("Book with ISBN Number %s removed.\n", id);
            break;
        }
    }
    if (found == 0) {
        printf("Book with ISBN Number %s not found.\n", id);
    }
}

void searchbook(book *arr, int n) {
    int choice;
    printf("\nSearch book By:\n1. Book Name\n2. ISBN No\nEnter Choice for Search: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            searchbyname(arr, n);
            break;
        case 2:
            searchbyid(arr, n);
            break;
        default:
            printf("Invalid Choice! Please enter a valid choice.\n");
    }
}

void searchbyname(book *arr, int n) 
{
    int count = 0;
    char searchname[20];
    fflush(stdin);
    printf("Enter name You want to search: ");
    gets(searchname);

    for (int i = 0; i < n; i++) {
        if (strcasecmp(arr[i].bookname, searchname) == 0) {
            count++;
            printf("\n%s\nBook ISBN: %s\nBook Author: %s\n", arr[i].bookname, arr[i].id, arr[i].authorname);
        }
    }

    if (count == 0) {
        printf("Book not found! Please enter a valid Bookname.\n");
    }
}

void searchbyid(book *arr, int n) 
{
    int count = 0;
    char no[10];
    printf("Enter Book ISBN No You want to search: ");
    scanf("%s", no);

    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].id, no) == 0) {
            count++;
            printf("\n%s\nBook ISBN: %s\nBook Author: %s\n", arr[i].bookname, arr[i].id, arr[i].authorname);
        }
    }

    if (count == 0) {
        printf("Book not found! Please enter a valid ISBN No.\n");
    }
}

void updatebook(book *arr, int n) 
{
    int count = 0;
    char no[10];
    printf("Enter Book ISBN No You want to update: ");
    scanf("%s", no);

    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].id, no) == 0) {
     
            int choice;
            printf("\nUpdate book:\n1. Price\n2. Rating\nEnter choice: ");
            scanf("%d", &choice);
              count++;
            switch (choice) {
                case 1:
                    printf("Update price: ");
                    scanf("%lf", &arr[i].price);
                    printf("Book with ISBN %s price updated.\n", no);
                    break;
                case 2:
                    printf("Update rating: ");
                    scanf("%lf", &arr[i].rating);
                    printf("Book with ISBN %s rating updated.\n", no);
                    break;
                default:
                    printf("Invalid choice! Please enter a valid choice.\n");
            }
        }
    }

    if (count == 0) {
        printf("Book not found! Please enter a valid ISBN number.\n");
    }
    displayer(arr, n);
}
void top3(book *arr, int n) 
{
    int choice;
    printf("\nSearch Top 3 Books By:\n1. Rating\nEnter Choice for Search: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            maxrating(arr, n);
            break;
        default:
            printf("Invalid Choice! Please enter a valid choice.\n");
    }
}

void maxrating(book *arr, int n) 
{
    int i, j;
    book temp;

    for (i = 0; i < n ; i++) {
        for (j = 0; j < n; j++) {
            if (arr[j].rating < arr[j + 1].rating) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                
                arr[j + 1] = temp;
            }
        }
    }

    printf("Top 3 books with the highest rating:\n");
    for (i = 0; i < 3 && i < n; i++) {
        printf("Name: %s\nISBN: %s\nAuthor: %s\nPrice: %lf\nRating: %lf\n",
               arr[i].bookname, arr[i].id, arr[i].authorname, arr[i].price, arr[i].rating);
    }
}
                                 /*** BOOK LIST DISPALY***/
void displayer(book *arr, int n) {
    printf("| Book Name      | ISBN No   | Author Name | Price   | Rating\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("|----------------|-----------|-------------|---------|--------|\n");
        printf("| %-15s | %-8s | %-11s | %-7.2lf | %-6.2lf\n", arr[i].bookname, arr[i].id, arr[i].authorname, arr[i].price, arr[i].rating);
    }
    printf("|----------------|-----------|-------------|---------|--------|\n");
}