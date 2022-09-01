#include "main.hpp"

#include <string.h>
#include <stdexcept>
#include <iostream>

using namespace std;

int main()
{
    // Instanciar controladoras de apresentação.

    IAControle *cntrApresentacaoControle;
    IAAutenticacao *cntrApresentacaoAutenticacao;
    IAUsuario *cntrApresentacaoPessoal;
    IAHospedagem *cntrApresentacaoHospedagem;

    cntrApresentacaoControle = new CntrAControle();
    cntrApresentacaoAutenticacao = new CntrAAutenticacao();
    cntrApresentacaoPessoal = new CntrAUsuario();
    cntrApresentacaoHospedagem = new CntrAHospedagem();

    // Instanciar stubs de serviço.

    ISAutenticacao *cntrServicoAutenticacao;
    ISUsuario *cntrServicoPessoal;
    //ISHospedagem *stubServicoHospedagem;

    cntrServicoAutenticacao = new CntrSAutenticacao();
    cntrServicoPessoal = new CntrSUsuario();
    //stubServicoHospedagem = new StubServicoHospedagem(); precisa implementar os metódos da interface

    // Interligar controladoras e stubs.

    cntrApresentacaoControle->setCntrAAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrAUsuario(cntrApresentacaoPessoal);
    cntrApresentacaoControle->setCntrAHospedagem(cntrApresentacaoHospedagem);

    cntrApresentacaoAutenticacao->setCntrSAutenticacao(cntrServicoAutenticacao);
    cntrApresentacaoPessoal->setCntrSUsuario(cntrServicoPessoal);
    //cntrApresentacaoHospedagem->setCntrSHospedagem(stubServicoHospedagem);

    initscr();                                                                      // Iniciar curses.
    cntrApresentacaoControle->executar();                                           // Solicitar serviço apresentacao.
    endwin();                                                                       // Finalizar curses.

    return 0;
}
