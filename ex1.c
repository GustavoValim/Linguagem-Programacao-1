#include<stdlib.h>
#include<stdio.h>
#define MAX 10

struct aluno {

    char prontuario[7];
    char nome[20];
    float nota_p1;
    float nota_p2;
    float media;
};


void cadastro (struct aluno *vAluno, int tam)
{
      int i;
      for(i = 0; i < tam; i++)
      {

            printf("Aluno [%d]: \n", i + 1);
            printf("Digite pontuario: \n");
            scanf("%s", &vAluno[i].prontuario);
            printf("Digite nome: \n");
            scanf("%s", &vAluno[i].nome);
            printf("Digite nota 1: \n");
            scanf("%f", &vAluno[i].nota_p1);
            printf("Digite nota 2: \n");
            scanf("%f", &vAluno[i].nota_p2);
            vAluno[i].media = (vAluno[i].nota_p1 +vAluno[i].nota_p2)/2;
      }
}



int main()
{

    struct aluno listaAluno[MAX];

    FILE *arq;

    if((arq = fopen("alunos.txt", "w")) == NULL)  //Verifica se foi possivel criar um arquivo chamado alunos.txt
    {
        printf("ERRO AO ABRIR ARQUVIO\n");
        exit(0);
    }

    int tam = 20;

    cadastro(listaAluno, tam);

    //Armazenar no arquivo
    int i;
    for(i = 0; i < tam; i++)
    {
      fprintf(arq, "%s - %s - %.2f - %.2f - %.2f\n",   /* salva no formato pontuario - nome - nota1 - nota2 - media
               listaAluno[i].prontuario,
               listaAluno[i].nome,
               listaAluno[i].nota_p1,
               listaAluno[i].nota_p2,
               listaAluno[i].media);
    }

    fclose(arq);  //Fecha o arquivo

   return 0;
}