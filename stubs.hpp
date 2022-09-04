#ifndef STUBS_HPP_INCLUDED
#define STUBS_HPP_INCLUDED

#include <string>
#include "lib/Domains/domain.hpp"
#include "lib/Entities/entity.hpp"
#include "interfaces.hpp"

using namespace std;

//--------------------------------------------------------------------------------------------
// Classe stub do serviço autenticação.

class StubServicoAutenticacao:public ISAutenticacao {
    private:
        static const string INVALIDO;
    public:
        bool autenticar(Email, Password);
};

//--------------------------------------------------------------------------------------------
// Classe stub do serviço pessoal.

//incompleto
class StubServicoPessoal:public ISUsuario {
    private:
        static const string INVALIDO;
    public:
        bool cadastrar(User);
        bool descadastrarConta(Email);
        bool editarConta(User);
        User consultarDadosPessoais(Email);
};

//--------------------------------------------------------------------------------------------
// Classe stub do serviço produtos financeiros.

//incompleto
class StubServicoHospedagem:public ISHospedagem {
    private:
        static const string CODIGO_INVALIDO;
        static const string NOTA_INVALIDA;
    public:
        bool cadastrarHospedagem(Accommodation);
        bool descadastrarHospedagem(Code);
        bool editarHospedagem(Accommodation);
        Accommodation consultarHospedagem(Code);
        bool cadastrarAvaliacao(Rating);
        bool descadastrarAvaliacao(Code);
        bool editarAvaliacao(Rating);
        User acessarDadosAnfitriaoHospedagem(Code);
        list<string> listarHospedagens();
        Rating consultarAvaliacao(Code);
};


#endif // STUBS_HPP_INCLUDED
