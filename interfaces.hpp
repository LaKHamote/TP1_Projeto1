#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "lib/Domains/domain.hpp"
#include "lib/Entities/entity.hpp"

#include <map>
//--------------------------------------------------------------------------------------------
// declaração antecipada

class IAControle;
class IAAutenticacao;
class IAUsuario;
class IAHospedagem;
class ISAutenticacao;
class ISUsuario;
class ISHospedagem;

//--------------------------------------------------------------------------------------------
// Interfaces camada de apresentação

class IAControle {
public:
    virtual void executar() = 0;
    virtual void setCntrAAutenticacao(IAAutenticacao*) = 0;
    virtual void setCntrAUsuario(IAUsuario*) = 0;
    virtual void setCntrAHospedagem(IAHospedagem*) = 0;
    virtual ~IAControle(){}
};

class IAAutenticacao {
public:
    virtual bool autenticar(Email*) = 0;
    virtual void setCntrSAutenticacao(ISAutenticacao *) = 0;
    virtual ~IAAutenticacao(){}
};

class IAUsuario {
public:
    virtual bool executar(Email) = 0; // true enquanto usuario não for descadastrado
    virtual void cadastrar() = 0;
    virtual void setCntrSUsuario(ISUsuario*) = 0;
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
    virtual bool descadastrarConta(Email) = 0;
    virtual bool editarConta(User) = 0;
    virtual User consultarDadosPessoais(Email) = 0;
    virtual ~ISUsuario(){}
};

class ISHospedagem {
public:
    virtual bool cadastrarHospedagem(Accommodation) = 0;
    virtual bool descadastrarHospedagem(Code) = 0;
    virtual bool editarHospedagem(Accommodation) = 0;
    virtual Accommodation consultarHospedagem(Code) = 0;
    virtual bool cadastrarAvaliacao(Rating) = 0;
    virtual bool descadastrarAvaliacao(Code) = 0;
    virtual bool editarAvaliacao(Rating) = 0;
    virtual std::map<string, Accommodation> listarHospedagens() = 0;
    virtual User acessarDadosAnfitriaoHospedagem(Code) = 0;
    virtual ~ISHospedagem(){}
};

#endif // INTERFACES_H_INCLUDED
