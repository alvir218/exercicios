//allan stuart virmond 2379525

#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<fstream>
#include "Usuario.h";
#include "Filme.h";



void criar_usuario(vector<Usuario>& usuariosf);
void listar_filmes(vector<Filme>& filmesf);
Usuario* logar(vector<Usuario>& usuariosf, string loginf, string senhaf);
Filme* filme_existente(vector<Filme>& filmesf, string nomef);
void salvar_dados(vector<Filme>& filmesf, vector<Usuario>& usuariosf, string saidaf);
unsigned long long int posicao_do_filme(vector<Filme>& filmesf, string nomef, string usuariof);


int main(int argumentosn, char* argumentosv[]) {
	
	vector<Usuario> usuarios;
	vector<Filme> filmes;
	int menu;
	string nome_do_filme;
	Filme* filme_temporario;
	string usuario_temporario;
	string senha_temporario;
	string tag_temporario;
	int ano_temporario;
	float nota_temporario;
	string arquivo_entrada;
	string arquivo_saida;
	unsigned long long int posicao = 0;



	if (argumentosn == 1) {
		arquivo_saida = "salvo.xml";
		
		cout << "\nnao foi possivel obter base de dados.\n";
		cout << "\no arquivo de base de dados\nnao foi passado como paramentro\na saida padrao sera " << arquivo_saida << ".\n";
		
	}
	else if(argumentosn == 2){
		arquivo_entrada = argumentosv[1];
		arquivo_saida = "salvo.xml";
		
		cout << "\ncarregando base de dados de " << argumentosv[1] << " ...\n";
		cout << "\no nome do arquivo de saida nao foi informado,\na saida padrao sera " << arquivo_saida << ".\n";
		

	}
	else if (argumentosn == 3) {
		arquivo_entrada = argumentosv[1];
		arquivo_saida = argumentosv[2];
		
		cout << "\ncarregando base de dados...\n";
		cout << "\nobtendo base de dados de " << arquivo_entrada << "\na base de dados sera salva como " << arquivo_saida << ".\n";
	}
	else if (argumentosn > 3) {
		cout << "\nerro de inicializacao cheque os parametros de inicializacao.\n\n\n";
		system("pause");
		return 1;

	}
	
	if (argumentosn > 1) {
			//inicia a entrada de dados
		ifstream entrada(arquivo_entrada);

		if (!entrada.good()) {
			cout << "\nerro ao abrir " << arquivo_entrada << ".\nverifique se o nome e local do arquivo estam de acordo.\n";
		}

		do {
			entrada >> tag_temporario;
		} while (tag_temporario != "<usuarios>");

		while (1) {
			entrada >> usuario_temporario;
			if (usuario_temporario == "</usuarios>") {
				break;
			}
			entrada >> senha_temporario;

			usuarios.push_back({ usuario_temporario, senha_temporario });


		}

		while (1) {
			do {
				entrada >> tag_temporario;

			} while (tag_temporario != "<filme>" && tag_temporario != "</filmes>");

			if (tag_temporario == "</filmes>") {
				break;
			}

			entrada.ignore();
			getline(entrada, nome_do_filme);
			entrada >> ano_temporario;
			entrada >> usuario_temporario;
			entrada >> nota_temporario;
			filmes.push_back({ nome_do_filme, ano_temporario, usuario_temporario, nota_temporario });

			do {
				entrada >> tag_temporario;
			} while (tag_temporario != "<notas>");

			while (1) {
				entrada >> usuario_temporario;
				if (usuario_temporario == "</notas>") {
					break;
				}
				entrada >> nota_temporario;
				filmes[filmes.size() - 1].notas[usuario_temporario] = nota_temporario;
			}

			do {
				entrada >> tag_temporario;
			} while (tag_temporario != "</filme>");

		}

		entrada.close();
	}



	while(1){
		cout << "\nbem vindo ao mundo do cinema...\n\ncomo deseja prosseguir?\n";
		cout << "\n1. ja tenho conta cadastrada.\n2. criar um novo usuario.\n3. encerrar o sistema.\n";
		do {
			cin >> menu;
		} while (menu != 1 && menu != 2 && menu != 3);

			//sistema em si, enquanto o usuario quiser mexer
		if (menu == 1) {
			string login_temporario;
			string senha;
			Usuario* usuario_ativo;
			int desistir_de_logar = 0;
			int menu_usuario = 0;

				//autenticacao
			do {
				cout << "\ndigite seu nome de usuario:\n";
				cin >> login_temporario;
				cout << "\ndigite a senha:\n";
				cin >> senha;
				usuario_ativo = logar(usuarios, login_temporario, senha);
				if (usuario_ativo == NULL) {
					cout << "\nfalha na autenticacao, deseja desistir e criar um usuario?\n1. sim.\n0. nao.\n";
					cin >> desistir_de_logar;
					if (desistir_de_logar == 1) {
						menu_usuario = 0;
					}
				}
				else {
					menu_usuario = -1;
				}

			} while (usuario_ativo == NULL && menu_usuario != 0);
						
				//o usuario mexendo no sistema ate desejar sair
			while (menu_usuario != 0) {
					
				cout << "\no que deseja fazer?\n0. sair.\n1. editar filme.\n2. listar os filmes.\n3. adicionar um filme ao catalogo.\n4. remover um filme do catalogo.\n";
				do {
					cin >> menu_usuario;
				} while (menu_usuario < 0 || menu_usuario > 4);
				
					//editar filme
				if (menu_usuario == 1) {
					cout << "\ndigite o nome do filme para edita-lo:\n";
					cin.ignore();
					getline(cin, nome_do_filme);
					filme_temporario = filme_existente(filmes, nome_do_filme);
					
					if (filme_temporario != NULL) {
						usuario_ativo->editar_filme(filme_temporario);
					}


				}
					//listar filmes
				else if (menu_usuario == 2) {
					listar_filmes(filmes);
				}
					//adicionar filme
				else if (menu_usuario == 3) {
					cout << "\ndigite o nome do filme para cria-lo:\n";
					cin.ignore();
					getline(cin,nome_do_filme);
					if (filme_existente(filmes, nome_do_filme) == NULL){
						filmes.push_back(usuario_ativo->criar_filme(nome_do_filme));
					}
					else {
						cout << "\nesse filme ja esta registrado\n";
					}
				}
					//remover filme
				else if (menu_usuario == 4) {
					cout << "\ndigite o nome do filme.\n";
					cin.ignore();
					getline(cin, nome_do_filme);
					posicao = posicao_do_filme(filmes, nome_do_filme, usuario_ativo->login);

					if (posicao != 0) {
						filmes.erase(filmes.begin() + (posicao - 1));
						cout << "\n" << nome_do_filme << " foi removido.\n";
					}

				}

			}
		}
		else if (menu == 2) {
			criar_usuario(usuarios);
		}
		else if(menu == 3){
			int encerrar = 0;
				//encerrar o sistema
			cout << "\ntem certeza que deseja encerrar o sistema?\n0. nao\n1. sim\n";
			do{
				cin >> encerrar;
			} while (encerrar != 0 && encerrar != 1);
			
			if (encerrar == 1) {
				salvar_dados(filmes, usuarios, arquivo_saida);

				cout << "\n\n";
				system("pause");
				return 0;
			}
				
		}

	}

}

