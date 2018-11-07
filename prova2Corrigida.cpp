#include <iostream>

using namespace std;

typedef struct Dados{
	int Mat;
	char Nome[30];
	float n1;
	float n2;
	float n3;
	float media;
}Diario;

typedef struct Reg{
	Diario info;
	Reg *prox;
}Celula;

Celula *inicializa(void){
	return NULL;
}

Celula *insere (Celula *L){ 
	Celula  *novo;
	novo = new Celula;
	cout<<"\nDigite os dados: "<<endl;
	cout<<"Matrícula: ";
	cin>>novo->info.Mat;
	cout<<"Nome: ";
	cin.ignore();
	cin.getline(novo->info.Nome,30);
	cout<<"Nota1: ";
	cin>>novo->info.n1;
	cout<<"Nota2: ";
	cin>>novo->info.n2;
	cout<<"Nota3: ";
	cin>>novo->info.n3;
	novo->info.media = ((novo->info.n1*4+novo->info.n2*5+novo->info.n3*6)/15);
	L = novo;
	novo ->prox = NULL;
	L->prox = novo->prox;
	return L;
}

void imprime(Celula *L){
	Celula *p;
	//p = new Celula;
	for (p = L; p!= NULL; p = p->prox){
		cout<<"\n Dados"<<endl;
		cout<<"Matricula = "<<p->info.Mat<<endl;
		cout<<"Nome = "<<p->info.Nome<<endl;
		cout<<"Nota 1 = "<<p->info.n1<<endl;
		cout<<"Nota 2 = "<<p->info.n2<<endl;
		cout<<"Nota 3 = "<<p->info.n3<<endl;
		cout<<"Media = "<<p->info.media<<endl;
	}
	}

void busca( Celula *L, int mat){
	Celula* p;
	for (p = L; p!= NULL; p = p->prox)
		if (p->info.Mat == mat) cout<< p->info.Nome<<endl;
		
		else cout<<"Matricula não encontrada"<<endl;

	}
	
void excluir(Celula *L, int mat){
	Celula *guarda, *lixo;
	guarda = L;
	lixo = L->prox;
	while (lixo != NULL && (lixo->info.Mat != mat)) {
		guarda = lixo;
		lixo = lixo->prox;
	}
	if (lixo != NULL) {
		guarda->prox = lixo->prox;
		delete lixo;
	}
}


int main(){
	Celula *L1;
	L1 = new Celula;
	int a;
	//L1 = inicializa();
	cout<<"Quantos alunos deseja inserir?"<<endl;
	cin>>a;
	for(int i=0; i<a; i++)
		L1 = insere(L1);
	//imprime(L1);
	//busca(L1,12); //O segundo parametro é o da matrículo do usuário, do tipo inteiro.
	excluir(L1, 12);
	imprime(L1);
	


	return 0;
}
