/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/* 
 * Please fill in the following student struct 
 */
team_t team = {
    "e2171353",              /* Student ID */

    "Osman Emre Bilici",     /* full name */
    "e2171353@ceng.metu.edu.tr",  /* email address */

    "",                   /* leave blank */
    ""                    /* leave blank */
};


/***************
 * CONVOLUTION KERNEL
 ***************/

/******************************************************
 * Your different versions of the convolution functions  go here
 ******************************************************/

/* 
 * naive_conv - The naive baseline version of convolution 
 */
char naive_conv_descr[] = "naive_conv: Naive baseline implementation";
void naive_conv(int dim,int *src, int *ker,int *dst) {
    int i,j,k,l;

    for(i = 0; i < dim-8+1; i++)
        for(j = 0; j < dim-8+1; j++) {
        	
            dst[j*dim+i] = 0;
            for(k = 0; k < 8; k++)
                for(l = 0; l < 8; l++) {
                    dst[j*dim+i] = dst[j*dim+i] +src[(j+l)*dim+(i+k)]*ker[l*dim+k];
                }
        }
            
        
}

/* 
 * convolution - Your current working version of convolution
 * IMPORTANT: This is the version you will be graded on
 */
char convolution_descr[] = "Dot product: Current working version";
void convolution(int dim,int *src, int *ker,int *dst) 
{
//kernel hep 64 zaten
//3.3 oldu
// cok fazla dim ekliyon. engelle bunlari
	
    int i,j,jdi,jldik;

    int ker0  = ker[0];
    int ker1  = ker[1];
    int ker2  = ker[2];
    int ker3  = ker[3];
    int ker4  = ker[4];
    int ker5  = ker[5];
    int ker6  = ker[6];
    int ker7  = ker[7];

    ker += dim;
    int ker8  = ker[0];
    int ker9  = ker[1];
    int ker10 = ker[2];
    int ker11 = ker[3];
    int ker12 = ker[4];
    int ker13 = ker[5];
    int ker14 = ker[6];
    int ker15 = ker[7];
    
    ker += dim;
    int ker16 = ker[0];
    int ker17 = ker[1];
    int ker18 = ker[2];
    int ker19 = ker[3];
    int ker20 = ker[4];
    int ker21 = ker[5];
    int ker22 = ker[6];
    int ker23 = ker[7];
    
    ker += dim;
    int ker24 = ker[0];
    int ker25 = ker[1];
    int ker26 = ker[2];
    int ker27 = ker[3];
    int ker28 = ker[4];
    int ker29 = ker[5];
    int ker30 = ker[6];
    int ker31 = ker[7];
    
    ker += dim;
    int ker32 = ker[0];
    int ker33 = ker[1];
    int ker34 = ker[2];
    int ker35 = ker[3];
    int ker36 = ker[4];
    int ker37 = ker[5];
    int ker38 = ker[6];
    int ker39 = ker[7];
    
    ker += dim;
    int ker40 = ker[0];
    int ker41 = ker[1];
    int ker42 = ker[2];
    int ker43 = ker[3];
    int ker44 = ker[4];
    int ker45 = ker[5];
    int ker46 = ker[6];
    int ker47 = ker[7];
    
    ker += dim;
    int ker48 = ker[0];
    int ker49 = ker[1];
    int ker50 = ker[2];
    int ker51 = ker[3];
    int ker52 = ker[4];
    int ker53 = ker[5];
    int ker54 = ker[6];
    int ker55 = ker[7];
    
    ker += dim;
    int ker56 = ker[0];
    int ker57 = ker[1];
    int ker58 = ker[2];
    int ker59 = ker[3];
    int ker60 = ker[4];
    int ker61 = ker[5];
    int ker62 = ker[6];
    int ker63 = ker[7];

    for(i = 0; i < dim-7; i++)
        for(j = 0; j < dim-7; j++) {
        	jdi = j*dim + i;
        	jldik = jdi;

        	dst[jdi] = 0;

        	dst[jdi] += src[jldik]*ker0;
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker8;
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker16;
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker24;
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker32;
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker40;
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker48;
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker56;

        	
        	jldik = jdi + 1;

        	dst[jdi] += src[jldik]*ker1;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker9;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker17;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker25;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker33;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker41;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker49;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker57;

        	
        	jldik = jdi + 2;

        	dst[jdi] += src[jldik]*ker2;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker10;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker18;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker26;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker34;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker42;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker50;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker58;

        	
        	jldik = jdi + 3;

        	dst[jdi] += src[jldik]*ker3;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker11;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker19;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker27;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker35;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker43;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker51;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker59;

        	
        	jldik = jdi + 4;

        	dst[jdi] += src[jldik]*ker4;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker12;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker20;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker28;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker36;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker44;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker52;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker60;

        	
        	jldik = jdi + 5;

        	dst[jdi] += src[jldik]*ker5;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker13;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker21;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker29;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker37;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker45;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker53;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker61;

        	
        	jldik = jdi + 6;

        	dst[jdi] += src[jldik]*ker6;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker14;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker22;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker30;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker38;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker46;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker54;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker62;

        	jldik = jdi + 7;

        	dst[jdi] += src[jldik]*ker7;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker15;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker23;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker31;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker39;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker47;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker55;
        	
        	jldik+=dim;
        	dst[jdi] += src[jldik]*ker63;


        }

 
}

