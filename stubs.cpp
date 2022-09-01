#include "stubs.hpp"
#include "lib/Curses/curses.h"
#include "lib/Domains/domain.hpp"
#include "lib/Entities/entity.hpp"

// Adequar os valores.

const string StubServicoAutenticacao::INVALIDO = "invalidotorvalds@linux-foundation.org";
const string StubServicoPessoal::INVALIDO = "userinvalidotorvalds@linux-foundation.org";
const string StubServicoHospedagem::NOTA_INVALIDA = "11";

//--------------------------------------------------------------------------------------------
// Implementações dos métodos dos stubs.

bool StubServicoAutenticacao::autenticar(Email email, Password senha){
    if(email.getValue().compare(INVALIDO) == 0)
        return false;
    return true;
}

//--------------------------------------------------------------------------------------------

bool StubServicoPessoal::cadastrar(User usuario){
    if(usuario.getEmail().getValue().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoPessoal::editarConta(User usuario){
    if(usuario.getEmail().getValue().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoPessoal::descadastrarConta(Email email){
    if(email.getValue().compare(INVALIDO) == 0)
        return false;
    return true;
}

User StubServicoPessoal::consultarDadosPessoais(Email email){
    // criando um usuario_stub
    User usuario_stub;

    Name nome;
    nome.setValue(string("Lucas Correa"));
    usuario_stub.setName(nome);
    Email emails;
    emails.setValue(string("lucas@mail.com"));
    usuario_stub.setEmail(emails);
    Password senha;
    senha.setValue(string("aA22&"));
    usuario_stub.setPassword(senha);
    Language idioma;
    idioma.setValue(string("Ingles"));
    usuario_stub.setLanguage(idioma);
    Date aniversario;
    aniversario.setValue(string("24/Dez"));
    usuario_stub.setDate(aniversario);
    Description descricao;
    descricao.setValue(string("Minha Descricao"));
    usuario_stub.setDescription(descricao);

    return usuario_stub;
}

//--------------------------------------------------------------------------------------------

bool StubServicoHospedagem::cadastrarHospedagem(Accommodation hospedagem){
    if(hospedagem.getCode().getValue().compare(CODIGO_INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoHospedagem::consultarHospedagem(Code code){
    if(code.getValue().compare(CODIGO_INVALIDO) == 0)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar código que atribui valores ao objeto identificado por conta.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}

bool StubServicoHospedagem::consultarAvaliacao(Code code){
    if(code.getValue().compare(CODIGO_INVALIDO) == 0)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar código que atribui valores ao objeto identificado por conta.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}

bool StubServicoHospedagem::cadastrarAvaliacao(Code code, Grade grade){
    if(code.getValue().compare(CODIGO_INVALIDO) == 0)
        return false;
    if(grade.getValue().compare(NOTA_INVALIDA) == 0)
        return false;
    return true;
}

bool StubServicoHospedagem::descadastrarAvaliacao(Code codigo){
    if(codigo.getValue().compare(CODIGO_INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoHospedagem::acessarDadosHospedagens(Code code){
    if(code.getValue().compare(CODIGO_INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoHospedagem::listarHospedagens(){
    return true;
}
