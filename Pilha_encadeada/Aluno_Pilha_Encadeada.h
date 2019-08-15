typedef struct aluno Aluno;

Aluno *novo(int matricula, char *nome, char *curso);

void libera(Aluno *aluno);

void acessa(Aluno *aluno, int *matricula, char *nome, char *curso);

void atribui(Aluno *aluno, int matricula, char *nome, char *curso);

Aluno *proximo(Aluno *aluno);

void addproximo(Aluno *aluno, Aluno *proximo);

int size();
