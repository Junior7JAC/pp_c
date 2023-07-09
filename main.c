#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DateAngajat
{
    char nume[60], nrTelefon[20], adresa[70], postul[50], data[15];
    float salariul;
} DateAngajat;

DateAngajat angajat[300];
FILE* ptr;
int n;

void CautareAngajat();
void CautaDupaNume();
void CautaDupaPost();
void StergereAngajat();
void AfisareAngajati();
void ActualizareAngajat();
void AdaugareAngajat();
void Meniu();

void Meniu()
{
    int optiune;

    do
    {
        printf("\n");
        printf("===================\n");
        printf("     MENIU     \n\n");
        printf("Alegeti o ramura:\n");
        printf("1. Cautare Angajat\n");
        printf("2. Stergere Angajat\n");
        printf("3. Afisare Angajati\n");
        printf("4. Actualizare Angajat\n");
        printf("5. Adaugare Angajat\n");
        printf("6. Exit\n");
        printf("===================\n");

        scanf("%d",&optiune);
        if(optiune==1)
            CautareAngajat();
        else if (optiune==2)
            StergereAngajat();
        else if (optiune==3)
            AfisareAngajati();
        else if (optiune==4)
            ActualizareAngajat();
        else if (optiune==5)
            AdaugareAngajat();
        else if (optiune==6)
            return ;
        else printf("Alegeti o optiune existenta!\n");
    }
    while(1==1);

}

void CautareAngajat()
{
    int optiune;
    if(n==1)
    {
        printf("Nu se poate cauta deoarece nu exista angajati.\n");
        return ;
    }
    do
    {
        printf("Cauta angajatul dupa:\n");
        printf("1. Nume\n");
        printf("2. Postul Ocupat\n");
        printf("3. Inapoi\n");
        scanf("%d",&optiune);
        if (optiune==1)
            CautaDupaNume();
        else if (optiune==2)
            CautaDupaPost();
        else if (optiune==3)
            return ;
        else
        {
            printf("Date incorecte!\n");
        }
    }
    while(optiune>3 || optiune<1);
}

