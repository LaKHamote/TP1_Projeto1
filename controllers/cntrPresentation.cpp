#include "cntrPresentation.hpp"
#include <string>

//--------------------------------------------------------------------------------------------
// Implementações dos métodos de classes controladoras.

void CntrAControle::executar(){

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Acessar sistema.";
    char texto3[]="2 - Cadastrar usuario.";
    char texto4[]="3 - Acessar dados sobre Hospedagens.";
    char texto5[]="4 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de seleção de serviço.

    char texto6[]="Selecione um dos servicos : ";
    char texto7[]="1 - Selecionar servicos de usuario.";
    char texto8[]="2 - Selecionar servicos relacionados a Hospedagens.";
    char texto9[]="3 - Encerrar sessao.";

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";                        // Mensagem a ser apresentada.

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela inicial.

        clear();                                                                                //limpa janela
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch(campo){
            case 1: if(cntrAAutenticacao->autenticar(&email)){                         // Solicita autenticação.
                        bool apresentar = true;                                                 // Controle de laço.
                        while(apresentar){

                            // Apresenta tela de seleção de serviço.

                            clear();                                                            // Limpa janela.
                            if (has_colors()){
                                start_color();
                                init_color(COLOR_CYAN, 930, 910, 850);
                                init_pair(1, COLOR_BLACK, COLOR_CYAN);
                                attron(COLOR_PAIR(1));
                                for (int y = 0; y < linha; y++) {
                                    mvhline(y, 0, ' ', coluna);
                                }
                            }
                            box(stdscr, 0, 0);
                            mvprintw(linha/4,coluna/4,"%s",texto6);                             // Imprime nome do campo.
                            mvprintw(linha/4 + 2,coluna/4,"%s",texto7);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 4,coluna/4,"%s",texto8);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 6,coluna/4,"%s",texto9);                         // Imprime nome do campo.                                    // Apresenta tela de seleção de serviço.
                            noecho();
                            campo = getch() - 48;                                               // Leitura do campo de entrada e conversão de ASCII.
                            echo();

                            switch(campo){
                                case 1: if(cntrAUsuario->executar(email)){ // houve descadastramento
                                            apresentar = false;
                                        }
                                        break;
                                case 2: cntrAHospedagem->executar(email);     // Solicita serviço de Hospedagem.
                                        break;
                                case 3: apresentar = false;
                                        break;
                            }
                        }
                    }
                    else {
                        clear();                                                                // Limpa janela.
                        if (has_colors()){
                            start_color();
                            init_color(COLOR_CYAN, 930, 910, 850);
                            init_pair(1, COLOR_BLACK, COLOR_CYAN);
                            attron(COLOR_PAIR(1));
                            for (int y = 0; y < linha; y++) {
                                mvhline(y, 0, ' ', coluna);
                            }
                        }
                        box(stdscr, 0, 0);
                        mvprintw(linha/4,coluna/4,"%s",texto10);                                // Imprime mensagem.
                        noecho();                                                               // Desabilita eco.
                        getch();                                                                // Leitura de caracter digitado.
                        echo();                                                                 // Habilita eco.
                    }
                    break;
            case 2: cntrAUsuario->cadastrar();
                    break;
            case 3: cntrAHospedagem->executar();
                    break;
            case 4: apresentar = false;
                    break;
        }
    }
    return;
}

//--------------------------------------------------------------------------------------------

