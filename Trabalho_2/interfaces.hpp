#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "domain.hpp"
#include "entity.hpp"

//--------------------------------------------------------------------------------------------
// declaração antecipada

class IAAutenticacao;
class IAUsuario;
class IAHospedagem;
class ISAutenticacao;
class ISUsuario;
class ISHospedagem;

//--------------------------------------------------------------------------------------------
// Interfaces camada de apresentação

class IAAutenticacao {
public:
    virtual bool autenticar(Email*) = 0;
    virtual void setCntrSAutenticacao(ISAutenticacao *) = 0;
    virtual ~IAAutenticacao(){}
};

class IAUsuario {
public:
    virtual void executar(Email) = 0;
    virtual void cadastrar() = 0;
    virtual void setCntrSUsuario(ISUsuario*) = 0;
    virtual void setCntrSHospedagem(ISHospedagem*) = 0;
    virtual ~IAUsuario(){}
};

class IAHospedagem{
    public:
        virtual void executar() = 0;
        virtual void executar(Email) = 0;
        virtual void setCntrSHospedagem(ISHospedagem*) = 0;
        virtual ~IAHospedagem(){}
};

//--------------------------------------------------------------------------------------------
// Interfaces camada de serviço

class ISAutenticacao {
public:
    virtual bool autenticar(Email, Password) = 0;
    virtual ~ISAutenticacao(){}
};

class ISUsuario {
public:
    virtual bool cadastrar(User) = 0;
    virtual bool descadastrar(User) = 0;
    virtual bool editar(User) = 0;
    virtual void acessarDadosAnfitrioes() = 0;
    virtual ~ISUsuario(){}
};

class ISHospedagem {
public:
    virtual bool cadastrarHospedagem(Accommodation) = 0;
    virtual bool descadastrarHospedagem(Accommodation) = 0;
    virtual bool editarHospedagem(Accommodation) = 0;
    virtual bool cadastrarAvaliacao(Rating) = 0;
    virtual bool descadastrarAvaliacao(Rating) = 0;
    virtual bool editarAvaliacao(Rating) = 0;
    virtual void listarHospedagens() = 0;
    virtual void acessarDadosHospedagens() = 0;
    virtual ~ISHospedagem(){}
};

#endif // INTERFACES_H_INCLUDED
