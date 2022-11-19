#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct S
{
    int a;
    int arr[]; // 柔性数组成员
};

int main()
{
    // struct S s;
    // printf("%d\n", sizeof(s));
    struct S *ps = (struct S *)malloc(sizeof(struct S) + 5 * sizeof(int));
    ps->a = 100;

    int i = 0;
    for (i = 0; i < 5; i++)
    {
        ps->arr[i] = i;
    }
    struct S *ptr = realloc(ps, 44);
    if (ptr != NULL)
    {
        ps = ptr;
    }
    for (i = 5; i < 10; i++)
    {
        printf("%d\n", ps->arr[i]);
    }
    // 释放动态内存
    free(ps);
    ps = NULL;
    return 0;
}

// char pp(void)
// {
//     char p[] = "hello";
//     return p;
// }
// int main()
// {
//     int *p = (int *)malloc(40);
//     // 万一malloc失败了，p就被赋值空指针
//     // 所以要校验malloc返回值的合法性
//     int i = 0;
//     for (i = 0; i < 10; i++)
//     {
//         *(p + i) = i;
//     }
//     free(p);
//     p = NULL;
//     return 0;
// }

// int main()
// {
//     // realloc 调整动态开辟内存空间的大小
//     int *p = (int *)malloc(20);

//     // 当我们发现动态内存空间不足，需要增加，可以使用realloc来调整动态空间
//     // 不要将返回值赋给要处理的变量(p)
//     int *p2 = realloc(p, 40);
//     if (p2 != NULL)
//     {
//         p = p2;
//     }

//     free(p);
//     p = NULL;
//     return 0;
// }

// int main()
// {
//     int *p = (int *)calloc(10, sizeof(int));

//     free(p);
//     p = NULL;
//     return 0;
// }

// int main()
// {
//     // 向内存申请10个整形的空间
//     int *p = (int *)malloc(10 * sizeof(int));
//     // 即使不释放空间，该变量到达生命周期时，也会主动释放空间

//     // 当动态申请的空间不再使用的时候
//     // 就应该还给操作系统
//     free(p);
//     p = NULL;
//     return 0;
// }

// void menu()
// {
//     printf("*****************************************\n");
//     printf("****** 1. add            2. del    ******\n");
//     printf("****** 3. search         4. modify ******\n");
//     printf("****** 5. show           6. sort   ******\n");
//     printf("****** 0. exit                     ******\n");
//     printf("*****************************************\n");
// }

// int main()
// {
//     int input = 0;
//     do
//     {
//         menu();
//         printf("请选择:->");
//         scanf("%d", &input);
//         switch (input)
//         {
//         case 1:

//             break;
//         case 2:

//             break;
//         case 3:

//             break;
//         case 4:

//             break;
//         case 5:

//             break;
//         case 6:

//             break;
//         case 0:
//             printf("退出通讯录\n");
//             break;
//         default:
//             printf("选择错误\n");
//             break;
//         }
//     } while (input);

//     return 0;
// }

// union Un
// {
//     int a;
//     char arr[5];
// };

// int main()
// {
//     union Un u;
//     printf("%d\n", sizeof(u));
//     return 0;
// }

// int check_sys()
// {
//     union Un
//     {
//         char c;
//         int i;
//     } u;
//     u.i = 1;
//     return u.c;
// }

// int main()
// {
//     int ret = check_sys();
//     if (1 == ret)
//     {
//         printf("小端");
//     }
//     else
//     {
//         printf("大端");
//     }
//     return 0;
// }
// int check_sys()
// {
//     int a = 1;
//     // 返回1表示小端，返回表示大端
//     return *(char *)&a;
// }

// int main()
// {
//     int ret = check_sys();
//     if (1 == ret)
//     {
//         printf("小端");
//     }
//     else
//     {
//         printf("大端");
//     }
//     return 0;
// }

// union Un
// {
//     char c;
//     int i;
// };

