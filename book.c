#include <stdio.h>
struct Book {
    char title[80];
    char author[80];
    float price;
};

int main () {
    struct Book bk[3] = 
        {{"The Hunger Games", "Suzanne Collins", 999},
        {"Harry Potter", "J.K. Rowling", 1399},
        {"Your Name", "Makoto Shinkai", 799}};

    int high = 0, low = 0;

    for (int i = 0; i < 2; i++) {
        if (bk[i].price < bk[i + 1].price) {
            high = i + 1;
        }
    }

    for (int i = 0; i < 2; i++) {
        if (bk[i].price > bk[i + 1].price) {
            low = i + 1;
        }
    }
    
    printf("%s, %s, %.2f", bk[high].title, bk[high].author, bk[high].price);
    printf("\n%s, %s, %.2f", bk[low].title, bk[low].author, bk[low].price);
}

