/*
    Eduarda Picolo Barboza RA - 24021934
    Eduardo Ferreira Gomes RA - 24020599
    Laura Akemi Suzuki     RA - 24019712
*/

#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>
using namespace std;

struct cliente
{
    char nome[50];
    int ID;
};

struct livro
{
    char titulo[30];
    char autor[30];
    int listaclientes[10] = { 0 };
    int numPaginas, anopublicacao, ID, qtdexemplares;
};

void cadastro (struct livro livros[] , int *count)
{
    cout << string(40, '-') << endl;
    cout << "CADASTRAR LIVRO " << endl;
    cout << "Digite o ID: " << endl;
    cin >> livros[*count].ID;
    for (int i = 0; i <*count ; i++)
    {
        if (livros[i].ID == livros[*count].ID)
        {
            cout << "ID já cadastrado, insira outro. " << endl << "ID: " << endl;
            cin >> livros[*count].ID;
            i = -1;
        }
    }
    cin.ignore();
    cout << "Título: " << endl;
    cin.getline (livros[*count].titulo , 30);
    cout << "Autor: " << endl;
    cin.getline (livros[*count].autor , 30);
    cout << "Número de páginas: " << endl;
    cin >> livros[*count].numPaginas;
    cout << "Ano de Publicação: " << endl;
    cin >> livros[*count].anopublicacao;
    while (livros[*count].anopublicacao > 2024) {
        cout << "Ano inválido, digite novamente: ";
        cin >> livros[*count].anopublicacao;
    }
    cout << "Quantidades disponíveis: " << endl;
    cin >> livros[*count].qtdexemplares;
   
   
    while (livros[*count].qtdexemplares > 10)
    {
        cout << "Quantidade Maxima permitida são 10 unidades. Tente de novo." << endl << "Quantidades disponiveis: " << endl;
        cin >> livros[*count].qtdexemplares;

    }
    (*count) ++;
    cout << string(40, '-') << endl;
    cout << "Livro cadastrado! " << endl;
}

void consultatotal (struct livro livros[] , int count )
{
    cout << string(40, '-') << endl;
    cout << "ID: " << livros[count].ID << endl;
    cout << "Titulo: " << livros[count].titulo << endl;
    cout << "Autor: " << livros[count].autor << endl;
    cout << "Número de páginas: " << livros[count].numPaginas << endl;
    cout << "Ano de Publicação: " << livros[count].anopublicacao << endl;
    cout << "Quantidades disponiveis: " << livros[count].qtdexemplares << endl;
}

void consultaIDouTitulo (struct livro livros[] , int sz)
{
    int id;
    char tituloc [30];
    int opcaoIDouTitulo = 0;
    cout << string(40, '-') << endl;
    cout << "Deseja pesquisar o livro via \n1 - ID. \n2 - Título." << endl;
    cin >> opcaoIDouTitulo;
    switch (opcaoIDouTitulo)
    {
        case 1:
        {
            cout << "Digite o ID que deseja pesquisar: " << endl;
            cin >> id;
            bool encontrado = false;
            for (int i = 0; i < sz; i++)
            {
                if (livros[i].ID == id)
                {
                    cout << string(40, '-') << endl;
                    consultatotal(livros, i);
                    encontrado = true;
                }
            }
            if (!encontrado)
            {
                cout << "ID não encontrado." << endl;
            }
            break;
        }
        case 2:
        {
            cout <<"Digite o titulo que deseja pesquisar: " << endl;
            cin.ignore();
            cin.getline (tituloc , 30);
            bool encontrado = false;
            for (int i = 0; i < sz; i++)
            {
                if (strcmp(tituloc, livros[i].titulo) == 0)
                {
                    consultatotal(livros, i);
                    encontrado = true;
                }
            }
            if (!encontrado)
            {
                cout << "Título não encontrado." << endl;
            }
            break;
        }
        default:
            cout << "Opção inválida." << endl;
    }
}

void menuconsultar (struct livro livros[] , int count)
{
    int opcaoconsulta = 0;
    cout << string(40, '-') << endl;
    cout << "CONSULTAR LIVRO " << endl;
    cout << "1 - listar todos os livros cadastrados. \n2 - Pesquisar um livro pelo ID ou título. \nDigite a opção desejada: " << endl;
    cout << string(40, '-') << endl;
    cin >> opcaoconsulta;
    switch (opcaoconsulta)
    {
        case 1:
        {
            for (int i = 0 ; i < count ; i++)
            {
                consultatotal (livros, i);
            }
            break;
        }
        case 2:
        {
           consultaIDouTitulo (livros , count);
           break;
        }
        default:
            cout << "Opção inválida." << endl;
    }
}

