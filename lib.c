#include<stdio.h>
#include<stdlib.h>
typedef struct _book{
    int num; //编号
    int cnt; //数量
    char *hist[3]; //借阅记录
    char* name; //书名
    struct _book *next;//指针域
} book;
typedef struct _student{
    int num; //编号
    char *hist[3]; //借阅记录
    char *name; //人名
    char *now_read;//当前借阅
    struct _student *next;//指针域
} student;
void b_insert(book *head); //book创建函数
void b_delet(book *head);  //book删除函数
void b_change(book *head); //book修改函数
void b_print(book *head);  //调用查书函数
void s_insert(student *head); //student创建函数
void s_delet(student *head);  //student删除函数
void s_change(student *head); //调用student修改函数
void s_print(student *head);  //调用查人函数
void borrow(book *b_head, student *s_head, int b_num, int s_num, int step); //借书函数
int main()
{
    //链表初始化
    //1.book链表初始化
    book *b_head,*b_temp;
    b_head = (book *)malloc(sizeof(book));
    b_head->next = NULL;
    //2.student链表初始化
    student *s_head, *s_end;
    s_head = (student *)malloc(sizeof(student));
    s_head->next = NULL;
    //进入系统
    printf("欢迎\n");
    char mod;
    int book_num, st_num, step1, step2, step3;
    do
    {
        printf("选择用户身份\n\na为管理员\nu为学生\n");
        scanf("%c", &mod);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if(mod=='a')
        {
            do
            {
                printf("选择操作对象\n\n图书 1\n用户 2\n返回 0\n");
                scanf("%d", &step1);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                if(step1==0)
                    break;
                printf("选择操作类型\n\n新建 1\n注销 2\n修改 3\n查看 4\n返回上一级 0\n");
                scanf("%d", &step2);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                if (step2==0)
                    continue;
                if (step1==1)
                {
                    if (step2==1)
                    {
                        b_insert(b_head);
                        continue;
                    }
                    else if (step2==2)
                    {
                        b_delet(b_head);
                        continue;
                    }
                    else if (step2==3)
                    {
                        b_change(b_head);
                        continue;
                    }
                    else if (step2==4)
                    {
                        b_print(b_head);
                        continue;
                    }
                }
                if (step1==2)
                {
                    if (step2==1)
                    {
                        s_insert(s_head);
                        continue;
                    }
                    else if (step2==2)
                    {
                        s_delet(s_head);
                        continue;
                    }
                    else if (step2==3)
                    {
                        s_change(s_head);
                        continue;
                    }
                    else if (step2==4)
                    {
                        s_print(s_head);
                        continue;
                    }
                }
            } while (1);
            
        }
        else if(mod=='u')
        {
            do
            {
                printf("输入你的编号\n");
                scanf("%d", &st_num);
                printf("\n\n\n欢迎\n\n\n");
                b_print(b_head);//列书表
                printf("借 1\n还 2\n");
                scanf("%d", &step3);
                printf("\n输入欲阅图书编号或按0退出\n");
                scanf("%d", &book_num);
                if (book_num == 0)//0退出
                {
                    printf("see you\n");
                    break;
                }
                //调用修改图书信息及用户信息函数
                borrow(b_head, s_head, book_num, st_num, step3);
                printf("\n\n\n");
            } while (1);
            
        }
        else if (mod != 'a' && mod != 'u')
        {
            printf("\n\n\n\n\n\n");
            continue;
        }
    } while (1);
    
}
void b_insert(book *head) //book创建函数
{
    int i = 1;
    book *in = (book *)malloc(sizeof(book));
    if (head->next==NULL)
        {
            
        }
    else
    {
        i++;
        for (i;1; i++)
        {
            in->next = head;
            head = head->next;
            if (head->next==NULL)
            {
                break;
            }
        }
    }
    in->num = i;
    printf("填入书名\n");
    in->name = (char *)malloc(sizeof(char));
    scanf("%s", in->name);
    printf("输入书本数量\n");
    scanf("%d", &in->cnt);
    in->next = NULL;
    head->next = in;
    printf("创建成功\n\n\n\n\n\n");
}
void b_delet(book *head) //book删除函数
{
    int num;//编号
    printf("输入书本编号\n");
    scanf("%d", &num);
    book *in = (book *)malloc(sizeof(book));
    for (int i = 0; i < num;i++)//移动至指定编号位
    {
        in = head;
        head = head->next;
    }
    in->next = head->next;//越过欲删除的位置
    free(head);//释放内存
    for (; 1;)//删除位之后的编号-1
    {
        head = head->next;
        head->num--;
        if (head->next==NULL)
        {
            break;
        }
        
    }
    printf("删除成功\n\n\n\n\n\n");
}
void b_change(book *head) //book修改函数
{
    int num,temp;
    printf("你需要修改\n\n1 书名\n2 数量\n");
    scanf("%d", &temp);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("输入该图书的编号\n");
    scanf("%d", &num);
    for (int i = 0; i < num;i++)
    {
        head = head->next;
    }
    if (temp==1)
    {
        printf("将%s修改为____", head->name);
        head->name = (char *)malloc(sizeof(char));
        scanf("%s", head->name);
    }
    else if (temp==2)
    {
        printf("将%d修改为____", head->cnt);
        scanf("%d", &head->cnt);
    }
}
void b_print(book *head) //查书函数
{
    printf("编号\t\t书名\t\t\t数量\t\t借阅史\n");
    for (; 1;)
    {
        head = head->next;
        printf("%d\t\t%s\t\t\t%d\t\t%s %s %s\n", head->num, head->name, head->cnt, head->hist[0], head->hist[1], head->hist[2]);
        if (head->next==NULL)
        {
            break;
        }
    }
    printf("\n\n\n\n");
}
void s_insert(student *head) //student创建函数
{
    int i = 1;
    student *in = (student *)malloc(sizeof(student));
    if (head->next==NULL)
        {
            
        }
    else
    {
        i++;
        for (i;1; i++)
        {
            in->next = head;
            head = head->next;
            if (head->next==NULL)
            {
                break;
            }
        }
    }
    in->num = i;
    printf("填入学生姓名\n");
    in->name = (char *)malloc(sizeof(char));
    scanf("%s", in->name);
    in->next = NULL;
    head->next = in;
    printf("创建成功\n\n\n\n\n\n");
}
void s_delet(student *head) //student删除函数
{
    int num;//编号
    printf("输入学生编号\n");
    scanf("%d", &num);
    student *in = (student *)malloc(sizeof(student));
    for (int i = 0; i < num;i++)//移动至指定编号位
    {
        in = head;
        head = head->next;
    }
    in->next = head->next;//越过欲删除的位置
    free(head);//释放内存
    for (; 1;)//删除位之后的编号-1
    {
        head = head->next;
        head->num--;
        if (head->next==NULL)
        {
            break;
        }
        
    }
    printf("删除成功\n\n\n\n\n\n");
}
void s_change(student *head) //student修改函数
{
    int num;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("输入该生的编号\n");
    scanf("%d", &num);
    for (int i = 0; i < num;i++)
    {
        head = head->next;
    }
    printf("将%s修改为____", head->name);
    head->name = (char *)malloc(sizeof(char));
    scanf("%s", head->name);
}
void s_print(student *head) //查人函数
{
    printf("编号\t姓名\t\t当前借阅\t\t借阅史\n");
    for (; 1;)
    {
        head = head->next;
        printf("%d\t%s\t\t%s\t\t%s %s %s\n", head->num, head->name, head->now_read, head->hist[0], head->hist[1], head->hist[2]);
        if (head->next==NULL)
        {
            break;
        }
    }
    printf("\n\n\n\n");
}
void borrow(book *b_head, student *s_head, int b_num, int s_num, int step)//借书函数
{
    // 进行至指定位置
    for (int i = 0; i < s_num;i++)
    {
        s_head = s_head->next;
    }
    for (int i = 0; i < b_num; i++) 
    {
        b_head = b_head->next;
    }
    //借书模块
    if (step==1)
    {
        //权限判断
        if (s_head->now_read==NULL&&b_head->cnt>0)//是空则允许
        {
            //书本记录
            b_head->hist[2] = b_head->hist[1];
            b_head->hist[1] = b_head->hist[0];
            b_head->hist[0] = s_head->name;
            //学生记录
            s_head->now_read = b_head->name;
            s_head->hist[2] = s_head->hist[1];
            s_head->hist[1] = s_head->hist[0];
            s_head->hist[0] = b_head->name;
        }
        else
        {
            printf("未归还或库存为0\n");
        }
    }
    //还书模块
    else
    {
        s_head->now_read = NULL;
    }
}