bool CntrAAutenticacao::autenticar(Email *email){

    // Mensagens a serem apresentadas na tela de autenticação.

    char texto1[]="Digite o Email: ";
    char texto2[]="Digite a Senha: ";
    char texto3[]="Dado em formato incorreto.";
    char texto4[]="1 - Tentar novamente.";
    char texto5[]="2 - Retornar ao menu principal";

    // Campos de entrada.

    int campo;
    char campo1[80];
    char campo2[80];

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    Password senha;                                                                                // Instancia a classe Senha.

    echo();                                                                                     // Habilita eco.

    while(true){

        // Apresenta tela de autenticação.

        clear();                                                                                // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        getstr(campo1);                                                                         // Lê valor do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        getstr(campo2);                                                                         // Lê valor do campo.

        try{
            email->setValue(string(campo1));                                                      // Atribui valor ao Email.
            senha.setValue(string(campo2));                                                     // Atribui Valor à senha.
            break;                                                                              // Abandona laço em caso de formatos corretos.
        }
        catch(invalid_argument &exp){                                                           // Captura exceção devido a formato incorreto.
            clear();                                                                            // Limpa janela.
            if (has_colors()){
                start_color();
                init_color(COLOR_CYAN, 930, 910, 850);
                init_pair(1, COLOR_BLACK, COLOR_CYAN);
                attron(COLOR_PAIR(1));
                for (int y = 0; y < linha; y++) {
                    mvhline(y, 0, ' ', coluna);
                }
            }
            box(stdscr, 0, 0);
            echo();
            mvprintw(linha/4,coluna/4,"%s",texto3);                                             // Informa formato incorreto.
            mvprintw(linha/4 + 2,coluna/4,"%s",texto4);
            mvprintw(linha/4 + 4,coluna/4,"%s",texto5);
            noecho();
            campo = getch() - 48;                                                                            // Lê caracter digitado.
            echo();
            if (campo == 2)
                return false;
        }
    }
    return (cntr->autenticar(*email, senha));                                                     // Solicita serviço de autenticação.
}

//--------------------------------------------------------------------------------------------

bool CntrAUsuario::executar(Email email){

    // Mensagens a serem apresentadas na tela de seleção de serviço..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Consultar dados pessoais.";
    char texto3[]="2 - Editar conta.";
    char texto4[]="3 - Descadastrar conta.";
    char texto5[]="4 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    bool apresentar = true;                                                                     // Controle de laço.

    echo();                                                                                     // Habilita eco.

    while(apresentar){

        // Apresenta tela de selação de serviço.

        clear();                                                                                // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch(campo){
            case 1: consultarDadosPessoais(email);
                    break;
            case 2: editarConta(email);
                    break;
            case 3: if(descadastrarConta(email)){
                        apresentar = false;
                        return true; // houve descadastramento
                    }
                    break;
            case 4: apresentar = false;
                    break;
        }
    }
    return false; // não houve descadastramento
}

//--------------------------------------------------------------------------------------------

void CntrAUsuario::cadastrar(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Nome            :";
    char texto3[] ="Email           :";
    char texto4[] ="Senha           :";
    char texto5[] ="Idioma          :";
    char texto6[] ="Aniversario     :";
    char texto7[] ="Descricao       :";
    char texto8[] ="Dados em formato incorreto. Digite algo.";
    char texto9[] ="Sucesso no cadastramento. Digite algo.";
    char texto10[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80], campo6[80];                // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Name nome;
    Email email;
    Password senha;
    Language idioma;
    Date aniversario;
    Description descricao;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s ",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s ",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 10,coluna/4,"%s ",texto6);                                                // Imprime nome do campo.
    getstr(campo5);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 12,coluna/4,"%s ",texto7);                                                // Imprime nome do campo.
    getstr(campo6);                                                                             // Lê valor do campo.

    try{
        nome.setValue(string(campo1));
        email.setValue(string(campo2));
        senha.setValue(string(campo3));
        idioma.setValue(string(campo4));
        aniversario.setValue(string(campo5));
        descricao.setValue(string(campo6));
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto8);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade usuario.

    User usuario;

    usuario.setName(nome);
    usuario.setEmail(email);
    usuario.setPassword(senha);
    usuario.setLanguage(idioma);
    usuario.setDate(aniversario);
    usuario.setDescription(descricao);

    // Cadastra usuário.
    if(cntr->cadastrar(usuario)){
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
            box(stdscr, 0, 0);
        }
        mvprintw(linha/4 + 2,coluna/4,"%s",texto9);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }


    clear();
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto10);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrAUsuario::consultarDadosPessoais(Email email){

    // Mensagens a serem apresentadas na tela de apresentação de dados pessoais.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    //char texto[]="Servico consultar dados pessoais nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    char texto1[] ="Nome            :";
    char texto2[] ="Email           :";
    char texto3[] ="Senha           :";
    char texto4[] ="Idioma          :";
    char texto5[] ="Aniversario     :";
    char texto6[] ="Descricao       :";
    char texto7[] ="Digite algo para retornar.";

    User usuario;

    usuario = cntr->consultarDadosPessoais(email);

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s %s",texto1, usuario.getName().getValue().c_str());                                                      // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s %s",texto2, usuario.getEmail().getValue().c_str()); 
    mvprintw(linha/4 + 4,coluna/4,"%s %s",texto3, usuario.getPassword().getValue().c_str()); 
    mvprintw(linha/4 + 6,coluna/4,"%s %s",texto4, usuario.getLanguage().getValue().c_str());
    mvprintw(linha/4 + 8,coluna/4,"%s %s",texto5, usuario.getDate().getValue().c_str());
    mvprintw(linha/4 + 10,coluna/4,"%s %s",texto6, usuario.getDescription().getValue().c_str());
    mvprintw(linha/4 + 12,coluna/4,"%s",texto7);
    noecho();
    getch();
    echo();
}

