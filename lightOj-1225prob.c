#include <stdio.h>
#include <string.h>

int main()
{
    int a, c1 = 0, c2 = 0;
    scanf("%d",&a);

    for (int i = 0; i < a; i++)
    {
        c2++;
        char num[10000];
        scanf("%s",num);
        int len = strlen(num);

        for (int j = 0; j < len / 2; j++)
        {
            if (num[j] != num[len - j - 1])
            {
                c1++;
            }
        }

        if (c1 == 0)
        {
            printf("Case %d: Yes\n", c2);
        }
        else
        {
            printf("Case %d: No\n", c2);
        }

        c1 = 0;
    }

    return 0;
}