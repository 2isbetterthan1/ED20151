/* Copyright [2015] <LeoSL>
 * Lista.hpp
 */
#include "Elemento.hpp"

template<typename T>
class ListaEnc {
 private:
		Elemento<T>* head;
		int size = -1;

	public:
		ListaEnc() {
		  size = 0;
		  Elemento<T>* cabeca = new Elemento();
		  if(cabeca != NULL) {
		  	head = cabeca;
		  } else {
		  	throw('Não foi possível criar a lista');
		  }
		}

		~ListaEnc() {
			destroiLista();
		}

		// inicio
		void adicionaNoInicio(const T& dado) {
			Elemento<T>* antigoPrimeiro = head.getProximo();

			T elemento = new Elemento();
			elemento.setInfo(dado);
			elemento.setProximo(antigoPrimeiro);

			head = *elemento;
			size++;
		}

		T retiraDoInicio() {
			Elemento<T>* antigoPrimeiro = head.getProximo();
			head = *antigoPrimeiro.getProximo();
			size--;
			return antigoPrimeiro;
		}

		void eliminaDoInicio() {
			Elemento<T>* antigoPrimeiro = head.getProximo();
			head = *antigoPrimeiro.getProximo();
			antigoPrimeiro.~Elemento();
			size--;
		}

		// posicao
		void adicionaNaPosicao(const T& dado, int pos) {
			Elemento<T>* novoDado = new Elemento();
			if(novoDado != NULL && (pos > -1 && pos <= size)) {
				Elemento<T>* proximo = acheElementoNaPos(pos);
				novoDado.setInfo(dado);
				proximo.setProximo(novoDado);
				novoDado.setProximo(proximo.getProximo());
				size++;
			} else {
				throw("Lista Cheia ou Posição Inválida");
			}
		}

		T acheElementoNaPos(int pos) {
			excecaoListaVazia();
			Elemento<T>* proximo = head.getProximo();
			int controller = 0;
			while (controller >= 0 && controller < pos) {
				proximo = proximo.getProximo();
				controller++;
			}
			return proximo;
		}

		int posicao(const T& dado) const {
			excecaoListaVazia();
			int position = -1;
			
			if (contem(dado)) {
				while(proximo.getInfo() != dado && position < size) {
					position++;
					Elemento<T>* proximo = acheElementoNaPos(position);
				}
				return position;
			} else {
				throw('Dado Inválido');
			}
		}

		T* posicaoMem(const T& dado) const {
			excecaoListaVazia();
			int position = -1;

			if (contem(dado)) {
				while(proximo.getInfo() != dado && position < size) {
					position++;
					Elemento<T>* proximo = acheElementoNaPos(position);
				}
				return *proximo;
			} else {
				throw('Dado Inválido');
			}
		}

		bool contem(const T& dado) {
			excecaoListaVazia();
			int position = -1;
			
			while(position < size) {
				position++;
				Elemento<T>* proximo = acheElementoNaPos(position);
				if (proximo.getInfo() == dado) { 
					return true;
				}
			}
			return false;
		}

		T retiraDaPosicao(int pos) {

		}

		//fim
		void adiciona(const T& dado) {

		}

		T retira() {

		}

		// especifico
		T retiraEspecifico(const T& dado) {

		}

		void adicionaEmOrdem(const T& data) {

		}

		bool listaVazia() const {
			return head.getProximo() == NULL;
		}

		void excecaoListaVazia() {
	    if (listaVazia()) {
	      throw("Lista Vazia!");
	    }
	  }
		bool igual(T dado1, T dado2) {

		}

		bool maior(T dado1, T dado2) {

		}

		bool menor(T dado1, T dado2) {

		}

		void destroiLista() {

		}
};