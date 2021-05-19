#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct Employee
{
	int EmpId;
	int Age;
	char Name[50];
	float Salary;
	char cGender[50];
	char cCity[50];
	char cDesignation[50];

	struct Employee *Next;
	struct Employee *Prev;
};

typedef struct Employee Employee;
typedef struct Employee* PEmployee;
typedef struct Employee** PPEmployee;

void InsertFirst(PPEmployee Head,PPEmployee Tail,int id,char *iName,int iAge,float iSalary,char *cGen,char *cCty,char *cDesg)
{
	PEmployee newn = NULL;
	int i = 0, j = 0, k = 0, l = 0;
	
	newn = (PEmployee)malloc(sizeof(Employee));
	newn->EmpId = id;

	while((*iName) != '\0')	// "Manali Aundhkar\0"
	{
		(newn->Name[i]) = (*iName);
		iName++;
		i++;
	}
	newn->Name[i] = '\0';
	//*iName = '\0'; //wrong

	newn->Age = iAge;
	newn->Salary = iSalary;

	while((*cGen) != '\0')
	{
		(newn->cGender[j]) = (*cGen);
		cGen++;
		j++;
	}
	newn->cGender[j] = '\0';

	while((*cCty) != '\0')
	{
		(newn->cCity[k]) = (*cCty);
		cCty++;
		k++;
	}
	newn->cCity[k] = '\0';

	while((*cDesg) != '\0')
	{	
		(newn->cDesignation[l]) = (*cDesg);
		cDesg++;
		l++;
	}
	newn->cDesignation[l] = '\0';

	newn->Next = NULL;
	newn->Prev = NULL;

	if((*Head == NULL) &&(*Tail == NULL))	//Linked List is Empty
	{
		(*Head) = newn;
		(*Tail) = newn;
	}

	else	//Linked List contains one or more Employee
	{
		newn->Next = (*Head);
		(*Head)->Prev = newn;
		(*Head) = (*Head)->Prev;
	}

	((*Tail)->Next) = (*Head);
	((*Head)->Prev) = (*Tail);
}

void InsertLast(PPEmployee Head,PPEmployee Tail,int id,char *iName,int iAge,float iSalary,char *cGen,char *cCty,char *cDesg)
{
	PEmployee newn = NULL;
	int i = 0,j = 0,k = 0,l = 0;
	newn = (PEmployee)malloc(sizeof(Employee));
	newn->EmpId = id;
	
	while(*iName != '\0')
	{
		(newn->Name[i]) = (*iName);
		iName++;
		i++;
	}
	newn->Name[i] = '\0';

	newn->Age = iAge;
	newn->Salary = iSalary;

	while((*cGen) != '\0')
	{
		(newn->cGender[j]) = (*cGen);
		cGen++;
		j++;
	}
	newn->cGender[j] = '\0';

	while((*cCty) != '\0')
	{
		(newn->cCity[k]) = (*cCty);
		cCty++;
		k++;
	}
	newn->cCity[k] = '\0';

	while((*cDesg) != '\0')
	{	
		(newn->cDesignation[l]) = (*cDesg);
		cDesg++;
		l++;
	}
	newn->cDesignation[l] = '\0';

	newn->Next=NULL;
	newn->Prev=NULL;

	if((*Head == NULL)&&(*Tail == NULL))	//if Linked List is empty
	{
		*Head = newn;
		*Tail = newn;
	}
	else	//if Linked List contains atleast one Employee
	{
		(*Tail)->Next = newn;
		newn->Prev = (*Tail);
		(*Tail) = (*Tail)->Next;
	}
	(*Tail)->Next = (*Head);
	(*Head)->Prev = (*Tail);
}