// int main()
// {
//     union Un u;
//     // 4
//     printf("%d\n", sizeof(u));
//     // 000000000061FE1C
//     printf("%p\n", &u);
//     // 000000000061FE1C
//     printf("%p\n", &(u.c));
//     // 000000000061FE1C
//     printf("%p\n", &(u.i));
//     return 0;
// }

// enum Day
// {
//     // 枚举中的可能取值
//     Mon,
//     Tues,
//     Wed,
//     Thur,
//     Fri,
//     Sat,
//     Sum
// };

// enum Sex
// {
//     MALE,
//     FEMALE,
//     SECRET,
// };

// enum Color
// {
//     RED = 2,
//     GREEN = 4,
//     BULE = 8,
// };

// int main()
// {
//     enum Sex s = MALE;
//     enum Color c = RED;
//     // 0 1 2
//     printf("%d %d %d\n", RED, GREEN, BULE);
//     // // null
//     // printf("%s %s %s\n", RED, GREEN, BULE);
//     return 0;
// }

// struct A
// {
//     int a : 2;
//     int b : 5;
//     int c : 10;
//     int d : 30;
// };

// int main()
// {
//     struct A a;
//     printf("%d\n", sizeof(a));
//     return 0;
// }

// struct S
// {
//     int a;
//     char c;
//     double d;
// };
// void Init(struct S *tmp)
// {
//     tmp->a = 100;
//     tmp->c = 'w';
//     tmp->d = 3.14;
// }

// int main()
// {
//     struct S s;
//     Init(&s);
//     return 0;
// }

// struct S1
// {
//     char c1;
//     int a;
//     char c2;
// };

// struct S2
// {
//     char c1;
//     char c2;
//     int a;
// };

// int main()
// {
//     struct S1 s1 = {0};
//     printf("%d\n", sizeof(s1));
//     struct S2 s2 = {0};
//     printf("%d\n", sizeof(s2));
//     return 0;
// }

// struct Stu
// {
//     char name[20]; // 名字
//     char tele[12]; // 电话
//     char sex[10];
//     int age;
// };

// int main()
// {
//     struct Stu s = {"a", "110", "男", 10};
//     printf("%s, %s, %s, %d\n", s.name, s.tele, s.sex, s.age);
//     struct Stu *p;
//     p = &s;
//     printf("%s, %s, %s, %d\n", p->name, p->tele, p->sex, p->age);
//     return 0;
// };
// // 结构体不支持嵌套，但可以存放结构体类型指针
// struct Node
// {
//     int data;
//     struct Node *next;
// };

// // 声明一个结构体类型
// struct Stu
// {
//     char name[20]; // 名字
//     char tele[12]; // 电话
//     char sex[10];
//     int age;
// };

// struct
// {
//     int a;
// } x;

// struct
// {
//     int a;
// } * x;

// int main()
// {
//     // 创建结构体变量
//     struct Stu s1;
//     struct Stu s2;
//     return 0;
// }

// int my_strlen(const char *str)
// {
//     assert(str != NULL);
//     int count = 0;
//     while (*str != '\0')
//     {
//         count++;
//         str++;
//     }
//     return count;
// }

// char *my_strcpy(char *dest, const char *src)
// {
//     // 目标地址必须大于源地址
//     assert(dest != NULL);
//     assert(src != NULL);
//     char *ret = dest;
//     // 如果src的值是\0了,证明运行到最后了，表达式的值也是\0，while为false退出循环
//     while (*dest++ = *src++)
//     {
//     }
//     return ret;
// }

// char *my_strcat(char *dest, const char *src)
// {
//     assert(dest && src);
//     char *ret = dest;
//     // 两个字符串都要包含\0，目标空间必须足够大，能容纳下字符串的内容
//     // 1.找到目的字符串的\0位置
//     while (*dest != '\0')
//     {
//         dest++;
//     }
//     // 2.追加字符串
//     while (*dest++ = *src++)
//     {
//     }
//     return ret;
// }

// int my_strcmp(const char *str1, const char *str2)
// {
//     assert(str1 && str2);
//     while (*str1 == *str2)
//     {
//         if (*str1 == '\0')
//             return 0;
//         str1++;
//         str2++;
//     }
//     return (*str1 - *str2);
// }

