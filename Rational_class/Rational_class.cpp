#include <iostream>
#include <cmath>

using namespace std;

class Rational {
private:
    int numerator_;
    int denominator_;

    void Reduce() {
        int a = abs(numerator_);
        int b = abs(denominator_);

        while (a != 0 && b != 0) {
            a %= b;
            swap(a, b);
        }
        int gcd = a + b;
        numerator_ /= gcd;
        denominator_ /= gcd;
    }

public:
    Rational() : numerator_(0), denominator_(1) {};

    explicit Rational(int num) : numerator_(num), denominator_(1) {};

    explicit Rational(int p, int q) {
        numerator_ = (q > 0) ? p : -p;
        denominator_ = (q > 0) ? q : -q;

        if (q == 0) {
            cerr << "q is 0";
        }

        Reduce();
    }

    int GetNum() {
        return numerator_;
    }

    int GetDen() {
        return denominator_;
    }

    Rational Sum(Rational& rt) {
        int p = numerator_ * rt.GetDen() + rt.GetNum() * denominator_;
        int q = denominator_ * rt.GetDen();

        Rational sum(p, q);
        return sum;
    }

    Rational Sub(Rational& rt) {
        int p = numerator_ * rt.GetDen() - rt.GetNum() * denominator_;
        int q = denominator_ * rt.GetDen();

        Rational sub(p, q);
        return sub;
    }

    void Scan() {
        cin >> numerator_ >> denominator_;
        if (denominator_ == 0) {
            cerr << "Denominator is zero";
        }
        Reduce();
    }

    void print() const {
        if (denominator_ == 1) {
            cout << numerator_;
        }
        else {
            cout << numerator_ << "/" << denominator_;
        }
    }

    bool CompareLess(Rational& rt) {
        int p1 = this->numerator_ * rt.GetDen();
        int p2 = this->denominator_ * rt.GetNum();
        return (p1 < p2);
    }

    Rational Mult(Rational& rt) {
        Rational mult(this->numerator_ * rt.GetNum(), this->denominator_ * rt.GetDen());
        return mult;
    }

    Rational Div(Rational& rt) {
        Rational div(this->numerator_ * rt.GetDen(), this->denominator_ * rt.GetNum());
        return div;
    }

};

Rational operator + (Rational& rt1, Rational& rt2) {
    int p = rt1.GetNum() * rt2.GetDen() + rt2.GetNum() * rt1.GetDen();
    int q = rt1.GetDen() * rt2.GetDen();

    Rational sum(p, q);
    return sum;
}

Rational operator - (Rational& rt1, Rational& rt2) {
    int p = rt1.GetNum() * rt2.GetDen() - rt2.GetNum() * rt1.GetDen();
    int q = rt1.GetDen() * rt2.GetDen();

    Rational sub(p, q);
    return sub;
}

Rational operator * (Rational& rt1, Rational& rt2) {
    int p = rt1.GetNum() * rt2.GetNum();
    int q = rt1.GetDen() * rt2.GetDen();

    Rational mult(p, q);
    return mult;
}

Rational operator / (Rational& rt1, Rational& rt2) {
    int p = rt1.GetNum() * rt2.GetDen();
    int q = rt1.GetDen() * rt2.GetNum();

    Rational div(p, q);
    return div;
}

bool operator< (Rational& rt1, Rational& rt2) {
    int p1 = rt1.GetNum() * rt2.GetDen();
    int p2 = rt1.GetDen() * rt2.GetNum();
    return (p1 < p2);
}

ostream& operator << (ostream& out, Rational& rat) {
    if (rat.GetDen() == 1) {
        out << rat.GetNum();
    }
    else {
        out << rat.GetNum() << "/" << rat.GetDen();
    }
    return out;
}

int main() {
    /*Rational a(5, 4);
    Rational b(3, 2);

    Rational ss = a.Div(b);

    ss.print();

    Rational ss = a.Sum(b);
    
    ss.print();
    
    cout << endl;

    ss = a.Mult(b);

    ss.print();

    bool is_comp = a.CompareLess(b);*/

    Rational a(8, 12);
    Rational b(6, 4);

    Rational s1 = a + b;
    cout << s1 << endl;

    Rational s2= a - b;
    cout << s2 << endl;

    Rational s3 = a * b;
    cout << s3 << endl;

    Rational s4 = a / b;
    cout << s4 << endl;

    bool s5 = a < b;
    cout << s5 << endl;

    return 0;
}
