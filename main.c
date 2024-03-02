#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_PURPLE  "\e[0;35m"
#define ANSI_COLOR_RESET   "\x1b[0m"
int loaded1 = 0;
int loaded2 = 0;

struct player
{
    char name[70];
    int points;
    double timp;

} jucator[100];

struct intr
{
    char in[100];
    char var[200];
    char raspuns[200];

} intrebare[40],intrebare2[40];

int numar_int=0,k=0,numar_int2=0,k1=0;

void split(char s[],int *i,int x)
{
    char *token, c[500];
    memset(c,0,500);
    if(x==1)
    {
        token = strtok(s,";");
        strcpy(intrebare[*i].in,token);
        token = strtok(NULL, ";");
        strcpy(intrebare[*i].raspuns,token);
        token = strtok(NULL, ";");
        strcpy(intrebare[*i].var,token);
    }
    else
    {
        token = strtok(s,";");
        strcpy(intrebare2[*i].in,token);
        token = strtok(NULL, ";");
        strcpy(intrebare2[*i].raspuns,token);
        token = strtok(NULL, ";");
        strcpy(intrebare2[*i].var,token);

    }

}
void load(char path[],int *numar,int x)
{
    if(loaded1 >= 2)return;
    loaded1++;
    FILE* filePointer;
    filePointer = fopen(path, "r");
    if (filePointer == NULL)
    {
        printf("Fisierul nu poate fi accesat.");
        exit(1);
    }
    else
    {
        char c[500];
        while(fgets(c,500,filePointer))
        {
            split(c,numar,x);
            (*numar)++;
        }
    }
    fclose(filePointer);
}




void scrie_antet()
{
    printf("\n");
    printf("\t\t\t    1.Reguli\n");
    printf("\t\t\t    2.Start joc\n");
    printf("\t\t\t    3.Clasament\n");
    printf("\t\t\t    4.Admin - Adaugare intrebare\n");
    printf("\t\t\t    5.Admin - Stergere intrebare\n");
    printf("\t\t\t    6.Exit\n");

}

void adaugare(char path[])
{
    char v1[50], v2[50], v3[50], v4[50], intr[150]= {'\0'}, corect[50]= {'\0'},aux[200]= {'\0'},catev1[20]= {'\0'};
    int i,ok=0;
    char aux1[200]= {'\0'};
    printf("Introduceti intrebarea:\n");
    getchar();
    scanf("%[^\n]", intr);
    getchar();
    printf("Introduceti cate variantele de raspuns vreti sa adaugati:\n");

    while(1)

    {
        scanf("%[^\n]", catev1);
        if(validare(catev1)==1)
            break;
        else
        {
            getchar();
            printf("Introduceti din nou");

        }
    }

    for(i=1; i<=atoi(catev1); i++)
    {
        getchar();
        scanf("%[^\n]", v1);
        strcat(aux,v1);
        strcat(aux,",");

    }
    strcpy(aux1,aux);
    while (1)
    {
        printf("Introduceti varianta de raspuns corecta");
        getchar();
        scanf("%[^\n]", corect);

        char *p;
        p=strtok(aux,",");
        ok=0;
        while(p)
        {
            if(strcmp(p,corect)==0) ok=1;
            p=strtok(NULL,",");
        }

        if (ok==0)
        {
            printf("Raspunsul introdus nu se afla printre variantele de raspuns.Reincercati\n");
            getchar();
        }
        else
        {
            break;
        }

    }




strcpy(intrebare[numar_int].in,intr);
strcpy(intrebare[numar_int].var,corect);
strcpy(intrebare[numar_int].raspuns,aux);

copiereIntrebariInFisier(path,intr,aux1,aux);
numar_int++;
}

