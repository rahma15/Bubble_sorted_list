#include <stdio.h>
#include <stdlib.h>


typedef struct list { int data ; struct list *next ;} list ;
int is_empty (const list *l ){return (l==NULL) ; } 
struct list *head, *tail = NULL;  
 
//create list with the head "first element"
list* create_list(int d)
{

    list *head = malloc(sizeof(list)) ; 
    head -> data = d ; 
    head ->next = NULL ; 
    return head ; 

}

// create the rest of the list with allocating memory to the rest of list and fill it with data  
list* add_to_front(int d , list* h)
{

    //list* head = create_list(d) ; (not a comment) 
    
    list *node = malloc(sizeof(list)) ; 
        node -> data = d ; 
        node ->next = h ; 
        return node ; 
}

// make the list to an array to better visualize it  
list* array_of_list(int d[] , int size )
{
    list* head  ;
    head = create_list(d[0]) ;
    //list* node ; (not a comment)
    int i ; 
    for (i = 1 ; i < size ; i++)
    {
        head = add_to_front (d[i], head) ; 
    } 
    return head ; 
}


//print the first list and separate it with "|"
void print_list (list *h , char *title)
{
    printf("%s\n" , title) ; 
    while (h != NULL)
    {
        printf("%d |" , h->data ) ; 
        h = h->next ;
    }
}

//swap() will swap the given two nodes  
void swap(list *node1, list *node2){  
        //Swaps the next nodes of node1 and node2  
        int temp = node1->data;   
        node1->data = node2->data;   
        node2->data = temp;      
}  

// In the function of bubble sorted list , we will create two lists the first ptr to do a condition on so that 
// the function will do iteration until all the list is sorted and ptr1 to save the list h so that 
// when we compare two data in the nodes it will be recursive 
void bubble_sorted_list(list *h )
{ int a ,b ,swapped; 
struct list *ptr = NULL;
struct list *ptr1 ;
   // list *head ; 
     if (h == NULL)
        return;
        
   do
        {swapped =0 ;
        ptr1 = h;
        while (ptr1->next != ptr)
            {a = ptr1 ->data  ;
            b = ptr1-> next-> data ;
            if (a > b)  
            {
                swap(ptr1, ptr1->next);
                swapped = 1 ; 
            }
            ptr1 = ptr1->next ; }
        ptr = ptr1;}
    while (swapped);
}

// print the sorted list with rows of 5 and each data is separated with "|"
void printList_sorted(struct list *start)
{
    struct list *temp = start;
    int i = 0, j=0 ; 
    printf("\n");
    while (temp!=NULL){
        for ( j =0 ; j<20 ;){
            
            for ( i =0 ; i<5 ;){
                printf("%d |", temp->data);
                temp = temp->next;
                i++;}  
            printf("\n") ;
            j++;
        }
    }
}
  
int main () 
{
    // create the head and initialize it to null 
    list *head = NULL ; 
    int data[100] , i   ; 
    // create the array of data with random number between 0 and 999 
    for (i=0 ; i<100 ; i++)
    {
        data[i] = rand()%1000 ;
        printf("%d |" , data[i]) ;
    }
    // function call 
    head = array_of_list(data, 100) ; 
    print_list(head , "element list ") ; 
    printf("\n\n") ; 
    printf("OK\n") ;
    bubble_sorted_list(head) ; 
    printList_sorted(head) ; 
    printf("OK") ;
    return 0 ; 
}