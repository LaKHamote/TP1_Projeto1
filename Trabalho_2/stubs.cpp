#include "stubs.hpp"

// Adequar os valores.

const string StubServicoAutenticacao::INVALIDO = "12345";
const string StubServicoPessoal::INVALIDO = "12345";
const string StubServicoHospedagem::INVALIDO = "12345";

//--------------------------------------------------------------------------------------------
// Implementações dos métodos dos stubs.

bool StubServicoAutenticacao::autenticar(Email email, Password senha){
    if(email.getValue().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoPessoal::cadastrarUsuario(User usuario){
    if(usuario.getEmail().getValue().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoHospedagem::cadastrarHospedagem(Accommodation hospedagem){
    if(hospedagem.getCode().getValue().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoHospedagem::consultarHospedagem(Accommodation *hospedagem){
    if(hospedagem->getCode().getValue().compare(INVALIDO) == 0)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar código que atribui valores ao objeto identificado por conta.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}

bool StubServicoHospedagem::cadastrarAvaliacao(Rating avaliacao){
    if(avaliacao.getCode().getValue().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoHospedagem::descadastrarAvaliacao(Code codigo){
    if(codigo.getValue().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoHospedagem::acessarDadosHospedagens(Rating avaliacao){
    if(avaliacao.getCode().getValue().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoHospedagem::listarHospedagens(Rating *avaliacao){
    if(avaliacao->getCode().getValue().compare(INVALIDO) == 0)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar código que atribui valores ao objeto identificado por aplicacao.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}
