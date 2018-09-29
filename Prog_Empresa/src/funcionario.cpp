//Implementação dos métodos da classe funcionário
#include <iostream>
#include <string>
#include "funcionario.h"
using namespace std;

//Construtor
Funcionario::Funcionario(const string nome_, double salario_):m_nome(nome_),m_salario(salario_){}

//Destrutor
Funcionario::~Funcionario(){}

//Getters
string Funcionario::getNome()
{
  return m_nome;
}

double Funcionario::getSalario()
{
  return m_salario;
}
//Fim Getters

//Método para modificar salário
void Funcionario::aumentoSalario(float porcentagem_)
{
  double salario=getSalario();
  m_salario=((porcentagem_*salario)/100)+salario;
}

//Sobrecarga de operador de inserção
std::ostream& operator<<(std::ostream &o, Funcionario * func)
{
  o<<func->getNome()<<" Salário: R$ "<<func->getSalario();
  return o;
}
