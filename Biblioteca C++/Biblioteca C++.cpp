#include <iostream>
#include <cstring>
using namespace std;

struct livros 
{
    char titulo[30];
    char autor[30];
    int numPaginas , anopublicacao , ID , qtdexemplares;
};

void cadastro (struct livros livro[] , int *count)
{
    cout << "ID: " << endl;
    cin >> livro[*count].ID;
    cin.ignore();
    cout << "Titulo: " << endl;
    cin.getline (livro[*count].titulo , 30);
    cout << "Autor: " << endl;
    cin.getline (livro[*count].autor , 30);
    cout << "Número de páginas: " << endl;
    cin >> livro[*count].numPaginas;
    cout << "Ano de Publicação: " << endl;
    cin >> livro[*count].anopublicacao;
    cout << "Quantidades disponiveis: " << endl;
    cin >> livro[*count].qtdexemplares;
    
    if (livro[*count].qtdexemplares > 10)
    {
        cout << "Quantidade Maxima permitida são 10 unidades. Tente de novo." << endl << "Quantidades disponiveis: " << endl;
        cin >> livro[*count].qtdexemplares;
        
    }
    (*count) ++;
}
void consultatotal (struct livros livro[] , int count )
{
    cout << "ID: " << livro[count].ID << endl;
    cout << "Titulo: " << livro[count].titulo << endl;
    cout << "Autor: " << livro[count].autor << endl;
    cout << "Número de páginas: " << livro[count].numPaginas << endl;
    cout << "Ano de Publicação: " << livro[count].anopublicacao << endl;
    cout << "Quantidades disponiveis: " << livro[count].qtdexemplares << endl;
    cout << string(40, '-') << endl;
}

void consultaIDouTitulo (struct livros livro[] , int sz)
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
                if (livro[i].ID == id)
                {
                    cout << string(40, '-') << endl;
                    consultatotal(livro, i);
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
            cout <<"DIgite o titulo que deseja pesquisar: " << endl;
            cin.ignore();
            cin.getline (tituloc , 30);
            bool encontrado = false;
            for (int i = 0; i < sz; i++)
            {
                if (strcmp(tituloc, livro[i].titulo) == 0)
                {
                    cout << string(40, '-') << endl;
                    consultatotal(livro, i);
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
void menuconsultar (struct livros livro[] , int count)
{
    int opcaoconsulta = 0;
    cout << string(40, '-') << endl;
    cout << "Bem Vindo(a) ao menu de consulta de livros" << endl;
    cout << "1 - listar todos os livros cadastrados. \n2 - Pesquisar um livro pelo ID ou título. \nDigite a opção desejada: " << endl;
    cin >> opcaoconsulta;
    cout << string(40, '-') << endl;
    switch (opcaoconsulta)
    {
        case 1:
        {
            for (int i = 0 ; i < count ; i++)
            {
                consultatotal (livro, i);
            }
            break;
        }
        
        case 2:
        {
           consultaIDouTitulo (livro , count); 
           break;
        }
        default:
            cout << "Opção inválida." << endl;
    }
}

//criei um main só para poder testar o codigo - foi o chat que fez.
int main()
{
    struct livros livro[100];
    int count = 0;
    int opcao = 0;
    
    do
    {
        cout << "Menu Principal:" << endl;
        cout << "1 - Cadastrar um livro." << endl;
        cout << "2 - Consultar livros." << endl;
        cout << "3 - Sair." << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcao;
        cin.ignore(); // Ignorar o newline após a escolha da opção

        switch (opcao)
        {
            case 1:
                cadastro(livro, &count); // Função para cadastrar um novo livro
                break;
            case 2:
                menuconsultar(livro, count); // Função para consultar livros
                break;
            case 3:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 3);
    
    return 0;
}
