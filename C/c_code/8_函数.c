#include <stdio.h>
// #include <string.h>
// #include <math.h>

// int Add(int x, int y)
// {
//     return x + y;
// }

// int main()
// {
//     // // 指针数组
//     // int *arr[10];
//     // // 数组指针
//     // int(*pa)[10];
//     // // 指向指针数组的数组指针
//     // int *(*pa)[10];
//     // 函数指针
//     // int (*paa)(int x, int y) = Add;

//     // int sum = 1;
//     // printf("sum=%d\n", sum);
//     return 0;
// }

// void print(char *str)
// {
//     printf("hello:%s", str);
// }
// void test(void (*p)(char *))
// {
//     printf("test\n");
//     p("bit");
// }
// int main()
// {
//     test(print);
//     return 0;
// }

// int Add(int x, int y)
// {
//     return x + y;
// }
// int main()
// {
//     int arr[10] = {0};
//     int(*p)[10] = &arr; // 取出数组的地址

//     int (*pf)(int, int);       // 函数指针
//     int (*pfarr[4])(int, int); // 函数指针数组
//     int (*(*ppfarr)[4])(int, int) = &pfarr;
//     // ppfarr是一个数组指针， 指针指向的数组有四个元素，每个元素是一个函数指针
//     return 0;
// }
// void menu()
// {
//     printf("**********************\n");
//     printf("****1.add    2.sub****\n");
//     printf("****3.mul    4.div****\n");
//     printf("******  0.exit  ******\n");
//     printf("**********************\n");
// }

// int Sub(int x, int y)
// {
//     return x - y;
// }
// int Mul(int x, int y)
// {
//     return x * y;
// }
// int Div(int x, int y)
// {
//     return x / y;
// }
// int Calc(int (*pf)(int, int))
// {
//     int x = 0;
//     int y = 0;
//     printf("请输入两个操作数:>");
//     scanf("%d%d", &x, &y);
//     printf("%d\n", pf(x, y));
// }
// int main()
// {
//     // 实现一个计算器
//     int input = 0;
//     int x = 0;
//     int y = 0;
//     int (*pfarr[5])(int, int) = {0, Add, Sub, Mul, Div};
//     do
//     {
//         menu();
//         printf("请选择：>");
//         scanf("%d", &input);
//         if (input >= 1 && input <= 4)
//         {
//             printf("请输入两个操作数:>");
//             scanf("%d%d", &x, &y);
//             int ret = pfarr[input](x, y);
//             printf("%d\n", ret);
//         }
//         else if (input == 0)
//         {
//             printf("退出\n");
//         }
//         else
//         {
//             printf("选择错误\n");
//         }

//     } while (input);

//     return 0;
// }

// int Add(int x, int y)
// {
//     return x + y;
// }
// int Sub(int x, int y)
// {
//     return x - y;
// }
// int Mul(int x, int y)
// {
//     return x * y;
// }
// int Div(int x, int y)
// {
//     return x / y;
// }

// int main()
// {
//     int *arr[5];
//     int (*pa)(int, int) = Add;
//     int (*parr[4])(int, int) = {Add, Sub, Mul, Div};

//     int i = 0;
//     for (i = 0; i < 4; i++)
//     {
//         printf("%d\n", parr[i](2, 3));
//     }
//     return 0;
// }

// int main()
// {
//     // void (*signal(int, void (*)(int)))(int);
//     typedef void (*pfun_t)(int);
//     pfun_t signal(int, pfun_t);
//     signal;
// }

// int main() {
//     (*(void (*)())0)();
// }

// void Print(char *str)
// {
// }
// int main()
// {
//     void (*p)(char *) = Print;
// }

// int Add(int x, int y)
// {
//     int z = 0;
//     z = x + y;
//     return z;
// }

// int main()
// {
//     int a = 10;
//     int b = 20;
//     printf("%d\n", Add(a, b));
//     printf("%p\n", &Add);
//     printf("%p\n", Add);
//     int (*pa)(int, int) = Add; // 定义函数指针
//     printf("%d\n", (*pa)(2, 3));  // 使用函数指针
//     return 0;
// }