void Display(PEmployee Head,PEmployee Tail)
{
	do
	{
		if(Head->Next == Tail->Next)	//if node is the last node
		{
			printf("\n|Employee id is : %d  \nEmployee Age is : %d \n Employee Salary is : %0.2f \n Employee Name is : %s \n Employee Gender is : %s \n Employee City is : %s \n Employee Designation is : %s|\n",Head->EmpId,Head->Age,Head->Salary,Head->Name,Head->cGender,Head->cCity,Head->cDesignation);
		}
		else
		{
			printf("\n|Employee id is : %d  \nEmployee Age is : %d \n Employee Salary is : %0.2f \n Employee Name is : %s \n Employee Gender is : %s \n Employee City is : %s \n Employee Designation is : %s|\n",Head->EmpId,Head->Age,Head->Salary,Head->Name,Head->cGender,Head->cCity,Head->cDesignation);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);
}

int Count(PEmployee Head,PEmployee Tail)
{
	int iCnt = 0;

	do
	{
		iCnt++;
		Head = Head->Next;
	}while(Head != Tail->Next);

	return iCnt;
}

void DeleteFirst(PPEmployee Head,PPEmployee Tail)
{
	if((*Head == NULL)&&(*Tail == NULL))
	{
		return;
	}
	else if(*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		(*Head) = (*Head)->Next;
		free((*Head)->Prev);
		((*Head)->Prev) = (*Tail);
		((*Tail)->Next) = (*Head);
	}
}

void DeleteLast(PPEmployee Head,PPEmployee Tail)
{
	if((*Head == NULL)&&(*Tail == NULL))
	{
		return;
	}
	else if(*Head == *Tail)
	{
		free(*Tail);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		(*Tail) = (*Tail)->Prev;
		free((*Tail)->Next);

		((*Head)->Prev) = (*Tail);
		((*Tail)->Next) = (*Head);
	}
}

void InsertAtPosition(PPEmployee Head,PPEmployee Tail,int id,char *iName,int iAge,float iSalary,char *cGen,char *cCty,char *cDesg,int iPos)
{
	PEmployee temp = NULL;
	PEmployee newn = NULL;
	PEmployee Head2 = NULL;
	PEmployee Tail2 = NULL;

	int iSize = 0,iCnt = 0;
	int i = 0,j = 0,k = 0,l = 0;

	iSize = Count(*Head,*Tail);	

	if((iPos < 0) || (iPos > (iSize+1)))
	{
		return;
	}
	else if(iPos == 1)
	{
		InsertFirst(Head,Tail,id,iName,iAge,iSalary,cGen,cCty,cDesg);
	}
	else if(iPos == (iSize+1))
	{
		InsertLast(Head,Tail,id,iName,iAge,iSalary,cGen,cCty,cDesg);
	}
	else
	{
		/*if(iPos < (iSize/2))
		{
			//InsertAtPosition from starting end
			//Maintain a pointer Head2
		}
		else if(iPos < (iSize/2))
		{
			//InsertAtPosition from Terminating end
			//Maintain a pointer Tail2
		}*/
		temp = *Head;
		newn = (PEmployee)malloc(sizeof(Employee));
		newn->EmpId = id;

		while(*iName != '\0')
		{
			(newn->Name[i]) = (*iName);
			iName++;
			i++;
		}
		newn->Name[i] = '\0';
		
		newn->Age = iAge;
		newn->Salary = iSalary;
		
		while((*cGen) != '\0')
		{
			(newn->cGender[j]) = (*cGen);
			cGen++;
			j++;
		}
		newn->cGender[j] = '\0';

		while((*cCty) != '\0')
		{
			(newn->cCity[k]) = (*cCty);
			cCty++;
			k++;
		}
		newn->cCity[k] = '\0';

		while((*cDesg) != '\0')
		{	
			(newn->cDesignation[l]) = (*cDesg);
			cDesg++;
			l++;
		}
		newn->cDesignation[l] = '\0';

		newn->Prev=NULL;
		newn->Next=NULL;

		for(iCnt=1;iCnt<(iPos-1);iCnt++)
		{
			temp=temp->Next;
		}

		(newn->Next) = (temp->Next);
		(temp->Next->Prev) = newn;
		(temp->Next) = newn;
		(newn->Prev) = temp;
	}
}

void DeleteAtPostion(PPEmployee Head,PPEmployee Tail,int iPos)
{
	PEmployee temp = NULL;
	int iSize = 0,iCnt = 0;
	PEmployee Head2 = NULL;
	PEmployee Tail2 = NULL;

	iSize = Count(*Head,*Tail);

	if((iPos < 0) || (iPos > iSize))
	{
		return;
	}

	if(iPos == 1)
	{
		DeleteFirst(Head,Tail);
	}
	else if(iPos == iSize)
	{
		DeleteLast(Head,Tail);
	}
	else
	{
		/*if(iPos < (iSize/2))
		{
			//DeleteAtPosition from starting end
			//Maintain a pointer Head2
		}
		else if(iPos < (iSize/2))
		{
			//DeleteAtPosition from Terminating end
			//Maintain a pointer Tail2
		}*/
		temp = (*Head);
		for(iCnt=1;iCnt<(iPos-1);iCnt++)
		{
			temp = temp->Next;
		}

		temp->Next = temp->Next->Next;
		free(temp->Next->Prev);
		temp->Next->Prev=temp;
	}
}

/*
	SearchBySalary(conditions)
		1. Display salary of all employees same as input taken from the user.(for same salary)
		2. Display salary of all employees below input taken from user.(for less salary)
		3. Display salary of all employees above input taken from user.(for more salary)
*/

void SearchBySalary(PEmployee Head,PEmployee Tail,float fSal)
{
	do
	{
		if((Head->Salary) == fSal)
		{
			printf("\n|Employee id is : %d \t Employee Salary is : %0.2f|\n",Head->EmpId,Head->Salary);
		}
		else if(fSal <= 50000)
		{
			printf("\n|Employee id is : %d \t Employee Salary is : %0.2f|\n",Head->EmpId,Head->Salary);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);
}

void SearchGrtSalary(PEmployee Head,PEmployee Tail,float fSal)
{
	do
	{
		if((Head->Salary)>fSal)
		{
			printf("\n|Employee id is : %d \t Employee Salary is : %0.2f|\n",Head->EmpId,Head->Salary);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);
}

void SearchLesSalary(PEmployee Head,PEmployee Tail,float fSal)
{
	do
	{
		if((Head->Salary)<fSal)
		{
			printf("\n|Employee id is : %d \t Employee Salary is : %0.2f|\n",Head->EmpId,Head->Salary);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);
}

void SearchEqaSalary(PEmployee Head,PEmployee Tail,float fSal)
{
	do
	{
		if((Head->Salary)==fSal)
		{
			printf("\n|Employee id is : %d \t Employee Salary is : %0.2f|\n",Head->EmpId,Head->Salary);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);
}

void SearchByID(PEmployee Head,PEmployee Tail,int iID)
{
	int iFlag = 1;
	printf("\nSearching Employee by ID:\n");
	do
	{
		if((Head->EmpId) == iID)
		{
			iFlag++;
			printf("\n|Employee id is : %d \tEmployee Age is : %d \t Employee Salary is : %0.2f \t Employee Name is : %s|\n",Head->EmpId,Head->Age,Head->Salary,Head->Name);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	if(iFlag == 1)
	{
		printf("No Employee ID Found according to user input\n");
	}
}

float MinimumSalary(PEmployee Head,PEmployee Tail)
{
	float iMin = 0;
	iMin = Head->Salary;

	printf("\nSearching minimum salary of an Employee :\n");
	do
	{
		if((Head->Salary) < iMin)
		{
			iMin = (Head->Salary);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	return iMin;
}

float MaximumSalary(PEmployee Head,PEmployee Tail)
{
	float iMax = 0;
	iMax = Head->Salary;

	printf("\nSearching Maximum salary of an Employee :\n");
	do
	{
		if((Head->Salary) > iMax)
		{
			iMax = (Head->Salary);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	return iMax;
}

int MinimumAge(PEmployee Head,PEmployee Tail)
{
	int iMin = 0;
	iMin = Head->Age;

	printf("\nSearching minimum age of an Employee :\n");
	do
	{
		if((Head->Age) < iMin)
		{
			iMin = (Head->Age);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	return iMin;
}

int MaximumAge(PEmployee Head,PEmployee Tail)
{
	int iMax = 0;
	iMax = Head->Age;

	printf("\nSearching Maximum age of an Employee :\n");
	do
	{
		if((Head->Age) > iMax)
		{
			iMax = (Head->Age);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	return iMax;
}

BOOL Like(PEmployee Head,PEmployee Tail,char ch)
{
	int flag = 0;
	int iCnt = 0;
	printf("\nFinding Employee name with %c :\n",ch);
	do
	{
		if((Head->Name[0]) == ch)
		{
			flag = 1;
			iCnt++;
			printf("Employee Name is : %s\n",Head->Name);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	if(flag == 1)
	{
		printf("Total Employees found starting with letter %c are %d\n",ch,iCnt);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL Like1(PEmployee Head,PEmployee Tail,char ch)
{
	int flag = 0;
	int iCnt = 0;
	int i = 0 , j = 0;
	char FName[50] = {'\0'};

	printf("\nFinding Employee name with %c :\n",ch);
	do
	{
		while((Head->Name[i]) != 32)
		{
			FName[j] = Head->Name[i];
			i++;
			j++;
		}
		if(FName[j-1] == ch)
		{
			flag = 1;
			iCnt++;
			printf("Employee Name is : %s\n",Head->Name);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	if(flag == 1)
	{
		printf("Total Employees found ending with letter %c are %d\n",ch,iCnt);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void SearchByAge(PEmployee Head,PEmployee Tail,int iAge)
{
	do
	{
		if((Head->Age) == iAge)
		{
			printf("\n|Employee id is : %d \t Employee Age is : %d|\n",Head->EmpId,Head->Age);

		}
		Head = Head->Next;
	}while(Head != Tail->Next);
}

void SearchByName(PEmployee Head,PEmployee Tail,char *name)
{
	int i = 0,flag = 0;
	do
	{
		i = 0;
		while((Head->Name[i] != '\0') && (*name != '\0'))
		{
			if((Head->Name[i]) == *name)
			{
				i++;
				name++;
			}
			else
			{
				break;
			}
		}
		if(Head->Name[i] == *name)
		{
			flag++;
			printf("\n|Employee id is : %d \t Employee Name is : %s|\n",Head->EmpId,Head->Name);
		}
		Head = Head->Next;		
	}while(Head != Tail->Next);

	if(flag == 0)
	{
		printf("No Employee found according to the user input\n");
	}
}

void SearchByCity(PEmployee Head,PEmployee Tail,char *city)
{
	int i = 0,flag = 0;
	do
	{
		i = 0;
		while((Head->cCity[i] != '\0') && (*city != '\0'))
		{
			if((Head->cCity[i]) == *city)
			{
				i++;
				city++;
			}
			else
			{
				break;
			}
		}
		if(Head->cCity[i] == *city)
		{
			flag++;
			printf("\n|Employee id is : %d \t Employee Name is : %s \t Employee City is : %s|\n",Head->EmpId,Head->Name,Head->cCity);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	if(flag == 0)
	{
		printf("No Employee found with the same city\n");
	}
}

void SearchByDesignation(PEmployee Head,PEmployee Tail,char *cDesg)
{
	int i = 0,flag = 0;
	do
	{
		i = 0;
		while((Head->cDesignation[i] != '\0') && (*cDesg != '\0'))
		{
			if((Head->cDesignation[i]) == (*cDesg))
			{
				i++;
				cDesg++;
			}
			else
			{
				break;
			}
		}
		if(Head->cDesignation[i] == *cDesg)
		{
			flag++;
			printf("\n|Employee id is : %d \t Employee Name is : %s \t Employee Designation is : %s|\n",Head->EmpId,Head->Name,Head->cDesignation);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	if(flag == 0)
	{
		printf("No Employee found with the same designation\n");
	}
}

void SearchByGender(PEmployee Head,PEmployee Tail,char *gender)
{
	int i = 0,flag = 0;
	do
	{
		i = 0;
		while((Head->cGender[i] != '\0') && (*gender != '\0'))
		{
			if((Head->cGender[i]) == *gender)
			{
				i++;
				gender++;
			}
			else
			{
				break;
			}
		}
		if(Head->cGender[i] == *gender)
		{
			flag++;
			printf("\n|Employee id is : %d \t Employee Name is : %s \t Employee Gender is : %s|\n",Head->EmpId,Head->Name,Head->cGender);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	if(flag == 0)
	{
		printf("No Employee found with the same Gender\n");
	}
}

int main()
{
	PEmployee First = NULL;
	PEmployee Last = NULL;
	int iNo = 0,id = 0, letter = 0,letter1 = 0, iPlace = 0,age = 0,iAge = 0;
	int choice = 1, choice1 = 1, choice2 = 1;
	int iRet = 0,iRet3 = 0,iRet4 = 0,iRet5 = 0,iRet6 = 0;
	float iRet1 = 0.0,iRet2 = 0.0,salary = 0.0;
	char Name[50] = {'\0'}, cName[50] = {'\0'}, cName1[50] = {'\0'}, cName2[50] = {'\0'}, cName3[50] = {'\0'}; 
	char designation[50] = {'\0'}, gender[50] = {'\0'}, city[50] = {'\0'};
	char ch1 = '\0',ch2 = '\0';

	printf("\n-------------------------------------------------------------------------------------------------------------\n");
	printf("\n-------------------Employee Database Management System using Doubly Circular Linked List---------------------\n");

	while(choice) //while(choice != 0)//for better readability
	{
		printf("\n-------------------------------------------------------------------------------------------------------------\n");
		printf("\n1: Insert First Employee");
		printf("\n2: Insert Last Employee");
		printf("\n3: Insert Employee At Position");
		printf("\n4: Delete First Employee");
		printf("\n5: Delete Last Employee");
		printf("\n6: Delete Employee At Position");
		printf("\n7: Display the Employee Details of Employees in the Company");
		printf("\n8: Count number of Employees in a Company");
		printf("\n9: SearchBy");
		printf("\n10: Minimum Salary");
		printf("\n11: Maximum Salary");
		printf("\n12: Minimum Age");
		printf("\n13: Maximum Age");
		printf("\n14: Search Name With Starting letter");
		printf("\n15: Search Name With Endining letter");
		printf("\n0: Exit");

		printf("\n----------------------------------------------------------------\n");

		printf("\nEnter your choice\n");
		scanf("%d",&choice);

		printf("\n----------------------------------------------------------------\n");

		switch(choice)
		{
			case 1:
				printf("\n............Enter the Employee Details:...........\n");
				printf("\n1:Enter EMP_ID:\n");
				scanf("%d",&iNo);

				ch1 = '\0';
				scanf("%c",&ch1);//empty scanf
				printf("\n2:Enter Employee Name:\n");
				scanf("%[^'\n']s",Name);
				// "Manali Aundhkar\0"{'M','a'.......\0'};
				//fflush(stdin);

				printf("\n3:Enter Employee Age:\n");
				scanf("%d",&age);
				printf("\n4:Enter Employee Salary:\n");
				scanf("%f",&salary);
				
				ch1 = '\0';
				scanf("%c",&ch1);//empty scanf
				printf("\n5:Enter Employee Gender:\n");
				scanf("%[^'\n']s",gender);

				ch1 = '\0';
				scanf("%c",&ch1);//empty scanf
				printf("\n6:Enter Employee City:\n");
				scanf("%[^'\n']s",city);

				ch1 = '\0';
				scanf("%c",&ch1);//empty scanf
				fflush(stdin);
				printf("\n7:Enter Employee Designation:\n");
				scanf("%[^'\n']s",designation);
				fflush(stdin);
				
				InsertFirst(&First,&Last,iNo,Name,age,salary,gender,city,designation);
				break;

			case 2:
				printf("\n............Enter the Employee Details:...........\n");
				printf("\n1:Enter EMP_ID:\n");
				scanf("%d",&iNo);

				scanf("%c",&ch1);
				printf("\n2:Enter Employee Name:\n");
				scanf("%[^\n]s",Name);
				printf("\n3:Enter Employee Age:\n");
				scanf("%d",&age);
				printf("\n4:Enter Employee Salary:\n");
				scanf("%f",&salary);

				scanf("%c",&ch1);//empty scanf
				printf("\n5:Enter Employee Gender:\n");
				scanf("%[^'\n']s",gender);

				scanf("%c",&ch1);//empty scanf
				printf("\n6:Enter Employee City:\n");
				scanf("%[^'\n']s",city);

				scanf("%c",&ch1);//empty scanf
				printf("\n7:Enter Employee Designation:\n");
				scanf("%[^'\n']s",designation);
				scanf("%c",&ch1);//empty scanf

				InsertLast(&First,&Last,iNo,Name,age,salary,gender,city,designation);
				break;

			case 3:
				printf("\n............Enter the Employee Details:...........\n");
				printf("\n1:Enter EMP_ID:\n");
				scanf("%d",&iNo);

				scanf("%c",&ch1);//empty scanf
				printf("\n2:Enter Employee Name:\n");
				scanf("%[^\n]s",Name);
				printf("\n3:Enter Employee Age:\n");
				scanf("%d",&age);
				printf("\n4:Enter Employee Salary:\n");
				scanf("%f",&salary);
				printf("\nEnter Position:\n");
				scanf("%d",&iPlace);

				scanf("%c",&ch1);//empty scanf
				printf("\n5:Enter Employee Gender:\n");
				scanf("%[^'\n']s",gender);

				scanf("%c",&ch1);//empty scanf
				printf("\n6:Enter Employee City:\n");
				scanf("%[^'\n']s",city);

				scanf("%c",&ch1);//empty scanf
				printf("\n7:Enter Employee Designation:\n");
				scanf("%[^'\n']s",designation);
				scanf("%c",&ch1);//empty scanf

				InsertAtPosition(&First,&Last,iNo,Name,age,salary,gender,city,designation,iPlace);

				break;

			case 4:
				DeleteFirst(&First,&Last);
				break;

			case 5:
				DeleteLast(&First,&Last);
				break;

			case 6:
				printf("\n1:Enter EMP_ID:\n");
				scanf("%d",&iNo);
				printf("\nEnter Position:\n");
				scanf("%d",&iPlace);
				DeleteAtPostion(&First,&Last,iPlace);
				break;

			case 7:
				Display(First,Last);
				break;

			case 8:
				iRet = Count(First,Last);
				printf("The Count of Employees in the Linked List is: %d\n",iRet);
				break;

			case 9:
				printf("Select from Search By:");
				while(choice1)
				{
					printf("\n1. Search by Employee id");
					printf("\n2. Search by  Employee Name");
					printf("\n3. Search by  Employee City");
					printf("\n4. Search by  Employee Salary");
					printf("\n5. Search by  Employee Designation");
					printf("\n6. Search by  Employee Gender");
					printf("\n7. Search by  Employee Age");
					printf("\n0. Exit");

					printf("\nEnter your choice\n");
					scanf("%d",&choice1);

					switch(choice1)
					{
						case 1:
							printf("Enter Employee id you want to search\n");
							scanf("%d",&id);
							SearchByID(First,Last,id);
							break;
						
						case 2:
							scanf("%c",&ch1);//empty scanf
							printf("Enter Employee Name you want to search\n");
							scanf("%[^'\n']s",cName);
							SearchByName(First,Last,cName);
							break;
						
						case 3:
							scanf("%c",&ch1);//empty scanf
							printf("Enter Employee's City Name you want to search\n");
							scanf("%[^'\n']s",cName1);
							SearchByCity(First,Last,cName1);
							break;
						
						case 4:
								printf("Enter a salary and choice you want to search\n");
                                printf("Enter Employee Salary you want to search\n");
								scanf("%f",&salary);
								printf("1:Grater salaries amount than %f: \n",salary);
                                printf("2:Less salaries amount than %f: \n",salary);
                                printf("3:salaries amount Equal  to %f: \n",salary);
                                printf("0:exit\n");
								while(choice2)
                                {
                                    printf("\nEnter your choice\n");
					                 scanf("%d",&choice2);
								switch(choice2)
								{
                                     case 1:
                                     SearchGrtSalary(First,Last,salary);
                                     break;
                                     case 2:
                                     SearchLesSalary(First,Last,salary);
                                     break;
                                     case 3:
                                     SearchEqaSalary(First,Last,salary);
                                     break;
                                     case 0:
                                     break;
								}
                                }
								break;
						case 5:
							scanf("%c",&ch1);//empty scanf
							printf("Enter Employee's Designation you want to search\n");
							scanf("%[^'\n']s",cName2);
							SearchByDesignation(First,Last,cName2);
							break;
						
						case 6:
							scanf("%c",&ch1);//empty scanf
							printf("Enter Employee's Gender you want to search\n");
							scanf("%[^'\n']s",cName3);
							SearchByGender(First,Last,cName3);
							break;

						case 7:
								printf("Enter Employee Age you want to search\n");
								scanf("%d",&iAge);
								SearchByAge(First,Last,iAge);
								break;

						case 0:
							printf("\nThank You for SearchBy Operation\n");
							break;

						default:
							printf("\nWrong Choice\n");
							break;
					}
				}
				break;

			case 10:
				iRet1 = MinimumSalary(First,Last);
				printf("Minimum Salary of an Employee is %0.2f",iRet1);
				break;

			case 11:
				iRet2 = MaximumSalary(First,Last);
				printf("Maximum Salary of an Employee is %0.2f",iRet2);
				break;

			case 12:
				iRet3 = MinimumAge(First,Last);
				printf("Minimum Age of an Employee is %d",iRet3);
				break;

			case 13:
				iRet4 = MaximumAge(First,Last);
				printf("Maximum Age of an Employee is %d",iRet4);
				break;

			case 14:
				scanf("%c",&ch1);//empty scanf
				printf("Enter starting letter of Employee Name that you want to search :\n");
				scanf("%c",&letter);

				iRet5 = Like(First,Last,letter);
				if(iRet5 == FALSE)
				{
					printf("No Name found starting with letter %c\n",letter);
				}
				break;

			case 15:
				scanf("%c",&ch1);//empty scanf
				printf("Enter ending letter of Employee Name that you want to search :\n");
				scanf("%c",&letter1);

				iRet6 = Like1(First,Last,letter1);
				if(iRet6 == FALSE)
				{
					printf("No Name found ending with letter %c\n",letter1);
				}
				break;

			case 0:
				printf("\nThank You for using the Application\n");
				break;

			default:
				printf("\nWrong Choice\n");
				break;
		}
	}

	return 0;
}