void criar_usuario(vector<Usuario>& usuariosf) {
	string login_temporario;
	string senha_temporario;
	string senha_de_confirmacao;
	bool login_novo = true;
	
	do {
		login_novo = true;
		cout << "\ndigite seu nome de usuario\n";
		cin >> login_temporario;

		for (auto& iteracao : usuariosf) {
			if (iteracao.login == login_temporario) {
				cout << "\nesse nome de usuario ja existe, \nescolha um outro nome de usuario.\n";
				login_novo = false;
				break;
			}
		}

	} while (login_novo == false);

	do {
		cout << "\ndigite a senha:\n";
		cin >> senha_temporario;
		cout << "\nrepita a senha:\n";
		cin >> senha_de_confirmacao;

		if (senha_temporario != senha_de_confirmacao) {
			cout << "\nas senhas nao conferem digite novamente.\n";
		}

	} while (senha_temporario != senha_de_confirmacao);


	
	
	usuariosf.push_back(Usuario(login_temporario, senha_temporario));
}

void listar_filmes(vector<Filme>& filmesf) {
	for (auto& iteracao : filmesf) {
		iteracao.informar();
		cout << "\n";
	}
}

Usuario* logar(vector<Usuario>& usuariosf, string loginf, string senhaf) {
	
	Usuario* usuario_temporario = NULL;
	
	for (auto& iteracao : usuariosf) {
		if (iteracao.login == loginf) {
			usuario_temporario = &iteracao;
		}
	}

	return usuario_temporario;
}

Filme* filme_existente(vector<Filme>& filmesf, string nomef){
	Filme* filme_encontrado = NULL;
	for (auto& iteracao : filmesf) {
		if (iteracao.nome == nomef) {
			filme_encontrado = &iteracao;
		}
	}
	
	if (filme_encontrado == NULL) {
		cout << "\ntu pode adicionar este filme.\n";
	}
	else {
		cout << "\nesse filme ja esta no catalogo.\n";
	}


	return filme_encontrado;
}

void salvar_dados(vector<Filme>& filmesf, vector<Usuario>& usuariosf, string saidaf) {
	ofstream saida(saidaf);

	saida << "<usuarios>\n";

	for (auto& iteracao : usuariosf) {
		saida << iteracao.login << " " << iteracao.senha << endl;
	}

	saida << "</usuarios>\n\n";

	saida << "<filmes>\n\n";

	for (auto& filme : filmesf) {
		saida << "<filme>\n";
		saida << filme.nome << endl;
		saida << filme.ano_de_lancamento << endl;
		saida << filme.usuario_que_criou << endl;
		saida << filme.nota_media << endl;
		saida << "<notas>\n";
		
		for (auto& nota : filme.notas) {
			saida << nota.first << endl;
			saida << nota.second << endl;
		}

		saida << "</notas>\n";
		saida << "</filme>\n\n";
	}

	saida << "</filmes>\n\n";

	saida.close();
}

unsigned long long int posicao_do_filme(vector<Filme>& filmesf, string nomef, string usuariof) {
	unsigned long long int contador = 0;
	bool encontrou = false;

	for (auto& iterador : filmesf) {
		if (iterador.nome == nomef && iterador.usuario_que_criou == usuariof) {
			encontrou = true;
			contador = contador + 1;
			break;
		}
		contador = contador + 1;
	}

	if (encontrou == true) {
		return contador;
	}
	else {
		cout << "\nnao foi possivel remover " << nomef << ",\nverifique se ele esta no catalogo\ne se foi tu quem o postou.\n";
		return 0;
	}
}