void CntrAUsuario::editarConta(Email email){

    // Mensagens a serem apresentadas na tela de apresentação de dados pessoais.
    char texto1[] ="Preencha os seguintes campos: (Deixe em branco caso nao queira alterar)";
    char texto2[] ="Nome            :";
    char texto3[] ="Senha           :";
    char texto4[] ="Idioma          :";
    char texto5[] ="Aniversario     :";
    char texto6[] ="Descricao       :";
    char texto7[] ="Dados em formato incorreto. Digite algo.";
    char texto8[] ="Sucesso na edicao. Digite algo.";
    char texto9[]="Falha na edicao. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80];

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.


    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                      // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
    getstr(campo1);
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);
    getstr(campo2);
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);
    getstr(campo3);
    mvprintw(linha/4 + 8,coluna/4,"%s",texto5);
    getstr(campo4);
    mvprintw(linha/4 + 10,coluna/4,"%s",texto6);
    getstr(campo5);

    // Instancia os domínios.

    Name nome;
    Password senha;
    Language idioma;
    Date aniversario;
    Description descricao;

    try{
        if (string(campo1) != "")
            nome.setValue(string(campo1));
        if (string(campo2) != "")
            senha.setValue(string(campo2));
        if (string(campo3) != "")
            idioma.setValue(string(campo3));
        if (string(campo4) != "")
            aniversario.setValue(string(campo4));
        if (string(campo5) != "")
            descricao.setValue(string(campo5));   
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto7);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    User usuario;

    usuario.setName(nome);
    usuario.setEmail(email);
    usuario.setPassword(senha);
    usuario.setLanguage(idioma);
    usuario.setDate(aniversario);
    usuario.setDescription(descricao);

    // Edita usuário.
    if(cntr->editarConta(usuario)){
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto8);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }


    clear();
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto9);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}


bool CntrAUsuario::descadastrarConta(Email email){

    // Mensagens a serem apresentadas na tela de apresentação de dados pessoais.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto1[]="Ao descadastrar sua conta todas as hospedagens e avaliacoes atreladas a sua conta serao descadastradas.";
    char texto2[]="Voce tem certeza que deseja descadastrar sua conta?";                         // Mensagem a ser apresentada.
    char texto3[]="1 - Descadastrar.";
    char texto4[]="2 - Retornar.";
    char texto5[]="Sucesso, conta descadastrada.";
    char texto6[]="Falha no descadastramento.";

    int campo;    

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/8,"%s",texto1);                                                      // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/8,"%s",texto2);
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);
    noecho();
    campo = getch() - 48;
    echo();

    // Descadastra usuario
    if (campo == 1){
        if(cntr->descadastrarConta(email)){
            clear();
            if (has_colors()){
                start_color();
                init_color(COLOR_CYAN, 930, 910, 850);
                init_pair(1, COLOR_BLACK, COLOR_CYAN);
                attron(COLOR_PAIR(1));
                for (int y = 0; y < linha; y++) {
                    mvhline(y, 0, ' ', coluna);
                }
            }
            box(stdscr, 0, 0);
            mvprintw(linha/4 + 2,coluna/4,"%s",texto5);                                               // Informa sucesso.
            noecho();
            getch();
            echo();
            return true;
        }
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto6);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return false;
    }
    return false;
}