void emprestimo(struct livro livros[], struct cliente clientes[], int count, int *ncliente)
{
    int id;
    cout << string(40, '-') << endl;
    cout << "EMPRESTAR LIVRO" << endl;
    cout << "Digite o ID do livro que o cliente deseja emprestar: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (livros[i].ID == id) {
            if (livros[i].qtdexemplares == 0) {
                cout << "Não existem mais exemplares desse livro na biblioteca." << endl;
                return;
            }
            int k = 0;
            for (int aux = 0; aux < 10; aux++) {
                if (livros[i].listaclientes[aux] != 0) {
                    k++;
                }
            }
            cout << "Digite o nome do cliente: ";
            cin >> clientes[*ncliente].nome;
            cout << "Digite o ID do cliente: ";
            cin >> clientes[*ncliente].ID;

            for (int aux = 0; aux < k; aux++) {
                if (livros[i].listaclientes[aux] == clientes[*ncliente].ID) {
                    cout << "Esse livro já está emprestado para esse cliente." << endl;
                    return;
                }
            }

            livros[i].listaclientes[k] = clientes[*ncliente].ID;

            (*ncliente)++;
            livros[i].qtdexemplares--;

            cout << "O livro foi emprestado com sucesso!" << endl;
            cout << "Ainda existe(m) " << livros[i].qtdexemplares << " exemplares desse livro em estoque." << endl;
            return;
        }
    }
    cout << "ID não encontrado." << endl;
}

void devolucao(struct livro livros[], struct cliente clientes[], int count)
{
    int id;
    cout << string(40, '-') << endl;
    cout << "DEVOLVER LIVRO" << endl;
    cout << "Digite o ID do livro que o cliente deseja devolver: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (livros[i].ID == id) {
            int k = 0;
            for (int aux = 0; aux < 10; aux++) {
                if (livros[i].listaclientes[aux] != 0) {
                    k++;
                }
            }

            int idcliente;
            cout << "Digite o ID do cliente: ";
            cin >> idcliente;

            bool veri = false;
            for (int aux = 0; aux < k; aux++) {
                if (livros[i].listaclientes[aux] == idcliente) {
                    veri = true;
                }
            }
            if (veri == false) {
                cout << "O cliente com o ID " << idcliente << " não emprestou esse livro." << endl;
                return;
            }

            for (int aux = 0; aux < k; aux++) {
                if (livros[i].listaclientes[aux] == idcliente) {
                    for (int aux2 = aux; aux2 < k; aux2++){
                        livros[i].listaclientes[aux2] = livros[i].listaclientes[aux2 + 1];
                    }
                }
            }

            livros[i].qtdexemplares++;
            cout << string(40, '-') << endl;
            cout << "O livro foi devolvido com sucesso!" << endl;
            cout << "Agora existem " << livros[i].qtdexemplares << " exemplares desse livro em estoque." << endl;
            return;
        }
    }
    cout << "ID não encontrado." << endl;
}

void remover(struct livro livros[], int *count) {
    bool encontrado = false;
    int id;
   
    cout << string(40, '-') << endl;
    cout << "REMOVER LIVRO " << endl;
    cout << "Digite o ID do livro que deseja remover: " << endl;
    cin >> id;
    cout << string(40, '-') << endl;

    // Encontrando o livro com o id fornecido
    for (int i = 0; i < *count; i++) {
        if (livros[i].ID == id) {
            encontrado = true;
            cout << "Título: " << livros[i].titulo << endl;

            // Deslocando os elementos
            for (int j = i; j < (*count - 1); j++) {
                livros[j] = livros[j + 1];  
            }
            (*count)--;
            cout << "Livro " << livros[i].titulo << " removido." << endl;
            break;  // Saindo do loop após remover
        }
    }

    if (!encontrado) {
        cout << "ID não encontrado." << endl;
    }
}

int main()
{
    struct livro livros[100];
    struct cliente clientes[1000];
    int count = 0;
    int k = 0;
    int ncliente = 0;
    int opcao = 0;

    do
    {
        cout << string(40, '-') << endl;
        cout << "MENU PRINCIPAL:" << endl;
        cout << "1 - Cadastrar um livro." << endl;
        cout << "2 - Consultar livros." << endl;
        cout << "3 - Emprestar um livro." << endl;
        cout << "4 - Devolver um livro." << endl;
        cout << "5 - Remover livro." << endl;
        cout << "6 - Finalizar." << endl;
        cout << string(40, '-') << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 1:
            cadastro(livros, &count); //Função para cadastrar um novo livro
            break;
        case 2:
            menuconsultar(livros, count); //Função para consultar livros
            break;
        case 3:
            emprestimo(livros, clientes, count, &ncliente); //Função para emprestar um livro
            break;
        case 4:
            devolucao(livros, clientes, count); //Função para devolver um livro
            break;
        case 5:
            remover(livros, &count); //Função para remover um livro do sistema
            break;
        case 6:
            cout << "Saindo do programa..." << endl;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 6);

    return 0;
}