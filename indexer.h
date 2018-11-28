
typedef struct NO* ArvLLRB;
// ABB RUBRO NEGRO 2-3

ArvLLRB* cria_ArvLLRB();
void libera_NO(struct NO* no);
void libera_ArvLLRB(ArvLLRB* raiz);
int consulta_ArvLLRB(ArvLLRB *raiz, char* palavra);
int QuantiaPalavra(ArvLLRB* raiz, char* palavra);
struct NO* rotacionaEsquerda(struct NO* A);
struct NO* rotacionaDireita(struct NO* A);
int cor(struct NO* H);
void trocaCor(struct NO* H);
struct NO* insereNO(struct NO* H, char* palavra, int *resp);
//int vetorDeMaiores(int vetor[20], int valor);
int insere_ArvLLRB(ArvLLRB* raiz, char* palavra);
struct NO* balancear(struct NO* H);
struct NO* move2EsqRED(struct NO* H);
struct NO* move2DirRED(struct NO* H);
struct NO* removerMenor(struct NO* H);
struct NO* procuraMenor(struct NO* atual);
struct NO* remove_NO(struct NO* H, char* palavra);
int remove_ArvLLRB(ArvLLRB *raiz, char* palavra);
int estaVazia_ArvLLRB(ArvLLRB *raiz);
int totalNO_ArvLLRB(ArvLLRB *raiz);
int altura_ArvLLRB(ArvLLRB *raiz);
void  posOrdem_ArvLLRB(ArvLLRB *raiz, int H);
void emOrdem_ArvLLRB(ArvLLRB *raiz, int H);
void preOrdem_ArvLLRB(ArvLLRB *raiz,int H);
int insertfromf(ArvLLRB* raiz,char* file_name );
//void repete_word(char* palavra);
void imprimeNmaiores(int *vetor, int n);
//int consulta_ArvNum(ArvLLRB *raiz,int t, int N, int *vetor);
int encherVetor(ArvLLRB *raiz, int H, int *vetor);
void quickSort(int *vetor, int inicio, int fim);
void PalavrAarqRel(ArvLLRB *raiz, char *palavra, char *arq1, char *arq2, char *arq3, char *arq4,char *arq5);
