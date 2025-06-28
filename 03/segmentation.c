#include <stdio.h>

int main(){
	int segment_number;
	int segment_limit; 
	int base_address;
	int offset;
	printf("%s", "Enter segment number: ");
	scanf("%d", &segment_number);
    printf("%s", "Enter base address: ");
    scanf("%d", &base_address);
    printf("%s", "Enter segment limit: ");
    scanf("%d", &segment_limit);
    printf("%s", "Enter offset value: ");
    scanf("%d", &offset);

    if (offset<=segment_limit){
    	int physical_address;
    	physical_address=offset+base_address;
    	printf("The physical address is %d\n", physical_address);
    }

    else
    	printf("%s", "Invalid input. Offset cannot exceed segment limit. Try again :)\n");
    

}