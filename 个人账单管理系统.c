#include<stdio.h>
#include <string.h>
//第二次修改 
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

void menu()//系统菜单 
{
	system("cls");//清屏 
	printf("======================================\n");
	printf("       欢迎使用个人帐单管理系统       \n");
	printf("======================================\n");
	printf("请选择操作\n");
	printf("1、记录收入\n"); 
	printf("2、记录支出\n"); 
	printf("3、查看所有账单\n"); 
	printf("4、查询账单\n"); 
	printf("5、设置月度预算\n"); 
	printf("6、查看月度统计报告\n"); 
	printf("7、退出系统\n");
	printf("\n");
	printf("请输入选项序号："); 
}
//记录收入 
void recordincome()
{
	FILE *fp;
	int n=0;
	int i;
	if((fp=fopen("bill.txt","ab+"))==NULL)
	{
		printf("Fail to open file!\n");
		return;//退出程序 
	}
	printf("输入个人账单系统id:");
	scanf("%s",number[n].id);
	for(i=0;i<n;i++)
		{
			if(strcmp(number[i].id,number[n].id)!=0)
			{
				printf("不存在该id的个人账户！"); 
				fclose(fp);
				return;
			}
		}
	printf("请输入%s收入信息：\n",number[n].id);
	printf("日期（YYYY-MM-DD):");
	scanf("%s",number[n].date);
	printf("金额：");
	scanf("%lf",&number[n].income);
	printf("类别（如工资、奖金等）：");
	scanf("%s",number[n].sort);
	printf("备注：");
	scanf("%s",number[n].remarks);
	
	if((fwrite(&number[n],sizeof(struct people),1,fp))!=1)
		{
			printf("账单收入信息写入失败！\n");
			getch();
		}
		else
		{
			printf("%s 的个人账单收入信息写入成功!\n",number[n].id);
		}
	++n;
	fflush(stdin); 
	fclose(fp);
	printf("本次录入结束！\n"); 
}
//记录支出 
void recordexpense()
{
	FILE *fp;
	int n=0;
	int i;
	if((fp=fopen("people.txt","ab+"))==NULL)
	{
		printf("Fail to open file!\n");
		return;//退出程序 
	}
	printf("输入个人账单系统id:");
	scanf("%s",number[n].id);
	for(i=0;i<n;i++)
		{
			if(strcmp(number[i].id,number[n].id)!=0)
			{
				printf("不存在该id的个人账户！"); 
				fclose(fp);
				return;
			}
		}
	printf("请输入%s支出信息：\n",number[n].id);
	printf("日期（YYYY-MM-DD):");
	scanf("%s",number[n].date);
	printf("金额：");
	scanf("%lf",&number[n].expense);
	printf("类别（如饮食、日常用品、交通费用等）：");
	scanf("%s",number[n].sort);
	printf("备注：");
	scanf("%s",number[n].remarks);
	
	if((fwrite(&number[n],sizeof(struct people),1,fp))!=1)
		{
			printf("账单支出信息写入失败！\n");
			getch();
		}
		else
		{
			printf("%s 的个人账单支出信息写入成功!\n",number[n].id);
		}
	++n;
	fflush(stdin); 
	fclose(fp);
	printf("本次录入结束！\n"); 
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
	printf("请输入要进行查询的用户：");
	fflush(stdin);
	scanf("%s",ch);
	for(i=0;i<n;i++)
	{
		if(strcmp(ch,number[i].id)==0)
		{
			printf("用户信息查找成功！\n");
			printf("用户id:\n");
			printf("%s\n",number[i].id);
			printf("用户收入:\n");
			printf("%lf\n",number[i].income);
			printf("用户支出:\n");
			printf("%lf\n",number[i].expense);
			break;
		}
	}
	if(i==n)
	{
		printf("未查询到该用户信息！\n");
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


