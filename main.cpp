#include <iostream>
using namespace std;

	bool check = true;

struct DoubleList {
string data; 				// value field
DoubleList *next; 
DoubleList *prev; 
};
DoubleList *head; 

void AddList(string value){
	DoubleList *node=new DoubleList; //создание нового элемента
	node->data=value; //присвоение элементу значения
//	if(head->data == "\0"){
//		return;
//	}
	if (head==NULL){
		node->next=node; //установка указателя next
		node->prev=node; //установка указателя prev
		head=node; //определяется голова списка
	//	cout<<"\nElement was added.\n\n";
	}
	else{
		DoubleList *p=head;
	//	for(int i=position; i>1; i--) p=p->next;
		(p->prev)->next=node;
		node->prev=p->prev;
		node->next=p; //добавление элемента
		p->prev=node;
	//	cout<<"\nElement was added.\n\n";
	}
//	cout<<"\nElement was added.\n\n";
}

void outputList(){
	if (head->data =="\0" && head->next == head->prev){
		cout<<"List is empty\n";
		check=false;
		return;
	} 
	else
	{
		DoubleList *a=head;
		cout<<"\n Elements of list: ";
		do{
		cout<<a->data<<" ";
		a=a->next;
		} while(a!=head); cout<<"\n\n";
	}
}

void analyzeString (){
	DoubleList *p = head;
	DoubleList *d;
	string mid, result;
	char begin;
	begin = (head->data)[0];
	p=p->next;
	while (p->next != head->next){
		if (p->data[0] != begin){	
			// changing of every char element 'a' on 'o'
			mid = p->data;
			for (int i = 0; i <= mid.length(); i++){
				if (mid[i] != 'a' && mid[i] != 'o'){
				//	mid.erase(i,1);
				//	cout << mid.substr(i, 1) << endl;
					result+=mid.substr(i, 1);
				}
			}
			cout << result << " ";
			result = "\0";
		}
		p=p->next;
	}
}

void deletingFirst (){
	DoubleList *p = head;
	DoubleList *d;
	string mid, result;
	string begin;
	begin = (head->data);
	p=p->next;
	while (p->next != head->next){
		if (p->data != begin){	
			
			cout << p->data << " ";
			result = "\0";
		}
		p=p->next;
	}
}


int main(){
	string input;
	string middle;
	int mm = 0, cs = 0;
	cout << "Welcome to my application with using of list, please, write your words: " << endl;
    getline(cin, input);
	for (int a = 0; a <= input.length(); a++){
		if (input[a] != '\0'){
			if(input[a] == ' ' || input[a]=='.'){
				if (mm == 0){
					middle = input.substr(cs, a);
					AddList(middle);
				}
				else{
					middle = input.substr(cs+1, a-cs-1);
					AddList(middle);
				}
			mm++;
			cs = a;
			}
			if(input[a] == '.'){
				break;
			}
		}
		else{
			cout << "String does not exist dot element. ERROR!" << endl;
			return 403;
		}
		
	}
	outputList();
	cout << endl;
	if (check){
		cout << "Elements of the list that satisfy the conditions: ";
		analyzeString();
	}
	else{
		cout << "This list is empty, so elements of this list don't' satisfy the conditions. " << endl;
	}
	cout << endl;
	if (check){
		cout << "String without word that such as first: ";
		deletingFirst();
	}
	else{
		cout << "This list is empty, so elements of this list don't' satisfy the conditions. " << endl;
	}
	return 1;
}
