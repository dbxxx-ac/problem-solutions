/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-19 23:07:41  
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-19 01:07:24
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <string>

int max(int a,int b) {
    return a > b ? a : b;
}

static const int base = 1000000000;
static const int width = 9;
    
struct ubigint {
    typedef long long ull;

    ull s[8005] = {0};
    int len = 1;

    ubigint(){}

    ubigint(const ubigint& x) {
        for(int i = 0; i < x.len; i++)
            this -> s[i] = x.s[i];
        this -> len = x.len;
    }
    
    ubigint(const int& x) {
        int tmp = x;
        this -> len = 0;
        do{
            this -> s[this -> len++] = tmp % base;
            tmp /= base;
        }while(tmp);
    }

    ubigint operator = (const std :: string& str) {
        std :: string tmp = str;
        while(tmp.length() > width) {
            this -> s[this -> len - 1] = atoi(tmp.substr(tmp.length() - width).c_str());
            tmp.erase(tmp.length() - width);
            this -> len++;
        }
        this -> s[this -> len - 1] = atoi(tmp.c_str());
        return *this;
    }

    void clear_zero() {
        while(this -> len > 1 && !(this -> s[this -> len - 1])) this -> len--;
    }

    ubigint operator = (const ubigint& x) {
        this -> len = x.len;
        for(register int i = 0; i < this -> len; i++)
            this -> s[i] = x.s[i];
        return *this;
    }

    bool operator < (const ubigint& b) const {
        if(this -> len != b.len) return this -> len < b.len;
        for(register int i = this -> len - 1; i >= 0; i--)
            if(this -> s[i] != b.s[i])
                return this -> s[i] < b.s[i];
        return false;
    }

    bool operator > (const ubigint& b) const {
        return b < *this;
    }

    bool operator <= (const ubigint& b) const {
        return !(b < *this);
    }

    bool operator >= (const ubigint& b) const {
        return !(*this < b);
    }

    bool operator != (const ubigint& b) const {
        return *this < b || b < *this;
    }

    bool operator == (const ubigint& b) const {
        return !(b < *this) && !(*this < b);
    }

    ubigint operator + (const ubigint& b) const {
        ubigint res;
        res.len = max(this -> len, b.len);
        for(register int i = 0, last = 0; i < res.len; i++) {
            res.s[i] = this -> s[i] + b.s[i] + last;
            last = res.s[i] / base;
            res.s[i] %= base;
            if(i == res.len - 1 && last) res.len++;
        }
        res.clear_zero();
        return res;
    }

    ubigint operator - (const ubigint& b) const {
        assert(*this >= b);
        ubigint res = *this;
        for(register int i = 0, last = 0; i < this -> len; i++) {
            res.s[i] -= b.s[i] + last;
            if(res.s[i] < 0) {
                res.s[i] += base;
                last = 1;
            }else last = 0;
        }
        res.clear_zero();
        return res;
    }

    ubigint operator * (const ubigint& b) const {
        if(*this == 0 || b == 0) return ubigint(0);
        //if(*this == 1) return b;
        //if(b == 1) return *this;
        ubigint res;
        res.len = this -> len + b.len + 1;
        for(register int i = 0; i < this -> len; i++) {
            for(register int j = 0; j < b.len; j++) {
                res.s[i + j] += this -> s[i] * b.s[j];
                res.s[i + j + 1] += res.s[i + j] / base;
                res.s[i + j] %= base;
            }
        }
        res.clear_zero();
        return res;
    }

    ubigint operator / (const ubigint& b) const {
        if(b > *this) return 0;
        //if(b == *this) return 1;
        ubigint res = 0, div = b, mod = *this;
        while(div * ubigint(base) <= *this) div *= ubigint(base);
        for(;;) {
            int l = 1, r = base, mid;
            if(mod >= div) {
                while(r > l + 1) {
                    int mid = l + r >> 1;
                    if(div * ubigint(mid) > mod) r = mid;
                    else l = mid;
                }
                mod -= div * ubigint(l);
                res.s[res.len - 1] += l;
            }

            if(div == b) break;
            res.len++;
            for(register int i = 1; i < div.len; i++)
                div.s[i - 1] = div.s[i];
            div.s[div.len - 1] = 0;
            div.len--;
        }
        std :: reverse(res.s, res.s + res.len);
        res.clear_zero();
        return res;
    }

    ubigint operator % (const ubigint& b) const {
        return *this - (*this / b * b);
    }

    ubigint operator += (const ubigint& b) {*this = *this + b; return *this;}
    ubigint operator -= (const ubigint& b) {*this = *this - b; return *this;}
    ubigint operator *= (const ubigint& b) {*this = *this * b; return *this;}
    ubigint operator /= (const ubigint& b) {*this = *this / b; return *this;}
    ubigint operator %= (const ubigint& b) {*this = *this % b; return *this;}
    
    friend std :: istream& operator >> (std :: istream& in, ubigint& b) {
        std :: string str;
        in >> str;
        b = str;
        return in;
    }

    friend std :: ostream& operator << (std :: ostream& out, ubigint b) {
        out << b.s[b.len - 1];
        for(register int i = b.len - 2; i >= 0; i--) {
            int div = base / 10;
            while(b.s[i] < div) {
                std :: cout << 0;
                div /= 10;
            }
            if(b.s[i]) out << b.s[i];
        }
        return out;
    }
};

int main() {
    ubigint a,b;
    std :: cin >> a >> b;
    std :: cout << a + b << std :: endl;
    if(a >= b) std :: cout << a - b << std :: endl;
    else std :: cout << '-' << b - a << std :: endl;
    std :: cout << a * b << std :: endl;
    std :: cout << a / b << std :: endl;
    std :: cout << a % b << std :: endl;
    return 0;    
}