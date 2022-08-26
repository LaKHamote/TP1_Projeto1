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

    ISAutenticacao *stubServicoAutenticacao;
    ISUsuario *stubServicoPessoal;
    //ISHospedagem *stubServicoHospedagem;

    stubServicoAutenticacao = new StubServicoAutenticacao();
    stubServicoPessoal = new StubServicoPessoal();
    //stubServicoHospedagem = new StubServicoHospedagem(); precisa implementar os metódos da interface

    // Interligar controladoras e stubs.

    cntrApresentacaoControle->setCntrAAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrAUsuario(cntrApresentacaoPessoal);
    cntrApresentacaoControle->setCntrAHospedagem(cntrApresentacaoHospedagem);

    cntrApresentacaoAutenticacao->setCntrSAutenticacao(stubServicoAutenticacao);
    cntrApresentacaoPessoal->setCntrSUsuario(stubServicoPessoal);
    //cntrApresentacaoHospedagem->setCntrSHospedagem(stubServicoHospedagem);

    initscr();                                                                      // Iniciar curses.
    cntrApresentacaoControle->executar();                                           // Solicitar serviço apresentacao.
    endwin();                                                                       // Finalizar curses.

    return 0;
}