void CautaDupaNume()
{
    int i=1,ok=0;
    char Nume[60];
    printf("Numele:\n");
    fflush(stdin);
    gets(Nume);
    for(i=1; i<n; i++)
    {
        if(strstr(angajat[i].nume,Nume))
        {
            printf("%s %s %s %s %s %.2f\n",angajat[i].nume,angajat[i].nrTelefon,angajat[i].adresa,angajat[i].postul,angajat[i].data,angajat[i].salariul);
            ok=1;
        }
    }
    if (ok==0)
    {
        printf("Nu exista!");
    }
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void CautaDupaPost()
{
    int i=1,ok=0;
    char Post[50];
    printf("Postul:\n");
    fflush(stdin);
    gets(Post);
    for(i=1; i<n; i++)
    {
        if(strstr(angajat[i].postul,Post))
        {
            printf("%s %s %s %s %s %.2f\n",angajat[i].nume,angajat[i].nrTelefon,angajat[i].adresa,angajat[i].postul,angajat[i].data,angajat[i].salariul);
            ok=1;
        }
    }
    if (ok==0)
    {
        printf("Nu exista!\n");
    }
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void AdaugareAngajat()
{
    printf("Introduceti datele angajatului in aceasta ordine:\nNume complet, numar de telefon, adresa de email, postul detinut, data angajarii, salariul\n\n");
    scanf("\n%[^,],%[^,],%[^,],%[^,],%[^,],%f", angajat[n].nume, angajat[n].nrTelefon, angajat[n].adresa, angajat[n].postul, angajat[n].data, &angajat[n].salariul);
    n++;
    ScriereDinFsr();
}

void AfisareAngajati()
{
    int i=1;
    for(i=1; i<n; i++)
    {
        printf("%s %s %s %s %s %.2f\n",angajat[i].nume,angajat[i].nrTelefon,angajat[i].adresa,angajat[i].postul,angajat[i].data,angajat[i].salariul);
    }
    if(i==1)
        printf("Nu exista angajati.\n");
}

void StergereAngajat()
{
    int i=1,ok=1,k=1;
    if(n==1)
    {
        printf("Nu se poate sterge deoarece nu exista angajati.\n");
        return ;
    }
    char numele[60];
    printf("Numele angajatului:\n");
    fflush(stdin);
    gets(numele);
    printf("\n");
    for(i=1; i<n; i++)
    {
        if(strstr(angajat[i].nume,numele))
        {
            printf("%d. %s %s %s %s %s %.2f\n",k,angajat[i].nume,angajat[i].nrTelefon,angajat[i].adresa,angajat[i].postul,angajat[i].data,angajat[i].salariul);
            ok=1;
            k++;
        }
    }
    if(k==1)
    {
         printf("Nu exista!\n");
         return ;
    }
    int optiune;
    do{
    scanf("%d",&optiune);
    k=0;
    i=1;
    while(k<optiune && i<n)
    {
        if(strstr(angajat[i].nume,numele))
        {
            k++;
        }
        i++;
    }
    if(k!=optiune || optiune<1)
    {
        printf("Aceasta optiune nu exista!\n");
        return ;
    }
    }while(k!=optiune || optiune<1);
    i--;
    for(int j=i; j<n-1; j++)
    {
        strcpy(angajat[j].nume,angajat[j+1].nume);
        strcpy(angajat[j].nrTelefon,angajat[j+1].nrTelefon);
        strcpy(angajat[j].adresa,angajat[j+1].adresa);
        strcpy(angajat[j].postul,angajat[j+1].postul);
        strcpy(angajat[j].data,angajat[j+1].data);
        angajat[j].salariul=angajat[j+1].salariul;
    }
    n--;
    ScriereDinFsr();
}

void ActualizareAngajat()
{
    int i=1,k=1,ok;
    if(n==1)
    {
        printf("Nu se poate actualiza deoarece nu exista angajati.\n");
        return ;
    }
    char numele[60],aux[60];
    fflush(stdin);
    printf("Numele angajatului:\n");
    gets(numele);
    for(i=1; i<n; i++)
    {
        if(strstr(angajat[i].nume,numele))
        {
            printf("%d. %s %s %s %s %s %.2f\n",k,angajat[i].nume,angajat[i].nrTelefon,angajat[i].adresa,angajat[i].postul,angajat[i].data,angajat[i].salariul);
            ok=1;
            k++;
        }
    }
    if(k==1)
    {
         printf("Nu exista!\n");
         return ;
    }
    int optiune;
    do{
    scanf("%d",&optiune);
    k=0;
    i=1;
    while(k<optiune && i<n)
    {
        if(strstr(angajat[i].nume,numele))
        {
            k++;
        }
        i++;
    }
    if(k!=optiune || optiune<1)
    {
        printf("Aceasta optiune nu exista!\n");
        return ;
    }
    }while(k!=optiune || optiune<1);
    i--;
    printf("Noile date ale angajatului in aceasta ordine:\nNume complet, numar de telefon, adresa de email, postul detinut, data angajarii, salariul\n\n");
    scanf("\n%[^,],%[^,],%[^,],%[^,],%[^,],%f", angajat[i].nume, angajat[i].nrTelefon, angajat[i].adresa, angajat[i].postul, angajat[i].data, &angajat[i].salariul);
    ScriereDinFsr();
}

void CitireDinFsr()
{
    int ok = 1,i=1;
    ptr = fopen("date.txt","r");
    do
    {
        if(fscanf(ptr, "%[^,],%[^,],%[^,],%[^,],%[^,],%f\n", angajat[i].nume, angajat[i].nrTelefon, angajat[i].adresa, angajat[i].postul, angajat[i].data, &angajat[i].salariul) > 2)
            i++;
        else
            ok=0;
    }
    while(ok);
    fclose(ptr);
    n=i;
}

void ScriereDinFsr()
{
    ptr = fopen("date.txt","w");
    int i;
    for(i=1; i<n; i++)
    {
        fprintf(ptr, "%s,%s,%s,%s,%s,%.2f\n", angajat[i].nume, angajat[i].nrTelefon, angajat[i].adresa, angajat[i].postul, angajat[i].data, angajat[i].salariul);
    }
    fclose(ptr);
}

int main()
{
    CitireDinFsr();
    Meniu();
    return 0;
}
