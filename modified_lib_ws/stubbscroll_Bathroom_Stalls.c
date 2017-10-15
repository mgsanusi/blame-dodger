#include <stdio.h>

/* min-heap! warning, 1-indexed, index 0 is unused */ 
/* heapn starts at 1 (number of elements is 0, +1) */ 
    
#define MAXH 1000003
int heap[MAXH];		/* heap value (on which it is sorted)  */
int heapn;			/* (number of elements in heap)+1 */
 
/* insert a new value to the heap */ 
/* warning, function will choke if heap is full */ 
void heapinsert(int val)
{
	int pos = heapn++;
	
	    /* change to val> for maxheap */ 
	    while (pos > 1 && val > heap[pos >> 1]) {
		heap[pos] = heap[pos >> 1];
		pos >>= 1;
	}
	heap[pos] = val;
}

 
/* remove a value from the heap and put it in *val,*id */ 
/* don't call if heap is empty! */ 
void heapremove(int *val)
{
	int pos = 1, next = 1, newval;
	*val = heap[1];
	newval = heap[--heapn];
	while ((pos << 1) <= heapn) {
		
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
		heap[pos] = heap[next];
		pos = next;
	}
	heap[pos] = newval;
}

 void solve()
{
	int n, k, v, v1, v2;
	scanf("%d %d", &n, &k);
	heapn = 1;
	heapinsert(n);
	while (k--) {
		heapremove(&v);
		v1 = v / 2;
		v2 = (v - 1) / 2;
		heapinsert(v1);
		heapinsert(v2);
		if (!k)
			printf("%d %d\n", v1, v2);
	}
}

 int main()
{
	int T, caseno = 1;
	scanf("%d", &T);
	while (T--)
		printf("Case #%d: ", caseno++), solve();
	return 0;
}