// void test1(int (*arr)[5])
// {
// }
// int main()
// {
//     int arr[3][5] = {0};
//     test1(arr);
//     return 0;
// }

// int main()
// {
//     int arr[10][10] = {{1}, {2}};
//     int i = 0;
//     int(*p)[10] = arr;
//     for (i = 0; i < 5; i++)
//     {
//         printf("%d ", *(p + i) + 1);
//     }
// }

// void print2(int (*p)[5], int x, int y)
// {
//     int i = 0;
//     for (i = 0; i < x; i++)
//     {
//         int j = 0;
//         for (j = 0; j < y; j++)
//         {
//             // p = 000000000061FDE0
//             //
//             printf("%d ", *(*(p + i)+j));
//             // printf("%p ", p[i]);
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     int arr[3][5] = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}};
//     print2(arr, 3, 5);
//     return 0;
// }

// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int *p = arr;
//     int i = 0;
//     for (i = 0; i < 10; i++)
//     {
//         printf("%d ", *(p + i));
//     }
// }

// int main()
// {
//     char *arr[5];
//     // char * 表示pa变量指向的数组的元素类型，因为arr是指针数组所以表达式中嵌套两颗星
//     char *(*pa)[5] = &arr;
//     return 0;
// }

// int main()
// {
//     int *p = NULL;
//     char *pc = NULL;
//     // 数组指针：指向数组的指针，可以存放数组的地址
//     // arr 首元素地址
//     // &arr[0] 首元素地址
//     // &arr 数组的地址
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     // 中括号比星号的优先级高，所以用括号
//     int(*p)[10] = &arr; // 数组的地址要存起来
//     return 0;
// }

// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[] = {2, 3, 4, 5, 6};
//     int arr3[] = {3, 4, 5, 6, 7};
//     int *parr[] = {arr1, arr2, arr3};
//     int i = 0;
//     for (i = 0; i < 3; i++)
//     {
//         int j = 0;
//         for (j = 0; j < 5; j++)
//         {
//             printf("%d ", *(parr[i] + j));
//         }
//         printf("\n");
//     }
//     return 0;
// }

// int main()
// {
//     char arr1[] = "abcdef";
//     char arr2[] = "abcdef";
//     char *p1 = "abcdef";
//     char *p2 = "abcdef";
//     if (arr1 == arr2)
//     {
//         printf("hehe\n");
//     }
//     else
//     {
//         printf("haha\n");
//     }

//     return 0;
// }

// int main(){
//     // 字符串并不是把内容给了p，而是把首字符的地址赋值给了p
//     char * p = "abcd"; // "abcd"是一个常量字符串
//     printf("%c\n", *p);
//     printf("%s\n", p);
//     return 0;
// }

// int main()
// {
//     char arr[] = "abcd";
//     char * pc = arr;
//     printf("%s\n", arr);
//     printf("%s\n", pc);
//     return 0;
// }

// int main()
// {
//     char a = -1;
//     signed char b = -1;
//     unsigned char c = -1;
//     printf("a=%d,b=%d,c=%d", a, b, c);
//     return 0;
// }

// int check_sys()
// {
//     int a = 1;
//     // 返回1小端，返回0大端
//     return *(char *)&a;
// }

// int main()
// {
//     // 函数返回1表示小端，函数返回0表示大端
//     int ret = check_sys();
//     if (ret == 1)
//         printf("小端\n");
//     else
//         printf("大端\n");
//     return 0;
// }

// int my_strlen(const char *str)
// {
//     int count = 0;
//     assert(str != NULL);
//     while (*str != '\0')
//     {
//         count++;
//         str++;
//     }
//     return count;
// }

// int main()
// {
//     char arr[] = "abcdef";
//     int len = my_strlen(arr);
//     printf("%d\n", len);
//     return 0;
// }
// char *my_strcpy(char *dest, const char *src)
// {
//     char *ret = dest;
//     assert(dest != NULL);
//     assert(src != NULL);
//     while (*dest++ = *src++)
//     {
//         ;
//     }
//     return ret;
// }

