#include"..\Headers\Headers.h"

// ��ʼ��ջ 
Status initLStack(LinkStack *s){
	s->top = NULL;
	s->count = 0; // ʵʱ��¼Ԫ�ظ��� 
	return SUCCESS;
}

// �ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	return s->top == NULL ? SUCCESS : ERROR;
}

// �õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(isEmptyLStack(s) == SUCCESS){
		return ERROR; // �ж��Ƿ�Ϊ�� 
	}
	*e = s->top->data;
	return SUCCESS;
}

// ���ջ
Status clearLStack(LinkStack *s){
	if(s == NULL) return ERROR;
	LinkStackPtr p,q;
	p = s->top;
	while(p) { // ������ջ
		q = p;
		p = p->next; 
		free(q); // �ͷſռ� 
	}
	initLStack(s);
}

// ����ջ
Status destroyLStack(LinkStack *s){
	clearLStack(s); // ��պ��ͷ� 
	free(s);
    return SUCCESS;
}

// ���ջ����
Status LStackLength(LinkStack *s,int *length){
	if(isEmptyLStack(s) == SUCCESS){
		printf("\n������ҵ�Ǯ������~\n");
		system("pause");
		return SUCCESS; 
	} // �ж��Ƿ�Ϊ�� 
	*length = s->count;
	printf("\n��ջ�ĳ���Ϊ: %d\n", *length);
    system("pause");
	return SUCCESS;
}

// ��ջ
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr newNode = (LinkStack*)malloc(sizeof(StackNode)); 
	if(!newNode) {
		return ERROR;
	} // �ж��ڴ����ɹ��� 
	newNode->data = data;
	newNode->next = s->top;
	s->top = newNode; // ���¶��� 
	s->count++; // ����count
	return SUCCESS; 
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if(isEmptyLStack(s) == SUCCESS){
		return ERROR;
	}
	LinkStackPtr temp = s->top;
	*data = temp->data;
	s->top = s->top->next; // ���¶��� 
	free(temp);
	s->count--; // ����count
	return SUCCESS; 
}

//��ӡջ
Status print(LinkStack* s) {
	LinkStackPtr p = s->top;
	printf("\nLinkStack:");
	while(p){
		printf("\n\t\t%d\n",p->data);
		p = p->next;
	} 
	return SUCCESS;
}

//��ӡ�˵�
void Userwelcome(){
	system("cls");
	printf("*********************************************\n");
	printf("**    ��ӭ����517-QG֮��-WeekTwo-��ջվ    **\n");
	printf("**-----------------------------------------**\n");
	printf("**     1--��ջ             2--��ջ         **\n");
	printf("**     3--��ȡջ��Ԫ��     4--�жϿ�ջ     **\n");
	printf("**     5--����ջ����       6--���ջ       **\n");
	printf("**     7--����ջ           8--��ӡջ       **\n");
	printf("**                0--�˳�����              **\n"); 
	printf("*********************************************\n");
	printf("\n���������������Ӧ���֣�(����������ֽ�ȡ��һ������)");
} 

int main(){
	LinkStack stack;
    ElemType data;
    char choice;
    Status status;
    int length;

    initLStack(&stack); // ��ʼ��ջ 

	system("mode can cols=116 lines=35");//���ô��ڴ�С 
	system("color f0");//������ɫ 
    while(1){
        Userwelcome();//�����û�ҳ�� 
		fflush(stdin);//����ȡ���з� 
		choice = getchar();//�û�ѡ�� 
        while(getchar()!='\n');//����getchar�������ַ�
        system("cls"); // ���� 
        
        switch (choice){
        	case '1':
            	printf("��������Ҫ��ջ������: (������ȡ��������)");
            	scanf("%d", &data);
            	status = pushLStack(&stack, data);
            	if (status == SUCCESS){
               		printf("\n��ջ�ɹ�����\n");
            	}
            	else{
                printf("\n��ջʧ����������\n");
            	}
            	system("pause");
            	break;
        	case '2':
            	status = popLStack(&stack, &data);
            	if (status == SUCCESS){
                	printf("\n��ջ�ɹ�������ջԪ��Ϊ: %d\n", data);
            	}
            	else{
                printf("\n��ջʧ�ܣ�������ҵ�Ǯ������~\n");
            	}
            	system("pause");
            	break;
        	case '3':
            	status = getTopLStack(&stack, &data);
            	if (status == SUCCESS){
                	printf("\nջ��Ԫ��Ϊ: %d\n", data);
            	}
            	else{
                	printf("\n�Ҳ���ջ����������������ɾ�~\n");
            	}
            	system("pause");
            	break;
        	case '4':
            	if (isEmptyLStack(&stack) == SUCCESS){
                	printf("\n������ҵ�Ǯ������~\n");
            	}
            	else{
                	printf("\n���ǿյ�:)\n");
            	}
            	system("pause");
            	break;
        	case '5':
            	LStackLength(&stack, &length);
            	break;
        	case '6':
            	clearLStack(&stack);
            	printf("\n��ճɹ�~\n");
            	system("pause");
            	break;
        	case '7':
            	destroyLStack(&stack);
            	printf("\n���ٳɹ�~\n");
            	system("pause");
            	break;
        	case '8':
            	status = print(&stack);
            	system("pause");
            	break;
        	case '0':exit(0);
        	default:{
				printf("\nû�����ѡ��~\n");
            	system("pause");
			}
		}
    } 
    return 0;
} 
