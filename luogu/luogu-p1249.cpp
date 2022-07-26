/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-02 00:58:54 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-02 01:10:27
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

	ubigint& operator = (ull num) {
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

    bool operator < (const ubigint& b) const {
        if(s.size() != b.s.size()) return s.size() < b.s.size();
        for(int i = s.size() - 1; i >= 0; i--)
            if(s[i] != b.s[i])
                return s[i] < b.s[i];
        return false;
    }
    bool operator > (const ubigint& b) const {return b < *this; }
    bool operator <= (const ubigint& b) const {return !(b < *this);}
    bool operator >= (const ubigint& b) const {return !(*this < b);}
    bool operator == (const ubigint& b) const {return !(b < *this) && !(b > *this);}
    bool operator != (const ubigint& b) const {return b < *this || *this < b;}

    ubigint operator + (const ubigint& b) const {
        ubigint res;
        res.s.clear();
        for(int i = 0, x = 0; x || i < s.size() || i < b.s.size(); i++, x /= base) {
            if(i < s.size()) x += s[i];
            if(i < b.s.size()) x += b.s[i];
            res.s.push_back(x % base);
        }
        return res.clear_zero();
    }

	ubigint operator - (const ubigint& b) const {
		assert(*this >= b);
		ubigint res;
		res.s.clear();
		for(int i = 0, last = 0;last || i < s.size() || i < b.s.size();i++) {
			int x = s[i] + last;
			if(i < b.s.size()) x -= b.s[i];
			if(x < 0) {
				last = -1;
				x += base;
			}else last = 0;
			res.s.push_back(x);
		}
		return res.clear_zero();
	}

	ubigint operator * (const ubigint& b) const {
		std :: vector<ull> tmp(s.size() + b.s.size(),0);
		ubigint res;
		res.s.clear();
		for(int i = 0; i < s.size(); i++)
			for(int j = 0; j < b.s.size(); j++)
				tmp[i + j] += ull(s[i]) * b.s[j];
		
        ull last = 0;
		for(int i = 0; last || i < tmp.size(); i++) {
			ull x = tmp[i] + last;
			res.s.push_back(x % base);
			last = x / base;
		}
		return res.clear_zero();
	}

	int midsearch(const ubigint& b, const ubigint& m) const {
		int l = 0, r = base - 1;
		while(1) {
			int mid = l + r >> 1;
			if(b * mid <= m && b * (mid + 1) > m) return mid;
			if(b * mid <= m) l = mid;
			else r = mid;
		}
	}

	ubigint operator / (const ubigint& b) const {
		assert(b > 0);
		ubigint res = *this, mod;
		for(int i = s.size() - 1; i >= 0; i--) {
			mod = mod * base + s[i];
			res.s[i] = midsearch(b, mod);
			mod -= b * res.s[i];
		}
		return res.clear_zero();
	}

	ubigint operator % (const ubigint& b) const {
		assert(b > 0);
		ubigint res = *this, mod;
		for(int i = s.size() - 1; i >= 0; i--) {
			mod = mod * base + s[i];
			res.s[i] = midsearch(b, mod);
			mod -= b * res.s[i];
		}
		return mod.clear_zero();
	}

	ubigint& operator += (const ubigint& b) {*this = *this + b; return *this;}
	ubigint& operator -= (const ubigint& b) {*this = *this - b; return *this;}
	ubigint& operator *= (const ubigint& b) {*this = *this * b; return *this;}
	ubigint& operator /= (const ubigint& b) {*this = *this / b; return *this;}
	ubigint& operator %= (const ubigint& b) {*this = *this % b; return *this;}
	

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
		}
		return out;
	}
};

int main() {
    int n;
    std :: cin >> n;
	int sum = 0, to;
    if(n <= 4) {
        std :: cout << n << std :: endl << n << std :: endl;
        return 0;
    }
    for(int i = 2; sum <= n; i++) {
        sum += i;
        to = i;
    }
    ubigint ans = 1;
    for(int i = 2; i <= to; i++) {
		if(sum - n == 1)  {
			if(i == 2) continue;
			if(i == to) {
				std :: cout << i + 1 << ' ';
				ans *= (i + 1);
				break;
			}
		}
		if(i != sum - n) {
            std :: cout << i << ' ';
            ans *= i;
        }
    }
    std :: cout << std :: endl << ans << std :: endl;
    return 0;
}