// int main()
// {
//     char arr1[] = "#######";
//     char arr2[] = "bit";
//     printf("%s\n", my_strcpy(arr1, arr2));
//     return 0;
// }

// void reversr_string(char arr[])
// {
//     char tmp = arr[0];
//     int len = my_strlen(arr);
//     arr[0] = arr[len - 1];
//     if (reverse_string(arr + 1) >= 2)
//         reverse_string(arr + 1);
//     arr[len - 1] = tmp;
// }

// int main()
// {
//     char arr[] = "abcedf";
//     reverse_string(arr);
//     printf("%s\n", arr);
//     return 0;
// }

// int mian()
// {
//     int arr1[] = {1, 3, 5, 7, 9};
//     int arr2[] = {2, 4, 6, 8, 10};
//     int i = 0;
//     int tmp = 0;
//     int sz = sizeof(arr1[0]) / sizeof(arr1);
//     for (i = 0; i < sz; i++)
//     {
//         tmp = arr1[0];
//         arr1[0] = arr2[0];
//         arr2[0] = tmp;
//     }
// }

// int main()
// {
//     int a = 10;
//     int b = 20;
//     int c = 30;

//     int *arr[] = {&a, &b, &c};
//     int i = 0;
//     for (i = 0; i < 3; i++)
//     {
//         printf("%d\n", *arr[i]);
//     }
//     return 0;
// }

// int main()
// {
//     int a = 10;
//     int *pa = &a;
//     int **ppa = &pa; // 创建二级指针
//     printf("%d\n", **ppa);
//     return 0;
// }

// int main()
// {
//     int arr[10] = {0};
//     int *p = arr;
//     int i = 0;
//     for (i = 0; i < 10; i++)
//     {
//         // printf("%p ===== %p\n", p + i, &arr[i]);
//         *(p + i) = i;  //  循环递增替换数组中的值
//     }
//     return 0;
// }

// int main()
// {
// #define N_VALUES 5
//     float values[N_VALUES];
//     float *vp;
//     for (vp = &values[N_VALUES]; vp > values;)
//     {

//         *(--vp) = 0;
//     }
// }

// int my_strlen(char *str)
// {
//     char *start = str;
//     char *end = str;
//     while (*end != '\0')
//     {
//         end++;
//     }
//     return end - start;
// }
// int main()
// {
//     char arr[] = "bit";
//     int len = my_strlen(arr);
//     printf("%d\n", len);
//     return 0;
// }

// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     printf("%d\n", &arr[9] - &arr[0]);
//     return 0;
// }

// int main()
// {
// #define N_VALUES 5
//     float values[N_VALUES];
//     float *vp;
//     for (vp = values; vp < &values[N_VALUES];)
//     {
//         *vp++ = 0;
//     }
// }
// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int i = 0;
//     int *p = &arr[9];
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     for (i = 0; i < sz; i++)
//     {
//         printf("%d  ", *p);
//         p--;
//     }
// }

// int main(){
//     int *p = NULL; // 用来初始化指针，给指针赋值

//     // 指针不想使用时可以定义为空值
//     p = NULL;

//     // 使用指针前判断是否为空
//     if (p!=NULL)
//     {
//         *p = 20;
//     }
// }

// int main(){
//    int arr[10] = {0};
//    int *p = arr;
//    int i = 0;
//    for (i=0;i<12;i++)
//    {
//       p++;
//    }
//    return 0;
// }

// int main()
// {
//    int a;  // 局部变脸不初始化，默认是随机值
//    int *p; // 局部的指针变量，就是初始化随机值
//    *p = 20;
//    return 0;
// }

// int main()
// {
//    int arr[10] = {0};
//    int *p = arr;
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//       *(p + i) = 1;
//    }
// }

// int main()
// {
//    int a = 10;
//    int *pa = &a;
//    char *pc = &a;
//    printf("%p\n", pa);
//    printf("%p\n", pa + 1); // 整形指针加1，内存地址加4
//    printf("%p\n", pc);
//    printf("%p\n", pc + 1); // 字符类型指针加1，内存地址加4
//    return 0;
// }
// int main()
// {
//    // 不使用临时变量交换数据
//    int a = 0;
//    int b = 0;
//    a = a + b;
//    b = a - b;
//    a = a - b;
// }