// char *my_strncmp(char *front, const char *back, size_t count)
// {
//     char *start = front;

//     while (*front++)
//         ;

//     front--;

//     while (count--)
//     {
//         printf("func %s \n", start);
//         if (!(*front++ = *back++))
//         {

//             return (start);
//         }
//     }
//     *front = '\0';
//     return (start);
// }

// // strstr 查找字符串
// char *my_strstr(const char *p1, const char *p2)
// {
//     assert(p1 && p2);
//     char *s1 = (char *)p1;
//     char *s2 = (char *)p2;
//     char *cur = (char *)p1;
//     // 非空校验
//     if (*p2 == '\0')
//         return (char *)p1;
//     while (*cur)
//     {
//         // 每次循环都初始化一次两个数的位置
//         // 保证每次都只往前走一步匹配子字符串
//         s1 = cur;
//         s2 = (char *)p2;
//         while (!(*s1 - *s2) && *s2 && *s1)
//         {
//             s1++;
//             s2++;
//         }
//         // s2为0代表找到了目标，返回cur
//         if (*s2 == '\0')
//             return cur;
//         cur++;
//     }
//     // 找不到字符串，返回空指针
//     return NULL;
// }

// int main()
// {
//     char arr[] = "192.168.0.100";
//     char *p = ".";

//     char buf[1024] = {0};
//     strcpy(buf, arr);

//     char *ret = NULL;
//     for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
//     {
//         printf("%s\n", ret);
//     }
//     return 0;
// }
// void *my_memcpy(void *dest, const void *src, size_t num)
// {
//     while (num--)
//     { // void *类型不支持解引用，转化为char*类型，直接复制num个字符便实现复制操作
//         *(char *)dest = *(char *)src;
//         ++(char *)dest;
//         ++(char *)src;
//     }
// }

// void *my_memmove(void *dest, const void *src, size_t count)
// {
// }

// #include <errno.h>
// int main()
// {
//     // 错误码   错误信息
//     // 0 ------ No error
//     // 1 ------ Operation not permitted
//     // 2 ------ No such file or directory
//     // errno是一个全局的错误码变量
//     // 当C语言的库函数在执行过程中发生了错误，就会把对应的错误码复制到errno变量中
//     // char *str = strerror(errno);
//     // printf("%s\n", str);
//     FILE *pf = fopen("test.txt", "r");
//     return 0;
// }

// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[] = {1, 2, 5, 4, 3};
//     int ret = memcmp(arr1, arr2, 9);
//     printf("%d\n", ret);
// }

// int FindNum(int arr[3][3], int k, int *px, int *py)
// {
//     int x = 0;
//     int y = *py - 1;
//     while (x <= *py - 1 && y >= 0)
//     {
//         if (arr[x][y] > k)
//         {
//             y--;
//         }
//         else if (arr[x][y] < k)
//         {
//             x++;
//         }
//         else
//         {
//             *px = x;
//             *py = y;
//             return 1;
//         }
//     }
// }
// int main()
// {
//     int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int k = 7;
//     int x = 3;
//     int y = 3;
//     int ret = FindNum(arr, k, &x, &y);
//     if (ret == 1)
//     {
//         printf("找到了\n");
//     }
//     else
//     {
//         printf("找不到\n");
//     }
//     return 0;
// }

// int main()
// {
//     int money = 0;
//     int total = 0;
//     int empty = 0;
//     scanf("%d", &money);
//     total = money;
//     empty = money;
//     while (empty >= 2)
//     {
//         total += empty / 2;
//         empty = empty / 2 + empty % 2;
//     }
//     printf("total=%d\n", total);
//     return 0;
// }

// void reverse(char *str)
// {
//     assert(str);
//     int len = strlen(str);
//     char *left = str;
//     char *right = str + len - 1;

//     while (left < right)
//     {
//         char tmp = *left;
//         *left = *right;
//         *right = tmp;
//         left++;
//         right--;
//     }
// }
// int main()
// {
//     char arr[256] = {0};
//     scanf("%s", arr);
//     //逆序函数
//     reverse(arr);

