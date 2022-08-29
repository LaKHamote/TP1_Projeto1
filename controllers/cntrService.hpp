#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include <string>
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

/*
class CntrSHospedagem:public ISHospedagem{
    // Métodos públicos presentes na interface realizada.
};
*/

#endif // CONTROLADORASSERVICO_H_INCLUDED