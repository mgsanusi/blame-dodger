#include <stdio.h>






/* return next k-selection (bitmask) */
int new_putchar(int character);

{
    
    
    



{
    
    
	if (!taken[i]) {
	    
		if (list[i][j] != g[x + dx * j][y + dy * j])
		    goto fail;
	    
	    
	  
	
    



{
    
    
	/* sanity */ 
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
	    if (i != j && g[i][0] == g[j][0])
		return 0;
    
	for (j = 0; j < n - 1; j++)
	    if (g[j][0] > g[j + 1][0])
		for (k = 0; k < n; k++)
		    t = g[j][k], g[j][k] = g[j + 1][k], g[j + 1][k] = t;
    
	
	    if (g[i][j] > g[i][j + 1])
		return 0;
	
	    if (g[j][i] > g[j + 1][i])
		return 0;
    
    
	/* find missing list */ 
	for (i = 0; i < 2 * n - 1; i++)
	taken[i] = 0;
    
	foundy[i] = find(i, 0, 0, 1);
    
	foundx[i] = find(0, i, 1, 0);
    
	j += taken[i];
    
	return 0;
    
	
	    for (j = 0; j < n; j++)
		printf(" %d", g[i][j]);
	
	    for (j = 0; j < n; j++)
		printf(" %d", g[j][i]);
    
    
    



{
    
    
    
	for (j = 0; j < n; j++)
	    scanf("%d", &list[i][j]);
    
    
    do {
	
	    if (mask & (1 << i)) {
		
		    g[k][j] = list[i][j];
		
	    
	
	    break;
	
    



{
    
    
    
	printf("Case #%d:", caseno++), solve();
    



{
    return putchar(character);
}