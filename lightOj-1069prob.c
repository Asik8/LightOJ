#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int  cont = 0;

    for (int i = 0; i < n; i++)
    {  
        cont++;
        int a, b;
        scanf("%d %d", &a, &b);
        int sub = a - b;
        if (sub >= 0)
        {
            int ans = (sub * 4) + 4 * a + 19;
            printf("Case %d: %d\n",cont,ans);
        }
        else
        {
            sub = sub*-1;
            int ans = (sub * 4) + 4 * a + 19;
            printf("Case %d: %d\n",cont,ans);
        }
    }

    return 0;
}
