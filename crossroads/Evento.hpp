abstract Evento() {
private:
  double tempo;

public:
  virtual double getTime() = 0;
  virtual ~Evento() { }
}