/*��Ni=M/mi,��(Ni,mi)=1,�ʴ���xi,����Nixi+miyi=1,
  ��Nixi��1(mod mi) ��sum(aiNixi) ��ai(mod mi)
 */

//�ⷽ����x=ai(mod mi) mi֮����������
int China(int r)
{
    int M = 1, ans = 0;
    for (int i = 0; i < r; ++i)
        M *= m[i];
    for(int i = 0;i < r;i++)
    {
        int N = M/m[i];
        int x, y;
        extend_Euclid(N, m[i], x, y);
        ans = (ans+a[i]*N*x)%M;
    }
    ans = (ans - a[r])%M;
    return (ans+M)%M;
}
