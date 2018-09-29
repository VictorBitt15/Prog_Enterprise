//Criação da classe Sindicato que irá controlar o fluxo da criaçao de empresas
#ifndef SINDICATO_H
#define SINDICATO_H
#define MAX_EMPRESAS 25

#include <iostream>
#include <string>
#include "empresa.h"

using namespace std;

class Sindicato {
private:
  int m_opcao;
  float m_porcentagem_aumento;
  int m_indice;
  bool m_menu_de_entrada;
  Empresa * m_empresas[MAX_EMPRESAS];
  int m_total_empresas;
  int m_total_geral_funcionarios;
  string m_nome_empresa;
  string m_cnpj;
  string m_nome_funcionario;
  double m_salario_funcionario;

public:
  Sindicato();
  ~Sindicato ();
  int getTotalEmpresas();
  int getTotalGeralFuncionarios();
  float getPorcentagem_aumento();
  void addEmpresa(Empresa * Enterprise);
  void listarEmpresas();
  void run();
  int menu();
  void empresa_Nome_Cnpj();
  void empresa_Nome();
  string getNomeEmpresa();
  void funcionario_nome_salario(int indice_);
  void funcionario_nome();
  int verifica_empresa();
  void funcionario_porcentagem();
  void listarMedia();
  void ajuda();
};



#endif
