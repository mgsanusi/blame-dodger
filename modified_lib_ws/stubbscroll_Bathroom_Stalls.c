#include <stdio.h>

/* min-heap! warning, 1-indexed, index 0 is unused */ 
/* heapn starts at 1 (number of elements is 0, +1) */ 
    
#define MAXH 1000003



/* insert a new value to the heap */ 
/* warning, function will choke if heap is full */ 
void heapinsert(int val)
{
	
	
	    /* change to val> for maxheap */ 
	    while (pos > 1 && val > heap[pos >> 1]) {
		
		
	
	



/* remove a value from the heap and put it in *val,*id */ 
/* don't call if heap is empty! */ 
void heapremove(int *val)
{
	
	
	
	
		
		    /* take lowest of left and right children */ 
		    if ((pos << 1) == heapn)
			next = pos << 1;
		
		    /* change to <heap[...] for maxheap */ 
		    else
			next =
			    (pos << 1) + (heap[pos << 1] <
					  heap[(pos << 1) + 1]);
		
		    /* change to <=newval for maxheap */ 
		    if (heap[next] <= newval)
			break;
		
		
	
	



{
	
	
	
	
	
		
		
		
		
		
		
			printf("%d %d\n", v1, v2);
	



{
	
	
	
		printf("Case #%d: ", caseno++), solve();
	