void adaugare2(char path2[])
{
    char v1[50], v2[50], v3[50], v4[50], intr[150], corect[50],aux[200]= {'\0'},catev[200]= {'\0'},catec[200]= {'\0'};
    int i,ok=0;
    char aux1[200]= {'\0'};
    printf("Introduceti intrebarea:\n");
    getchar();
    scanf("%[^\n]", intr);
    getchar();
    printf("Introduceti cate variantele de raspuns vreti sa adaugati:\n");

    while(1)

    {
        scanf("%[^\n]", catev);
        if(validare(catev)==1)
            break;
        else
        {
            getchar();
            printf("Introduce ti din nou");

        }
    }

    for(i=1; i<=atoi(catev); i++)
    {
        getchar();
        scanf("%[^\n]", v1);
        strcat(aux,v1);
        strcat(aux,",");

    }
    strcpy(aux1,aux);
    getchar();
    printf("Introduceti cate variantele de raspuns corecte sunt:\n");
    scanf("%[^\n]",catec);
    char ras[200]= {'\0'};
    for(i=1; i<=atoi(catec); i++)
    {
        while (1)
        {
            strcpy(aux,aux1);
            printf("Introduceti varianta de raspuns corecta\n");
            getchar();
            scanf("%[^\n]", corect);
            char *p;
            p=strtok(aux,",");
            ok=0;

            while(p)
            {
                if(strcmp(p,corect)==0) {ok=1,strcat(ras,corect),strcat(ras,",");break;}
                p=strtok(NULL,",");
            }

            if (ok==0)
            {
                printf("Raspunsul introdus nu se afla printre variantele de raspuns.Reincercati\n");
                getchar();
            }
            else
            {
                break;
            }

        }
    }
    strcpy(intrebare[numar_int2].in,intr);
    strcpy(intrebare[numar_int2].var,corect);
    strcpy(intrebare[numar_int2].raspuns,aux);
    copiereIntrebariInFisier(path2,intr,aux1,ras);
    numar_int2++;
}

void generareNumere(int aparitii[],int count)
{
    int generate = 0;
    while (1)
    {
        int num = (rand() % count);
        if (aparitii[num] == 0 && num!=0)
        {
            aparitii[num] = 1;
            generate++;
        }
        if (generate == 5)
            break;
    }
}



int validare(char* s)
{
    int n = strlen(s),i=0;
    for (i = 0; i < n; i++)
    {
        if (strchr("0123456789", s[i]) == 0)
            return 0;
    }
    return 1;
}
int  validare_var_raspuns(char *s,char raspuns[] )
{
    int n = strlen(raspuns),i=0,cate_vigule=0;
    for (i = 0; i < n; i++)
    {
        if (strchr(",", raspuns[i]) != 0)
            cate_vigule++;
    }
    if(atoi(s)>cate_vigule) return 0;
    return 1;
}

void continuare(char path[],char jucatori[])
{
    printf("\nDoriti sa mergeti la meniul principal?\n");
    printf("\n\t1. Doresc sa merg la meniul principal");
    printf("\n\t2. Doresc sa parasesc aplicatia\n");
    char optiune[15];
    while (1)
    {
        scanf("%s", optiune);
        if (validare(optiune) == 1)
        {
            int numar = atoi(optiune);
            switch (numar)
            {
            case 1:
                system("cls");
                main();
                break;
            case 2:

                //copiereClasamentInFisier(jucatori);
                //copiereIntrebariInFisier(path);
                system("cls");
                printf("\nBYE!\n");
                exit(0);
            default:
                printf("\nNu este o varianta valida");
                break;
            }
        }
        else
        {
            printf("\nNu este o varianta valida\n");
        }
    }
    free(optiune);
}

void reguli(char path[],char jucatori[])
{
    system("cls");
    printf("\n\nREGULI");
    printf("\n");
    printf("\n1.Numele ales nu poate contine diacitice\n");
    printf("\n2.Jocul contine 2 parti:PRIMA PARTE - cu 5 intrebari cu un singur raspuns corect, A DOUA PARTE -cu raspunsul multiplu.\nPentru fiecare raspuns corect se va acorda 1 punct.\nPentru a trece la cea de-a doua partea jocul trebuie sa acumulati minim 3 puncte la prima parte\nSUCCES\n\n");
    continuare(path,jucatori);
}

void afisari()
{
    printf("\n\n\n");
    printf( "\t\t\t  C PROGRAM QUIZ \n");
    printf("\t\t........................................");
    printf("\n\t\t\t     WELCOME " );
    printf("\n\t\t........................................");
    printf("\n");
}

