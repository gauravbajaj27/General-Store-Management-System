#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

/*
Employee ID:
Gaurav,emp1;
Devanshu,emp2;
Henil,emp3;

 Admin ID:
 Gaurav,admin1;
 Devanshu,admin2;
 Henil,admin3
*/


struct product
{
int code;
char name[27];
int quantity;
int price;
};

COORD c = {0, 0};
void setxy (int x, int y)
{
 c.X = x; c.Y = y; // Set X and Y coordinates
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void clrscr(){
    system("@cls||clear");
}

float amount(float p, int q)
{
	return (p*q);
}

void drawLine(){
	int a;
	for(a=0;a<80;a++){
		printf("%c" ,219);
	}
}

void empMenu(){
	    drawLine();
	    printf("\n Access granted!\n Welcome Employee!\n");
		printf("\n");
		printf("                             Employee Menu\n");
		printf("\n");
		printf("1.Prepare Bill\n");
		printf("2.Item search and detail\n");
		printf("3.Switch User or Exit\n");
		printf("\n");
		printf("--> Enter you choice(1/2/3): \n");
		printf("\n");
		drawLine();
		setxy(28,11);
}
void adminMenu(){
	    drawLine();
		printf("Access granted!\n");
	    printf("Welcome Admin!\n");
        printf("                                Admin Menu\n");
		printf("\n");
		printf("1.View Stock \n" );
		printf("2.Add or Delete Product\n");
		printf("3.Employee data\n");
		printf("4.Item search and details\n");
		printf("5.Prepare Bill\n");
		printf("6.Switch User or Exit\n");
		printf("\n");
		printf("--> Enter your choice(1/2/3/4/5/6): \n");
		printf("\n");
		drawLine();
		setxy(36,12);
}

	struct product pr[100];
	int count=0; 


int main()
{
	char username[30];
	char password[20];
	int choice,i,temp1=0;
	jump:
	setxy(0,0);
	drawLine();
	printf("                  Welcome to General Store Managment System                                       ");
	printf("\n");
	printf("USERNAME:\n" );
	printf("PASSWORD:\n");
	printf("\n");
	drawLine();
	setxy(10,3);
	scanf("%s",username);
	setxy(10,4);
	char ch;
	for(i=0;i<10;)
	{
		ch = getch();
		if(ch!=13){
			if(ch==8 && i!=0){
				printf("\b \b");
				i--;
			}
			if(ch!=8){
				printf("*");
				password[i++]=ch;
			}
		}
		else{
			break;
		}
	}
	password[i]='\0';
	

	
    clrscr();
		if (strcmp(username, "Gaurav") == 0 && strcmp(password, "admin1") == 0 || strcmp(username, "Devanshu") == 0 && strcmp(password, "admin2") == 0 || strcmp(username, "Henil") == 0 && strcmp(password, "admin3") == 0 )
		{
		adminMenu: adminMenu();
		int number;
		scanf("%i",&number);
	if(number==1){
	option1: clrscr();
	drawLine();
	
	int i;
    
	printf("                         *****  Stock List ***** \n");
    printf("------------------------------------------------------------------\n");
    printf("NAME                        |   CODE   |  STOCK   |   PRICE \n");
    printf("------------------------------------------------------------------\n");
	
    
	setxy(1,5);
    for (i = 0; i <count; i++){
	if(pr[i].name!=NULL){
	printf(" %-15s\n ",pr[i].name);
    setxy(1,5+(i+1));
	}
    }
    
	setxy(31,5);
    for (i = 0; i <count; i++){
	if(pr[i].code!=0){
	printf(" %-d \n ",pr[i].code);
    setxy(31,5+(i+1));
	}
    }
	setxy(44,5);
	for (i = 0; i <count; i++){
	if(pr[i].quantity!=0){
	printf(" %d\n ",pr[i].quantity);
    setxy(44,5+(i+1));
	} 
    }
	
	setxy(61,5);
	for (i = 0; i <count; i++){
	if(pr[i].price!=0){
	printf(" %d\n ",pr[i].price);
    setxy(61,5+(i+1));
	}
    }
	printf("\nPress 1 to return to main menu: ");
	int exit;
	scanf("%d" ,&exit);
	if(exit==1){
		clrscr();
		goto adminMenu;
	}
	else{
		clrscr();
		printf("Invalid Input! Wait for 2 secs...");
		sleep(2);
		goto option1;
	}
   } 
	    
	    if(number==2){
	   option2Menu:  clrscr();
	    drawLine();
	    printf("\n");
	    printf("1. Add Product\n");
	    printf("2. Remove Product\n");
	    printf("3. Return to main menu\n" );
	    printf("\n");
		printf("--> Enter your choice (1/2/3):  \n");
	    printf("\n");
		drawLine();
	    setxy(31,6);
	    int option2;
	    scanf("%d" ,&option2);
	    if(option2==1){
	    addProductMenu:  clrscr();
	      drawLine();
	    printf("\nEnter Product Code: ");
    	scanf("%d",&pr[count].code);
    	printf("\nEnter Product Price : ");
    	scanf("%d",&pr[count].price);
    	printf("\nEnter Product Qunatity : ");
    	scanf("%d",&pr[count].quantity);
		printf("\nEnter Product Name (Use underscore for space): ");
		scanf("  %s",&pr[count].name);
	    count++;
	    temp1++;
    	printf("\n----------------------------");
    	printf("\nProduct Added Successfully!");
    	printf("\n----------------------------");
    	printf("\n");
		printf("\n1.Add another product");
    	printf("\n2.Return to previous menu");
    	printf("\nEnter your choice(1/2): ");
    	int addProductChoice;
		scanf("%d" ,&addProductChoice);
    	if(addProductChoice==1){
    		goto addProductMenu;
		}
		if(addProductChoice==2){
			clrscr();
			goto option2Menu;
		}
		else if(addProductChoice>2 || addProductChoice==0){
			printf("Invalid Input! Wait for 2 secs...");
			sleep(2);
			goto option2Menu;
			
		}
	    }
	    if(option2==2){
	    	clrscr();
	    	drawLine();
	    	printf("\nEnter the code of the product to be deleted: ");
	    	int codeOfProduct;
			scanf("%d",&codeOfProduct);
			sleep(5);
	    	int i;
			for(i=0;i<count;i++){
				if(codeOfProduct==pr[i].code){
					while(i<=count){
						pr[i]=pr[i+1];
						i++;
					}
					count=count-1;
					printf("Product removed!");
					sleep(1);
					clrscr();
					goto option2Menu;
				}
				else if(codeOfProduct!=pr[i].code &&  i== count-1){
					printf("\nProduct data do not exist!");
					sleep(5);
					goto option2Menu;
				}
			}
			
	    }
	    if(option2==3){
	    	clrscr();
	    	goto adminMenu;
	    }
	    if(option2>3 || option2<1){
	    	clrscr();
			printf("Invalid Input! Wait for 2 seconds....");
	    	sleep(2);
	    	clrscr();
	    	goto option2Menu;
		}
	    
	    }
	    if(number==3){
	    option3Menu: clrscr();
	    drawLine();
		FILE *fp1;
	    fp1=fopen("EmployeeData.txt","r+");
	    char ch=fgetc(fp1);
	    while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(fp1);
		} 	
	    fclose(fp1);
		printf("\n");
		drawLine();
		printf("1. Add Employee\n");
		printf("2. Remove Employee\n");
		printf("3. Back to Admin Menu\n");
		printf("--> Enter you choice: ");
		int empchoice;
		scanf("%d" ,&empchoice);
		
		if(empchoice==1){
		   FILE *fp1;
         	int i=0,day,month,year,salary;
			char c,Emp_id[6],Emp_name[80];
			fp1 = fopen("EmployeeData.txt", "a+");
	     	printf("\nEnter Employee Id :");
        	scanf("%s",&Emp_id);
        	printf("Enter Employee's Name :");
        	scanf("%s",&Emp_name);
        	printf("Enter Date of joining :");
        	scanf("%d-%d-%d",&day,&month,&year);
        	printf("Enter Employee's Salary :");
        	scanf("%d",&salary);
        	fprintf(fp1,"\n%s\t%s\t\t%d-%d-%d\t%d",Emp_id,Emp_name,day,month,year,salary);
        	fclose(fp1);
        	fp1 = fopen("EmployeeData.txt", "r");
			if(fp1==NULL){
        		printf("Error Opening File !!!!!");
			}
			c = getc(fp1);
        	while (c != EOF)
        	{
          		printf("%c", c);
          		c = getc(fp1);
        	}
        	fclose(fp1);
        	clrscr();
			printf("\nEmployee Added Successfully!");
        	sleep(2);
        	clrscr();
        	goto adminMenu;
		} 
		if(empchoice==2){
        	FILE *fp1, *fp2;
			char c;
			int del_line=0,temp=1;
        	fp1 = fopen("EmployeeData.txt", "r");
        	if(fp1==NULL){
        		printf("Error Opening File !!!!!");
			}
			c = getc(fp1);
        	while (c != EOF)
        	{
          		printf("%c", c);
         		c = getc(fp1);
    		}
        	rewind(fp1);
        	printf(" \n Enter line number of the line to be deleted:");
	        scanf("%d", &del_line);
    	    fp2 = fopen("temp.txt", "w");
        	c = getc(fp1);
       		while (c != EOF) {
         		 c = getc(fp1);
         		 if (c == 10){
          			temp++;
    		}
          if (temp != del_line)
          {
            putc(c, fp2);
          }
        }
        fclose(fp1);
        fclose(fp2);
        remove("EmployeeData.txt");
        rename("temp.txt","EmployeeData.txt");
        printf("\n The contents of file after being modified are as  follows:\n");
        fp1 = fopen("EmployeeData.txt", "r");
        if(fp1==NULL){
        		printf("Error Opening File !!!!!");
			}
        c = getc(fp1);
        while (c != EOF) {
            printf("%c", c);
            c = getc(fp1);
        }
        fclose(fp1);
        clrscr();
        printf("Employee data removed Successfully!");
        sleep(2);
        clrscr();
		goto adminMenu;
        }
		if(empchoice==3){
		clrscr();
		goto adminMenu;
		}
		else{
			clrscr();
			printf("Invalid Input! Wait for 2 seconds....");
			sleep(2);
			clrscr();
			goto option3Menu;
		}
		
		}
		
	    if(number==4){
	    option4Menu: clrscr();
	    drawLine();
	    printf("\n");
		printf("1. Search item\n");
	    printf("2. Return to main menu\n");
	    printf("--> Enter your choice (1/2): \n");
	    printf("\n");
		drawLine();
	    setxy(30,4);
	    int option4Choice;
	    scanf("%d" ,&option4Choice);
	    if(option4Choice==1){
	    	printf("Enter code of Product: ");
	    	int productCode;
			scanf("%d" ,&productCode);
	    	for(i=0;i<100;i++){
	    		if(productCode==pr[i].code){
	    		    clrscr();
					drawLine();
					printf("\nProductName: %s" ,pr[i].name);
	    			printf("\nPrice: %d" ,pr[i].price);
	    			printf("\nStock left: %d" ,pr[i].quantity);
				    printf("\n");
					drawLine();
				    printf("Press any key to return to previous menu: ");
				    getch();
				    goto option4Menu;
				}
			}
		}
		if(option4Choice==2){
	    clrscr();
		goto adminMenu;	
		
		}
		else {
			clrscr();
			printf("Invalid Input. Wait for 2 secs....");
			sleep(2);
			goto option4Menu;
		}
        }
		if(number==5){
	    option5Menu:
		clrscr();
		drawLine();
		printf("\n1. Prepare Bill");
		printf("\n2. Return to previous menu");
		printf("\nEnter your choice (1/2): ");
		printf("\n");
		drawLine();
		setxy(24,4);
		int choiceOption5;
		scanf("%d" ,&choiceOption5);
		
		if(choiceOption5==1){
		option1OfOption5:clrscr();
		drawLine(); 
  		FILE *fp1;
 		fp1=fopen("Bill.txt","w");
 		if(fp1==NULL){
 			printf("Error opening File");
		 }
		int itemcode,j, quantity, cash, w = 0;
		long cash_received;
		float t_amount=0,amount1;
		char date[20];
		printf("\t\t\t\tSUPERMARKET\n");
		fprintf(fp1,"\t\t\t\tSUPERMARKET\n");
		printf("\t\t\t\tAddress line 1\n");
		fprintf(fp1,"\t\t\t\tAddress line 1\n");
		printf("\t\t\t\tAddress line 2\n");
		fprintf(fp1,"\t\t\t\tAddress line 2\n");
		printf("----------------------------------------------------------------------------------------------------------------\n");
		printf("    PRODUCTS AVAILABLE AT OUR STORE:\n");
			printf("Code\tName\t\tQty\tPrice\n");
		for(j=0;j<temp1;j++){
		printf("%d.\t%s\t\t%d\t%d\n",pr[j].code,pr[j].name,pr[j].quantity,pr[j].price);
		}
		printf("----------------------------------------------------------------------------------------------------------------\n");
		printf("DATE:");
		scanf("%s",&date);
		fprintf(fp1,"Date :%s",date);
		printf("\t\t\tCASH MEMO - RETAIL INVOICE\n");
		fprintf(fp1,"\t\t\tCASH MEMO - RETAIL INVOICE\n");
		printf("---------------------------------------------------------------------------------------------\n");
		fprintf(fp1,"----------------------------------------------------------------------------------------------\n");
		printf("CODE\tITEM NAME\t\t\t\t\t\t\t\t\t\tQUANTITY\n");
		fprintf(fp1,"CODE\tITEM NAME\t\t\t\t\t\t\t\t\t\tQUANTITY\n");
		printf("\t\tAMOUNT(Rs.)\n");
		fprintf(fp1,"\t\tAMOUNT(Rs.)\n");
		printf("---------------------------------------------------------------------------------------------\n");
		fprintf(fp1,"---------------------------------------------------------------------------------------------\n");
		printf("Enter -1 to exit bill\n");
		B:
		for(j = 1; j!= 0; j++)
		{
		scanf("%d",&itemcode);
		if(itemcode!=-1){
		fprintf(fp1,"%d",itemcode);
	}
				if(itemcode == -1)
				{
			printf("TOTAL AMOUNT :\t%0.2f\n", t_amount);
			printf("-------------------------------------------------------------------------------------------\n");
			fprintf(fp1,"-------------------------------------------------------------------------------------------\n");
			j = -1;
		}
		int k;
		for(k=0;k<temp1;k++){
		if(itemcode==pr[k].code)
		{
				printf("\t%s\t\t\t\t\t\t\t\t\t\t\t",pr[k].name);
				fprintf(fp1,"\t%s\t\t\t\t\t\t\t\t\t\t\t",pr[k].name);
				scanf("%d", &quantity);
				fprintf(fp1,"%d",quantity);
				getchar();
				amount1=amount(pr[k].price,quantity);
				printf("\n\t\t%0.2f\n", amount1);
				fprintf(fp1,"\n\t\t%0.2f\n", amount1);
		}
				if(itemcode == -1)
				{
			printf("TOTAL AMOUNT :\t%0.2f\n", t_amount);
			fprintf(fp1,"\nTOTAL AMOUNT :\t%0.2f\n", t_amount);
			printf("-----------------------------------------------------------------------------------------------\n");
			fprintf(fp1,"------------------------------------------------------------------------------------------------\n");
			j = -1;
			break;
		}
		if(k==temp1-1){
			if(itemcode!=pr[k].code){
				printf("Please Enter valid Product code\n");
				goto B;
			}
		}
	}
		t_amount += amount1;
			w += quantity;
	}
		w-=quantity;
		t_amount -= amount1;
		printf("Total number of items sold = %d\n", w);
		fprintf(fp1,"Total number of items sold = %d\n", w);
		printf("BALANCE DUE                = %0.2f\n", t_amount);
 		fprintf(fp1,"BALANCE DUE                = %0.2f\n", t_amount);
 			A:
		printf("CASH RECEIVED              = ");
		fprintf(fp1,"\nCASH RECEIVED              = ");
		scanf("%ld", &cash_received);
		if(cash_received < t_amount)
		{
			printf("Amount insufficient. Please provide more money.\n");
			goto A;
		}
		fprintf(fp1,"%ld",cash_received);
		printf("CHANGE TO BE RETURNED      = %.2f\n",(cash_received-t_amount));
		fprintf(fp1,"\nCHANGE TO BE RETURNED      = %.2f\n",(cash_received - t_amount));
		printf("-----------------------------------------------------------------------------------------------------\n");
		fprintf(fp1,"-------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\tCustomer Care E-mail : custcare@gmail.com\n");
		fprintf(fp1,"\t\t\tCustomer Care E-mail : custcare@gmail.com\n");
		printf("\t\t\tStore Phone # : 080-23316509\n");
		fprintf(fp1,"\t\t\tStore Phone # : 080-23316509\n");
		printf("\n\t\t\tCALL FOR FREE HOME DELIVERY.\n");
		fprintf(fp1,"\n\t\t\tCALL FOR FREE HOME DELIVERY.\n");
		printf("\n\t\t\t\tNo cash refunds.\n");
		fprintf(fp1,"\n\t\t\t\tNo cash refunds.\n");
		printf("\t\t\tTerms and Conditions apply.*\n");
		fprintf(fp1,"\t\t\tTerms and Conditions apply.*\n");
		printf("\t\t\t** Thank you for shopping with us **\n");
		fprintf(fp1,"\t\t\t** Thank you for shopping with us **\n");
		printf("\n*Any goods purchased from us can be exchanged along with presenting the original cash memo within 15 days from the date of purchase on any working day. Any electrical appliance purchased, is eligible for repair under warranty only if the original cash memo is shown.\n");
		fprintf(fp1,"\n*Any goods purchased from us can be exchanged along with presenting the original cash memo within 15 days from the date of purchase on any working day. Any electrical appliance purchased, is eligible for repair under warranty only if the original cash memo is shown.\n");
		sleep(5);	
		fclose(fp1);
		goto option5Menu;
		}
		
		if(choiceOption5==2){
			clrscr();
			goto adminMenu;
		}
		else{
	    	clrscr(); 
	    	printf("Invalid Input! Wait for 2 seconds...");
	    	sleep(2);
	    	clrscr();
	    	goto option5Menu;
		}
}
	    if(number==6){
		option6Menu: clrscr();
	    drawLine();
	    printf("\n1. Switch User");
	    printf("\n2. Exit");
	    printf("\nEnter your Choice (1/2): ");
	    printf("\n");
	    printf("\n");
		drawLine();
	    setxy(24,4);
		int choiceOption6;
		scanf("%d" ,&choiceOption6);
		if(choiceOption6==1){
			clrscr();
			printf("Logging off! Wait for 2 seconds");
			sleep(2);
			clrscr();
			goto jump;
		}
		if(choiceOption6==2){
		setxy(0,6);
		exit(0);
	    }
	    else{
	    	clrscr(); 
	    	printf("Invalid Input! Wait for 2 seconds...");
	    	sleep(2);
	    	clrscr();
	    	goto option6Menu;
		}
		}
	
		else if(number>=7 || number==0){
		clrscr();
		printf("Invalid input. Wait for 5 seconds.");
		sleep(5);
		clrscr();
		goto adminMenu;
		}
		}
		else if(strcmp(username, "Gaurav") == 0 && strcmp(password, "emp1") == 0 || strcmp(username, "Devanshu") == 0 && strcmp(password, "emp2") == 0 || strcmp(username, "Henil") == 0 && strcmp(password, "emp3") == 0) 
		{
		empMenu: empMenu();
		int num;
		
		scanf("%d" ,&num);
		
		if(num==1){
		empOption1: clrscr();
		drawLine();
		printf("\n1. Prepare Bill");
		printf("\n2. Return to previous menu");
		printf("\nEnter your choice (1/2): ");
		printf("\n");
		drawLine();
		setxy(24,4);
		int choiceemp1;
		scanf("%d" ,&choiceemp1);
	
	
		if(choiceemp1==1){
		drawLine(); 
  		FILE *fp1;
 		fp1=fopen("Bill.txt","w");
 		if(fp1==NULL){
 			printf("Error opening File");
		 }
		int itemcode,j, quantity, cash, w = 0;
		long cash_received;
		float t_amount=0,amount1;
		char date[20];
		printf("\t\t\t\tSUPERMARKET\n");
		fprintf(fp1,"\t\t\t\tSUPERMARKET\n");
		printf("\t\t\t\tAddress line 1\n");
		fprintf(fp1,"\t\t\t\tAddress line 1\n");
		printf("\t\t\t\tAddress line 2\n");
		fprintf(fp1,"\t\t\t\tAddress line 2\n");
		printf("----------------------------------------------------------------------------------------------------------------\n");
		printf("    PRODUCTS AVAILABLE AT OUR STORE:\n");
			printf("Code\tName\t\tQty\tPrice\n");
		for(j=0;j<temp1;j++){
		printf("%d.\t%s\t\t%d\t%d\n",pr[j].code,pr[j].name,pr[j].quantity,pr[j].price);
		}
		printf("----------------------------------------------------------------------------------------------------------------\n");
		printf("DATE:");
		scanf("%s",&date);
		fprintf(fp1,"Date :%s",date);
		printf("\t\t\tCASH MEMO - RETAIL INVOICE\n");
		fprintf(fp1,"\t\t\tCASH MEMO - RETAIL INVOICE\n");
		printf("---------------------------------------------------------------------------------------------\n");
		fprintf(fp1,"----------------------------------------------------------------------------------------------\n");
		printf("CODE\tITEM NAME\t\t\t\t\t\t\t\t\t\tQUANTITY\n");
		fprintf(fp1,"CODE\tITEM NAME\t\t\t\t\t\t\t\t\t\tQUANTITY\n");
		printf("\t\tAMOUNT(Rs.)\n");
		fprintf(fp1,"\t\tAMOUNT(Rs.)\n");
		printf("---------------------------------------------------------------------------------------------\n");
		fprintf(fp1,"---------------------------------------------------------------------------------------------\n");
		printf("Enter -1 to exit bill\n");
		C:
		for(j = 1; j!= 0; j++)
		{
		scanf("%d",&itemcode);
		if(itemcode!=-1){
		fprintf(fp1,"%d",itemcode);
	}
				if(itemcode == -1)
				{
			printf("TOTAL AMOUNT :\t%0.2f\n", t_amount);
			printf("-------------------------------------------------------------------------------------------\n");
			fprintf(fp1,"-------------------------------------------------------------------------------------------\n");
			j = -1;
		}
		int k;
		for(k=0;k<temp1;k++){
		if(itemcode==pr[k].code)
		{
				printf("\t%s\t\t\t\t\t\t\t\t\t\t\t",pr[k].name);
				fprintf(fp1,"\t%s\t\t\t\t\t\t\t\t\t\t\t",pr[k].name);
				scanf("%d", &quantity);
				fprintf(fp1,"%d",quantity);
				getchar();
				amount1=amount(pr[k].price,quantity);
				printf("\n\t\t%0.2f\n", amount1);
				fprintf(fp1,"\n\t\t%0.2f\n", amount1);
		}
				if(itemcode == -1)
				{
			printf("TOTAL AMOUNT :\t%0.2f\n", t_amount);
			fprintf(fp1,"\nTOTAL AMOUNT :\t%0.2f\n", t_amount);
			printf("-----------------------------------------------------------------------------------------------\n");
			fprintf(fp1,"------------------------------------------------------------------------------------------------\n");
			j = -1;
			break;
		}
		if(k==temp1-1){
			if(itemcode!=pr[k].code){
				printf("Please Enter valid Product code\n");
				goto C;
			}
		}
	}
		t_amount += amount1;
			w += quantity;
	}
		w-=quantity;
		t_amount -= amount1;
		printf("Total number of items sold = %d\n", w);
		fprintf(fp1,"Total number of items sold = %d\n", w);
		printf("BALANCE DUE                = %0.2f\n", t_amount);
 		fprintf(fp1,"BALANCE DUE                = %0.2f\n", t_amount);
 			D:
		printf("CASH RECEIVED              = ");
		fprintf(fp1,"\nCASH RECEIVED              = ");
		scanf("%ld", &cash_received);
		if(cash_received < t_amount)
		{
			printf("Amount insufficient. Please provide more money.\n");
			goto D;
		}
		fprintf(fp1,"%ld",cash_received);
		printf("CHANGE TO BE RETURNED      = %.2f\n",(cash_received-t_amount));
		fprintf(fp1,"\nCHANGE TO BE RETURNED      = %.2f\n",(cash_received - t_amount));
		printf("-----------------------------------------------------------------------------------------------------\n");
		fprintf(fp1,"-------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\tCustomer Care E-mail : custcare@gmail.com\n");
		fprintf(fp1,"\t\t\tCustomer Care E-mail : custcare@gmail.com\n");
		printf("\t\t\tStore Phone # : 080-23316509\n");
		fprintf(fp1,"\t\t\tStore Phone # : 080-23316509\n");
		printf("\n\t\t\tCALL FOR FREE HOME DELIVERY.\n");
		fprintf(fp1,"\n\t\t\tCALL FOR FREE HOME DELIVERY.\n");
		printf("\n\t\t\t\tNo cash refunds.\n");
		fprintf(fp1,"\n\t\t\t\tNo cash refunds.\n");
		printf("\t\t\tTerms and Conditions apply.*\n");
		fprintf(fp1,"\t\t\tTerms and Conditions apply.*\n");
		printf("\t\t\t** Thank you for shopping with us **\n");
		fprintf(fp1,"\t\t\t** Thank you for shopping with us **\n");
		printf("\n*Any goods purchased from us can be exchanged along with presenting the original cash memo within 15 days from the date of purchase on any working day. Any electrical appliance purchased, is eligible for repair under warranty only if the original cash memo is shown.\n");
		fprintf(fp1,"\n*Any goods purchased from us can be exchanged along with presenting the original cash memo within 15 days from the date of purchase on any working day. Any electrical appliance purchased, is eligible for repair under warranty only if the original cash memo is shown.\n");
		sleep(5);	
		fclose(fp1);
		goto empOption1;
			}
	
	
	
		if(choiceemp1==2){
			clrscr();
			goto empMenu;
		}
		else{
			clrscr();
			printf("Invalid Input! Wait for 2 seconds");
			sleep(2);
			goto empOption1;
		}
		}
        
		if(num==2){
    	clrscr();
	    drawLine();
	    printf("\n");
		printf("1. Search item\n");
	    printf("2. Return to main menu\n");
	    printf("--> Enter your choice (1/2): \n");
	    printf("\n");
		drawLine();
	    setxy(30,4);
	    int option2Choice;
	    scanf("%d" ,&option2Choice);
	
	
	    if(option2Choice==1){
	    	option2emp: printf("Enter code of Product: ");
	    	int productCode;
			scanf("%d" ,&productCode);
	    	for(i=0;i<100;i++){
	    		if(productCode==pr[i].code){
	    		    clrscr();
					drawLine();
					printf("\nProductName: %s" ,pr[i].name);
	    			printf("\nPrice: %d" ,pr[i].price);
	    			printf("\nStock left: %d" ,pr[i].quantity);
				    printf("\n");
					drawLine();
				    printf("Press any key to return to previous menu: ");
				    getch();
				    goto option2emp;
				}
				else if(productCode!=pr[i].code && pr[i].code==99){
				printf("Product data do not exist!");
				goto option2emp; 
				}
			}
		}
	
	
		if(option2Choice==2){
	    clrscr();
		goto empMenu;	
		}
		
		else{
	    	clrscr(); 
	    	printf("Invalid Input! Wait for 2 seconds...");
	    	sleep(2);
	    	clrscr();
	    	goto option2emp;
		}
	}
		if(num==3){
		goto option6Menu;	
		}
		
		else{
			clrscr();
			printf("Invalid Input! Wait for 2 secs!");
			sleep(2);
			goto empMenu;
		}
		
	}
		else{
		printf("\n Access denied! Invalid username or password");		
		printf("\n Wait for 2 seconds...");
		sleep(2);
		goto jump;
		}	


}
