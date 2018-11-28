#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED 1
#define BLACK 0

struct NO{
    char info[50];
    struct NO *esq;
    struct NO *dir;
    int cor;
    int num;
};
typedef struct NO* ArvLLRB;

typedef struct palavra_repetida{
	char reapword[1024];
	int num;
}repete;

repete rewords[1244]; //vetor de letras repetidas

// =================================
// CRIAÇÃO DA ARVORE
// =================================
ArvLLRB* cria_ArvLLRB(){
    ArvLLRB* raiz = (ArvLLRB*) malloc(sizeof(ArvLLRB));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}
// =================================
// LIBERAR
// =================================
void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvLLRB(ArvLLRB* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}
// =================================
// CONSULTA ÁRVORE
// =================================
int consulta_ArvLLRB(ArvLLRB *raiz, char* palavra){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(strcmp(palavra, atual->info)==0){ //compara de palavra ==atual->info. Se for, retorna 1

            return 1;
        }
        if (strcmp(palavra, atual->info)>0) //compara se palavra > atual->info. Se sim executa esse if.
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

//Usarei a mesma função para tentar encontrar a palavra buscada. Resolvi não mexer na função que, aparentemnte, já está sendo usada.
int QuantiaPalavra(ArvLLRB* raiz, char* palavra){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(strcmp(palavra, atual->info)==0){ //compara de palavra ==atual->info. Se for, retorna 1

            return atual -> num;
        }
        if (strcmp(palavra, atual->info)>0) //compara se palavra > atual->info. Se sim executa esse if.
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

// =================================
// ROTAÇÃO
// =================================
struct NO* rotacionaEsquerda(struct NO* A){
    struct NO* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO* rotacionaDireita(struct NO* A){
    struct NO* B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

int cor(struct NO* H){
    if(H == NULL)
        return BLACK;
    else
        return H->cor;
}

void trocaCor(struct NO* H){
    H->cor = !H->cor;
    if(H->esq != NULL)
        H->esq->cor = !H->esq->cor;
    if(H->dir != NULL)
        H->dir->cor = !H->dir->cor;
}

// =================================
// INSERCAO
// =================================
struct NO* insereNO(struct NO* H, char* palavra, int *resp){
    if(H == NULL){
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL){
            *resp = 0;
            return NULL;
        }
        novo->num=0;
        strcpy (novo->info,palavra); //faz atribuição novo->info =palavra;
        novo->cor = RED;
        novo->dir = NULL;
        novo->esq = NULL;
        novo->num++;
        *resp = 1;
        return novo;
    }

    if(strcmp(palavra, H->info)==0){ //compara se palavra == H->info
        *resp = 0;// Valor duplicado
        //void repete_word(palavra);
        H->num++;
        }
    else{
        if (strcmp(palavra, H->info)<0) //compara se palavra < H->info
            H->esq = insereNO(H->esq,palavra,resp);
        else
            H->dir = insereNO(H->dir,palavra,resp);
    }

    //nó Vermelho é sempre filho à esquerda
    if(cor(H->dir) == RED && cor(H->esq) == BLACK)
        H = rotacionaEsquerda(H);

    //Filho e Neto são vermelhos
    //Filho vira pai de 2 nós vermelhos
    if(cor(H->esq) == RED && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);

    //2 filhos Vermelhos: troca cor!
    if(cor(H->esq) == RED && cor(H->dir) == RED)
        trocaCor(H);

    return H;
}

int vetorDeMaiores(int vetor[20], int valor){
    int i;
    int aux;
    if (vetor[0]==NULL)
        vetor[0]=valor;
    else{
        for(i=1;i<20;i++){
            if(vetor[i]==valor)
//                for(j=)
                vetor[i+1]==valor;
        }
    }
}



int insere_ArvLLRB(ArvLLRB* raiz, char* palavra){
    int resp;

    *raiz = insereNO(*raiz,palavra,&resp);
    if((*raiz) != NULL)
        (*raiz)->cor = BLACK;

    return resp;
}


// =================================
// REMOÇÃO
// =================================
struct NO* balancear(struct NO* H){
    //nó Vermelho é sempre filho à esquerda
    if(cor(H->dir) == RED)
        H = rotacionaEsquerda(H);

    //Filho da direita e neto da esquerda são vermelhos
    if(H->esq != NULL && cor(H->dir) == RED && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);

    //2 filhos Vermelhos: troca cor!
    if(cor(H->esq) == RED && cor(H->dir) == RED)
        trocaCor(H);

    return H;
}

struct NO* move2EsqRED(struct NO* H){
    trocaCor(H);
    if(cor(H->dir->esq) == RED){
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        trocaCor(H);
    }
    return H;
}

struct NO* move2DirRED(struct NO* H){
    trocaCor(H);
    if(cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
        trocaCor(H);
    }
    return H;
}

struct NO* removerMenor(struct NO* H){
    if(H->esq == NULL){
        free(H);
        return NULL;
    }
    if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
        H = move2EsqRED(H);

    H->esq = removerMenor(H->esq);
    return balancear(H);
}

struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

struct NO* remove_NO(struct NO* H, char* palavra){
    if(strcmp(palavra, H->info)<0){
        if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
            H = move2EsqRED(H);

        H->esq = remove_NO(H->esq, palavra);
    }else{
        if(cor(H->esq) == RED)
            H = rotacionaDireita(H);


        if(strcmp(palavra, H->info)==0 && (H->dir == NULL)){
            free(H);
            return NULL;
        }

        if(cor(H->dir) == BLACK && cor(H->dir->esq) == BLACK)
            H = move2DirRED(H);

        if(strcmp(palavra, H->info)==0){
            struct NO* x = procuraMenor(H->dir);
            strcpy (H->info,x->info);
            H->dir = removerMenor(H->dir);
        }else
            H->dir = remove_NO(H->dir, palavra);
    }
    return balancear(H);
}


int remove_ArvLLRB(ArvLLRB *raiz, char* palavra){
    if(consulta_ArvLLRB(raiz,palavra)){
        struct NO* h = *raiz;
        *raiz = remove_NO(h,palavra);
        if(*raiz != NULL)
            (*raiz)->cor = BLACK;
        return 1;
    }else
        return 0;
}
// =================================
// PROPRIEDADES ÁRVORE
// =================================
int estaVazia_ArvLLRB(ArvLLRB *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvLLRB(ArvLLRB *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;

    int alt_esq = totalNO_ArvLLRB(&((*raiz)->esq));
    int alt_dir = totalNO_ArvLLRB(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);
}

int altura_ArvLLRB(ArvLLRB *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvLLRB(&((*raiz)->esq));
    int alt_dir = altura_ArvLLRB(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}
// =================================
// PERCURSO
// =================================
void  posOrdem_ArvLLRB(ArvLLRB *raiz, int H){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        posOrdem_ArvLLRB(&((*raiz)->esq),H+1);
        posOrdem_ArvLLRB(&((*raiz)->dir),H+1);

        if((*raiz)->cor == RED)
            printf("%s  Vermelho: H(%d) \n",(*raiz)->info,H);
        else
            printf("%s  Preto: H(%d) \n",(*raiz)->info,H);

    }
}

void emOrdem_ArvLLRB(ArvLLRB *raiz, int H){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        emOrdem_ArvLLRB(&((*raiz)->esq),H+1);

        if((*raiz)->cor == RED)
            printf("%s - %d Vermelho: H(%d)\n",(*raiz)->info,(*raiz)->num,H);
        else
            printf("%s - %d Preto: H(%d)\n",(*raiz)->info,(*raiz)->num,H);

        emOrdem_ArvLLRB(&((*raiz)->dir),H+1);
    }
}

void preOrdem_ArvLLRB(ArvLLRB *raiz,int H){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        if((*raiz)->cor == RED)
            printf("%s  Vermelho: H(%d) \n",(*raiz)->info,H);
        else
            printf("%s  Preto: H(%d) \n",(*raiz)->info,H);

        preOrdem_ArvLLRB(&((*raiz)->esq),H+1);
        preOrdem_ArvLLRB(&((*raiz)->dir),H+1);
    }
}

int insertfromf(ArvLLRB* raiz,char* file_name ){
	FILE *arq;
	int contDePalavras=0;		//ALTERAÇÂO
	char ch[1024];
	int ind,ind2;
	arq = fopen(file_name, "r"); // abrndo aquivo modo leitura

   if (arq == NULL){//caso tenha erro ao abrir o arquico
      printf("Erro ao abir o arquivo .\n");
      exit(EXIT_FAILURE);
   }

  while (fscanf(arq, "%1023s", ch) == 1) {

  	  ind = strlen(ch)-1;
		if (ch[ind]==','){ //tudo esses if é pra ele nao inserir caractere especial
        	ch[ind]='\0';
		}
		if (ch[ind]=='.'){
        	ch[ind]='\0';
		}
		if (ch[ind]==')'){
        	ch[ind]='\0';
		}
		if (ch[ind]=='-'){
        	ch[ind]='\0';
		}
		if (ch[ind]=='"'){
        	ch[ind]='\0';
		}
		if (ch[ind]=='!'){
        	ch[ind]='\0';
		}
      insere_ArvLLRB(raiz,ch);      contDePalavras++;		//ALTERAÇÃO
}
   fclose(arq); //fechando
	return contDePalavras;		//ALTERAÇÃO
}

void repete_word(char* palavra){
int i=0,j;
	for(j=0;j<i;j++){ //como eu faco esse for ??????????????????????????????????
		if (strcmp(palavra,rewords[i].reapword)==0){ //se essa palavra ja tiver sido repetida uma vez ele só aumenta a var num
			rewords[i].num= rewords[i].num++;
		}
		strcpy(rewords[i].reapword, palavra); // se nao foi insrida é pra inserir no final
		rewords[i].num = rewords[i].num++;
	}
}

void imprimeNmaiores(int *vetor, int n){
    int i;

    for (i=n;i>0;i--){
        printf("%d ",vetor[i]);
    }
}

int consulta_ArvNum(ArvLLRB *raiz,int t, int N, int *vetor){
    printf("Oi!");
    int i;
    quickSort(vetor, 0,t-1);
    imprimeNmaiores(&vetor,N);


}

int encherVetor(ArvLLRB *raiz, int H, int *vetor){
    if(raiz == NULL)
        return 0;
     while(*raiz!=NULL){
        encherVetor(&((*raiz)->esq),H+1,vetor);
        encherVetor(&((*raiz)->dir),H+1,vetor);
        vetor[H]=(*raiz)->num;
    }
}
void quickSort(int *vetor, int inicio, int fim){
   int i, j, meio, aux;

   i = inicio;
   j = fim;
   meio = vetor[(inicio + fim) / 2];

   do
   {
      while(vetor[i] < meio)
         i++;
      while(vetor[j] > meio)
         j--;
      if(i <= j)
      {
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i++;
         j--;
      }
   }while(i <= j);

   if(inicio < j)
      quickSort(vetor, inicio, j);
   if(i < fim)
      quickSort(vetor, i, fim);
}

////////////////////////////////////////////////////////////////////

/*void rankingpalavras (ArvLLRB* raiz, int num){
	int H =0;
	int i=0, x=0;
	int ver=0;
	ArvLLRB no[num];
	if(raiz == NULL) return;
    if(*raiz != NULL){
        posOrdem_ArvLLRB(&((*raiz)->esq),H+1);
        posOrdem_ArvLLRB(&((*raiz)->dir),H+1);
        for (i=0;i<num;i++){
        	while (ver == 0){
				if (raiz->num > no[i]->num){
					for (x=num;x>num;x--) no[x] = no[x-1];
					no[i]->num = raiz -> num;
					no[i]->info = raiz -> info;
					ver = 1;
				}
				else if( i==num) ver=1;
			}
		}
    }
    for (i=0;i<num;i++){
    	printf ("Posição %d: Palavra %s, com %d usos.\n", i, no[i]->info, no[i]->num);
	}
}
///////////////////////////////////////////////////////////////////
*/
int main(){
    int opt=0,t=0,n=0, i, numpalavras;   //ALTERAÇÃO
	double citacao;	//ALTERAÇÃo
	double contDePalavras[5];  //ALTERAÇÃO
    double relevancia[5], val3;		//ALTERAÇÃO
    char arq1[50], arq2[50], arq3[50], arq4[50], arq5[50];
    char palavra[50];		//ALTERAÇÂO
    char file_name[50];
    int vetor[99999];
    ArvLLRB * raiz = cria_ArvLLRB();

    while(opt!=87){

        printf("Menu\n");
        printf("1-Inserir Nodo na árvore.\n");
        printf("2-Imprimir árvore.\n");
        printf("3-Contar nós da árvore\n");
        printf("4-Buscar a maior relevância duma palavra.\n");		//ALTERAÇÃO
        printf("5-Palavras mais usadas num arquivo.\n");
        printf("6- Busca ocorrências de uma palavra. \n");
		printf("87-Sair.\n");

        scanf("%d",&opt);
        switch(opt){
            case 1 :
            printf("digite o nome do arquivo : \n");
                scanf("%s",file_name);
                insertfromf(raiz,file_name);
                break;
            case 2 :
                emOrdem_ArvLLRB(raiz,0);
                break;
            case 3 :
            	t = totalNO_ArvLLRB(raiz);
            	printf("%d",t);
              //  int vetorzao[t];
                scanf("%d", &n);
                encherVetor(raiz,0,vetor);
                consulta_ArvNum(raiz,t,n,vetor);
                break;
            case 4:
                libera_ArvLLRB(raiz);
                raiz = cria_ArvLLRB();
				printf ("Digite a palavra que quer: \n");
            	scanf ("%s", &palavra);
            	printf("digite o nome dos 5 arquivos : \n");
            	citacao = 0;
                scanf("%s",arq1);
                contDePalavras[0] = insertfromf(raiz,arq1);
                relevancia[0] = (double)QuantiaPalavra(raiz,palavra) / contDePalavras[0];
                printf("Relevancia, multiplicada por 100.000: %f\n\n", relevancia[0]*100000 );
                if ( relevancia [0] != 0 ) citacao ++;
                libera_ArvLLRB(raiz);
                raiz = cria_ArvLLRB();
                scanf("%s",arq2);
                contDePalavras[1] = insertfromf(raiz,arq2);
                relevancia[1] = (double)QuantiaPalavra(raiz,palavra) / contDePalavras[1];
                printf("Relevancia, multiplicada por 100.000: %f\n\n", relevancia[1]*100000 );
                if ( relevancia [1] != 0 ) citacao ++;
                libera_ArvLLRB(raiz);
				raiz = cria_ArvLLRB();
                scanf("%s",arq3);
                contDePalavras[2] = insertfromf(raiz,arq3);
                relevancia[2] = (double)QuantiaPalavra(raiz,palavra) / contDePalavras[2];
                printf("Relevancia, multiplicada por 100.000: %f\n\n", relevancia[2]*100000 );
                if ( relevancia [2] != 0 ) citacao ++;
                libera_ArvLLRB(raiz);
                raiz = cria_ArvLLRB();
                scanf("%s",arq4);
				contDePalavras[3] = insertfromf(raiz,arq4);
				relevancia[3] = (double)QuantiaPalavra(raiz,palavra) / contDePalavras[3];
                printf("Relevancia, multiplicada por 100.000: %f\n\n", relevancia[3]*100000 );
                if ( relevancia [3] != 0 ) citacao ++;
                libera_ArvLLRB(raiz);
                raiz = cria_ArvLLRB();
                scanf("%s",arq5);
            	contDePalavras[4] = insertfromf(raiz,arq5);
            	relevancia[4] = (double)QuantiaPalavra(raiz,palavra) / contDePalavras[4];
                printf("Relevancia, multiplicada por 100.000: %f\n\n", relevancia[4]*100000 );
                if ( relevancia [4] != 0 ) citacao ++;
                libera_ArvLLRB(raiz);
                raiz = cria_ArvLLRB();
				citacao = log10(5/citacao);
    			printf ("\n1: %s, %f\n2: %s, %f\n3: %s, %f\n4: %s, %f\n5: %s, %f\n",
				arq1, relevancia[0] * citacao, arq2, relevancia[1] * citacao,arq3, (relevancia[2] * citacao),arq4, relevancia[3] * citacao,arq5, relevancia[4] * citacao);
				break;
	/*		case 5:
				libera_ArvLLRB(raiz);
                raiz = cria_ArvLLRB();
				printf("Quantas palavras?");
				scanf("%d", &numpalavras);
				printf("Qual o arquivo que quer usar?");
				scanf("%s",file_name);
            	insertfromf(raiz,file_name);
				rankingpalavras(raiz,numpalavras);
				break;
    */      case 6 :
    			printf("Entre com a palavra: \n");
    			scanf("%s",&palavra);
    			printf("%d",QuantiaPalavra(raiz,palavra));
			case 87 :
                exit(0);
            default:
            	printf("errou");
            //    scanf("%s",palavra);
            //    insere_ArvLLRB(raiz,palavra);
            //    break;
        }


    }
  //  for(i=0; i< N; i++){
        //insere_ArvLLRB(raiz,val[i]);
//    emOrdem_ArvLLRB(raiz,0);

    printf("\n\n==========================\n\n");
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
