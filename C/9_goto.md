goto语句跳转到自定义的位置

```C
int main()
{
again:
    printf("hello bit");
    goto again;
    return 0;
}
```

下述代码利用goto跳过nihao返回

```c
int main()
{

    printf("hello bit");
    goto again;
    printf("NI HAO");
again:
    printf("haha");
    return 0;
}
```

可以利用goto语句结果深层嵌套的场景

例子

```c
#include <stdlib.h> // system库

int main()
{
    char input[20] = {0};
    system("shutdown -s -t 60");
again:
    printf("请输入你好，不然关机，请输入>:");
    scanf("%s", input);
    if (strcmp(input, "你好") == 0) //比较两个字符串 strcmp()
    {
        system("shutdown -a");
    }
    else
    {
        goto again;
    }
    return 0;
}
```

