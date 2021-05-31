#include <Windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct Node {
	int value;
	Node* next;
};

void addToList(struct Node* List, int X) {
	Node* current = new Node;
	current->value = X;
	current->next = nullptr;
	int size = List->value + 1;
	List->value = List->value + 1;
	for (int i = 1; i < size; ++i) List = List->next;
	List->next = current;
}

Node* createList() {
	Node* current = new Node;
	current->value = 0;
	current->next = nullptr;
	return current;
}

int getByIndex(struct Node* List, int x) {
	for (int i = 0; i <= x - 1; ++i) List = List->next;
	return List->value;
}

void showList(struct Node* List) {
	int size = List->value;
	List = List->next;
	cout << "List(" << size << "):";
	for (int i = 0; i < size; ++i) {
		cout << ' ' << List->value;
		List = List->next;
	}
	cout << endl;
}

void deleteElement(struct Node* List, int index) {
	List->value = List->value - 1;
	for (int i = 1; i < index; ++i) {
		List = List->next;
	}
	Node* TempList = List;
	List = List->next;
	TempList->next = List->next;
	delete List;
}

int findFirst(struct Node* List, int x) {
	int size = List->value;
	List = List->next;
	for (int i = 1; i <= size; ++i) {
		if (List->value == x) return i;
		List = List->next;
	}
	return 0;
}

void sortList(struct Node* List) {
	Node* TempList1, * TempList2;
	bool Sorted = false;
	int size = List->value;
	while (!Sorted) {
		Sorted = true;
		TempList1 = List;
		for (int i = 1; i < size; ++i) {
			TempList1 = TempList1->next;
			TempList2 = TempList1->next;
			if (TempList1->value > TempList2->value) {
				swap(TempList1->value, TempList2->value);
				Sorted = false;
			}
		}
	}
}

void placePos(struct Node* List, int x) {
	Node* TempList, * current = new Node;
	current->value = x;
	int size = List->value + 1;
	List->value = size;
	TempList = List;
	List = List->next;
	for (int i = 1; i < size && List->value < x; ++i) {
		TempList = List;
		List = List->next;
	}
	TempList->next = current;
	current->next = List;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 0, temp = -1;
	Node* List = createList();

	while (temp != '8') {
		showList(List);
		cout << "1|Add Element" << endl;
		cout << "2|Add Element (Force)" << endl;
		cout << "3|Delete Element (Index)" << endl;
		cout << "4|Delete Element (Element)" << endl;
		cout << "5|Find Index" << endl;
		cout << "6|Sort" << endl;
		cout << "7|Clear" << endl;
		cout << "8|Exit" << endl;
		cout << "Press Key...";
		temp = _getch();
		system("cls");
		showList(List);

		switch (temp)
		{
		case '1':
			cout << "Enter element=";
			cin >> temp;
			if (findFirst(List, temp)) {
				cout << "Error" << endl;
				cout << "Press any key...";
				_getch();
				system("cls");
				temp = 0;
				break;
			}
			placePos(List, temp);
			cout << "Element " << temp << " added!" << endl;
			cout << "Press any key...";
			_getch();
			system("cls");
			temp = 0;
			break;
		case '2':
			cout << "Enter element=";
			cin >> temp;
			if (findFirst(List, temp)) {
				cout << "Error!" << endl;
				cout << "Press any key...";
				_getch();
				system("cls");
				temp = 0;
				break;
			}
			addToList(List, temp);
			cout << "Element " << temp << " added!" << endl;
			cout << "Press any key...";
			_getch();
			system("cls");
			temp = 0;
			break;
		case '3':
			if (List->value == 0) {
				cout << "Nothing there!" << endl << "Press any key...";
				_getch();
				system("cls");
				break;
			}
			cout << "Enter number of element (1-" << List->value << ")=";
			cin >> temp;
			if (temp < 1 || temp > List->value) {
				cout << "Wrong index!" << endl;
				cout << "Press any key...";
				_getch();;
				system("cls");
				break;
			}
			deleteElement(List, temp);
			cout << "Element deleted!" << endl;
			cout << "Press any key...";
			_getch();
			system("cls");
			temp = 0;
			break;
		case '4':
			if (List->value == 0) {
				cout << "Nothing there!" << endl << "Press any key...";
				_getch();
				system("cls");
				break;
			}
			cout << "Enter element=";
			cin >> temp;
			if (!findFirst(List, temp)) {
				cout << "Can't find!" << endl;
				cout << "Press any key...";
				_getch();
				system("cls");
				break;
			}
			deleteElement(List, findFirst(List, temp));
			cout << "Element deleted!" << endl;
			cout << "Press any key...";
			_getch();
			system("cls");
			temp = 0;
			break;
		case '5':
			cout << "Enter element=";
			cin >> temp;
			if (findFirst(List, temp)) cout << "First index: " << findFirst(List, temp);
			else cout << "Элементов не найденно!";
			cout << "Press any key...";
			_getch();
			system("cls");
			temp = 0;
			break;
		case '6':
			sortList(List);
			cout << "Sorted!" << endl;
			cout << "Press any key...";
			_getch();
			system("cls");
			break;
		case '7':
			for (int i = List->value; i > 0; --i) deleteElement(List, 1);
			cout << "Cleared!" << endl;
			cout << "Press any key...";
			_getch();
			system("cls");
			break;
		default:
			system("cls");
			break;
		}
	}
}