//     printf("%s\n", arr);
//     return 0;
// }

// int main()
// {
//     char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
//     char **cp[] = {c + 3, c + 2, c + 1, c};
//     char ***cpp = cp;
//     // POINT
//     printf("%s\n", **++cpp);
//     // ER
//     printf("%s\n", *--*++cpp + 3);
//     // ST
//     printf("%s\n", *cpp[-2] + 3);
//     // EW
//     printf("%s\n", cpp[-1][-1] + 1);
//     return 0;
// }

// int main()
// {
//     // 字符指针存放是字符串的首字符地址  w, a, a
//     char *a[] = {"work", "at", "alibaba"};
//     // a 指针数组 a是首元素地址
//     char **pa = a;
//     pa++;
//     // at
//     printf("%s\n", *pa);
//     return 0;
// }

// int main()
// {
//     int aa[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int *ptr1 = (int *)(&aa + 1);
//     int *ptr2 = (int *)(*(aa + 1));
//     // 10 5
//     printf("%d, %d\n", *(ptr1 - 1), *(ptr2 - 1));
//     printf("%d, %d\n", ptr1[-1], ptr2[-1]);
// }

// int main()
// {
//     int a[5][5];
//     int(*p)[4];
//     p = a;
//     // &p[4][2] int *
//     printf("%p, %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//     return 0;
// }

// int main()
// {
//     // 逗号表达式结果是最后一数的结果1，3，5
//     int a[3][2] = {(0, 1), (2, 3), (4, 5)};
//     int *p;
//     // a[0]存放的是二维数组中第一个数组的数组名，第一个数组的数组名也代表第一个数组的首元素地址
//     // p=第一个数组的首元素地址
//     p = a[0];
//     // p[0]  p是指针，所以代表*(p+0)，取值为1
//     printf("%d", p[0]);
//     return 0;
// }
// int main()
// {
//     int a[4] = {1, 2, 3, 4};
//     int *ptr1 = (int *)(&a + 1);
//     int *ptr2 = (int *)((int)a + 1);
//     printf("%x, %x", ptr1[-1], *ptr2);
//     return 0;
// }

// struct Test
// {
//     int Num;
//     char *pcName;
//     short sDate;
//     char cha[2];
//     short sBa[4];
// } * p;
// // 假设p的值是0x100000，如下表表达式的值分别是多少
// // 已知结构体test类型的变量大小是20个字节

// int main()
// {
//     p = (struct Test*)0x100000;
//     printf("%p\n", p + 0x1);
//     // printf("%p\n", (unsigned log)p + 0x1);
//     printf("%p\n", (unsigned int *)p + 0x1);
//     return 0;
// }

// int main()
// {
//     int a[5] = {1, 2, 3, 4, 5};
//     int *ptr = (int *)(&a+1);
//     printf("%d, %d\n", *(a+1), *(ptr-1));
//     return 0;
// }

// int main(){
//     // 创建数组
//     int arr[10] = {1, 2, 3}; // 不完全初始化，剩下的元素默认初始化为0
//     char arr2[5] = "abc"; // 以这种形式创建数组，数组的形式为：['a', 'b', 0, 0, 0] ,其中第三个0是字符串结尾的\0
//     char arr3[] = "abcdef"; // ['a', 'b', 'c', 'd', 'e', 'f', 0]
//     printf("%d\n", sizeof(arr3)); // 计算arr3所占空间的大小，占7个元素 所以结果是7
//     printf("%d\n", strlen(arr3)); // 求字符串长度， 截至到\0时，遇到\0终止
//     // strlen和sizeof没有什么关联
//     // strlen只能求字符串长度
//     // sizeof是计算数组的大小类型，单位是字节
//     return 0;
// }
// // 数组名是首元素地址有两个例外，sizeof中使用和取地址数组
// int a[] = {1, 2, 3, 4};
// //  16 sizeof内部放入数组是计算数组大小
// printf("%d\n", sizeof(a));
// //  8  数组名表示首元素地址，a+0还是首元素地址
// printf("%d\n", sizeof(a + 0));
// //  4  a是首元素地址，*a是首元素
// printf("%d\n", sizeof(*a));
// //  8  第二个元素的地址
// printf("%d\n", sizeof(a + 1));
// //  4  第二个元素的大小
// printf("%d\n", sizeof(a[1]));
// //  8  整个数组的地址， 数组的地址也是地址，地址的大小就是4/8个大小
// printf("%d\n", sizeof(&a));
// //  16 整个数组的大小
// printf("%d\n", sizeof(*&a));
// //  8
// printf("%d\n", sizeof(&a + 1));
// //  8 a先于[0]结合，获取数组首元素，然后与取地址符结合获得到首元素地址
// printf("%d\n", sizeof(&a[0]));
// //  8  第二个元素的地址
// printf("%d\n", sizeof(&a[0] + 1));

