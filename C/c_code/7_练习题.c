#include <stdio.h>
#include <stdlib.h> // system库

// int main()
// {
//     char input[20] = {0};
//     system("shutdown -s -t 60");
// again:
//     printf("请输入你好，不然关机，请输入>:");
//     scanf("%s", input);
//     if (strcmp(input, "你好") == 0) //比较两个字符串 strcmp()
//     {
//         system("shutdown -a");
//     }
//     else
//     {
//         goto again;
//     }
//     return 0;
// }

// int main()
// {

//     printf("hello bit");
//     goto again;
//     printf("NI HAO");
// again:
//     printf("haha");
//     return 0;
// }

// int main()
// {
//     int i = 0;
//     int j = 0;
//     for (i = 1; i <= 9; i++)
//     {
//         for (j = 1; j <= i; j++)
//         {
//             printf("%d * %d = %d ", i, j, i*j);
//         }
//         printf("\n");
//     }
// }

// int main(){
//     int arr[] = {1, 2,3,4,5,6,7,8,9,10};
//     int max = arr[0];
//     int i=0;
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     for (i=1;i<sz;i++)
//     {
//         if (arr[i]>max)
//         {
//             max = arr[i];
//         }
//     }
//     printf("最大值是%d\n", max);
//     return 0;
// }