//Implementação de métodos da classe Empresa
#include <iostream>
#include "empresa.h"
#include "funcionario.h"
using namespace std;

//Construtor
Empresa::Empresa(const string nome_, const string cnpj_){
  m_nome=nome_;
  m_cnpj=cnpj_;
  m_total_funcionarios=0;
  m_porcentagem=0.00;
}
//Destrutor
Empresa::~Empresa(){}

//Criação de Getters;
int Empresa::getTotalFuncionarios()
{
  return m_total_funcionarios;
}

string Empresa::getNome()
{
  return m_nome;
}

string Empresa::getCNPJ()
{
  return m_cnpj;
}

float Empresa::getPorcentagem()
{
  return m_porcentagem;
}
//Fim Getters;


//Adicionando Funcionários na empresa;
void Empresa::addFuncionario(Funcionario * employee)
{
  if(m_total_funcionarios<MAX_FUNCIONARIOS)
  {
    m_funcionarios[m_total_funcionarios++]=employee;
  }
  else
  {
    cerr << "A Empresa não está contratando mais!\nDeixe seu curriculo que entraremos em contato.\nAtt. "<<getNome() << endl;
  }
}

//Listando Funcionários da Empresa;
void Empresa::listarFuncionarios()
{
  for(int i=0;i<m_total_funcionarios;i++)
  {
    cout <<i+1<< ": " << m_funcionarios[i] << endl;
  }
  cout << endl;
}
//Aumentando Salário de fúncionarios na Empresa
void Empresa::aumentandoSalario(float valor_porcentagem)
{
  m_porcentagem=valor_porcentagem;
  for(int i=0; i<m_total_funcionarios; i++)
  {
    m_funcionarios[i]->aumentoSalario(getPorcentagem());
  }
}
//Sobrecarga do operador de inserção
std::ostream& operator<< (std::ostream &o, Empresa * empre)
{
  o<<empre->getNome()<<"- Quantidade de funcionários: "<<empre->getTotalFuncionarios();
  return o;
}

//Método para verificação de nome de funcionário já existente
bool Empresa::verifica_nome_funcionario(const string nome_)
{
  for(int i=0; i<m_total_funcionarios; i++)
  {
    if(nome_==m_funcionarios[i]->getNome())
    {
      return false;
    }
  }
  return true;
}

//Sobrecarga de operador de igualdade
bool Empresa::operator== (const string nome_)
{
  if(m_nome == nome_)
  {
    return true;
  }
  return false;
}
