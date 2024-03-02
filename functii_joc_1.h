void split(char s[],int i)
{
    char *token, c[500];
    memset(c,0,500);
    token = strtok(s,";");
    strcpy(intrebare[i].in,token);
    token = strtok(NULL, ";");
    strcpy(intrebare[i].raspuns,token);
    token = strtok(NULL, ";");
    strcpy(intrebare[i].var,token);

}
void load(char path[])
{
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
            split(c,numar_int);
            numar_int++;
        }
    }
    fclose(filePointer);
}