//--------------------------------------------------------------------------------------------


void CntrAHospedagem::executar(){
    // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.
    char texto1[]="Selecione um dos serviços : ";
    char texto2[]="1 - Consultar produto de investimento.";
    char texto3[]="2 - Retornar.";
    int campo;                                                                                  // Campo de entrada.
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    echo();                                                                                     // Habilita eco.
    bool apresentar = true;                                                                     // Controle de laço.
    while(apresentar){
        // Apresenta tela simplificada de produtos financeiros.
        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();
        switch(campo){
            case 1:
                consultarHospedagem();
                break;
            case 2:
                apresentar = false;
                break;
        }
    }
}

void CntrAHospedagem::executar(Email email){
    char texto1[] ="Selecione um dos servicos:";
    char texto2[] ="1 - Consultar hospedagem.";
    char texto3[] ="2 - Cadastrar hospedagem.";
    char texto4[] ="3 - Cadastrar avaliacao.";
    char texto5[] ="4 - Descadastrar avaliacao.";
    char texto6[] ="5 - Consultar avaliacao.";
    char texto7[] ="6 - Acessar dados de hospedagens disponiveis.";
    char texto8[] ="7 - Listar Hospedagens.";
    char texto9[] ="8 - Retornar.";
    int campo;                                                                                  // Campo de entrada.
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    echo();                                                                                     // Habilita eco.
    bool apresentar = true;                                                                     // Controle de laço.
    echo();                                                                                     // Habilita eco.
    while(apresentar){
        // Apresenta tela completa de produtos financeiros.
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);                                                                               // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 12,coluna/4,"%s",texto7);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 14,coluna/4,"%s",texto8);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 16,coluna/4,"%s",texto9);                                            // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();
        switch(campo){
            case 1:
                consultarHospedagem();
                break;
            case 2:
                cadastrarHospedagem();
                break;
            case 3:
                cadastrarAvaliacao();
                break;
            case 4:
                descadastrarAvaliacao();
                break;
            case 5:
                consultarAvaliacao();
                break;
            case 6:
                acessarDadosHospedagens();
                break;
            case 7:
                listarHospedagens();
                break;
            case 8:
                apresentar = false;
                break;
        }
    }
}

string CntrAHospedagem::auxiliar(int linha, int coluna, char campo[], char texto[]) {
    clear();    
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);                                                                                // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);   
    mvprintw(linha/4 + 2,coluna/4,"%s","");   
    getstr(campo);
    return (string)campo;
}

void CntrAHospedagem::consultarHospedagem(){
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);
    char texto1[] ="Digite o codigo da hospedagem a ser consultada.";
    char erro1[] ="Formato de codigo invalido.";
    char idHospedagem[80];
    Code code;
    try {
        code.setValue(auxiliar(linha, coluna, idHospedagem, texto1));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",erro1);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }
    cntr->consultarHospedagem(code);
    noecho();
    getch();
    echo();
}

