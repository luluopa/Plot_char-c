#include <iostream>
#include <fstream>

class Matriz_string{
protected:
	char** Matriz;
	int qtd_line, qtd_col;
public:
	Matriz_string(int qtd_line, int qtd_col){
		Matriz = new char*[qtd_line];
		for(int i=0;i<qtd_line;i++){
			*(Matriz+i) = new char[qtd_col];
		}
		this->qtd_line = qtd_line;
		this->qtd_col = qtd_col;
	}
	~Matriz_string(){
		delete[] Matriz;
	}
	int get_line(){
		return this->qtd_line;
	}
	int get_col(){
		return this->qtd_col;
	}
	void Set_newchar(int line, int col, char c){
		*(*(Matriz+line)+col) = c;
	}
	char Get_char(int line, int col){
		return *(*(Matriz+line)+col);
	}
	const char* get_allline(int line){
		return *(Matriz+line);
	}
};

int find_qtd_col(std::ifstream* pointer){
	int qtd_coluna=0;
	pointer->clear();
	pointer->seekg(0, std::ios::beg);
	char test;
	while(pointer->get(test)){
		if(test == '\n')
			break;
		qtd_coluna++;
	}
	return qtd_coluna;
}

int find_qtd_line(std::ifstream* pointer, int qtd_col){
    int qtd_caractere=0;
    pointer->clear();
	pointer->seekg(0, std::ios::beg);
	while(pointer->good()){
		pointer->get();
		qtd_caractere++;
	}
	return (qtd_caractere/qtd_col);
}

void copy_string_txt(Matriz_string* pointer, std::ifstream* arquivo){
	arquivo->clear();
	arquivo->seekg(0, std::ios::beg);
	int i=0,j=0;
	char test;
	while(arquivo->good()){
		arquivo->get(test);
		if(test == '\n'){
			i++;
			j=0;	
		}
		else
	    	pointer->Set_newchar(i,j++,test);
	}
}

void Transformation(Matriz_string* string_new, Matriz_string* string_old){
	int check_control=0, auxiliar=0;
	for(int i=0;i<string_new->get_line();i++){
		for(int j=0;j<string_new->get_col();j++){
			if(j == 0 || j == string_new->get_col()-1){
				string_new->Set_newchar(i,j,'{');
				if(j == string_new->get_col()-1)
					string_new->Set_newchar(i,j,'}');
			}
			else{
				if(check_control%2 != 0){
					string_new->Set_newchar(i,j,',');
				}
				else{
					string_new->Set_newchar(i,j,string_old->Get_char(i,auxiliar++));
				}
				check_control++;
			}
		}
		auxiliar = 0;
		check_control = 0;
	}
}

int main(){
	std::ifstream arquivo("bank.txt");
	
	int qtd_col = find_qtd_col(&arquivo);
	int qtd_line = find_qtd_line(&arquivo, qtd_col);
	
	Matriz_string string_new(qtd_line, qtd_col);
	copy_string_txt(&string_new, &arquivo);

	int new_col = qtd_col + 2 + qtd_col-1;
	
	Matriz_string string_reloaded(qtd_line, new_col);
	Transformation(&string_reloaded, &string_new);

    std::ofstream new_arquivo("novo_bank.txt");
    for(int i=0;i<string_reloaded.get_line();i++){
		new_arquivo << (string_reloaded.get_allline(i));
		new_arquivo << "\n";
	}
	return 0;
}


