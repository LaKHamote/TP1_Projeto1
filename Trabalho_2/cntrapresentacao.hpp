#ifndef CNTRAPRESENTACAO_HPP_INCLUDED
#define CNTRAPRESENTACAO_HPP_INCLUDED

#include <string.h>
#include "curses.h"
#include "domain.hpp"
#include "entity.hpp"
#include "interfaces.hpp"

//--------------------------------------------------------------------------------------------
// Declarações de classes controladoras e implementações de métodos.

//incompleto
class CntrAControle{
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
        ISUsuario *cntrSUsuario;
        ISHospedagem *cntrSHospedagem;
        void consultarDadosPessoais();
    public:
        void executar(Email);
        void cadastrar();
        void setCntrSUsuario(ISUsuario*);
        void setCntrSHospedagem(ISHospedagem*);
};

inline void CntrAUsuario::setCntrSUsuario(ISUsuario *cntr){
    cntrSUsuario = cntr;
}

inline void CntrAUsuario::setCntrSHospedagem(ISHospedagem *cntr){
    cntrSHospedagem = cntr;
}

//--------------------------------------------------------------------------------------------

// incompleto
class CntrAHospedagem:public IAHospedagem{
    private:
        ISHospedagem *cntr;
        void consultarHospedagem();
        void cadastrarAvaliacao();
        void descadastrarAvaliacao();
        void consultarAvaliacao();
        void acessarDadosHospedagens();
        void listarHospedagens();
    public:
        void executar();
        void executar(Email);
        void setCntrSHospedagem(ISHospedagem*);
};

inline void CntrAHospedagem::setCntrSHospedagem(ISHospedagem *cntr){
    this->cntr = cntr;
}




#endif // CNTRAPRESENTACAO_HPP_INCLUDED
