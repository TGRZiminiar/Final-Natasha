#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"


void AddProduct(){
    
    Product product;

    FILE *fp;
    system("cls");
    printf("\n========= Add Product To Store =========");

    printf("\nEnter Product Name:\t");
    // fgets(product.productName, 50, stdin);
    // product.productName[strlen(product.productName)-1] = 0;
    char temp[50];
    fgets(temp, 50,stdin);
    temp[strlen(temp)-1] = 0;
    strcpy(product.productName, temp);

    printf("\nEnter Product Quantity:\t");
    scanf("%d",&product.productQuantity);
    
    printf("\nEnter Product Price:\t");
    scanf("%d",&product.productPrice);

    printf("\nEnter Product Minimum Quantity:\t");
    scanf("%d",&product.minimumQuantity);

    printf("\n\t------------- Product Detail ---------------\n\n");
    printf("\tProduct Name              :\t%s\n", product.productName);
    printf("\tProduct Price             :\t%d\n", product.productPrice);
    printf("\tProduct Quantity          :\t%d\n", product.productQuantity);
    printf("\tProduct minimumQuantity   :\t%d\n", product.minimumQuantity);
    printf("\n\n");
    printf("\nConfirm To Add This Product? [y/n]:\t");
    char saveProduct;
    scanf("%s",&saveProduct);
    printf("THIS IS PRODUCT NAME %s\n",product.productName);

    if(saveProduct == 'y'){
        fp = fopen("Product.dat","a+");
        fwrite(&product, sizeof(Product), 1, fp);
        if(fwrite != 0){
            printf("\nSuccessfully saved");
        }
        else{
            printf("\nError saving");
        } 
        fclose(fp);
    }
}

void PrintProduct(){
    Product product;
    FILE *fp;

    fp = fopen("Product.dat","r");
    printf("\n ****Product Information****\n");
    int i = 1;
    while (fread(&product, sizeof(Product), 1, fp)){
        printf("----------- Product Number : %d -------------\n\n",i);
        printf("\tProduct Name              :\t%s\n", product.productName);
        printf("\tProduct Price             :\t%d\n", product.productPrice);
        printf("\tProduct Quantity          :\t%d\n", product.productQuantity);
        printf("\tProduct minimumQuantity   :\t%d\n", product.minimumQuantity);
        printf("\n\n");
        i++;
    }
    fclose(fp);    
}