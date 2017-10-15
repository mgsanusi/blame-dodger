#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
void generateFilename(char *out, char *fp, char *add)
{
	char *y;
	sprintf(out, "%s", fp);
	for (y = (out + strlen(out)) - 1; y >= out; y--) {
		if ((*y) == '/')
			break;
		if ((*y) == '\\')
			break;
		if ((*y) == '.') {
			*y = '\0';
			break;
		}
	}
	sprintf(out + strlen(out), "%s", add);
}

typedef struct ST_NODE ST_NODE;
struct ST_NODE {
	int n;
	int parentNum;
	int flg;
	ST_NODE **parent;
};
void Main(int argc, char *argv[])
{
	char fnameO[1000];
	FILE *fpIndex;
	FILE *fpO;
	int n;
	int s;
	int temp;
	ST_NODE *node;
	ST_NODE *nodeP;
	ST_NODE *nodeP2;
	ST_NODE **nodeTmp;
	ST_NODE **nodePp1;
	ST_NODE **nodePp2;
	ST_NODE **nodePp3;
	int value;
	generateFilename(fnameO, argv[1], "_out.txt");
	fpIndex = fopen(argv[1], "r");
	fpO = fopen(fnameO, "w");
	node = (ST_NODE *) calloc(2000, sizeof(ST_NODE));
	nodeTmp = (ST_NODE **) calloc(2000, sizeof(ST_NODE *));
	fscanf(fpIndex, "%d", &s);
	for (n = 1; n <= s; n++) {
		fprintf(stderr, "Case #%d/%d...", n, s);
		fscanf(fpIndex, "%d", &temp);
		for (nodeP = node; nodeP < (node + temp); nodeP++) {
			nodeP->n = (nodeP - node) + 1;
		}
		for (nodeP = node; nodeP < (node + temp); nodeP++) {
			fscanf(fpIndex, "%d", &nodeP->parentNum);
			nodeP->parent =
			    (ST_NODE **) calloc(nodeP->parentNum,
						sizeof(ST_NODE *));
			for (nodePp1 = nodeP->parent;
			     nodePp1 < (nodeP->parent + nodeP->parentNum);
			     nodePp1++) {
				fscanf(fpIndex, "%d", &value);
				*nodePp1 = (node + value) - 1;
			}
		}
		for (nodeP = node; nodeP < (node + temp); nodeP++) {
			for (nodeP2 = node; nodeP2 < (node + temp); nodeP2++) {
				nodeP2->flg = 0;
			}
			memset(nodeTmp, 0, 2000 * (sizeof(ST_NODE *)));
			nodePp1 = nodeTmp;
			*nodePp1 = nodeP;
			nodePp1++;
			for (nodePp2 = nodeTmp; (*nodePp2) != 0; nodePp2++) {
				for (nodePp3 = (*nodePp2)->parent;
				     nodePp3 <
				     ((*nodePp2)->parent +
				      (*nodePp2)->parentNum); nodePp3++) {
					if ((*nodePp3)->flg)
						break;
					(*nodePp3)->flg = 1;
					*nodePp1 = *nodePp3;
					nodePp1++;
				}
				if (nodePp3 !=
				    ((*nodePp2)->parent +
				     (*nodePp2)->parentNum))
					break;
			}
			if ((*nodePp2) != 0)
				break;
		}
		if (nodeP == (node + temp)) {
			fprintf(fpO, "Case #%d: No\n", n);
		} else {
			fprintf(fpO, "Case #%d: Yes\n", n);
		}
		for (nodeP = node; nodeP < (node + temp); nodeP++) {
			free(nodeP->parent);
		}
		fprintf(stderr, "finish!!\n");
	}
	free(node);
	fclose(fpIndex);
	fclose(fpO);
}
