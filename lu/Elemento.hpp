/* Copyright [2015] <marcelinol>
 * Lista.hpp
 */

#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

template <typename T>

class Elemento {
 private:
	T *info;
	Elemento<T>* _next;

 public:
	Elemento(const T& info, Elemento<T>* next) : info(new T(info)), _next(next) {}

	~Elemento() {
		delete info;
	}

	Elemento<T>* getProximo() const {
		return _next;
	}

	T getInfo() const {
		return *info;
	}

	Elemento<T>* getNext() {
		return _next;
	}

	void setNext(Elemento<T>* next) {
		_next = next;
	}

	void setInfo(T *newInfo) {
		info = *newInfo;
	}
};

#endif
