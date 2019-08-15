typedef struct no No;

No *criaNo(int chave, char conteudo);

void liberaNo(No *no);

int chaveNo(No *no);

char conteudoNo(No *no);

void insereNo(No *raiz, No *no);

No *buscaNo(No *raiz, int chave);

No *removeNo(No *raiz, int chave);

int altura(No *raiz);

int numero(No *raiz);

char *preOrdem(No *no);

char *ordem(No *no);

char *posOrdem(No *no);
