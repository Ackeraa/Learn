namespace mylib {
    template<typename T>
    class Complex {
        public:
            typedef T value_type;

            Complex() : real(0), imag(0) {}
            Complex(double real, double imag)
                : real{real}, imag{imag} {}
            Complex(const Complex& c)
                : real{c.real}, imag{c.imag} {}
            Complex& operator=(const Complex& c) {
                real = c.real;
                imag = c.imag;
                return *this;
            }
            ~Complex(){};

            Complex operator+(const Complex& c) const {
                return Complex(real + c.real, imag + c.imag);
            }

            value_type get_real() const { return real; }
            value_type get_imag() const { return imag; }

        private:
            value_type real, imag;
    };
}
