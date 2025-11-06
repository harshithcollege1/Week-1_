#include <stdio.h>
# define Max 5
int queue[Max];
int item;
int front=-1, rear=-1;
void insert(){
    if(front==0 && rear == Max-1 || (rear+1)% Max == front){
        printf("Queue Overflow!");
    }
    else{
        if(front == -1 && rear ==-1){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear+1) % Max;
        }
        printf("Enter your element to insert :");
        scanf("%d",&item);
        queue[rear] = item;
    }
}
void delete(){
    if(front == -1){
        printf("Queue Underflow!");
    }
    else{
        printf("Deleted %d",queue[front]);
        if(rear == front){
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)% Max;
        }
    }
}
void display(){
    if(front == -1){
        printf("Queue is Empty!");
    }
    else{
        printf("Circular Queue elements :");
        int i = front;
        while(1){
            printf("%d",queue[i]);
            if(i = rear) break;
            i = (i+1)% Max;
        }
        printf("\n");
    }
}

int main(){
    int choice;
    do{
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4 :
            printf("Exiting...\n");
            break;
        default :
            printf("Invalid Choice!");
        }
    }while(choice != 4);
    return 0;
}
