//Criação da classe empresa
#ifndef EMPRESA_H
#define EMPRESA_H
#define MAX_FUNCIONARIOS 25
using namespace std;
#include <iostream>
#include <string>
#include "funcionario.h"

class Empresa{
private:
  int m_total_funcionarios;
  string m_nome;
  string m_cnpj;
  Funcionario * m_funcionarios[MAX_FUNCIONARIOS];
  float m_porcentagem;

public:
  static int geral_empresas;
  Empresa(const string nome_,const string cnpj_);
  ~Empresa();
  int getTotalFuncionarios();
  string getNome();
  string getCNPJ();
  float getPorcentagem();
  void addFuncionario(Funcionario * employee);
  void listarFuncionarios();
  void aumentandoSalario(float valor_porcentagem);
  friend std::ostream& operator<< (std::ostream &o, Empresa * empre );
  bool operator ==(const string nome_);
  bool verifica_nome_funcionario(const string nome_);

};
#endif
