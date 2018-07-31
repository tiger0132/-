#include<bits/stdc++.h>
#define pb push_back
using namespace std;
class fun{
private:
    int n;
    vector <double> num;
public:
    fun ()
    {
        n=0;
        num.clear();
    }
    int size()
    {
        return n;
    }

    vector <double> getarray()
    {
        return num;
    }

    void insert(vector <double> p)
    {
        num=p;
        n=p.size();
    }

    void mem(int p,double e,...)
    {
        double *q=&e;
        n=p;
        for (int i=1;i<=n;i++)
        {
            num.pb(*q);
            q++;
        }
    }

    double operator ()(double x)
    {
        double ans=0;
        double xt =1;
        for (int i=0;i<=n-1;i++)
        {
            ans+=xt*num[i];
            xt*=x;
        }
        return ans;
    }

    void print()
    {
        for (int i=0;i<n;i++)
        {
            if (i==0) cout << num[i];
            else
            if (num[i] != 0)
            {
                if (num[i]<0)
                    cout << num[i] << "x^"<<i;
                else cout << "+" << num[i] << "x^"<<i;
            }
        }
    }
    fun operator !()
    {
        fun H;
        H.n=n-1;
        for (int i=0;i<H.n;i++)
        {
            H.num.pb((i+1)*num[i+1]);
        }
        return H;
    }

    double get_root(double p,double q)
    {
        fun f;
        f.insert(num);
        if (f(p)*f(q)>0) return -100000000;
        double mid = (p+q)/2;
        while (p+0.000001<q)
        {
            if (f(p)*f(mid)<=0) q=mid;
            else p=mid;
            mid=(p+q)/2;
        }
        return mid;
    }

    double operator [] (int p)
    {
        return num[p];
    }
};

vector <double> get_all_answer(double s,double e,fun f)
{
    vector <double> ret;
    vector <double> qw;
    qw = f.getarray();
    ret.clear();
    if (qw.size()<=2)
    {
        ret.pb(-qw[0]/qw[1]);
        return ret;
    }
    vector <double> ans_list = get_all_answer(s,e,(!f));
    if (ans_list.size()==0)
    {
        if (f.get_root(s,e)>-99999999) ret.pb(f.get_root(s,e));
        return ret;
    }
    if (f.get_root(s,ans_list[0])>-99999999) ret.pb(f.get_root(s,ans_list[0]));
    for (int i=0;i<ans_list.size()-1;i++)
    {
        if (f.get_root(ans_list[i],ans_list[i+1])>-99999999)
            ret.pb(f.get_root(ans_list[i],ans_list[i+1]));
    }
    if (f.get_root(ans_list[ans_list.size()-1],e)>-99999999)
        ret.pb(f.get_root(ans_list[ans_list.size()-1],e));
    vector <double> RET;
    if (ret.size()==0) return ret;
    RET.pb(ret[0]);
    for (int i=1;i<ret.size();i++)
    {
        if (abs(ret[i]-ret[i-1])>0.00001)
            RET.pb(ret[i]);
    }
    return RET;
}

int main()
{
    fun f;
    vector <double> g;
    int n;
    cin >> n;
    n++;
    for (int i=1;i<=n;i++)
    {
        double x;
        cin >> x;
        g.pb(x);
    }
    f.insert(g);
    double s,e;
    cin >> s >> e;
    vector <double> ans;
    ans = get_all_answer(s,e,f);
    for (int i=0;i<ans.size();i++)
        printf("%.5lf ",ans[i]);
		return 0;
}