int verificare(char nume[])
{
    int i;
    for(i=1; i<=k; i++)
    {
        if(strcmp(jucator[i].name,nume)==0)
            return 0;
    }
    return 1;
}

void numeJucator(char nume[])
{
    printf("Introduceti-va numele\n");
    while (1)
    {
        getchar();
        scanf("%[^\n]s", nume);

        if (verificare(nume) == 0)
        {
            printf("Numele introdus exista deja.\n");

        }
        else
        {
            break;
        }
    }
}
void input_user(char ras_corect[],char raspuns[],int*pct, clock_t *end)
{
    char r[10],*p;
    int r1=0,nr=1;
    printf("\nRaspunsul dumneavoastra: ");
    getchar();
    scanf("%[^\n]",r);
    *end = clock();
    while(validare(r)==0 || validare_var_raspuns(r,raspuns)==0)
    {

        printf("Introduceti din nou ");
        getchar();
        scanf("%[^\n]",r);
    }
    r1=atoi(r);
    p= strtok(raspuns,",");
    while(p)
    {
        if(nr==r1)
        {
            if( strcmp(p,ras_corect)==0)
            {


                (*pct)++;

            }
        }
        p = strtok(NULL, ",");
        nr++;
    }
}
void continuare_joc2(int v[],int *maxi)
{
    char r[20];
    printf("Doriti sa mai introduceti un raspuns?\n(a)DA\n(b)NU\n\n");
    scanf("%s",r);

    while(1)
    {
        if(strcmp(r,"a")==0)
        {
            printf("Introduceti din nou");
            scanf("%s",r);
        }
        if(strcmp(r,"b")==0)
            break;
        if(verificare_joc2(v,*maxi)==1)
            break;
        if(validare(r)==1 && v[atoi(r)]==1)
            printf("Varianta introdusa ati ales-o deja\n");
        else
        {
            if(validare(r)==1 && v[atoi(r)]==0)
            {
                v[atoi(r)]++;
                if(atoi(r)>*maxi)
                    *maxi=atoi(r);
            }
        }
        printf("Doriti sa mai introduceti un raspuns?\n(a)DA\n(b)NU\n\n");

        scanf("%s",r);

    }
}

int verificare_joc2(int v[],int maxi)
{
    int i=0,nr=0;
    for(i=1; i<=maxi; i++)
        if(v[i]==1)
            nr++;
    if(nr==4)
        return 1;
    return 0;


}
void  rasp_corect_quiz2( char m[][100],int *h, char ras_corect[])
{
    char *p;
    p= strtok(ras_corect,",");
    while(p)
    {
        strcpy(m[(*h)++],p);
        p = strtok(NULL, ",");
    }
}

int verificare_raspuns(char m[][100],int h, char *p)
{
    int i;
    for(i=0; i<h; i++)
    {
        if(strcmp(m[i],p)==0)
            return 1;
    }
    return 0;
}