/*********************************************************************
 * register_conv_functions - Register all of your different versions
 *     of the convolution functions  with the driver by calling the
 *     add_conv_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_conv_functions() {
    add_conv_function(&naive_conv, naive_conv_descr);   
    add_conv_function(&convolution, convolution_descr);   
    /* ... Register additional test functions here */
}




/***************
 * MATRIX MULTIP KERNEL
 ***************/

/******************************************************
 * Your different versions of the matrix multiplications  go here
 ******************************************************/

/* 
 * naive_matrix_multiplication - The naive baseline version of matrix multiplication 
 */
char naive_matrix_multiplication_descr[] = "Naive_matrix_multiplication: Naive baseline implementation";
void naive_matrix_multiplication(int dim,int *src, int *src2,int *dst) {
    int i,j,k;

    for(i = 0; i < dim; i++)
        for(j = 0; j < dim; j++) {
        	
            dst[j*dim+i]=0;
            for(k = 0; k < dim; k++) {
            	
                dst[j*dim+i] = dst[j*dim+i] + src[j*dim+k]*src2[i+k*dim];
            }
        }    
}


/* 
 * matrix_multiplication - Your current working version of matrix_multiplication
 * IMPORTANT: This is the version you will be graded on
 */
char matrix_multiplication_descr[] = "Matrix multiplications: Current working version";
void matrix_multiplication(int dim,int *src, int *src2,int *dst) 
{
	int i, j, k,jdi,kd,jdk,d,jd,kdi;
	d=dim-32;
	for(j = 0; j<dim; j++){
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
/*	for(i=0; i<dim; i++){

		d=dim-8;
		for(j=0; j<d;j+=8){
			jd = j*dim;
			jdi = jd + i;
			dst[jdi]=0;
			jdi += dim;
			dst[jdi]=0;
			jdi += dim;
			dst[jdi]=0;
			jdi += dim;
			dst[jdi]=0;
			jdi += dim;
			dst[jdi]=0;
			jdi += dim;
			dst[jdi]=0;
			jdi += dim;
			dst[jdi]=0;
			jdi += dim;
			dst[jdi]=0;
			
			for(k=0;k <dim; k++){
				kd = k*dim + i;
				jdk = jd + k;
				jdi = jd + i;
				//printf("%d %d %d bas\n", jdi, jdk, kd);
				dst[jdi] += src[jdk]*src2[kd];
				jdi += dim;
				jdk += dim;
				//printf("%d %d %d\n", jdi, jdk, kd);
				dst[jdi] += src[jdk]*src2[kd];
				jdi += dim;
				jdk += dim;
				//printf("%d %d %d\n", jdi, jdk, kd);
				dst[jdi] += src[jdk]*src2[kd];
				jdi += dim;
				jdk += dim;
				//printf("%d %d %d\n", jdi, jdk, kd);
				dst[jdi] += src[jdk]*src2[kd];
				jdi += dim;
				jdk += dim;
				//printf("%d %d %d\n", jdi, jdk, kd);
				dst[jdi] += src[jdk]*src2[kd];
				jdi += dim;
				jdk += dim;
				//printf("%d %d %d\n", jdi, jdk, kd);
				dst[jdi] += src[jdk]*src2[kd];
				jdi += dim;
				jdk += dim;
				//printf("%d %d %d\n", jdi, jdk, kd);
				dst[jdi] += src[jdk]*src2[kd];
				jdi += dim;
				jdk += dim;
				//printf("%d %d %d son\n", jdi, jdk, kd);
				dst[jdi] += src[jdk]*src2[kd];
	
			}

		}
		
		for(; j<dim;  j++){
			jdi = j*dim+i;
			dst[jdi]=0;
			for(k=0;k <dim; k++){	
				dst[jdi] += src[j*dim+k]*src2[k*dim+i];
			}
		}
	}
        


*/

        //naive_matrix_multiplication(dim,src,src2,dst);


/*********************************************************************
 * register_matrix_multiplication_functions - Register all of your different versions
 *     of the matrix multiplication  with the driver by calling the
 *     add_matrix_multiplication_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_matrix_multiplication_functions() {
    add_matrix_multiplication_function(&naive_matrix_multiplication, naive_matrix_multiplication_descr);   
    add_matrix_multiplication_function(&matrix_multiplication, matrix_multiplication_descr);   
    /* ... Register additional test functions here */
}

