/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-13 12:50:27 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-13 13:50:01
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>

const int maxn = 4005;
struct bigint {
    int s[maxn], len;
    //一些基础的东西
    bigint() { memset(s, 0, sizeof(s)); }
    bigint(int num) { *this = num; }
    bigint(char *num) { *this = num; }
    
    bigint operator = (int num) {
        char c[maxn];
        sprintf(c, "%d", num);
        *this = c;
        return *this;
    }

    bigint operator = (const char *num) {
        len = strlen(num);
        for(int i = 0; i < len; i++)
            s[i] = num[len - i - 1] - '0';
        return *this;
    }

    int midsearch(const bigint &b, const bigint &m) const {
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

    //逻辑运算符
    bool operator < (const bigint &b) const {
        if(len != b.len) return len < b.len;
        for(int i = len - 1; i >= 0; i--)
            if(s[i] != b.s[i])
                return s[i] < b.s[i];
        return false;
    }
    bool operator > (const bigint &b) const {return b < *this; }
    bool operator <= (const bigint &b) const {return !(b < *this);}
    bool operator >= (const bigint &b) const {return !(*this < b);}
    bool operator == (const bigint &b) const {return !(b < *this) && !(b > *this);}
    bool operator != (const bigint &b) const {return b < *this || *this < b;}

    bigint operator + (const bigint &b) const {
        bigint res;
        res.len = 0;
        for(int i = 0, x = 0; x || i < len || i < b.len; i++, x /= 10) {
            if(i < len) x += s[i];
            if(i < b.len) x += b.s[i];
            res.s[res.len++] = x % 10;
        }
        return res;
    }

    bigint operator - (const bigint &b) const {
        bigint res;
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

    bigint operator * (const bigint &b) const {
        bigint res;
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

    //高精度除法好像并不会考到，但还事写一下吧qaq？
    bigint operator / (const bigint &b) const {
        assert(b > 0);
        bigint res = *this,m;
        for(int i = len - 1; i >= 0; i--) {
            m = m * 10 + s[i];
            res.s[i] = midsearch(b, m);
            m = m - b * res.s[i];
        }
        res.clear_zero();
        return res;
    }

    bigint operator % (const bigint &b) const {
        assert(b > 0);
        bigint res = *this;
        bigint m;
        for(int i = len - 1; i >= 0; i--) {
            m = m * 10 + s[i];
            res.s[i] = midsearch(b,m);
            m = m - b * res.s[i];
        }
        m.clear_zero();
        return m;
    }

    bigint& operator += (const bigint &b) {*this = *this + b; return *this;}
    bigint& operator -= (const bigint &b) {*this = *this - b; return *this;}
    bigint& operator *= (const bigint &b) {*this = *this * b; return *this;}
    bigint& operator /= (const bigint &b) {*this = *this / b; return *this;}
    bigint& operator %= (const bigint &b) {*this = *this % b; return *this;}
};

std :: istream& operator >>(std :: istream &in, bigint &x) {
    std :: string s;
    in >> s;
    x = s.c_str();
    return in;
}

std :: ostream& operator <<(std :: ostream &out,bigint x) {
    out << x.to_str();
    return out;
}

int main() {
    bigint a,b;
    std :: cin >> a >> b;
    std :: cout << a * b << std :: endl;
    return 0;
}