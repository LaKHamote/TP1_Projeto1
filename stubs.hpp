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
        Accommodation consultarHospedagem(Code);
        bool consultarAvaliacao(Code);
        bool cadastrarAvaliacao(Rating);
        bool descadastrarAvaliacao(Code);
        User acessarDadosAnfitriaoHospedagem(Code);
        std::map<string, Accommodation> listarHospedagens();
};


#endif // STUBS_HPP_INCLUDED
