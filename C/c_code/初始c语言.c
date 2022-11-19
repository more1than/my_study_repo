// #include <stdio.h>
// #include <string.h>
// 结构体是我们自己创建出的类型
// struct Book
// {
//     char name[20]; // c语言
//     short price; // 价格
// }; // 结构体结束要加上分号
// int main(){
//     // 创建一个结构体类型的变量
//     struct Book b1 = {"C", 55};
//     strcpy(b1.name, "C++"); // string copy函数拷贝字符串
//     printf("book name:%s\n", b1.name);
//     struct Book* pb = &b1;
//     printf((*pb).name);  // 利用指针获取结构体中的值
//     printf(pb->name); // 利用箭头的方式指向结构体对象中的值
//     printf("book name:%s\n", b1.name);
//     printf("price:%d\n", b1.price);
//     return 0;
// }




// int main(){
//     double d = 3.14;
//     double* pd = &d;
//     *pd = 5.55;
//     printf("%lf\n", d);
//     return 0;
// }



// 内存：

// int main()
// {
//     int a = 10;
//     // 有一种变量专门来存放地址
//     int* p = &a; // 取地址  int*中的int指的是该指针指向的数据类型
//     // 该指针的类型是int*
//     // *星号是解引用操作符，找到该地址的值
//     // 如果修改变量p的值是修改了变量a的内存地址，而*p才是修改值
//     *p = 20;
    
//     printf("%d\n", a);
//     printf("%p\n", p);
//     printf("%p\n", &a);
//     return 0;
// }






// // #define MAX 100
// //定义函数
// int Max(int a, int b)
// {
//     if (a > b)
//         return a;
//     else
//         return b;
// }
// // 定义宏
// #define MAX(X,Y) (X>Y?X:Y)
// int main()
// {
//     int a = 10;
//     int b = 20;
//     // 函数的方式
//     int max = Max(a, b);
//     printf("max=%d\n", max);
//     max = MAX(a,b);
//     printf("max=%d\n", max);
//     return 0;
// }


// extern int Add(int, int);
// int main(){
//     int a = 10;
//     int b = 20;
//     int sum = Add(a, b);
//     printf("sum=%d\n", sum);
//     return 0;
// }

// void test()
// {
//     // static 修饰局部变量
//     // 局部变量的声明周期延长了
//     // static修改全局变量，改变了变量的作用域，让静态的全局变量只能在自己的源文件中使用
//     // 
//     static int a = 1; // a被定义为了一个静态的局部变量
//     printf("a=%d\n", a);
// }

// int main()
// {
//     int i = 0;
//     while (i<5)
//     {
//         test();
//         i++;
//     }
    
// }

// int main()
// {
//     //typedef -类型定义 类型重定义
//     typedef unsigned int u_int; // unsigned int过长，使用typedef关键字重命名
//     unsigned int num = 20;  // 定义无符号整型
//     u_int num2 = 20;  // 使用重新命名后的关键字
//     return 0;
// }

// int main()
// {
//     int a = 10; // 自动创建的变量，自动变量
//     a = -2;
//     // int定义的变量是有符号的
//     signed int; // 默认是有signed的，只是省略了
//     unsigned int; // 无符号的int
//     register int b = 20; // register关键字可以把使用频率高的变量建议放在寄存器中变成寄存器变量，从而更快的调用该变量，因为寄存器相对内存来说更高速
// }

// int main()
// {
//     int a = 10;
//     int b = a--;
//     // 后置++：先使用再++，前置++：先++再使用
//     printf("a=%d b=%d", a, b);
//     return 0;

// }
// int main()
// {
//     int a = 1;
//     int b = 2;
//     int c = 3;
//     int d = 4;
//     // 数组：一组相同类型元素的集合
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 定义一个存放十个整型数字的数组
//     printf("%d\n", arr[4]);                        // 根据下标打印元素
//     int i = 0;
//     while (i < 10)
//     {
//         printf("%d ", arr[i]);
//         i++;
//     }
//     char ch[20];
//     return 0;
// }

// int Add(int x, int y)
// {
//     int z = x + y;
//     return z;
// }

// int main()
// {
//     int num1 = 10;
//     int num2 = 20;
//     int sum = 0;
//     sum = Add(num1, num2);
//     printf("sum=%d", sum);
//     return 0;
// }

// int main()
// {
//     int line = 0;
//     while (line<20)
//     {
//         printf("一行代码:%d\n", line);
//         line++;
//     }
//     if(line>=20)
//         printf("good");

//     return 0;
// }
// int main()
// {
//     int input = 0;
//     printf("Do you want study?");
//     scanf("%d\n", &input);
//     if(input==1)
//         printf("good");
//     else
//         printf("no");
//     return 0;
// }

// #include <string.h>
// int main()
// {
//     printf("%d\n", strlen("\32"));  // \ddd表示8进制数字
//     printf("%d\n", strlen("\x12")); // \xddd表示16进制数字
//     // 八进制数字和十六进制数字均代表一个字符
//     return 0;
// }
// int main()f
// {
//     char arr1[] = "abc"; // 创建一个数组
//     // "abc" --> 'a' 'b' 'c' '\0' 隐藏了一个0，\0表示字符串的结束标志
//     // 计算长度时，\0不计算为内容
//     char arr2[] = {'a', 'b', 'c', '\0'}; // 单个字符需要使用单引号？
//     printf("%s\n", arr1);
//     printf("%d\n", strlen(arr1));
//     printf("%d\n", strlen(arr2));
//     printf("%s\n", arr2);

//     return 0;
// }
// int main()
// {
//     int num1 = 0;
//     int num2 = 0;
//     int sum = 0;
//     // 取地址符号&
//     scanf("%d%d", &num1, &num2); // 把输入的值放在某个地址处
//     // printf("%d", &num1);  打印出num1的地址：6422040
//     // int sum = 0;  C语言语法规定，变量要定义在代码块的最前面
//     sum = num1 + num2;
//     printf("%d\n", sum);
//     return 0;
// }

// // 全局变量
// int num = 10;
// int main()
// {
//     float f = 95.6;
//     // 局部变量与全局变量建议不要相同，容易出现问题
//     // 变量名相同时，局部变量优先调用
//     int num = 11;  // 局部变量
//     printf("%f", f);
//     return 0;
// }

// int main()
// {

//     printf("%d\n", sizeof(char));      // char 1字节
//     printf("%d\n", sizeof(short));     // short 2字节
//     printf("%d\n", sizeof(int));       // int 4字节
//     printf("%d\n", sizeof(long));      // long 4字节
//     printf("%d\n", sizeof(long long)); // long long 8字节
//     printf("%d\n", sizeof(float));     // float 4字节
//     printf("%d\n", sizeof(double));    // double 8字节
//     short age = 20; // 只用两个自己表达age，更加节省内存空间
//     return 0;
// }

// int main()
// {
//     char ch = 'a';
//     int age = 20;
//     printf("%d", age); // %d 打印整型十进制数据
//     printf("%c", ch);  // %c 打印字符格式的数据
//     // char 字符 %c
//     // int 整型 %d
//     // short 短整型
//     // long 长整型
//     // float 浮点数 %f
//     long num = 100;
//     float f = 5.0;
//     double dou = 3.14;
//     printf("%lf", dou);
//     printf("%f", f);
//     return 0;
// }
