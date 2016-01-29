
class Complex {
private:
  float *num;

public:

  Complex(float real, float imag) {
    num = new float[2];
    num[0] = real;
    num[1] = imag;
  }

  void operator= (Complex &other) {
    this.num[0] = other.num[0];
    this.num[1] = other.num[1];
  }

  Complex operator+ (Complex &other) {
    Complex result(-1, -1);
    result.num[0] = this.num[0] + other.num[0];
    result.num[1] = this.num[1] + other.num[1];
    return result;
  }

  bool operator== (Complex &other) {
    return (this.num[0] == other.num[0] &&
            this.num[1] == other.num[1]);
  }

  ~Complex() {
    delete[] num;
  }
};
