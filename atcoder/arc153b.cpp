#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = false;
    for (; isdigit(ch); ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    return f ? x : (~(x - 1));
}

const int maxn = (int)5e5 + 5;
const int inf = 100000089;
struct SPLAY {
    struct Splay_tree{
        int f,sub_size,cnt,value,tag;
        int son[2];
    }s[maxn];
    int original[maxn],root,wz;
    inline bool which(int x){
        return x==s[s[x].f].son[1];
    }
    inline void update(int x){
        if(x){
        s[x].sub_size=s[x].cnt;
        if(s[x].son[0])s[x].sub_size+=s[s[x].son[0]].sub_size;
        if(s[x].son[1])s[x].sub_size+=s[s[x].son[1]].sub_size;
        }
    }
    inline void pushdown(int x){
        if(x&&s[x].tag){
            s[s[x].son[1]].tag^=1;
            s[s[x].son[0]].tag^=1;
            std :: swap(s[x].son[1],s[x].son[0]);
            s[x].tag=0;
        }	
    }
    inline void rotate(int x){
        int fnow=s[x].f,ffnow=s[fnow].f;
        pushdown(x),pushdown(fnow);
        bool w=which(x);
        s[fnow].son[w]=s[x].son[w^1];
        s[s[fnow].son[w]].f=fnow;
        s[fnow].f=x;
        s[x].f=ffnow;
        s[x].son[w^1]=fnow;
        if(ffnow){
            s[ffnow].son[s[ffnow].son[1]==fnow]=x;
        }
        update(fnow);
    }
    inline void splay(int x,int goal){
        for(int qwq;(qwq=s[x].f)!=goal;rotate(x)){
            if(s[qwq].f!=goal){//这个地方特别重要，原因是需要判断的是当前的父亲有没有到目标节点，而如果把“qwq”改成“x”……就会炸 
                rotate(which(x)==which(qwq)?qwq:x);
            }
        }
        if(goal==0){
            root=x;
        }
    }

    int build_tree(int l, int r, int fa) {
            if(l > r) { return 0; }
            int mid = (l + r) >> 1;
            int now = ++ wz;
            s[now].f=fa;
            s[now].son[0]=s[now].son[1]=0;
            s[now].cnt++;
            s[now].value=original[mid];
            s[now].sub_size++;
            s[now].son[0] = build_tree(l, mid - 1, now);
            s[now].son[1] = build_tree(mid + 1, r, now);
            update(now);
            return now;
    }
    inline int find(int x){
        int now=root;
        while(1)
        {
            pushdown(now);
            if(x<=s[s[now].son[0]].sub_size){
                now=s[now].son[0];
            }	
            else  {
            x-=s[s[now].son[0] ].sub_size + 1;
            if(!x)return now;
            now=s[now].son[1];
            }
        }
    }
    inline void reverse(int x,int y){
        int l=x-1,r=y+1;
        l=find(l),r=find(r);
        splay(l,0);
        splay(r,l);
        int pos=s[root].son[1];
        pos=s[pos].son[0];
        s[pos].tag^=1;
    }
    
    std :: vector <int> ans;
    void dfs(int now){
        pushdown(now);
        if(s[now].son[0])dfs(s[now].son[0]);
        if(s[now].value!=-inf&&s[now].value!=inf){
            ans.push_back(s[now].value);
        }
        if(s[now].son[1])dfs(s[now].son[1]);
    }

    void init(int n) {
        original[1]=-inf,original[n+2]=inf;
        for(int i=1;i<=n;i++){
            original[i+1]=i;
        }
        root=build_tree(1,n+2,0);//有一个良好的定义变量习惯很重要……重复定义同一个变量（比如全局的和局部的同名）那么就会发生覆盖。 
    }
    void rev(int l, int r) {
        reverse(l + 1, r + 1);
    }

    std :: vector <int> get() {
        ans.clear();
        dfs(root);
        return ans;
    }
} TX, TY;

inline std :: pair <std :: string, int> rest(bool space = true) {
    std :: string s;
    char ch = getchar();
    for (; !isgraph(ch); ch = getchar());
    for (; isgraph(ch); ch = getchar())
        s.push_back(ch);
    return {space ? " " + s : s, s.length()};
}

std :: string s[maxn];

int main(){
	int n = read(), m = read();
    TX.init(n);
    TY.init(m);
    for (int i = 1; i <= n; ++i)
        s[i] = rest().first;
    int q = read();
    while (q--) {
        int x = read(), y = read();
        TX.rev(1, x);
        TX.rev(x + 1, n);
        TY.rev(1, y);
        TY.rev(y + 1, m);
    }

    std :: vector <int> px = TX.get(), py = TY.get();
    for (int i = 1; i <= n; ++i, puts(""))
        for (int j = 1; j <= m; ++j)
            putchar(s[px[i - 1]][py[j - 1]]);
    return 0;
}