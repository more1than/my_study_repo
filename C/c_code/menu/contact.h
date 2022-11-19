#define MAX 100
#define MAX_NAME 20
#define MAX_AGE 5
#define MAX_TELE 12
#define MAX_ADDR 30
#include <stdio.h>
#include <stdlib.h>

struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_AGE];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};

enum Option
{
    EXIT, // 默认为0
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT,
};

struct Contact
{
    struct PeoInfo data[MAX];
    int size; // 记录当前已有元素个数
    int capacity; // 记录当前通讯录的最大容量
};

// 声明函数
// 初始化通讯录的函数
void InitContact(struct Contact *ps);

// 增加一个信息到通讯录
void AddContact(struct Contact *ps);

// 打印通讯录中的信息
void ShowContact(const struct Contact *ps);

// 删除指定的联系人
void DelContact(struct Contact *ps);

// 查找指定的联系人
void SearchContact(const struct Contact *ps);

// 修改指定的联系人
void ModifyContact(struct Contact *ps);

// 排序联系人列表
void SortContact(const struct Contact *ps);