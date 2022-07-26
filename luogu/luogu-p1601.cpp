/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-18 08:32:46 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-18 16:09:02
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>
#include <vector>

int max(int a,int b) {
	return a > b ? a : b;
}

struct ubigint {
	typedef long long ll;
	typedef unsigned long long ull;

	static const int base = 100000000;
	static const int width = 8;
	
	std :: vector<int> s;

	ubigint& clear_zero() {
		while(!s.back() && s.size() > 1) s.pop_back();
		return *this;
	}
	
	ubigint(ull num = 0) {*this = num;}
	ubigint(std :: string str) {*this = str;}

	ubigint& operator = (ll num) {
		s.clear();
		do {
			s.push_back(num % base);
			num /= base;
		}while(num);
		return *this;
	}

	ubigint& operator = (const std :: string& str) {
		s.clear();
		int x;
		int len = (str.length() - 1) / width + 1;
		for(int i = 0; i < len; i++) {
			int endidx = str.length() - i * width;
			int startidx = max(0, endidx - width);
			int x;
			sscanf(str.substr(startidx, endidx - startidx).c_str(), "%d", &x);
			s.push_back(x);
		}
		return (*this).clear_zero();
	}

    bool operator < (const ubigint &b) const {
        if(s.size() != b.s.size()) return s.size() < b.s.size();
        for(int i = s.size() - 1; i >= 0; i--)
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
        res.s.clear();
        for(int i = 0, x = 0; x || i < s.size() || i < b.s.size(); i++, x /= base) {
            if(i < s.size()) x += s[i];
            if(i < b.s.size()) x += b.s[i];
            res.s.push_back(x % base);
        }
        return res;
    }

	friend std :: istream& operator >> (std :: istream& in, ubigint& x) {
		std :: string str;
		if(!(in >> str)) return in;
		x = str;
		return in;
	}

	friend std :: ostream& operator << (std :: ostream& out, ubigint x) {
		out << x.s.back();
		for(int i = x.s.size() - 2; i >= 0; i--) {
			char buf[20];
			sprintf(buf, "%08d", x.s[i]);
			for(int j = 0; j < strlen(buf); j++)
				out << buf[j];
		}//ilIL
		return out;
	}
};

int main() {
	ubigint a,b;
	std :: cin >> a >> b;
	std :: cout << a + b << std :: endl;
	return 0;
}