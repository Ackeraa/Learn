namespace demo {
    class Complex {
        public:
            Complex(double real, double imag) {
                this->real = real;
                this->imag = imag;
            };
            ~Complex(){};

            double get_real() { return real; };
            double get_imag() { return imag; };

        private:
            double real, imag;
    };
};

