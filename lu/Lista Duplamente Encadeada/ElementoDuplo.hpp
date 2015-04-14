/* Copyright [2015] <marcelinol>
 * ElementoDuplo.hpp
 */

template <typename T>

class Elemento {
 private:
	T *info;
  Elemento<T>* _previous
	Elemento<T>* _next;

 public:
	Elemento(const T& info, Elemento<T>* next, Elemento<T>* previous) : info(new T(info)), _next(next), _previous(previous) {}

	~Elemento() {
		delete info;
	}

	Elemento<T>* getProximo() const {
		return _next;
	}

  Elemento<T>* getPrevious() const {
    return _previous;
  }

	T getInfo() const {
		return *info;
	}
  //
  // Elemento<T>* getNext() {
  //   return _next;
  // }

  void setNext(Elemento<T>* next) {
    _next = next;
  }

  void setPrevious(Elemento<T>* previous) {
    _previous = previous;
  }

  void setInfo(T *newInfo) {
    info = *newInfo;
  }
};

#endif
