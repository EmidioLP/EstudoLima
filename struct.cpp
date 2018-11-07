#include <iostream>

using namespace std;

typedef struct Reg{
	int id;
	char Nome[30];
	char Telefone[15];
	char email[40];
	Reg *prox;
}Celula;
	
Celula *inicializa(void){
	return NULL;
}

Celula *AlocaEstrutura (Celula *fc)
{
fc = new Celula;
if (fc == NULL) {
cout<<"Memória insuficiente!"<<endl;
exit(1);}
return fc;
}

Celula *insere(Celula *L, int ordem, Celula *fc){
	fc->id = ordem;
	for(int i=0;i<1;i++) {
		cout<<"\nDigite os dados: "<<endl;
		cout<<"Telefone: ";
		cin.ignore();
		cin.getline(fc[i].Nome,15);
		cout<<"NOME: ";
		cin.ignore();
		cin.getline(fc[i].Nome,30);
		cout<<"Email: ";
		cin.ignore();
		cin.getline(fc[i].Nome,40);
	}
	fc->prox = L->prox;
	L->prox= fc;
	return L;

}
void imprime(int n, Celula *fc)
{cout<<"\n-------- RELATORIO--------"<<endl;
cout<<"---------------------------------------------"<<endl;
for(int j=0; j<n; j++){
cout<<"DADOS"<<endl;
cout<<"---------------------------------------------"<<endl;
cout<<"Telefone: "<<fc[j].Telefone<<endl;
cout<<"NOME: "<<fc[j].Nome<<endl;
cout<<"Email: "<<fc[j].email<<endl;
cout<<"Id: "<<fc[j].id<<endl;
cout<<"---------------------------------------------"<<endl;
}
}
int main()
{
	Celula *L1;
	
	L1 = inicializa();
	L1 = AlocaEstrutura(L1);//sempre que for inserir uma lista nova terá que alocar primeiro.
	L1 = insere(L1, 1, L1);//o segundo parâmetro é o do id.
	imprime(1,L1);
	
	return 0;
	}
