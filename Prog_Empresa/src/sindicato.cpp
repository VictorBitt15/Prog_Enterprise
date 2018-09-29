//Implementação dos métodos da classe Sindicato
#include <iostream>
#include <string>
#include "funcionario.h"
#include "empresa.h"
#include "sindicato.h"
using namespace std;
//Construtor
Sindicato::Sindicato(){
  m_total_empresas=0;
  m_total_geral_funcionarios=0;
  m_menu_de_entrada=true;
  m_opcao=0;

}

//Destrutor
Sindicato::~Sindicato(){}

//Getters
int Sindicato::getTotalEmpresas()
{
  return m_total_empresas;
}
string Sindicato::getNomeEmpresa()
{
  return m_nome_empresa;
}
float Sindicato::getPorcentagem_aumento()
{
  return m_porcentagem_aumento;
}
int Sindicato::getTotalGeralFuncionarios()
{
  return m_total_geral_funcionarios;
}
//Fim dos Getters

//Adicionando empresas no sindicato;
void Sindicato::addEmpresa(Empresa * Enterprise)
{
  if(m_total_empresas<MAX_EMPRESAS)
  {
    m_empresas[m_total_empresas++]= Enterprise;
  }
  else
  {
    cerr << "Nosso limite de empresas cadastradas chegou ao topo!\nProocure outro sindicato para cadastrar sua empresa." << endl;
  }
}

//Listando detalhes de cada empresa;
void Sindicato::listarEmpresas()
{
  for(int i=0; i<m_total_empresas; i++)
  {
    cout <<i+1<< " " << m_empresas[i];
  }
  cout << endl;
}

//Iniciando Menu de criação de Empresas
void Sindicato::run()
{
  while(m_menu_de_entrada)
  {
    int comando=menu();
    switch(comando){
      case 1:
        empresa_Nome_Cnpj();
        addEmpresa(new Empresa(m_nome_empresa,m_cnpj));
        cout << "Esperando próximo comando..." << endl;
      break;

      case 2:
        m_indice=verifica_empresa();
        if(m_indice>=0)
        {
            funcionario_nome_salario(m_indice);
            m_empresas[m_indice]->addFuncionario(new Funcionario(m_nome_funcionario,m_salario_funcionario));
            m_total_geral_funcionarios++;
            cout << "Esperando próximo comando..." << endl;
        }
      break;
      case 3:
        m_indice=verifica_empresa();
        if(m_indice>=0)
        {
          m_empresas[m_indice]->listarFuncionarios();
        }
        cout << "Esperando próximo comando..." << endl;
      break;
      case 4:
        m_indice=verifica_empresa();
        if(m_indice>=0)
        {
          funcionario_porcentagem();
          m_empresas[m_indice]->aumentandoSalario(getPorcentagem_aumento());
        }
        cout << "Esperando próximo comando..." << endl;
      break;
      case 5:
        listarMedia();
        cout << "Esperando próximo comando..." << endl;
      break;
      case 6:
        m_menu_de_entrada=false;
        cout << "Esperando próximo comando..." << endl;
      break;
      case 7:
        listarEmpresas();
        cout << "Esperando próximo comando..." << endl;
      break;
      default:
        cout << "Opção Inválida! Tente Outra Vez." << endl;
        cout << "Esperando próximo comando..." << endl;
    }
  }
}

//Método que trata as entradas que úsuario digitar no menu de comando
int Sindicato::menu()
{
  do{
    string nome_comando;
    cin >> nome_comando;

    if(nome_comando=="Create_Enterprise")
    {
      m_opcao= 1;
    }
    else if(nome_comando=="Add_Employee")
    {
      m_opcao= 2;
    }
    else if(nome_comando == "List_Employee")
    {
      m_opcao= 3;
    }
    else if(nome_comando == "Salary_Increase")
    {
      m_opcao= 4;
    }
    else if(nome_comando=="List_Average")
    {
      m_opcao= 5;
    }
    else if(nome_comando=="Exit")
    {
      m_opcao=6;
    }
    else if(nome_comando=="List_Enterprises")
    {
      m_opcao=7;
    }
    else if(nome_comando== "Clear")
    {
      system("clear");
      ajuda();
      m_opcao=0;
    }
    else if(nome_comando=="Help")
    {
      ajuda();
      m_opcao=0;
    }
    else
    {
      m_opcao=-1;
    }
  }while(m_opcao==0);
  return m_opcao;
}

//Menu de Comandos
void Sindicato::ajuda()
{
  cout << "Menu de Comandos" << endl;
  cout << "Criação de Empresas - Create_Enterprise"<< endl;
  cout << "Adicionar Funcionários em uma empresa - Add_Employee" << endl;
  cout << "Listar Funcionários - List_Employee" << endl;
  cout << "Aumento Salarial - Salary_Increase" << endl;
  cout << "Listar Media de Funcionários - List_Average" << endl;
  cout << "Listar Empresas - List_Enterprises" << endl;
  cout << "Limpar tela - Clear" << endl;
  cout << "Ajuda - Help" << endl;
  cout << "Sair - Exit\n\n" << endl;
}

//Método que é usado na criação da empresa, pedindo nome e cnpj
void Sindicato::empresa_Nome_Cnpj()
{
  cin.ignore();
  cout << "Digite o nome da sua empresa: " << endl;
  getline(cin,m_nome_empresa);
  cout << "Digite o CNPJ da sua empresa: " << endl;
  cin >> m_cnpj;
  cout << "Empresa Cadastrada!\n" << endl;
}

//Método que é usado para receber somente o nome da empresa
void Sindicato::empresa_Nome()
{
  cin.ignore();
  cout << "Digite o nome da sua empresa: " << endl;
  getline(cin,m_nome_empresa);

}

//Método para adicionar funcionários
void Sindicato::funcionario_nome_salario(int indice_)
{
  cout << "Digite o nome do seu funcionário: " << endl;
  getline(cin,m_nome_funcionario);
  if(!m_empresas[indice_]->verifica_nome_funcionario(m_nome_funcionario))
  {
    std::cerr << "Este funcionário já existe! Por favor, informe outro nome." << '\n';
    getline(cin,m_nome_funcionario);
  }
  cout << "Digite o salário de seu funcionário: " << endl;
  cin >> m_salario_funcionario;
  cout << "Funcionário Adicionado!\n" << endl;
}

//Método para receber somente nome dos funcionários
void Sindicato::funcionario_nome()
{
  cout << "Digite o nome de seu funcionário: " << endl;
  getline(cin,m_nome_funcionario);
}

//Método para verificar se empresa existe
int Sindicato::verifica_empresa()
{
  empresa_Nome();
  for(int i=0; i<m_total_empresas;i++)
  {
    if(m_empresas[i]->getNome() == m_nome_empresa)
    {
      return i;
    }
  }
  cerr << "Empresa não encontrada!" << endl;
  return -1;

}

//Método para aumentar sálario dos funcionários de uma empresa
void Sindicato::funcionario_porcentagem()
{
  cout << "Digite a porcentagem que deseja aumentar: " << endl;
  cin >> m_porcentagem_aumento;
}

//Método para listar media de funcionários por empresa
void Sindicato::listarMedia()
{
  float media = m_total_geral_funcionarios/m_total_empresas;
  std::cout << "A média de funcionários por empresa é: " << media <<endl;
}
