/* common *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>

void GenerateFilename(char* out, char* in, char* add){
	char* p;
	sprintf(out, "%s", in);
	for(p=out+strlen(out)-1; p>=out; p--){
		if(*p=='/' )break;
		if(*p=='\\')break;
		if(*p=='.' ){*p='\0'; break;}
	}
	sprintf(out+strlen(out), "%s", add);
}
/******************************************************************************/

int sort1(const void* data1, const void* data2){
	double* I1 = (double*)data1;
	double* I2 = (double*)data2;

	if(I1[1]>I2[1]) return 1;
	if(I1[1]<I2[1]) return -1;
	return 0;
}

int sort0(const void* data1, const void* data2){
	double* I1 = (double*)data1;
	double* I2 = (double*)data2;

	if(I1[0]>I2[0]) return 1;
	if(I1[0]<I2[0]) return -1;
	return 0;
}


void main(int argc, char* argv[]){
	char fname_o[_MAX_PATH];
	FILE* fp_i;
	FILE* fp_o;
	int No;
	int ii;
	int jj;

	int T;
	int N;
	double S[200][3];
	double X;
	double Total;

	GenerateFilename(fname_o, argv[1], "_out.txt");
	fp_i = fopen(argv[1], "r");
	fp_o = fopen(fname_o, "w");

	fscanf(fp_i, "%d", &T);
	for(No=1; No<=T; No++){
		fprintf(stderr, "Case #%d/%d...", No, T);
		fscanf(fp_i, "%d", &N);
		X=0;
		for(ii=0; ii<N; ii++){
			fscanf(fp_i, "%lf", &(S[ii][1]));
			S[ii][0] = ii;
			S[ii][2] = 0.0;
			X+=S[ii][1];
		}

		qsort(S, N, sizeof(double)*3, sort1);
		Total = X;
		for(ii=1; ii<N; ii++){
			if(Total > (S[ii][1]-(S[0][1]+S[0][2]))*ii){
				for(jj=0; jj<ii; jj++){
					Total -= S[ii][1]-(S[jj][1]+S[jj][2]);
					S[jj][2] += S[ii][1]-(S[jj][1]+S[jj][2]);
				}
			}else{
				for(jj=0; jj<ii; jj++){
					S[jj][2] += Total/(double)ii;
				}
				Total = 0.0;
				break;
			}
		}
		if(Total>0){
			for(ii=0; ii<N; ii++){
				S[ii][2] += Total/(double)N;
			}
		}

		qsort(S, N, sizeof(double)*3, sort0);

		fprintf(fp_o, "Case #%d:", No);
		for(ii=0; ii<N; ii++){
			fprintf(fp_o, " %.6lf", 100*S[ii][2]/X);
		}
		fprintf(fp_o, "\n");

		fprintf(stderr, "finish!!\n");
	}

	fclose(fp_i);
	fclose(fp_o);
}
