/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-13 12:50:27 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-16 23:47:13
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>

const int maxn = 30005;
struct ubigint {
    int s[maxn], len;
    //一些基础的东西
    ubigint() { memset(s, 0, sizeof(s)); }
    ubigint(int num) { *this = num; }
    ubigint(char *num) { *this = num; }
    
    ubigint operator = (int num) {
        char c[maxn];
        sprintf(c, "%d", num);
        *this = c;
        return *this;
    }

    ubigint operator = (const char *num) {
        len = strlen(num);
        for(int i = 0; i < len; i++)
            s[i] = num[len - i - 1] - '0';
        return *this;
    }

    int midsearch(const ubigint &b, const ubigint &m) const {
        int L = 0, R = 9, mid;
        while(1) {
            mid = (L + R) >> 1;
            if(b * mid <= m) {
                if(b * (mid + 1) > m) return mid; 
                else L = mid;
            }
            else R = mid;
        }    
    }

    std :: string to_str() {
        std :: string res = "";
        for(int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
        return res;
    }

    void clear_zero() {
        while(len > 1 && !s[len - 1]) len--;
    }

    //关系运算符
    bool operator < (const ubigint &b) const {
        if(len != b.len) return len < b.len;
        for(int i = len - 1; i >= 0; i--)
            if(s[i] != b.s[i])
                return s[i] < b.s[i];
        return false;
    }
    bool operator > (const ubigint &b) const {return b < *this; }
    bool operator <= (const ubigint &b) const {return !(b < *this);}
    bool operator >= (const ubigint &b) const {return !(*this < b);}
    bool operator == (const ubigint &b) const {return !(b < *this) && !(b > *this);}
    bool operator != (const ubigint &b) const {return b < *this || *this < b;}

    ubigint operator + (const ubigint &b) const {
        ubigint res;
        res.len = 0;
        for(int i = 0, x = 0; x || i < len || i < b.len; i++, x /= 10) {
            if(i < len) x += s[i];
            if(i < b.len) x += b.s[i];
            res.s[res.len++] = x % 10;
        }
        return res;
    }

    ubigint operator - (const ubigint &b) const {
        assert(*this < b);
        ubigint res;
        res.len = 0;
        int x;
        for(int i = 0, g = 0; i < len; i++) {
            x = s[i] - g;
            if(i < b.len) x -= b.s[i];
            if(x >= 0) g = 0;
            else {
                x += 10;
                g = 1;
            }
            res.s[res.len++] = x;
        }
        res.clear_zero();
        return res;
    }

    ubigint operator * (const ubigint &b) const {
        ubigint res;
        res.len = len + b.len;
        for(int i = 0; i < len; i++)
            for(int j = 0; j < b.len; j++)
                res.s[i + j] += s[i] * b.s[j];
        for(int i = 0; i < res.len - 1; i++) {
            res.s[i + 1] += res.s[i] / 10;
            res.s[i] %= 10;
        }
        res.clear_zero();
        return res;
    }

    ubigint operator / (const ubigint &b) const {
        assert(b > 0);
        ubigint res = *this,m;
        for(int i = len - 1; i >= 0; i--) {
            m = m * 10 + s[i];
            res.s[i] = midsearch(b, m);
            m = m - b * res.s[i];
        }
        res.clear_zero();
        return res;
    }

    ubigint operator % (const ubigint &b) const {
        assert(b > 0);
        ubigint res = *this;
        ubigint m;
        for(int i = len - 1; i >= 0; i--) {
            m = m * 10 + s[i];
            res.s[i] = midsearch(b,m);
            m = m - b * res.s[i];
        }
        m.clear_zero();
        return m;
    }

    ubigint& operator += (const ubigint &b) {*this = *this + b; return *this;}
    ubigint& operator -= (const ubigint &b) {*this = *this - b; return *this;}
    ubigint& operator *= (const ubigint &b) {*this = *this * b; return *this;}
    ubigint& operator /= (const ubigint &b) {*this = *this / b; return *this;}
    ubigint& operator %= (const ubigint &b) {*this = *this % b; return *this;}
};

std :: istream& operator >>(std :: istream &in, ubigint &x) {
    std :: string s;
    in >> s;
    x = s.c_str();
    return in;
}

std :: ostream& operator <<(std :: ostream &out,ubigint x) {
    out << x.to_str();
    return out;
}

int main() {
    ubigint a,b;
    std :: cin >> a >> b;
    if(a < b) std :: cout << "-" << b - a << std :: endl;
    else std :: cout << a - b<< std :: endl;
    return 0;
}