// int main(){
//    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//    printf("%p\n", arr);
//    printf("%p\n", &arr[0]);
//    printf("%p\n", &arr); // 取出数组的地址
//    return 0;
// }

// void bubble_sort(int arr[], int arr_len)
// {
//     int i = 0;
//     for (i = 0; i < arr_len - 1; i++)
//     {
//         int flag = 1; // 假设要排序的数据已经有序
//         int j = 0;
//         for (j = 0; j < arr_len - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int tmp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = tmp;
//                 flag = 0; // 本次排序的数据是无序的
//             }
//         }
//         if (1==flag)
//         {
//             break;
//         }
//     }
// }

// int main()
// {
//     int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//     // 冒泡排序
//     // 数组作为参数传递的时候，实际上传递的是数组首元素的地址，&arr[0]
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     bubble_sort(arr, sz);
//     int i = 0;

//     for (i = 0; i < sz; i++)
//     {
//         printf("%d", arr[i]);
//     }
//     return 0;
// }
// int main()
// {
//     // 创建数组
//     int arr[10] = {1, 2, 3};      // 不完全初始化，剩下的元素默认初始化为0
//     char arr2[5] = "abc";         // 以这种形式创建数组，数组的形式为：['a', 'b', 0, 0, 0] ,其中第三个0是字符串结尾的\0
//     char arr3[] = "abcdef";       // ['a', 'b', 'c', 'd', 'e', 'f', 0]
//     printf("%d\n", sizeof(arr3)); // 计算arr3所占空间的大小，占7个元素 所以结果是7
//     printf("%d\n", strlen(arr3)); // 求字符串长度， 截至到\0时，遇到\0终止
//     // strlen和sizeof没有什么关联
//     // strlen只能求字符串长度
//     // sizeof是计算数组的大小类型，单位是字节

//     char arg1[] = "abc";
//     char arg2[] = {'a', 'b', 'c'};
//     printf("%d\n", sizeof(arg1));
//     printf("%d\n", sizeof(arg2));
//     printf("%d\n", strlen(arg1));
//     printf("%d\n", strlen(arg2)); // 理论是获取随机值，因为没有获取到\0

//     // 计算数组的长度
//     int sz = sizeof(arg2) / sizeof(arg2[0]);
//     printf("%d\n", sz);
//     return 0;
// }

// int jump(int n)
// {
//     // 台阶只有一个时，有一种跳法，台阶有两个时，有两种跳法
//     int a = 1;
//     int b = 2;
//     int c = 1;
//     // 台阶有两个时，不进入循环，直接返回，其余策略等同与斐波那契
//     if (2 == n)
//         return 2;
//     while (n > 2)
//     {
//         c = a + b;
//         a = b;
//         b = c;
//         n--;
//     }
//     return c;
// }

// int main()
// {
//     int n = 0;
//     int ret = 0;
//     scanf("%d", &n);
//     ret = jump(n);
//     printf("%d\n", ret);
//     return 0;
// }
// int hanio(int n, char A, char B, char C)
// {
//     if (1==n)
//     printf("%c->%c\n", A, C);
//     else
//     {
//         hanio(n-1, A, C, B);
//         printf("%c->%c\n", A, C);
//         hanio(n-1, B, A, C);
//     }

// }
// int main(){
//     int n = 0;
//     scanf("%d", &n);
//     hanio(n, 'A', 'B', 'C');
//     return 0;
// }

// // 优化斐波那契
// int Fib(int n)
// {
//     int a = 1;
//     int b = 1;
//     int c = 1;
//     while (n > 2)
//     {
//         c = a + b;
//         a = b;
//         b = c;
//         n--;
//     }
//     return c;
// }

// // 递归的进行计算斐波那契数时，进行大量重复操作
// int Fib(int n)
// {
//     if (n <= 2)
//         return 1;
//     else
//     {
//         return Fib(n - 1) + Fib(n-2);
//     }
// }

