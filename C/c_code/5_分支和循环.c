#include <stdio.h>

// int main()
// {
//     int i = 1;
//     do
//     {
//         printf("%d", i);
//         i++;
//     } while (i <= 10);
//     return 0;
// }

// int main()
// {
//     int i = 0;
//     int k = 0;
//     for (i = 0, k = 0; k = 0; i++, k++) // 表达式2为k=0,k=0的值为0，0为假，所以不会进入循环体中
//     {
//         printf("x=%d\n", i);
//         k++;
//     }
//     return 0;
// }

// int main()
// {
//     int x, y;
//     for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)
//     {
//         printf("x=%d\n", x);
//         printf("y=%d\n", y);
//         printf("hehe\n");
//     }
//     return 0;
// }
// int main()
// {
//     int i = 0;
//     int j = 0;
//     for (; i < 10; i++)
//     {
//         for (; j < 10; j++)
//         {
//             printf("hehe\n");
//         }
//     }
// }

// int main()
// {
//     for(;;)
//     {
//         printf("haha");
//     }
//     return 0;
// }
// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int i = 0;
//     for (i = 0; i < 10; i++)
//     {
//         printf("i=%d\n", i);
//         printf("arr=%d\n", arr[i]);
//     }
// }

// int main(){
//     int i = 0;
//     for (i=1;i<=10;i++) // 表达式1：初始化变量， 表达式2：范围， 表达式3：动作
//     {
//         if (i==5)
//             break;
//         printf("%d\n", i);
//     }
//     return 0;
// }

// int main()
// {
//     int ch = 0;
//     while ((ch = getchar()) != EOF)
//     {
//         if (ch < '0' || ch > '9')
//             continue;
//         putchar(ch);
//     }
//     return 0;
// }

// int main()
// {
//     // system("chcp 65001");
//     int ret = 0;
//     char password[20] = {0};
//     printf("请输入密码:");
//     scanf("%s", password); // 输入密码并存入数组
//     // 缓冲区还剩余一个回车字符 \n
//     printf("请确认(Y/N)");
//     int ch = 0;
//     while ((ch = getchar())!='\n') // 循环清除缓冲区 ，拿走回车符
//          {
//             ;
//          }
//     ret = getchar(); // getchar会获取到用户输入的回车\n导致直接进入判断中，因此要清空scanf函数的缓存区
//     if (ret == 'Y')
//         printf("确认成功\n");
//     else
//         printf("放弃确认\n");
//     return 0;
// }
// int main()
// {
//     // int ch = getchar(); // 获取一个用户输入的字符（input）
//     // putchar(ch); // 打印一个该getchar获取到的字符，类似于print
//     int ch = 0;
//     // EOF - end of file 文件结束标志 值为: -1
//     while ((ch = getchar()) != EOF)
//     {
//         putchar(ch);
//     }
// }

// int main(){
//     int i = 1;
//     while(i<=10)
//     {
//         if(i==5)
//             continue;
//         printf("%d", i);
//         i++;
//     }
//     return 0;
// }

// int main()
// {
//     int n = 1;
//     int m = 2;
//     switch (n)
//     {
//     case 1:
//         m++;
//     case 2:
//         n++;
//     case 3:
//         switch (n)
//         {
//         case 1:
//             n++;
//         case 2:
//             m++;
//             n++;
//             break;
//         }
//     case 4:
//         m++;
//         break;
//     default:
//         break;
//     }
//     printf("m=%d, n=%d", m, n);
//     return 0;
// }

// // swich语句
// int main()
// {
//     int day = 0;
//     scanf("%d", &day);
//     switch (day)
//     {
//     case 1:
//     case 2:
//     case 3:
//     case 4:
//     case 5:
//         printf("工作日");
//         break;
//     case 6:
//     case 7:
//         printf("休息日");
//         break;
//     default:
//         printf("输入错误");
//         break;
//     }
//     return 0;
// }
// int main()
// {
//     int a = 0;
//     while (a < 100)
//     {
//         a++;
//         if ((a % 2) == 1)
//             printf("%d\n", a);
//     }
//     return 0;
// }

// int main()
// {
//     int a = 0;
//     int b = 2;
//     if (a == 1)
//         if (b == 2)
//             printf("hehe");
//     else
//         printf("haha");
//     return 0;
// }

// int main(){
//     int age =  30;
//     if (age < 18)
//         printf("未成年");
//     else if (18<=age && age<28)
//     {
//         printf("青年");
//     }
//     else if (28<=age && age<50)
//     {
//         printf("中年");
//     }

//     else
//         printf("成年");
//     return 0;
// }