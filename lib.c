#include<stdio.h>
#include<stdlib.h>
typedef struct _book{
    int num; //���
    int cnt; //����
    char *hist[3]; //���ļ�¼
    char* name; //����
    struct _book *next;//ָ����
} book;
typedef struct _student{
    int num; //���
    char *hist[3]; //���ļ�¼
    char *name; //����
    char *now_read;//��ǰ����
    struct _student *next;//ָ����
} student;
void b_insert(book *head); //book��������
void b_delet(book *head);  //bookɾ������
void b_change(book *head); //book�޸ĺ���
void b_print(book *head);  //���ò��麯��
void s_insert(student *head); //student��������
void s_delet(student *head);  //studentɾ������
void s_change(student *head); //����student�޸ĺ���
void s_print(student *head);  //���ò��˺���
void borrow(book *b_head, student *s_head, int b_num, int s_num, int step); //���麯��
int main()
{
    //�����ʼ��
    //1.book�����ʼ��
    book *b_head,*b_temp;
    b_head = (book *)malloc(sizeof(book));
    b_head->next = NULL;
    //2.student�����ʼ��
    student *s_head, *s_end;
    s_head = (student *)malloc(sizeof(student));
    s_head->next = NULL;
    //����ϵͳ
    printf("��ӭ\n");
    char mod;
    int book_num, st_num, step1, step2, step3;
    do
    {
        printf("ѡ���û����\n\naΪ����Ա\nuΪѧ��\n");
        scanf("%c", &mod);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if(mod=='a')
        {
            do
            {
                printf("ѡ���������\n\nͼ�� 1\n�û� 2\n���� 0\n");
                scanf("%d", &step1);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                if(step1==0)
                    break;
                printf("ѡ���������\n\n�½� 1\nע�� 2\n�޸� 3\n�鿴 4\n������һ�� 0\n");
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
                printf("������ı��\n");
                scanf("%d", &st_num);
                printf("\n\n\n��ӭ\n\n\n");
                b_print(b_head);//�����
                printf("�� 1\n�� 2\n");
                scanf("%d", &step3);
                printf("\n��������ͼ���Ż�0�˳�\n");
                scanf("%d", &book_num);
                if (book_num == 0)//0�˳�
                {
                    printf("see you\n");
                    break;
                }
                //�����޸�ͼ����Ϣ���û���Ϣ����
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
void b_insert(book *head) //book��������
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
    printf("��������\n");
    in->name = (char *)malloc(sizeof(char));
    scanf("%s", in->name);
    printf("�����鱾����\n");
    scanf("%d", &in->cnt);
    in->next = NULL;
    head->next = in;
    printf("�����ɹ�\n\n\n\n\n\n");
}
void b_delet(book *head) //bookɾ������
{
    int num;//���
    printf("�����鱾���\n");
    scanf("%d", &num);
    book *in = (book *)malloc(sizeof(book));
    for (int i = 0; i < num;i++)//�ƶ���ָ�����λ
    {
        in = head;
        head = head->next;
    }
    in->next = head->next;//Խ����ɾ����λ��
    free(head);//�ͷ��ڴ�
    for (; 1;)//ɾ��λ֮��ı��-1
    {
        head = head->next;
        head->num--;
        if (head->next==NULL)
        {
            break;
        }
        
    }
    printf("ɾ���ɹ�\n\n\n\n\n\n");
}
void b_change(book *head) //book�޸ĺ���
{
    int num,temp;
    printf("����Ҫ�޸�\n\n1 ����\n2 ����\n");
    scanf("%d", &temp);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("�����ͼ��ı��\n");
    scanf("%d", &num);
    for (int i = 0; i < num;i++)
    {
        head = head->next;
    }
    if (temp==1)
    {
        printf("��%s�޸�Ϊ____", head->name);
        head->name = (char *)malloc(sizeof(char));
        scanf("%s", head->name);
    }
    else if (temp==2)
    {
        printf("��%d�޸�Ϊ____", head->cnt);
        scanf("%d", &head->cnt);
    }
}
void b_print(book *head) //���麯��
{
    printf("���\t\t����\t\t\t����\t\t����ʷ\n");
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
void s_insert(student *head) //student��������
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
    printf("����ѧ������\n");
    in->name = (char *)malloc(sizeof(char));
    scanf("%s", in->name);
    in->next = NULL;
    head->next = in;
    printf("�����ɹ�\n\n\n\n\n\n");
}
void s_delet(student *head) //studentɾ������
{
    int num;//���
    printf("����ѧ�����\n");
    scanf("%d", &num);
    student *in = (student *)malloc(sizeof(student));
    for (int i = 0; i < num;i++)//�ƶ���ָ�����λ
    {
        in = head;
        head = head->next;
    }
    in->next = head->next;//Խ����ɾ����λ��
    free(head);//�ͷ��ڴ�
    for (; 1;)//ɾ��λ֮��ı��-1
    {
        head = head->next;
        head->num--;
        if (head->next==NULL)
        {
            break;
        }
        
    }
    printf("ɾ���ɹ�\n\n\n\n\n\n");
}
void s_change(student *head) //student�޸ĺ���
{
    int num;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("��������ı��\n");
    scanf("%d", &num);
    for (int i = 0; i < num;i++)
    {
        head = head->next;
    }
    printf("��%s�޸�Ϊ____", head->name);
    head->name = (char *)malloc(sizeof(char));
    scanf("%s", head->name);
}
void s_print(student *head) //���˺���
{
    printf("���\t����\t\t��ǰ����\t\t����ʷ\n");
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
void borrow(book *b_head, student *s_head, int b_num, int s_num, int step)//���麯��
{
    // ������ָ��λ��
    for (int i = 0; i < s_num;i++)
    {
        s_head = s_head->next;
    }
    for (int i = 0; i < b_num; i++) 
    {
        b_head = b_head->next;
    }
    //����ģ��
    if (step==1)
    {
        //Ȩ���ж�
        if (s_head->now_read==NULL&&b_head->cnt>0)//�ǿ�������
        {
            //�鱾��¼
            b_head->hist[2] = b_head->hist[1];
            b_head->hist[1] = b_head->hist[0];
            b_head->hist[0] = s_head->name;
            //ѧ����¼
            s_head->now_read = b_head->name;
            s_head->hist[2] = s_head->hist[1];
            s_head->hist[1] = s_head->hist[0];
            s_head->hist[0] = b_head->name;
        }
        else
        {
            printf("δ�黹����Ϊ0\n");
        }
    }
    //����ģ��
    else
    {
        s_head->now_read = NULL;
    }
}