void input_user2(char ras_corect[],char raspuns[],int*pct,clock_t *end)
{
    char r[10],*p;
    int r1=0,nr=1,v[100];
    memset(v,0,100);
    printf("\nIntroduceti prima varianta de raspuns pe care o considerati adevarata: ");

    scanf("%s",r);
    *end = clock();
    int maxi=0;
    while(1)
    {

        if(validare(r)==1)
        {

            v[atoi(r)]++;
            if(atoi(r)>maxi) maxi=atoi(r);
            continuare_joc2(v,&maxi);
            break;
        }
        else
        {
            printf("Introduceti din nou\n");
            scanf("%s",r);
        }

    }

    int i,j,h=0;
    char m[10][100];

    p= strtok(ras_corect,",");
    while(p)
    {
        strcpy(m[(h)++],p);
        p = strtok(NULL, ",");
    }

    for(i=1; i<=100; i++)
    {
        char copie[500];
        memset(copie,0,100);
        strcpy(copie,raspuns);


        if(v[i]!=0)
        {
            nr=1;
            p= strtok(copie,",");
            while(p)
            {
                if(v[i]!=0 && nr==i && verificare_raspuns(m,h,p)==1)
                {
                    (*pct)++;
                }

                p = strtok(NULL, ",");
                nr++;
            }


        }
    }

}
void joc2(char nume[],int *pct,double *timp)
{
    double time_spent=0,sum=0;
    system("cls");
    printf("\n\t\tA DOUA PARTE A JOCULUI\n\n");
    int i,j,p=0,c=0;
    int puncte=0;
    int aparitii[100]= {0};
    generareNumere(aparitii,10);

    for(i=0; i<numar_int2; i++)
    {
        clock_t end=0;
        time_spent=0;
        int nr=0;
        char c[100];
        int j=i;
        int counter = 0;
        if(aparitii[j]==1)
        {
            counter++;
            printf("%s\n", intrebare2[i].in);
            strcpy(c,intrebare2[i].raspuns);
            char *p;
            p= strtok(c,",");
            while(p)
            {
                printf("%d. %s\n",nr+1,p);
                p = strtok(NULL, ",");
                nr++;
            }
            clock_t begin = clock();
            input_user2(intrebare2[i].var,intrebare2[i].raspuns,pct,&end);
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nPunctajul dumneazvoastra este:");printf(ANSI_COLOR_BLUE "%d / %d\n" ANSI_COLOR_RESET,*pct, counter);
            printf("Timpul dumneavoastra este:"); printf(ANSI_COLOR_BLUE "%lf\n\n\n" ANSI_COLOR_RESET,time_spent);
        }

        sum+=time_spent;
        *timp=sum/5;


    }
}

void adaugare_in_structura(char nume[],int puncte,double tmp)
{
    strcpy(jucator[k].name,nume);
    jucator[k].points=puncte;
    jucator[k].timp=tmp;
    k++;

}

void joc1(char nume[],int *pct, double *timp)
{
    system("cls");
    double time_spent=0, sum=0;
    int i,j,p=0;
    int puncte=0;
    int counter = 0;
    int aparitii[100]= {0};
    generareNumere(aparitii,15);
    for(i=0; i<numar_int; i++)
    {
        clock_t end=0;
        int nr=0;
        time_spent=0;
        char c[100];
        int j=i+1;
        if(aparitii[j]==1)
        {
            counter++;
            printf(ANSI_COLOR_RED "==========================================\n" ANSI_COLOR_RESET);
            printf("%s\n", intrebare[i].in);
            strcpy(c,intrebare[i].raspuns);
            char *p;
            p= strtok(c,",");
            while(p)
            {

                printf(ANSI_COLOR_MAGENTA "%d." ANSI_COLOR_RESET, nr + 1);
                printf("%s\n",p);
                p = strtok(NULL, ",");
                nr++;
            }
            clock_t begin = clock();

            input_user(intrebare[i].var,intrebare[i].raspuns,pct,&end);
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

            printf("\nPunctajul dumneazvoastra este:");printf(ANSI_COLOR_CYAN "%d / %d\n" ANSI_COLOR_RESET,*pct,counter);
            printf("Timpul dumneavoastra este:"); printf(ANSI_COLOR_CYAN "%lf\n\n\n" ANSI_COLOR_RESET,time_spent);
        }
        sum+=time_spent;
        *timp=sum/5;


    }

}


void afisareJucatori()
{
    int i=0;
    for(i=0; i<k; i++)
    {
        printf("Nume:%s Puncte:%d Timp:%lf\n",jucator[i].name,jucator[i].points,jucator[i].timp);
    }
}
void swap(int *x, int *y)
{
    int t= *x;
    *x = *y;
    *y = t;
}
void swapd(double *x, double*y)
{
    double t= *x;
    *x = *y;
    *y = t;
}
void Clasament(char jucatori[])
{
    int i,j;
    for(i = 0; i< k; i++)
    {
        for( j = i + 1; j < k; j++)
        {
            if(jucator[i].points<jucator[j].points)
            {
                char n[70];
                strcpy(n,jucator[i].name);
                strcpy(jucator[i].name,jucator[j].name);
                strcpy(jucator[j].name,n);
                swap(&(jucator[i].points),&(jucator[j].points));
                swapd(&(jucator[i].timp),&(jucator[j].timp));

            }
            else
            {
                if(jucator[i].points==jucator[j].points && jucator[i].timp>jucator[j].timp )
                {
                    char n[70];
                    strcpy(n,jucator[i].name);
                    strcpy(jucator[i].name,jucator[j].name);
                    strcpy(jucator[j].name,n);
                    swap(&(jucator[i].points),&(jucator[j].points));
                    swapd(&(jucator[i].timp),&(jucator[j].timp));

                }
            }



        }
    }
}

