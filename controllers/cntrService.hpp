#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include <string>
#include <list>
#include "../lib/Domains/domain.hpp"
#include "../lib/Entities/entity.hpp"
#include "../interfaces.hpp"
#include "../containers.hpp"

using namespace std;

//--------------------------------------------------------------------------------------------
// Declarações de classes controladoras da camada de serviços.

class CntrSAutenticacao:public ISAutenticacao{
    public:
        bool autenticar(Email, Password);
};

//--------------------------------------------------------------------------------------------

class CntrSUsuario:public ISUsuario{
    public:
        bool cadastrar(User);
        bool descadastrarConta(Email);
        bool editarConta(User);
        User consultarDadosPessoais(Email);
};

//--------------------------------------------------------------------------------------------


class CntrSHospedagem:public ISHospedagem{
    public:
        bool cadastrarHospedagem(Accommodation);
        bool descadastrarHospedagem(Code);
        bool editarHospedagem(Accommodation);
        Accommodation consultarHospedagem(Code);
        bool cadastrarAvaliacao(Rating);
        bool descadastrarAvaliacao(Code);
        bool editarAvaliacao(Rating);
        Rating consultarAvaliacao(Code);
        User acessarDadosAnfitriaoHospedagem(Code);
        list<string> listarHospedagens();
};


#endif // CONTROLADORASSERVICO_H_INCLUDED