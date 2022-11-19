#include <stdio.h>
#include <string.h>
#include <math.h>

// int main()
// {
//     int i = 0;
//     double sum = 0.0;
//     int flag = 1;
//     for (i = 1; i <= 100; i++)
//     {
//         sum += flag * 1.0 / i;
//         flag = -flag; // 颠倒数值，便于使用
//     }
// }

// int main()
// {
//     int i = 0;
//     int count = 0;
//     for (i = 101; i <= 200; i += 2)
//     {
//         int j = 0;
//         for (j = 2; j <= sqrt(i); j++)
//         {
//             if (i % j == 0)
//                 break;
//         }
//         if (j > sqrt(i))
//         {
//             count++;
//             printf("%d\n", i);
//         }
//     }
// }

// int main()
// {
//     char arr1[] = "welcome to bit!!!!!!";
//     char arr2[] = "####################";
//     int left = 0;
//     // int right = sizeof(arr1) / sizeof(arr1[0]) - 1; // 这种方法计算数组长度会包含尾部的\0进去，所以要减一
//     int right = strlen(arr1) - 1; // strlen函数默认获取\n前的元素个数，需要导入<string.h>使用
//     while (left <= right)
//     {
//         arr2[left] = arr1[left];
//         arr2[right] = arr1[right];
//         printf("%s\n", arr2);
//         left++;
//         right--;
//     }

//     printf("%d", right);
//     return 0;
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int k = 7;
//     int left = 0;
//     int right = (sizeof(arr) / sizeof(arr[0])) - 1;
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
//             printf("找到了下标是%d", mid);
//             break;
//         }
//     }
//     if (left > right)
//     {
//         printf("找不到");
//     }
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int k = 7;
//     int i;
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     for (i = 0; i < sz; i++)
//     {

//         if (k == arr[i])
//         {
//             printf("arr[%d]=7\n", i);
//             break;
//         }
//     }
//     if (i == sz)
//     {
//         printf("找不到\n");
//     }

//     return 0;
// }

// int main()
// {
//     int n = 10;
//     int i = 0;
//     int ret = 1;
//     int res = 0;
//     for (i = 1; i <= n; i++)
//     {
//         ret = ret * i;
//         res = ret + res;
//     }
//     printf("%d", res);
//     return 0;
// }

// int main()
// {
//     int i = 1;
//     do
//     {
//         if (i == 5)
//             continue;
//         printf("%d", i);
//         i++;
//     } while (i <= 10);
//     return 0;
// }