void copiereClasamentInFisier(char jucatori[],char nume[], int puncte, double timp)
{

    int i;
    FILE *file;
    file=fopen(jucatori,"a");
    if(file==NULL)
    {
        printf("Fisierul nu exista");
        exit(1);
    }
    else
    {

    fprintf(file,"%s;%d;%lf\n",nume,puncte,timp);
    }
    fclose(file);
}

void copiereIntrebariInFisier(char path[],char intr[],char corect[],char aux[])
{
    int i;
    char fis[500];
    FILE *pointerFis;
    pointerFis=fopen(path,"a");
    if(pointerFis==NULL)
    {
        printf("Fisierul nu poate fi accesat");
        exit(1);
    }
    else{
        fprintf(pointerFis,"%s;%s;%s;\n",intr,corect,aux);
    }
    fclose(pointerFis);
}

void sterge_intrebare()
{
    int i,t;
    for( i=0;i<numar_int;i++)
    {
        printf("%d", i + 1);
        printf("%s\n", intrebare[i].in);
    }

    printf("\n");

    for( i=0;i<numar_int2;i++)
    {
        printf( "%d.", numar_int + i + 1);
        printf("%s\n", intrebare2[i].in);
    }

    int id;
    printf("Introduceti numarul intrebarii pe care vreti sa o stergeti(0 - Exit):");
    scanf("%d", &id);

    if(!id)
        return;

    printf("scanned: %d\n", id);
    id--;

    if(id >= numar_int)
    {
        id -= numar_int;
        if(id >= numar_int2)
        {
            printf("Intrebarea %d nu exista...", id + numar_int2 + 1);
            system("pause");
            sterge_intrebare();
        }
        else
        {
            char** lines = (char**)malloc(numar_int * sizeof(char*));
            FILE* filePointer;
            filePointer = fopen("quiz2.txt", "r");
            char c[500];
            int numar = 0;
            int i = 0;
            while(fgets(c,500,filePointer))
            {
                if(i != id)
                {
                    lines[numar] = (char*)malloc(500);
                    strcpy(lines[numar], c);
                    numar++;
                }
                i++;
            }
            fclose(filePointer);

            FILE* newFile = fopen("quiz2.txt", "w");
            for(t=0;t<numar;t++)
            {
                fprintf(newFile,lines[t]);
            }

            fclose(newFile);


            for( t=id;t<numar_int2-1;t++)
            {
                intrebare2[t] = intrebare2[t + 1];
            }
            numar_int2--;
            sterge_intrebare();
            //copiereIntrebariInFisier(path2,intr,aux1,ras);
        }
    }
    else
    {
        if(id < 0)
        {
            printf("Intrebarea %d nu exista...", id + 1);
            system("pause");
            main();
        }
        else
        {
            char** lines = (char**)malloc(numar_int * sizeof(char*));
            FILE* filePointer;
            filePointer = fopen("quiz1.txt", "r");
            char c[500];
            int numar = 0;
            int i = 0;
            while(fgets(c,500,filePointer))
            {
                if(i != id)
                {
                    lines[numar] = (char*)malloc(500);
                    strcpy(lines[numar], c);
                    numar++;
                }
                i++;
            }
            fclose(filePointer);

            FILE* newFile = fopen("quiz1.txt", "w");
            for( t=0;t<numar;t++)
            {
                fprintf(newFile,lines[t]);
            }

            fclose(newFile);


            for( t=id;t<numar_int-1;t++)
            {
                intrebare[t] = intrebare[t + 1];
            }
            numar_int--;
            sterge_intrebare();
        }
    }
}

