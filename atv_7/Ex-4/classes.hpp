class Base {

  int i;

protected:
  int read() const { return i; }
  void set(int ii) { i = ii; }

public:
  Base(int ii = 0) : i(ii) {}
  int value(int m) const { return m * i; }
};

class Derived : protected Base {

  int j;

public:
  Derived(int jj = 0) : j(jj) {}
  void change(int x) { set(x); }
};

class Derived2 : public Derived {

  int k;

public:
  Derived2(int kk = 0) : k(kk) {}
};