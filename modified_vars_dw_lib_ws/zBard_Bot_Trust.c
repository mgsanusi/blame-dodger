#include <stdio.h>
char robotId[100];
int robotPts[100];
int Main(void)
{
    int first_iteration;
    int jt = 0;
    int c = 0;
    long j = 0;
    long currentAns = 0;
    int numTest = 0;
    int currNumPts = 0;
    int currPointer = 0;
    int roboLocation;
    int robbLocation;
    scanf("%d", &numTest);
    for (jt = 0; jt < numTest; jt++) {
	scanf("%d", &currNumPts);
	for (j = 0; j < currNumPts; j++) {
	    scanf(" %c", &robotId[j]);
	    scanf(" %d", &robotPts[j]);
	}
	currentAns = 0;
	currPointer = 0;
	roboLocation = 1;
	robbLocation = 1;
	j = 0;
	while (1) {
	    if (currPointer == currNumPts) {
		currentAns = j;
		printf("Case #%d: %ld\n", jt + 1, currentAns);
		break;
	    }
	    if (robotId[currPointer] == 'O') {
		if (robotPts[currPointer] < roboLocation)
		    roboLocation--;
		else if (robotPts[currPointer] > roboLocation)
		    roboLocation++;
		else if (robotPts[currPointer] == roboLocation) {
		    robotPts[currPointer] = 0;
		    currPointer++;
		}
		for (c = currPointer;
		     (robotId[c] == 'O') && (c != currNumPts); c++);
		if (c != currNumPts) {
		    if (robotPts[c] < robbLocation)
			robbLocation--;
		    else if (robotPts[c] > robbLocation)
			robbLocation++;
		}
	    } else {
		if (robotPts[currPointer] < robbLocation)
		    robbLocation--;
		else if (robotPts[currPointer] > robbLocation)
		    robbLocation++;
		else if (robotPts[currPointer] == robbLocation) {
		    robotPts[currPointer] = 0;
		    currPointer++;
		}
		for (c = currPointer;
		     (robotId[c] == 'B') && (c != currNumPts); c++);
		if (c != currNumPts) {
		    if (robotPts[c] < roboLocation)
			roboLocation--;
		    else if (robotPts[c] > roboLocation)
			roboLocation++;
		}
	    }
	    j++;
	}
    }
    return 1;
}
