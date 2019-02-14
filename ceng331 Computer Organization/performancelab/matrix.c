// C program to multiply two square matrices. 
#include <stdio.h> 
#define N 16 

// This function multiplies mat1[][] and mat2[][], 
// and stores the result in res[][] 
void multiply(int *src, int *src2, int *dst, int dim) 
{ 
/*	int i, j, k,jdi,kd,jdk,d,jd,kdi;
	d=dim-8;
	for(j = 0; j<dim; j++){
		jd = j*dim;
		
		for(i=0; i< d; i+=8){
			jdi = jd + i;
			dst[jdi] = 0;
			dst[jdi+1] = 0;
			dst[jdi+2] = 0;
			dst[jdi+3] = 0;
			dst[jdi+4] = 0;
			dst[jdi+5] = 0;
			dst[jdi+6] = 0;
			dst[jdi+7] = 0;


			
			for(k = 0; k<dim; k++ ){
				kd = k*dim;
				jdk = jd + k;
				kdi = kd + i;
				dst[jdi] += src[jdk]*src2[kdi];
				dst[jdi+1] += src[jdk]*src2[kdi+1];
				dst[jdi+2] += src[jdk]*src2[kdi+2];
				dst[jdi+3] += src[jdk]*src2[kdi+3];
				dst[jdi+4] += src[jdk]*src2[kdi+4];
				dst[jdi+5] += src[jdk]*src2[kdi+5];
				dst[jdi+6] += src[jdk]*src2[kdi+6];
				dst[jdi+7] += src[jdk]*src2[kdi+7];

				


			}

			
		}
		for(;i<dim;i++){
			jdi = jd + i;
			dst[jdi] = 0;
			for(k = 0; k<dim; k++ ){
				jdk = jd + k;
				dst[jdi] += src[jdk]*src2[k*dim+i];

		}
	}
}

*/


	int i, j, k,jdi,kd,jdk,d,jd,kdi;
	d=dim-32;
	for(j = 0; j<dim; j+=2){
		jd = j*dim;

		
		for(i=0; i< d; i+=32){
			jdi = jd + i;
			dst[jdi] = 0;
			dst[jdi+1] = 0;
			dst[jdi+2] = 0;
			dst[jdi+3] = 0;
			dst[jdi+4] = 0;
			dst[jdi+5] = 0;
			dst[jdi+6] = 0;
			dst[jdi+7] = 0;
			jdi+=8;
			dst[jdi] = 0;
			dst[jdi+1] = 0;
			dst[jdi+2] = 0;
			dst[jdi+3] = 0;
			dst[jdi+4] = 0;
			dst[jdi+5] = 0;
			dst[jdi+6] = 0;
			dst[jdi+7] = 0;
			jdi+=8;
			dst[jdi] = 0;
			dst[jdi+1] = 0;
			dst[jdi+2] = 0;
			dst[jdi+3] = 0;
			dst[jdi+4] = 0;
			dst[jdi+5] = 0;
			dst[jdi+6] = 0;
			dst[jdi+7] = 0;
			jdi+=8;
			dst[jdi] = 0;
			dst[jdi+1] = 0;
			dst[jdi+2] = 0;
			dst[jdi+3] = 0;
			dst[jdi+4] = 0;
			dst[jdi+5] = 0;
			dst[jdi+6] = 0;
			dst[jdi+7] = 0;

			jdi = jd + i +dim;
			dst[jdi] = 0;
			dst[jdi+1] = 0;
			dst[jdi+2] = 0;
			dst[jdi+3] = 0;
			dst[jdi+4] = 0;
			dst[jdi+5] = 0;
			dst[jdi+6] = 0;
			dst[jdi+7] = 0;
			jdi+=8;
			dst[jdi] = 0;
			dst[jdi+1] = 0;
			dst[jdi+2] = 0;
			dst[jdi+3] = 0;
			dst[jdi+4] = 0;
			dst[jdi+5] = 0;
			dst[jdi+6] = 0;
			dst[jdi+7] = 0;
			jdi+=8;
			dst[jdi] = 0;
			dst[jdi+1] = 0;
			dst[jdi+2] = 0;
			dst[jdi+3] = 0;
			dst[jdi+4] = 0;
			dst[jdi+5] = 0;
			dst[jdi+6] = 0;
			dst[jdi+7] = 0;
			jdi+=8;
			dst[jdi] = 0;
			dst[jdi+1] = 0;
			dst[jdi+2] = 0;
			dst[jdi+3] = 0;
			dst[jdi+4] = 0;
			dst[jdi+5] = 0;
			dst[jdi+6] = 0;
			dst[jdi+7] = 0;

			
			for(k=0;k<dim;k++){
				jdi = jd + i;
				kd = k*dim;
				jdk = jd + k;
				kdi = kd + i;
				dst[jdi] += src[jdk]*src2[kdi];
				dst[jdi+1] += src[jdk]*src2[kdi+1];
				dst[jdi+2] += src[jdk]*src2[kdi+2];
				dst[jdi+3] += src[jdk]*src2[kdi+3];
				dst[jdi+4] += src[jdk]*src2[kdi+4];
				dst[jdi+5] += src[jdk]*src2[kdi+5];
				dst[jdi+6] += src[jdk]*src2[kdi+6];
				dst[jdi+7] += src[jdk]*src2[kdi+7];
				dst[jdi+8] += src[jdk]*src2[kdi+8];
				jdi +=9;
				kdi += 9;
				dst[jdi] += src[jdk]*src2[kdi];
				dst[jdi+1] += src[jdk]*src2[kdi+1];
				dst[jdi+2] += src[jdk]*src2[kdi+2];
				dst[jdi+3] += src[jdk]*src2[kdi+3];
				dst[jdi+4] += src[jdk]*src2[kdi+4];
				dst[jdi+5] += src[jdk]*src2[kdi+5];
				dst[jdi+6] += src[jdk]*src2[kdi+6];
				dst[jdi+7] += src[jdk]*src2[kdi+7];
				dst[jdi+8] += src[jdk]*src2[kdi+8];
				jdi +=9;
				kdi += 9;
				dst[jdi] += src[jdk]*src2[kdi];
				dst[jdi+1] += src[jdk]*src2[kdi+1];
				dst[jdi+2] += src[jdk]*src2[kdi+2];
				dst[jdi+3] += src[jdk]*src2[kdi+3];
				dst[jdi+4] += src[jdk]*src2[kdi+4];
				dst[jdi+5] += src[jdk]*src2[kdi+5];
				dst[jdi+6] += src[jdk]*src2[kdi+6];
				dst[jdi+7] += src[jdk]*src2[kdi+7];
				dst[jdi+8] += src[jdk]*src2[kdi+8];
				jdi +=9;
				kdi += 9;
				dst[jdi] += src[jdk]*src2[kdi];
				dst[jdi+1] += src[jdk]*src2[kdi+1];
				dst[jdi+2] += src[jdk]*src2[kdi+2];
				dst[jdi+3] += src[jdk]*src2[kdi+3];
				dst[jdi+4] += src[jdk]*src2[kdi+4];



				jdi = jd + i +dim;
				kd = k*dim;
				jdk = jd + k +dim;
				kdi = kd + i;
				dst[jdi] += src[jdk]*src2[kdi];
				dst[jdi+1] += src[jdk]*src2[kdi+1];
				dst[jdi+2] += src[jdk]*src2[kdi+2];
				dst[jdi+3] += src[jdk]*src2[kdi+3];
				dst[jdi+4] += src[jdk]*src2[kdi+4];
				dst[jdi+5] += src[jdk]*src2[kdi+5];
				dst[jdi+6] += src[jdk]*src2[kdi+6];
				dst[jdi+7] += src[jdk]*src2[kdi+7];
				dst[jdi+8] += src[jdk]*src2[kdi+8];
				jdi +=9;
				kdi += 9;
				dst[jdi] += src[jdk]*src2[kdi];
				dst[jdi+1] += src[jdk]*src2[kdi+1];
				dst[jdi+2] += src[jdk]*src2[kdi+2];
				dst[jdi+3] += src[jdk]*src2[kdi+3];
				dst[jdi+4] += src[jdk]*src2[kdi+4];
				dst[jdi+5] += src[jdk]*src2[kdi+5];
				dst[jdi+6] += src[jdk]*src2[kdi+6];
				dst[jdi+7] += src[jdk]*src2[kdi+7];
				dst[jdi+8] += src[jdk]*src2[kdi+8];
				jdi +=9;
				kdi += 9;
				dst[jdi] += src[jdk]*src2[kdi];
				dst[jdi+1] += src[jdk]*src2[kdi+1];
				dst[jdi+2] += src[jdk]*src2[kdi+2];
				dst[jdi+3] += src[jdk]*src2[kdi+3];
				dst[jdi+4] += src[jdk]*src2[kdi+4];
				dst[jdi+5] += src[jdk]*src2[kdi+5];
				dst[jdi+6] += src[jdk]*src2[kdi+6];
				dst[jdi+7] += src[jdk]*src2[kdi+7];
				dst[jdi+8] += src[jdk]*src2[kdi+8];
				jdi +=9;
				kdi += 9;
				dst[jdi] += src[jdk]*src2[kdi];
				dst[jdi+1] += src[jdk]*src2[kdi+1];
				dst[jdi+2] += src[jdk]*src2[kdi+2];
				dst[jdi+3] += src[jdk]*src2[kdi+3];
				dst[jdi+4] += src[jdk]*src2[kdi+4];

			
			}
		}
		for(;i<dim;i++){
			jdi = jd + i;
			dst[jdi] = 0;
			for(k = 0; k<dim; k++ ){
				jdk = jd + k;
				dst[jdi] += src[jdk]*src2[k*dim+i];

		}
	}
}


}

int main() 
{ 
	int mat1[N*N] = { 1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                    1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4
                    }; 
	int mat2[N*N] = { 1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                    1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4,
                     1, 1, 1, 1, 
					2, 2, 2, 2, 
					3, 3, 3, 3, 
					4, 4, 4, 4
                    };  

	int res[N*N]; // To store result 
	int i, j; 
	multiply(mat1, mat2, res, N); 

	printf("Result matrix is \n"); 
	for (i = 0; i < N; i++) 
	{ 
		for (j = 0; j < N; j++) 
		printf("%d ", res[j*N + i]); 
		printf("\n"); 
	} 



	return 0; 
} 
