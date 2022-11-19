#include <string.h>
#include "contact.h"
#include <stdlib.h>

// 声明初始化函数
void InitContact(struct Contact *ps)
{
    ps->data = (struct PeoInfo *)malloc(3 * sizeof(struct PeoInfo));
    if (ps->data == NULL)
    {
        return;
    }
    ps->size = 0;
    ps->capacity = 3;
}

void AddContact(struct Contact *ps)
{
    if (ps->size == MAX)
    {
        printf("通讯录已满，无法增加");
    }
    else
    {
        printf("请输入名字:->");
        scanf("%s", ps->data[ps->size].name);
        printf("请输入年龄:->");
        scanf("%d", &(ps->data[ps->size].age));
        printf("请输入性别:->");
        scanf("%s", ps->data[ps->size].sex);
        printf("请输入电话:->");
        scanf("%s", ps->data[ps->size].tele);
        printf("请输入地址:->");
        scanf("%s", ps->data[ps->size].addr);

        ps->size++;
        printf("添加成功\n");
    }
}

void ShowContact(const struct Contact *ps)
{
    if (ps->size == 0)
    {
        printf("通讯录为空\n");
    }
    else
    {
        int i = 0;
        printf("size=%d\n", ps->size);
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
        for (i = 0; i < ps->size; i++)
        {
            printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                   ps->data[i].name,
                   ps->data[i].age,
                   ps->data[i].sex,
                   ps->data[i].tele,
                   ps->data[i].addr);
        }
    }
}

// 加static后，函数只能在本文件中使用，不暴露给外部
static int FindByName(struct Contact *ps, char name[MAX_NAME])
{
    int i = 0;
    for (i = 0; i < ps->size; i++)
    {
        if (0 == strcmp(ps->data[i].name, name))
        {
            return i;
        }
    }
    return -1;
}

void DelContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要删除人的名字:->");
    scanf("%s", name);
    // 1. 查找要删除的人在什么位置
    // 找到了返回下标，找不到返回-1
    int pos = FindByName(ps, name);
    // 2. 删除
    if (pos == -1)
    {
        printf("要删除的人不存在\n");
    }
    else
    {
        int j = 0;
        for (j = pos; j < ps->size - 1; j++)
        {
            ps->data[j] = ps->data[j + 1];
        }
        ps->size--;
        printf("删除成功\n");
    }
}

void SearchContact(const struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要查找人的名字:->");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("要查询的人不存在\n");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n",
               ps->data[pos].name,
               ps->data[pos].age,
               ps->data[pos].sex,
               ps->data[pos].tele,
               ps->data[pos].addr);
    }
}

void ModifyContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要修改人的名字:->");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("要查询的人不存在\n");
    }
    else
    {
        printf("请输入名字:->");
        scanf("%s", ps->data[pos].name);
        printf("请输入年龄:->");
        scanf("%d", &(ps->data[pos].age));
        printf("请输入性别:->");
        scanf("%s", ps->data[pos].sex);
        printf("请输入电话:->");
        scanf("%s", ps->data[pos].tele);
        printf("请输入地址:->");
        scanf("%s", ps->data[pos].addr);

        printf("修改完成\n");
    }
}

void SortContact(const struct Contact *ps)
{
    if (ps->size == 0)
    {
        printf("通讯录为空\n");
    }
    int temp = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < ps->size - 1; i++)
    {
        for (j = 0; j < ps->size - i - 1; j++)
        {
            if (0 == (strcmp(ps->data[j].name, ps->data[j + 1].name)))
            {
                strcpy(temp, ps->data[j + 1].name);
                strcpy(ps->data[j + 1].name, ps->data[j].name);
                strcpy(ps->data[j].name, temp);
            }
        }
    }
    printf("排序成功\n");
}