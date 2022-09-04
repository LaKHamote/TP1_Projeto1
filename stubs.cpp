#include "stubs.hpp"
#include "lib/Curses/curses.h"
#include "lib/Domains/domain.hpp"
#include "lib/Entities/entity.hpp"

// Adequar os valores.

const string StubServicoAutenticacao::INVALIDO = "invalidotorvalds@linux-foundation.org";
const string StubServicoPessoal::INVALIDO = "userinvalidotorvalds@linux-foundation.org";
const string StubServicoHospedagem::NOTA_INVALIDA = "7";
const string StubServicoHospedagem::CODIGO_INVALIDO = "79927398713"; 

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

User StubServicoHospedagem::acessarDadosAnfitriaoHospedagem(Code code){
    // criando um usuario_stub
    User usuario_stub;

    Name nome;
    nome.setValue(string("Lucas Anfitriao"));
    usuario_stub.setName(nome);
    Email emails;
    emails.setValue(string("lucas@mail.com"));
    usuario_stub.setEmail(emails);
    Language idioma;
    idioma.setValue(string("Ingles"));
    usuario_stub.setLanguage(idioma);
    Date aniversario;
    aniversario.setValue(string("24/Dez"));
    usuario_stub.setDate(aniversario);
    Description descricao;
    descricao.setValue(string("Anfitriao"));
    usuario_stub.setDescription(descricao);

    return usuario_stub;
}

list<string> StubServicoHospedagem::listarHospedagens(){
    list<string> lista_stub;

    for (int i = 0;i < 20;i++)
        lista_stub.push_back("79927398713");

    return lista_stub;
}

bool StubServicoHospedagem::cadastrarHospedagem(Accommodation hospedagem){
    if(hospedagem.getCode().getValue().compare(CODIGO_INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoHospedagem::cadastrarAvaliacao(Rating avaliacao){
    if(avaliacao.getGrade().getValue().compare(NOTA_INVALIDA) == 0)
        return false;
    return true;
}

Accommodation StubServicoHospedagem::consultarHospedagem(Code code){
    Accommodation hospedagem_stub;

    hospedagem_stub.setCode(code);
    City cidade;
    cidade.setValue("Londres");
    hospedagem_stub.setCity(cidade);
    Country pais;
    pais.setValue("Brasil");
    hospedagem_stub.setCountry(pais);
    Grade nota;
    nota.setValue("10");
    hospedagem_stub.setGrade(nota);
    Description descricao;
    descricao.setValue("Hospedagem Stub");
    hospedagem_stub.setDescription(descricao);
    Email email;
    email.setValue("anfitriao@mail.com");
    hospedagem_stub.setEmail(email);

    return hospedagem_stub;
}

Rating StubServicoHospedagem::consultarAvaliacao(Code code){
    Rating avaliacao;

    avaliacao.setCode(code);
    Grade nota;
    nota.setValue("10");
    avaliacao.setGrade(nota);
    Description descricao;
    descricao.setValue("Avaliacao Stub");
    avaliacao.setDescription(descricao);
    Email email;
    email.setValue("avaliador@mail.com");
    avaliacao.setEmail(email);
    Code hospedagemCode;
    hospedagemCode.setValue("79927398713");
    avaliacao.setAccommodationCode(hospedagemCode);

    return avaliacao;
}

bool StubServicoHospedagem::descadastrarHospedagem(Code code){
    if(code.getValue().compare(CODIGO_INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoHospedagem::descadastrarAvaliacao(Code codigo){
    if(codigo.getValue().compare(CODIGO_INVALIDO) == 0)
        return false;
    return true;
}


bool StubServicoHospedagem::editarHospedagem(Accommodation hospedagem){
    if(hospedagem.getCode().getValue().compare(CODIGO_INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoHospedagem::editarAvaliacao(Rating avaliacao){
    if(avaliacao.getCode().getValue().compare(CODIGO_INVALIDO) == 0)
        return false;
    return true;
}