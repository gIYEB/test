#include<stdio.h>
#include <string.h>
//�ڶ����޸� 
struct people
{
	char id[20];
	double income;
	double expense;
	char date[10];
	char sort[20];
	char remarks[30];
};
struct people number[50];

void menu()//ϵͳ�˵� 
{
	system("cls");//���� 
	printf("======================================\n");
	printf("       ��ӭʹ�ø����ʵ�����ϵͳ       \n");
	printf("======================================\n");
	printf("��ѡ�����\n");
	printf("1����¼����\n"); 
	printf("2����¼֧��\n"); 
	printf("3���鿴�����˵�\n"); 
	printf("4����ѯ�˵�\n"); 
	printf("5�������¶�Ԥ��\n"); 
	printf("6���鿴�¶�ͳ�Ʊ���\n"); 
	printf("7���˳�ϵͳ\n");
	printf("\n");
	printf("������ѡ����ţ�"); 
}
//��¼���� 
void recordincome()
{
	FILE *fp;
	int n=0;
	int i;
	if((fp=fopen("bill.txt","ab+"))==NULL)
	{
		printf("Fail to open file!\n");
		return;//�˳����� 
	}
	printf("��������˵�ϵͳid:");
	scanf("%s",number[n].id);
	for(i=0;i<n;i++)
		{
			if(strcmp(number[i].id,number[n].id)!=0)
			{
				printf("�����ڸ�id�ĸ����˻���"); 
				fclose(fp);
				return;
			}
		}
	printf("������%s������Ϣ��\n",number[n].id);
	printf("���ڣ�YYYY-MM-DD):");
	scanf("%s",number[n].date);
	printf("��");
	scanf("%lf",&number[n].income);
	printf("����繤�ʡ�����ȣ���");
	scanf("%s",number[n].sort);
	printf("��ע��");
	scanf("%s",number[n].remarks);
	
	if((fwrite(&number[n],sizeof(struct people),1,fp))!=1)
		{
			printf("�˵�������Ϣд��ʧ�ܣ�\n");
			getch();
		}
		else
		{
			printf("%s �ĸ����˵�������Ϣд��ɹ�!\n",number[n].id);
		}
	++n;
	fflush(stdin); 
	fclose(fp);
	printf("����¼�������\n"); 
}
//��¼֧�� 
void recordexpense()
{
	FILE *fp;
	int n=0;
	int i;
	if((fp=fopen("people.txt","ab+"))==NULL)
	{
		printf("Fail to open file!\n");
		return;//�˳����� 
	}
	printf("��������˵�ϵͳid:");
	scanf("%s",number[n].id);
	for(i=0;i<n;i++)
		{
			if(strcmp(number[i].id,number[n].id)!=0)
			{
				printf("�����ڸ�id�ĸ����˻���"); 
				fclose(fp);
				return;
			}
		}
	printf("������%s֧����Ϣ��\n",number[n].id);
	printf("���ڣ�YYYY-MM-DD):");
	scanf("%s",number[n].date);
	printf("��");
	scanf("%lf",&number[n].expense);
	printf("�������ʳ���ճ���Ʒ����ͨ���õȣ���");
	scanf("%s",number[n].sort);
	printf("��ע��");
	scanf("%s",number[n].remarks);
	
	if((fwrite(&number[n],sizeof(struct people),1,fp))!=1)
		{
			printf("�˵�֧����Ϣд��ʧ�ܣ�\n");
			getch();
		}
		else
		{
			printf("%s �ĸ����˵�֧����Ϣд��ɹ�!\n",number[n].id);
		}
	++n;
	fflush(stdin); 
	fclose(fp);
	printf("����¼�������\n"); 
}
void checkAllBill()
{
    FILE *fp;
	int n=0,i;
	char ch[n];
	int choice=0;
	if((fp=fopen("Bill.txt","ab+"))==NULL)
	{
		printf("Failed to open file!\n");
		return; 
	}
	memset(number,0,50*sizeof(struct people));
	while(!feof(fp))
	{
		if(fread(&number[n],sizeof(struct people),1,fp)==1)
		{
			++n;
		}
	}
	system("cls");
	printf("������Ҫ���в�ѯ���û���");
	fflush(stdin);
	scanf("%s",ch);
	for(i=0;i<n;i++)
	{
		if(strcmp(ch,number[i].id)==0)
		{
			printf("�û���Ϣ���ҳɹ���\n");
			printf("�û�id:\n");
			printf("%s\n",number[i].id);
			printf("�û�����:\n");
			printf("%lf\n",number[i].income);
			printf("�û�֧��:\n");
			printf("%lf\n",number[i].expense);
			break;
		}
	}
	if(i==n)
	{
		printf("δ��ѯ�����û���Ϣ��\n");
	}
	fclose(fp);
} 
void referBill()
{
	
}
void setMonthBudget()
{
	
}
void checkMonthReturns()
{
	
}
int main()
{
	int choice;
	menu();
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			recordincome();
			break;
		case 2:
			recordexpense();
			break;
		case 3:
			checkAllBill();
			break;
		case 4:
			referBill();
			break;
		case 5:
			setMonthBudget();
			break;
		case 6:
			checkMonthReturns();
			break;
		case 7:
			return;
	} 	
	return 0;	
} 


