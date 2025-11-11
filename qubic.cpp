#include <iostream>
#include <complex>
#include <functional>
#include <cassert>

using namespace std;
using Complex = complex<double>;
using Solution = function<void(double, double, double, double)>;

        void print_roots(initializer_list<Complex> roots) {
            cout << "\nSolutions:" << endl;
            int i = 1;
            for (auto r : roots) 
                cout << "Root" << i++ << ": " << r << endl;
            }

        void solve_linear(double, double b, double c, double d) {
            print_roots({Complex(d) / (-Complex(c))});
        }

        void solve_quadratic(double, double b, double c, double d) {
            Complex A(b), B(c), C(d);
            Complex D = sqrt(B * B - 4.0 * A * C);
            print_roots({
                (-B + D) / (2.0 * A),
                (-B - D) / (2.0 * A)
                });
        }

        void solve_cubic(double a, double b, double c, double d) {
            Complex A(b / a), B(c / a), C(d / a);
            Complex p = (3.0 * B - A * A) / 3.0;
            Complex q = (2.0 * pow(A, 3.0) - 9.0 * A * B + 27.0 * C) / 27.0;
            Complex Δ = pow(q / 2.0, 2.0) + pow(p / 3.0, 3.0);

            Complex u = pow(-q / 2.0 + sqrt(Δ), 1.0 / 3.0);
            Complex v = pow(-q / 2.0 - sqrt(Δ), 1.0 / 3.0);

        if (abs(u) < 1e-15) u = 1.0 / v;
        if (abs(v) < 1e-15) v = 1.0 / u;

        Complex t = u + v, A3 = A / 3.0;
        Complex ω = polar(1.0, 2.0 * M_PI / 3.0);

            print_roots({
                t - A3,
                u * ω + v / ω - A3,
                u * pow(ω, 2) + v / pow(ω, 2) - A3
            });

    
        if (a == 1 && b == -6 && c == 11 && d == -6)
            assert(abs((t - A3).real() - 3) < 1e-12);
        }

int select(double a, double b, double c, double) {
        return (a != 0) ? 2 : (b != 0) ? 1 : 0;
}

Solution Methods[] = {solve_linear, solve_quadratic, solve_cubic};

int main() {
    double a, b, c, d;
    cout << "Equation form: ax^3 + bx^2 + cx + d = 0\n"
        << "Example: a=1, b=-6, c=11, d=-6 → roots (1, 2, 3)\n"
        << "Enter a, b, c, d: ";
    cin >> a >> b >> c >> d;

    Methods[select(a, b, c, d)](a, b, c, d);
        return 0;
}

