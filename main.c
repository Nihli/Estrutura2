#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "indexer.h"


int main(int argc, char *argv[ ]){
/*    int opt=0,t=0,n=0,i=0;
    char file_name[50],file_name2[50],file_name3[50],file_name4[50],file_name5[50];
    char palavra[50];
    int vetor[99999];
    ArvLLRB * raiz = cria_ArvLLRB();
    for (i=0;i<argc;i++){
        if(strcmp(argv[i],'--freq')==0){
            opt=1;
        }
        else{
            if(strcmp(argv[i],'--freq-word')==0)
                opt=2;
            else{
                if(strcmp(argv[i],'--search')==0)
                opt=3;
            }
        }
    }
    if (opt==1){
        //    indexer --freq N ARQUIVO
        strcpy(file_name,argv[3]);
        insertfromf(raiz,file_name);

    }
    if (opt==2){
        //    indexer --freq-word PALAVRA ARQUIVO
        strcpy(palavra,argv[2]);
        strcpy(file_name,argv[3]);
        insertfromf(raiz,file_name);
        QuantiaPalavra(raiz,palavra);
    }
    if (opt==3){
//        indexer --search TERMO ARQUIVO [ARQUIVO ...]

        strcpy(palavra,argv[2]);
            strcpy(file_name,argv[3]);
            strcpy(file_name2,argv[4]);
            strcpy(file_name3,argv[5]);
            strcpy(file_name4,argv[6]);
            strcpy(file_name5,argv[7]);
            PalavrAarqRel(raiz,palavra,file_name,file_name2,file_name3,file_name4,file_name5);
        }
		return 0;

    }
*/
    while(opt!=87){

        printf("Menu\n");
        printf("1-Inserir Nodo na árvore.\n");
        printf("2-Imprimir árvore.\n");
        printf("3-Contar nós da árvore\n");
        printf("4-Buscar a maior relevância duma palavra.\n");		//ALTERAÇÃO
        printf("87-Sair.\n");

        scanf("%d",&opt);
        switch(opt){
            case 1 :
            printf("digite o nome do arquivo : \n");
                scanf("%s",file_name);
                insertfromf(raiz,file_name);
       //         break;
        //    case 2 :
         //       emOrdem_ArvLLRB(raiz,0);
         //       break;
       //     case 3 :
      //      	t = totalNO_ArvLLRB(raiz);
      //      	printf("%d",t);
              //  int vetorzao[t];
     //           scanf("%d", &n);
    //            encherVetor(raiz,0,vetor);
     //           consulta_ArvNum(raiz,t,n,vetor);
      //          break;
      //      case 4 :
       //         PalavrAarqRel(raiz);
         //       break;
         //   case 87 :
         //       exit(0);
        //    default:
         //   	printf("errou");
            //    scanf("%s",palavra);
            //    insere_ArvLLRB(raiz,palavra);
            //    break;
 /*       }


    }
 /* //  for(i=0; i< N; i++){
        //insere_ArvLLRB(raiz,val[i]);
//    emOrdem_ArvLLRB(raiz,0);

 //   printf("\n\n==========================\n\n");
   // remove_ArvLLRB(raiz,15);
   // emOrdem_ArvLLRB(raiz,0);
    //printf("\n\n==========================\n\n");
   // remove_ArvLLRB(raiz,50);
   // emOrdem_ArvLLRB(raiz,0);

    return 0;
//}
}

/*
Teste do seg ex:

4
Delano
101.txt
103.txt
104.txt
1013.txt
1014.txt

*/