// // 字符数组
// char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
// // 6  数组长度 1*6
// printf("%d\n", sizeof(arr));
// // 8  首元素地址加0，还是地址
// printf("%d\n", sizeof(arr + 0));
// // 1  首元素地址取值，取到首元素，字符大小1
// printf("%d\n", sizeof(*arr));
// // 1  数组中第二个元素
// printf("%d\n", sizeof(arr[1]));
// // 8  数组地址
// printf("%d\n", sizeof(&arr));
// // 8  数组地址
// printf("%d\n", sizeof(&arr + 1));
// // 8  首元素地址加一
// printf("%d\n", sizeof(&arr[0] + 1));

// // 字符数组
// char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
// // 随机值，因为找不到\0
// printf("%d\n", strlen(arr));
// // 随机值
// printf("%d\n", strlen(arr + 0));
// // strlen要传入地址，结果传入了字符a，字符a  ASC码值是97，函数便把97当作地址去寻找，此代码报错
// printf("%d\n", strlen(*arr));
// // error 同上
// printf("%d\n", strlen(arr[1]));
// // 随机值
// printf("%d\n", strlen(&arr));
// // 随机值
// printf("%d\n", strlen(&arr + 1));
// // 随机值
// printf("%d\n", strlen(&arr[0] + 1));

// char arr[] = "abcdef";
// // 7 siezof计算的是数组的大小，单位是字节，所以带上\0计算
// printf("%d\n", sizeof(arr));
// // 8
// printf("%d\n", sizeof(arr + 0));
// // 1
// printf("%d\n", sizeof(*arr));
// // 1
// printf("%d\n", sizeof(arr[1]));
// // 8
// printf("%d\n", sizeof(&arr));
// // 8
// printf("%d\n", sizeof(&arr + 1));
// // 8
// printf("%d\n", sizeof(&arr[0] + 1));

// char arr[] = "abcdef";
// // 6
// printf("%d\n", strlen(arr));
// // 6
// printf("%d\n", strlen(arr + 0));
// // error
// printf("%d\n", strlen(*arr));
// // error
// printf("%d\n", strlen(arr[1]));
// // 6
// printf("%d\n", strlen(&arr));
// // 随机值
// printf("%d\n", strlen(&arr + 1));
// // 5 从第二元素往后取到\0所以是5
// printf("%d\n", strlen(&arr[0] + 1));

// // 此写法的首元素地址放入了p中
// char *p = "abcdef";
// // 8
// printf("%d\n", sizeof(p));
// // 8
// printf("%d\n", sizeof(p + 1));
// // 1
// printf("%d\n", sizeof(*p));
// // 1
// printf("%d\n", sizeof(p[0]));
// // 8
// printf("%d\n", sizeof(&p));
// // 8
// printf("%d\n", sizeof(&p + 1));
// // 8
// printf("%d\n", sizeof(&p[0] + 1));

// char *p = "abcdef";
// // 6
// printf("%d\n", strlen(p));
// // 5
// printf("%d\n", strlen(p + 1));
// // error
// printf("%d\n", strlen(*p));
// // error
// printf("%d\n", strlen(p[0]));
// // 随机值
// printf("%d\n", strlen(&p));
// // 随机值
// printf("%d\n", strlen(&p + 1));
// // 5
// printf("%d\n", strlen(&p[0] + 1));

