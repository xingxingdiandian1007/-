#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int questionNum;//��Ŀ����
int symbolNum;//�����������
char symbolType[5];//���������
int maxNum;//�������ֵ
int brackets;//�Ƿ�������
int decimal;//�Ƿ���С��
int outputMode;//�û�ѡ�������ʽ
float number[5];//����
char symbol[4];//�����
int bracketsPosition;//����λ��
void getNumber()//�������
{
    for (int i = 0; i < 5; i++)
    {
        if (decimal == 0)//�������
        {
            number[i] = rand() % (maxNum + 1);
        }
        else//���С��
        {
            number[i] = rand() % maxNum;
            number[i] = number[i] + rand() % 100 * 0.01;
        }
    }
}
void getSymbol()//�������
{
    for (int i = 0; i < 4; i++)
    {
        symbol[i] = symbolType[rand() % symbolNum];
    }
}
void outputScreen()//ֱ������Ļ��ӡ
{
    if (decimal == 1)//����
    {
        if (brackets == 1)//������
        {
            printf("                 ");
            printf("%.0f%c%.0f%c%.0f%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
        }
        if (brackets == 2)//������
        {
            bracketsPosition = rand() % 4;
            if (bracketsPosition == 0)//һ����������
            {
                printf("                 ");
                printf("��%.0f%c%.0f��%c%.0f%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
            }
            if (bracketsPosition == 1)//������������
            {
                printf("                 ");
                printf("%.0f%c(%.0f%c%.0f)%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
            }
            if (bracketsPosition == 2)//������������
            {
                printf("                 ");
                printf("%.0f%c%.0f%c(%.0f%c%.0f)%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
            }
            if (bracketsPosition == 3)//������������
            {
                printf("                 ");
                printf("%.0f%c%.0f%c%.0f%c(%.0f%c%.0f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
            }
        }

    }
    if (decimal == 2)//С��
    {
        if (brackets == 1)//������
        {
            printf("                 ");
            printf("%.2f%c%.2f%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
        }
        if (brackets == 2)//������
        {
            printf("                 ");
            bracketsPosition = rand() % 4;
            if (bracketsPosition == 0)//һ����������
            {
                printf("                 ");
                printf("��%.2f%c%.2f��%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
            }
            if (bracketsPosition == 1)//������������
            {
                printf("                 ");
                printf("%.2f%c(%.2f%c%.2f)%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
            }
            if (bracketsPosition == 2)//������������
            {
                printf("                 ");
                printf("%.2f%c%.2f%c(%.2f%c%.2f)%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
            }
            if (bracketsPosition == 3)//������������
            {
                printf("                 ");
                printf("%.2f%c%.2f%c%.2f%c(%.2f%c%.2f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
            }
        }
    }
}

int main()
{
    printf(" *************************************************\n");
    printf("                 �����������ɳ���                 \n");
    printf(" ��������Ŀ����:\n");
    printf(" *************************************************\n");
    printf(" ");
    scanf("%d", &questionNum);
    printf(" *************************************************\n");
    printf(" �����������������:1.һ�� 2.���� 3.���� 4.����  \n");
    printf(" *************************************************\n");
    printf(" ");
    scanf("%d", &symbolNum);
    printf(" *************************************************\n");
    printf(" ����������ʹ�õ��������ֱ������+-*/\n");
    printf(" *************************************************\n");
    printf(" ");
    scanf("%s", symbolType);
    printf(" �����õ������ֵ������ֵ��\n");
    printf(" *************************************************\n");
    printf(" ");
    scanf("%d", &maxNum);
    printf(" *************************************************\n");
    printf(" ��ѡ���Ƿ������ţ�1.û�� 2.��\n");
    printf(" *************************************************\n");
    printf(" ");
    scanf("%d", &brackets);
    printf(" *************************************************\n");
    printf(" ��ѡ���Ƿ���С����1.û�� 2.��\n");
    printf(" *************************************************\n");
    printf(" ");
    scanf("%d", &decimal);
    printf(" *************************************************\n");
    printf(" ��ѡ�������ʽ��1.ֱ�Ӵ�ӡ����Ļ 2.������ļ�\n");
    printf(" *************************************************\n");
    printf(" ");
    scanf("%d", &outputMode);
    printf(" *************************************************\n");
    if (outputMode == 1)
    {
        printf(" ������ʽ����\n");
    }
    if (outputMode == 2)
    {
        printf(" �����ļ��ɹ�\n");
    }
    srand((int)time(0));//�������ͬ
    FILE* fp;
    fp = fopen("��������.txt", "w");//�ļ�д����
    for (int t = 0; t < questionNum; t++)
    {
        getNumber();//�������
        getSymbol();//�������
        for (int i = 0; i < 4; i++)
        {
            if ((symbol[i] == '/') && (number[i + 1] == 0))//������Ϊ0
            {
                number[i + 1]++;
            }
        }
        if (outputMode == 1)//�������Ļ
        {
            outputScreen();
        }
        if (outputMode == 2)//������ļ�
        {
            if (decimal == 1)//����
            {
                if (brackets == 1)//������
                {
                    fprintf(fp, "%.0f%c%.0f%c%.0f%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                }
                if (brackets == 2)//������
                {
                    bracketsPosition = rand() % 4;
                    if (bracketsPosition == 0)//һ����������
                    {
                        fprintf(fp, "��%.0f%c%.0f��%c%.0f%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 1)//������������
                    {
                        fprintf(fp, "%.0f%c(%.0f%c%.0f)%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 2)//������������
                    {
                        fprintf(fp, "%.0f%c%.0f%c(%.0f%c%.0f)%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 2)//������������
                    {
                        fprintf(fp, "%.0f%c%.0f%c%.0f%c(%.0f%c%.0f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                }
            }
            if (decimal == 2)//С��
            {
                if (brackets == 1)//������
                {
                    fprintf(fp, "%.2f%c%.2f%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                }
                if (brackets == 2)//������
                {
                    bracketsPosition = rand() % 4;
                    if (bracketsPosition == 0)//һ����������
                    {
                        fprintf(fp, "��%.2f%c%.2f��%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 1)//������������
                    {
                        fprintf(fp, "%.2f%c(%.2f%c%.2f)%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 2)//������������
                    {
                        fprintf(fp, "%.2f%c%.2f%c(%.2f%c%.2f)%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 3)//������������
                    {
                        fprintf(fp, "%.2f%c%.2f%c%.2f%c(%.2f%c%.2f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                }
            }
        }

    }
    fclose(fp);//�ر��ļ�
    printf(" -------------------------------------------------\n");
    return 0;
}