### 初始C语言

什么是C语言

是一门计算机语言（人和计算机交流的语言）

```c
// stdio 标准输入输出
#include <stdio.h> // 包含一个stdio.h的文件
// int是整型的意思
// main前面的int表示，main函数调用之后返回一个整型
int main() //主函数-程序的入口-main函数有且只有一个
{
    printf("112312"); // print f=func - 打印函数
    return 0; // 返 回值
}

void main() // 过时的写法，不建议使用
{}
```

// char 字符数据类型

// short 短整型

// int 整型

// long 长整型

// long long 更长的整型

// float 单精度浮点型

// double 双精度浮点型

```c
#include <stdio.h>

int main()
{
    char ch = 'a';
    int age = 20;
    printf("%d", age); // %d 打印整型十进制数据
    printf("%c", ch);  // %c 打印字符格式的数据
    // char 字符 %c
    // int 整型 %d
    // short 短整型 
    // long 长整型
    // float 浮点数 %f
    long num = 100;
    float f = 5.0;
    double dou = 3.14;
    printf("%lf", dou);
    printf("%f", f);
    return 0;
}
```

```c
int main()
{

    printf("%d\n", sizeof(char));      // char 1字节
    printf("%d\n", sizeof(short));     // short 2字节
    printf("%d\n", sizeof(int));       // int 4字节
    printf("%d\n", sizeof(long));      // long 4字节
    printf("%d\n", sizeof(long long)); // long long 8字节
    printf("%d\n", sizeof(float));     // float 4字节
    printf("%d\n", sizeof(double));    // double 8字节
    short age = 20; // 只用两个自己表达age，更加节省内存空间
    return 0;
}
```

```c
// 全局变量
int num = 10;
int main()
{
    float f = 95.6;
    // 局部变量与全局变量建议不要相同，容易出现问题
    // 变量名相同时，局部变量优先调用
    int num = 11;  // 局部变量
    printf("%f", f);
    return 0;
}
```

```c
int main()
{
    int num1 = 0;
    int num2 = 0;
    int sum = 0;
    // 取地址符号&
    scanf("%d%d", &num1, &num2); // 把输入的值放在某个地址处
    // printf("%d", &num1);  打印出num1的地址：6422040
    // int sum = 0;  C语言语法规定，变量要定义在代码块的最前面
    sum = num1 + num2;
    printf("%d\n", sum);
    return 0;
}

```

