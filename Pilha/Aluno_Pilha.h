typedef struct aluno Aluno;

Aluno *novo(int matricula, char *nome, char *curso);

void libera(Aluno *aluno);

void acessa(Aluno *aluno, int *matricula, char *nome, char *curso);

void atribui(Aluno *aluno, int matrciula, char *nome, char *curso);

int size();
