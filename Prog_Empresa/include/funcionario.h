//Criação da classe Funcionário

#ifndef FUNCIONARIO_H_
#define FUNCIONARIO_H_

#include <iostream>
#include <string>

using namespace std;

class Funcionario{

private:
  string m_nome;
  double m_salario;

public:
  static int geral_funcionarios;
  Funcionario(const string nome_, double salario_);
  ~Funcionario();
  string getNome();
  double getSalario();
  void aumentoSalario(float porcentagem_);
  friend std::ostream& operator<< (std::ostream &o, Funcionario * func);
  bool verifica_nome_funcionario(const string nome_);

};
#endif
