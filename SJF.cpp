#include <stdio.h>
#include <stdlib.h>
 
typedef struct process {
    int p_time;
    int stime;
    int runtime;
    int ftime;
    
    struct process* next;
} process;
 
void SJF(process* head){
    process* current, *next, *min;
    int time = 0;
    int stime=0;
    int runtime;
    int ftime;
 
    if (head == NULL)
        return;
 
    current = head;
    while(current != NULL){
        min = current;
        next = current->next;
        while(next != NULL){
            if(next->p_time < min->p_time)
                min = next;
            next = next->next;
        }
        
        	time=time+min->p_time;
        	printf("进程完成时间%d：\n",time);
        
		
 
        
        if(min == current) {
            if(min->next != NULL)
                current = min->next;
            else
                current = NULL;
        } else {
            if(min->next != NULL) {
                current->next = min->next;
                min->next = current;
                current = min;
            } else {
                current->next = min;
                current = min;
                current->next = NULL;
            }
        }
 
        min = current;
        next = current->next;
    }
}
 
int main(){
    process* head = NULL;
    process* current;
    int n, i,name, p_time,runtime,ftime;
 
    printf("请输入总进程数: ");
    scanf("%d", &n);
 
    
    for(i =1; i<=n; i++){
	printf("请输入第%d个进程的名 运行时间:\n",i);
        scanf("%s%d",name,&p_time);
        current = (process*)malloc(sizeof(process));
        current->p_time = p_time;
        current->next = head;
        head = current;
    }
    
		
 
    SJF(head);
    return 0;
}