void CntrAHospedagem::cadastrarHospedagem() {
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);
    char textoCodigo[] ="Digite o codigo da hospedagem a ser cadastrada.";
    char textoCidade[] ="Digite a cidade de origem.";
    char textoPais[] ="Digite o pais de origem.";
    char textoDescricao[] ="Digite uma descricao para a hospedagem.";
    char campoCodigo[80];
    char campoCidade[80];
    char campoPais[80];
    char campoDescricao[80];
    char erroCodigo[] ="Formato de codigo invalido.";
    char erroCidade[] ="Formato de cidade invalido.";
    char erroPais[] ="Formato de pais invalido.";
    char erroDescricao[] ="Formato de descricao invalido.";
    char *erros[4] = {
        erroCodigo,
        erroCidade,
        erroPais,
        erroDescricao
    };
    Code code;
    City city;
    Country country;
    Description description;
    Accommodation hospedagem;
    int index = 0;
    try {
        code.setValue(auxiliar(linha, coluna, campoCodigo, textoCodigo));
        ++index;
        city.setValue(auxiliar(linha, coluna, campoCidade, textoCidade));
        ++index;
        country.setValue(auxiliar(linha, coluna, campoPais, textoPais));
        ++index;
        description.setValue(auxiliar(linha, coluna, campoDescricao, textoDescricao));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",erros[index]);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }
    hospedagem.setCode(code);
    hospedagem.setCity(city);
    hospedagem.setCountry(country);
    hospedagem.setDescription(description);
    cntr->cadastrarHospedagem(hospedagem);
}

void CntrAHospedagem::cadastrarAvaliacao(){
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);
    char texto1[] ="Digite o codigo da hospedagem para a qual a avaliacao sera cadastrada.";
    char texto2[] ="Digite a avaliacao para a hospedagem que foi informada.";
    char erro1[] ="Formato de codigo invalido.";
    char erro2[] ="Formato invalido de avaliacao.";
    char *erros[2] = {erro1, erro2};
    char idHospedagem[80];
    char avaliacaoHospedagem[80];
    Code code;
    Grade grade;
    int index = 0;
    try {
        code.setValue(auxiliar(linha, coluna, idHospedagem, texto1));
        ++index;
        grade.setValue(auxiliar(linha, coluna, avaliacaoHospedagem, texto2));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",erros[index]);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }
    Rating avaliacao;
    avaliacao.setCode(code);
    avaliacao.setGrade(grade);




    
    ////////////////////// falta implementar accommodacion_grade e email




    cntr->cadastrarAvaliacao(avaliacao);
    noecho();
    getch();
    echo();
}

void CntrAHospedagem::descadastrarAvaliacao(){
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    char texto[]="Informe o codigo da hospedagem cuja avaliacao sera descadastrada";            // Mensagem a ser apresentada.
    char erro1[] ="Formato de codigo invalido.";
    char idHospedagem[80];
    Code code;
    try {
        code.setValue(auxiliar(linha, coluna, idHospedagem, texto));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",erro1);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }
    cntr->descadastrarAvaliacao(code);
    noecho();
    getch();
    echo();
}

void CntrAHospedagem::consultarAvaliacao(){
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);
    char texto1[] ="Digite o codigo da hospedagem cuja avaliacao sera consultada.";
    char erro1[] ="Formato de codigo invalido.";
    char idHospedagem[80];
    Code code;
    try {
        code.setValue(auxiliar(linha, coluna, idHospedagem, texto1));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",erro1);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }
    cntr->consultarHospedagem(code);
    noecho();
    getch();
    echo();
}

void CntrAHospedagem::acessarDadosHospedagens(){
    int linha,coluna;                                                                               // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                                  // Armazena quantidade de linhas e colunas.
    char texto[]="Informe o codigo da hospedagem a ser acessada.";                                  // Mensagem a ser apresentada.
    char erro[]="Formato de codigo invalido";
    char campo[80];
    Code code;
    try {
        code.setValue(auxiliar(linha, coluna, campo, texto));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",erro);                                               // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }
    cntr->acessarDadosAnfitriaoHospedagem(code);
    noecho();
    getch();
    echo();
}

void CntrAHospedagem::listarHospedagens(){
    cntr->listarHospedagens();
    noecho();
    getch();
    echo();
}
