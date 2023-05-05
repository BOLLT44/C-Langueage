#include <stdio.h>
#include <stdlib.h>

/*
	Node ����ü
*/
typedef struct Node
{
	int data;		// ��忡 ����� ������
	Node* next;		// ���� ��� �ּҰ�
};

/*
	Linked List�� �տ� �߰�

	- �տ��� �߰��ϴ� ���� ó������ ����ϴ� �� �ƴ�!!
*/
Node* add_first(Node* head, int value) 
{
	Node* p = (Node*)malloc(sizeof(Node));		// p��� ���� ���� ����

	p->data = value;	// p->data�� ������ ��(value) �ֱ�

	p->next = head;		// p->next�� head�� ����
	head = p;			// �������� head(�� ��)�� p


	return head;		// head ��ȯ
}

/*
	Linked List�� �ڿ� �߰�
*/
Node* add_last(Node* head, Node* pre, int value)
{
	Node* p = (Node*)malloc(sizeof(Node));		// p��� ���� ���� ����

	p->data = value;
	p->next = pre->next;	// p->next�� pre->next�� ����
	pre->next = p;			// �������� pre->next�� p��


	return head;	// head ��ȯ
}

/*
	�� �� ��� ����
*/
Node* del_first(Node* head)
{
	Node* remove;	// ������ ��带 ������ ����

	if (head == NULL)	// ���� head�� �̹� NULL �� �� NULL ��ȯ
	{
		return NULL;
	}

	remove = head;			// remove�� head
	head = remove->next;	// head�� remove->next (= �������� head�� ���� ���� ���� ���� ��. ���͵� �� �����Ͷ� �ּҷ� �Ѿ)

	free(remove);	// �����޸� ������(= head ������)


	return head;	// head ��ȯ
}

/*
	pre ���� ��� ����
*/
Node* del_next(Node* head, Node* pre)
{
	Node* remove;	// ������ ��带 ������ ����

	remove = pre->next;			// pre�� ���� ��带 �����ϱ� ���� remove�� pre->next�� ����
	pre->next = remove->next;	// ������ ������ �ڸ��� ���� ������ ������ ���� �༮�� ���� (remove�� ����Ű�� �� remove�� ���� ������ �ٲ�)

	free(remove);		// �����޸�(���� ���) ������


	return head;	// head ��ȯ
}

/*
	���ϴ� �κ��� ��� �ּ� ��ȯ
*/
Node* search_node(Node* head, int loop)
{
	Node* p = head;

	for (int q = 0; q < loop; q++)
	{
		if (p != NULL)
		{
			p = p->next;
		}
		else
		{
			return NULL;
		}
	}


	return p;
}

/*
	���Ḯ��Ʈ ���
*/
void print_list(Node* head)
{
	for (Node* p = head; p != NULL; p = p->next)	// p�� ���� ��� �� ���� ���� �Ǹ鼭 ���� ���� ���� ������(NULL) �ݺ�
	{
		printf("%d -> ", p->data);
	}

	printf("NULL \n");
}

/*
	���Ḯ��Ʈ�� ������ �߰�
*/
Node* add_linkedlist(Node* head)
{
	printf("\n\n");

	printf("����Ʈ�� �տ� �����͸� �߰��Ѵ� -> (1) / ����Ʈ�� �ڿ� �����͸� �߰��Ѵ� -> (2) \n> ");
	int input = 0, pre_data = 0, value = 0;
	scanf("%d", &input);

	if (input == 1)
	{

		printf("\n�߰��ϰ� ���� �����͸� �Է����ּ��� \n> ");
		scanf("%d", &value);

		head = add_first(head, value);

		printf("\n");
	}
	else
	{

		printf("\n");
		print_list(head);
		printf("\n���° ������(0���� ����)�� � �����͸� �������� �Է����ּ��� \n> ");
		scanf("%d %d", &pre_data, &value);

		Node* pre_node_num = search_node(head, pre_data);

		if (pre_node_num != NULL)
		{
			head = add_last(head, pre_node_num, value);

			printf("\n");
		}
		else
		{
			printf("\n�׵� �� �����ϴ�..? \n");
		}
	}


	return head;
}

/*
	���Ḯ��Ʈ�� ������ ����
*/
Node* del_linkedlist(Node* head)
{
	printf("\n\n");

	printf("����Ʈ�� �տ� �����͸� �����Ѵ� -> (1) / ����Ʈ�� �ڿ� �����͸� �����Ѵ� -> (2) \n> ");
	int input = 0, pre_data = 0;
	scanf("%d", &input);

	if (input == 1)
	{
		head = del_first(head);

		printf("\n");
	}
	else
	{

		printf("\n");
		print_list(head);
		printf("\n���° ������(0���� ����)�� ���� �����͸� ������ �ǰ���? \n> ");
		scanf("%d", &pre_data);

		Node* pre_node_num = search_node(head, pre_data);

		if (pre_node_num != NULL)
		{
			head = del_next(head, pre_node_num);

			printf("\n");
		}
		else
		{
			printf("\n�׵� �� �����ϴ�..? \n");
		}
	}


	return head;
}

int main()
{
	Node* head = NULL;

	while (1)
	{
		printf("\n�����͸� �Է��Ͻ� �ǰ���? (�� -> 1, �ƴϿ� -> 0) \n> ");
		int input = 0;
		scanf("%d", &input);

		if (input == 1)
		{
			head = add_linkedlist(head);
		}
		else
		{
			break;
		}
	}
	while (1)
	{
		printf("\n�����͸� �����Ͻ� �ǰ���? (�� -> 1, �ƴϿ� -> 0) \n> ");
		int input = 0;
		scanf("%d", &input);

		if (input == 1)
		{
			head = del_linkedlist(head);
		}
		else
		{
			break;
		}
	}

	printf("\n\n\n");
	print_list(head);


	return 0;
}