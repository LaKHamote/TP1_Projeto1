#ifndef CNTRAPRESENTACAO_HPP_INCLUDED
#define CNTRAPRESENTACAO_HPP_INCLUDED

#include <string.h>
#include "../lib/Curses/curses.h"
#include "../lib/Domains/domain.hpp"
#include "../lib/Entities/entity.hpp"
#include "../interfaces.hpp"

//--------------------------------------------------------------------------------------------
// Declarações de classes controladoras e implementações de métodos.


class CntrAControle:public IAControle{
    private:
        Email email;
        IAAutenticacao *cntrAAutenticacao;
        IAUsuario *cntrAUsuario;
        IAHospedagem *cntrAHospedagem;
    public:
        void executar();
        void setCntrAAutenticacao(IAAutenticacao*);
        void setCntrAUsuario(IAUsuario*);
        void setCntrAHospedagem(IAHospedagem*);
};

inline void CntrAControle::setCntrAAutenticacao(IAAutenticacao *cntr){
    cntrAAutenticacao = cntr;
}

inline void CntrAControle::setCntrAUsuario(IAUsuario *cntr){
    cntrAUsuario = cntr;
}

inline void CntrAControle::setCntrAHospedagem(IAHospedagem *cntr){
    cntrAHospedagem = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrAAutenticacao:public IAAutenticacao{
    private:
        ISAutenticacao *cntr;
    public:
        bool autenticar(Email*);
        void setCntrSAutenticacao(ISAutenticacao*);
};

inline void CntrAAutenticacao::setCntrSAutenticacao(ISAutenticacao *cntr){
    this->cntr = cntr;
}

//--------------------------------------------------------------------------------------------

//incompleto
class CntrAUsuario:public IAUsuario{
    private:
        ISUsuario *cntr;
        void consultarDadosPessoais(Email);
        void editarConta(Email);
        bool descadastrarConta(Email);
    public:
        bool executar(Email); // true enquanto usuario não for descadastrado
        void cadastrar();
        void setCntrSUsuario(ISUsuario*);
};

inline void CntrAUsuario::setCntrSUsuario(ISUsuario *cntr){
    this->cntr = cntr;
}

//--------------------------------------------------------------------------------------------

// incompleto
class CntrAHospedagem:public IAHospedagem{
    private:
        ISHospedagem *cntr;
        void listarHospedagens();
        void acessarDadosAnfitriaoHospedagem();
        void cadastrarHospedagem(Email);
        void cadastrarAvaliacao(Email);
        void descadastrarHospedagem(Email);
        void descadastrarAvaliacao(Email);
        void consultarHospedagem();
        void consultarAvaliacao();
        void editarHospedagem(Email);
        void editarAvaliacao(Email);
    public:
        void executar();
        void executar(Email);
        void setCntrSHospedagem(ISHospedagem*);
};

inline void CntrAHospedagem::setCntrSHospedagem(ISHospedagem *cntr){
    this->cntr = cntr;
}




#endif // CNTRAPRESENTACAO_HPP_INCLUDED