// 二维数组
// int a[3][4] = {0};
// // 48 3X4X4(int)
// printf("%d\n", sizeof(a));
// // 4
// printf("%d\n", sizeof(a[0][0]));
// // 16 第一个数组的大小
// printf("%d\n", sizeof(a[0]));
// // 8 a[0]没单独与sizeof使用，则表示首元素地址，地址+1还是地址
// printf("%d\n", sizeof(a[0] + 1));
// // 4 整型大小
// printf("%d\n", sizeof(*(a[0] + 1)));
// // 8
// printf("%d\n", sizeof(a + 1));
// // 16
// printf("%d\n", sizeof(*(a + 1)));
// // 8 第二个数组的地址
// printf("%d\n", sizeof(&a[0] + 1));
// // 16 第二个数组的值
// printf("%d\n", sizeof(*(&a[0] + 1)));
// // 16
// printf("%d\n", sizeof(*a));
// // 16
// printf("%d\n", sizeof(a[3]));

// // 按宽度交换两数
// void Swap(char *buf1, char *buf2, int width)
// {
//     int i = 0;
//     for (i = 0; i < width; i++)
//     {
//         char tmp = *buf1;
//         *buf1 = *buf2;
//         *buf2 = tmp;
//         buf1++;
//         buf2++;
//     }
// }

// void bubble_sort(void *base, int sz, int width, int (*cmp)(const void *e1, const void *e2))
// {
//     int i = 0;
//     for (i = 0; i < sz - 1; i++)
//     {
//         int j = 0;
//         for (j = 0; j < sz - i - 1; j++)
//         {
//             if (cmp((char *)base + j * width, (char *)base + (j + 1) * width) > 0)
//             {
//                 Swap((char *)base + j * width, (char *)base + (j + 1) * width, width);
//             }
//         }
//     }
// }

// struct Stu
// {
//     char name[20];
//     int age;
// };

// int cmp_int(const void *e1, const void *e2)
// {
//     //比较两个整型值
//     return *(int *)e1 - *(int *)e2;
// }

// int cmp_float(const void *e1, const void *e2)
// {
//     // 比较两个浮点数
//     return (int)(*(float *)e1 - *(float *)e2);
// }

// int cmp_stu_by_age(const void *e1, const void *e2)
// {
//     // 比较两个结构体
//     return ((struct Stu *)e1)->age - ((struct Stu *)e2)->age;
// }

// int main()
// {
//     int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//     // int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//     // int sz = sizeof(arr) / sizeof(arr[0]);
//     // qsort(arr, sz, sizeof(arr[0]), cmp_int);
//     // // 第一个参数：待排序数组的首元素地址
//     // // 第二个参数：待排序数组的元素个数
//     // // 第三个参数：待排序数组的每个元素的大小
//     // // 第四个参数：是函数指针，比较两个元素的所有函数的地址，这个函数使用者自己实现
//     // //            函数指针的两个参数是：待比较的两个元素的地址
//     int i = 0;
//     for (i = 0; i < sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// int main()
// {
//     int a = 10;
//     int *pa = &a;

//     char ch = 'w';
//     void *p = &a;
//     p = &ch;

//     // void* 类型的指针可以接受任意任意类型的地址

//     // 对于void*类型的指针不能进行解引用操作
//     // void* 类型不能进行+-符号操作
//     return 0;
// }

// void bubble_sort(int arr[], int sz)
// {
//     int i = 0;
//     for (i = 0; i < sz - 1; i++)
//     {
//         int j = 0;
//         for (j = 0; j < sz - 1 - i; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int tmp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = tmp;
//             }
//         }
//     }
// }

// int main()
// {
//     int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     struct Stu s[3] = {{"zhang", 20}, {"li", 30}, {"gao", 19}};

//     bubble_sort(arr, sz);
//     int i = 0;
//     for (i = 0; i < sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }