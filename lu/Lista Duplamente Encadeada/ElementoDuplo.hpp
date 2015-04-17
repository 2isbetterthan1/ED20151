/* Copyright [2015] <marcelinol>
 * ElementoDuplo.hpp
 */

template <typename T>

class ElementoDuplo {
 private:
	T *info;
	ElementoDuplo<T>* _previous;
	ElementoDuplo<T>* _next;

 public:
	ElementoDuplo(
	const T& info, ElementoDuplo<T>* previous, ElementoDuplo<T>* next)
	: info(new T(info)), _previous(previous), _next(next) {}

	~ElementoDuplo() {
		delete info;
	}

	T getInfo() const {
		return *info;
	}

	ElementoDuplo<T>* getPrevious() const {
		return _previous;
	}

	ElementoDuplo<T>* getNext() {
		return _next;
	}

	void setNext(ElementoDuplo<T>* next) {
		_next = next;
	}

	void setPrevious(ElementoDuplo<T>* previous) {
		_previous = previous;
	}

	void setInfo(T *newInfo) {
		info = *newInfo;
	}
};