// int main()
// {
//     int n = 0;
//     int ret = 0;
//     scanf("%d", &n);
//     ret = Fib(n);
//     printf("%d\n", ret);
//     return 0;
// }

// int Fac(int n)
// {
//     if (n <= 1)
//         return 1;
//     else
//     {
//         return n * Fac(n - 1);
//     }
// }

// int main()
// {
//     int n = 0;
//     int ret = 0;
//     scanf("%d", &n);
//     ret = Fac(n);
//     printf("%d\n", ret);
//     return 0;
// }

// int my_strlen(char *str)
// {
//     if (*str != '\0')
//     {
//         // 指针加1后，指向的值便是第二个字符，由此往复，直至指向字符\0停止递归
//         return 1 + my_strlen(str + 1);
//     }
//     else
//         return 0;
// }

// int main()
// {
//     char arr[] = "bit";
//     char *str = arr;
//     int len = my_strlen(arr);
//     printf("len=%d\n", len);
//     return 0;
// }

// // 使用指针变量的参数形式来接收数组的入参
// int my_strlen(char *str)
// {
//     int count = 0;
//     while (*str != '\0')
//     {
//         printf("%c", *str);
//         count++;
//         str++;
//     }
//     return count;
// }

// int main()
// {
//     char arr[] = "bit";
//     // char *str = arr;
//     // printf("%c", *str);
//     // str++;
//     // printf("%c", *str);
//     int len = my_strlen(arr);
//     printf("len=%d\n", len);
//     return 0;
// }
// void print(int n)
// {
//     if (n>9){
//         print(n/10);
//     }
//     printf("%d\n", n%10);
// }

// int main(){
//     unsigned int num = 0;
//     scanf("%d", &num);
//     print(num);
//     return 0;
// }

// int binary_search(int arr[], int k, int len)
// {
//     int left = 0;
//     int right = len;
//     while (left <= right)
//     {
//         int mid = (left + right) / 2;
//         if (arr[mid] < k)
//         {
//             left = mid + 1;
//         }
//         else if (arr[mid] > k)
//         {
//             right = mid - 1;
//         }
//         else
//         {
//             return mid;
//         }
//     }
//     if (left > right)
//     {
//         return -1;
//     }
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int k = 7;
//     int len = sizeof(arr) / sizeof(arr[0]) - 1;
//     int ret = binary_search(arr, k, len);
//     if (ret == -1)
//     {
//         printf("找不到指定数字\n");
//     }
//     else
//     {
//         printf("找到了，下标是：%d\n", ret);
//     }
//     return 0;
// }

// int is_prime(int x)
// {
//     int i = 0;
//     for (i = 2; i <= sqrt(x); i++)
//     {
//         if (x % i == 0)
//         {
//             return 0;
//         }
//     }
//     // 如果i>sqrt(x)代表上面的循环整体走完，也代表x是素数
//     if (i > sqrt(x))
//     {
//         return 1;
//     }
// }
// int main()
// {
//     int i = 0;
//     for (i = 100; i <= 200; i++)
//     {
//         if (is_prime(i) == 1)
//         {
//             printf("%d\n", i);
//         }
//     }
// }

// void swap(int x, int y)
// {
//     int tmp = 0;
//     x = y;
//     y = tmp;
// }
// void swap2(int* x, int* y)
// {
//     int tmp = 0;
//     tmp = *x;
//     *x = *y;
//     *y = tmp;
// }
// int main()
// {
//     int a = 10;
//     int b = 20;
//     printf("a = %d, b = %d\n", a, b);
//     swap2(&a, &b);
//     printf("a = %d, b = %d\n", a, b);
//     return 0;
// }
// int get_max(int a, int b)
// {
//     return a > b ? a : b;
// }

// int main()
// {
//     int a = 1;
//     int b = 5;
//     int max = get_max(a, b);
//     printf("max = %d\n", max);
//     return 0;
// }

// int main()
// {
//     char arr1[] = "bit";
//     char arr2[] = "####";

//     strcpy(arr2, arr1);
//     printf("%s\n", arr2);
// }