void start(char path[],char path2[],char jucatori[], char nume[30])
{

    int i;
    char* optiune = (char*)calloc(50, sizeof(char));
    char* op = (char*)calloc(50, sizeof(char));
    char parola[30];
    nume[0]='\0';
    int catiJucatori = 0;
    int pct=0;
    double timp=0;
    int suma_pct=0;
    double suma_timp=0;
    while (1)
    {
        scrie_antet();
        printf("\nAlege optiunea: ");
        scanf("%s", optiune);
        if (validare(optiune) == 1)
        {
            int numar = atoi(optiune);
            switch (numar)
            {
            case 1:
                reguli(path,jucatori);
                break;
            case 2:
                 printf("\n\tPRIMA PARTE A JOCULUI\n\n");
                numeJucator(nume);
                joc1(nume,&pct,&timp);
                suma_pct+=pct;
                suma_timp=timp;
                if(pct>=3)
                {
                    printf("Ati terminat partea 1 cu %d puncte\nUrmeaza partea a doua\n", pct);
                    system("pause");
                    pct=0;
                    timp=0;
                    joc2(nume,&pct,&timp);
                    suma_pct+=pct;
                    suma_timp+=timp;
                    copiereClasamentInFisier(jucatori,nume,suma_pct,suma_timp);
                    exit(0);


                }
                else
                {
                    system("cls");
                    printf("Nu ati trecut in cea de a doua etapa.Poate data viitoate.\nBYE\n");
                    exit(0);
                }
                adaugare_in_structura(nume,suma_pct,suma_timp);
                break;

            case 3:
                system("cls");
                Clasament(jucatori);
                afisareJucatori();
                break;
            case 4:
                printf("Introduceti parola:");
                getchar();
                scanf("%[^\n]",parola);
                if(strcmp(parola,"admin")==0)
                {
                    printf("1. Introduceti o intrebare cu raspuns singular\n");
                    printf("2. Introduceti o intrebare cu raspuns multiplu\n");
                    scanf("%s", op);
                    if (validare(op) == 1)
                    {
                        int nr = atoi(op);
                        switch (nr)
                        {
                        case 1:
                            adaugare(path);
                            break;
                        case 2:
                            adaugare2(path2);
                            break;
                        default:
                            printf("Nu este o varianta valida");
                            break;
                        }
                    }
                    else
                    {
                        printf("Nu este o varianta valida");
                    }
                }
                else
                {
                    printf("\nParola incorecta");
                    main();
                }
                free(op);


            case 5:
                printf("Introduceti parola:");
                getchar();
                scanf("%[^\n]",parola);
                if(strcmp(parola,"admin")==0)
                {
                    sterge_intrebare();
                    main();
                }
                else
                {
                    printf("\nParola incorecta");
                    main();
                }
                free(op);
                break;

            case 6:
                printf(ANSI_COLOR_RED "\nBYE!\n" ANSI_COLOR_RESET);
                exit(0);
            default:
                printf("\nNu este o varianta valida");
                break;
            }
        }
        else
        {
            printf("\nNu este o varianta valida");
        }
    }
    free(optiune);
    free(nume);
}
void functie_preia_jucatori(char jucatori[])
{
    char *p;
    FILE* pointerFis;
    pointerFis = fopen(jucatori, "r");
    if (pointerFis == NULL)
    {
        printf("Fisierul nu exista");
        exit(1);
    }
    char c[200];
    c[0]='\0';
    while(fgets(c,200,pointerFis))
    {
        p=strtok(c,";");
        strcpy(jucator[k].name,p);
        p= strtok(NULL,";");
        int numar=atoi(p);
        jucator[k].points=numar;
        p=strtok(NULL,";");
        double timp=atof(p);
        jucator[k].timp=timp;
        k++;
    }
    fclose(pointerFis);
}

int main()
{
    srand(time(0));
    char nume[50];
    char path[] = "quiz1.txt";
    char path2[] = "quiz2.txt";
    char jucatori[] = "clasament.txt";
    int i;
    afisari();
    functie_preia_jucatori(jucatori);

    load(path,&numar_int,1);
    load(path2,&numar_int2,2);
    start(path,path2,jucatori,nume);

    return 0;
}

